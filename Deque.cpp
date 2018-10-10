#include <iostream>
#define MAX_SIZE 10
using namespace std;
class Dqueue
{
    int arr[MAX_SIZE];
    int f ;
    int r ;
    public:
    Dqueue(){f = -1;r = -1;}
    void pushfront();
    void pushback();
    void popfront();
    void popback();
    void display();
    bool isempty();
    bool isfull();
    void check(){cout << "f:" << f << endl << "r:" << r << endl;}
};


int main(){

    Dqueue o;
    char ch;
    do{
        cout << "1.Insert at Front" << endl;
        cout << "2.Insert at Rear" << endl;
        cout << "3.Delete from Front" << endl;
        cout << "4.Delete from Rear" << endl;
        cout << "5.Display Queue" << endl;
        cout << "6.EXIT" << endl;
        cin >> ch;
        switch(ch)
        {
            case '1':
                o.pushfront();
                break;
            case '2':
                o.pushback();
                break;
            case '3':
                o.popfront();
                break;
            case '4':
                o.popback();
                break;
            case '5':
                o.display();
                break;
            case '9':
                o.check();
                break;

        }
    }while(ch != '6');

}

bool Dqueue::isfull()
{
    if(f == 0 && r == (MAX_SIZE - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Dqueue::isempty()
{
    if(f == -1 && r == - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Dqueue::pushback()
{
    if(!isfull() && r != (MAX_SIZE - 1))
    {
        cout << "Enter Element" << endl;
        int element;
        cin >> element;
        arr[r+1] = element;
        r++;
    }
    else
    {
        cout << "The Rear Is full" << endl;
    }
}

void Dqueue::pushfront()
{
    if(!isfull() && f == -1 && r == -1 )
    {
        cout << "Enter Element" << endl;
        int element;
        cin >> element;
        arr[f+1] = element;
        f++;r++;
    }else if(f != 0 )
    {
        cout << "Enter Element" << endl;
        int element;
        cin >> element;
        arr[f-1] = element;
        f--;
    }
    else
    {
        cout << "The Front Is full" << endl;
    }
}

void Dqueue::popback()
{
    if(!isempty())
    {
        cout << "The element at the back is: " << arr[r] << endl;
        if(r == f){
            r = -1 ;
            f = -1;
        }
        else
        {
            r--;
        }

    }
    else
    {
        cout << "The Queue is Empty" << endl;
    }
}

void Dqueue::popfront()
{
    if(!isempty())
    {
        cout << "The element at the front is: " << arr[f] << endl;
        if(r == f){
            r = -1 ;
            f = -1;
        }
        else
        {
            f++;
        }

    }
    else{
        cout << "The Queue is empty" << endl;
    }
}

void Dqueue::display()
{
    if(!isempty()){
    for(int i = f ; i < r+1 ; i++){
        cout << arr[i] << " " ;
    }cout << endl;
    }else{
        cout << "The Queue is empty" << endl;
    }
}
