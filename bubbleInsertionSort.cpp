//Write a program to store 1st year percentage of students in array .
//write a function for sorting the array of floating point numbers in ascending order
//Use selection sort bubble sort and insertion sort to display top 5 scores
#include <iostream>
#include <string>
#define MAX_SIZE 20
using namespace std;
class ssort
{
	int n;
	double a[MAX_SIZE];
public:
	void accept();
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void display();
};

void ssort::accept()
{
	cout << "---------------------" << endl;
	cout << "Enter Number of students" << endl;
	cin >> n;
	cout << "Enter their percentage" << endl;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
}

void ssort::bubbleSort()
{
	accept();
	for(int i = 0 ; i < n - 1 ; i++)
	{
		for(int j = 0 ; j < n -1 ; j++)
		{
			if(a[j] > a[j+1])
			{
				double temp1 ;
				temp1 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp1;
			}
		}
	}
	display();
}

void ssort::selectionSort()
{
	accept();
	int temp1;
	for(int i = 0 ; i < n ; i++)
	{
		double temp2 = a[i];
		for(int j = i ; j < n ; j++)
		{
			if(a[j] < temp2)
			{
				temp1 = j;
				temp2 = a[j];
			}
		}
		temp2 = a[i];
		a[i] = a[temp1];
		a[temp1] = temp2;
	}
	display();
}

void ssort::insertionSort()
{
	accept();
	for(int i = 1 ; i < n ; i++)
	{
		int hole = i;
		double value = a[i];
		while(hole > 0 && a[hole - 1] > value)
		{
			a[hole] = a[hole - 1];
			hole -= 1;
		}
		a[hole] = value;
	}
	display();
}
void ssort::display()
{
	cout << "-------------------------" << endl;
	cout << "The top 5 scores are" << endl;
	for(int i = n-1 ; i > n - 6 ; i--)
	{
		cout << a[i] << endl;
	}

}

char menu(ssort &o)
{
	char ch;
	do
	{
		cout << "------------------------" << endl;
		cout << "1.Bubble Sort" << endl;
		cout << "2.Selection Sort" << endl;
		cout << "3.Insertion Sort" << endl;
		cout << "4.EXIT" << endl;
		cin >> ch;
		switch(ch){
		case '1':
		{
			o.bubbleSort();
			break;
		}
		case '2':
				{
					o.selectionSort();
					break;
				}
		case '3':
				{
					o.insertionSort();
					break;
				}
		}
	}while(ch != '4');
	return '4';
}

int main()
{
	ssort o;
	char ch;
	do{
		ch = menu(o);
	}while(ch != '4');
}
