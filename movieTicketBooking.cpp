#include <iostream>
#include <string>
using namespace std;

struct node
{
    char status;
    string name;
    struct node * next , * previous;
};
struct headp
{
    struct node * first;
    struct headp * next;
};

class dll
{
    struct node * p , * q , * temp1 ;
    struct headp * ph , * temph1 , * start;
    int nop;
public:
    dll()
    {
        temph1 = new struct headp ;
        temph1 -> first = NULL;
        temph1 -> next = NULL;
        ph = temph1;
        start = temph1;
        for(int i = 0 ; i < 9 ; i++)
        {
            temph1 = new struct headp ;
            temph1 -> first = NULL;
            temph1 -> next = NULL;
            ph -> next = temph1;
            ph = ph -> next;
        }

        ph = start;

        for(int i = 0 ; i < 10 ; i++)
        {
            temp1 = new struct node;
            temp1 -> status = 'A'  ;
            temp1 -> name = " " ;
            temp1 -> next = NULL;
            temp1 -> previous = NULL;
            ph -> first = temp1;
            p = temp1;
            for(int j = 0 ; j < 9 ; j++)
            {
                temp1 = new struct node;
                temp1 -> status = 'A';
                temp1 -> name = " " ;
                temp1 -> next = NULL;
                temp1 -> previous = p;
                p -> next = temp1;
                p = p -> next;
            }
            p -> next = ph -> first;
            ph = ph -> next;
        }
        nop = 0;
    }
    void bookedSeats();
    void bookASeat();
    void deleteBooking();
};
void dll::bookedSeats()
{
    cout << "------------------------------------------" << endl;
    cout << "      ==============================      " << endl << endl;
    cout << "  \t1 2 3 4 5 6 7 8 9 10 " << endl;
    int rowdisp = 1;
    ph = start ;
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << rowdisp << "\t" ;
        p = ph -> first;
        for(int j = 0 ; j < 10 ; j++)
        {
            cout << p -> status << " " ;
            p = p -> next;
        }cout << endl;
        ph = ph -> next;
        rowdisp++;
    }
}
void dll::bookASeat()
{
    if(nop != 100)
    {
        cout << "Enter The Row And Column Number of The Seat" << endl;
        cout << "Row: " ;
        int row ;
        cin >> row;
        cout << "Column: " ;
        int col;
        cin >> col;
        ph = start;
        if(col == 1 && row == 1)
        {
            p = ph -> first;
            if(p -> status == 'B')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Booked" << endl;
            }
            else
            {
                cout << "Enter Your Name: " ;
                string element;
                getline(cin >> ws , element);
                p -> name = element;
                p -> status = 'B' ;
                nop++;
            }
        }
        else if(col == 1 && row != 1)
        {
            for(int i = 0 ; i < row - 1 ; i++)
            {
                ph = ph -> next;
            }
            p = ph -> first;
            if(p -> status == 'B')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Booked" << endl;
            }
            else
            {
                cout << "Enter Your Name: " ;
                string element;
                getline(cin >> ws , element);
                p -> name = element;
                p -> status = 'B' ;
                nop++;
            }
        }
        else if(col != 1 && row == 1)
        {
            p = ph -> first;
            for(int i = 0 ; i < col - 1 ; i ++)
            {
                p = p -> next;
            }
            if(p -> status == 'B')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Booked" << endl;
            }
            else
            {
                cout << "Enter Your Name: " ;
                string element;
                getline(cin >> ws , element);
                p -> name = element;
                p -> status = 'B' ;
                nop++;
            }
        }
        else if(col != 1 && row != 1)
        {
            for(int i = 0 ; i < row - 1 ; i ++)
            {
                ph = ph -> next;
            }
            p = ph -> first;
            for(int i = 0 ; i < col - 1 ; i++)
            {
                p = p -> next;
            }
            if(p -> status == 'B')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Booked" << endl;
            }
            else
            {
                cout << "Enter Your Name: " ;
                string element;
                getline(cin >> ws , element);
                p -> name = element;
                p -> status = 'B' ;
                nop++;
            }
        }
    }
    else
    {
        cout << "----------------------------------" << endl;
        cout << "All Seats Are Booked" << endl;
    }
    bookedSeats();
}
void dll::deleteBooking()
{
    if(nop != 0)
    {
        cout << "Enter The Row And Column Number of The Seat" << endl;
        cout << "Row: " ;
        int row ;
        cin >> row;
        cout << "Column: " ;
        int col;
        cin >> col;
        ph = start;
        if(col == 1 && row == 1)
        {
            p = ph -> first;
            if(p -> status == 'A')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Not Booked" << endl;
            }
            else
            {
                cout << "----------------------------------" << endl;
                cout << "Booking Canceled" << endl;
                p -> status = 'A' ;
                nop--;
            }
        }
        else if(col == 1 && row != 1)
        {
            for(int i = 0 ; i < row - 1 ; i++)
            {
                ph = ph -> next;
            }
            p = ph -> first;
            if(p -> status == 'A')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Not Booked" << endl;
            }
            else
            {
                cout << "----------------------------------" << endl;
                cout << "Booking Canceled" << endl;
                p -> status = 'A' ;
                nop--;
            }
        }
        else if(col != 1 && row == 1)
        {
            p = ph -> first;
            for(int i = 0 ; i < col - 1 ; i ++)
            {
                p = p -> next;
            }
            if(p -> status == 'A')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Not Booked" << endl;
            }
            else
            {
                cout << "----------------------------------" << endl;
                cout << "Booking Canceled" << endl;
                p -> status = 'A' ;
                nop--;
            }
        }
        else if(col != 1 && row != 1)
        {
            for(int i = 0 ; i < row - 1 ; i ++)
            {
                ph = ph -> next;
            }
            p = ph -> first;
            for(int i = 0 ; i < col - 1 ; i++)
            {
                p = p -> next;
            }
            if(p -> status == 'A')
            {
                cout << "----------------------------------" << endl;
                cout << "The Seat Is Not Booked" << endl;
            }
            else
            {
                cout << "----------------------------------" << endl;
                cout << "Booking Canceled" << endl;
                p -> status = 'A' ;
                nop--;;
            }
        }
    }
    else
    {
        cout << "----------------------------------" << endl;
        cout << "All The Seats Are Empty" << endl;
    }
    bookedSeats();

}
int main()
{
    dll o;
    o.bookedSeats();

    int ch;
    do
	{
		cout << "\n==========================\n\tMain Menu";
		cout << "\n--------------------------";
		cout << "\n1.Book a seat\n2.Delete Booking\n3.Exit\nEnter Choice:";
		cin >> ch;
		switch(ch)
		{
			case 1: o.bookASeat();
				break;
			case 2: o.deleteBooking();
				break;
			case 3: cout<<"\nExiting from Menu...";
				break;
			default:cout<<"\nxxxx Wrong Choice xxxx";
		}
	}while(ch!=3);
	cout << "\n\n\n****************************************************************\nExit from main()!!!";
    return 0;
}
