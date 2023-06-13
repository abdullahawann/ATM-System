#include<iostream>
using namespace std;

int Menu()
{
	char option;

	cout << "Please select an option from the menu below" << endl;
	cout << "c -> Create account" << endl;
	cout << "l -> Login Using ID" << endl;
	cout << "q -> Quit The Program" << endl;
	cout << "Enter the option here : ";
	cin >> option;

	while (option != 'c' && option != 'l' && option != 'q')
	{
		cout << "Error! Select a valid option from menu again : ";
		cin >> option;
	}

	return option;
}

int create()
{
	int ID;
	bool flag = true;
	cout << endl << "Please enter a username from 1 - 10: ";
	cin >> ID;

	while (flag == true)
	{
		if (ID >= 1 && ID <= 10)
		{
			cout << "Thank you! Your account has been created" << endl << endl;
			flag = false;
		}
		else
		{
			cout << "Invalid Input" << endl;
			cout << "Please enter the username Again: ";
			cin >> ID;
		}
	}
	return ID;
}

int Deposit()
{
	int dep_amount;
	cout << endl << "Enter the amount you want to deposit : ";
	cin >> dep_amount;
	cout << "Amount credited successfully" << endl << endl;

	return dep_amount;
}

int withdraw(int acc[], int id)
{
	int amount;
	int x = 0;
	bool flag = false;
	int note[7] = {5000, 1000, 500, 100, 50, 20, 10};
	int note_freq[7];

	cout << endl << "Enter the amount you want to withdraw : ";
	cin >> amount;
	cout << endl;

	while (amount%10 != 0)
	{
		cout << "Please enter the valid amount again : ";
		cin >> amount;
	}

	if (amount%10 == 0)
	{
		for (int i=0; i<10; i++)
		{  
			if (i == id)
			{
				if (amount <= acc[i])
				{
					x = amount;
					flag = true;
		            cout << "Cash withdrawal for Rs." << amount << " requested" << endl;
		
	                for (int i=0; i<7; i++) 
		            {
                        if (amount >= note[i]) 
			            {
                            note_freq[i] = amount / note[i];
                            amount = amount - note_freq[i] * note[i];
                        }
                    }

                    for (int i=0; i<7; i++) 
		            {
                        if (note_freq[i] > 0)
			            {
                            cout << "Denomination " << note[i] << "s - " << note_freq[i] << endl;
                        }
                    }
				}
				else 
				{
					cout << "You have insufficient balance in your account for this trancsection" << endl;
				}
			}
		}
	}
	cout << endl;

	return x;
}

void request_balance(int amount[], int ID)
{
	for (int i=0; i<10; i++)
	{
		if (i == ID)
		{
			cout << endl << "Your balance is Rs." << amount[i] << endl << endl;
		}
	}
}

int login(int ids[])
{
	int ID;
	int x=0;
	int dep_amount[10] = {0};
	char option;
	bool flag = false;
	bool flag2 = false;

	cout << endl << "Enter your user ID to login : ";
	cin >> ID;
	cout << endl;

    while (flag2 == false)
    {
	    for(int i=0; i<10; i++)
	    {
		    if (ids[i] == ID)
		    {
			cout << "Access granted!" << endl << endl;
			cout << "d -> Deposit Money" << endl;
			cout << "w -> Withdraw Money" << endl;
			cout << "r -> Request Balance" << endl;
			cout << "m -> Go back to Main Screen" << endl;
			cout << "Enter your choice here : ";
			cin >> option;

			if (option == 'd')
			{
				dep_amount[ID] = Deposit();
			}

			if (option == 'w')
		    {
				x = withdraw(dep_amount, ID);
		    }

			if (option == 'r')
		    {
				dep_amount[ID] = dep_amount[ID] - x;
				request_balance(dep_amount, ID);
		    }

			if (option == 'm')
		    {
				Menu();
				flag2 = true;
				break;
		    }

			flag = true;
		    }
	    }

		if(flag == false)
		{
			flag2 = true;
			break;
		}
    }

	if (flag == false)
	{
		cout << "No account found against your user ID" << endl;
		Menu();
	}

	return ID;
}

int main()
{
	cout << "\t\t\t\t\t Hi! Welcome to Ms.Farzeen's ATM Machine" << endl << endl;
	bool flag = false;
	int i = 0;

	while (flag == false)
	{
	    char keypressed;
		char option;
	    option = Menu();
	    int IDs[10];
		int dep_amount[10];

	    if (option == 'c')
	    {
		    IDs[i] = create();
			dep_amount[i] = 0;
		    i++;
	    }

		else if (option == 'l')
		{
			login(IDs);
		}

	    else if (option == 'q')
	    {
		    cout << "Thanks for stopping the process! BYE" << endl;

			cout << "Do you want to open main menu again (y/n) : ";
		    cin >> keypressed;
			cout << endl;

		    if (keypressed == 'y')
		    {
			    flag = false;
		    }

		    else
		    {
			   flag = true;
			   break;
		    }
	    }
	}

	system("pause");
	return 0;
}
