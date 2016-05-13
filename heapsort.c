/*
 * time complexity
 * 
 * time complexity: O(NlogN)
 * 
 */
#include <stdio.h>
/* when index count from 0
 * left child index = 2*index+1,
 * right child index = 2*index+2, 
 * parent index for any child is = (index - 1)/2.
 */
 void heapify(int list[], int index, int length);
 void print(int len,int data[]); 
void makeheap(int list[], int listsize)
{
	int i;
	for(i = listsize/2; i >= 0; i--){//since index is length-1;
		heapify(list, i, listsize);
	}
}

void heapify(int list[], int index, int length)
{
	int left, right, largest, temp;
	left = 2*index + 1;
	right = 2*index + 2;
	largest = index;
	if(left < length && list[left] > list[index]){
		largest = left;
	}
	if(right < length && list[right] > list[largest]){
		largest = right;
	}
	if(largest != index){
		temp = list[index];
		list[index] = list[largest];
		list[largest] = temp;
		heapify(list, largest, length);
	}
}

void heapsort(int list[], int length)
{
	int i, temp;
	makeheap(list, length);
	for(i = length - 1; i > 0; i--){
		temp = list[0];
		list[0] = list[i];
		list[i] = temp;
		heapify(list, 0, i);
	}	
}

void print(int len,int data[])
{
	int i;
	printf("[");
	for(i = 0; i < len; i++)
		printf("%d ", data[i]);
	printf("]\n");
}

int main()
{
	int a[12] = {65,87,77,99,31,989,2143,787,684,246,7675,767};
	heapsort(a, 12);
	print(12,a);
}
