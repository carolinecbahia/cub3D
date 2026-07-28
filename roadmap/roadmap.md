# Roadmap do cub3D

> **Prazo de Entrega:** **14/08/2026**
>
> **Integrantes**

### anunes-o

- Parsing
- Validação
- Flood Fill
- Inicialização do Jogo
- Tratamento de Erros
- Mapas de Teste
- Documentação

### ccavalca

- MLX42
- Renderização
- Jogador
- Raycasting
- Mapeamento de Texturas

---

# Estratégia de Desenvolvimento

## Responsabilidades

### Pessoa A — Parsing e Core

Responsável por toda a infraestrutura do projeto.

- Parsing
- Validação
- Flood Fill
- Inicialização do Jogo
- Gerenciamento de Memória
- Tratamento de Erros
- Testes
- Documentação

### Pessoa B — Motor de Renderização

Responsável por todo o motor gráfico.

- MLX42
- Renderização
- Jogador
- Hooks de Entrada
- Raycasting
- Mapeamento de Texturas

---

# Fluxo de Trabalho com Git

## Estratégia de Branches

```text
master
└── develop
    ├── feature/parsing
    ├── feature/validation
    ├── feature/floodfill
    ├── feature/game
    ├── feature/mlx
    ├── feature/rendering
    ├── feature/player
    ├── feature/raycasting
    ├── feature/textures
    ├── feature/tests
    └── feature/docs
```

## Regras

- Nunca realizar commits diretamente na `master`;
- Trabalhar apenas em branches `feature/*`;
- Fazer merge somente após a conclusão dos testes;
- Atualizar a branch (`pull`) antes de iniciar qualquer desenvolvimento;
- Resolver conflitos imediatamente;
- Manter commits pequenos, objetivos e descritivos.

## Convenção de Commits

```text
feat:
fix:
refactor:
test:
docs:
style:
```

---

# Estrutura do Repositório

```text
cub3D/
├── inc/
├── src/
│   ├── game/
│   ├── hooks/
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   └── utils/
├── maps/
├── textures/
├── libft/
├── MLX42/
├── Makefile
└── README.md
```

---

# Sprint 0 — Configuração do Projeto

**Meta:** 29/07

## Checklist Geral

- [ ] Revisar o subject
- [ ] Revisar a arquitetura do projeto
- [ ] Revisar as structs
- [ ] Revisar o Makefile
- [ ] Revisar os arquivos de cabeçalho (`includes`)
- [ ] Verificar se o projeto compila corretamente

## Git

- [x] Atualizar a branch `features`
- [x] Criar as branches de desenvolvimento
- [ ] Definir a estratégia de merge
- [ ] Definir convenções de código

### Entrega da Sprint

- [x] Projeto compilando com sucesso.

---

# Sprint 1 — Parsing e Fundação da MLX

**Meta:** 02/08

## Pessoa A

### Parsing

- [ ] path_validation.c
- [ ] textures_parsing.c
- [ ] color_parsing.c
- [ ] map_parsing.c
- [ ] map_building.c
- [ ] parsing_utils.c
- [ ] map_utils.c
- [ ] grid_utils.c

### Inicialização do Jogo

- [ ] init_game.c
- [ ] init_player.c

### Entrega da Sprint

- Arquivo `.cub` interpretado corretamente.
- Estruturas principais do jogo inicializadas.

---

## Pessoa B

### MLX42

- [ ] mlx_init()
- [ ] Criação da janela
- [ ] Criação da imagem
- [ ] Buffer de imagem
- [ ] Registro dos hooks
- [ ] Encerramento correto da aplicação

### Renderização

- [ ] put_pixel.c

### Entrega da Sprint

- Janela da MLX funcionando de forma estável.

---

# Sprint 2 — Validação e Renderização do Plano de Fundo

**Meta:** 05/08

## Pessoa A

### Validação

- [ ] map_validation.c
- [ ] validation_utils.c

### Validações Obrigatórias

- [ ] Validação da extensão
- [ ] Validação das texturas
- [ ] Validação das cores RGB
- [ ] Validação dos caracteres
- [ ] Validação de jogador único
- [ ] Validação das dimensões do mapa

### Flood Fill

- [ ] Verificar se o mapa está completamente fechado

### Entrega da Sprint

- Todos os mapas válidos são aceitos.
- Todos os mapas inválidos são rejeitados.

---

## Pessoa B

### Renderização

- [ ] render_background.c
- [ ] render_frame.c

