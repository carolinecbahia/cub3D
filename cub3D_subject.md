# 🎯 Guia de Requisitos: cub3D

## Capítulo I - Introdução

Desenvolvido pela Id Software, liderado pela equipe lendária de John Carmack e John Romero, e publicado em 1992 pela Apogee Software, Wolfenstein 3D é o primeiro verdadeiro "First Person Shooter" na história dos videogames.

Wolfenstein 3D é o ancestral de clássicos como Doom (Id Software, 1993), Doom II (Id Software, 1994), Duke Nukem 3D (3D Realm, 1996) e Quake (Id Software, 1996) — marcos eternos no mundo dos videogames.

Agora é a sua vez de reviver a história...

Este projeto é inspirado neste lendário Wolfenstein 3D, considerado o primeiro FPS da história dos videogames. Você irá explorar os princípios do ray-casting para criar uma visão dinâmica em primeira pessoa dentro de um labirinto, onde precisará encontrar o caminho até a saída. O objetivo é aprender sobre gráficos, matemática aplicada, manipulação de eventos e otimizar algoritmos em C, usando a MiniLibX.

**Com este projeto, você irá:**
- Implementar um RayCaster do zero usando algoritmos clássicos
- Manipular gráficos 2D/3D com MiniLibX
- Praticar parsing robusto, validação e manipulação de arquivos
- Aprender sobre performance, texturização e eventos de teclado
- Compreender matemática aplicada em gráficos (trigonometria, projeção, ray-casting)

**Objetivos do Projeto:**
Os objetivos são similares aos de todo o primeiro ano: rigor, uso de C, algoritmos básicos, pesquisa de informações, etc. Como um projeto de design gráfico, cub3D permitirá melhorar suas habilidades em: janelas, cores, eventos, preenchimento de formas, etc. Concluindo, cub3D é um excelente playground para explorar as aplicações práticas e divertidas da matemática sem precisar entender os detalhes específicos.

Com a ajuda de diversos documentos disponíveis na internet, você usará matemática como ferramenta para criar algoritmos elegantes e eficientes.

## Capítulo II - Instruções Comuns

- **Linguagem**: Seu projeto deve ser escrito em C.
- **Norma**: Seu projeto deve estar em conformidade com a Norm 42. Bônus também são verificados.
- **Comportamento**: Suas funções não devem sair inesperadamente (segfault, bus error, double free, etc.).
- **Memória**: Toda memória alocada deve ser liberada. Vazamentos não serão tolerados.
- **Makefile**: Envie um Makefile com as flags `-Wall -Wextra -Werror`, usando `cc`. Não faça relinking desnecessário.
- **Regras do Makefile**: Deve conter pelo menos as regras `$(NAME)`, `all`, `clean`, `fclean`, `re`, `bonus`.
- **Bônus**: Para bônus, use arquivos `_bonus.c/h` e a regra `bonus` no Makefile. Avaliação obrigatória e bônus são separadas.
- **Libft**: Permitida. Copie fontes e Makefile para a pasta `libft/` e integre ao build.
- **Restrições Específicas**: O uso de variáveis globais é proibido, exceto se explicitamente permitido.
- **Testes**: Crie programas de teste para facilitar sua defesa.
- **Submissão**: Envie seu trabalho para o repositório Git designado. Apenas o conteúdo do repositório será avaliado.

## Capítulo III - Instruções de IA

### Contexto
Durante sua jornada, a IA pode auxiliar em diversas tarefas. Explore as ferramentas, mas sempre revise criticamente os resultados. Use apenas conteúdo que você compreenda e possa explicar.

### Mensagem Principal
☛ Use IA para automatizar tarefas repetitivas.
☛ Desenvolva habilidades de prompting e revisão.
☛ Aprenda como sistemas de IA funcionam para evitar riscos e vieses.
☛ Trabalhe em equipe e busque revisão de pares.
☛ Só use conteúdo gerado por IA que você compreenda totalmente.

### Regras de Aprendizado
- Explore ferramentas de IA e entenda seu funcionamento.
- Reflita sobre o problema antes de perguntar.
- Revise, questione e teste tudo que for gerado por IA.
- Sempre busque revisão de colegas.

### Resultados Esperados
- Habilidade em prompting e revisão crítica.
- Maior produtividade com IA.
- Fortalecimento do pensamento computacional e colaboração.

