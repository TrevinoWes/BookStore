//============================================================================================================================
//	Class:			CIS 22B 
//	Instructor:		Manish Goel
//	Class hours:	TTh- 3:30 pm - 5:20 pm
//	Room:			AT204
//					Team Project
//	Description:	Implement InventoryBook.cpp
//
//	Written by:		Ryan T. Hong
//	Date:			Feb. 24th, 2015
//============================================================================================================================
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>									//	This is for I/O file
#include <iomanip>									//	This is for alignment
#include <vector>
#include "Book.h"

using namespace std;

//	mutator member function
void Book::setIsbn(string sID)
{
	sIsbn = sID;
}
void Book::setTitle(string sName)
{
	sTitle = sName;
}
void Book::setAuthor(string sWriter)
{
	sAuthor = sWriter;
}
void Book::setDate(string sDate)
{
	sEntryDate = sDate;
}
void Book::setPublisher(string sPub)
{
	sPublisher = sPub;
}
void Book::setBookunits(int units)
{
	iUnits = units;
}
void Book::setWholesale(double dWholeSale)
{
	dWholesale = dWholeSale;
}
void Book::setRetail(double dRetail)
{
	dRetail = dRetail;
}

Book::Book()
	{
		sIsbn = "";
		sTitle = "";
		sAuthor = "";
		sEntryDate = "";
		sPublisher = "";
		iUnits = 0;
		dWholesale = 0.0;
		dRetail	= 0.0;
		count++;
	}

//	Overload member function
Book::Book(string isbn, string name, string writer, string pub, string date, int units, double wholeSale, double retail)
{
	sIsbn = isbn;
	sTitle = name;
	sAuthor = writer;
	sEntryDate = date;
	sPublisher = pub;
	iUnits = units;
	dWholesale = wholeSale;
	dRetail = retail;
	count++;
}

//	Accessor member functions
string Book::getISBN() const
{
	return sIsbn;
}

string Book::getTitle() const
{
	return sTitle;
}

string Book::getAuthor() const
{
	return sAuthor;
}

string Book::getDate() const
{
	return sEntryDate;
}

string Book::getPublisher() const
{
	return sPublisher;
}

int Book::getBookunits() const
{
	return iUnits;
}
double Book::getWholesale() const
{
	return dWholesale;
}

double Book::getRetail() const
{
	return dRetail;
}

int Book::getCount() const
{
	return count;
}

// Overload operator << and >>
ostream &operator << (ostream &strm, const Book &obj)
{
	strm	<< "ISBN: " << obj.sIsbn << endl
			<< "Title: " << obj.sTitle << endl
			<< "Author: " << obj.sAuthor << endl
			<< "Publisher: " << obj.sPublisher << endl
			<< "Date entry: " << obj.sEntryDate << endl
			<< "Quantity: " << obj.iUnits << endl
			<< "Whole sale cost: $" << obj.dWholesale << endl
			<< "Retail price: $" << obj.dRetail << endl;
	return strm;
}

