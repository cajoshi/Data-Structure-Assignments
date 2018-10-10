#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

class stClass
{
	struct stknode
	{
		char stack[50];
		int top;
	}st;
public:
	stClass()
	{
		st.top = -1;
	}
	void push(char);
	char pop();
	bool isempty(stknode);
	int check(char exp[MAX]);
	bool match(char a, char b);
};
bool stClass::isempty(stknode st)
{
	if(st.top == -1)
		return true;
	else
		return false;
}
void stClass::push(char a)
{
	if(st.top != 49)
	{
		(st.top)++;
		st.stack[st.top] = a;
	}
	else
	{
		cout << "----------------------" << endl;
		cout << "The Stack is Full" << endl;
	}
}
char stClass::pop()
{
	if(!isempty(st))
	{
		int k = st.top;
		(st.top)--;
		return st.stack[k];
	}
	else
	{
		return '0';
	}
}
bool stClass::match(char a, char b)
{
	if(a == '[' && b == ']')
		return true;
	else if(a == '{' && b == '}')
		return true;
	else if(a == '(' && b == ')')
		return true;
	else
		return false;
}
int stClass::check(char exp[])
{
	char temp1 ;
	int flag = 0;
	int n = strlen(exp);
	for(int i = 0 ; i < n ; i++)
	{
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
		{
			push(exp[i]);
		}
		else if(((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) && (!isempty(st)))
		{
			temp1 = pop();
			if(temp1 == '0')
			{
				cout << "The stack is empty";
			}
			else if(match(temp1,exp[i]) && isempty(st))
			{
				cout << "Balanced Expression" << endl;
				flag = 1;
			}


		}

	}
	if(flag == 0)
		cout << "Unbalanced Expression" << endl;
	return 0;
}
int main() {
	stClass o;
	cout << "Enter Brackets: " ;
	char exp[MAX];
	cin >> exp;
	o.check(exp);
	return 0;
}
