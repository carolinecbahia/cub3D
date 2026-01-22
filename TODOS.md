# 🚧 ETAPA ATUAL: Parsing do .cub (Cub3D)

- **Roadmap:** [Parsing do Arquivo .cub (Semana 1-2)](#fase-2-parsing-do-arquivo-cub-semana-1-2)
- **Data de início:** 21/01/2026
- **Previsão de término:** 28/01/2026

## Testes a Realizar (código)

```sh
# Teste: mapa válido
./cub3D maps/valid.cub

# Teste: extensão inválida
./cub3D maps/test.txt  # Deve retornar erro

# Teste: mapa aberto
# (criar .cub com buraco nas bordas)

# Teste: múltiplos players
# (criar .cub com mais de um N/S/E/W)

# Teste: caractere inválido
# (criar .cub com caractere não permitido)

# Teste: textura inexistente
# (caminho de textura inválido)

# Teste: cor fora do range
# (F 300,0,0 ou C -1,255,255)

# Teste: linhas vazias e ordem variada dos elementos
# (mapa com linhas vazias entre elementos e ordem trocada)
```

---

## Etapas

1. **Ajuste de Tipos e Defines**
   - [ ] Revisar e adaptar structs (`t_map`, `t_vectors`, etc.) para o padrão do Cub3D.
   - [ ] Atualizar defines dos elementos do mapa (WALL, EMPTY, PLAYER, etc.) conforme Cub3D.

2. **Funções de Matriz**
   - [ ] Garantir compatibilidade de `create_matrix` e `dup_matrix` com o formato do Cub3D.
   - [ ] Validar uso de `ft_split`, `ft_strdup`, `ft_free_matrix`.

3. **Validação do Mapa**
   - [ ] Adaptar `check_map_dimensions` para aceitar mapas retangulares e regras do Cub3D.
   - [ ] Adaptar `check_map_walls` para garantir fechamento por '1'.
   - [ ] Refatorar `count_map_elements` para validar apenas player e caracteres válidos.

4. **Flood Fill e Pathfinding**
   - [ ] Adaptar flood fill para garantir apenas fechamento do mapa.
   - [ ] Remover lógica de collectibles/exits.

5. **Leitura e Parsing do Arquivo**
   - [ ] Revisar `map_reader` e `open_and_read_map` para tratamento de erros e BUFFER_SIZE.
   - [ ] Implementar `check_file_extension`, `validate_file`, `parse_map` para parsing do .cub.

6. **Mensagens de Erro**
   - [ ] Padronizar mensagens de erro para inglês e saída em stderr.

7. **Testes**
   - [ ] Criar testes para mapas válidos/invalidos, múltiplos players, buracos, caracteres inválidos, etc.

## Arquivos Envolvidos
- src/parsing/map_parsing.c
- src/parsing/map_utils.c
- src/parsing/map_validation.c
- src/parsing/path_validation.c

---

# 🎮 Mapa de Desenvolvimento - cub3D

## 📊 Visão Geral do Projeto
- **Tempo Total Estimado:** 5-7 semanas
- **Dificuldade:** ⭐⭐⭐⭐⭐ (Muito Alta)
- **Pontos Críticos:** Ray-casting, Texturização, Performance, Parsing de .cub

## 🔧 Funções Autorizadas e Seus Usos
- **I/O Básico:**
  - open(), close(), read(), write() — Manipulação de arquivos
  - printf() — Saída formatada
  - perror(), strerror() — Mensagens de erro
  - exit() — Finalizar programa
- **Memória:**
  - malloc(), free() — Alocação dinâmica
- **Tempo:**
  - gettimeofday() — FPS/animações
- **Matemática:**
  - Todas as funções de math.h (-lm)
  - sin(), cos(), tan(), sqrt(), floor(), ceil(), fabs()
- **MiniLibX:**
  - mlx_init(), mlx_new_window(), mlx_new_image(), mlx_get_data_addr(), mlx_put_image_to_window(), mlx_xpm_file_to_image(), mlx_hook(), mlx_key_hook(), mlx_loop(), mlx_destroy_image(), mlx_destroy_window()

## 📅 Fase 1: Fundação e Setup (Semana 1)
- **Tempo estimado:** 5-7 dias
- **Dificuldade:** ⭐⭐⭐☆☆

### 1.1 Estrutura Básica do Projeto
- Criar Makefile com flags (-Wall -Wextra -Werror)
- Configurar estrutura de pastas (src/, includes/, textures/, maps/)
- Integrar MiniLibX ao Makefile
- Configurar libft (se usar)

**Estrutura Sugerida:**
```
cub3D/
├── src/
│   ├── main.c
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   └── utils/
├── includes/
├── textures/
├── maps/
├── libft/
└── Makefile
```

### 1.2 Estruturas de Dados Principais
```c
typedef struct s_map {
    char    **grid;
    int     width;
    int     height;
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    int     floor_color;   // RGB packed
    int     ceiling_color; // RGB packed
} t_map;

typedef struct s_player {
    double  pos_x;
    double  pos_y;
    double  dir_x;  // vetor direção
    double  dir_y;
    double  plane_x; // plano da câmera
    double  plane_y;
} t_player;

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_img;

typedef struct s_game {
    void        *mlx;
    void        *win;
    t_map       map;
    t_player    player;
    t_img       textures[4]; // N,S,E,W
    t_img       screen;
} t_game;
```
**Testes:**
- Makefile compila sem erros
- Programa inicia (mesmo que vazio)
- Estruturas definidas corretamente

## 📅 Fase 2: Parsing do Arquivo .cub (Semana 1-2)
- **Tempo estimado:** 6-8 dias
- **Dificuldade:** ⭐⭐⭐⭐☆

### 2.1 Validação Básica
- Verificar extensão .cub
- Abrir e ler arquivo
- Tratamento de erros de leitura

**Funções a Implementar:**
- check_file_extension() — Validar .cub
- read_file() — Ler arquivo completo
- validate_file() — Validações gerais

### 2.2 Parse de Elementos (Texturas e Cores)
- Identificar e extrair NO, SO, WE, EA
- Validar caminhos de texturas
- Parse de cores F e C (RGB)
- Permitir qualquer ordem (exceto mapa)
- Permitir múltiplos players

**Funções a Implementar:**
- parse_texture() — Extrair caminho de textura
- parse_color() — Extrair RGB e converter
- validate_texture_path() — Verificar se arquivo existe
- validate_rgb() — Validar range [0,255]

**Formato de Cor:**
```c
int create_color(int r, int g, int b) {
    return (r << 16 | g << 8 | b);
}
```

**Testes:**
- `NO ./textures/north.xpm` → path extraído
- `F 220,100,0` → RGB convertido corretamente
- `C 225,30,0` → RGB convertido corretamente
- Ordem variada dos elementos funciona
- Linhas vazias ignoradas corretamente
- Texturas inexistentes → erro

### 2.3 Parse do Mapa
- Identificar início do mapa (após elementos)
- Ler todas as linhas do mapa
- Validar caracteres (0, 1, N, S, E, W)
- Encontrar posição e orientação do player
- Garantir apenas um player

**Funções a Implementar:**
- parse_map() — Extrair grid do mapa
- find_player() — Localizar posição inicial
- validate_map_chars() — Validar caracteres

**Testes:**
- Mapa válido → grid criado
- Player encontrado (N, S, E, W)
- Múltiplos players → erro
- Sem player → erro
- Caractere inválido → erro

### 2.4 Validação de Mapa (Fechado por Paredes)
- Verificar que mapa é cercado por '1'
- Flood-fill para detectar vazamentos
- Lidar com espaços no mapa

**Funções a Implementar:**
- validate_walls() — Verificar paredes
- flood_fill() — Detectar mapa aberto
- check_map_borders() — Validar bordas

**Casos Críticos:**
```text
# Válido
111111
100001
100N01
111111

# Inválido (aberto)
111111
10000
100N01
111111

# Válido (espaços válidos)
  111
  101
11101
10001
11111
```
**Testes:**
- Mapa fechado → válido
- Mapa aberto em qualquer direção → erro
- Espaços no mapa tratados corretamente

## 📅 Fase 3: Setup MiniLibX e Renderização Básica (Semana 2)
- **Tempo estimado:** 4-5 dias
- **Dificuldade:** ⭐⭐⭐☆☆

### 3.1 Inicialização MiniLibX
- Criar janela (ex: 1280x720)
- Criar imagem para buffer
- Setup de eventos (teclado, fechar janela)

**Funções a Implementar:**
- init_mlx() — Inicializar mlx e janela
- init_image() — Criar buffer de pixels
- setup_hooks() — Configurar eventos

**Exemplo de Inicialização:**
```c
game->mlx = mlx_init();
game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
game->screen.addr = mlx_get_data_addr(game->screen.img,
    &game->screen.bits_per_pixel,
    &game->screen.line_length,
    &game->screen.endian);
```

### 3.2 Carregamento de Texturas
- Carregar 4 texturas (N, S, E, W) usando mlx_xpm_file_to_image
- Validar dimensões
- Obter data_addr de cada textura

**Funções a Implementar:**
- load_texture() — Carregar XPM
- validate_texture() — Verificar se carregou
- get_texture_pixel() — Obter cor de pixel

**Testes:**
- 4 texturas carregadas
- Texturas acessíveis via addr
- Arquivo inválido → erro

### 3.3 Renderização de Teste
- Desenhar teto e chão coloridos
- Função para colocar pixel em imagem
- Renderizar imagem na janela

**Funções a Implementar:**
- put_pixel() — Colocar pixel em x,y
- render_background() — Desenhar teto/chão
- render_frame() — Atualizar janela

**Exemplo put_pixel:**
```c
void put_pixel(t_img *img, int x, int y, int color) {
    char *dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
```
**Testes:**
- Janela abre
- Teto e chão com cores corretas
- ESC fecha janela
- Red cross fecha janela

---

## (Demais fases mantidas com estrutura semelhante, consulte o arquivo para detalhes de Ray-casting, Texturização, Movimentação, Otimização, Testes e Bônus)
