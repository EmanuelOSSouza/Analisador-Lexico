# ANALISADOR LEXICO
### Data: 04/12/2019
### Autor: [Emanuel Souza](https://github.com/EmanuelOSSouza)
### Matéria: Teoria da computação e compiladores
### Descrição: 
Criar um programa em “C” ou em “C++”, que será um analisador léxico, para a linguagem chamada “Minha Linguagem Normal”, este analisador deve ser construído com algumas das técnicas vistas em laboratório, isso inclui usar AFD, Máquina de Turing, AFD 
de Pilha com Máquina de Turing.
Este analisador deve ser capaz de ler um arquivo fonte da nossa linguagem MLN, exemplo “ArquivoFonte1.mln” e “ArquivoFonte2.mln”
que são os dois programas escrito na linguagem MLN (texto livre de marcações), estes serão fornecidos pelo professor.
Após o analisador ler o arquivo ele deve gerar como saída um arquivo chamado “resultado.txt” que para cada arquivo fonte lido deve
possuir um arquivo de resultado correspondente, contendo a(s) mensagen(s) como descrito abaixo:

#### Para validações corretas:
 
 > Arquivo fonte: ArquivoFonte1.mln analisado corretamente.

#### Para validações inconsistentes ou erradas:
> Arquivo fonte: ArquivoFonte1.mln contendo erro(s)

> Palavra XPTO não reconhecida

> Falta de fechamento de código 

### Técnica utilizada:
AFD (Automato Finito Deterministico), para entrada de palavras. Para verificação lexica foi feito uma fila
dinâmica, com o objetivo de armazenar as palavras que possuem o alfabeto válido.
Sendo esperado na saida, a exibição das palavras que possuem o alfabeto válido, geração do arquivo "resultado.txt" e a tabela de 
palavras válidas e seu tipo, por exemplo: Numero, operador aritmetico, operador de fechamento e operador relacionais.

### Utilização: 
Ao iniciar a aplicação deve ser informado um arquivo existente e válido (dentro da mesma pasta que contém o executável), como por exemplo: “ArquivoFonte1.mln” e “ArquivoFonte2.mln”. 
Logo em seguida o analisador léxico vai exibir as informações descritas acima e gerar o arquivo de saida: "resultado.txt".

**OBS:** Programa projetado para funcionar no windows.
