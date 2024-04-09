#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 3   // global variable
int stack[MAX]; // stack implementation using Array
int top = -1;
void push(int n);
int pop(); 
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int ch, value;
    while (1)
    {
        printf("\n");
        printf("1.push");
        printf("\n2.pop");
          printf("\n5. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be push:");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            printf("\n Deleted value is %d\n", value);
            break;
             case 5:
        	exit(1);
            break;

        default:
            printf("please choose the right value\n");
        }
    }
    return 0;
}
void push(int data)
{
    if (isFull())
    {
        printf("stack overflow");
         return;
    }
    else{
    top++;
    stack[top] = data;
    }
}
int pop()
{
    int n;
    if (isEmpty())
    {
        printf("\n stack underflow");
        exit(1);
    }
    n = stack[top];
    top = top - 1;
    return n;
}
