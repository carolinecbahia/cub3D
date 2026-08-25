# cub3D — Conclusion e rastreamento da finalização

## Objetivo

Centralizar o encerramento das Sprints 00–08 e acompanhar, com evidências, o que ainda precisa ser corrigido, testado ou documentado antes da avaliação do mandatory.

Este documento considera:

- `cub3D_subject.md` da branch `develop`;
- estado integrado atual da branch `develop`;
- correções realizadas nas Sprints 03–06;
- checklists das Sprints 07 e 08;
- organização atual de mapas em `maps/valid/` e `maps/invalid/`.

> Regra de uso: marcar um item como concluído apenas depois de executar o teste correspondente na versão atual da `develop`.

## Legenda

- [x] concluído e já observado durante a integração;
- [ ] pendente de correção ou verificação;
- [!] bloqueador objetivo do subject;
- [?] decisão técnica que precisa ser confirmada pela dupla ou pela 42SP.

---

# 0. Sprints 00–02 — Core, parsing e validation

## Sprint 00 — Core Architecture e inicialização

### Estruturas e arquitetura

- [x] `t_game` definido.
- [x] `t_map` definido.
- [x] `t_player` definido.
- [x] `t_ray` definido.
- [?] o roadmap lista `t_texture`, mas a implementação final usa diretamente `mlx_texture_t *textures[4]`.
- [ ] atualizar `00_core.md` para refletir as estruturas realmente usadas.
- [x] módulos separados em `game`, `parsing`, `hooks`, `raycasting`, `rendering` e `utils`.
- [x] ausência de um `init_game()` monolítico compensada por inicialização modular.

### Inicialização

- [x] `t_game` alocado com `ft_calloc()` na `main`.
- [x] ponteiros do jogo começam em `NULL`.
- [x] contadores e flags começam zerados.
- [x] `init_map()` define defaults do mapa.
- [x] `init_player()` inicializa posição, direção, plano e velocidades.
- [x] `init_mlx()` inicializa contexto e imagem.
- [x] `load_all_textures()` inicializa as texturas.
- [?] o roadmap exige `init_game()` e `init_textures()` nominais, mas o subject exige comportamento, não esses nomes.
- [ ] documentar no roadmap o fluxo modular escolhido.

Fluxo real atual:

```text
main
  -> ft_calloc(t_game)
  -> init_map
  -> parse_file
  -> init_player
  -> init_mlx
  -> init_image
  -> load_all_textures
  -> hooks e loop
  -> destroy_game
```

### Erros

- [x] helper central `return_error()` existente.
- [x] erros de MLX possuem mensagens próprias.
- [ ] [!] padronizar toda falha como `Error\n` + mensagem.
- [ ] evitar mistura de `printf`, `ft_putstr_fd` e formatos diferentes.
- [x] confirmar que mensagens não são duplicadas em falhas encadeadas.
- [x] testar malloc, open, parser, textura e MLX.

### Cleanup e destruição

- [x] `ft_free_matrix()` disponível.
- [x] `cleanup_map()` libera grid, path do mapa e paths de textura.
- [x] `destroy_textures()` aceita slots nulos e zera ponteiros.
- [x] `destroy_game()` centraliza encerramento da MLX, mapa e jogo.
- [x] rollback parcial de inicialização implementado.
- [ ] provar ordem e ownership com Valgrind.
- [x] testar falha na primeira, segunda, terceira e quarta textura.
- [ ] testar chamadas seguras após falha parcial.
- [ ] testar múltiplas execuções e encerramentos consecutivos.

### Pendências documentais da Sprint 00

- [ ] substituir caminhos antigos `maps/tests/...`.
- [ ] atualizar checkboxes já implementados.
- [ ] remover funções planejadas que não fazem parte da arquitetura final.
- [ ] substituir `t_texture` pela representação real.
- [ ] registrar que o projeto não usa `window` separada na MLX42.

---

## Sprint 01 — Parsing do arquivo `.cub`

### Arquivo e leitura

- [x] valida exatamente o sufixo `.cub`.
- [x] abre arquivo em modo de leitura.
- [x] lê o arquivo completo com GNL.
- [x] fecha descritores nos caminhos normais observados.
- [x] armazena as linhas em matriz terminada por `NULL`.
- [x] testar nome vazio.
- [x] testar arquivo inexistente.
- [x] testar diretório chamado `arquivo.cub`.
- [x] testar arquivo vazio.
- [x] testar arquivo sem permissão.
- [x] testar arquivo muito grande.
- [ ] validar Valgrind e `--track-fds=yes` em todas essas falhas.

