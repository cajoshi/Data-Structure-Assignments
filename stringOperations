#include <iostream>
#include <stdio.h>
using namespace std;

class sop
{
	public:
		void LengthOfString();
		void Copy();
		void ConCat();
		void Rev();
		void Compare();
		void Frequency();
		void AlphaNum();
};
void sop::LengthOfString()
{
	char a[20];
	cout << "Enter your string:" ;
	cin >> a;
	int count1 = 0;

//The Condition in this for loop checks occurrence of null as it occurs at the end of a char array

	for(int i = 0 ; a[i] != '\0' ; i++)
	{
		count1++;
	}
		cout << "\n**Length of the string is :" << count1 << endl;

}

void sop::Copy()
{
	int i ;
	char a[20];
	char b[20];
	cout << "Enter destination string:" ;
	cin >> a;
	cout << "Enter string to be copied:" ;
	cin >> b;

	cout << "\n**String at destination Before Copying is: " << a << endl;

	//This loop Copies individual elements in a new char array

	for(i = 0 ; b[i] != '\0' ; i++ )
	{
		a[i] = b[i];
	}

	//This condition is useful if length of copied string is less than the destination string


	if(a[i] != '\0')
	{
		a[i] = '\0';
		cout << "**The string at the destination after copying is: " << a;
	}
	else
	{
		cout << "**The string at the destination after copying is :" << a;
	}
}

void sop::ConCat()
{
	int i = 0;
	int count1 = 0;
	char a[20];
	char b[20];
	cout << "Enter string1:" ;
	cin >> a;
	cout << "Enter string2:" ;
	cin >> b;

//Gets length of string

	for(int i = 0 ; a[i] !='\0' ; i++ )
	{
		count1++;
	}

	//Copies the elements string2 after end of string1

	for( ; b[i] !='\0' ; i++)
	{
		a[count1+i] = b[i];
	}
	a[count1+i] ='\0';
	cout << "\n**The concatenated string is: " << a;
}

void sop::Rev()
{
	int count1 = 0;
	char a[20];
	char b[20];
	cout << "Enter the string: ";
	cin >> a;

//Finds length of string

	for(int i = 0 ; a[i] != '\0' ; i++)
	{
		count1++;
	}
	int i ;

	//Copies the elements of original string in a new string , in reverse order

	for(i = 0 ; i < count1; i++)
	{
		b[i] = a[count1 - i - 1];
	}b[i] = '\0';
	cout << "\n**The string is: " << b;
}

void sop::Compare()
{
	char a[20];
	char b[20];
	cout << "Enter String 1:" ;
	cin >> a;
	cout << "Enter string 2:" ;
	cin >> b;
	int i = 0;
	int count1 = 0;
	do
	{

	//Checks the ASCII values of individual elements and changes counter accordingly

		if(a[i] > b[i])
		{
			count1++;
		}
		else
		{
			count1--;
		}
			i++;
		}while(a[i] != '\0' || b[i] != '\0');
	cout << "\n**" << count1 << endl;
}

void sop::Frequency()
{
	char a[20];
	cout << "Enter String:" ;
	cin >> a;
	int len = 0;

	//Gets length of the string

	for(int i = 0 ; a[i] != '\0' ; i++)
	{
		len++;
	}
	int count1[len][2]; //Will be used to store the freq count and character associated with it

	//Initialization of all elements of counter to 0

	for(int i = 0 ; i < len ; i++)
	{
		count1[i][0] = 0;
	}
	int k = 0;

	//Loop to traverse the whole string

	for(int j = 0 ; j != len ; j++)
	{
	//Condition to check for the null character put in to delete a specific element
		if(a[j] !='\0')
		{
			int temp = a[j];
			for(int i = 0 ; i < len ; i++)
			{
				if(temp == a[i])
				{
					(count1[k][0])++;
					count1[k][1] = a[i];
					a[i] = '\0'; //Put to delete the element to exclude it from being counted again

				}

			}
			k++;
		}
	}
	cout << "\n" ;
	for(int i = 0 ; i < k ; i++)
	{
		cout << (char)count1[i][1] << "-" << count1[i][0] << endl ;
	}

}

void sop::AlphaNum()
{
	char a[20];
	cout << "Enter String:" ;
	cin >> a;
	int temp;
	int len = 0;
	for(int i = 0 ; a[i] != '\0' ; i++)
	{
		len++;
	}
	int i;
	for(i = 0 ; i < len ; i++ )
	{
		temp = a[i];
		if((temp > 122) || (temp < 97 && temp > 90) || (temp < 65)) //This check if the element is an alphabet or not by checking the ASCII value
		{
			a[i] = '\0'; //Simulates deletion of the element
		}
	}
	cout << "\n**The Final string is:";
	for(int j = 0 ; j < i ; j++)
	{
		if(a[j] != '\0') //Prevents from printing blank spaces
		{
			cout << a[j];
		}
	}cout << endl;
}


int main() {

sop obj;
int choice;
do
{
	cout << endl << endl << "Find the length of a string(1):" << endl;
	cout << "Copy one string in other(2):" << endl;
	cout << "Concatenate two strings(3):" << endl;
	cout << "Reverse a string(4):" << endl;
	cout << "Compare two strings(5):" << endl;
	cout << "Find the frequency count of a string(6):" << endl;
	cout << "Delete the alphanumeric characters of a string of a string(7):" << endl;
	cout << "EXIT(8)" << endl;
	cout << "Enter your choice: " ;
	cin >> choice;


	switch(choice)
		{
			case 1:
			{
				obj.LengthOfString();
				break;
			}
			case 2:
			{
				obj.Copy();
				break;
			}
			case 3:
			{
				obj.ConCat();
				break;
			}
			case 4:
			{
				obj.Rev();
				break;
			}
			case 5:
			{
				obj.Compare();
				break;
			}
			case 6:
			{
				obj.Frequency();
				break;
			}
			case 7:
			{
				obj.AlphaNum();
				break;
			}

		}
}while( choice != 8);

return 0;
}
