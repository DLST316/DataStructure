#ifndef DISJOINGSET_H
#define DISJOINGSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjointSet
{
    struct tagDisjointSet* parent;
    void* data;
} DisjointSet;

void DS_UnionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* DS_FindSet(DisjointSet* set);
void* DS_MakeSet(void* newData);
void DS_DestroySet(DisjointSet* set);

#endif