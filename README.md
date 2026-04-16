# Jogo da Cobrinha

Este repositório contém uma implementação clássica do jogo da Cobrinha (Snake) desenvolvida na linguagem C, projetada para ser executada no terminal/console do Windows. O jogo foi desenvolvido para rodar diretamente no prompt de comando, utilizando a biblioteca `conio.h` para capturar as teclas em tempo real sem a necessidade de pressionar "Enter" e `windows.h` para gerenciar a lógica de renderização do console.
![Demonstração do Jogo](Cobrinha%20GIF.gif)

## Características implementadas:
- Movimentação bidirecional contínua da cobra.
- Sistema de colisão com o próprio corpo.
- Ao encostar nos limites da tela, a cobra reaparece no lado oposto.
- Crescimento progressivo conforme a coleta de itens (`@`).
- Geração aleatória de "comida" em espaços vazios garantidos.


## Controles

- **`W`** - Move para Cima
- **`A`** - Move para a Esquerda
- **`S`** - Move para Baixo
- **`D`** - Move para a Direita


## Como Compilar e Executar

Para compilar e rodar o jogo, você precisará de:
* Um sistema operacional **Windows** (devido às dependências específicas como `<windows.h>` e `<conio.h>`).
* Um compilador de linguagem C, como o **GCC/MinGW**.
* (Opcional) A IDE **Code::Blocks**, já que os arquivos de projeto `.cbp`, `.depend` e `.layout` estão inclusos no repositório.

### Opção 1: Usando Code::Blocks
1. Dê um duplo clique no arquivo `Cobrinha.cbp` para abri-lo no Code::Blocks.
2. Na barra de ferramentas superior, clique em **Build and run** (ou pressione a tecla `F9`).

### Opção 2: Usando linha de comando (GCC)
Abra o seu terminal (CMD ou PowerShell), navegue até a pasta do projeto e digite o seguinte comando para compilar:

```bash
gcc main.c -o cobrinha.exe
```

Após a compilação ser concluída com sucesso, execute o jogo com:

```bash
.\cobrinha.exe
```