### Texturas

- [x] reconhece `NO`, `SO`, `WE` e `EA`.
- [x] exige as quatro texturas.
- [x] rejeita textura duplicada.
- [x] salva paths dinamicamente.
- [x] [!] revisar restrição exclusiva a `.png`.
- [x] rejeitar diretório usado como path de textura.
- [x] rejeitar arquivo corrompido antes ou durante a inicialização gráfica.
- [x] testar espaços e tabs entre identificador e path.
- [x] decidir comportamento para espaços finais no path.
- [x] testar identificadores semelhantes, como `NOO`, `N` e `NORTH`.

### Cores

- [x] reconhece `F` e `C`.
- [x] exige uma cor de chão e uma de teto.
- [x] rejeita cor duplicada.
- [x] verifica intervalo final entre 0 e 255.
- [x] [!] substituir `ft_split()` + `ft_atoi()` por parsing estrito.
- [x] rejeitar componentes vazios.
- [x] rejeitar letras e sufixos.
- [x] rejeitar overflow.
- [x] validar quantidade exata de vírgulas.
- [x] testar espaços em todas as posições permitidas.

### Mapa e player

- [x] encontra o início do mapa.
- [x] exige mapa como último bloco.
- [x] calcula largura máxima e altura.
- [x] cria grid retangular interno.
- [x] preserva linhas originais e completa faltas com espaços externos.
- [x] encontra posição e direção do player.
- [x] rejeita múltiplos players.
- [x] rejeita ausência de mapa.
- [x] adicionar mapa explícito sem player.
- [x] adicionar mapa mínimo.
- [x] adicionar mapa grande.
- [x] testar informação após o mapa.
- [x] testar linha vazia após o início do mapa.

### Diferenças entre roadmap e implementação

- [x] `path_validation.c` não existe mais; responsabilidade distribuída entre `map_validation.c` e `validation_utils.c`.
- [x] `map_building.c` não existe mais; construção está em `map_parsing.c` e `grid_utils.c`.
- [x] o parsing preenche primeiro `t_map`; `t_player` é inicializado depois por `init_player()`.
- [x] exemplos do roadmap usam XPM, mas a implementação atual aceita PNG.
- [x] atualizar todos os comandos de `maps/tests` para `maps/valid` ou `maps/invalid`.

### Definition of Done da Sprint 01

- [x] abre `.cub` válido.
- [x] rejeita extensão inválida.
- [x] identifica texturas.
- [x] identifica cores.
- [x] cria grid.
- [x] encontra player.
- [x] dados chegam ao `t_game` durante a integração.
- [x] parsing estrito de RGB.
- [x] validação de textura generalizada/confirmada.
- [ ] Valgrind em todos os caminhos de erro.
- [x] Norminette completa.

---

## Sprint 02 — Validation do arquivo `.cub`

### Dimensões e caracteres

- [x] trabalha com linhas de tamanhos diferentes.
- [x] normaliza internamente pela largura máxima.
- [x] aceita `0`, `1`, `N`, `S`, `E`, `W` e espaço.
- [x] rejeita caracteres desconhecidos.
- [x] rejeita linha vazia dentro do mapa.
- [x] testar tabs dentro do mapa e confirmar decisão conforme o subject.
- [x] testar mapa com altura ou largura mínima.
- [x] testar mapa somente com paredes e player ausente.

### Player

- [x] aceita N, S, E ou W.
- [x] exige exatamente um player.
- [x] salva posição e direção.
- [x] troca a célula do player por `EMPTY` para o runtime.
- [?] `02_validation.md` afirma que validation não deve modificar o mapa, mas a implementação modifica a célula do player.
- [ ] decidir se a normalização permanece na validation ou é movida para `init_player()`.
- [ ] atualizar o roadmap para refletir a decisão.

### Fechamento do mapa e espaços

