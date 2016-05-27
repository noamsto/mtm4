/*
 MTM4 - Yahel Tsufim -304952898, Noam Stolero -201581683.
 job inquiry, Air Port, and Graphs
 File: main.c
 */

#include "matrixGraph.h"
#include "linkedListGraph.h"
#include <stdio.h>

/*fill graph Matrix with Edges*/
void insertEdgesMat(int g[][N])
{
    addMatEdge(g, N, 0, 1);
    addMatEdge(g, N, 0, 6);
    addMatEdge(g, N, 1, 2);
    addMatEdge(g, N, 1, 3);
    addMatEdge(g, N, 1, 5);
    addMatEdge(g, N, 2, 6);
    addMatEdge(g, N, 2, 3);
    addMatEdge(g, N, 3, 4);
    addMatEdge(g, N, 4, 5);
    addMatEdge(g, N, 4, 6);
    addMatEdge(g, N, 5, 6);
}

/*fill graph linked list with edges*/
void insterEdgesLink(graph* g)
{
    addEdge(g, 0, 1,2);
    addEdge(g, 0, 6,2);
    addEdge(g, 1, 2,2);
    addEdge(g, 1, 3,2);
    addEdge(g, 1, 5,2);
    addEdge(g, 2, 6,2);
    addEdge(g, 2, 3,2);
    addEdge(g, 3, 4,2);
    addEdge(g, 4, 5,2);
    addEdge(g, 4, 6,2);
    addEdge(g, 5, 6,2);
}


int main()
{
    int gm[N][N];   /*decalre matrix graph*/
    int mainG[3]={0,3,5}; /*declare main group*/
    graph g;    /*declare linked list graph*/

    
    initMatGraph(gm,N); /*init matrix graph and linked list graph*/
    initGraph(&g);
    
    insterEdgesLink(&g);    /*insert edges to both graphs*/
    insertEdgesMat(gm);
    
    print_matrix_graph(gm, N);  /*print the 2 graphs.*/
    print_linked_graph(&g, N);
    
    
    /*check if the group is main group and print result*/
    printf("Checking for main group in graphs:\n");
    if(is_main_matrix(gm, N, mainG, 3))
        printf("Matrix check: main group!\n");
    if (isMainGroup(&g, N, mainG, 3))
        printf("Linked List Check: main group!\n");
    return 0;
}