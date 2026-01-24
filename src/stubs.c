#include "cub3D.h"
#include <stdio.h>

void draw_map(t_game *game) {
    if (!game || !game->mlx_ptr)
        return;
    int width = game->map.width * TILE_SIZE;
    int height = game->map.height * TILE_SIZE;
    mlx_image_t *img = mlx_new_image(game->mlx_ptr, width, height);
    if (!img)
        return;
    // Cores fixas: teto (cinza claro), chão (azul)
    uint32_t ceiling = 0xFFCCCCCC; // ARGB
    uint32_t floor = 0xFF3366FF;   // ARGB
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y < height / 2)
                mlx_put_pixel(img, x, y, ceiling);
            else
                mlx_put_pixel(img, x, y, floor);
        }
    }
    mlx_image_to_window(game->mlx_ptr, img, 0, 0);
}

int handle_close(t_game *game) {
    (void)game;
    // Stub: Implementar fechamento do jogo
    return 0;
}

int move_up(t_game *game) {
    (void)game;
    // Stub: Implementar movimento para cima
    return 0;
}

int move_down(t_game *game) {
    (void)game;
    // Stub: Implementar movimento para baixo
    return 0;
}

int move_left(t_game *game) {
    (void)game;
    // Stub: Implementar movimento para esquerda
    return 0;
}

int move_right(t_game *game) {
    (void)game;
    // Stub: Implementar movimento para direita
    return 0;
}


void cleanup_game(t_game *game) {
    if (game) {
        if (game->map.grid)
            ft_free_matrix(game->map.grid);
        game->map.grid = NULL;
        // Adicione aqui outras liberações necessárias futuramente
    }
}

void setup_game(t_game *game) {
    (void)game;
    // Stub: Implementar setup do jogo
}

int check_map_borders(t_map map) {
    (void)map;
    // Stub: Implementar validação das bordas do mapa
    return 0;
}
