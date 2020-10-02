#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
const int size=50;
char infix[size],postfix[size],Stack[size];
int top=-1;
int precedence(char ch);//function to get precedence of operators
char pop(); //function to pop an element from the stack
char Topelement();//function to return top element from stack without popping
void Push(char ch);//function to push an element to stack
int braces(char *);//function to match number of braces

int main()
{
	char ele,elem,st[2];
	int prep,pre,popped,j=0,chk=0;
	strcpy(postfix," ");
	system("cls");
	std::cout<<"\nEnter the infix expresion:";
	gets(infix);
	chk=braces(infix);
	if(chk!=0)
	{
		std::cout<<"Unbalanced number of braces:";
		std::cout<<(chk==1?"right braces": "left braces")<<std::endl;
		system("pause");
		exit(1);
	}
	
	for(int i=0;infix[i]!='0';i++)
	{
		if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-')
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			elem=infix[i];
			Push(elem);
		}
		else if(infix[i]==')')
		{
			while((popped=pop())!='(')
			{
				postfix[j++]=popped;
			}
		}
		else
		{
			elem=infix[i];
			pre=precedence(elem);//pre stores precedence of operator coming from infix expression
			ele=Topelement();
			prep=precedence(ele);//prep stores precedence of operator at the top of the stack
			
			if(pre>prep)
			{
				Push(elem);
			}
			else
			{
				while(prep>=pre)
				{
					if(ele=='#')
					break;
					popped=pop();
					ele=Topelement();
					postfix[j++]=popped;
					prep=precedence(ele);
				}
				Push(elem);
			}
		}
	}
	while((popped=pop())!='#')
		postfix[j++]=popped;
	postfix[j]='\0';
	std::cout<<"\n post fix:"<<postfix<<std::endl;

	return 0;
}

int precedence(char ch)
{
	switch(ch)
	{
		case'^':return 5;
		case'/':return 4;
		case'*':return 3;
		case'+':return 2;
		case'-':return 1;
		default:return 0;
	}
}


char pop()
{
	char ret;
	if(top!=-1)
	{
		ret=Stack[top];
		top--;
		return ret;
	}
	else
	{
		return '#';
	}
}


char Topelement()

{
	char ch;
	if(top!=-1)
		ch=Stack[top];
	else
		ch='#';
		return ch;
}


void Push(char ch)
{
	if(top!=size-1)
	{
		top++;
		Stack[top]=ch;
	}
}


int braces(char *s)
{
	int leftbr,rightbr;
	leftbr=rightbr=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
			leftbr++;
		else if(s[i]==')')
			rightbr++;
	}
	if(leftbr==rightbr)
		return 0;
	else if(leftbr<rightbr)
		return 1;
	else
		return -1;
}


