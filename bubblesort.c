#include <stdio.h>

void bubblesort(int len, int data[])
{
	int i, j, temp;
	for(i = 0; i < len-1; i++){
		for(j = 1; j < len - i; j++){
			if(data[j] < data[j-1]){
				temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
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
	bubblesort(12, a);
	print(12, a);
}
				