#include <stdio.h>
//****************************************************************************************//
//1. Описать очередь с приоритетным исключением
typedef struct {
	int pr;
	int dat;
} Node;

#define SZ 20
Node* arr[SZ];
int tail;
int items;

void init(){
		for(int i = 0;i<SZ;i++){
			arr[i]=NULL;
		}
		tail = 0;
		items = 0;
	}

void ins(int pr, int dat){
		Node *node = (Node*)malloc(sizeof (Node));
		node->dat = dat;
		node->pr = pr;
		if (items < SZ) {
			arr[tail++] = node;
			items++;
		} else {
			printf("%s \n", "Queue is full!");
		}
	}

//функция top(), только возвращает элемент из очереди (не удаляет)
Node* top() {
	if (items == 0) {
		printf("%s \n", "Queue is empty");
		return NULL;
	}
	int max = arr[0]->pr;
	int idx = 0;

	for (int i = 1; i < items; ++i) {
		if (arr[i]->pr > max) {
			max = arr[i]->pr;
			idx = i;
		}
	}
	return arr[idx];
}
//функция rem(), полностью удаляет элемент и особождает его память
void rem(){
		if (items == 0) {
			printf("%s \n", "Queue is empty");
			return;
		}
		int max = arr[0]->pr;
		int idx = 0;

		for (int i = 1; i < items; ++i) {
			if (arr[i]->pr > max) {
				max = arr[i]->pr;
				idx = i;
			}
		}
		free(arr[idx]);
		while (idx < items) {
			arr[idx] = arr[idx + 1];
			idx++;
		}
		items--;
		tail--;
	}

void printQueue(){
		for (int i = 0;i<items;i++ )printf("[%4d,%4d] ",arr[i]->pr,arr[i]->dat);
		printf("\n");
	}
//****************************************************************************************//
//2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

#define BIT unsigned char
#define true 1 == 1
#define false 1 != 1
typedef int bool;

int cursor = -1;
int SIZE;
//функции операций со стеком
bool pushStack(BIT* stack, BIT value){
		if (cursor < SIZE) {
			stack[++cursor] = value;
			return true;
		} else {
			printf("%s \n", "Stack overflow");
			return false;
		}
	}
BIT topStack(BIT* stack) {
	if (cursor != -1) {
		return stack[cursor];
	} else {
		printf("%s", "Stack is empty");
		return -1;
	}
}
bool popStack(BIT* stack){
		if (cursor != -1) {
			stack[cursor--]=2;
			return true;
		} else {
			printf("%s", "Stack is empty");
			return false;
		}
	}

void DecToBin(BIT* stack,int number){
		while (number>0) {
			if(!pushStack(stack,number%2)){break;}else{number = number/2;}
		}
	}
//инициализатор стека, возвращает минимально необходимый для записи числа стек из "бит"
BIT* initBinaryStack(int number){
		//Вычисляем минимальное количество "бит" для записи числа
		int bits = 0;
		int compareWith = 1;
		do{ //по сути это pow(arg,arg). я просто не захотел подключать библиотеку math.h
			compareWith = 1;
			bits++;
			for(int i=0;i<bits;i++){
				compareWith*=2;
			}
		}while(compareWith<number);
		BIT *stack = (BIT*) calloc(sizeof(BIT), bits);
		SIZE = bits;
		DecToBin(stack,number); //сразу же переводим число в двоичную систему
		return stack;
	}
void printStack(BIT *stack){

		for(int i=0;i<SIZE;i++){
			BIT buff = topStack(stack);
			if (buff > 1) break;
			printf("%d",buff);
			popStack(stack);
		}
	}
//****************************************************************************************//
int main()
	{
		printQueue();
		ins(1,36);
		ins(2,27);
		ins(3,18);
		ins(1,9);
		ins(4,29);
		ins(2,3);
		ins(1,44);
		ins(2,8);
		ins(8,0);
		ins(44,99);
		ins(7,1023);
		printQueue();
		printf("[%4d,%4d]\n",top()->pr,top()->dat);
		rem();
		printf("[%4d,%4d]\n",top()->pr,top()->dat);
		rem();
		printf("[%4d,%4d]\n",top()->pr,top()->dat);
		rem();
		printQueue();

		//****************************************************************************************//

		{
				unsigned int number = 315708;
				BIT* bin = initBinaryStack(number);
				printf("%d(dec) = ",number);printStack(bin);printf("(bin)\n");
				free(bin); //очищаем память
		}

		{
				unsigned int number = 1201;
				BIT* bin = initBinaryStack(number);
				printf("%d(dec) = ",number);printStack(bin);printf("(bin)\n");
				free(bin); //очищаем память
		}
		return 0;
	}
