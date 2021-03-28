#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//вспомогательные функции
void swapInt(int *a, int *b); void fillIntRandom(int* arr, const int len, int border); int* initIntArray(const int len); void printIntArray(int* arr, const int len); void sortIntInsert(int* arr, int first, int last);

const int SIZE = 30;

int median(int *arr, int first, int last){

		int middle = (first + last) / 2;

		if(arr[first]>=arr[last] && arr[first]>=arr[middle]){
			if (arr[last]<=arr[middle]) return middle; else return last;
		}
		if(arr[middle]>=arr[last] && arr[middle]>=arr[first]){
			if (arr[last]<=arr[first]) return first; else return last;
		}
		if(arr[last]>=arr[first] && arr[last]>=arr[middle]){
			if (arr[first]<=arr[middle]) return middle; else return first;
		}
		return middle; //никогда не достигается (по-идее)
	}

void qs_adv(int *arr,int first, int last){
		if(last - first > 10){

			int i = first;
			int j = last;
			int med = median(arr,first,last);
			int middle = (first + last) / 2;
			swapInt(&arr[middle],&arr[med]);
			int x = arr[middle];
			do {
				while (arr[i] < x) i++;
				while (arr[j] > x) j--;
				if(i <= j) {
					swapInt(&arr[i], &arr[j]);
					i++;
					j--;
				}
			} while (i <= j);

			qs_adv(arr, i, last);
			qs_adv(arr, first, j);
		}else{
			sortIntInsert(arr,first,last);
			return;
		}
	}

void heapSortEven(int* arr, int len) {
		const int max = len;
		const int b = 10;

		int heap[b][max+1];
		for (int i = 0; i < b; ++i) {
			heap[i][max] = 0;
		}

		for (int digit = 1; digit < 1000000000; digit*=10) {
			for (int i = 0; i < max; ++i) {
				if (arr[i] % 2 == 0) {
					int d = (arr[i] / digit) % b;
					heap[d][heap[d][max]++] = arr[i];
					arr[i] = -1;
				}
			}
			int index = 0;
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < heap[i][max]; ++j) {
					while (arr[index] != -1) index++;

					arr[index] = heap[i][j];
				}
				heap[i][max] = 0;
			}
		}
	}



int main()
	{
		//1. Описать в коде улучшенный алгоритм быстрой сортировки
		int *arr = initIntArray(SIZE);
		fillIntRandom(arr,SIZE,100);
		printf("Array before:\n");
		printIntArray(arr,SIZE);
		qs_adv(arr,0,SIZE-1);
		printf("Array after:\n");
		printIntArray(arr,SIZE);

		printf("\n\n");

		//2. Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах при помощи алгоритма блочной сортировки
		int *arr2 = initIntArray(SIZE);
		fillIntRandom(arr2,SIZE,100);
		printf("Array before:\n");
		printIntArray(arr2,SIZE);
		heapSortEven(arr2,SIZE);
		printf("Array after:\n");
		printIntArray(arr2,SIZE);

		return 0;
	}







//вспомогательные функции
void swapInt(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
void fillIntRandom(int* arr, const int len, int border)
	{
		srand(time(NULL));
		for (int i = 0; i < len; ++i)
			*(arr + i) = rand() % border;
	}
int* initIntArray(const int len)
	{
		return (int*) calloc(sizeof(int), len);
	}

void printIntArray(int* arr, const int len)
	{
		for (int i = 0; i < len; ++i)
			printf("%2d ", *(arr + i));
		puts("");
	}
void sortIntInsert(int* arr, int first, int last)
	{
		int temp, pos, i;
		for (i = first + 1; i <= last; i++) {
			temp = arr[i];
			pos = i - 1;
			while (pos >= first && arr[pos] > temp) {
				arr[pos + 1] = arr[pos];
				pos = pos - 1;
			}
			arr[pos + 1] = temp;
		}
	}