istream &operator >> (istream &strm, Book &obj)
{
	getline(strm, obj.sIsbn, '\n');
	getline(strm, obj.sTitle, '\n');
	getline(strm, obj.sAuthor, '\n');
	getline(strm, obj.sPublisher, '\n');
	getline(strm, obj.sEntryDate, '\n');
	strm >> obj.iUnits;
	strm >> obj.dWholesale;
	strm >> obj.dRetail;

	return strm;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													inventory function
//	This program doesn't have any argument. The purpos of this file is opened for reading data.  
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Book::inventory(vector<Book> books)
{
	string	sSuccess_rd_file = "Reading from the file.",
			sPath_request = "To specify your file at specific path, please enter similar to the format below.",
			sExample_path = "\"c:\\\\data\\\\studentScore.txt\"",
			sEnter_path = "Please enter your path here: ",
			sError_rd_file = "ERROR: Cannot open the file.",
			sFinish_reading = "Reading is done.",
			sPath_name;
	bool	ReadOK;
	fstream dataFile;

	cout << endl << sPath_request << endl << "\t\t" << sExample_path << endl << endl << sEnter_path;
	getline(cin, sPath_name);

	ReadOK = OpenFile(dataFile, sPath_name);
	if (ReadOK)
	{
		cout << sSuccess_rd_file << endl << endl;
		ReadContents(dataFile, books);
		dataFile.close();
		cout << endl << sFinish_reading << endl;
	}
	else
	{
		cout << sError_rd_file << endl;
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													OpenFile function
//	This program accepts a reference to an fstream object as an argument. The file is opened for input.  The functions true
//	upon success, false upon failure.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool Book::OpenFile(fstream &file, string name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													editFile function
//	This program accepts a reference to an fstream object as an argument. The file is opened for input.  The functions true
//	upon success, false upon failure.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool Book::editFile(fstream &file, string name)
{
	file.open(name, ios::out | ios::app);
	if (file.fail())
		return false;
	else
		return true;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														ReadContents function
//	This program accepts an fstream reference and string array as its argument.  Use a loop to read each name from the file.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Book::ReadContents(fstream &file, vector<Book> books)
{
	if (file)
	{
		// used to represent the amount of books in the file list
		int bookCount;
		// read first number on list determining how many books are in the list.
		file >> bookCount;
		// resize the vector to hold the amount of books listed
		books.resize(bookCount);
		// read in each member info
		for(int i = 0; i < bookCount; i++)
		{
			string info;

			file >> books[i];

			/*getline(file, info, '\n');
			books[i].setIsbn(info);
			getline(file, info, '\n');
			books[i].setTitle(info);
			getline(file, info, '\n');
			books[i].setAuthor;
			getline(file, info, '\n');
			books[i].setDate(info);
			getline(file, info, '\n');
			books[i].setPublisher(info);
			file >> units;
			books[i].setBookunits(units);
			file >> price;
			books[i].setWholesale(price);
			file >> price;
			books[i].setRetail(price);*/
		}
	}
	else
		cout << "ERROR: Cannot open file.\n";
	//	Close the file
	file.close();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													addBook function
//	This program doesn't have any argument. The purpos of this file is opened for adding data.  
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Book::addBook(vector<Book> books)
{
	Book newBook;
	cin >> newBook;
	books.push_back(newBook);
	count++;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													sort functions
//	 
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Book::sortIsbn(vector<Book> Array, int arraySize) // Call a different sort function for each member we want the array sorted by
{

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getISBN();
	}
	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getISBN() < minValue.getISBN()) // change .getISBN to the getter of the member we want to sort by
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getISBN();
	}

}

void Book::sortTitle(vector<Book> Array, int arraySize) // Example for sort by title
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getTitle() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getTitle() < minValue.getTitle()) // changed to .getTitle()
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getTitle() << endl;
	}

}

void Book::sortAuthor(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getAuthor() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getAuthor() < minValue.getAuthor())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getAuthor() << endl;
	}

}

void Book::sortPublisher(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getPublisher() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getPublisher() < minValue.getPublisher())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getPublisher() << endl;
	}

}

void Book::sortDate(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getDate() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getDate() < minValue.getDate())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getDate() << endl;
	}

}



void Book::sortUnits(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getBookunits() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getBookunits() < minValue.getBookunits())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getBookunits() << endl;
	}

}

void Book::sortWholesale(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getWholesale() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getWholesale() < minValue.getWholesale())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getWholesale() << endl;
	}

}

void Book::sortRetail(vector<Book> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getRetail() << endl;
	}

	int startScan, minIndex;
	Book minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getRetail() < minValue.getRetail())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getRetail() << endl;
	}

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													search functions
//	 
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int Book::searchIsbn(vector<Book> Array, int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortIsbn(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getISBN() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getISBN() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchTitle(vector<Book> Array, int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortTitle(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getTitle() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getTitle() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchAuthor(vector<Book> Array, int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortAuthor(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getAuthor() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getAuthor() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchPublisher(vector<Book> Array, int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortPublisher(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getPublisher() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getPublisher() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchDate(vector<Book> Array, int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortDate(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getDate() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getDate() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}




int Book::searchUnits(vector<Book> Array, int numElems, int value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortUnits(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getBookunits() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getBookunits() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchWholesale(vector<Book> Array, int numElems, double value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortDate(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getWholesale() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getWholesale() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Book::searchRetail(vector<Book> Array, int numElems, double value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortDate(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getRetail() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getRetail() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													remove function
//	 
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Book::remove(int amount)
{
	if(amount <= iUnits)
		iUnits -= amount;
	else
		iUnits = 0;
}

int Book::count = 0;

//	No need to use displayBooks member funtion because I do oveloaded operator << and >>
/*
void Books::displayBooks() const
{
	cout << "ISBN: " << getISBN() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Publisher: " << getPublisher() << endl;
	cout << "Date Entry: " << getDate() << endl;
	cout << "Quantity: " << getBookunits() << endl;
	cout << "Whole sale cost: $" << getWholesale() << endl;
	cout << "Retail price: $" << getRetail() << endl << endl;
}
*/