#include<iostream>
using namespace std;

struct ascend
{
    int row;
    int col;
    int val;
};
int main()
{
    ascend a[10],b[10],c[20];
    int i=0,j=0,k=0,n1,n2;

    cout << "Enter size of structure 1(<10):" ;
    cin >> n1;
    cout << "Enter size of structure 2(<10):" ;
    cin >> n2;
    cout << "For structure 1:" << endl ;
    for(int m = 0 ; m < n1 ; m++ )
    {
        cout << "Enter R " << m << ":" ;
        cin >> a[m].row ;
        cout << "Enter C " << m << ":" ;
        cin >> a[m].col ;
        cout << "Enter Val " << m << ":" ;
        cin >> a[m].val ;
    }
    cout << "For Structure 2:" << endl  ;
    for(int n = 0 ; n < n2 ; n++ )
    {
        cout << "Enter R" << n << ":" ;
        cin >> b[n].row ;
        cout << "Enter C" << n << ":" ;
        cin >> b[n].col ;
        cout << "Enter Val " << n << ":" ;
        cin >> b[n].val ;
    }
    while(i < n1 && j < n2)
    {
        if(a[i].row == b[j].row)
        {
            if(a[i].col == b[j].col)
            {
                if(a[i].val == b[j].val)
                {
                    c[k].row = a[i].row;
                    c[k].col = a[i].col;
                    c[k].val = 2*a[i].val;
                    k++ , i++ , j++;
                }
                else if(a[i].val < b[j].val)
                {
                    c[k].row = a[i].row;
                    c[k].col = a[i].col;
                    c[k].val = a[i].val;
                    k++ , i++;
                }
                else
                {
                    c[k].row = b[j].row;
                    c[k].col = b[j].col;
                    c[k].val = b[j].val;
                    k++ , j++;
                }
            }
            else if(a[i].col < b[j].col)
            {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].val = a[i].val;
                k++ , i++;
            }
            else
            {
                c[k].row = b[j].row;
                c[k].col = b[j].col;
                c[k].val = b[j].val;
                k++ , j++;
            }
        }
        else if(a[i].row < b[j].row)
        {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val;
            k++ , i++;
        }
        else
        {
            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].val = b[j].val;
            k++ , j++;
        }
    }
    while(i < n1)
    {
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].val = a[i].val;
        k++ , i++;
    }
    while(j < n2)
    {
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].val = b[j].val;
        k++ , j++;
    }

    cout << "\nThe required array is \n" << endl ;
    cout << "R\t" << "C\t" << "Val\n\n" ;

    for(i = 0 ; i < k ;i++)
    {
        cout << c[i].row << "\t" << c[i].col << "\t" << c[i].val << "\n" ;
    }
}