- [x] rejeita célula caminhável na borda externa.
- [x] rejeita célula caminhável ortogonalmente adjacente a espaço externo.
- [x] linhas curtas são completadas com espaços para a validação.
- [x] `open_wall.cub` e `space_leak.cub` fazem parte da suíte.
- [ ] adicionar aberturas específicas ao norte, sul, leste e oeste.
- [ ] adicionar vazamentos em cantos e geometrias irregulares complexas.
- [ ] testar ilhas internas de espaço.
- [ ] testar corredores de largura 1 próximos ao padding.

### Flood fill

- [x] flood fill não está implementado na `develop` auditada.
- [x] não afirmar na defesa que ele existe.
- [x] decidir entre provar a validação atual com testes adversariais ou implementar flood fill.
- [x] se mantiver o algoritmo atual, atualizar `02_validation.md`, `07_integration.md` e `08_final_review.md`.
- [x] se implementar flood fill, usar cópia do grid e validar cleanup dessa cópia.

O subject exige o resultado “mapa fechado”, não um algoritmo nominal. A implementação atual só pode ser considerada suficiente após cobrir casos adversariais equivalentes.

### Mensagens de validation

- [x] erros explícitos existem para caractere, player, borda e mapa.
- [x] [!] todas devem começar exatamente com `Error\n`.
- [x] diferenciar player ausente de players múltiplos de forma consistente.
- [x] garantir apenas uma mensagem por falha.

### Definition of Done da Sprint 02

- [x] parser e validation estão integrados.
- [x] caracteres são validados.
- [x] player é validado.
- [x] bordas e espaços ortogonais são validados.
- [x] cobertura adversarial de mapas irregulares.
- [x] decisão final sobre flood fill.
- [x] mensagens padronizadas.
- [x] zero leaks e acessos inválidos.
- [x] Norminette completa.

---

# 1. Estado consolidado das Sprints 03–06

## Inicialização e recursos

- [x] `t_game` inicializado com memória zerada.
- [x] caminhos de textura recebidos pelo parser.
- [x] carregamento das quatro texturas pelo mapa.
- [x] rollback parcial da MLX implementado.
- [x] texturas destruídas com ponteiros zerados.
- [x] `destroy_game()` integrado.
- [x] grid, `map_path` e paths de textura possuem cleanup central.
- [x] validar cleanup com Valgrind em todas as falhas de inicialização.

## Player e controles

- [x] posição inicial centralizada na célula.
- [x] direções `N`, `S`, `E` e `W` convertidas em vetores.
- [x] plano de câmera configurado por direção.
- [x] célula inicial do player normalizada para `0`.
- [x] WASD funcionando.
- [x] setas esquerda/direita funcionando.
- [x] colisão com limites e células inválidas.
- [ ] testar movimento simultâneo e deslizamento em todos os cantos.

## Raycasting e texturas

- [x] DDA integrado.
- [x] distância perpendicular separada.
- [x] proteção de raio fora do mapa.
- [x] seleção `NO/SO/WE/EA` corrigida.
- [x] cálculo de `wall_x` e `texture_x` separado.
- [x] sampling compatível com alturas que não sejam potência de dois.
- [x] desenho de coluna refatorado para a Norm.
- [x] minimapa removido do mandatory.
- [ ] testar textura diagnóstica para espelhamento horizontal.
- [ ] testar texturas com dimensões não quadradas.

---

# 2. Sprint 07 — Integração

## Pipeline

- [x] argumentos conectados à inicialização.
- [x] parser conectado ao `t_game`.
- [x] validation conectada ao parser.
- [x] player inicializado pelos dados do `.cub`.
- [x] MLX inicializada depois do parsing.
- [x] texturas carregadas pelos paths do mapa.
- [x] hooks registrados.
- [x] raycasting e texture mapping no loop principal.
- [x] mock removido da `main`.
- [x] `libft` convertida de submódulo para pasta comum.
- [x] branch de integração incorporada à `develop`.

## Hooks e encerramento

- [x] W, A, S e D.
- [x] seta esquerda e seta direita.
- [x] ESC fecha a janela.
- [x] botão de fechar chama o fechamento da MLX.
- [x] Valgrind fechando por ESC.
- [x] Valgrind fechando pelo botão X.
- [ ] minimizar, restaurar e alternar janelas repetidamente.

## Validação

- [x] exatamente um player.
- [x] caracteres conhecidos.
- [x] células caminháveis não podem tocar espaços externos.
- [x] células caminháveis não podem estar na borda.
- [?] o roadmap afirma “flood fill integrado”, mas a implementação atual usa validação por bordas e vizinhos.

