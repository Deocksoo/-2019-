#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "maxheap.h"

// 1
void HeapInit(Heap * pheap, int heap_size, PriorityComp pc)
{
}

// 2
int HIsEmpty(Heap * pheap)
{
}

// 3
int GetParentIndex(int index)
{
}

int GetLChildIndex(int index)
{
}

int GetRChildIndex(int index)
{
}

int GetHiPriChildIndex(Heap *pheap, int index)
{
}

void HInsert(Heap *pheap, HData data)
{
}

HData HDeleteMax(Heap *pheap)
{
}

double Log2(double n)
{
    return log(n) / log(2);
}

void HPrintAll(Heap *pheap)
{
    if (pheap->num_of_data == 0) {
        printf("Print: Max Heap is empty.\n");
        return;
    }

    printf("----------heap----------\n");
    int height = (int)Log2(pheap->num_of_data);
    int max_leaf_num = pow(2, height);
    for(int i = 1; i <= pheap->num_of_data; i++) {
        int cur_depth = (int)Log2(i);
        int next_depth = (int)Log2(i+1);
        int wing_size = pow(2, height - cur_depth) - 1;
        for (int j = 0; j < wing_size; j++) {
            printf("   ");
        }
        if (pheap->heapArr[i] < 10) printf(" %d ", pheap->heapArr[i]);
        else if (pheap->heapArr[i] > 10 ) printf("%3d", pheap->heapArr[i]);
        for (int j = 0; j < wing_size; j++) {
            printf("   ");
        }
        printf("   ");
        if (cur_depth != next_depth) {
            printf("\n");
        }
    }
    printf("\n");
}