//
//  linkedListGraph.h
//  MTM4
//
//  Created by Noam Stolero on 25.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#ifndef linkedListGraph_h
#define linkedListGraph_h

#include <stdio.h>
#include <stdlib.h>
#define N 7



typedef struct vertices{
    int val;                /*value of vertex*/
    struct vertices *next;  /*point to next vertex in linked list*/
}vertex;



typedef struct graphLinked{
    vertex array[N];            /*array of N (predefined number) vertices */
    int size;                   /*size of the  array*/
}graph;


void addEdge (graph* g, int verFrom, int verTo, int times);
/*add edge to the graph from two vertices*/

void initGraph (graph* g);
/*intinalize link list graph*/

int isMainGroup(graph*, int, int group[], int);
/*check if a group is a main group in the graph (linked list graph)*/

void print_linked_graph(graph*,int);
/*print graph (linked list) to output*/


#endif /* linkedListGraph_h */