### Eventos da Janela

- [ ] ESC encerra o programa
- [ ] Botão de fechar da janela
- [ ] Renderização do teto
- [ ] Renderização do piso

### Entrega da Sprint

- Plano de fundo renderizado corretamente.

---

# Sprint 3 — Tratamento de Erros e Jogador

**Meta:** 08/08

## Pessoa A

### Jogo

- [ ] destroy_game.c

### Utilitários

- [ ] errors.c
- [ ] cleanup.c
- [ ] debug.c *(se necessário)*
- [ ] strings.c *(se necessário)*

### Mapas de Teste

- [ ] Extensão inválida
- [ ] Textura inválida
- [ ] RGB inválido
- [ ] Caractere inválido
- [ ] Jogador ausente
- [ ] Múltiplos jogadores
- [ ] Mapa aberto

### Entrega da Sprint

- Módulo de parsing finalizado.
- Limpeza de memória e tratamento de erros implementados corretamente.

---

## Pessoa B

### Hooks

- [ ] key_hook.c
- [ ] update_hook.c
- [ ] movement.c
- [ ] rotation.c
- [ ] collision.c
- [ ] close_hook.c

### Entrega da Sprint

- Movimentação e colisão do jogador funcionando corretamente.

# Sprint 4 — Raycasting

**Meta:** 11/08

## Pessoa B

### Raycasting

- [ ] ray_init.c
- [ ] ray_distance.c
- [ ] ray_dda.c
- [ ] raycast.c

### Entrega da Sprint

- Paredes 3D renderizadas corretamente.

---

# Sprint 5 — Mapeamento de Texturas

**Meta:** 12/08

## Pessoa B

### Jogo

- [ ] load_textures.c

### Renderização

- [ ] texture_sampling.c

### Raycasting

- [ ] ray_texture.c

### Entrega da Sprint

- Paredes renderizadas com as texturas corretas.

---

# Sprint 6 — Integração

**Meta:** 13/08

## Integração

- [ ] Parser integrado ao sistema de renderização
- [ ] Jogador utilizando o mapa processado
- [ ] Renderizador utilizando as texturas carregadas
- [ ] Loop principal do jogo completo

### Entrega da Sprint

- cub3D totalmente jogável.

---

# Sprint 7 — Revisão Final

**Meta:** 13/08

## Estabilidade

- [ ] Sem vazamentos de memória
- [ ] Sem `invalid read`
- [ ] Sem `invalid write`
- [ ] Sem `segmentation fault`

## Norminette

- [ ] Projeto totalmente compatível com a Norminette

## Documentação

- [ ] README concluído
- [ ] Capturas de tela (screenshots)
- [ ] Instruções de compilação
- [ ] Instruções de testes

## Preparação para a Avaliação

- [ ] Explicar o Parsing
- [ ] Explicar a Validação
- [ ] Explicar o Flood Fill
- [ ] Explicar o algoritmo DDA
- [ ] Explicar o Raycasting
- [ ] Explicar o Mapeamento de Texturas
- [ ] Explicar o uso da MLX42

### Entrega da Sprint

- Projeto pronto para avaliação.

---

# Checklist do Subject

## Parsing

- [ ] Ler o arquivo `.cub`
- [ ] Interpretar as texturas
- [ ] Interpretar as cores
- [ ] Interpretar o mapa
- [ ] Identificar o jogador

## Validação

- [ ] Validar extensão
- [ ] Validar texturas
- [ ] Validar RGB
- [ ] Validar caracteres
- [ ] Validar jogador único
- [ ] Validar mapa fechado

## Janela

- [ ] Janela abre corretamente
- [ ] Janela permanece responsiva
- [ ] ESC encerra o programa
- [ ] Botão de fechar funciona

## Renderização

- [ ] Renderizar teto
- [ ] Renderizar piso
- [ ] Textura Norte
- [ ] Textura Sul
- [ ] Textura Leste
- [ ] Textura Oeste

## Controles

- [ ] W
- [ ] A
- [ ] S
- [ ] D
- [ ] Seta Esquerda
- [ ] Seta Direita

## Geral

- [ ] Sem vazamentos de memória
- [ ] Sem segmentation fault
- [ ] Mensagens de erro adequadas
- [ ] Norminette aprovada

---

# Mapas de Teste

## Mapas Válidos