### Decisão sobre flood fill

O subject exige mapa fechado, mas não exige um algoritmo específico. Portanto:

- [x] provar com testes que a validação atual rejeita todos os vazamentos relevantes; ou
- [x] implementar flood fill e documentá-lo; ou
- [x] atualizar Sprints 07–08 e defesa para explicar corretamente o algoritmo atual.

Não afirmar que existe flood fill enquanto ele não estiver implementado.

## Performance e estabilidade

- [x] mapa grande.
- [x] mapa muito largo.
- [x] mapa muito alto.
- [x] corredores estreitos.
- [x] paredes muito próximas.
- [x] rotação contínua por pelo menos 60 segundos.
- [x] movimentação contínua por pelo menos 60 segundos.
- [x] nenhuma coluna preta, piscando ou desaparecendo.
- [x] janela responsiva após minimizar e restaurar.

## Documentação da Sprint 07

- [x] corrigir o campo `Sprint: 6` em `07_integration.md`.
- [x] substituir caminhos `maps/tests/...` pelos caminhos atuais.
- [x] atualizar checkboxes que já foram efetivamente concluídos.
- [x] remover a afirmação de flood fill ou implementar o algoritmo.
- [x] substituir referência a `master` pelo fluxo real de `develop` para `main`.

---

# 3. Sprint 08 — Final review

## Build obrigatório

- [x] [!] alterar `CC = gcc` para `CC = cc`.
- [x] `make fclean` em clone limpo.
- [x] `make` sem warnings.
- [x] segundo `make` sem recompilar ou relinkar.
- [x] `make clean` remove objetos.
- [x] `make fclean` remove objetos e binários.
- [x] `make re` reconstrói o mandatory.
- [ ] [!] `make bonus` termina com sucesso.
- [ ] confirmar que `libft` compila como pasta comum em clone limpo.

### Situação atual do bônus

O Makefile referencia arquivos em `src_bonus/`, mas esse diretório não está presente na `develop` auditada.

- [ ] enquanto o bônus não for integrado, usar `bonus: all`; ou
- [ ] integrar arquivos `_bonus.c/_bonus.h` reais e validar o binário bônus.

## Norminette

- [x] [!] `make norm` retorna zero erros.
- [x] remover comentários internos `//` incompatíveis com a versão final.
- [x] corrigir alinhamento dos protótipos em `cub3D.h`.
- [x] corrigir espaços finais e formatação de `grid_utils.c`.
- [x] remover ou normalizar `src/utils/debug.c`.
- [x] remover ou normalizar `src/utils/strings.c`.
- [ ] verificar também arquivos bônus quando existirem.
- [ ] verificar a `libft` conforme as regras da avaliação local.

## Memória

- [x] [!] zero `definitely lost` no mandatory.
- [x] zero `indirectly lost`.
- [x] zero invalid reads.
- [x] zero invalid writes.
- [x] zero double frees.
- [x] zero descritores próprios abertos ao sair.
- [x] distinguir recursos internos da MLX/GLFW dos recursos do projeto.

Executar pelo menos:

```bash
valgrind --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --track-fds=yes \
  ./cub3D maps/valid/valid_basic.cub
```

Repetir fechando por ESC e pelo botão X.

## Revisão de código

- [ ] remover código morto.
- [ ] remover prints de debug.
- [ ] remover placeholders vazios.
- [ ] confirmar ausência de variáveis globais proibidas.
- [ ] conferir somente funções externas autorizadas.
- [ ] confirmar funções com no máximo 25 linhas.
- [ ] confirmar no máximo 4 parâmetros por função.
- [ ] revisar mensagens e retornos de erro.
- [ ] revisar ownership de toda alocação.

## Preparação da defesa

- [ ] ambas explicam parsing e ordem dos elementos.
- [ ] ambas explicam validação de mapas irregulares.
- [ ] ambas explicam o algoritmo realmente usado para fechamento do mapa.
- [ ] ambas explicam vetor de direção e plano da câmera.
- [ ] ambas explicam DDA e distância perpendicular.
- [ ] ambas explicam `wall_x`, `texture_x` e sampling vertical.
- [ ] ambas explicam hooks e loop da MLX42.
- [ ] ambas conseguem localizar rapidamente cada módulo.
- [ ] ambas conseguem realizar uma pequena modificação durante a avaliação.

