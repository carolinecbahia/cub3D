# 🚧 ETAPA 04 — Player e Controles

> **Sprint:** 3
>
> **Responsável:**
>
> **Período:** 02/08 → 05/08
>
> **Dificuldade:** ⭐⭐⭐⭐☆

---

# Objetivo

Implementar toda a lógica relacionada ao jogador.

Ao final desta etapa o projeto deverá:

* inicializar corretamente o jogador a partir do parser;
* movimentar o jogador utilizando **WASD**;
* rotacionar utilizando **← →**;
* impedir atravessar paredes;
* atualizar a câmera em tempo real.

**Ainda não haverá raycasting.** O foco é garantir que toda a movimentação esteja pronta antes da renderização 3D.

---

# Resultado Esperado

```text
Parser

↓

Player encontrado

↓

Inicialização

↓

Hooks

↓

Movimento

↓

Colisão

↓

Rotação

↓

Player funcionando
```

---

# Arquivos Envolvidos

## src/game/

```text
init_player.c
```

*(Apenas integração, já inicializado pela etapa de Parsing.)*

---

## src/hooks/

```text
key_hook.c

movement.c

rotation.c

collision.c

update_hook.c
```

---

## src/utils/

```text
math_utils.c
```

*(Caso funções auxiliares sejam necessárias.)*

---

# Dependências

Esta etapa depende de:

* Parsing concluído
* Validation concluída
* MLX funcionando
* Janela criada
* Hooks registrados

---

# Fluxo Geral

```text
Parser

↓

Player inicializado

↓

Key Hook

↓

Movement

↓

Collision

↓

Rotation

↓

Update Hook
```

---

# Conceitos Importantes

Nesta etapa serão utilizados:

* Vetor direção
* Plano da câmera
* Delta Time (opcional)
* Colisão em grid
* Entrada do teclado
* Atualização contínua

---

# Estruturas Utilizadas

## t_player

```c
typedef struct s_player
{
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	double	move_speed;
	double	rot_speed;
}	t_player;
```

---

# Ordem de Implementação

---

# Parte 1 — Inicialização do Player

## Objetivo

Converter a posição encontrada durante o parsing em coordenadas reais do jogo.

---

## Arquivo

```text
init_player.c
```

---

## Inicializar

* [ ] posição X
* [ ] posição Y
* [ ] vetor direção
* [ ] plano da câmera
* [ ] velocidade
* [ ] velocidade de rotação

---

## Testes

```text
N

↓

dir = (0, -1)
```

```text
S

↓

dir = (0, 1)
```

```text
E

↓

dir = (1, 0)
```

```text
W

↓

dir = (-1, 0)
```

---

# Parte 2 — Key Hook

## Objetivo

Capturar eventos do teclado.

---

## Arquivo

```text
key_hook.c
```

---

## Teclas

* [ ] W
* [ ] A
* [ ] S
* [ ] D
* [ ] ←
* [ ] →

---

## Resultado

Cada tecla altera um estado de movimento.

---

# Parte 3 — Movimento

## Arquivo

```text
movement.c
```

---

## Objetivo

Implementar:

* mover para frente
* mover para trás
* strafe esquerda
* strafe direita

---

## Movimento

```text
W

↓

dir_x

dir_y
```

---

## Funções

* [ ] move_forward()
* [ ] move_backward()
* [ ] move_left()
* [ ] move_right()

---

## Testes

* andar continuamente
* parar corretamente
* movimentação suave

---

# Parte 4 — Rotação

## Arquivo

```text
rotation.c
```

---

## Objetivo

Rotacionar:

* esquerda
* direita

---

## Alterar

* vetor direção
* plano da câmera

---

## Funções

* [ ] rotate_left()
* [ ] rotate_right()

---

## Testes

* rotação contínua
* 360°
* sem perda de precisão

---

# Parte 5 — Colisão

## Arquivo

```text
collision.c
```

---

## Objetivo

Impedir que o jogador atravesse paredes.

---

## Regra

O jogador nunca poderá entrar em uma célula contendo:

```text
1
```

---

## Fluxo

```text
Nova posição

↓

É parede?

↓

SIM

↓

Cancela movimento

↓

NÃO

↓

Atualiza posição
```

---

## Funções

* [ ] check_collision()
* [ ] can_move()

---

## Casos

* parede frontal
* parede lateral
* canto
* corredor estreito

---

# Parte 6 — Update Hook

## Arquivo

```text
update_hook.c
```

---

## Objetivo

Atualizar continuamente o estado do jogador.

---

## Fluxo

```text
Frame

↓

Input

↓

Movimento

↓

Rotação

↓

Render
```

---

## Funções

* [ ] update_player()

---

# Checklist

## Player

* [ ] inicializado
* [ ] posição correta
* [ ] direção correta

---

## Input

* [ ] W
* [ ] A
* [ ] S
* [ ] D

---

## Rotação

* [ ] esquerda
* [ ] direita

---

## Colisão

* [ ] não atravessa paredes
* [ ] movimento bloqueado corretamente

---

## Atualização

* [ ] update por frame
* [ ] movimento contínuo

---

# Testes

## Movimento

* [ ] andar para frente
* [ ] andar para trás
* [ ] strafe esquerda
* [ ] strafe direita

---

## Rotação

* [ ] girar esquerda
* [ ] girar direita
* [ ] rotação completa

---

## Colisão

* [ ] parede frontal
* [ ] parede lateral
* [ ] canto
* [ ] corredor

---

## Execução

```bash
./cub3D maps/tests/valid_basic.cub
```

---

## Valgrind

```bash
valgrind --leak-check=full \
--show-leak-kinds=all \
./cub3D maps/tests/valid_basic.cub
```

---

## Norminette

```bash
norminette src/hooks src/game
```

---

# Casos Críticos

## Movimento diagonal

Verificar se a velocidade permanece consistente.

---

## Rotação contínua

Não perder precisão após muitas rotações.

---

## Colisão em cantos

Não permitir atravessar diagonais.

---

## Movimento contra parede

O jogador deve deslizar naturalmente quando possível.

---

## FPS variável

Caso seja utilizado Delta Time, manter velocidade independente da taxa de quadros.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] jogador inicializado
* [ ] movimentação completa
* [ ] rotação completa
* [ ] colisão funcionando
* [ ] atualização contínua

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] integrado com Parsing
* [ ] integrado com MLX
* [ ] pronto para Raycasting

---

# Próxima Etapa

➡️ **05_raycasting.md**

Objetivos da próxima etapa:

* lançar um raio para cada coluna da tela;
* implementar o algoritmo DDA;
* detectar paredes;
* calcular distância perpendicular;
* renderizar paredes em 3D (sem texturas).
