# 🚧 ETAPA 05 — Raycasting

> **Sprint:** 4
>
> **Responsável:**
>
> **Período:** 05/08 → 08/08
>
> **Dificuldade:** ⭐⭐⭐⭐⭐

---

# Objetivo

Implementar o motor de raycasting responsável por transformar o mapa 2D em uma visualização 3D.

Ao final desta etapa o projeto deverá ser capaz de:

* lançar um raio para cada coluna da tela;
* detectar a primeira parede atingida;
* calcular corretamente a distância perpendicular;
* calcular a altura da parede;
* desenhar paredes sem texturas.

Neste momento o jogo já deverá ser completamente navegável.

---

# Resultado Esperado

```text
Mapa

↓

Posição do jogador

↓

Lançar um raio

↓

Executar DDA

↓

Encontrar parede

↓

Calcular distância

↓

Calcular altura

↓

Desenhar coluna

↓

Imagem 3D
```

---

# Arquivos Envolvidos

## src/raycasting/

```text
ray_init.c

ray_distance.c

ray_dda.c

raycast.c
```

---

## src/rendering/

```text
draw_line.c

render_frame.c
```

---

# Dependências

Esta etapa depende de:

* Parsing
* Validation
* MLX
* Player
* Renderização básica

---

# Conceitos Fundamentais

Antes de iniciar esta etapa é importante compreender:

* Vetor direção
* Plano da câmera
* Campo de visão (FOV)
* Raios
* DDA (Digital Differential Analyzer)
* Distância perpendicular
* Fish-eye effect
* Projeção em perspectiva

---

# Fluxo Geral

```text
render_frame()

↓

para cada coluna da tela

↓

criar raio

↓

DDA

↓

encontrar parede

↓

calcular distância

↓

calcular altura

↓

desenhar coluna

↓

próxima coluna
```

---

# Estruturas Utilizadas

## t_ray

```c
typedef struct s_ray
{
	double	camera_x;

	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	double	perp_wall_dist;

	int		step_x;
	int		step_y;

	int		side;

	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;
```

---

# Ordem de Implementação

---

# Parte 1 — Inicialização do Raio

## Arquivo

```text
ray_init.c
```

---

## Objetivo

Inicializar todas as informações necessárias para um único raio.

---

## Calcular

* [ ] camera_x
* [ ] ray_dir_x
* [ ] ray_dir_y
* [ ] map_x
* [ ] map_y

---

## Fórmula

```text
camera_x

↓

[-1 ... +1]
```

---

## Resultado

Cada coluna possui um raio diferente.

---

# Parte 2 — Delta Distance

## Arquivo

```text
ray_distance.c
```

---

## Objetivo

Calcular a distância necessária para atravessar uma célula do grid.

---

## Calcular

* [ ] delta_dist_x
* [ ] delta_dist_y

---

## Objetivo Matemático

Determinar quanto o raio percorre até cruzar uma linha vertical ou horizontal do mapa.

---

# Parte 3 — Step

## Objetivo

Determinar para qual direção o raio irá caminhar.

---

## Calcular

* [ ] step_x
* [ ] step_y

---

## Casos

```text
ray_dir_x > 0

↓

step_x = +1
```

```text
ray_dir_x < 0

↓

step_x = -1
```

Mesmo processo para Y.

---

# Parte 4 — Side Distance

## Objetivo

Calcular a primeira interseção do raio com a malha do mapa.

---

## Calcular

* [ ] side_dist_x
* [ ] side_dist_y

---

## Resultado

Primeira distância até uma linha vertical e horizontal.

---

# Parte 5 — Algoritmo DDA

## Arquivo

```text
ray_dda.c
```

---

## Objetivo

Percorrer o grid até encontrar uma parede.

---

## Fluxo

```text
Enquanto não encontrar parede

↓

side_dist_x < side_dist_y ?

↓

SIM

↓

andar em X

↓

NÃO

↓

andar em Y

↓

encontrou parede?

↓

fim
```

---

## Funções

* [ ] perform_dda()

---

## Resultado

Obter:

* posição da parede
* lado atingido

---

# Parte 6 — Distância Perpendicular

## Arquivo

```text
ray_distance.c
```

---

## Objetivo

Eliminar o efeito fish-eye.

---

## Calcular

* [ ] perp_wall_dist

---

## Resultado

A distância utilizada para projetar a parede na tela.

---

# Parte 7 — Altura da Parede

## Objetivo

Converter distância em altura.

---

## Calcular

* [ ] line_height
* [ ] draw_start
* [ ] draw_end

---

## Resultado

```text
Perto

↓

Parede alta
```

```text
Longe

↓

Parede baixa
```

---

# Parte 8 — Renderização da Coluna

## Arquivo

```text
draw_line.c
```

---

## Objetivo

Desenhar uma única coluna vertical correspondente ao raio.

---

## Funções

* [ ] draw_vertical_line()

---

## Dados

* posição X
* draw_start
* draw_end
* cor da parede

---

## Resultado

Uma parede sólida.

---

# Parte 9 — Loop de Raycasting

## Arquivo

```text
raycast.c
```

---

## Objetivo

Executar o algoritmo completo para todas as colunas da tela.

---

## Fluxo

```text
Para x = 0

↓

Inicializar raio

↓

DDA

↓

Calcular distância

↓

Desenhar coluna

↓

x++

↓

Repetir até WIDTH
```

---

# Checklist

## Inicialização

* [ ] camera_x
* [ ] ray_dir

---

## Distâncias

* [ ] delta_dist
* [ ] side_dist

---

## Navegação

* [ ] step
* [ ] DDA

---

## Projeção

* [ ] perp_wall_dist
* [ ] line_height
* [ ] draw_start
* [ ] draw_end

---

## Renderização

* [ ] draw_vertical_line()
* [ ] raycast()

---

# Testes

## Jogador próximo da parede

Parede ocupa grande parte da tela.

---

## Jogador distante

Parede pequena.

---

## Rotação

Sem distorções.

---

## Corredor

Linhas paralelas.

---

## Canto

Sem falhas de renderização.

---

## Distâncias

Objetos mais próximos devem parecer maiores.

---

## Fish-eye

Não deve existir distorção lateral.

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
norminette src/raycasting src/rendering
```

---

# Casos Críticos

## Raio paralelo ao eixo X

Verificar divisão por zero.

---

## Raio paralelo ao eixo Y

Verificar divisão por zero.

---

## Jogador muito próximo da parede

A projeção deve permanecer estável.

---

## Corredores estreitos

Não pode haver tremulação.

---

## Rotação contínua

Não deve ocorrer efeito "fish-eye".

---

## Precisão

Utilizar `double` em todos os cálculos do raycaster.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] um raio lançado por coluna
* [ ] algoritmo DDA funcionando
* [ ] paredes detectadas corretamente
* [ ] distância perpendicular correta
* [ ] projeção em perspectiva funcionando
* [ ] paredes renderizadas sem texturas

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] integrado ao Player
* [ ] integrado à MLX
* [ ] pronto para Texturização

---

# Próxima Etapa

➡️ **06_texture_mapping.md**

Objetivos da próxima etapa:

* carregar texturas XPM;
* selecionar a textura correta (N, S, E, W);
* calcular a coordenada X da textura;
* aplicar textura em cada coluna da parede;
* adicionar sombreamento por orientação da parede.
