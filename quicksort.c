#include <stdio.h>
#include <stdlib.h>

void print(int len,int data[]);
void quicksort(int data[], int start, int end)
{
	if(end-start < 1)
		return;
	int pivotvalue = data[start];
	int left, right, temp;
	left = start;
	right = end;
	while(left < right){
		while(left <= right && data[left] <= pivotvalue){
			left++;
		}
		while(left <= right && data[right] > pivotvalue){
			right--;
		}
		if(left < right){
			temp = data[right];
			data[right] = data[left];
			data[left] = temp;
		}
	}
	data[start] = data[left-1];
	data[left-1] = pivotvalue;
	quicksort(data, start, left-2);
	quicksort(data, left, end);
	return;
}

// void print(int len,int data[])
// {
// 	int i;
// 	printf("[");
// 	for(i = 0; i < len; i++)
// 		printf("%d ", data[i]);
// 	printf("]\n");
// }
// 
// int main()
// {
// 	int a[12] = {65,312,965,99,31,989,2143,787,684,246,7675,767};
// 	quicksort(a, 0, 11);
// 	print(12,a);
// }




void print(int len,int data[])
{
	int i;
	for(i = 0; i < len; i++)
		printf("%d ", data[i]);
	printf("\n");
}

int main()
{
	int i, N, a[100];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	quicksort( a, 0, N);
	print(N, a);
	return 0;
}

