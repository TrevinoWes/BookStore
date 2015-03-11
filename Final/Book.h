//============================================================================================================================
//	Class:			CIS 22B 
//	Instructor:		Manish Goel
//	Class hours:	TTh- 3:30 pm - 5:20 pm
//	Room:			AT204
//					Team Project
//	Description:	Class InventoryBook.h
//
//	Written by:		Ryan T. Hong
//	Date:			Feb. 24th, 2015
//============================================================================================================================
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Book
{
protected:

	string	sIsbn,		//	unique id for books in inventory
			sTitle,			//	Title of book
			sAuthor,		//	Author of book
			sEntryDate,	//	The date the book was added to the inventory
			sPublisher;		//	The company that publishes the book
	int		iUnits;	//	Number of books on hand
	double	dWholesale,	//	Quote buy from Serendipity bookstore
			dRetail;	//	Quote sale to customer
	static int count; // number of instances

public:
	//	Default constructor
	Book();

	//	Overloaded constructor
	Book(string isbn, string name, string writer, string pub, string date, int units, double wholeSale, double retail);

	virtual ~Book()
	{
		cout << " Book Destructor running" << endl;
	}

	//	Mutator function
	void setIsbn(string);
	void setTitle(string);
	void setAuthor(string);
	void setDate(string);
	void setPublisher(string);
	void setBookunits(int);
	void setWholesale(double);
	void setRetail(double);

	//	Overloaded member function
	void setAll(string, string, string, string, string, int, int, double, double);

	//	Accessor functions
	string getISBN() const;
	string getTitle() const;
	string getAuthor() const;
	string getDate() const;
	string getPublisher() const;
	int getBookunits() const;
	double getWholesale() const;
	double getRetail() const;
	int getCount() const;

	// Friends Overload operator << and >> prototypes
	friend ostream &operator << (ostream &, const Book &);
	friend istream &operator >> (istream &, Book &);

	//	Create inventory of Books
	virtual void inventory(vector<Book>);
	//	Test open file pass or fail
	virtual bool OpenFile(fstream &, string);	

	//	Test open file pass or fail
	virtual bool editFile(fstream &, string);
	//	Read the file data with a string
	virtual void ReadContents(fstream &, vector<Book>);		
	//	Add new Title into Book's list
	virtual void addBook(vector<Book> books);
	virtual void addContents(fstream &, string);
	//sort functions
	virtual void sortIsbn(vector<Book>, int arraySize);
	virtual void sortTitle(vector<Book>, int arraySize);
	virtual void sortAuthor(vector<Book>, int arraySize);
	virtual void sortPublisher(vector<Book>, int arraySize);
	virtual void sortDate(vector<Book>, int arraySize);
	virtual void sortUnits(vector<Book>, int arraySize);
	virtual void sortWholesale(vector<Book>, int arraySize);
	virtual void sortRetail(vector<Book>, int arraySize);
	//search functions
	virtual int searchIsbn(vector<Book>, int numElems, string value);
	virtual int searchTitle(vector<Book>, int numElems, string value);
	virtual int searchAuthor(vector<Book>, int numElems, string value);
	virtual int searchPublisher(vector<Book>, int numElems, string value);
	virtual int searchDate(vector<Book>, int numElems, string value);
	virtual int searchUnits(vector<Book>, int numElems, int value);
	virtual int searchWholesale(vector<Book>, int numElems, double value);
	virtual int searchRetail(vector<Book>, int numElems, double value);

	virtual void purchase(int, double);

	virtual void remove(int);
	//	No need to use displayBooks member funtion because I do oveloaded operator << and >>
	//	Display member function
	//void displayBooks() const;
};

#endif

