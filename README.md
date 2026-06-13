# Projeto 04: Conversor e Renderizador de Formas (SVG)

Este projeto consiste no desenvolvimento de um motor de plotagem vetorial em C++ orientado a objetos. O programa lê instruções e propriedades de formas geométricas a partir de um arquivo de texto e gera, como saída, um arquivo de imagem no formato **SVG** (*Scalable Vector Graphics*), que pode ser renderizado nativamente por qualquer navegador web.

## 🎯 Objetivos e Foco Acadêmico

Desenvolvido para a disciplina de Programação Avançada na UFRN, este projeto é um forte exercício sobre conceitos fundamentais do paradigma de **Programação Orientada a Objetos (POO)** e C++ moderno:

- **Polimorfismo e Herança:** Utilização de uma classe base genérica (`Shape`) com métodos virtuais (`read()`, `save()`, `clone()`). O programa armazena as mais diversas formas (linhas, retângulos, círculos, etc.) em uma única coleção polimórfica (`std::vector<pShape>`).
- **Gerenciamento Seguro de Memória (Regra dos 5):** A classe gerenciadora `Designer` aplica de forma estrita construtores de cópia e movimento, operadores de atribuição (cópia/movimento) e um destrutor minucioso. Isso garante que não ocorram *memory leaks* ao lidar com alocação dinâmica de ponteiros (`new` e `delete`).
- **Tratamento de Exceções:** Uso extenso de blocos `try/catch` para capturar falhas de I/O de arquivos e erros de lógica, lançando exceções nativas (`std::ios_base::failure`, `std::logic_error`) em casos de arquivos corrompidos ou inexistentes.
- **Manipulação de Arquivos (I/O):** Leitura iterativa e extração de dados de arquivos `.txt` (usando `std::ifstream`) e serialização de tags XML na formatação padrão SVG exportando em arquivos `.svg` (usando `std::ofstream`).

## 🚀 Funcionalidades Principais

- **Leitura Dinâmica:** O sistema reconhece palavras-chave em arquivos de texto e aloca em tempo de execução a forma geométrica adequada, que pode ser:
  - `'I'`: Linha (`Line`)
  - `'C'`: Círculo (`Circle`)
  - `'R'`: Retângulo (`Rectangle`)
  - `'T'`: Triângulo (`Triangle`)
  - `'L'`: Losango (`Rombo`)
  - `'S'`: Estrela (`Star`)
- **Motor de Delegação:** A classe `Designer` atua como um maestro, delegando a responsabilidade de leitura dos parâmetros (dimensões, espessura da borda, preenchimento, cor) e a responsabilidade de escrita do código SVG (como `<circle>`, `<polygon>`, etc.) para as próprias instâncias das formas.
- **Prevenção contra Falhas:** Caso alguma linha do arquivo não siga o padrão geométrico ou uma forma alocada gere falha ao ter suas propriedades lidas, o sistema aborta a operação sem deixar sujeira na memória.

## 🗂 Estrutura do Projeto

- `designer.h` / `designer.cpp`: O coração do projeto. Define a classe `Designer`, responsável por guardar a tela, ler os dados sequenciais do arquivo e gerenciar todo o ciclo de vida dos ponteiros das formas.
- `shape.h` / `shape.cpp`: Define as representações matemáticas e visuais das formas, com a base polimórfica e suas derivadas.
- `designer-main.cpp`: Interface em console pela qual o usuário informa os arquivos de entrada e saída.

## 🛠️ Como Compilar e Executar

**Requisitos:** Compilador compatível com C++17 (ex: `g++`).

Abra o terminal na pasta do projeto e compile os arquivos-fonte do `Designer` e do `Shape` juntamente com a `main`:

```cmd
g++ -Wall -Wextra -std=c++17 shape.cpp designer.cpp designer-main.cpp -o designer.exe
```

Em seguida, execute a aplicação recém-compilada:

```cmd
designer.exe
```

**Fluxo de Execução:**
1. O programa pedirá o nome do arquivo texto com o design original (ex: `brasil.txt`).
2. Em seguida, pedirá o nome do arquivo que será salvo contendo a imagem (ex: `brasil.svg`).
3. Abra o arquivo `.svg` gerado em um navegador (como Google Chrome ou Microsoft Edge) para ver o desenho renderizado.

---

*Desenvolvido como projeto acadêmico focado em Polimorfismo, Regras de Gerenciamento de Recursos (RAII) e C++ Moderno.*