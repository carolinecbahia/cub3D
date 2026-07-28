# 🚧 ETAPA 08 — Final Review e Preparação para Avaliação

> **Sprint:** Final
>
> **Responsáveis:**
>
> **Período:**
>
> **Dificuldade:** ⭐⭐⭐⭐⭐

---

# Objetivo

Realizar uma revisão completa do projeto antes da avaliação.

Nenhuma funcionalidade nova deverá ser implementada nesta etapa.

O objetivo é garantir que:

* o projeto esteja estável;
* todos os requisitos do subject sejam atendidos;
* não existam vazamentos de memória;
* a Norminette seja aprovada;
* a dupla esteja preparada para defender todas as decisões técnicas.

---

# Fluxo da Revisão

```text
Clone do repositório

↓

make

↓

Testes obrigatórios

↓

Norminette

↓

Valgrind

↓

Revisão de código

↓

Revisão do subject

↓

Simulação da avaliação

↓

Entrega
```

---

# Revisão do Build

## Makefile

Verificar:

* [ ] make
* [ ] make clean
* [ ] make fclean
* [ ] make re

---

## Compilação

* [ ] sem warnings
* [ ] sem erros
* [ ] sem dependências quebradas

---

## Testes

```bash
make

make clean

make fclean

make re
```

---

# Revisão da Norminette

## Executar

```bash
norminette src inc
```

---

## Conferir

* [ ] funções ≤ 25 linhas
* [ ] máximo de parâmetros
* [ ] indentação
* [ ] nomes corretos
* [ ] includes organizados
* [ ] arquivos sem erros

---

# Revisão de Memória

## Executar

```bash
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./cub3D maps/tests/valid_basic.cub
```

---

## Verificar

* [ ] 0 leaks
* [ ] 0 invalid read
* [ ] 0 invalid write
* [ ] 0 definitely lost
* [ ] 0 indirectly lost

---

# Revisão do Subject

## Parsing

* [ ] extensão
* [ ] leitura
* [ ] texturas
* [ ] cores
* [ ] mapa

---

## Validation

* [ ] mapa fechado
* [ ] player único
* [ ] caracteres válidos
* [ ] flood fill

---

## MLX

* [ ] janela
* [ ] imagem
* [ ] eventos

---

## Player

* [ ] movimentação
* [ ] rotação
* [ ] colisão

---

## Raycasting

* [ ] DDA
* [ ] distância perpendicular
* [ ] projeção

---

## Texture Mapping

* [ ] quatro texturas
* [ ] orientação correta
* [ ] sem distorções

---

# Testes Obrigatórios

## Arquivos Válidos

* [ ] mapa pequeno
* [ ] mapa grande
* [ ] mapa com espaços
* [ ] todas as direções do player

---

## Arquivos Inválidos

* [ ] extensão inválida
* [ ] textura inexistente
* [ ] RGB inválido
* [ ] múltiplos jogadores
* [ ] jogador inexistente
* [ ] caractere inválido
* [ ] mapa aberto
* [ ] linhas vazias inválidas

---

# Testes de Gameplay

## Movimento

* [ ] andar para frente
* [ ] andar para trás
* [ ] strafe
* [ ] rotação

---

## Colisão

* [ ] parede frontal
* [ ] parede lateral
* [ ] cantos
* [ ] corredores

---

## Renderização

* [ ] paredes corretas
* [ ] teto
* [ ] chão
* [ ] texturas corretas
* [ ] sem fish-eye

---

# Revisão de Código

## Organização

* [ ] funções pequenas
* [ ] responsabilidade única
* [ ] nomes claros
* [ ] código duplicado removido

---

## Arquitetura

Verificar se o fluxo permanece consistente:

```text
main()

↓

Parsing

↓

Validation

↓

MLX

↓

Player

↓

Raycasting

↓

Texture Mapping

↓

Renderização

↓

Cleanup
```

---

# Cleanup

Confirmar que toda memória é liberada.

## Liberar

* [ ] grid
* [ ] texturas
* [ ] imagens
* [ ] MLX
* [ ] estruturas auxiliares

---

# Git

Antes da entrega:

* [ ] branch `develop` atualizada
* [ ] merge final realizado
* [ ] conflitos resolvidos
* [ ] commits organizados
* [ ] tags criadas (opcional)

---

# README

Verificar:

* [ ] descrição do projeto
* [ ] instruções de compilação
* [ ] instruções de execução
* [ ] estrutura do projeto
* [ ] dependências
* [ ] autores

---

# Simulação da Avaliação

Cada integrante deverá conseguir explicar:

## Parsing

* [ ] Como o `.cub` é lido?
* [ ] Como as texturas são armazenadas?
* [ ] Como as cores são convertidas?

---

## Validation

* [ ] Como funciona o flood fill?
* [ ] Como detectar mapa aberto?
* [ ] Como tratar espaços?

---

## MLX

* [ ] Como funciona o loop da MLX?
* [ ] Diferença entre janela e imagem?
* [ ] Como os hooks funcionam?

---

## Player

* [ ] Vetor direção
* [ ] Plano da câmera
* [ ] Colisão

---

## Raycasting

* [ ] O que é `camera_x`?
* [ ] O que é DDA?
* [ ] Como calcular `delta_dist`?
* [ ] Como calcular `side_dist`?
* [ ] O que é `perp_wall_dist`?
* [ ] Como evitar o efeito fish-eye?

---

## Texture Mapping

* [ ] Como escolher a textura?
* [ ] Como calcular `wall_x`?
* [ ] Como calcular `texture_x`?
* [ ] Como desenhar uma coluna texturizada?

---

# Checklist Final

## Mandatory

* [ ] 100% funcional

---

## Código

* [ ] Norminette OK
* [ ] Valgrind OK
* [ ] Sem warnings

---

## Projeto

* [ ] README atualizado
* [ ] Estrutura organizada
* [ ] Código revisado

---

## Defesa

* [ ] Ambos dominam todas as etapas
* [ ] Ambos conseguem explicar o algoritmo de DDA
* [ ] Ambos conseguem explicar o Texture Mapping
* [ ] Ambos conseguem explicar a arquitetura completa

---

# Critérios de Conclusão (Definition of Done)

## Funcional

* [ ] todos os requisitos obrigatórios implementados
* [ ] projeto totalmente jogável
* [ ] todos os testes aprovados

---

## Código

* [ ] sem leaks
* [ ] sem invalid reads
* [ ] sem invalid writes
* [ ] sem segfault
* [ ] norminette OK
* [ ] compilação sem warnings

---

## Entrega

* [ ] repositório organizado
* [ ] branch principal atualizada
* [ ] projeto pronto para avaliação da 42

---

# Pós-Entrega

Após a aprovação do **mandatory**, iniciar apenas então o desenvolvimento dos bônus.

## Backlog de Bônus

* [ ] Minimap
* [ ] Portas
* [ ] Mouse Look
* [ ] Sprites animados
* [ ] Animações
* [ ] HUD
* [ ] FPS Counter
* [ ] Otimizações de renderização

---

# 🎉 Projeto Mandatory Concluído

Se todos os itens acima estiverem marcados, o projeto está pronto para a avaliação e entrega do **cub3D**.
