#include <stdio.h>
#define WIDTH 8
#define HEIGHT 8
//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию
void DecToBin(int number){
		if (number == 0) return;
			DecToBin(number/2);
			printf("%d",number%2);
			return;
	}
//2. Реализовать функцию возведения числа [a] в степень [b]

int Power(int a, int b){
		if(b==0) return 1;
		return a * Power(a,b-1);
	}

int PowerAlt(int a, int b){
		if(b==0) return 1;
		if (b%2==1) return a * Power(a,b-1);
		if (b%2==0) return Power(a*a,b/2);
		return 0; //никогда не достигает этого
	}
//3. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка)
int routeWithObsticales(int x, int y,int board[WIDTH][HEIGHT]){
		if(x == 0 && y == 0) return 0;
		if(board[x][y]==1) return 0;
		if(x == 0){
			if(routeWithObsticales(x,y-1,board) == 0 && y!=1) return 0;
			return 1;
		}
		if(y == 0){
			if(routeWithObsticales(x-1,y,board) == 0 && x!=1) return 0;
			return 1;
		}
		return routeWithObsticales(x,y-1,board)+routeWithObsticales(x-1,y,board);
	}
void drawBoard(int board[WIDTH][HEIGHT]){
		for(int y = 0; y < HEIGHT; y++){
			for(int x = 0; x < WIDTH; x++)
				printf("%5d",board[x][y]);
			printf("\n");
		}
	}
int main()
	{
		DecToBin(1023);printf("\n");
		printf("%d\n",Power(2,20));
		printf("%d\n",PowerAlt(2,20));

		int board[WIDTH][HEIGHT] = {};
		board[2][1]=1;
		board[2][2]=1;
		board[2][3]=1;
		board[2][4]=1;
		printf("-----------\n");
		drawBoard(board);
		printf("-----------\n");

		for(int y = 0; y < HEIGHT; y++){
			for(int x = 0; x < WIDTH; x++)
				printf("%5d",routeWithObsticales(x,y,board));
			printf("\n");
		}

		return 0;
	}
