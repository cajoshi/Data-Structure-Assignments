

#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;

class arr
{
	int _row,_col,_id;
	public:
		int len;
		int a[50][50];		//Stores original matrix
		int b[100][3];		//Stores sparse matrix
		int c[100][3];		//Stores the result of fast transpose of the matrix
		void setval();
		int getrow();
		int getcol();
		int getname(int);
		void accept();
		void original();
		void threecol();
		void simpletrans();
		void fasttrans();
		void addition(arr,arr);
};
int arr::getname(int a)				//Sets the Id of the matrix
{
	_id = a;
	return _id;
}
void arr::setval()
{
	cout << "Enter the number of rows:";
	cin >> _row;

	cout << "Enter the number of cols:";
	cin >> _col;
}
int arr::getrow()
{
	return _row;
}

int arr::getcol()
{
	return _col;
}

void arr::accept()
{

	int row = getrow();
	int col = getcol();
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]:" ;
			cin >> a[i][j];
		}
	}
}
void arr::original()			//Prints original matrix
{
	int row = getrow();
	int col = getcol();
	cout << endl << "Original Matrix" << endl;
	for(int i = 0 ; i < row ; i++)
	{
		for (int j = 0 ; j < col ; j++)
		{
			cout << a[i][j] << "\t";
		}cout << endl;
}
}
void arr::threecol()		//Function for three column Representation
{

int row = getrow();
int col = getcol();

int m = 0;
for(int i = 0 ; i < row ; i++ )
{
	for(int j = 0 ; j < col ; j++)
	{
		if(a[i][j] != 0)
		{
			b[m][0] = i;
			b[m][1] = j;
			b[m][2] = a[i][j];
			m++;
		}
	}
}
len = m;
cout << endl << "Sparse Matrix" << endl;			//Prints The sparse matrix
cout << "\n R " << " C " << " V " << endl;
cout << "----------------" << endl;
for(int i = 0 ; i < m ; i++)
{
	for (int j = 0 ; j < 3 ; j++)
	{
		cout << " " << b[i][j] << " ";
	}cout << endl;
}cout << endl <<endl;
}

void arr::simpletrans()			//Gives output as simple transpose
{
int ncol = getrow();
int nrow = getcol();

int b[nrow][ncol]; //Declared as a local array because we don't want to change the original b[][] array and this array is of no use for now
for(int i = 0 ; i < nrow ; i++)
{
	for (int j = 0 ; j < ncol ; j++)
	{
		b[i][j] = a[j][i];
	}
}
cout << "Simple Transpose" << endl;
for(int i = 0 ; i < nrow ; i++)
{
	for (int j = 0 ; j < ncol ; j++)
	{
		cout << b[i][j] << "\t";
	}cout << endl;
}

}
void arr::fasttrans()			//Gives output as fast transpose of the matrix
{
int col = getcol();
int row = getrow();
int terms[col] ;
for(int i = 0 ; i < col ; i++)			//Initialization of terms array to 0
{
	terms[i] = 0;
}
int rpos[col] ;
rpos[0] = 1;
for(int i = 1 ; i < col ; i++ )			//Initialization of rpos array to 0
{
	rpos[i] = 0 ;
}

for(int j = 0 ; j < col ; j++ ) //Fills the terms array by checking the condition
{
	for(int i = 0 ; i < row ; i++)
	{
		if(a[i][j] != 0)
		{
			(terms[j])++;
		}
	}
}

for(int i = 1 ; i < col ; i++) //Fills the rpos array
{
	rpos[i] = rpos[i-1] + terms[i-1];
}

for(int i = 0 ; i < len ; i++)
{
	for(int j = 0 ; j < col ; j++)
	{
		if(b[i][1] == j)
		{
			c[rpos[j]][0] = b[i][1];
			c[rpos[j]][1] = b[i][0];
			c[rpos[j]][2] = b[i][2];
			(rpos[j])++;

		}
	}
}

cout << endl << "Fast transpose:" << endl;
cout << "\n R " << " C " << " V " << endl;
cout << "----------------" << endl;
for(int i = 1 ; i < len + 1 ; i++)
{
	for (int j = 0 ; j < 3 ; j++)
	{
		cout << " " << c[i][j] << " ";
	}cout << endl;
}cout << endl <<endl;

}

void arr::addition(arr a, arr b)			//Adds two matrices
{
int c[50][50];
	if((a.getrow() != b.getrow()) || (a.getcol() != b.getcol()))
	{
		cout << "The matrices cannot be added:" << endl;
	}
	else
	{
		for(int i = 0 ; i < a.getrow() ; i++)
		{
			for(int j = 0 ; j < a.getcol() ; j++)
			{
				c[i][j] = a.a[i][j] + b.a[i][j] ;
			}
		}
		cout << "The sum is:" << endl;
		for(int i = 0 ; i < a.getrow() ; i++)
		{
			for (int j = 0 ; j < a.getcol() ; j++)
			{
				cout << c[i][j] << "\t";
			}cout << endl;
		}
	}
}
int main()
{
	int c , i = -1 ;
	arr o[10],a;


	do

	{
		cout << "New Matrix(1):" << endl;
		cout << "Convert to 3 Column representation(2):" << endl;
		cout << "Simple Transpose(3):" << endl;
		cout << "Fast Transpose(4):" << endl;
		cout << "Add two matrices(5):" << endl;
		cout << "EXIT(6):" << endl;
		cout << "Enter your choice: ";
		cin >> c;



		switch (c)
		{
		case 1:
			{
				i++;
				cout << "The ID of your matrix is : " << i << endl;
				o[i].getname(i);
				o[i].setval();
				o[i].accept();

				break;
			}
		case 2:
			{
				int r = 0;
				cout << "Enter the ID of your matrix: " ;
				cin >> r;
				if(r > i)
				{
					cout << endl << "No matrix found on the Id" << endl << endl;
				}
				else {
					o[r].threecol();
				}
				break;
			}
		case 3:
			{
				int r = 0 ;
				cout << "Enter the ID of your matrix: " ;
				cin >> r;
				if(r > i )
				{
					cout << endl << "No matrix found on the Id" << endl << endl;
				}
				else {
					o[r].simpletrans();
				}
				break;
			}
		case 4:
			{
				int r = 0 ;
				cout << "Enter the ID of your matrix: ";
				cin >> r;
				if(r > i)
				{
					cout << endl << "No matrix found on the Id" << endl << endl;
				}
				else {
				o[r].fasttrans();
				}
				break;
			}
		case 5:
			{
				int r = 0 ,s = 0;
				cout << "Enter the ID of 1st matrix: ";
				cin >> r;
				cout << "Enter the ID of 2nd matrix: ";
				cin >> s;

				if(r > i || s > i)
				{
					cout << endl << "No Data for one or both of the Id(s)" << endl << endl;
				}
				else{
					a.addition(o[r],o[s]);
				}
				break;

			}
		case 6:
			{
				c = 6;
				break;
			}
		}
	}while(c != 6 );



return 0;
}

