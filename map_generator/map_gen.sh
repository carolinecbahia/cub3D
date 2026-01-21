#!/bin/bash
# Gerador AUTOMÁTICO e ALEATÓRIO de mapas para cub3D

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Configurações
VALID_COUNT=${1:-10}      # Quantos mapas válidos gerar (padrão: 10)
INVALID_COUNT=${2:-15}    # Quantos mapas inválidos gerar (padrão: 15)

mkdir -p maps/valid maps/invalid

echo -e "${GREEN}=== Gerador AUTOMÁTICO de Mapas cub3D ===${NC}"
echo -e "${BLUE}Gerando $VALID_COUNT mapas válidos e $INVALID_COUNT inválidos${NC}\n"

# Função para gerar cabeçalho válido
generate_valid_header() {
    cat << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

EOF
}

# Gerar mapa aleatório válido
generate_random_valid_map() {
    local width=$((RANDOM % 20 + 10))   # 10-30
    local height=$((RANDOM % 15 + 8))   # 8-23
    local density=$((RANDOM % 30 + 20)) # 20-50% de paredes internas
    
    # Criar matriz
    declare -a map
    
    # Primeira linha (tudo parede)
    map[0]=$(printf '1%.0s' $(seq 1 $width))
    
    # Linhas do meio
    for ((y=1; y<height-1; y++)); do
        line="1"
        for ((x=1; x<width-1; x++)); do
            if [ $((RANDOM % 100)) -lt $density ]; then
                line+="1"
            else
                line+="0"
            fi
        done
        line+="1"
        map[$y]="$line"
    done
    
    # Última linha (tudo parede)
    map[$((height-1))]=$(printf '1%.0s' $(seq 1 $width))
    
    # Adicionar jogador em posição aleatória
    local player_placed=0
    local attempts=0
    while [ $player_placed -eq 0 ] && [ $attempts -lt 100 ]; do
        local py=$((RANDOM % (height-2) + 1))
        local px=$((RANDOM % (width-2) + 1))
        
        # Verificar se é espaço vazio
        local char="${map[$py]:$px:1}"
        if [ "$char" = "0" ]; then
            local dir=("N" "S" "E" "W")
            local player_dir=${dir[$((RANDOM % 4))]}
            
            # Substituir caractere na posição
            local line="${map[$py]}"
            map[$py]="${line:0:$px}${player_dir}${line:$((px+1))}"
            player_placed=1
        fi
        attempts=$((attempts+1))
    done
    
    # Imprimir mapa
    for ((i=0; i<height; i++)); do
        echo "${map[$i]}"
    done
}

# Gerar mapa inválido específico
generate_invalid_map() {
    local type=$1
    local width=$((RANDOM % 15 + 8))
    local height=$((RANDOM % 10 + 6))
    
    case $type in
        "no_player")
            # Mapa sem jogador
            echo "$(printf '1%.0s' $(seq 1 $width))"
            for ((y=1; y<height-1; y++)); do
                line="1"
                for ((x=1; x<width-1; x++)); do
                    [ $((RANDOM % 100)) -lt 30 ] && line+="1" || line+="0"
                done
                echo "${line}1"
            done
            echo "$(printf '1%.0s' $(seq 1 $width))"
            ;;
            
        "multiple_players")
            # Colocar 2+ jogadores
            generate_random_valid_map | sed "s/0/S/2"
            ;;
            
        "open_map")
            # Remover parte da borda
            generate_random_valid_map | head -n -1
            echo "1111111100"
            ;;
            
        "hole_in_wall")
            # Criar buraco na parede
            local map=$(generate_random_valid_map)
            echo "$map" | sed "${height}s/1/0/$((RANDOM % 3 + 2))"
            ;;
            
        "invalid_char")
            # Adicionar caractere inválido
            generate_random_valid_map | sed "s/0/X/1"
            ;;
            
        "space_inside")
            # Adicionar espaço dentro do mapa
            generate_random_valid_map | sed "s/0/ /1"
            ;;
            
        "not_closed")
            # Mapa não fechado - linha com menos caracteres
            local base=$(generate_random_valid_map)
            echo "$base" | head -n 3
            echo "10000"
            echo "$base" | tail -n 3
            ;;
            
        "newline_in_map")
            # Linha vazia no meio do mapa
            local base=$(generate_random_valid_map)
            local mid=$((height / 2))
            echo "$base" | head -n $mid
            echo ""
            echo "$base" | tail -n $((height - mid))
            ;;
    esac
}

