//
//  matrixGraph.h
//  MTM4
//
//  Created by Noam Stolero on 25.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#ifndef matrixGraph_h
#define matrixGraph_h

#define N 7


#include <stdio.h>


void initMatGraph(int g[][N],int);
/*initialize a symetric matrix graph */

void addMatEdge(int g[][N],int size,int verFrom,int verTo);
/* add edges to a non weighted graph (matrix)*/

int is_main_matrix(int g[][N],int size,int group[],int groupSize);
/*check if certain group is a main group in the graph*/

void print_matrix_graph(int g[][N], int);
/*print the matrix to output*/


#endif /* matrixGraph_h */
