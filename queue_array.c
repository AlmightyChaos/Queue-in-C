#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define QUEUE_SIZE 5
#define BUFFER_SIZE 100

typedef enum{
	false = 0,
	true = 1
} bool;

int queue[QUEUE_SIZE];
int front = QUEUE_SIZE - 1;
int rear = QUEUE_SIZE - 1;
bool full = false;
bool enqueue(int);
bool dequeue(int*);

int main(void) {
	int value;
	char input[BUFFER_SIZE], *ins, *pch, *dlt = " ";
	while(memset(input, '\0', BUFFER_SIZE), scanf("%[^\n]", input), getchar()){
		ins = strtok(input, dlt);
		ins[strlen(ins)] = ' ';
		pch = strtok(NULL, dlt);
		if(strncmp(ins, "dequeue ", 8) == 0){
			if(pch != NULL){
				printf("Too many arguments of dequeue!\n");
				continue;
			}
			if(dequeue(&value))
				printf("dequeue %d\n",value);
			else
				printf("The queue is empty!\n");
		}

		else if(strncmp(ins, "enqueue ", 8) == 0){
			if(pch != NULL){
				if(!(value = atoi(pch))){
					printf("queue value error!\n");
					continue;
				}

			}
			else{
				printf("Too few arguments of enqueue!\n");
				continue;
			}
			if(enqueue(value))
				printf("enqueue successfully!\n");
			else
				printf("The queue is full!\n");
		}
		else
			printf("Please enter meaningful instructions!\n");
	}
	return 0;
}

bool enqueue(int value) {
	if (full)
		return false;
	else{
		if (++rear == QUEUE_SIZE)
			rear = 0;
		queue[rear] = value;
		if (front == rear)
			full = true;
		return true;
	}
}
bool dequeue(int* value) {
	if (front == rear && !full)
		return false;
	else{
		if (++front == QUEUE_SIZE)
			front = 0;
		*value = queue[front];
		full = false;
		return true;
	}
}


