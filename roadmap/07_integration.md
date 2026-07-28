# 🚧 ETAPA 07 — Integração do Sistema

> **Sprint:** 6
>
> **Responsáveis:**
>
> **Período:** 15/08 → 17/08
>
> **Dificuldade:** ⭐⭐⭐⭐☆

---

# Objetivo

Integrar todos os módulos desenvolvidos nas etapas anteriores em um único fluxo de execução estável.

Ao final desta etapa o projeto deverá:

* executar todo o pipeline automaticamente;
* carregar qualquer mapa válido;
* inicializar corretamente todos os módulos;
* renderizar o ambiente completo;
* permitir movimentação contínua;
* encerrar corretamente sem vazamentos de memória.

O foco desta etapa **não é adicionar novas funcionalidades**, mas garantir que todos os componentes funcionem juntos.

---

# Resultado Esperado

```text
./cub3D maps/valid.cub

↓

Parsing

↓

Validation

↓

Inicialização

↓

MLX

↓

Player

↓

Raycasting

↓

Texture Mapping

↓

Loop Principal

↓

Jogo Funcionando
```

---

# Módulos Integrados

## Parsing

* leitura do arquivo
* texturas
* cores
* mapa
* player

---

## Validation

* caracteres
* player único
* bordas
* flood fill
* espaços
* mensagens de erro

---

## MLX

* inicialização
* janela
* framebuffer
* hooks

---

## Player

* movimentação
* rotação
* colisão

---

## Raycasting

* DDA
* distância
* projeção

---

## Texture Mapping

* carregamento
* seleção
* renderização

---

# Fluxo Geral do Programa

```text
main()

↓

Inicializar estruturas

↓

Parsing

↓

Validation

↓

Inicializar MLX

↓

Carregar texturas

↓

Inicializar Player

↓

Registrar Hooks

↓

mlx_loop()

↓

update()

↓

render_frame()

↓

raycast()

↓

texture_mapping()

↓

renderização final
```

---

# Ordem de Integração

---

# Parte 1 — Inicialização

## Objetivo

Garantir que todos os módulos sejam inicializados na ordem correta.

---

## Checklist

* [ ] argumentos
* [ ] parsing
* [ ] validation
* [ ] MLX
* [ ] texturas
* [ ] player

---

## Testes

* inicialização completa
* inicialização com erro
* limpeza correta

---

# Parte 2 — Loop Principal

## Objetivo

Verificar se o fluxo completo funciona continuamente.

---

## Fluxo

```text
Frame

↓

Input

↓

Player

↓

Raycasting

↓

Texture Mapping

↓

Renderização

↓

Próximo Frame
```

---

## Checklist

* [ ] atualização contínua
* [ ] renderização contínua
* [ ] sem travamentos

---

# Parte 3 — Integração dos Hooks

## Objetivo

Garantir que todos os eventos estejam funcionando.

---

## Eventos

* [ ] ESC
* [ ] fechar janela
* [ ] W
* [ ] A
* [ ] S
* [ ] D
* [ ] ←
* [ ] →

---

# Parte 4 — Testes Funcionais

## Objetivo

Executar todos os cenários previstos pelo subject.

---

## Parsing

* [ ] mapa válido
* [ ] extensão inválida
* [ ] textura inexistente
* [ ] RGB inválido

---

## Validation

* [ ] múltiplos players
* [ ] player inexistente
* [ ] mapa aberto
* [ ] caractere inválido

---

## Player

* [ ] movimento
* [ ] rotação
* [ ] colisão

---

## Renderização

* [ ] paredes
* [ ] texturas
* [ ] teto
* [ ] chão

---

# Parte 5 — Testes de Performance

## Objetivo

Verificar estabilidade durante uso contínuo.

---

## Testes

* [ ] movimentação contínua
* [ ] rotação contínua
* [ ] mapas grandes
* [ ] corredores estreitos
* [ ] cantos
* [ ] paredes próximas

---

# Parte 6 — Tratamento de Erros

## Objetivo

Garantir encerramento seguro em qualquer falha.

---

## Casos

* erro de parsing
* erro na MLX
* textura inválida
* malloc falhou
* arquivo inexistente

---

## Checklist

* [ ] liberar memória
* [ ] destruir imagens
* [ ] destruir janela
* [ ] destruir contexto MLX
* [ ] fechar arquivos

---

# Parte 7 — Limpeza Geral

## Objetivo

Centralizar toda a desalocação do projeto.

---

## Verificar

* [ ] grid
* [ ] texturas
* [ ] imagens
* [ ] MLX
* [ ] estruturas auxiliares

---

## Ferramentas

```bash
valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./cub3D maps/tests/valid_basic.cub
```

---

# Checklist de Integração

## Sistema

* [ ] inicializa corretamente
* [ ] fecha corretamente

---

## Parsing

* [ ] integrado

---

## Validation

* [ ] integrado

---

## MLX

* [ ] integrado

---

## Player

* [ ] integrado

---

## Raycasting

* [ ] integrado

---

## Texture Mapping

* [ ] integrado

---

## Memória

* [ ] sem leaks

---

# Casos de Teste

## Inicialização

* [ ] mapa válido
* [ ] mapa inválido
* [ ] argumentos incorretos

---

## Gameplay

* [ ] explorar mapa inteiro
* [ ] colisão em todos os lados
* [ ] rotação completa
* [ ] movimentação contínua

---

## Encerramento

* [ ] ESC
* [ ] botão fechar
* [ ] erro durante execução

---

# Build

```bash
make

make clean

make fclean

make re
```

---

# Norminette

```bash
norminette src inc
```

---

# Git

Antes de finalizar esta etapa:

* [ ] atualizar `develop`
* [ ] resolver conflitos
* [ ] revisar PRs
* [ ] remover código morto
* [ ] remover `printf()` de debug
* [ ] revisar comentários

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] jogo totalmente jogável
* [ ] pipeline completo funcionando
* [ ] renderização estável
* [ ] movimentação fluida
* [ ] texturas funcionando
* [ ] tratamento de erros completo

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK

---

## Integração

* [ ] todos os módulos conectados
* [ ] nenhuma dependência quebrada
* [ ] pronto para avaliação

---

# Próxima Etapa

➡️ **08_final_review.md**

Objetivos da próxima etapa:

* revisão completa do projeto;
* revisão da Norminette;
* testes finais;
* revisão da defesa;
* preparação para a avaliação na 42;
* organização da branch `master`;
* planejamento dos bônus (apenas após o mandatory estar completamente estável).
