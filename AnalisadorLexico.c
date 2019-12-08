/*
 * ANALISADOR LEXICO
 * Data: 04/12/2019
 * Autor: Emanuel Souza (https://github.com/EmanuelOSSouza/Learning)
 * Matéria: Teoria da computação e compiladores
 * Descrição: Criar um programa em “C” ou em “C++”, que será um analisador léxico, para a linguagem chamada “Minha Linguagem Normal”,
 * este analisador deve ser construído com algumas das técnicas vistas em laboratório, isso inclui usar AFD, Máquina de Turing, AFD de
 * Pilha com Máquina de Turing.
 * Técnica utilizada:  AFD (Automato Finito Deterministico), para entrada de palavras. Para verificação lexica foi feito uma fila
 * dinâmica, com o objetivo de armazenar as palavras que possuem o alfabeto válido.
 * Sendo esperado na saida, a exibição das palavras que possuem o alfabeto válido, geração do arquivo "resultado.txt" e a tabela de
 * palavras válidas e seu tipo, por exemplo: Numero, operador aritmetico, operador de fechamento e operador relacionais.
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countLinha = 0;
char palavra[500];
int countCaracter = 0;
int countAspas = 0;
int countChaves = 0;
int countParenteses = 0;
int countErroCaracter = 0;
int errocod = 0;
char file[50];

typedef int LINHA;

typedef struct {
	LINHA linha;                 // Controle ID
	char palavra[50];              // Dicionario
	int nElemento;
} REGISTRO;

typedef struct aux {
 REGISTRO reg;
 struct aux* prox;
} ELEMENTO,* PONT;

typedef struct {
 PONT inicio;
 PONT fim;
} FILA;

FILA f;
void inicializarFila(FILA* f) {
f->inicio = NULL;
f->fim = NULL;
}

int tamanho(FILA* f) {
PONT end = f->inicio;
int tam = 0;
while (end != NULL) {
tam++;
end = end->prox;
}
return tam;
}

int exibirFila(FILA* f) {
    PONT end = f->inicio;
    if(f->inicio==NULL) {
            printf("\nFila vazia!!\n");
    return 0;
    }else{
        printf("\tPalavras analisadas:  ");
        while (end != NULL) {
            printf("\nPalavra:          %s", end->reg.palavra);
            //printf("\nN de Elementos:   %d\n", end->reg.nElemento);
            end = end->prox;
        }
    printf("\n");
    }
}

int salvarCodigo(char *token, FILA *f,int elementos){
    //printf("\n%s",token);
        PONT novo = (PONT) malloc(sizeof(ELEMENTO));
        novo->reg.linha = countLinha;
        strcpy(novo->reg.palavra, token);
        novo->reg.nElemento = elementos;
        novo->prox = NULL;
        if (f->inicio==NULL) f->inicio = novo;
        else f->fim->prox = novo;
        f->fim = novo;
        return 1;
}

int verificaNumero(char *numero){
int countNum = 0;
int valor = atoi(numero);
if(strcmp(numero,"0")==0)
    countNum++;
if(valor==0)
    countNum++;
return countNum;
}

void inicio(FILA *f){
    PONT end = f->inicio;
    char aux[500];
    printf("\nPalavras validas:\n");
    while (end != NULL) {
            if (strcmp (end->reg.palavra, "num") == 0){              //num
                printf("\nPalavra valida: %s ",end->reg.palavra);
                end = end->prox;
            } else if (strcmp (end->reg.palavra, "string") == 0){    //string
                printf("\nPalavra valida: %s ",end->reg.palavra);
                end = end->prox;
            } else if (strcmp (end->reg.palavra, "print") == 0){     //print
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "read") == 0){      //read
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "return") == 0){    //return
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "if") == 0){        //if
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "else") == 0){      //else
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "sqrt") == 0){      //sqrt
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "for") == 0){       //for
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "step") == 0){      //step
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "to") == 0){        //to
                printf("\nPalavra valida: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "{") == 0){         //Fechamento Chave {
                printf("\nFechamento(chaves): %s ",end->reg.palavra);
                countChaves++;
            } else if (strcmp (end->reg.palavra, "}") == 0){         //Fechamento Chave }
                printf("\nFechamento(chaves): %s ",end->reg.palavra);
                countChaves--;
            } else if (strcmp (end->reg.palavra, "(") == 0){         //Fechamento Parenteses (
                printf("\nFechamento(parenteses): %s ",end->reg.palavra);
                countParenteses++;
            } else if (strcmp (end->reg.palavra, ")") == 0){         //Fechamento Parenteses )
                printf("\nFechamento(parenteses): %s ",end->reg.palavra);
                countParenteses--;
            } else if (strcmp(end->reg.palavra,"\"")==0){            // Fechamento aspas
                printf("\nFechamento (aspas): %s",end->reg.palavra);
                countAspas++;
            } else if (strcmp (end->reg.palavra, "<") == 0){         //Operador relacional <
                printf("\nOperador Relacional: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, ">") == 0){         //Operador relacional >
                printf("\nOperador Relacional: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "=") == 0){         //Operador relacional ou atribuição =
                printf("\nOperador Relacional: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "+") == 0){         //Operador aritimetico +
                printf("\nOperador Aritimetico: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "-") == 0){         //Operador aritimetico -
                printf("\nOperador Aritimetico: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "*") == 0){         //Operador aritimetico *
                printf("\nOperador Aritimetico: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "/") == 0){         //Operador aritimetico /
                printf("\nOperador Aritimetico: %s ",end->reg.palavra);
            } else if (strcmp (end->reg.palavra, "%") == 0){         //Operador aritimetico %
                printf("\nOperador Aritimetico: %s ",end->reg.palavra);
            } else if(verificaNumero(end->reg.palavra)==0 || verificaNumero(end->reg.palavra)==2 ){
                printf("\nNUM: %s",end->reg.palavra);
            }
            end = end->prox;
        }
}

int verificaFechamento(){
    FILE *arquivo;
    arquivo = fopen("resultado.txt", "a");
    //printf("\n Chaves: %d - Parenteses: %d - Aspas: %d", countChaves, countParenteses,countAspas);
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    if(countChaves!=0 || countParenteses!=0 || countAspas%2!=0 ){
        fprintf(arquivo, "\n%s", "Falta fechamento de codigo ");
        errocod++;
    }
    fclose(arquivo);
}

int verificaErros(){
    FILE *arquivo;
    arquivo = fopen("resultado.txt", "a");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    if(errocod==0){
        fprintf(arquivo, "\n%s", "Arquivo  ");
        fprintf(arquivo, "%s", file);
        fprintf(arquivo, "%s", "  analisado corretamente");
    } else {
        fprintf(arquivo, "\n%s", " O arquivo  ");
        fprintf(arquivo, "%s", file);
        fprintf(arquivo, "%s", " contem erro(s) ");
    }
    fclose(arquivo);
}

int verificaLexema(char *caractere, FILA *f, int countCaracter){
        int i;
        FILE *arquivo;
            if (strcmp (caractere, "a") == 0){
                  strcat(palavra,caractere);
                  printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "b") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "c") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "d") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "e") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "f") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "g") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "h") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "i") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "j") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "k") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "l") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "m") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "n") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "o") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "p") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "q") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "r") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "s") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "t") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "u") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "v") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "w") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "y") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "x") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "z") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "0") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "1") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "2") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "3") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "4") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "5") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "6") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "7") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "8") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "9") == 0){
                strcat(palavra,caractere);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "{") == 0){         //Fechamento Chave {
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "}") == 0){         //Fechamento Chave }
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "(") == 0){         //Fechamento Parenteses (
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, ")") == 0){         //Fechamento Parenteses )
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "\"")==0){          // Fechamento aspas
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "<") == 0){         //Operador relacional <
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, ">") == 0){         //Operador relacional >
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "=") == 0){         //Operador relacional ou atribuição =
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                printf("\nletra: %s - palavra: %s",caractere,palavra);
                strcpy(caractere,"");
            } else if (strcmp (caractere, "+") == 0){         //Operador aritimetico +
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "-") == 0){         //Operador aritimetico -
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "*") == 0){         //Operador aritimetico *
               verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "/") == 0){         //Operador aritimetico /
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, "%") == 0){         //Operador aritimetico %
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                salvarCodigo(caractere,f,countCaracter);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, ":") == 0){         // Dois pontos
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, ",") == 0){         // Dois pontos
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, ";") == 0){         // Dois pontos
                verificaCadeia(palavra,caractere,countCaracter,countErroCaracter,f);
                strcpy(caractere,"");
                printf("\nletra: %s - palavra: %s",caractere,palavra);
            } else if (strcmp (caractere, " ") == 0 || strcmp (caractere, "\n") == 0 || strcmp (caractere, "\0") == 0){         //espaço
                countLinha++;
                if(strcmp (palavra, " ") == 0 || strcmp (palavra, "\n") == 0 || strcmp (palavra, "\0") == 0){
                    printf("\nEspaco vazio: [%s]",palavra);
                    printf("\nErro: %d",countErroCaracter);
                } else {
                    if (countErroCaracter==0){
                        salvarCodigo(palavra,f,countCaracter);
                        printf("\nPalavra salva: [%s]",palavra);
                    }else {
                        errocod++;
                        arquivo = fopen("resultado.txt", "a");
                        if(arquivo == NULL){
                        printf("Erro na abertura do arquivo!");
                        return 1;
                        }
                        fprintf(arquivo, "\n%s", "Palavra");
                        fprintf(arquivo, "\t%s\t", palavra);
                        printf("------>word**: %s", palavra);
                        fprintf(arquivo, "\t%s", "nao reconhecida");
                        fclose(arquivo);
                    }
                }
                countErroCaracter = 0;
                strcpy(palavra,"");
                strcpy(caractere,"");
            } else {
                strcat(palavra,caractere);
                countErroCaracter++;
                printf("\n erro: letra: %s - palavra: %s - erro: %d",caractere,palavra,countErroCaracter);
            }
}

int verificaCadeia(char *palavra, char *caracter, int countCaracter, int countErroCaracter, FILA *f){
    FILE *arquivo;
    if(strcmp (palavra, " ") == 0 || strcmp (palavra, "\n") == 0 || strcmp (palavra, "\0") == 0){
            printf("\nEspaco vazio: [%s]",palavra);
            printf("\nErro: %d",countErroCaracter);
    } else {
        if(countErroCaracter==0){
            salvarCodigo(palavra,f,countCaracter);
            printf("\nPalavra salva: [%s]",palavra);
        } else {
            errocod++;
            arquivo = fopen("resultado.txt", "a");
            if(arquivo == NULL){
                printf("Erro na abertura do arquivo!");
                return 1;
            }
            fprintf(arquivo, "\n%s", "Palavra");
            fprintf(arquivo, "\t%s\t", palavra);
            printf("\n-------->word: [%s]", palavra);
            fprintf(arquivo, "\t%s", "nao reconhecida");
            fclose(arquivo);
        }
    }
    strcpy(palavra,"");
    countErroCaracter = 0;
}

void output(){
    printf("\n######################################################\n");
    printf("# ARQUIVO DE SAIDA GERADO COM SUCESSO: resultado.txt #\n");
    printf("######################################################\n");
    Sleep(5000);
}

void loading(){
    printf("\n################################################\n");
    printf("# CARREGANDO, LENDO E COMPILANDO O ARQUIVO:-> %s \n",file);
    printf("################################################\n");
    Sleep(5000);
}

void lerArquivo(FILA *f){
	FILE *arq;
	char caracter[500];
	gets(file);
	loading();
	arq = fopen(file, "r");
	strcpy(palavra,"");
	while (!feof(arq)){
       fread(&caracter,1,1,arq);
        countCaracter++;
        //printf("\n[%s]",caracter);
        //Sleep(5);
        verificaLexema(caracter,f,countCaracter);
	}
    printf("\nArquivo lido com sucesso!\n");
}

int main() {
    char arquivo[200];
    inicializarFila(&f);
    printf("|===============================================|\n");
    printf("|================ ANALISADOR LEXICO ============|\n");
    printf("|===============================================|\n");
    printf("|== DIGITE O NOME DO ARQUIVO A SER ANALISADO: ==|\n");
    printf("|=>");
    lerArquivo(&f);
    exibirFila(&f);
    Sleep(5000);
    system("cls");
    inicio(&f);
    verificaFechamento();
    verificaErros();
    output();
    return (0);
}
