//Pizza parlor accepting maximum n orders.Orders are served in first come first serve bases.
//Order once placed cannot be canceled.Write c++ program to simulate the system
//using circular queue using array.
#include <iostream>
#include <string>
#define MAX_SIZE 10
using namespace std;

struct queue
{
	int que[MAX_SIZE] ;
	int front = -1;
	int rear = -1;
}Q;
class pizza
{
	int n;
public:
	pizza(){for(int i = 0 ; i< MAX_SIZE ; i++)Q.que[i] = '\0'; n = 0;}
	void accept();
	void display();
	bool empty();
	bool full();
	void ready();
};

void pizza::accept()
{
	cout << "----------------------------" << endl;
	cout << "Enter Your Order number: " ;
	cin >> n;
	if(empty())
	{
		Q.front = 0;
		Q.rear = 0;
		Q.que[Q.front] = n;
	}
	else if(full())
	{
		cout << "--------------------------------------"<< endl;
		cout << "Cannot Take any More Orders, We Are Full" << endl;
	}
	else
	{
		Q.rear = (Q.rear + 1) % MAX_SIZE;
		Q.que[Q.rear] = n;
	}
}

void pizza::ready()
{
	if(Q.front == Q.rear && (Q.front != -1))
	{
		cout << "--------------------------------------------------" << endl;
		cout << "The Order Number " << Q.que[Q.front] << " is Ready.Thank You For Waiting!" << endl;
		Q.que[Q.front] = '\0';
		Q.front = -1;
		Q.rear = -1;
	}
	else if(empty())
	{
		cout << "------------------------" << endl;
		cout << "No Order In the List" << endl;
	}
	else if(Q.front != (Q.rear + 1) % MAX_SIZE )
	{
		cout << "----------------------------" << endl;
		cout << "The Order Number " << Q.que[Q.front] << " is Ready.Thank You For Waiting!" << endl;
		Q.que[Q.front] = '\0';
		Q.front = (Q.front + 1) % MAX_SIZE;
	}

}

void pizza::display()
{
	int i = 0;
	if(!empty())
	{
		cout << "-----------------------------" << endl;
		cout << "The Orders Remaining are" << endl;

		for( i = Q.front ; i != Q.rear ; i = (i + 1 ) % MAX_SIZE)
		{
			cout << Q.que[i] << endl;
		}cout << Q.que[i] << endl;
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "No Order In the List" << endl;
	}
}
bool pizza::full()
{
	if(Q.front == ((Q.rear + 1) % MAX_SIZE))
		return true;
	else
		return false;
}

bool pizza::empty()
{
	if(Q.front == -1 && Q.rear == -1)
		return true;
	else
		return false;
}
char menu(pizza o)
{
	char ch;
	do{
		cout << "---------------------" << endl;
		cout << "1.Accept Order" << endl;
		cout << "2.Ready Orders" << endl;
		cout << "3.Display orders" << endl;
		cout << "4.EXIT" << endl;
		cin >> ch;
		switch(ch)
		{
			case '1':
			{
				o.accept();
				break;
			}
			case '2':
			{
				o.ready();
				break;
			}
			case '3':
			{
				o.display();
				break;
			}
			default:
				cout << "Enter Correct Choice" << endl;
		}
	}while(ch != '4');
	return '2';
}
int main()
{
	char ch;
	pizza o;
	do{
		cout << "------------------" << endl;
		cout << "1.ORDER A PIZZA!!!!" << endl;
		cout << "2.EXIT" << endl;
		cin >> ch;
		switch(ch)
		{
		case '1':
			menu(o);
			break;
		}
	}while(ch != '2');
	return 0;
}
