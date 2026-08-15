# 🚧 ETAPA 00 — Core Architecture e Inicialização

> **Sprint:** 0
>
> **Responsável:**
>
> **Período:**
>
> **Dificuldade:** ⭐⭐⭐⭐☆

---

# Objetivo

Implementar toda a infraestrutura central do projeto.

Esta etapa é responsável por criar a base sobre a qual todos os outros módulos irão funcionar.

Ao final desta etapa o projeto deverá possuir:

* estruturas principais definidas;
* sistema de inicialização;
* gerenciamento de memória;
* sistema de erros;
* destruição segura dos recursos;
* fluxo de execução principal.

Nenhuma lógica de parsing, renderização ou raycasting será implementada nesta etapa.

---

# Resultado Esperado

```text
main()

↓

init_game()

↓

game pronto

↓

...

↓

destroy_game()

↓

todos os recursos liberados
```

---

# Arquivos Envolvidos

## src/game/

```text
init_game.c

destroy_game.c

init_player.c
```

---

## src/utils/

```text
cleanup.c

errors.c
```

---

## inc/

```text
cub3D.h

types.h
```

---

# Dependências

Esta é a primeira etapa do projeto.

Não depende de nenhum outro módulo.

---

# Arquitetura Geral

```text
               main()

                 │

         init_game()

                 │

        ┌────────┴────────┐

        │                 │

     Parsing          MLX42

        │                 │

        └────────┬────────┘

                 │

              Player

                 │

            Raycasting

                 │

        Texture Mapping

                 │

          destroy_game()
```

---

# Estruturas Principais

## t_game

Responsável por armazenar todo o estado do jogo.

---

## t_map

Responsável pelos dados carregados do arquivo `.cub`.

---

## t_player

Responsável pelo estado atual do jogador.

---

## t_texture

Responsável pelas quatro texturas utilizadas pelo renderer.

---

## t_ray

Estrutura auxiliar utilizada durante o raycasting.

---

# Fluxo do Programa

```text
main()

↓

validar argumentos

↓

init_game()

↓

parse()

↓

validate()

↓

init_mlx()

↓

load_textures()

↓

init_player()

↓

mlx_loop()

↓

destroy_game()
```

---

# Ordem de Implementação

---

# Parte 1 — Estruturas

## Objetivo

Definir todas as estruturas do projeto.

---

## Arquivos

```text
types.h

cub3D.h
```

---

## Checklist

* [x] t_game
* [x] t_map
* [x] t_player
* [x] t_texture
* [x] t_ray

---

# Parte 2 — init_game()

## Arquivo

```text
init_game.c
```

---

## Objetivo

Inicializar completamente a estrutura principal.

---

## Inicializar

* [ ] ponteiros com NULL
* [ ] contadores
* [ ] dimensões
* [ ] cores padrão
* [ ] estruturas auxiliares

---

## Fluxo

```text
malloc game

↓

zerar estrutura

↓

inicializar valores padrão

↓

retornar game
```

---

## Funções

* [ ] init_game()
* [x] init_map()
* [ ] init_player()
* [ ] init_textures()

---

# Parte 3 — Valores Padrão

## Objetivo

Garantir que nenhuma estrutura contenha lixo de memória.

---

## Exemplos

```c
game->mlx = NULL;
game->window = NULL;

game->map.grid = NULL;

game->textures[0] = NULL;
```

---

## Checklist

* [ ] ponteiros inicializados
* [ ] dimensões zeradas
* [ ] flags zeradas

---

# Parte 4 — Sistema de Erros

## Arquivo

```text
errors.c
```

---

## Objetivo

Centralizar todas as mensagens de erro.

---

## Funções

* [x] error()
* [ ] error_exit()
* [ ] print_error()

---

## Formato

```text
Error

Invalid file extension
```

---

## Casos

* malloc
* open
* read
* textura
* mapa
* MLX

---

# Parte 5 — Cleanup

## Arquivo

```text
cleanup.c
```

---

## Objetivo

Criar funções reutilizáveis para desalocação de memória.

---

## Funções

* [ ] free_matrix()
* [ ] free_textures()
* [ ] free_images()
* [ ] cleanup()

---

## Checklist

* [ ] matriz
* [ ] texturas
* [ ] imagens
* [ ] estruturas

---

# Parte 6 — destroy_game()

## Arquivo

```text
destroy_game.c
```

---

## Objetivo

Destruir completamente todos os recursos do projeto.

---

## Ordem

```text
loop

↓

imagens

↓

texturas

↓

janela

↓

MLX

↓

mapa

↓

player

↓

game
```

---

## Funções

* [ ] destroy_images()
* [ ] destroy_window()
* [ ] destroy_textures()
* [ ] destroy_game()

---

# Parte 7 — Tratamento de Falhas

## Objetivo

Garantir que qualquer erro encerre o programa corretamente.

---

## Casos

* malloc falhou
* MLX falhou
* textura inválida
* parser falhou
* mapa inválido

---

## Fluxo

```text
Erro

↓

cleanup()

↓

destroy_game()

↓

EXIT_FAILURE
```

---

# Parte 8 — Organização do Projeto

## Objetivo

Definir convenções para todo o desenvolvimento.

---

## Convenções

* uma responsabilidade por arquivo;
* funções pequenas;
* evitar variáveis globais;
* utilizar `const` quando possível;
* manter a API dos módulos consistente.

---

## Organização

```text
src/

game/

parsing/

hooks/

raycasting/

rendering/

utils/
```

---

# Checklist

## Estruturas

* [ ] todas definidas
* [ ] inicializadas corretamente

---

## Inicialização

* [ ] init_game()
* [x] init_map()
* [ ] init_player()
* [ ] init_textures()

---

## Erros

* [ ] mensagens padronizadas
* [ ] tratamento centralizado

---

## Cleanup

* [ ] funções reutilizáveis
* [ ] sem duplicação

---

## Destruição

* [ ] destroy_game()
* [ ] ordem correta

---

# Testes

## Inicialização

* [ ] game criado
* [ ] ponteiros válidos
* [ ] valores padrão

---

## Falhas

* [ ] malloc
* [ ] abertura de arquivo
* [ ] MLX
* [ ] texturas

---

## Cleanup

Executar múltiplas inicializações e encerramentos consecutivos.

---

## Valgrind

```bash
valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./cub3D maps/tests/valid_basic.cub
```

---

## Norminette

```bash
norminette src/game src/utils inc
```

---

# Casos Críticos

## Falha parcial

Se uma etapa falhar durante a inicialização, liberar apenas os recursos já alocados.

---

## Double Free

Garantir que recursos nunca sejam liberados duas vezes.

---

## Ponteiros Nulos

Todas as funções de destruição devem aceitar ponteiros `NULL`.

---

## Ordem de Destruição

A liberação deve ocorrer na ordem inversa da inicialização.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] estruturas definidas
* [ ] `init_game()` funcionando
* [ ] `destroy_game()` funcionando
* [ ] sistema de erros centralizado
* [ ] cleanup reutilizável

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] pronto para Parsing
* [ ] pronto para Validation
* [ ] pronto para MLX
* [ ] infraestrutura completa

---

# Próxima Etapa

➡️ **01_parsing.md**

Objetivos da próxima etapa:

* validar o arquivo `.cub`;
* realizar o parsing de texturas e cores;
* construir o grid do mapa;
* localizar o jogador;
* preencher a estrutura `t_game` com as informações do mapa.
