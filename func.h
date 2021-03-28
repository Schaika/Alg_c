#ifndef FUNC_GB
#define FUNC_GB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapInt(int *a, int *b);
void swapDbl(double *a, double *b);

int* initIntArray(const int len);
int** init2dIntArray(int** array, const int row, const int col);

void fillIntRandom(int* arr, const int len, int border);
void fill2dIntArray(int** array, const int row, const int col, int border);

void printIntArray(int* arr, const int len);
void print2dIntArray(int** array, const int row, const int col);

void sortIntBubble(int* arr, const int len);
void sortIntShaker(int* arr, const int len);

void sortIntInsert(int* arr, const int len);



void swapInt(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void swapDbl(double *a, double *b) 
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

int* initIntArray(const int len) 
{ 
	return (int*) calloc(sizeof(int), len); 
}

int** init2dIntArray(int** array, const int row, const int col)
{
	array = (int**) malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i)
		*(array + i) = (int*) calloc(sizeof(int*), col);
	return array;
}

void fillIntRandom(int* arr, const int len, int border)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
		*(arr + i) = rand() % border;
}

void fill2dIntArray(int** array, const int row, const int col, int border)
{
	srand(time(NULL));
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(*(array + i) + j) = rand() % border;
}

void printIntArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%4d ", *(arr + i));
	puts("");
}

void print2dIntArray(int** array, const int row, const int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%4d ", *(*(array + i) + j));
		puts("");
	}
	puts("");
}

void sortIntBubble(int* arr, const int len)
{
	for (int j = 0; j < len; ++j)
		for (int i = 0; i < len - 1; ++i)
			if (arr[i] > arr [i + 1])
				swapInt(&arr[i], &arr[i + 1]);
}

void sortIntShaker(int* arr, const int len)
{
	int left = 1;
	int right = len - 1;
	while (left <= right) {
		int i;
		for (int i = right; i >= left; --i)
			if (arr[i - 1] > arr[i])
				swapInt(&arr[i], &arr[i - 1]);
		left++;
		for (int i = left; i <= right; ++i)
			if (arr[i - 1] > arr[i])
				swapInt(&arr[i], &arr[i - 1]);
		right--;
	}
}

void sortIntInsert(int* arr, const int len)
{
	int temp, pos;
	for (int i = 1; i < len; ++i) {
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

#endif