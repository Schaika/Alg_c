#include <stdio.h>
#include <stdlib.h>
//*************************************************************************************//
// вспомогательные функции
#define T int
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode {
	T dat;
	struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
	OneLinkNode *head;
	int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst);
void printOneLinkNode(OneLinkNode *n);
void printOneLinkList(OneLinkList *lst);
boolean insertOneLinkList(OneLinkList *lst, T value);
OneLinkNode* removeOneLinkList(OneLinkList *lst, T value);
//*************************************************************************************//
//1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
boolean checkBrackets(char* string){
		if(string[0] == '\0') return true;
		OneLinkList *count = (OneLinkList*) malloc(sizeof (OneLinkList));
		initOneLinkList(count);
		const int NUM = 3;
		char open[] = {'{','[','('};
		char close[] = {'}',']',')'};
		int iterator = 0;
		while (string[iterator] != '\0') {
			char current=string[iterator];
			for(int i = 0; i < NUM; i++){
				if(current==open[i]){
					if(insertOneLinkList(count,current)){
						break;
					}else{
						printf("OUT OF MEMORY!");
						free(count);
						return false;
					}
				}
				if(current==close[i]){
					OneLinkNode* tmp = removeOneLinkList(count,open[i]);
					if(tmp == NULL) {
						free(count);
						return false;
					}else{
						break;
					}
				}
			}
			iterator++;
		}
		if(count->size==0){
			free(count);
			return true;
		}else{
			free(count);
			return false;
		}
	}
//2. Создать функцию, копирующую односвязный список (без удаления первого списка).
OneLinkList* copyOneLinkList(OneLinkList* lst){
		OneLinkList *newList = (OneLinkList*) malloc(sizeof (OneLinkList));
		initOneLinkList(newList);
		OneLinkNode *current=lst->head;
		if(current!=NULL){
			do{
				insertOneLinkList(newList,current->dat);
				current = current->next;
			}while (current != NULL);
		}
		return newList;
	}

//3. Реализуйте алгоритм, который определяет, отсортирован ли связный список.
boolean isSorted(OneLinkList* lst){
		if(lst->head == NULL){
			return true;
		}
		OneLinkNode *current=lst->head;
		OneLinkNode *previos = current;
		while (current->next != NULL && current->dat >= previos->dat) {
			previos = current;
			current = current->next;
		}
		if(current->next == NULL && current->dat >= previos->dat){
			return true;
		}else{
			return false;
		}
	}
int main()
	{

		OneLinkList *listOne = (OneLinkList*) malloc(sizeof (OneLinkList));
		initOneLinkList(listOne);
		insertOneLinkList(listOne,5);insertOneLinkList(listOne,2);insertOneLinkList(listOne,3);insertOneLinkList(listOne,4);insertOneLinkList(listOne,56);insertOneLinkList(listOne,9);insertOneLinkList(listOne,-3);insertOneLinkList(listOne,0);
		printf("List one: ");printOneLinkList(listOne);
		OneLinkList *listTwo = copyOneLinkList(listOne);
		printf("List two: ");printOneLinkList(listTwo);
		free(listOne);
		free(listTwo);

		printf("\n\n");

		char* string = "[2/{5*(4+7)}]";
		printf("Counting braces in `%s` : %s\n",string,checkBrackets(string)?"TRUE":"FALSE");
		string = "[9]0()}({)}[9]0]";
		printf("Counting braces in `%s` : %s\n",string,checkBrackets(string)?"TRUE":"FALSE");

		printf("\n\n");

		OneLinkList *listThree = (OneLinkList*) malloc(sizeof (OneLinkList));
		initOneLinkList(listThree);
		insertOneLinkList(listThree,1);
		insertOneLinkList(listThree,1);
		insertOneLinkList(listThree,23);
		insertOneLinkList(listThree,31);
		insertOneLinkList(listThree,49);
		insertOneLinkList(listThree,56);
		insertOneLinkList(listThree,56);
		printf("List Three: ");printOneLinkList(listThree);
		printf("List is %s\n",isSorted(listThree)?"sorted":"not sorted");
		free(listThree);

		OneLinkList *listFour = (OneLinkList*) malloc(sizeof (OneLinkList));
		initOneLinkList(listFour);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,-1);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		insertOneLinkList(listFour,0);
		printf("List Three: ");printOneLinkList(listFour);
		printf("List is %s\n",isSorted(listFour)?"sorted":"not sorted");
		free(listFour);
		return 0;
	}



//*************************************************************************************//
// вспомогательные функции
void initOneLinkList(OneLinkList *lst){
		lst->head = NULL;
		lst->size = 0;
	}
boolean insertOneLinkList(OneLinkList *lst, T value){
		OneLinkNode *new = (OneLinkNode*) malloc(sizeof (OneLinkNode));
		if(new == NULL) return false;

		new->dat = value;
		new->next = NULL;

		OneLinkNode *current = lst->head;
		if(current == NULL){
			lst->head = new;
		}else{
			while (current->next != NULL){
				current = current->next;
			}
			current->next = new;
		}
		lst->size++;
		return true;
	}
OneLinkNode* removeOneLinkList(OneLinkList *lst, T value){
		OneLinkNode *current = lst->head;
		OneLinkNode *previos = NULL;
		if(current == NULL) return NULL;
		while (current->next != NULL && current->dat != value) {
			previos = current;
			current = current->next;
		}
		if(current->dat != value) return NULL;
		if(current == lst->head){
			lst->head = current->next;
			lst->size--;
			return current;
		}
		previos->next = current->next;
		lst->size--;
		return current;
	}
void printOneLinkNode(OneLinkNode *n){
		if(n == NULL){
			printf("[]");
			return;
		}
		printf("[%d]",n->dat);
	}
void printOneLinkList(OneLinkList *lst){
		OneLinkNode *current = lst->head;
		if(current == NULL){
			printOneLinkNode(current);
		}else{
			do{
				printOneLinkNode(current);
				current = current->next;
			}while(current != NULL);
		}
		printf(" Size: %d\n",lst->size);
	}
//*************************************************************************************//
