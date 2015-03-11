




#include <iostream>
#include <string>
#include <cstring>
#include <fstream>									//	This is for I/O file
#include <iomanip>									//	This is for alignment
#include <vector>
#include <stdlib.h>
#include "Cashier.h"
#include "Book.h"

using namespace std;

//============================================================================================================================
//	Declare all function prototypes here
//============================================================================================================================

void showMenu(vector<Cashier> inv, const double tax);
int searchMenu(vector<Cashier> inventory);
void changeMenu(int book, vector<Cashier> inventory);
void printMenu(vector<Cashier> inventory);

const double TAX = .0785;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//											Main function
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
	vector<Cashier> inventory;

	inventory[0].inventory(inventory);

	showMenu(inventory, TAX);

	system("CLS");

	system("PAUSE");

	return 0;
}



void showMenu(vector<Cashier> inv, const double tax)
{

	system("CLS"); // clearing the console!

	string option;
	int choice;
	int book, amount;

	cout << endl << "                    Dank Book Store               " << endl << endl;

	cout << "                    Main Menu:                    " << endl;

	cout << endl << "     1. Cashier Module" << endl;
	cout << "     2. Inventory Database Module" << endl;
	cout << "     3. Report Module" << endl;
	cout << "     4. Exit" << endl;


	cout << endl << "     Enter your choice: ";

	cin >> choice;

	while (choice > 0 && choice < 5)
	{
		cout << "     Invalid choice." << endl;
		cout << endl << "     Enter your choice: ";
		cin >> choice;
	}

	switch (choice)
	{
		case 1:
			book = searchMenu(inv);
			cout <<  "In Stock: " << inv[book].getBookunits() << endl;
			cout << "Cost: " << inv[book].getRetail() << endl; 
			cin >> amount;

			while(!isdigit(amount))
			{
				cout <<  "How Many would you like to purchase?" << endl;
				cin >> amount;
				if(!isdigit(amount))
				{
					cout << "amount needs to be a whole number" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}
			}
			inv[book].purchase(amount, tax);
			break;
		case 2:
			do
			{
				cout << " (1) Look Up, (2) Add new Books, (3) Delete Books, (4) Change Book Info, (5) Finished" << endl;
				cout << "     Enter your choice: ";
				cin >> choice;
				cin.ignore();
				book = -1;
				switch(choice)
				{
					case 1:
						book = searchMenu(inv);
						cout << inv[book];
					case 2:
						inv[0].addBook(inv);
						cout << "Enter ISBN, Title, Author, Publisher, Current Date, Amount on Hand, WholeSale cost, and Retail cost" << endl;
						cout<< "All separated by Enter" << endl;
						cin >> inv[inv[0].getCount() - 1];
					case 3:
						book = searchMenu(inv);
						// delete function
					case 4:
						book = searchMenu(inv);
						changeMenu(book, inv);
					case 5:
						cout << "returning Main Menu" << endl;
					default:
						cout << choice << " is not an option" << endl;

				}
			}while(choice != 5);
			break;
		case 3:
			printMenu(inv);
			break;
		default:
			cout << choice << " is not an option" << endl;
	}
}

int searchMenu(vector<Cashier> inventory)
{
	int choice;
	string option;
	int book;
	do
	{
		cout << " Search by, (1) ISBN, (2) Title, (3) Author, (4) EntryDate, (5) Finish" << endl;
		cout << "     Enter your choice: ";
		cin >> choice;
		cin.ignore();
		book = -1;
		switch(choice)
		{
			case 1:
				while(book == -1)
				{
					cout << "Enter ISBN: ";
					getline(cin, option);
					book = inventory[0].searchIsbn(inventory, inventory[0].getCount(), option);
					if(book == -1)
					{
						cout << "Book was not found" << endl;
					}
				}
				break;
			case 2:
				while(book == -1)
				{
					cout << "Enter Title: ";
					getline(cin, option);
					book = inventory[0].searchTitle(inventory, inventory[0].getCount(), option);
					if(book == -1)
					{
						cout << "Book was not found" << endl;
					}
				}
				break;
			case 3:
				while(book == -1)
				{
					cout << "Enter Author: ";
					getline(cin, option);
					book = inventory[0].searchAuthor(inventory, inventory[0].getCount(), option);
					if(book == -1)
					{
						cout << "Book was not found" << endl;
					}
				}
				break;
			case 4:
				while(book == -1)
				{
					cout << "Enter EntryDate: ";
					getline(cin, option);
					book = inventory[0].searchDate(inventory, inventory[0].getCount(), option);
					if(book == -1)
					{
						cout << "Book was not found" << endl;
					}
				}
				break;
			default:
				cout << "That was not an option";
		}

	}while(choice < 1 && choice > 5);

	return book;
}

void changeMenu(int book, vector<Cashier> inventory)
{
	int choice;
	string option;
	do
	{
		cout << " Change, (1) ISBN, (2) Title, (3) Author, (4) EntryDate, (5) Finish" << endl;
		cout << "     Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch(choice)
		{
			case 1:
				cout << "Enter new ISBN: ";
				getline(cin, option);
				inventory[book].setIsbn(option);
				break;
			case 2:
				cout << "Enter new Title: ";
				getline(cin, option);
				inventory[book].setTitle(option);
				break;
			case 3:
				cout << "Enter new Author: ";
				getline(cin, option);
				inventory[book].setAuthor(option);
				break;
			case 4:
				cout << "Enter new EntryDate: ";
				getline(cin, option);
				inventory[book].setDate(option);
				break;
			default:
				cout << "That was not an option";
		}

	}while(choice < 1 && choice > 5);
}

void printMenu(vector<Cashier> inventory)
{
	int choice;
	string option;
	do
	{
		cout << " Sort by, (1) ISBN, (2) Title, (3) Author, (4) EntryDate, (5) Return to Main Menu" << endl;
		cout << "     Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				inventory[0].sortIsbn(inventory, inventory[0].getCount());
				for(int i = 0; i < inventory[0].getCount(); i++)
				{
					cout << inventory[i];
				}
				break;
			case 2:
				inventory[0].sortTitle(inventory, inventory[0].getCount());
				for(int i = 0; i < inventory[0].getCount(); i++)
				{
					cout << inventory[i];
				}
				break;
			case 3:
				inventory[0].sortAuthor(inventory, inventory[0].getCount());
				for(int i = 0; i < inventory[0].getCount(); i++)
				{
					cout << inventory[i];
				}
				break;
			case 4:
				inventory[0].sortDate(inventory, inventory[0].getCount());
				for(int i = 0; i < inventory[0].getCount(); i++)
				{
					cout << inventory[i];
				}
				break;
			default:
				cout << "That was not an option";
		}

	}while(choice != 5);
}