- [ ] Mapa pequeno
- [ ] Mapa grande
- [ ] Espaços internos no mapa
- [ ] Jogador voltado para Norte
- [ ] Jogador voltado para Sul
- [ ] Jogador voltado para Leste
- [ ] Jogador voltado para Oeste

## Mapas Inválidos

- [ ] Abertura na parte superior
- [ ] Abertura na parte inferior
- [ ] Abertura na esquerda
- [ ] Abertura na direita
- [ ] Textura inválida
- [ ] Textura ausente
- [ ] RGB inválido
- [ ] Múltiplos jogadores
- [ ] Jogador ausente
- [ ] Caractere inválido

---

# Checklist de Build

- [ ] make
- [ ] make clean
- [ ] make fclean
- [ ] make re

---

# Bônus *(Somente Após o Mandatory)*

- [ ] Minimap
- [ ] Rotação com o mouse
- [ ] Portas
- [ ] Sprites animados

> ⚠️ **Não inicie o bônus antes que o projeto mandatory esteja totalmente funcional, sem vazamentos de memória, compatível com a Norminette e completamente testado.**

---

# Fluxo de Desenvolvimento

O desenvolvimento seguirá uma abordagem incremental, onde cada sprint produz uma entrega funcional que servirá de base para a sprint seguinte.

```text
Sprint 0
      │
      ▼
Core
      │
      ▼
Parsing
      │
      ▼
Validação
      │
      ▼
MLX
      │
      ▼
Jogador
      │
      ▼
Raycasting
      │
      ▼
Mapeamento de Texturas
      │
      ▼
Integração
      │
      ▼
Revisão Final
      │
      ▼
Entrega
```

---

# Fluxo de Trabalho com Git

Durante o desenvolvimento, cada funcionalidade deverá ser implementada em uma branch própria.

```text
main
 │
 └── develop
      ├── feature/core
      ├── feature/parsing
      ├── feature/validation
      ├── feature/mlx
      ├── feature/player
      ├── feature/raycasting
      ├── feature/texture-mapping
      ├── feature/integration
      └── feature/final-review
```

## Regras

- Todo o desenvolvimento será realizado em branches `feature/*`;
- O merge será realizado para `develop` ao final de cada sprint;
- A branch `main` será utilizada apenas para versões estáveis e para a entrega;
- Resolver conflitos imediatamente após cada integração;
- Não iniciar uma nova sprint enquanto houver conflitos pendentes.

---

# Critérios de Conclusão do Projeto

O projeto será considerado concluído quando todos os itens abaixo forem atendidos.

## Funcionalidades

- Parsing completo;
- Validação completa;
- MLX inicializada;
- Jogador funcional;
- Raycasting funcionando;
- Mapeamento de Texturas aplicado;
- Integração concluída.

---

## Qualidade

- Norminette aprovada;
- Compilação sem warnings;
- Sem vazamentos de memória;
- Sem `invalid read`;
- Sem `invalid write`;
- Sem `segmentation fault`.

---

## Testes

- Todos os mapas válidos executam corretamente;
- Todos os mapas inválidos retornam erro;
- Movimentação funcionando;
- Colisão funcionando;
- Renderização correta;
- Texturas orientadas corretamente.

---

## Entrega

- README atualizado;
- Repositório organizado;
- Branch `main` atualizada;
- Projeto preparado para a avaliação da 42.

---

# Documentos do Projeto

| Documento | Objetivo |
|-----------|----------|
| **00_core.md** | Arquitetura, inicialização, gerenciamento de memória e tratamento de erros |
| **01_parsing.md** | Leitura e interpretação do arquivo `.cub` |
| **02_validation.md** | Validação completa do mapa e das regras do subject |
| **03_mlx.md** | Inicialização da MLX42 e infraestrutura gráfica |
| **04_player.md** | Inicialização e movimentação do jogador |
| **05_raycasting.md** | Implementação do algoritmo de Raycasting (DDA) |
| **06_texture_mapping.md** | Aplicação de texturas e sombreamento |
| **07_integration.md** | Integração de todos os módulos do projeto |
| **08_final_review.md** | Revisão final, testes, Valgrind e preparação para a avaliação |

---

# Resultado Esperado

Ao término deste roadmap, o projeto deverá possuir:

- arquitetura modular e organizada;
- código compatível com a Norminette;
- gerenciamento correto de memória;
- renderização completa utilizando Raycasting;
- texturas aplicadas corretamente;
- documentação técnica de todas as etapas do desenvolvimento;
- projeto pronto para avaliação e entrega na 42 São Paulo.