### Exemplos
- Boa prática: Uso IA para gerar ideias, reviso com colega, refinamos juntos.
- Má prática: Copio código da IA sem entender, não consigo explicar na avaliação.

## Capítulo IV - Visão Geral do Projeto

**Nome do programa**: cub3D
**Descrição**: Meu primeiro RayCaster com MiniLibX

Este projeto consiste em criar uma representação gráfica 3D realista do interior de um labirinto, a partir da perspectiva de primeira pessoa, usando ray-casting. O objetivo é renderizar o ambiente, permitir movimentação e rotação do jogador, e aplicar texturas e cores ao cenário.

**Características Principais:**
- Parsing e validação de arquivos .cub
- Renderização 3D com ray-casting
- Texturização de paredes (N/S/E/W)
- Cores customizáveis para teto e chão
- Movimentação (WASD) e rotação (setas)
- Fechamento limpo da janela (ESC e red cross)

## Capítulo V - Configuração Técnica

**Arquivos a entregar**: Makefile, *.h, *.c, mapas de teste, texturas
**Regras do Makefile**: NAME, all, clean, fclean, re, bonus
**Argumentos**: Um arquivo de mapa no formato *.cub
**Libft autorizada**: Sim

**Funções Externas Autorizadas**:
- Entrada/Saída: `open`, `close`, `read`, `write`, `printf`
- Memória: `malloc`, `free`
- Erros: `perror`, `strerror`
- Controle: `exit`
- Tempo: `gettimeofday`
- Matemática: Todas as funções de `math.h` (compilar com `-lm`)
- MiniLibX: Todas as funções da biblioteca MiniLibX
- Libft: Autorizada (copie fontes e Makefile para pasta `libft/`)

**Requisitos de Compilação**:
- Compilador: `cc`
- Flags: `-Wall -Wextra -Werror`
- Link: `-lm` para math.h
- Sem relinking desnecessário

## Capítulo VI - Parte Obrigatória

### 1. Parsing e Validação do Arquivo .cub

Seu programa deve tomar como primeiro argumento um arquivo de descrição de cena com extensão `.cub`.

**Formato do Arquivo:**

- **Texturas** (identidade de 2 caracteres):
  - `NO ./path_to_the_north_texture` — textura para parede norte
  - `SO ./path_to_the_south_texture` — textura para parede sul
  - `WE ./path_to_the_west_texture` — textura para parede oeste
  - `EA ./path_to_the_east_texture` — textura para parede leste

- **Cores** (identidade de 1 caractere):
  - `F 220,100,0` — cor do chão (RGB: 0-255)
  - `C 225,30,0` — cor do teto (RGB: 0-255)

- **Mapa**:
  - Composto apenas por: `0` (espaço vazio), `1` (parede), `N/S/E/W` (posição e orientação do player)
  - Deve ser fechado/cercado por paredes
  - Espaços são parte válida do mapa
  - Sempre deve ser o último elemento do arquivo

**Regras de Parsing:**

- Cada tipo de elemento (exceto mapa) pode ser separado por uma ou mais linhas vazias
- Cada tipo de elemento (exceto mapa) pode estar em qualquer ordem
- Cada tipo de informação pode ser separado por um ou mais espaços (exceto mapa)
- O mapa deve ser exatamente como aparece no arquivo (inclua espaços)
- Parsing deve validar:
  - Extensão `.cub` do arquivo
  - Existência e validade dos caminhos de textura
  - Valores de cor RGB no intervalo [0, 255]
  - Presença de exatamente um player (N, S, E ou W)
  - Mapa fechado por paredes (sem aberturas)
  - Nenhum caractere inválido no mapa

**Tratamento de Erros:**

Se qualquer erro de configuração for encontrado, o programa deve sair corretamente com `"Error\n"` seguido de uma mensagem de erro explícita de sua escolha.

### 2. Renderização e Interação

**Renderização Ray-Casting:**
- Usar os princípios de ray-casting para criar representação 3D realista
- Renderizar paredes com perspectiva correta de primeira pessoa
- Aplicar texturas diferentes para cada orientação (N, S, E, W)
- Aplicar cores do chão e teto conforme especificado

**Controles do Teclado:**
- **Setas esquerda/direita**: Rotacionar o ponto de vista (olhar para esquerda/direita)
- **W, A, S, D**: Mover o ponto de vista através do labirinto
  - W: Mover para frente
  - S: Mover para trás
  - A: Mover para esquerda
  - D: Mover para direita

