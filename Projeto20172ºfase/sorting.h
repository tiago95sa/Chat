#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

void merge_sort_td(int a[], int aux[], int lo, int hi);
void merge_arrays(int a[], int aux[], int lo, int mid, int hi);
void merge_sort_bu(int a[], int aux[], int N);

void printArrayPart(int a[], int lo, int hi);
void client_demo_mergesort_td1(void);
void client_demo_mergesort_bu1(void);

void quicksort_rand(int a[], int n);
void quicksort_r(int a[], int lo, int hi);
int quickpartition(int a[], int lo, int hi);
void knuth_shuffle(int v[], int n);
void troca(int * a, int lo, int j);
    
#endif // SORTING_H_INCLUDED
