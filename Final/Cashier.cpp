#include <iostream>
#include <fstream>
#include "Cashier.h"

Cashier::Cashier()
{}

Cashier::~Cashier()
{}

void Cashier::purchase(int amount, double tax)
{
	double totalPrice;
	double price = getRetail() * amount;
	double taxAmount = price * tax;
	cout <<"Tax  =" << taxAmount << endl; 
	remove(amount);
	totalPrice = (amount * getRetail()) + taxAmount;
	cout << "Total =" << totalPrice << endl;
}

// Overload operator << and >>
ostream &operator << (ostream &strm, const Cashier &obj)
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

istream &operator >> (istream &strm, Cashier &obj)
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
void Cashier::inventory(vector<Cashier> books)
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
bool Cashier::OpenFile(fstream &file, string name)
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
bool Cashier::editFile(fstream &file, string name)
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
void Cashier::ReadContents(fstream &file, vector<Cashier> books)
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
void Cashier::addBook(vector<Cashier> books)
{
	Cashier newBook;
	cin >> newBook;
	books.push_back(newBook);
	count++;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													sort functions
//	 
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Cashier::sortIsbn(vector<Cashier> Array, int arraySize) // Call a different sort function for each member we want the array sorted by
{

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getISBN();
	}
	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortTitle(vector<Cashier> Array, int arraySize) // Example for sort by title
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getTitle() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortAuthor(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getAuthor() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortPublisher(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getPublisher() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortDate(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getDate() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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



void Cashier::sortUnits(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getBookunits() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortWholesale(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getWholesale() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

void Cashier::sortRetail(vector<Cashier> Array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getRetail() << endl;
	}

	int startScan, minIndex;
	Cashier minValue;

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

int Cashier::searchIsbn(vector<Cashier> Array, int numElems, string value)
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

int Cashier::searchTitle(vector<Cashier> Array, int numElems, string value)
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

int Cashier::searchAuthor(vector<Cashier> Array, int numElems, string value)
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

int Cashier::searchPublisher(vector<Cashier> Array, int numElems, string value)
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

int Cashier::searchDate(vector<Cashier> Array, int numElems, string value)
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




int Cashier::searchUnits(vector<Cashier> Array, int numElems, int value)
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

int Cashier::searchWholesale(vector<Cashier> Array, int numElems, double value)
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

int Cashier::searchRetail(vector<Cashier> Array, int numElems, double value)
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
