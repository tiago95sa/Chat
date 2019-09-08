//
// Created by André Pinto on 11/12/17.
//
#include "projeto_funcoes.h"
#ifndef MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H
#define MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H

/* Link list node */
struct Node
{
    char * data;
    int id;
    struct Node* next;
};

/* function prototypes */
void MergeSort(CONVERSA** list, int flag);
void FrontBackSplit(CONVERSA* source,CONVERSA** frontRef, CONVERSA** backRef);
long int converte_timestamp_em_inteiro(TIMESTAMP * tempo);
CONVERSA* Merge(CONVERSA *a, CONVERSA *b , int flag);


#endif //MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H
