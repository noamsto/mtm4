//
//  matrixGraph.c
//  MTM4
//
//  Created by Noam Stolero on 25.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//


#include "matrixGraph.h"


void initMatGraph(int g[][N],int size)
{
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            g[i][j] = 0;
}


void addMatEdge(int g[][N],int size,int verFrom,int verTo)
{
    if(verTo >= size || verTo<0 || verFrom >=size || verFrom<0)
    /*check if vertex is in bounds of array*/
        return;
    g[verFrom][verTo] = 1;
    g[verTo][verFrom] = 1;
    
}

int is_main_matrix(int g[][N],int size,int group[],int groupSize)
{
    int i,j,in_group;
    for(i=0;i<size;i++){
        in_group = 0;/*rcheck every vertex if in group*/
        for(j=0;j<groupSize;j++){
            if(group[j]==i){/*if vertex belong to group, no need to check*/
                in_group = 1;
                break;
            }
            if(g[i][group[j]] == 1){
                /*check if vertex outside of group has edge into the group*/
                in_group = 1;
                break;
            }
        }
        if(in_group == 0)
        /*certain vertex is neither in group nor has any edge into the group*/
            return 0;
    }
    return 1;
}

void print_matrix_graph(int g[][N], int size)
{
    int i,j;
    printf("___|");
    for(i=0;i<size;i++){
        printf("_%d_|",i);
    }
    putchar('\n');
    for(i=0;i<size;i++){
        printf("_%d_|",i);
        for(j=0;j<size;j++){
            printf("_%d_|",g[i][j]);
        }
        printf("\n");
    }
    
}


