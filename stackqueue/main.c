#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int maxsize;    
    int top;
    int *items;
};
 
// Utility function to initialize the stack
struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
 
    return pt;
}

void freestack(struct stack *st) {
	free(st->items);
	free(st);
}
 
// Utility function to return the size of the stack
int size(struct stack *pt) {
    return pt->top + 1;
}
 
// Utility function to check if the stack is empty or not
int isEmpty(struct stack *pt) {
    return pt->top == -1;                   // or return size(pt) == 0;
}
 
// Utility function to check if the stack is full or not
int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
}
 
// Utility function to add an element `x` to the stack
void push(struct stack *pt, int x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (!isFull(pt))
    {
		pt->items[++pt->top] = x;
    }
 
 
    // add an element and increment the top's index
    
}
 
// Utility function to return the top element of the stack
int peek(struct stack *pt)
{
    // check for an empty stack
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
}
 
// Utility function to pop a top element from the stack
int pop(struct stack *pt)
{
    // check for stack underflow
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
    }
    // decrement stack size by 1 and (optionally) return the popped element
    return pt->items[pt->top--];
}

typedef struct {
	struct stack *first;
	struct stack *buffer;	
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->first = newStack(100);
	queue->buffer = newStack(100);
	return queue;
}

void myQueuePush(MyQueue* obj, int x) {
	push(obj->first, x);
}

int myQueuePop(MyQueue* obj) {
	// pop all of the first elements, push them onto buffer except last one, and return last one
	int last;
	while(!isEmpty(obj->first)) {
		last = pop(obj->first);
		if(obj->first->top >= 0) {
			push(obj->buffer, last);
		}
	}

	while(!isEmpty(obj->buffer)) {
		int toPutBack = pop(obj->buffer);
		push(obj->first, toPutBack);
	}

	return last;
}

int myQueuePeek(MyQueue* obj) {
	// The only difference to the pop funcion is that we put every item back on the first-stack.
	int last;
	while(!isEmpty(obj->first)) {
		last = pop(obj->first);
		push(obj->buffer, last);
	}

	while(!isEmpty(obj->buffer)) {
		int toPutBack = pop(obj->buffer);
		push(obj->first, toPutBack);
	}
	return last;
}

bool myQueueEmpty(MyQueue* obj) {
	return (obj->first->top < 0);
}

void myQueueFree(MyQueue* obj) {
	freestack(obj->first);
	freestack(obj->buffer);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main() {
	MyQueue *obj = myQueueCreate();
	myQueuePush(obj,1);
	myQueuePush(obj, 2);
	int one = myQueuePeek(obj);
	int two = myQueuePop(obj);
	bool isempty = myQueueEmpty(obj);
	printf("%d %d %d \n", one, two,isempty);	
	
}
