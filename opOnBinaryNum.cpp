#include <iostream>
using namespace std;

struct node
{
	char bit;
	struct node * next;
	struct node * previous;
};
class binary1
{
	struct node * head , * temp1 , * p ;
	int n;
	char carry;
public:
	binary1(){carry = '0'; n = 0; p = NULL; temp1 = NULL; head = NULL;}
	struct node * gethead(){return  head;}
	struct node * getp(){return  p;}
	int getn(){return n;}
	void accept();
	void display();
	void onescomp();
	void twoscomp();
	void addition();
	char carr(char,char);
};
void binary1::accept()
{
	cout << "Enter The Number Of Bits:";
	cin >> n;
	temp1 = new struct node;
	cout << "Enter The BITS : ";
	char e;
	cin >> e;
	temp1 -> bit = e;
	temp1 -> next = NULL;
	temp1 -> previous = NULL;
	head = temp1;
	p = temp1;
	for(int i = 1 ; i < n ; i++)
	{
		temp1 = new struct node;
		cin >> e;
		temp1 -> bit = e;
		temp1 -> next = NULL;
		temp1 -> previous = p;
		p -> next = temp1;
		p = p -> next;
	}
}
void binary1::display()
{
	p = head ;
	cout << "--------------------------------------------------" << endl;
	cout << "The Binary Number is :" << endl;
	if(carry == '1')
	{
		cout << carry;
	}
	for(int i = 0 ; i < n ; i++)
	{
		cout << p -> bit ;
		p = p -> next;
	}
	cout << endl;
}
void binary1::onescomp()
{
    cout << "--------------------------------------------------" << endl;
	cout << "The One's Complement is: " << endl;
	p = head;
	for(int i = 0 ; i < n-1 ; i++)
	{
		if(p -> bit == '0')
		{
			cout << 1;
		}
		else if(p -> bit == '1')
		{
			cout << 0;
		}
		p = p-> next;
	}
	if(p -> bit == '0')
	{
		cout << 1;
	}
	else if(p -> bit == '1')
	{
		cout << 0;
	}
	cout << endl;
}
void binary1::twoscomp()
{
	p = head;
	for(int i = 0 ; i < n-1 ; i++)
	{
		if(p -> bit == '0')
		{
			p -> bit = '1';
		}
		else if(p -> bit == '1')
		{
			p -> bit =  '0';
		}
		p = p-> next;
	}
	if(p -> bit == '0')
	{
		p -> bit = '1';
	}
	else if(p -> bit == '1')
	{
		p -> bit =  '0';
	}
	//NEw

	carry = carr(p -> bit, '1');
	if(carry == '0')
	{
		p -> bit = '1';
	}
	else if(carry == '1')
	{
		p -> bit = '0';
	}
	p = p -> previous;
	for(int i = 0 ; i < n-1 ; i++)
	{
		if(carry == '1')
		{
			carry = carr(p -> bit , carry);
			if(carry == '0')
				p -> bit = '1';
			else if(carry == '1')
				p -> bit = '0';
		}
		p = p -> previous;
	}
	p = head ;
	cout << "--------------------------------------------------" << endl;
	cout << "The Tows Compliment is :" << endl;
	if(carry == '1')
	{
		cout << carry;
	}
	for(int i = 0 ; i < n ; i++)
	{
		cout << p -> bit ;
		p = p -> next;
	}
	cout << endl;
}
void binary1::addition()
{

	binary1 o1,o2;
	o1.accept();
	o2.accept();
	char carry1 = '0';

	if(o1.getn() != o2.getn())
	{
	    cout << "--------------------------------------------------" << endl;
		cout << "Please Enter Same Number Of Binary Digits" << endl;
	}
	else
	{
		struct node * head1 , * head2 , * p1 , * p2;
		head1 = o1.gethead();
		p1 = o1.getp();
		head2 = o2.gethead();
		p2 = o2.getp();
		p1 = head1;
		p2 = head2;
		for(int i = 0 ; i < o1.getn() - 1 ; i++)
		{
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		//Calculation
		for(int i = 0 ; i < o1.getn() ; i++)
		{
			if(carry1 == '0' && p1 -> bit == '0' && p2 -> bit == '0')
			{
				p1 -> bit = '0';
				carry1 = '0';
			}
			else if(carry1 == '0' && p1 -> bit == '0' && p2 -> bit == '1')
			{
				p1 -> bit = '1';
				carry1 = '0';
			}
			else if(carry1 == '0' && p1 -> bit == '1' && p2 -> bit == '0')
			{
				p1 -> bit = '1';
				carry1 = '0';
			}
			else if(carry1 == '0' && p1 -> bit == '1' && p2 -> bit == '1')
			{
				p1 -> bit = '0';
				carry1 = '1';
			}
			else if(carry1 == '1' && p1 -> bit == '0' && p2 -> bit == '0')
			{
				p1 -> bit = '1';
				carry1 = '0';
			}
			else if(carry1 == '1' && p1 -> bit == '0' && p2 -> bit == '1')
			{
				p1 -> bit = '0';
				carry1 = '1';
			}
			else if(carry1 == '1' && p1 -> bit == '1' && p2 -> bit == '0')
			{
				p1 -> bit = '0';
				carry1 = '1';
			}
			else if(carry1 == '1' && p1 -> bit == '1' && p2 -> bit == '1')
			{
				p1 -> bit = '1';
				carry1 = '1';
			}
			p1 = p1 -> previous;
			p2 = p2 -> previous;
		}
    cout << "--------------------------------------------------" << endl;
	cout << "The Addition is :" << endl;
    p1 = head1;
	if(carry1 == '1')
	{
		cout << carry1;
	}
	for(int i = 0 ; i < o1.getn() ; i++)
	{
		cout << p1 -> bit ;
		p1 = p1 -> next;
	}
	cout << endl;
	}

}
char binary1::carr(char a , char b)
{
	if(a == '1' && b == '1')
		return '1';
	else
		return '0';
}

int main()
{

	char ch;
    do
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Find The One's Compliment Of A Binary Number(1) : " << endl;
        cout << "Find The Two's Compliment Of A Binary Number(2) : " << endl;
        cout << "Find The Sum Of Two Binary Numbers(3) : " << endl;
        cout << "EXIT(4) : " << endl;
        cin >> ch;
        switch(ch)
        {
        case '1':
            {
                binary1 o;
                o.accept();
                o.onescomp();
                break;
            }
        case '2':
            {
                binary1 o;
                o.accept();
                o.twoscomp();
                break;
            }
        case '3':
            {
                binary1 o;
                o.addition();
                break;
            }
        case '4':
            {
                cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" << endl;
                cout << "Thank You" << endl;
                cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
                break;
            }
        default:
            {
                cout << "--------------------------------------------------" << endl;
                cout << "Please Enter Correct Choice" << endl ;
            }
        }
    }while(ch != '4');
	return 0;
}
