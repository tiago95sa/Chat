#ifndef PROJETO_FUNCOES_H_INCLUDED
#define PROJETO_FUNCOES_H_INCLUDED

#include <sorting.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib_util.h"
#include "stringsorting.h"
#include <math.h>
#include "lib_stats.h"
#include "stringsearch_kmp.h"

#define R_KMP 256
#define CHAR_8BIT_RADIX 256


typedef struct timestamp{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
}TIMESTAMP;

//typedef struct palavra{
//    char * palavra;
//    int importancia;
//    int tfidf;
//    struct palavra *pnext;
//}PALAVRA;

typedef struct mensagem{
    char * utilizador;
    char ** mensagem;
    int * importancia;
    int linhas_mensagem;
    char ** bag_of_words;
    int linhas_bag_of_words;
    int ** matriz_de_indices;
    int * linhas_matriz_indices;
    int * numero_de_ocorrencias;
    int total_palavras ;
    TIMESTAMP *tempo;
    struct mensagem *pnext;
    struct mensagem *pante;
}MENSAGEM;

typedef struct conversa{
    char ** utilizadores;
    int linhas_utilizadores;
    char ** bag_of_words;
    int linhas_bag_of_words;
    int * numero_de_ocorrencias;
    int tamanho ;
    int importancia;
    struct mensagem * pfirst;
    struct conversa *pnext;
    struct conversa *pante;
    int size_mensagem;
    TIMESTAMP *tempo;
}CONVERSA;

typedef struct corpus{
    struct conversa *pfirst;
    char ** bag_of_words;
    float *tfidf;
    int linhas_bag_of_words;
    int *numero_de_ocorrencias;
    int size_conversa;
}CORPUS;

void gravar_para_ficheiro_binario(CONVERSA *cv);
static int distancia (const char * word1, int len1, const char * word2, int len2);
void distancia_entre_strings (CORPUS * cp, char * string);
void copiar_ficheiro_para_matriz(char * path, int count, CONVERSA *pc);
int contar_linhas(char * path);
void utilizador_remover_mensagem(CORPUS *cp);
void client_projeto_2fase();
float term_frequency_inverse_document_frequency(char *string, CORPUS *cp);
int total_de_palavras(int linhas_matriz_palavras, int * array_ocorrencias);
int * numero_de_ocorrencias(int** matriz_indices, char** matriz_palavras, int linhas_palavras, int *linhas_de_indices, int linhas_matriz_indices);
void print_todas_conversas_usando_utilizadores_para_distincao(CORPUS *cp);
int contar_paragrafos_mensagem (char *string);
void inserir_mensagem_conversa_cauda(CONVERSA *pc, MENSAGEM *pnew);
void print_timestamp(MENSAGEM *ms);
void print_timestamp_conversa(CONVERSA * cv);
void bag_of_words_corpus (CORPUS *cp);
void inserir_nova_conversa_cauda(CORPUS *pc);
void ordenacao_por_tamanho(CORPUS *cp);
char** criar_matriz(int linhas);
void numero_paragrafos(CONVERSA *cv);
TIMESTAMP *string_para_inteiro_timestamp(char * string);
MENSAGEM *criar_struct_mensagem();
CONVERSA *criar_struct_conversa();
void print_matriz(char ** matriz, int linhas);
void print_mensagens_de_uma_conversa(CONVERSA *pc);
void preencher_matriz_palavras(char** matriz_mensagem,int* array_tamanho_matriz_indices, int** matriz_indices, int linhas_mensagem, int linhas_palavras, char ** matriz_palavras);
void preencher_matriz_indices(int** matriz_indices, char** matriz_mensagem, char** matriz_palavras, int linhas_palavras, int linhas);
char ** criar_matriz_ordenada(char** matriz,StringElementsArray *a, int *linhas);
void retirar_carateres_pontuacao_palavra(char** matriz, int linhas);
void remover_conversa(CORPUS *cp, int index);
int * criar_array_tamanho_indices(int linhas);
int contar_numero_de_palavras_mensagem(char** matriz,int linhas);
int ** criar_matriz_indices(int linhas);
void criar_matrizes_adicionais_de_mensagem(MENSAGEM *ms);
int verificar_se_palavra_e_pontuacao(char *string);
int verificar_pontuacao_palavra(char *string);
void free_matriz(char** matriz, int linhas);
int verificacao_caracter_ou_numero(char c);
void palavras_com_possiveis_raizes_comuns(char ** matriz_palavras , int linhas_matriz_palavras, char * palavra);
char ** create_prefix_array(char *str);
int pesquisa_binaria( char* procura, char** tudo, int low, int high);
int contar_distancia_desde_inicio_de_uma_palavra_KMP(char * string,char ** text, int linhas_matriz_mensagem);
int verifica_quantiade_linhas_stringelementarray(StringElementsArray* a);
void distancia_textual_entre_duas_palavras(CONVERSA *cv , char* string1 , char* string2);
void print_matriz_indices(int ** matriz,int linhas_matriz, int *tamanho_linhas);
void remover_mensagem(CONVERSA *cv , int index);
void frequencia_reutilizacao_palavra (CONVERSA *cv , char * string);
int verificar_se_existe_na_matriz(char** matriz, char *string , int size);
void print_timestamp(MENSAGEM *ms);
void bag_of_words_conversa (CONVERSA *cv);

#endif // PROJETO_FUNCOES_H_INCLUDED