# Gerar cabeçalho inválido
generate_invalid_header() {
    local type=$1
    case $type in
        "missing_texture")
            cat << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm

F 220,100,0
C 225,30,0

EOF
            ;;
        "duplicate_texture")
            cat << 'EOF'
NO ./textures/north.xpm
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

EOF
            ;;
        "missing_color")
            cat << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0

EOF
            ;;
        "invalid_rgb")
            local r=$((RANDOM % 156 + 256))  # 256-411
            cat << EOF
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F ${r},100,0
C 225,30,0

EOF
            ;;
        "wrong_format")
            cat << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220 100 0
C 225,30,0

EOF
            ;;
        "negative_rgb")
            cat << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F -10,100,0
C 225,30,0

EOF
            ;;
    esac
}

# ========== GERAR MAPAS VÁLIDOS ==========
echo -e "${GREEN}Gerando mapas válidos aleatórios...${NC}"

for i in $(seq 1 $VALID_COUNT); do
    filename="maps/valid/random_valid_${i}.cub"
    {
        generate_valid_header
        generate_random_valid_map
    } > "$filename"
    echo "✓ random_valid_${i}.cub ($(wc -l < "$filename") linhas)"
done

# ========== GERAR MAPAS INVÁLIDOS ==========
echo -e "\n${RED}Gerando mapas inválidos aleatórios...${NC}"

invalid_types=(
    "no_player"
    "multiple_players"
    "open_map"
    "hole_in_wall"
    "invalid_char"
    "space_inside"
    "not_closed"
    "newline_in_map"
)

header_invalid_types=(
    "missing_texture"
    "duplicate_texture"
    "missing_color"
    "invalid_rgb"
    "wrong_format"
    "negative_rgb"
)

counter=1

# Mapas com erro no mapa
for type in "${invalid_types[@]}"; do
    if [ $counter -gt $INVALID_COUNT ]; then break; fi
    
    filename="maps/invalid/invalid_${type}_${counter}.cub"
    {
        generate_valid_header
        generate_invalid_map "$type"
    } > "$filename"
    echo "✓ invalid_${type}_${counter}.cub"
    counter=$((counter+1))
done

# Mapas com erro no cabeçalho
for type in "${header_invalid_types[@]}"; do
    if [ $counter -gt $INVALID_COUNT ]; then break; fi
    
    filename="maps/invalid/invalid_${type}_${counter}.cub"
    {
        generate_invalid_header "$type"
        generate_random_valid_map
    } > "$filename"
    echo "✓ invalid_${type}_${counter}.cub"
    counter=$((counter+1))
done

# Mapas adicionais aleatórios
while [ $counter -le $INVALID_COUNT ]; do
    # Escolher tipo aleatório
    all_types=("${invalid_types[@]}" "${header_invalid_types[@]}")
    random_type=${all_types[$((RANDOM % ${#all_types[@]}))]}
    
    filename="maps/invalid/invalid_random_${counter}.cub"
    
    # Verificar se é tipo de cabeçalho ou mapa
    if [[ " ${header_invalid_types[@]} " =~ " ${random_type} " ]]; then
        {
            generate_invalid_header "$random_type"
            generate_random_valid_map
        } > "$filename"
    else
        {
            generate_valid_header
            generate_invalid_map "$random_type"
        } > "$filename"
    fi
    
    echo "✓ invalid_random_${counter}.cub (tipo: $random_type)"
    counter=$((counter+1))
done

# ========== RESUMO ==========
echo -e "\n${YELLOW}=== Resumo ===${NC}"
valid_count=$(ls -1 maps/valid/*.cub 2>/dev/null | wc -l)
invalid_count=$(ls -1 maps/invalid/*.cub 2>/dev/null | wc -l)

echo "Mapas válidos gerados: ${GREEN}$valid_count${NC}"
echo "Mapas inválidos gerados: ${RED}$invalid_count${NC}"
echo -e "\n${GREEN}Geração completa!${NC}"
echo "Execute novamente para gerar mapas diferentes!"
echo -e "\nUso: $0 [num_válidos] [num_inválidos]"
echo "Exemplo: $0 20 30"