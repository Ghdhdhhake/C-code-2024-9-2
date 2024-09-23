#include<stdio.h>

int main() {
	int max, min, temp;
	int max_index = 0, min_index = 0;
	int arr[10] = { 5,2,3,4,5,0,7,8,9,6 };
	max = arr[0];
	min = arr[0];
	for (int i = 1; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_index = i;
		}
		if (min > arr[i]) {
			min = arr[i];
			min_index = i;
		}
	}
	printf("max = %d,max_index = %d\n", max, max_index);
	printf("min = %d,min_index = %d\n", min, min_index);
	temp = arr[0];
	arr[0] = max;
	arr[max_index] = temp;
	temp = arr[9];
	arr[9] = min;
	arr[min_index] = temp;
	for (int i = 0; i < 10; i++)
		printf("%5d", arr[i]);

	return 0;
}