**Fechamento da Janela:**
- **ESC**: Fechar janela e sair do programa limpamente
- **Red cross (X)**: Fechar janela ao clicar no botão fechar e sair limpamente

**Gerenciamento de Janela:**
- Deve permanecer responsivo ao trocar de janelas
- Deve suportar minimização sem travamentos
- Uso de imagens da MiniLibX é fortemente recomendado
- Performance suave sem travamentos ou lag perceptível

### 3. Exemplo de Arquivo .cub Mínimo

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### 4. Gestão de Memória e Comportamento

- Sem vazamentos de memória (deve passar em valgrind)
- Sem segmentation faults ou comportamentos indefinidos
- Código em conformidade com a Norma 42
- Se libft é usada, deve estar compilada corretamente
- Tratamento apropriado de erros de arquivo/entrada

## Capítulo VI - Requisitos do README

Um arquivo `README.md` deve ser fornecido na raiz do seu repositório Git. Seu propósito é permitir que qualquer pessoa desconhecida com o projeto (colegas, equipe, recrutadores, etc.) compreenda rapidamente do que se trata, como executá-lo e onde encontrar mais informações sobre o tópico.

**O README.md deve incluir no mínimo:**

- **Primeira linha em itálico**: *This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]*
- **Seção "Description"**: Apresentação clara do projeto, incluindo objetivo e visão geral breve
- **Seção "Instructions"**: Informações sobre compilação, instalação e/ou execução
- **Seção "Resources"**: Referências clássicas relacionadas ao tópico (documentação, artigos, tutoriais, etc.)
  - Incluir descrição de como a IA foi usada — especificando para quais tarefas e quais partes do projeto

**Recomendações Adicionais:**

- Você pode incluir seções adicionais conforme necessário (exemplos de uso, lista de características, escolhas técnicas, etc.)
- O README deve estar em inglês

## Capítulo VII - Parte Bônus

**Bônus será avaliado apenas se a parte obrigatória estiver perfeita.**

Por perfeito, naturalmente significa que precisa estar completo, que não pode falhar, nem mesmo em casos de erros desagradáveis como uso incorreto, etc. Significa que se sua parte obrigatória não obtiver TODOS os pontos durante a avaliação, seus bônus serão completamente IGNORADOS.

**Lista de Bônus:**

- Colisão com paredes (não atravessar paredes)
- Sistema de minimap 2D
- Portas que podem abrir e fechar
- Sprites animados
- Rotação do ponto de vista com o mouse

Você será capaz de criar jogos melhores mais tarde — não desperdice muito tempo!

Você tem permissão para usar outras funções ou adicionar símbolos no mapa para completar a parte de bônus, desde que seu uso seja justificado durante sua avaliação. Você também tem permissão para modificar o formato do arquivo de cena esperado para atender suas necessidades. Seja esperto!

## Capítulo VIII - Submissão e Avaliação

- **Submissão**: Envie seu trabalho para o repositório Git designado como usual. Apenas o trabalho dentro do seu repositório será avaliado durante a defesa.
- **Verificação de Arquivos**: Verifique cuidadosamente os nomes de seus arquivos e diretórios.
- **Modificação Durante Avaliação**: Ocasionalmente, uma breve modificação do projeto pode ser solicitada durante a avaliação. Isso pode envolver uma mudança de comportamento menor, algumas linhas de código a escrever ou um recurso fácil de adicionar.
- **Escopo**: Esta etapa visa verificar sua compreensão real de uma parte específica do projeto. A modificação deve ser viável dentro de alguns minutos.
- **Exemplos**: Você pode ser solicitado a fazer uma pequena atualização em uma função, modificar uma exibição, ajustar uma estrutura para armazenar novas informações, etc.

---

## Dica de Ouro

O segredo deste projeto é: priorize o parser e a validação do mapa antes de qualquer renderização. Sem parsing robusto, não há jogo! Teste mapas inválidos, bordas abertas, múltiplos players e abuse do valgrind. Uma vez que o parser esteja sólido, a renderização ray-casting se torna um exercício matemático elegante. Comece simples (sem texturas), depois adicione gradualmente texturas, cores e otimizações. Você encontrará mais satisfação em um raycaster simples mas correto do que em um complexo mas bugado.
