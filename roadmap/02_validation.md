# 🚧 ETAPA 02 — Validation do Arquivo `.cub`

> **Sprint:** 2
>
> **Responsável:**
>
> **Período:** 02/08 → 05/08
>
> **Dificuldade:** ⭐⭐⭐⭐⭐

---

# Objetivo

Garantir que o mapa carregado durante o parsing atende **todas as regras exigidas pelo subject do cub3D**.

Esta etapa **não deve modificar o mapa**, apenas validar sua consistência antes que o restante do programa seja inicializado.

Ao final desta etapa, somente mapas completamente válidos deverão chegar ao módulo de renderização.

---

# Resultado Esperado

Entrada

```
char **grid
```

↓

```
Validação da estrutura
```

↓

```
Validação dos caracteres
```

↓

```
Validação do player
```

↓

```
Validação das bordas
```

↓

```
Flood Fill
```

↓

```
Mapa aprovado
```

---

# Arquivos Envolvidos

## src/parsing/

```
map_validation.c

validation_utils.c
```

---

# Dependências

Esta etapa depende de:

* Parsing concluído
* t_game preenchido
* Grid do mapa criado
* Posição inicial do player encontrada

---

# Fluxo Geral

```text
grid

↓

validate dimensions

↓

validate characters

↓

validate player

↓

validate borders

↓

flood fill

↓

map valid
```

---

# Regras do Subject

O mapa deve:

* possuir exatamente um jogador;
* conter apenas caracteres válidos;
* estar completamente fechado;
* permitir espaços externos;
* não possuir vazamentos;
* possuir todos os elementos obrigatórios carregados.

---

# Ordem de Implementação

---

# Parte 1 — Dimensões do Mapa

## Objetivo

Validar largura e altura do grid.

O parser pode receber linhas de tamanhos diferentes.

A validação deve trabalhar sobre o grid normalizado.

---

## Arquivo

```
validation_utils.c
```

---

## Funções

* [ ] get_map_width()
* [ ] get_map_height()
* [ ] validate_dimensions()

---

## Casos

### Válido

```
111111

100001

10N001

111111
```

---

### Também válido

```
111111

100001111

10N001

111111
```

Após normalização.

---

# Parte 2 — Caracteres Permitidos

## Objetivo

Garantir que apenas caracteres permitidos existam no mapa.

---

## Caracteres válidos

```
0

1

N

S

E

W

(espaço)
```

---

## Caracteres inválidos

```
A

B

2

X

#

@

$

*
```

---

## Arquivo

```
map_validation.c
```

---

## Funções

* [ ] validate_characters()

---

## Testes

### Válido

```
111111

100001

10N001

111111
```

---

### Inválido

```
111111

100A01

111111
```

---

# Parte 3 — Player

## Objetivo

Garantir que exista exatamente um jogador.

---

## Casos válidos

```
N

S

E

W
```

---

## Casos inválidos

```
NN

NS

NW

(nenhum player)
```

---

## Funções

* [ ] validate_player()

---

## Resultado

```
1 player

↓

OK
```

---

# Parte 4 — Bordas do Mapa

## Objetivo

Garantir que nenhuma área jogável toque diretamente o exterior.

---

## Casos válidos

```
111111

100001

10N001

111111
```

---

## Casos inválidos

```
111111

100001

10N000

11111
```

---

## Funções

* [ ] validate_borders()

---

# Parte 5 — Espaços

## Objetivo

Tratar corretamente espaços presentes no mapa.

Segundo o subject, espaços representam área externa.

Eles nunca podem permitir acesso às áreas jogáveis.

---

## Exemplo válido

```
   111111

   100001

11110N001

111111111
```

---

## Exemplo inválido

```
111111

10 001

10N001

111111
```

Se o espaço criar comunicação com uma área jogável.

---

## Funções

* [ ] validate_spaces()

---

# Parte 6 — Flood Fill

## Objetivo

Detectar vazamentos invisíveis no mapa.

Este é o teste definitivo para validar um mapa.

---

## Arquivo

```
map_validation.c
```

---

## Fluxo

```
posição do player

↓

cópia do mapa

↓

flood fill

↓

tocou espaço externo?

↓

SIM → erro

↓

NÃO → válido
```

---

## Algoritmo

```
player

↓

N

↓

S

↓

L

↓

O

↓

recursão
```

ou versão iterativa.

---

## Casos válidos

```
111111

100001

10N001

111111
```

---

## Casos inválidos

```
111111

100000

10N001

11111
```

---

## Funções

* [ ] flood_fill()
* [ ] validate_closed_map()

---

# Parte 7 — Mensagens de Erro

## Objetivo

Padronizar todas as mensagens.

---

## Exemplos

```
Error

Invalid file extension
```

```
Error

Invalid character in map
```

```
Error

Map is not closed
```

```
Error

Multiple players found
```

```
Error

Missing player
```

```
Error

Invalid RGB value
```

---

## Funções

* [ ] error_exit()
* [ ] print_error()

---

# Checklist

## Estrutura

* [ ] dimensões válidas
* [ ] grid consistente

---

## Caracteres

* [ ] apenas caracteres válidos

---

## Player

* [ ] apenas um jogador

---

## Bordas

* [ ] bordas fechadas

---

## Espaços

* [ ] espaços tratados corretamente

---

## Flood Fill

* [ ] sem vazamentos

---

## Erros

* [ ] mensagens padronizadas

---

# Casos de Teste

## Mapas válidos

```
valid_basic.cub

spaces_valid.cub
```

---

## Mapas inválidos

```
double_player.cub

invalid_char.cub

space_leak.cub

open_wall.cub

newline_in_map.cub
```

---

# Testes

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
norminette src/parsing inc
```

---

# Casos Críticos

## Mapa aberto

```
111111

100001

10N000

11111
```

↓

Erro.

---

## Múltiplos jogadores

```
111111

10N0S1

111111
```

↓

Erro.

---

## Caractere inválido

```
111111

10A001

111111
```

↓

Erro.

---

## Espaço vazando

```
111111

10 001

10N001

111111
```

↓

Erro.

---

## Player inexistente

```
111111

100001

100001

111111
```

↓

Erro.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] aceita mapas válidos
* [ ] rejeita mapas inválidos
* [ ] valida caracteres
* [ ] valida player
* [ ] valida bordas
* [ ] executa flood fill corretamente
* [ ] trata espaços corretamente

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] parser + validation funcionando
* [ ] pronto para inicializar a MLX
* [ ] pronto para iniciar a renderização

---

# Próxima Etapa

➡️ **03_mlx.md**

Objetivos da próxima etapa:

* inicializar a MLX42;
* criar a janela;
* criar a imagem principal;
* configurar os hooks;
* desenhar teto e chão;
* preparar o buffer de renderização.
