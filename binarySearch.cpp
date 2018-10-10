#include <iostream>

using namespace std;

class sorting
{
    int a[10];
    public:
    void ssort();
    void seqsearch();
    void binarysearch();
    void display();
};

void sorting::ssort()
{
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(a[j] > a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void sorting::seqsearch()
{
    cout << "-----------------------------------" << endl;
    cout << "Enter 10 Numbers" << endl;
    for(int i = 0 ; i < 10 ; i++)
    {
        cin >> a[i];
    }
        cout << "-----------------------------------" << endl;
    cout << "Enter The Number You Wnat To Search" << endl;
    int k;
    int flag = 0;
    cin >> k;
    for(int i = 0 ; i < 10 ; i++)
    {
        if(k == a[i])
        {
            cout << "-----------------------------------" << endl;
            cout << "Found the Number by sequential search" << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << "-----------------------------------" << endl;
        cout << "Did NOT find the number" << endl;
    }
}

void sorting::binarysearch()
{
    cout << "-----------------------------------" << endl;
    cout << "Enter 10 Numbers" << endl;
    for(int i = 0 ; i < 10 ; i++)
    {
        cin >> a[i];
    }
    cout << "-----------------------------------" << endl;
    cout << "Enter The Number You Wnat To Search" << endl;
    int k;
    int flag = 0;
    cin >> k;
    ssort();
    int low = 0 ;
    int up = (sizeof(a) / sizeof(int)) - 1;
    int m = (low + up) / 2;;
    do{
        if(a[m] < k)
        {
            low = m + 1 ;

        }
        else if(a[m] > k)
        {
            up = m - 1;

        }
        else if(a[m] == k)
        {
            cout << "-----------------------------------" << endl;
            cout << "Found The Number By binary search" << endl;
            flag = 1;
            break;
        }
        m = (low + up) / 2;
        if(a[m] == k)
        {
            cout << "-----------------------------------" << endl;
            cout << "Found The Number By binary search" << endl;
            flag = 1;
            break;
        }
    }while(low != up);
    if(flag == 0)
    {
        cout << "-----------------------------------" << endl;
        cout << "Couldn't Find The Number" << endl;
    }


}
void sorting::display()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << a[i] << " " ;
    }
}

int menu(sorting o)
{
    int ch;
    do{
        cout << "-----------------------------------" << endl;
        cout << "1.Sequential Search" << endl;
        cout << "2.Binary Search" << endl;
        cout << "3.EXIT" << endl;
        cin >> ch;
        switch(ch){
        case 1:
        {
            o.seqsearch();
            break;
        }
        case 2:
        {
            o.binarysearch();
            break;
        }
        default :
        {
            if(ch != 3){
            cout << "-----------------------------------" << endl;
            cout << "Enter Correct Choice" << endl;
            }
        }
        }
    }while(ch != 3);
    return 2;
}
int main()
{
    int ch;
    sorting o;
    do{
        ch = menu(o);
    }while(ch != 2);

    return 0;
}
