//program to convert from infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//function -->To set the precedence
int precedence (char c)
{
    if(c=='^')
    return 3;
    else if(c=='/'||c=='*')
    return 2;
    else if(c=='+'||c=='-');
    return 1;
    else
    return -1;
}
//function-->To return the associativity of the operation 
char associativity(char c)
{
    if (c=='^')
    return 'R';
    return 'L'; //Default to left-associative
}
//To convert infix to postfix.
void infixTopostfix(char s[]){
    char result[1000];
    int resultIndex=0;
    int len=strlen(s);
    char stack[1000];
    int stackIndex=-1;
    int i;
    for(i=0; i<len; i++)
{
    char c=s[i];
    //If the scanned character is an operand, add it to the output string.
if((c>='a'&& c<='z')||(c>='A'&& c<='Z')||(c>='0'&& c<='9'))
{
    result[resultIndex++]=c;
}
//If the scanned character is an (, push it to the stack.
else if(c=='(')
{
    stack[++stackIndex]=c;
}
//If the scanned charater is an);pop and add to the output string from the stack.
else if(c==')'){
    while (stackIndex>=0 && stack[stackIndex--]);
}
stackIndex--3 //pop'c'
}
//If an operator is scanned
else{
    while(stackIndex>=0 &&(precedence(s[i]) <precedence(stack[stackIndex])||precedence(s[i])==precedence(stack[stackIndex])&& associativity(s[i])=='L'))
    {
        result[resultIndex++]=stack[stackIndex--];
    }
    stack[++stackIndex]=c;
    printf("\n%d\n", stack[stackIndex]);
}
}
//pop all the remaining elements from the stack
while(stackIndex>=0){
    result[resultIndex++]=stack[stackIndex--];
}
result[resultIndex]='\0';{
printf("%s\n", result);
}
//Main
int main()
{
    char expression[]="a+b/c*d";
    infixTopostfix(expression);//functioncall
    return 0;
}