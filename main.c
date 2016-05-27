//
//  main.c
//  MTM4
//
//  Created by Noam Stolero on 25.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#include "matrixGraph.h"
#include "linkedListGraph.h"


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
    int gm[N][N];
    int mainG[3]={0,3,5};
    graph g;

    
    initMatGraph(gm,N);
    initGraph(&g);
    
    insterEdgesLink(&g);
    insertEdgesMat(gm);
    
    print_matrix_graph(gm, N);
    print_linked_graph(&g, N);
    
    if(is_main_matrix(gm, N, mainG, 3))
        printf("is main\n");
    if (isMainGroup(&g, N, mainG, 3))
        printf("main group!\n");
    return 0;
}