/*
 * time complexity
 * 
 * average case time complexity: O(NlogN)
 * best case time complexity:    O(N)
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void merge(int data[], int firstbiginning, int secondbiginning, int lastindex);
void print(int len,int data[]);
void mergesort(int startindex, int endindex, int data[])
{
	if(endindex == startindex){
		return;
	}
	int mid = (endindex + startindex)/2;
	mergesort(startindex, mid, data);
	mergesort(mid+1, endindex, data);
	merge(data, startindex, mid+1, endindex);
}
void merge(int data[], int firstbiginning, int secondbiginning, int lastindex)
{
	int size = lastindex - firstbiginning + 1, firstendindex = secondbiginning - 1;
	int *temp = malloc(size*sizeof(int));
	int tempindex = 0;
	while(firstbiginning <= firstendindex && secondbiginning <= lastindex){
		if(data[firstbiginning] <= data[secondbiginning])
			temp[tempindex++] = data[firstbiginning++];
		else
			temp[tempindex++] = data[secondbiginning++];
	}
	while(firstbiginning <= firstendindex)
		temp[tempindex++] = data[firstbiginning++];
	while(secondbiginning <= lastindex)
		temp[tempindex++] = data[secondbiginning++];
	for(; tempindex > 0;){
		data[lastindex--] = temp[--tempindex];
	}
	free(temp);
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
	mergesort(0, 11, a);
	print(12,a);
}