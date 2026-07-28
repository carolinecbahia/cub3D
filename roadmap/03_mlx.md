# 🚧 ETAPA 03 — Setup da MLX42

> **Sprint:** 3
>
> **Responsável:**
>
> **Período:** 29/07 → 02/08
>
> **Dificuldade:** ⭐⭐⭐☆☆

---

# Objetivo

Inicializar completamente a **MLX42**, criando toda a infraestrutura gráfica necessária para o restante do projeto.

Ao final desta etapa o projeto deverá:

* inicializar a MLX42;
* criar uma janela;
* criar o framebuffer principal;
* registrar os hooks;
* renderizar teto e chão;
* fechar corretamente a aplicação.

**Nenhum raycasting será implementado nesta etapa.**

---

# Resultado Esperado

Entrada

```text id="a5qkbx"
./cub3D maps/tests/valid_basic.cub
```

↓

```text id="e7ud0r"
MLX inicializada
```

↓

```text id="rw2mki"
Janela criada
```

↓

```text id="sz4x6u"
Framebuffer criado
```

↓

```text id="m8tvf0"
Hooks registrados
```

↓

```text id="4a2sh8"
Tela exibe teto e chão
```

---

# Arquivos Envolvidos

## src/game/

```text id="smd3tq"
load_textures.c
```

*(Será implementado apenas na etapa de texturas.)*

---

## src/rendering/

```text id="qyn8ye"
put_pixel.c
render_background.c
render_frame.c
```

---

## src/hooks/

```text id="v3g18g"
close_hook.c
```

---

## src/game/

```text id="f0ru2q"
init_game.c
```

*(Apenas integração com a MLX já criada.)*

---

# Dependências

Esta etapa depende de:

* Parsing concluído
* Validation concluída
* Estrutura `t_game` preenchida

---

# Fluxo Geral

```text id="hz1ixm"
main()

↓

mlx_init()

↓

criar janela

↓

criar imagem

↓

registrar hooks

↓

desenhar fundo

↓

mlx_loop()
```

---

# Conceitos Importantes

Nesta etapa será utilizada a API da **MLX42**.

Principais conceitos:

* Contexto MLX
* Janela
* Framebuffer
* Imagem
* Loop principal
* Hooks
* Atualização da tela

---

# Ordem de Implementação

---

# Parte 1 — Inicialização da MLX

## Objetivo

Criar o contexto principal da biblioteca.

---

## Funções

* [ ] mlx_init()

---

## Resultado

```text id="zz4uzm"
game->mlx != NULL
```

---

## Casos de erro

* Falha ao iniciar a MLX

---

# Parte 2 — Criação da Janela

## Objetivo

Criar a janela principal.

---

## Funções

* [ ] mlx_new_window()

---

## Configurações

```text id="5mwjlwm"
WIDTH

HEIGHT

"cub3D"
```

---

## Resultado

Janela aberta.

---

# Parte 3 — Criação do Framebuffer

## Objetivo

Criar a imagem onde toda a renderização será realizada.

Nunca desenhar diretamente na janela.

---

## Funções

* [ ] mlx_new_image()

---

## Estrutura

```text id="ib06a6"
game->screen
```

---

## Resultado

Framebuffer criado.

---

# Parte 4 — Inserção da Imagem

## Objetivo

Adicionar o framebuffer à janela.

---

## Funções

* [ ] mlx_image_to_window()

---

## Resultado

Imagem visível.

---

# Parte 5 — put_pixel()

## Arquivo

```text id="ek95gw"
put_pixel.c
```

---

## Objetivo

Criar a função responsável por alterar um único pixel do framebuffer.

---

## Funções

* [ ] put_pixel()

---

## Validações

* coordenadas negativas
* coordenadas maiores que WIDTH
* coordenadas maiores que HEIGHT

---

## Testes

Desenhar:

* ponto branco
* linha horizontal
* linha vertical

---

# Parte 6 — Renderização do Fundo

## Arquivo

```text id="whlym5"
render_background.c
```

---

## Objetivo

Renderizar apenas:

* teto
* chão

Sem paredes.

---

## Dados

Utilizar:

```text id="6mddq6"
map.ceiling_color

map.floor_color
```

---

## Resultado

```text id="5u0g5z"
────────────

TETO

────────────

CHÃO
```

---

# Parte 7 — Renderização do Frame

## Arquivo

```text id="tpmshk"
render_frame.c
```

---

## Objetivo

Centralizar toda a renderização da tela.

Inicialmente deverá chamar apenas:

* render_background()

No futuro será responsável por:

* raycasting
* sprites
* minimap
* HUD

---

## Fluxo

```text id="1o2z2v"
render_frame()

↓

render_background()

↓

(atualmente termina aqui)
```

---

# Parte 8 — Hooks

## Arquivo

```text id="a2g0ye"
close_hook.c
```

---

## Objetivo

Permitir fechar corretamente a aplicação.

---

## Eventos

* [ ] ESC
* [ ] Botão fechar janela

---

## Resultado

Programa encerrando corretamente.

---

# Parte 9 — Loop Principal

## Objetivo

Executar continuamente o programa.

---

## Funções

* [ ] mlx_loop()

---

## Fluxo

```text id="30q8bs"
while (game running)

↓

render_frame()

↓

espera eventos
```

---

# Checklist

## MLX

* [ ] MLX inicializada

---

## Janela

* [ ] janela criada
* [ ] tamanho correto
* [ ] título correto

---

## Framebuffer

* [ ] imagem criada
* [ ] imagem adicionada à janela

---

## Renderização

* [ ] put_pixel()
* [ ] render_background()
* [ ] render_frame()

---

## Hooks

* [ ] ESC
* [ ] fechar janela

---

# Testes

## Execução

```bash
./cub3D maps/tests/valid_basic.cub
```

---

## Resultado esperado

* janela abre
* teto aparece
* chão aparece
* sem travamentos
* ESC fecha
* botão fechar funciona

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
norminette src/rendering src/hooks
```

---

# Casos Críticos

## MLX não inicializa

↓

Mensagem de erro.

---

## Janela não abre

↓

Encerrar corretamente.

---

## Framebuffer inválido

↓

Liberar recursos e sair.

---

## ESC

↓

Finalizar aplicação sem leaks.

---

## Fechar janela

↓

Finalizar aplicação sem leaks.

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] MLX inicializa corretamente
* [ ] janela criada
* [ ] framebuffer criado
* [ ] renderização do fundo funcionando
* [ ] hooks funcionando
* [ ] loop principal funcionando

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] parser integrado
* [ ] cores carregadas do `.cub`
* [ ] pronto para iniciar o Player
* [ ] pronto para iniciar o Raycasting

---

# Próxima Etapa

➡️ **04_player.md**

Objetivos da próxima etapa:

* inicializar o jogador;
* implementar movimentação (WASD);
* implementar rotação;
* implementar colisões;
* integrar atualização por frame com o loop da MLX.