---

# 4. Conformidade com o subject

## Bloqueadores objetivos

### 4.1 Compilador do Makefile

- [x] [!] usar `cc`, conforme o subject.

### 4.2 Mensagens de erro

O subject exige `Error\n` seguido de mensagem explícita.

- [x] [!] trocar `Error: mensagem` por:

```text
Error
mensagem
```

- [x] imprimir erros preferencialmente em `stderr`.
- [x] evitar mensagem duplicada como `Error\nError\n...`.
- [x] testar todos os mapas inválidos verificando a primeira linha.

### 4.3 README obrigatório

- [ ] [!] primeira linha em itálico com os logins da dupla.
- [ ] seção `Description`.
- [ ] seção `Instructions`.
- [ ] seção `Resources`.
- [ ] descrição explícita do uso de IA.
- [ ] README integralmente em inglês.
- [ ] caminhos atuais de mapas.
- [ ] remover alegações de funcionalidades não implementadas.
- [ ] remover XPM se o projeto continuar exclusivamente PNG.
- [ ] não apresentar minimapa como mandatory.
- [ ] não afirmar “No memory leaks” antes da evidência final.

### 4.4 Texturas

A implementação atual valida apenas `.png` e usa `mlx_load_png()`.

- [?] confirmar formatos aceitos pela MLX42 na avaliação da 42SP.
- [ ] não limitar o parser a uma extensão que o subject não limita, sem justificativa.
- [ ] testar arquivo inexistente.
- [ ] testar diretório no lugar de textura.
- [ ] testar arquivo PNG corrompido.
- [ ] testar arquivo válido com extensão incompatível.
- [ ] testar falha na segunda, terceira e quarta texturas para validar rollback.

### 4.5 RGB estrito

- [ ] [!] validar exatamente três componentes.
- [ ] validar exatamente duas vírgulas.
- [ ] rejeitar componente vazio.
- [ ] rejeitar letras e sufixos.
- [ ] detectar overflow antes de converter.
- [ ] aceitar apenas valores entre 0 e 255.
- [ ] decidir e testar espaços em torno dos componentes.

Casos mínimos:

```text
F 0,0,0
C 255,255,255
F 256,0,0
F -1,0,0
F 1,,2,3
F 12abc,20,30
F 999999999999999999999,20,30
```

### 4.6 Mapa e elementos

- [x] mapa é o último elemento processável.
- [x] elementos anteriores podem aparecer em qualquer ordem.
- [x] linhas vazias são aceitas antes do mapa.
- [x] linhas vazias dentro do mapa são rejeitadas.
- [x] espaços do mapa são preservados.
- [x] exatamente um player.
- [ ] adicionar teste de informação após o mapa.
- [ ] adicionar teste de mapa ausente.
- [ ] adicionar teste de player ausente.
- [ ] adicionar teste de mapa composto somente por paredes.
- [ ] adicionar testes de linhas irregulares e vazamentos em cantos.

---

# 5. Suíte de testes final

## Mapas válidos

- [x] `valid_basic.cub`.
- [x] `valid_arcane.cub`.
- [x] `valid_crypt.cub`.
- [x] `valid_infernal.cub`.
- [x] `valid_hearts.cub`.
- [x] `spaces_valid.cub`.
- [ ] player inicial N.
- [ ] player inicial S.
- [ ] player inicial E.
- [ ] player inicial W.
- [ ] mapa mínimo.
- [ ] mapa grande.
- [ ] mapa irregular complexo.

## Mapas inválidos existentes

- [x] extensão inválida.
- [x] RGB fora do intervalo.
- [x] dois players.
- [x] textura duplicada.
- [x] caractere inválido.
- [x] textura ausente.
- [x] linha vazia dentro do mapa.
- [x] parede aberta.
- [x] vazamento para espaço externo.

## Mapas inválidos a adicionar

- [ ] nenhum argumento e argumentos extras.
- [ ] arquivo inexistente.
- [ ] diretório com nome `.cub`.
- [ ] arquivo `.cub` vazio.
- [ ] player ausente.
- [ ] cor ausente.
- [ ] cor duplicada.
- [ ] textura inexistente.
- [ ] textura apontando para diretório.
- [ ] textura corrompida.
- [ ] identificador desconhecido.
- [ ] informação depois do mapa.
- [ ] mapa ausente.
- [ ] abertura em cada borda.
- [ ] abertura diagonal/canto.
- [ ] múltiplos formatos RGB inválidos.

