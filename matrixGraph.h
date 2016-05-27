/*
 MTM4 - Yahel Tsufim -304952898, Noam Stolero -201581683.
 job inquiry, Air Port, and Graphs
 File: matrixGraph.h
 */
#ifndef matrixGraph_h
#define matrixGraph_h

#define N 7 /*size of graph*/




void initMatGraph(int g[][N],int);
/*initialize a symetric matrix graph */

void addMatEdge(int g[][N],int size,int verFrom,int verTo);
/* add edges to a non weighted graph (matrix)*/

int is_main_matrix(int g[][N],int size,int group[],int groupSize);
/*check if certain group is a main group in the graph*/

void print_matrix_graph(int g[][N], int);
/*print the matrix to output*/


#endif /* matrixGraph_h */
