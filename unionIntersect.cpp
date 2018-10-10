#include <iostream>
#include <string>
using namespace std;
class student
{
	string name;
	char cricket;
	char badminton;
	int rno;
public:
	void accept();
	void display();
	bool onlyCricket();
	bool onlyBadminton();
	bool both();
	bool none();
	bool either();
};
/*
 * Accept function to accept the student data
 */
void student::accept()
{
	cout << "------------------------------" << endl;
	cout << "Name:" ;
	getline(cin >> ws, name);
	cout << "Roll no. : " ;
	cin >> rno;
	cout << "Cricket(y/n): ";
	cin >> cricket;
	cout << "Badminton(y/n): " ;
	cin >> badminton;
}
/*
 * Function to check the condition if the student plays only cricket using logical
 * AND '&&' to eliminate other options
 */
bool student::onlyCricket()
{
	if((cricket == 'y' || cricket == 'Y') && (badminton == 'n' || badminton == 'N') )
		return true;
	else
		return false;
}
/*
 * Function to check the condition if the student plays only badminton using logical
 * AND '&&' to eliminate other options
 */
bool student::onlyBadminton(){
	if((badminton == 'y' || badminton == 'Y') && (cricket == 'n' || cricket == 'N'))
		return true;
	else
		return false;
}
/*
 * Function to check the condition if the student plays both cricket and badminton
 * using logical AND '&&' to eliminate other options
 */
bool student::both()
{
	if((badminton == 'y' || badminton == 'Y') && (cricket == 'y' || cricket == 'Y'))
		return true;
	else
		return false;
}
/*
 * Function to check the condition if the student plays neither cricket nor badminton
 * using logical AND '&&' to eliminate other options
 */
bool student::none()
{
	if((badminton == 'n' || badminton == 'N') && (cricket == 'n' || cricket == 'N'))
		return true;
	else
		return false;
}
/*
 * Function to check the condition if the student plays either cricket or badminton
 * or both using logical OR '||' to eliminate other options
 */
bool student::either()
{
	if((cricket == 'y' || cricket == 'Y') || (badminton == 'y' || badminton == 'Y'))
		return true;
	else
		return false;
}
/*
 * Function to display the student data
 */
void student::display()
{
	cout << "------------------------------" << endl;
	cout << name << endl;
}
/*
 * Main function
 */
int main() {
	cout << "Enter Number of Students:" ;
	int n;
	cin >> n;
	student o[n];
	cout << "Enter Their data" << endl;
	for(int i = 0 ; i < n ; i++) //Loop to accept Student data
	{
		o[i].accept();
	}
	int ch;
	do			//Do while used to keep the program going until user wants to exit
	{
		cout << "------------------------------" << endl;
		cout << "Students who only play Cricket(1)" << endl;
		cout << "Students who only play Badminton(2)" << endl;
		cout << "Students who only play Both(3)" << endl;
		cout << "Students who only play None(4)" << endl;
		cout << "Students who only play Either(5)" << endl;
		cout << "EXIT(6)" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				cout << "------------------------------" << endl;
				cout << "Students who play only cricket are" << endl;
				int k = 0;
				for(int i = 0 ; i < n ; i++)
				{
					if(o[i].onlyCricket())		//Executes only if condition true
					{
						o[i].display();
					}
					else		//Increments counter for check
					{
						k++;
					}
					if(k == n)//Executes only If none of the students satisfy condition
					{
						cout << "------------------------------" << endl;
						cout << "No Member found" << endl;
					}
				}
				break;
			}
			case 2:
			{
				cout << "------------------------------" << endl;
				cout << "Students who play only badminton are" << endl;

				int k = 0;
				for(int i = 0 ; i < n ; i++)
				{
					if(o[i].onlyBadminton())//Executes only if condition is true
					{
						o[i].display();
					}
					else		//Increments counter for check
					{
						k++;
					}
					if(k == n)//Executes only If none of the students satisfy condition
					{
						cout << "------------------------------" << endl;
						cout << "No Member found" << endl;
					}
				}
				break;
			}
			case 3:
			{
				cout << "------------------------------" << endl;
				cout << "Students who play both cricket and badminton are" << endl;

				int k = 0;
				for(int i = 0 ; i < n ; i++)
				{
					if(o[i].both())//Executes only if condition is true
					{
						o[i].display();
					}
					else		//Increments counter for check
					{
						k++;
					}
					if(k == n)//Executes only If none of the students satisfy condition
					{
						cout << "------------------------------" << endl;
						cout << "No Member found" << endl;
					}
				}
				break;
			}
			case 4:
			{
				cout << "------------------------------" << endl;
				cout << "Students who don't play anything are" << endl;

				int k = 0;
				for(int i = 0 ; i < n ; i++)
				{
					if(o[i].none())//Executes only if condition is true
					{
						o[i].display();
					}
					else		//Increments counter for check
					{
						k++;
					}
				}
				if(k == n)//Executes only If none of the students satisfy condition
				{
					cout << "------------------------------" << endl;
					cout << "No Member found" << endl;
				}
				else		//Gives number of students
				{
					cout << "------------------------------" << endl;
					cout << "Number of students:";
					cout << n - k << endl;
				}
				break;
			}
			case 5:
			{
				cout << "------------------------------" << endl;
				cout << "Students who play either cricket or badminton or both are" << endl;

				int k = 0;
				for(int i = 0 ; i < n ; i++)
				{
					if(o[i].either())//Executes only if condition is true
					{
						o[i].display();
					}
					else		//Increments counter for check
					{
						k++;
					}
					if(k == n)//Executes only If none of the students satisfy condition
					{
						cout << "------------------------------" << endl;
						cout << "No Member found" << endl;
					}
				}
				break;
			}
		}
	}while(ch != 6);//^ is the exit status
	return 0;
}
