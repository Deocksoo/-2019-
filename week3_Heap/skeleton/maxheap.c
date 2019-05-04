#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "maxheap.h"

// 1
void HeapInit(Heap * pheap, int heap_size, PriorityComp pc)
{
    pheap->num_of_data = 0;
    pheap->heap_size = heap_size;
    pheap->get_prior = pc;
    pheap->heapArr = (HData *)malloc(sizeof(HData) * (heap_size + 1));
    
}

// 2
int HIsEmpty(Heap * pheap)
{
    return pheap->num_of_data == 0;
}

// 3
int GetParentIndex(int index)
{
    return index / 2;
}

int GetLChildIndex(int index)
{
    return index * 2;
}

int GetRChildIndex(int index)
{
    return index * 2 + 1;
}

int GetHiPriChildIndex(Heap *pheap, int index)
{
    if (GetLChildIndex(index) > pheap->num_of_data ) {
        return 0;
    } else if (GetLChildIndex(index) == pheap->num_of_data) {
        return GetLChildIndex(index);
    } else {
        if (pheap->get_prior(pheap->heapArr[GetLChildIndex(index)], pheap->heapArr[GetRChildIndex(index)]) == pheap->heapArr[GetLChildIndex(index)]) {
            return GetLChildIndex(index);
        } else {
            return GetRChildIndex(index);
        }
    }


}

void HInsert(Heap *pheap, HData data)
{
    if(pheap->heap_size == pheap->num_of_data) {
        printf("Heap is full\n");
        return;
    }

    pheap->num_of_data++;

    int new_data_idx = pheap->num_of_data;
    int parent_idx = GetParentIndex(new_data_idx);

    while(new_data_idx != 1){

        if (pheap->get_prior(data, pheap->heapArr[parent_idx]) == pheap->heapArr[parent_idx])
            break;

        pheap->heapArr[new_data_idx] = pheap->heapArr[parent_idx];
        new_data_idx = parent_idx;
        parent_idx = GetParentIndex(new_data_idx);

    }
    
    pheap->heapArr[new_data_idx] = data;
}

HData HDeleteMax(Heap *pheap)
{
    if (HIsEmpty(pheap)) {
        printf("Delete: Max Heap is empty.\n");
        return 0;
    }

    int deleted_data = pheap->heapArr[1];
    
    int idx = 1;
    HData last_data = pheap->heapArr[pheap->num_of_data];
    int hi_pri_child_idx = GetHiPriChildIndex(pheap, idx);

    while(hi_pri_child_idx){
        if (pheap->get_prior(last_data, pheap->heapArr[hi_pri_child_idx]) == last_data ) {
            break;
        }
        pheap->heapArr[idx] = pheap->heapArr[hi_pri_child_idx];
        idx = hi_pri_child_idx;
        hi_pri_child_idx = GetHiPriChildIndex(pheap, idx);
    }

    pheap->heapArr[idx] = last_data;
    pheap->num_of_data--;

    return deleted_data;
}

double Log2(double n)
{
    return log(n) / log(2);
}

void HPrintAll(Heap *pheap)
{
    if (HIsEmpty(pheap)) {
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