# 🚧 ETAPA 06 — Texture Mapping

> **Sprint:** 5
>
> **Responsável:**
>
> **Período:** 12/08 → 15/08
>
> **Dificuldade:** ⭐⭐⭐⭐⭐

---

# Objetivo

Aplicar texturas às paredes renderizadas pelo raycaster.

Ao final desta etapa o projeto deverá ser capaz de:

* carregar as quatro texturas XPM;
* identificar corretamente qual face da parede foi atingida;
* calcular a coordenada da textura;
* desenhar cada coluna utilizando pixels da textura;
* aplicar sombreamento simples nas paredes laterais.

Após esta etapa o jogo terá aparência semelhante ao Wolfenstein 3D.

---

# Resultado Esperado

```text
Arquivo .cub

↓

Carregar texturas

↓

Ray encontra parede

↓

Selecionar textura

↓

Calcular coordenada

↓

Amostrar pixels

↓

Renderizar coluna texturizada
```

---

# Arquivos Envolvidos

## src/game/

```text
load_textures.c
```

---

## src/rendering/

```text
texture_sampling.c
draw_line.c
```

---

## src/raycasting/

```text
ray_texture.c
```

---

# Dependências

Esta etapa depende de:

* Parsing concluído
* Validation concluída
* MLX funcionando
* Raycasting funcionando
* Paredes renderizadas corretamente

---

# Conceitos Fundamentais

Nesta etapa serão utilizados:

* Texture Mapping
* UV Coordinates
* Texture Sampling
* Wall Projection
* Texture Scaling
* Pixel Sampling
* Wall Orientation
* Shading

---

# Fluxo Geral

```text
Raycast

↓

Parede encontrada

↓

Selecionar textura

↓

Calcular wall_x

↓

Calcular texture_x

↓

Percorrer textura

↓

Desenhar coluna
```

---

# Estruturas Utilizadas

## t_texture

```c
typedef struct s_texture
{
	mlx_texture_t	*texture;
	uint32_t		*pixels;
	int				width;
	int				height;
}	t_texture;
```

---

# Ordem de Implementação

---

# Parte 1 — Carregamento das Texturas

## Arquivo

```text
load_textures.c
```

---

## Objetivo

Carregar todas as texturas informadas no arquivo `.cub`.

---

## Texturas

* [ ] Norte
* [ ] Sul
* [ ] Leste
* [ ] Oeste

---

## Funções

* [ ] load_texture()
* [ ] load_all_textures()
* [ ] destroy_textures()

---

## Validações

* arquivo existe
* formato XPM válido
* textura carregada corretamente

---

## Testes

* textura inexistente
* textura inválida
* quatro texturas carregadas

---

# Parte 2 — Seleção da Textura

## Arquivo

```text
ray_texture.c
```

---

## Objetivo

Selecionar qual textura utilizar com base na direção da parede atingida.

---

## Casos

```text
Parede Norte

↓

NO
```

```text
Parede Sul

↓

SO
```

```text
Parede Oeste

↓

WE
```

```text
Parede Leste

↓

EA
```

---

## Funções

* [ ] select_texture()

---

# Parte 3 — Cálculo da Posição na Parede

## Objetivo

Determinar exatamente onde o raio atingiu a parede.

---

## Calcular

* [ ] wall_x

---

## Resultado

```text
0.00 ─────────────── 1.00
```

Representa a posição horizontal do impacto na parede.

---

# Parte 4 — Coordenada X da Textura

## Objetivo

Converter `wall_x` em um pixel horizontal da textura.

---

## Calcular

* [ ] texture_x

---

## Ajustes

Corrigir inversão dependendo da direção da parede.

---

## Resultado

```text
wall_x

↓

texture_x

↓

Pixel da textura
```

---

# Parte 5 — Escala Vertical

## Arquivo

```text
texture_sampling.c
```

---

## Objetivo

Calcular como a textura será escalada para caber na parede projetada.

---

## Calcular

* [ ] step
* [ ] texture_pos

---

## Resultado

Cada pixel da parede corresponde ao pixel correto da textura.

---

# Parte 6 — Amostragem da Textura

## Objetivo

Obter a cor correta para cada pixel desenhado.

---

## Fluxo

```text
Linha da tela

↓

texture_y

↓

texture_x

↓

Cor

↓

put_pixel()
```

---

## Funções

* [ ] sample_texture()

---

# Parte 7 — Desenho da Coluna

## Arquivo

```text
draw_line.c
```

---

## Objetivo

Substituir a parede sólida pela textura correspondente.

---

## Fluxo

```text
draw_start

↓

Percorrer coluna

↓

Amostrar textura

↓

Desenhar pixel

↓

draw_end
```

---

## Funções

* [ ] draw_textured_wall()

---

# Parte 8 — Sombreamento

## Objetivo

Adicionar profundidade visual escurecendo paredes laterais.

---

## Regra

```text
Parede Vertical

↓

100%
```

```text
Parede Horizontal

↓

70%
```

*(ou outro fator definido pelo projeto.)*

---

## Funções

* [ ] apply_shading()

---

# Checklist

## Texturas

* [ ] quatro texturas carregadas
* [ ] memória armazenada corretamente

---

## Seleção

* [ ] Norte
* [ ] Sul
* [ ] Leste
* [ ] Oeste

---

## Mapeamento

* [ ] wall_x
* [ ] texture_x
* [ ] texture_y

---

## Renderização

* [ ] coluna texturizada
* [ ] sem distorções

---

## Sombreamento

* [ ] paredes laterais escurecidas

---

# Testes

## Aproximar da parede

A textura deve ampliar corretamente.

---

## Afastar da parede

A textura deve reduzir proporcionalmente.

---

## Rotação

A textura deve permanecer estável.

---

## Canto

Troca correta entre texturas.

---

## Parede Norte

Utiliza apenas textura Norte.

---

## Parede Sul

Utiliza apenas textura Sul.

---

## Parede Leste

Utiliza apenas textura Leste.

---

## Parede Oeste

Utiliza apenas textura Oeste.

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
norminette src/rendering src/raycasting src/game
```

---

# Casos Críticos

## Textura invertida

Verificar orientação de `texture_x`.

---

## Tremulação

Garantir estabilidade durante a movimentação.

---

## Costuras entre paredes

As texturas devem alinhar corretamente.

---

## Texturas de tamanhos diferentes

Validar dimensões antes do carregamento.

---

## Coordenadas fora da textura

Nunca acessar pixels fora dos limites.

---

## Precisão

Utilizar `double` em todos os cálculos intermediários.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] quatro texturas carregadas
* [ ] textura correta aplicada em cada face
* [ ] coordenadas calculadas corretamente
* [ ] paredes texturizadas
* [ ] sombreamento funcionando

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] integrado ao Raycasting
* [ ] integrado à MLX
* [ ] pronto para Integração Final

---

# Próxima Etapa

➡️ **07_integration.md**

Objetivos da próxima etapa:

* integrar todos os módulos do projeto;
* revisar o ciclo completo de execução;
* otimizar o loop de renderização;
* realizar testes de integração;
* preparar o projeto para a etapa final de revisão e defesa.
