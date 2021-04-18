#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char stack[30];
int top=-1;
void in2post(char *);
void push(char);
char pop();
int prior(char);

int main()
{
    char infix[40];
    printf("Enter Infix Expression\n");
    gets(infix);
    in2post(infix);
    return 0;
}

void push(char ch)
{
    top=top+1;
    stack[top]=ch;
}

char pop()
{
    char i;
    i=stack[top];
    top=top-1;
    return i;
}

int prior(char op)
{
    if(op=='^')
        return 5;
    else if(op=='*' || op=='/')
        return 4;
    else if(op=='+' || op=='-')
        return 3;
    else
        return 2;
}

void in2post(char infix[])
{
    int length;
    static int pos=0, index=0;
    char symbol, temp;
    char postfix[50];
    length= strlen(infix);

while(index < length)
{
    symbol= infix[index];
    switch (symbol)
    {
        case '(' : push(symbol);
                    break;
        case ')' : temp= pop();
                    while(temp!= '(')
                    {
                        postfix[pos]=temp;
                        pos++;
                        temp=pop();
                    }
                    break;
        case '+':
        case '-':
        case '*':
        case '/':
            while ( prior(stack[top]) >= prior(symbol))
            {
                temp= pop();
                postfix[pos]=temp;
                pos++;
            }
        push(symbol);
        break;

        default : postfix[pos++]= symbol;
        break;
    }
    index++;
}

while(top>=0)
{
    temp=pop();
    postfix[pos++]=temp;
}

postfix[pos++]='\0';
printf("Equivalent postfix expression is\n");
puts(postfix);
return;
}
