#include<stdio.h>
#include<conio.h>
#include<string.h>
int precedence(char c)
{
	if (c=='^')
	return 3;
	else if(c=='/'|| c=='*')
	return 2;
	else if(c=='+'||c=='-')
	return 1;
	else
	return -1;
}
char associativity(char c)
{
	if(c=='^')
	return 'R';
	return 'L';
}
void infixtopostfix(char s[])
{
	char result[1000];
	int resultIndex=0;
	int len=strlen(s);
	char stack[1000];
	int stackIndex=-1;
	int i;
	for(i=0;i<len;i++)
	{
		char c=s[i];
		// if the scanned character is an operand,jadd it to the output string
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
		{
			result[resultIndex++]=c;
		}
		else if(c=='(')
		{
			stack[++stackIndex]=c;
		}
		else if (c==')')
		{
			while(stackIndex>=0&&stack[stackIndex]!='(')
			{
				result[resultIndex++]=stack[stackIndex--];
			}
			stackIndex--;
			}//pop"("
			// if an operator is scanned
			else
			{
				while(stackIndex>=0 &&(precedence(s[i])<precedence(stack[stackIndex])||precedence(s[i])==precedence(stack[stackIndex])&&associativity(s[i])=='L'))
				{
					/* code */
					result[resultIndex++]=stack[stackIndex--];
				}
				stack[++stackIndex]=c;
				printf("\n%d\n",stack[stackIndex]);
				}
			}
			while(stackIndex>=0)
			{
				/* code */
				result[resultIndex++]=stack[stackIndex--];
			}
			result[resultIndex]='\0';
			printf("%s\n",result);
			}
			int main()
			{
				char expression[]="a+b/c*d";
				infixtopostfix(expression);// function call
				return 0;
			}

