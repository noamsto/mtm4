//
//  MTM4
//
//  Created by Noam Stolero on 20.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//





#include "linkedListGraph.h"


void addEdge (graph* g, int verFrom, int verTo, int times)
{
    
    vertex * newVer;
    vertex* temp;
    
    if(verTo >= N || verTo<0 || verFrom >=N || verFrom<0)
        return;
    
    if (times==0)
        return;
    
    newVer=(vertex*)malloc(sizeof(vertex));
    newVer->val=verTo;
    
    temp=g->array[verFrom].next;
    g->array[verFrom].next=newVer;
    newVer->next=temp;
    
    
    addEdge ( g, verTo,verFrom, times-1);
    
    
}



void initGraph (graph* g)
{
    int i;
    
    for (i=0;i<N; i++){
        g->array[i].val=i;
        g->array[i].next=NULL;
    }
}




int isMainGroup(graph* g, int size, int group[], int groupSize)
{
    int i,j, flag;
    vertex *temp;
    
    for (i=0 ; i<size; i++){
        temp=g->array+i;
        flag =0;
        while (temp!=NULL){
            for (j=0; j<groupSize; j++){
                if (temp->val==group[j]){
                    flag=1;
                    break;
                }
            }
            if (flag)
                break;
            temp=temp->next;
        }
        if (!temp)
            return 0;
    }
    return 1;
}

void print_linked_graph(graph* g, int size)
{
    int i;
    
    
    for (i=0; i<size; i++ ){
        printf("vertex %d-> ", i);
        vertex *temp=g->array[i].next;
        while (temp!=NULL){
            printf("%d%s ",temp->val, temp->next!=NULL ? "->":"");
            temp=temp->next;
        }
        putchar('\n');
    }

}

