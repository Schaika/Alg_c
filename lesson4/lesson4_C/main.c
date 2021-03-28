#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void swapInt(int *a, int *b);
int** init2dIntArray(const int row, const int col);
void fill2dIntArray(int** array, const int row, const int col, int border);
void printDoubleArray(double* arr, const int len);
void print2dIntArray(int** array, const int row, const int col);
void convertIndex(int index,int cols,int* row,int* col);



void sortInt2dBubble(int** array,int rows,int cols){
		int len=rows*cols;

		for (int j = 0; j < len; ++j){
			for (int i = 0; i < len-1; ++i){
				int rowCur,colCur;
				int rowNext,colNext;
				convertIndex(i,cols,&rowCur,&colCur);
				convertIndex(i+1,cols,&rowNext,&colNext);
				if(array[rowCur][colCur]>array[rowNext][colNext]) swapInt(&array[rowCur][colCur],&array[rowNext][colNext]);
			}
		}
	}


void requestArrP(double* arr, const int len)
{
	printf("Input %d numbers in sequence P\n", len);
	for (int i = 0; i < len; ++i) {
		scanf("%lf", &arr[i]);
	}
}

void reverseArrP(double* arr, const int len)
{
	for (int i = 0; i < len / 2; ++i) {
		double temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

void mathArrP(double* arr, const int len)
{
	int res;
	for (int i = 0; i < len; ++i) {
		res = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (res > 400)
			printf("Number %d(%.3f) with index %d exceeds the upper limit of 400\n",res, arr[i], i);
		else
			printf("Number %d(%.3f) with index %d passed\n", res, arr[i], i);
	}
}



int main()
	{
		//1. Реализовать пузырьковую сортировку двумерного массива
		const int cols=5;
		const int rows=5;
		int** arr = init2dIntArray(rows,cols);
		fill2dIntArray(arr,rows,cols,100);
		printf("Initial array (random):\n");print2dIntArray(arr,rows,cols);
		sortInt2dBubble(arr,rows,cols);
		printf("Sorted array:\n");print2dIntArray(arr,rows,cols);

		//3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
		const int SIZE = 11;
		double arrP[SIZE];
		requestArrP(arrP, SIZE);
		printf("Entered sequence:\n");
		printDoubleArray(arrP, SIZE);
		printf("Reversed sequence:\n");
		reverseArrP(arrP, SIZE);
		printDoubleArray(arrP, SIZE);

		mathArrP(arrP, SIZE);

		return 0;
	}
//вспомогательные функции
void swapInt(int *a, int *b)
	{
		*a = *a ^ *b;
		*b = *b ^ *a;
		*a = *a ^ *b;
	}

int** init2dIntArray(const int row, const int col)
	{
		int** array = (int**) malloc(sizeof(int*) * row);
		for (int i = 0; i < row; ++i)
			*(array + i) = (int*) calloc(sizeof(int), col);
		return array;
	}

void fill2dIntArray(int** array, const int row, const int col, int border)
	{
		srand(time(NULL));
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				*(*(array + i) + j) = rand() % border;
	}

void printDoubleArray(double* arr, const int len)
	{
		for (int i = 0; i < len; ++i)
			printf("%.3f ", *(arr + i));
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

void convertIndex(int index,int cols,int* row,int* col)
	{
		*row = index/cols;
		*col = index - *row*cols;
	}

