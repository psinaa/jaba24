#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
struct stack
{
	int number;
	char name[80];
	struct listitem* next;
};
typedef struct stack stack;
struct stack* push(stack* lst, int number, char name[80]);
struct stack* add(int a, char name[80]);
struct stack* pop(stack* root);
void display(stack* lst);

int main() {
	system("chcp 1251"); system("cls");
	char att[50][50];
	printf("Введите строку: ");
	scanf("%s", &att);
	stack* vars = add(15, att);
	display(vars);
}
struct stack* add(int a, char name[80])
{
	struct stack* lst;

	lst = (struct stackt*)malloc(sizeof(struct stack));
	lst->number = a;
	strcpy(lst->name, name);
	lst->next = NULL;
	return(lst);
}
struct stack* push(stack* lst, int number, char name[80])
{
	struct stack* temp, * p;
	temp = (struct stack*)malloc(sizeof(stack));
	p = lst->next;
	lst->next = temp;
	temp->number = number;
	strcpy(temp->name, name);
	temp->next = p;
	return(temp);
}
struct stack* pop(stack* root)
{
	struct stack* temp;
	temp = root->next;
	free(root);
	return(temp);
}
void display(stack* lst)
{
	struct stack* p;
	p = lst;
	printf("Итоговая строка: \n");
	while (p != NULL) {
		printf("%s ", p->name);
		p = p->next;
	}
}