# 🛣️ Roadmap de Implementação: cub3D

Este roadmap detalha todas as etapas necessárias para implementar o cub3D, desde o estudo dos conceitos até a entrega final, incluindo código, assets e testes.

---

## 1. Estudo Inicial

- Revisar o subject do projeto e requisitos obrigatórios e bônus
- Estudar raycasting (matemática, algoritmos, exemplos)
- Revisar conceitos de gráficos 2D/3D, projeção, vetores e matrizes
- Estudar a MiniLibX (API, funções permitidas, exemplos de uso)
- Revisar manipulação de arquivos em C (open, read, etc.)
- Revisar parsing de strings e validação de dados
- Estudar gestão de memória em C (malloc, free, leaks)
- Revisar Norm da 42 e boas práticas de Makefile

## 2. Planejamento do Projeto

- Definir estrutura de pastas (src, includes, assets, mapas, etc.)
- Listar módulos principais: parsing, renderização, movimentação, colisão, assets
- Definir formato dos arquivos de mapa (.cub)
- Planejar assets necessários: texturas, mapas de exemplo, sprites (bônus)
- Esboçar diagramas de fluxo e estruturas de dados

## 3. Parsing e Validação do Mapa

- Implementar leitura do arquivo .cub
- Validar formato, elementos obrigatórios (texturas, cores, layout)
- Armazenar dados do mapa em estruturas apropriadas
- Testar parsing com mapas válidos e inválidos

	- Função: `parse_map_file(const char *filename)`
	- Função: `validate_map_elements(Map *map)`
	- Função: `check_map_integrity(Map *map)`
	- Função: `init_map_struct(Map *map)`
	- Função: `test_map_parsing()`
- Definir cores de fundo
- Testar abertura e fechamento da janela

	- Função: `init_mlx(Window *win)`
	- Função: `create_window(Window *win, int width, int height)`
	- Função: `load_textures(Texture *textures, Map *map)`
	- Função: `set_background_colors(Window *win, Map *map)`
	- Função: `close_window(Window *win)`
- Aplicar texturas nas superfícies
- Testar renderização com diferentes mapas

	- Função: `perform_raycasting(Player *player, Map *map, Window *win)`
	- Função: `calculate_ray_distances(Player *player, Map *map)`
	- Função: `draw_floor_and_ceiling(Window *win, Map *map)`
	- Função: `apply_wall_textures(Window *win, Texture *textures)`
	- Função: `test_rendering()`

## 7. Gestão de Memória e Makefile

	- Função: `move_player(Player *player, Map *map, int direction)`
	- Função: `rotate_player(Player *player, double angle)`
	- Função: `check_collision(Player *player, Map *map)`
	- Função: `test_movement()`
- Testar Makefile (compilação, limpeza, recompilação)

## 8. Testes e Validação
	- Função: `free_map(Map *map)`
	- Função: `free_textures(Texture *textures)`
	- Função: `free_window(Window *win)`
- Testar robustez contra entradas inválidas

## 9. Implementação dos Bônus (Opcional)
	- Função: `run_all_tests()`
- Efeitos visuais: filtros, animações, etc.
- Testar separadamente cada bônus

	- Função: `render_sprites(Sprite *sprites, Player *player, Window *win)`
	- Função: `draw_minimap(Map *map, Player *player, Window *win)`
	- Função: `handle_doors(Map *map, Player *player)`
	- Função: `apply_visual_effects(Window *win)`
- Testar em diferentes máquinas/ambientes
- Preparar repositório Git para submissão


## 12. Revisão Final e Simulação de Avaliação


---