## Target automático

- [x] `maps_test` executa somente `maps/invalid/`.
- [x] lista explícita sem wildcard.
- [x] timeout evita sequência de janelas.
- [x] saída do programa é exibida.
- [ ] target falha se a saída não começar com `Error`.
- [ ] adicionar novos mapas manualmente em `INVALID_MAPS`.

---

# 6. Git e entrega

- [x] integração das texturas incorporada à `develop`.
- [x] parsing incorporado à `develop`.
- [x] `libft` como pasta comum.
- [x] mapas organizados.
- [x] Makefile reorganizado.
- [ ] working tree limpa.
- [ ] `develop` sincronizada com remoto.
- [ ] clone limpo realizado fora do repositório de trabalho.
- [ ] build completo no clone limpo.
- [ ] atualizar roadmap e README.
- [ ] merge final de `develop` para a branch de submissão.
- [ ] confirmar branch e commit avaliados pela 42.
- [ ] criar tag final opcional após aprovação da dupla.

---

# 7. Ordem recomendada de finalização

## Fase A — Bloqueadores estáticos

1. [ ] `CC = cc`.
2. [ ] corrigir regra `bonus`.
3. [ ] padronizar `Error\n`.
4. [ ] zerar Norminette.
5. [ ] remover placeholders e código morto.

## Fase B — Robustez do parser

6. [ ] RGB estrito.
7. [ ] decisão sobre formatos de textura.
8. [ ] ampliar mapas inválidos.
9. [ ] validar saída `Error` no tester.
10. [ ] provar fechamento de mapas irregulares ou implementar flood fill.

## Fase C — Documentação

11. [ ] reescrever README conforme o subject.
12. [ ] atualizar Sprints 07–08.
13. [ ] alinhar documentação com funcionalidades realmente entregues.

## Fase D — Evidência final

14. [ ] build e no-relink.
15. [ ] testes funcionais completos.
16. [ ] Valgrind em mapas válidos e inválidos.
17. [ ] teste de ESC e botão X.
18. [ ] clone limpo.
19. [ ] simulação de avaliação pela dupla.
20. [ ] merge para a branch de submissão.

---

# 8. Comandos de fechamento

```bash
git switch develop
git pull --ff-only origin develop
git status

make fclean
make
make
make clean
make
make re
make bonus
make norm
make maps_test
```

Testes manuais:

```bash
./cub3D maps/valid/valid_basic.cub
./cub3D maps/valid/spaces_valid.cub
./cub3D maps/valid/valid_crypt.cub
```

Valgrind:

```bash
make valgrind MAP=maps/valid/valid_basic.cub
valgrind --leak-check=full --show-leak-kinds=all \
  --track-origins=yes --track-fds=yes \
  ./cub3D maps/invalid/open_wall.cub
```

Auditoria rápida:

```bash
grep -RnsE '^<<<<<<<|^=======|^>>>>>>>' inc src
grep -Rns 'maps/tests' . --exclude-dir=.git --exclude=cub3D
git ls-files --stage libft | head
git status
```

---

# 9. Definition of Done final

O mandatory estará concluído somente quando todos os itens abaixo estiverem marcados:

- [ ] todos os requisitos do subject atendidos;
- [ ] todas as mensagens de falha começam com `Error\n`;
- [ ] todos os mapas inválidos são rejeitados;
- [ ] todos os mapas válidos testados abrem corretamente;
- [ ] quatro direções e texturas corretas;
- [ ] controles e fechamento corretos;
- [ ] Makefile obrigatório completo e sem relink;
- [ ] `make bonus` não falha;
- [ ] Norminette com zero erros;
- [ ] Valgrind sem erros atribuíveis ao projeto;
- [ ] README conforme o subject;
- [ ] documentação coerente com o código;
- [ ] clone limpo compila e executa;
- [ ] dupla preparada para explicar e modificar o projeto;
- [ ] branch de submissão contém exatamente a versão aprovada.

Quando todos os itens estiverem concluídos, o mandatory pode ser considerado pronto para avaliação. O bônus só deve ser integrado ou reivindicado depois disso.
