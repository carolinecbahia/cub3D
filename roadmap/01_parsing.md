# 🚧 ETAPA 01 — Parsing do Arquivo `.cub`

> **Sprint:** 1
>
> **Responsável:** 
>
> **Período:** 29/07 → 02/08
>
> **Dificuldade:** ⭐⭐⭐⭐☆

---

# Objetivo

Implementar todo o pipeline responsável por ler um arquivo `.cub`, validar sua estrutura e preencher a estrutura principal do jogo (`t_game`).

Ao final desta etapa o projeto deve ser capaz de:

- abrir um arquivo `.cub`;
- validar sua extensão;
- ler todo o conteúdo;
- identificar texturas;
- identificar cores;
- construir o mapa;
- localizar o jogador;
- preencher todas as estruturas necessárias para o restante do projeto.

Nenhuma renderização será realizada nesta etapa.

---

# Resultado Esperado

Entrada

```
./cub3D maps/valid.cub
```

↓

```
Arquivo válido
```

↓

```
t_game

↓

map preenchido

↓

player encontrado

↓

texturas registradas

↓

cores convertidas
```

---

# Arquivos Envolvidos

## src/parsing/

```
path_validation.c
textures_parsing.c
color_parsing.c
map_parsing.c
map_building.c
parsing_utils.c
map_utils.c
grid_utils.c
```

---

## include/

```
cub3D.h
types.h
```

---

# Dependências

Esta etapa depende apenas de:

- libft
- get_next_line
- ft_split
- ft_strdup
- ft_strlen
- ft_calloc
- ft_free_matrix

Nenhuma função da MLX será utilizada.

---

# Fluxo Geral

```
main()

↓

validate arguments

↓

check extension

↓

open file

↓

read file

↓

parse textures

↓

parse colors

↓

parse map

↓

build grid

↓

find player

↓

t_game preenchido
```

---

# Estruturas Envolvidas

Durante esta etapa deverão ser preenchidas:

## t_map

- largura
- altura
- grid
- texturas
- cores

## t_player

- posição inicial
- direção inicial

## t_game

- map
- player

---

# Ordem de Implementação

## Parte 1 — Validação do Arquivo

### Objetivo

Garantir que o arquivo recebido é um `.cub`.

### Arquivo

```
path_validation.c
```

### Funções

- [ ] check_file_extension()
- [ ] validate_path()

### Casos de erro

- extensão diferente de `.cub`
- nome vazio
- arquivo inexistente
- diretório

### Testes

```bash
./cub3D maps/valid.cub

./cub3D maps/test.txt

./cub3D maps/test

./cub3D maps/

./cub3D inexistente.cub
```

---

## Parte 2 — Leitura do Arquivo

### Objetivo

Ler completamente o arquivo.

### Arquivos

```
map_parsing.c

parsing_utils.c
```

### Funções

- [ ] open_file()
- [ ] read_file()
- [ ] close_file()

### Resultado

Obter uma matriz de linhas contendo todo o conteúdo do `.cub`.

### Testes

- arquivo vazio
- arquivo enorme
- arquivo inexistente

---

## Parte 3 — Parsing das Texturas

### Arquivo

```
textures_parsing.c
```

### Identificadores

```
NO

SO

WE

EA
```

### Objetivos

Extrair

```
NO ./textures/north.xpm
```

↓

```
game->map.north_texture
```

### Validações

- [ ] existe apenas uma NO
- [ ] existe apenas uma SO
- [ ] existe apenas uma WE
- [ ] existe apenas uma EA

### Casos de erro

- textura duplicada
- textura ausente
- identificador inválido

### Testes

```
NO textures/north.xpm
```

```
NO textures/north.xpm

NO textures/outro.xpm
```

---

## Parte 4 — Parsing das Cores

### Arquivo

```
color_parsing.c
```

### Identificadores

```
F

C
```

### Objetivo

Converter

```
220,100,0
```

↓

```
0xDC6400
```

### Funções

- [ ] parse_color()
- [ ] create_color()

### Validações

- apenas uma cor de piso
- apenas uma cor de teto

### RGB

Cada componente

```
0 ≤ valor ≤ 255
```

### Casos de erro

```
300,0,0

-1,0,0

255,255

255,255,255,255

abc
```

---

## Parte 5 — Parsing do Mapa

### Arquivo

```
map_parsing.c
```

### Objetivo

Detectar onde o mapa começa.

Criar a matriz do mapa.

### Resultado

```
111111

100001

10N001

111111
```

↓

```
char **grid
```

### Testes

- mapa mínimo
- mapa grande
- mapa com espaços

---

## Parte 6 — Construção do Grid

### Arquivos

```
map_building.c

grid_utils.c
```

### Objetivo

Normalizar todas as linhas.

Garantir largura consistente.

### Exemplo

```
1111

100001

111
```

↓

```
111100

100001

111000
```

*(O preenchimento deverá seguir a estratégia definida para o projeto.)*

---

## Parte 7 — Encontrar o Jogador

### Arquivo

```
map_utils.c
```

### Objetivo

Encontrar

```
N

S

E

W
```

### Preencher

```
player.x

player.y

player.direction
```

### Casos

- [ ] sem player
- [ ] múltiplos players

---

# Checklist

## Arquivo

- [ ] extensão válida
- [ ] arquivo aberto
- [ ] leitura completa

## Texturas

- [ ] NO
- [ ] SO
- [ ] WE
- [ ] EA

## Cores

- [ ] F
- [ ] C

## Mapa

- [ ] mapa encontrado
- [ ] grid criado

## Jogador

- [ ] player localizado
- [ ] direção salva

---

# Testes

## Arquivos válidos

```
valid_basic.cub

spaces_valid.cub
```

---

## Arquivos inválidos

```
bad_extension.txt

duplicate_texture.cub

missing_texture.cub

bad_rgb.cub

double_player.cub

invalid_char.cub

newline_in_map.cub

space_leak.cub
```

---

# Comandos

```bash
make

./cub3D maps/tests/valid_basic.cub
```

```bash
valgrind --leak-check=full ./cub3D maps/tests/valid_basic.cub
```

---

# Critérios de Conclusão (Definition of Done)

## Funcional

- [ ] abre arquivos `.cub`
- [ ] rejeita extensões inválidas
- [ ] identifica texturas
- [ ] identifica cores
- [ ] cria o grid
- [ ] encontra o jogador
- [ ] preenche `t_game`

## Código

- [ ] sem leaks
- [ ] sem invalid reads
- [ ] sem invalid writes
- [ ] sem segfault
- [ ] norminette OK

## Integração

- [ ] pronto para iniciar a etapa de Validation

---

# Próxima Etapa

➡️ **02_validation.md**

Nesta etapa serão implementadas todas as validações do subject:

- caracteres válidos;
- mapa fechado;
- flood fill;
- dimensões;
- regras do player;
- mensagens de erro.