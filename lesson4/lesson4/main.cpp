#include <iostream>
#include "func.h"

void convertIndex(int index,int cols,int& row,int& col){
		row = index/cols;
		col = index - row*cols;
	}

void sortInt2dBubble(int** array,int rows,int cols){
		int len=rows*cols;

		for (int j = 0; j < len; ++j){
			for (int i = 0; i < len-1; ++i){
				int rowCur,colCur;
				int rowNext,colNext;
				convertIndex(i,cols,rowCur,colCur);
				convertIndex(i+1,cols,rowNext,colNext);
				if(array[rowCur][colCur]>array[rowNext][colNext]) swapInt(&array[rowCur][colCur],&array[rowNext][colNext]);
			}
		}
	}

int main()
	{
		const int cols=10;
		const int rows=10;
		int** arr = init2dIntArray(rows,cols);
		fill2dIntArray(arr,rows,cols,100);
		print2dIntArray(arr,rows,cols);
		sortInt2dBubble(arr,rows,cols);
		print2dIntArray(arr,rows,cols);
		return 0;
	}
