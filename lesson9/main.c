#include <stdio.h>
#include <stdlib.h>

//***************************************************//
//1. Реализовать обход в глубину с использованием стека
//функции операций со стеком
#define BIT unsigned int
#define true 1 == 1
#define false 1 != 1
typedef int bool;

int cursor = -1;
int SIZE;
bool pushStack(BIT* stack, BIT value){
		if (cursor < SIZE) {
			stack[++cursor] = value;
			return true;
		} else {
			printf("%s \n", "\t\t\tStack overflow");
			return false;
		}
	}
BIT topStack(BIT* stack) {
	if (cursor != -1) {
		return stack[cursor];
	} else {
		printf("%s", "\t\t\tStack is empty");
		return -1;
	}
}
bool popStack(BIT* stack){
		if (cursor != -1) {
			stack[cursor--]=2;
			return true;
		} else {
			printf("%s", "\t\t\tStack is empty");
			return false;
		}
	}
bool isEmptyStack(BIT* stack){
		if (cursor != -1) {
			return false;
		} else {
			return true;
		}
	}
BIT* initStack(unsigned int SZ){
		BIT *stack = (BIT*) calloc(sizeof(BIT), SZ);
		SIZE = SZ;
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
//***************************************************//
#define N 6
BIT matrix[N][N] = { //матрица из второго урока
	{0,1,1,0,0,0},
	{0,0,0,1,1,1},
	{0,0,0,0,0,1},
	{1,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,1,0},

};


//***************************************************//

void depthTraversStack(BIT start){
		unsigned int SIZE = N;
		BIT visited[N]={0};
		BIT *stack = initStack(SIZE);
		pushStack(stack,start);			//кладем в стек начальную точку
		visited[start]=1;				//помечаем начальную точку как посещенную
		while (!isEmptyStack(stack)) {	//пока стек не пуск, вызываем элемент из стека
			BIT index = topStack(stack);popStack(stack); //вызываем из стека следующий элемент
			printf("%d ",index);
				for(unsigned int i = SIZE; i > 0; i--){ //обходим строку в матрице для текущего элемента в обратном порядке (из-за специфики работы стека "last in, first out")
					if (matrix[index][i-1] == 1 && !visited[i-1]){
						pushStack(stack,i-1);
						visited[i-1]=1;
					}
				}
		}
		printf("\n");
		free(stack);
	}

//***************************************************//

//2. Моделируем робот поисковой системы.
#define M 14
BIT matrix2[M][M] = {
{0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
};
//***************************************************//
//Очередь с приоритетным исключением
typedef struct {
	int pr;
	int dat;
} Node;

#define SZ M
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
			free(node);
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
		while (items) {
			Node* node = top();
			printf("[%c,%2d] ",node->dat+65,node->pr);
			rem();
		}
		printf("\n");
	}
//***************************************************//

int visited[M] = {0};

void resetArr(){
		for (int i = 0; i < M; i++){
			visited[i]=0;
		}
	}

void depthTraversRecursive(char c){
		int r;
		int start = c-65;
		visited[start] = 1;
		int count = 0;
		for (r = 0; r < M; ++r){
			if (matrix2[start][r] == 1){
				count++;
				if(!visited[r]) depthTraversRecursive(r+65);
			}
		}

		ins(count,start);
	}

void matrixTravers(){
		for (int i = 0; i < M; i++){
			int count = 0;
				for (int j = 0; j < M; j++){
					if (matrix2[i][j] == 1) count++;
				}
				ins(count,i);
		}
	}

int main()
	{
		depthTraversStack(0);
		depthTraversStack(2);
		depthTraversStack(1);
		init();
		//обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
		printf("//***************************************************//\n");
		printf("Recursive:\n");
        depthTraversRecursive('K'); // символ [A - N] для более простого понимания ввода-вывода
		printQueue();
		//обход графа по матрице смежности (с подсчётом всех вершин графа)
		printf("Matrix:\n");
		matrixTravers();
		printQueue();
		return 0;
	}
