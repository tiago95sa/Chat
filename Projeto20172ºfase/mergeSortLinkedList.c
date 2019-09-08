//
// Created by André Pinto on 11/12/17.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mergeSortLinkedList.h"



///* Function to insert a node at the beginging of the linked list */
//void addElement(struct Node** list, char * new_data, int key)
//{
//    /* allocate node */
//    struct Node* new_node =
//            (struct Node*) malloc(sizeof(struct Node));
//
//    new_node->data = (char *) malloc(sizeof(strlen(new_data)));
//
//    /* put in the data  */
//    strcpy(new_node->data,new_data);
//    new_node->id = key;
//
//    /* link the old list off the new node */
//    new_node->next = (*list);
//
//    /* move the head to point to the new node */
//    (*list) = new_node;
//}

//
///* Function to print nodes in a given linked list */
//void printList(MENSAGEM *node)
//{
//    while(node!=NULL)
//    {
//        printf("id -> %d %s\n",node->id, node->data);
//        node = node->next;
//    }
//}

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(CONVERSA** list, int flag)
{
    CONVERSA* aux = *list;
    CONVERSA* a;
    CONVERSA* b;

    /* Base case -- length 0 or 1 */
    if ((aux == NULL) || (aux->pnext == NULL))
    {
        //printf("entrou neste if\n");
        return;
    }
    // cutoff
    /* Split aux into 'a' and 'b' sublists */
    FrontBackSplit(aux, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a, flag);
    MergeSort(&b, flag);

    //printf("a = %d\n", a->tamanho);
    //printf("b = %d\n", b->tamanho);

    CONVERSA *auxiliar = NULL;
    auxiliar = a ;

    while(auxiliar ->pnext != NULL){
        auxiliar = auxiliar->pnext;
    }

//    printf("Saiu do mergesort\n");
    //if(b->pnext !=NULL){
    if(flag == 1){
        if(auxiliar->tamanho <= b->tamanho){
            // printf("entrou no if\n");
        auxiliar->pnext = b;
         *list = a;
        return;
        }
    } else {

        if(auxiliar->importancia <= b->importancia){
            auxiliar->pnext = b;
            *list = a;
            return ;
        }

    }
   //printf("a = %d\n", a->tamanho);
   //printf("a->pnext = %d\n", a->pnext->tamanho);
   // printf("b = %d\n" , b->tamanho);
    /* answer = merge the two sorted lists together */
    //printf("entre no merge\n");
    *list = Merge(a, b, flag);

}

CONVERSA* Merge(CONVERSA *a, CONVERSA *b , int flag)
{
    CONVERSA* result = NULL;

    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    /* Pick either a or b, and recur */
    if(flag==1){ // se for 1 , ordena por tamanho
        if (a->tamanho < b->tamanho) {
            //printf("tamanho\n");
            result = a;
            result->pnext = Merge(a->pnext, b, flag);

        } else {
            //printf("tamanho\n");
            result = b;
            result->pnext = Merge(a, b->pnext, flag);
    }
    } else if (flag == 0) { // se for 0 , ordena por timestamp
        printf("timestamp\n");
        long int timea=0 , timeb =0;
        timea = converte_timestamp_em_inteiro(a->tempo);
        timeb = converte_timestamp_em_inteiro(b->tempo);
        printf("timea = %ld\n", timea);
        printf("timeb = %ld\n", timeb);
        if (timea < timeb) {
            result = a;
            result->pnext = Merge(a->pnext, b, flag);

        } else {
            result = b;
            result->pnext = Merge(a, b->pnext, flag);
        }
    } else { // ordena por importancia
        //printf("importancia\n");
        if (a->importancia < b->importancia) {
            result = a;
            result->pnext = Merge(a->pnext, b, flag);

        } else {
            result = b;
            result->pnext = Merge(a, b->pnext, flag);
        }

    }

    return(result);
}

long int converte_timestamp_em_inteiro(TIMESTAMP * temp){

    unsigned long int tempo = 0 , aux = 0;
    printf("segundo = %d\n", temp->segundo);
    tempo = tempo + temp->segundo;
    aux = temp->minuto + 1000;
    printf("aux = %lu\n", aux);
    printf("minuto = %d\n", temp->minuto);
    tempo = tempo + aux;
    printf("mes = %d\n", temp->mes);
    aux = temp->mes + 100000;
    printf("aux = %lu\n", aux);
    tempo = tempo + aux;
    printf("ano = %d\n", temp->ano);
    aux = temp->ano + 10000000;
    printf("aux = %lu\n", aux);
    tempo = tempo + aux;
    printf("mes = %d\n", temp->mes);
    aux = temp->mes + 100000000000;
    printf("aux = %lu\n", aux);
    tempo = tempo + aux ;
    printf("dia = %d\n", temp->dia);
    aux = temp->dia + 10000000000000;
    printf("aux = %lu\n", aux);
    tempo = tempo + aux;
    printf("tempo = %lu\n", tempo);
    return tempo;

}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
void FrontBackSplit(CONVERSA* source,
                    CONVERSA** frontRef, CONVERSA** backRef)
{
    CONVERSA* fast;
    CONVERSA* slow;
    if (source==NULL || source->pnext==NULL)
    {
        /* length < 2 cases */
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->pnext;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL)
        {
            fast = fast->pnext;
            if (fast != NULL)
            {
                slow = slow->pnext;
                fast = fast->pnext;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
          at that point. */
        *frontRef = source;
        *backRef = slow->pnext;
        slow->pnext = NULL;
    }
}
