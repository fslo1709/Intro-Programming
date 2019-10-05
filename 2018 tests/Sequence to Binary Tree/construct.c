#include "construct.h"
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) { 
        int pos = partition(arr, l, r); 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k); 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return -1; 
}

Node* leftlist(int sequence[], int BG, int ED) {
	if (ED < BG)
		return NULL;
	Node* newnode = malloc(sizeof(Node));
	newnode->value = sequence[ED];
	newnode->right = NULL;
	newnode->left = leftlist(sequence, BG, ED-1);
	return newnode;
}

Node* RecursiveConstruct(int sequence[], int BG, int ED) {
	if (ED < BG)
		return NULL;
	if (ED - BG + 1 < MAXLENGTH) {
		return leftlist(sequence, BG, ED);
	}
	int comp[ED-BG+1];
	for (int i = 0; i < ED-BG+1; i++) {
		comp[i] = sequence[BG+i];
	}
	int x = kthSmallest(comp, 0, ED-BG, ED-BG+1-MAXLENGTH+1);
	Node* newnode = malloc(sizeof(Node));
	int y = BG;
	while (sequence[y] != x) {
		y++;
	}
	newnode->value = sequence[y];
	newnode->left = RecursiveConstruct(sequence, BG, y-1);
	newnode->right = RecursiveConstruct(sequence, y+1, ED);
	return newnode;
}

Node* ConstructTree(int sequence[], int N) {
	#ifdef MAXLENGTH
	int comp[N];
	for (int i = 0; i < N; i++)
		comp[i] = sequence[i];
	int x = kthSmallest(comp, 0, N-1, N-MAXLENGTH+1);
	Node* head = malloc(sizeof(Node));
	head->value = x;
	int y = 0;
	while (sequence[y] != x) {
		y++;
	}
	head->left = RecursiveConstruct(sequence, 0, y-1);
	head->right = RecursiveConstruct(sequence, y+1, N-1);
	return head;
	#endif
}