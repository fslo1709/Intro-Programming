#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"componentPart.h"

int rec(ComponentPart list[], int id){
    if(list[id].price==0)
        for(int i=0;i<list[id].numComponent;i++)
            list[id].price+= rec(list, list[id].componentPartList[i]);
    return list[id].price;
}
int cmp(const void*a, const void*b){
    return strcmp((*(ComponentPart **)a)->name, (*(ComponentPart **)b)->name);
}
void findPrice(int N,ComponentPart list[]){
    ComponentPart* temp[N];
    for(int i=0;i<N;i++){
        if(list[i].price==0)
            rec(list, i);
        temp[i] = &list[i];
    }
    qsort(temp, N, sizeof(ComponentPart*), cmp);
    for(int i=0;i<N;i++)
        printf("%s %d\n", temp[i]->name, temp[i]->price);
}
