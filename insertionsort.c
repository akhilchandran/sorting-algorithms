/*
 * time complexity
 * 
 * time complexity:    O(N^2)
 * 
 */


#include <stdio.h>
#include <stdlib.h>

void insertionsort(int len,int data[])
{
	int i;
	int j;
	int temp;
	for(i = 1; i < len; i++){
		for(j = i; j > 0 && data[j] < data[j-1]; j--){
			temp = data[j];
			data[j] = data[j-1];
			data[j-1] = temp;
		}
	}
}
void print(int len,int data[])
{
	int i;
	printf("[");
	for(i = 0; i < len; i++)
		printf(" %d", data[i]);
	printf("]\n");
}
int main()
{
	int a[12] = {65,87,77,99,31,989,2143,787,684,246,7675,767};
	insertionsort(12, a);
	print(12,a);
}

