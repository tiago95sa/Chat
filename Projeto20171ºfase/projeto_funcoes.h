#ifndef PROJETO_FUNCOES_H_INCLUDED
#define PROJETO_FUNCOES_H_INCLUDED

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


struct index{
    int numero_ocorrencias;
    char * str;
    int len;
};

void client_main_funcoes();
int contar_linhas(char * path);
char** criar_matriz(int linhas);
void print_matriz_indices(int ** matriz,int linhas_matriz, int *tamanho_linhas);
void ficheiro_para_matriz_mensagem(char ** matriz, int linhas, char* path);
void print_matriz(char ** matriz, int linhas );
int contar_numero_de_palavras_mensagem(char** matriz,int linhas);
void preencher_matriz_palavras(char** matriz_mensagem,int* array_tamanho_matriz_indices, int** matriz_indices, int linhas_mensagem, int linhas_palavras, char ** matriz_palavras);
int verificar_pontuacao_palavra(char *string);
void retirar_carateres_pontuacao_palavra(char** matriz , int linhas);
void realocar_memoria_matriz_palavras(char **matriz , int linhas );
void free_matriz(char** matriz, int linhas);
int pesquisa_binaria( char* procura, char** tudo, int low, int high);
char ** criar_matriz_ordenada(char** matriz, StringElementsArray *a , int *linhas);
int verifica_quantiade_linhas_stringelementarray(StringElementsArray* a);
int ** criar_matriz_indices(int linhas);
int * criar_array_tamanho_indices(int linhas);
void procurar_padrao (char ** matriz_mensagem, int linhas_matriz_mensagem, char * padrao );
int * numero_de_ocorrencias(int** matriz_indices, char** matriz_palavras , int linhas_palavras , int *linhas_de_indices , int linhas_matriz_indices);
void colocar_tudo_letras_pequenas(char ** matriz_palavras , int linhas_palavras);
void bag_of_words(char** matriz_palavras ,int** matriz_indices, int* linhas_indices, int linhas_matriz_palavras , int * array_ocorrencias , int linhas_matriz_mensagem);
int comparar(struct index *elem1, struct index *elem2);
void term_frequency_inverse_document_frequency(char * string, int ** matriz_indices , int * linhas_indices , int linhas_matriz_mensagem, char ** matriz_palavras , int linhas_matriz_palavras);
int contar_distancia_duas_palavras(char* string1 , char* string2 , int ** matriz_indices , int * linhas_indices, int linhas_matriz_mensagem, char ** matriz_palavras , int linhas_matriz_palavras);
int numero_de_frases_mensagem (char** matriz_mensagem , int linhas_matriz_mensagem);
char ** matriz_de_frases (char ** matriz_mensagem , int linhas_matriz_mensagem , int numero_frases);
float frequencia_de_reutilizacao(char* string, int total_palavras, int linhas_matriz_mensagem, char ** matriz_palavras, int linhas_matriz_palavras, int *array_ocorrencias);
int * count_matriz_de_pontuacao (char ** matriz_mensagem , int linhas_mensagem );
int * matriz_de_pontuacao (char ** matriz_mensagem , int linhas_mensagem ,int ** matriz_de_pontuacao, char ** pontuacao , int size_pontuacao);
void reconstruir_mensagem(int ** matriz_pontuacao , int ** matriz_indice_palavras , int linhas_matriz , int * linhas_matriz_pontuacao , int * linhas_matriz_indices , char ** pontuacao , char ** matriz_palavras , int size_matriz_palavras  );
void KMPsearch_modificado(char * text, char * pat, int** dfa , int len, int paragrafo);
int verificacao_caracter_ou_numero(char c);
int contar_distancia_desde_inicio_de_uma_palavra_KMP(char * string,char ** text, int linhas_matriz_mensagem);
int contar_distancia_duas_palavras_KMP(char * string1 , char* string2 , char** matriz_mensagem , int linhas_matriz_mensagem , char ** matriz_palavras , int linhas_matriz_palavras);
void frequencia_relativa_letras_alfabeto(char ** matriz_palavras , int linhas_matriz_palavras , int * array_ocorrencias);
float calculo_media_palavras(char ** matriz_palavras , int linhas_matriz_palavras, int * array_ocorrencias , int total_palavras);
int total_de_palavras(int linhas_matriz_palavras , int * array_ocorrencias);
float frequencia_relativa_palavras_menores_m(char ** matriz_palavras , int linhas_matriz_palavras , int *array_ocorrencias , int M , int total_palavras);
void palavras_com_possiveis_raizes_comuns(char ** matriz_palavras , int linhas_matriz_palavras, char * palavra);
char ** create_prefix_array(char *str);

#endif // PROJETO_FUNCOES_H_INCLUDED
