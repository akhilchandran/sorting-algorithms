#include <stdio.h>
#include <stdlib.h>

void selectionsort(int len,int data[])
{
	int temp, i, j;
	for (j = 0; j < len-1; j++){
		int *min = &data[j];
		for(i = j; i < len; i++){
			if(data[i] < *min){
				min = &data[i];
			}
		}
		temp = *min;
		*min = data[j];
		data[j] = temp;
	}
	return;
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
	selectionsort(12, a);
	print(12,a);
}

