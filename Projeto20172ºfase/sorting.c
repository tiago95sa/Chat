#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib_util.h"
#include "sorting.h"

void client_demo_mergesort_bu1(void){
    int a[]={17,9,22,11,9,23,19,22,24,9,28,5,17,20,16,9};
    int aux[16];
    int N=16,i;
    printf("\nMergesort (Bottom-up)\n");
    for (i = 0; i < N; i++) {
        printf("%3d ",i);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%3d ",a[i]);
    }
    printf("\n");
    merge_sort_bu(a, aux, N);
}

void client_demo_mergesort_td1(void){
    int a[]={17,9,22,11,9,23,19,22,24,9,28,5,17,20,16,9};
    int aux[16];
    int N=16,i;
    printf("Mergesort (Top-Down)\n");
    for (i = 0; i < N; i++) {
        printf("%3d ",i);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%3d ",a[i]);
    }
    printf("\n");
    merge_sort_td(a, aux, 0, N-1);
}

void merge_sort_td(int a[], int aux[], int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (hi <= lo) return;
    merge_sort_td(a, aux, lo, mid);
    merge_sort_td(a, aux, mid+1, hi);
    merge_arrays(a, aux, lo, mid, hi);
    printArrayPart(a, lo, hi);
}

void merge_arrays(int a[], int aux[], int lo, int mid, int hi) {
    int i = lo, j = mid+1, k;
    for (k = lo; k <= hi; k++) // copy
        aux[k] = a[k];
    for (k = lo; k <= hi; k++) { // merge
        if      (i > mid)          a[k] = aux[j++];
        else if (j > hi)           a[k] = aux[i++];
        else if (aux[j] < aux[i])  a[k] = aux[j++];
        else                       a[k] = aux[i++];
    }
}

void merge_sort_bu(int a[], int aux[], int N) {
    int lo,mid,hi;
    int sz=0;
    for (sz = 1; sz < N; sz = sz+sz)
        for (lo = 0; lo < N-sz; lo += sz+sz){
            mid = lo+sz-1;
            hi = ((lo+sz+sz-1 < N-1) ? (lo+sz+sz-1) : (N-1));
            merge_arrays(a, aux, lo, mid, hi);
            printArrayPart(a, lo, hi); // debug-print
        }
}


void printArrayPart(int a[], int lo, int hi) {
    int i;
    for (i = 0; i <= hi; i++) {
        if (i>=lo)
            printf("%3d ",a[i]);
        else
            printf("    ");
    }
    printf("\n");
}


/******* Quick Sort: arrays *****/
void quicksort_rand(int a[], int n) {
    knuth_shuffle(a,n);
    quicksort_r(a, 0, n - 1);
}

void quicksort_r(int a[], int lo, int hi) {
    if (hi <= lo) return;
    int j = quickpartition(a, lo, hi);
    quicksort_r(a, lo, j-1);
    quicksort_r(a, j+1, hi);
}

int quickpartition(int a[], int lo, int hi) {
    int i = lo, j = hi+1;
    while (1) {
        while(a[++i] < a[lo])
            if (i == hi) break;

        while(a[lo] < a[--j])
            if (j == lo) break;

        if (i >= j) break;
        troca(a,i,j);
    }
    troca(a,lo,j);
    return j;
}

void troca(int * a, int lo, int j) {
    int aux = a[lo];
    a[lo]=a[j];
    a[j]=aux;
}

/** gera um inteiro aleatoriamente/uniformemente no intervalo val_min...val_max */
void knuth_shuffle(int v[], int n) {
    int aux,r,i;
    for (i=0; i<n; i++) {
        r = uniform(0,i);
        aux=v[i];
        v[i]=v[r];
        v[r]=aux;
    }
}

