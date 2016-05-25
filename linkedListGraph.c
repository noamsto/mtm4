//
//  main.c
//  MTM4
//
//  Created by Noam Stolero on 20.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 7

typedef struct vertices{
    int val;
    struct vertices *next;
}vertex;



typedef struct graphLinked{
    vertex array[N];
    int size;
}graph;


void addEdge (graph* g, int verFrom, int verTo, int times){
    
    vertex * newVer;
    vertex* temp;
    
    if (times==0)
        return;
    
    newVer=(vertex*)malloc(sizeof(vertex));
    newVer->val=verTo;
    
    temp=g->array[verFrom].next;
    g->array[verFrom].next=newVer;
    newVer->next=temp;
    
    
    addEdge ( g, verTo,verFrom, times-1);
    
    
}



void initGraph (graph* g){
    int i;
    
    for (i=0;i<N; i++){
        g->array[i].val=i;
        g->array[i].next=NULL;
    }
}




int isMainGroup(graph* g, int size, int group[], int groupSize){
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




int main(int argc, const char * argv[]) {
    
    graph g;
    int mainG[3]={0,3,5};
    int i;
    
    initGraph(&g);
    
    addEdge(&g, 0, 1,2);
    addEdge(&g, 0, 6,2);
    addEdge(&g, 1, 2,2);
    addEdge(&g, 1, 3,2);
    addEdge(&g, 1, 5,2);
    addEdge(&g, 2, 6,2);
    addEdge(&g, 2, 3,2);
    addEdge(&g, 3, 4,2);
    addEdge(&g, 4, 5,2);
    addEdge(&g, 4, 6,2);
    addEdge(&g, 5, 6,2);
    
    
    
    for (i=0; i<N; i++ ){
        printf("vertex %d-> ", i);
        vertex *temp=g.array[i].next;
        while (temp!=NULL){
            printf("%d%s ",temp->val, temp->next!=NULL ? "->":"");
            temp=temp->next;
        }
        putchar('\n');
    }
    
    if (isMainGroup(&g, N, mainG, 3))
        printf("main group!\n");
    
    return 0;
}
