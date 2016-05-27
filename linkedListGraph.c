/*
 MTM4 - Yahel Tsufim -304952898, Noam Stolero -201581683.
 job inquiry, Air Port, and Graphs
 File: linkedListGraph.c
 */





#include "linkedListGraph.h"
#include <stdio.h>



/*adding edge to graph*/
void addEdge (graph* g, int verFrom, int verTo, int times)
{
    
    vertex * newVer;
    vertex* temp;
    
    /*stop the function depands on critical conditions.*/
    if(verTo >= N || verTo<0 || verFrom >=N || verFrom<0)
        return;
    
    /*stop the function depands on time parameter*/
    if (times==0)
        return;
    
    /*create a node with required vertex information.*/
    newVer=(vertex*)malloc(sizeof(vertex));
    newVer->val=verTo;
    
    temp=g->array[verFrom].next;    /*add the vertex to the head of relevant index, no special sorting.*/
    g->array[verFrom].next=newVer;
    newVer->next=temp;
    
    
    /*the function will call itself "time" times.*/
    addEdge ( g, verTo,verFrom, times-1);
    
    
}


/*init a node*/
void initGraph (graph* g)
{
    int i;
    
    for (i=0;i<N; i++){
        g->array[i].val=i;
        g->array[i].next=NULL;
    }
}



/*check if a group in the graph is main group*/
int isMainGroup(graph* g, int size, int group[], int groupSize)
{
    int i,j, foundFlag;
    vertex *temp;
    
    /*3 loops. first for the Vertex array, second for each vertex linkedList, third for check group.*/
    for (i=0 ; i<size; i++){
        temp=g->array+i;    /*next vertex*/
        foundFlag =0;   /*flag indicating if a vertex is in the MainGroup, or have an edge with it*/
        while (temp!=NULL){
            for (j=0; j<groupSize; j++){ /*group loop*/
                if (temp->val==group[j]){
                    foundFlag=1;    /*if a vertex connected to the group, flag on*/
                    break;
                }
            }
            if (foundFlag)  /*continue check*/
                break;
            temp=temp->next;    /*check next node for connection*/
        }
        if (!temp)  /*if test finished and temp is NULL, the group is not main, return 0*/
            return 0;
    }
    /*the test did not finished completely, there for the group is main.*/
    return 1;
}


/*function printing the linked list*/
void print_linked_graph(graph* g, int size)
{
    int i;
    for (i=0; i<size; i++ ){
        printf("Vertex %d->", i);
        vertex *temp=g->array[i].next;
        while (temp!=NULL){
            printf("%d%s",temp->val, temp->next!=NULL ? "->":".");
            temp=temp->next;
        }
        putchar('\n');
    }
    printf("\n");

}

