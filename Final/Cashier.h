#ifndef CASHIER_H
#define CASHIER_H

#include <string>
#include "Book.h"

class Cashier : public Book
{
public:
	Cashier();
	~Cashier();
	void purchase(int, double);

	friend ostream &operator << (ostream &, const Cashier &);
	friend istream &operator >> (istream &, Cashier &);

	//	Create inventory of Books
	void inventory(vector<Cashier>);
	//	Test open file pass or fail
	bool OpenFile(fstream &, string);	

	//	Test open file pass or fail
	bool editFile(fstream &, string);
	//	Read the file data with a string
	void ReadContents(fstream &, vector<Cashier>);		
	//	Add new Title into Book's list
	void addBook(vector<Cashier> books);
	void addContents(fstream &, string);
	//sort functions
	void sortIsbn(vector<Cashier>, int arraySize);
	void sortTitle(vector<Cashier>, int arraySize);
	void sortAuthor(vector<Cashier>, int arraySize);
	void sortPublisher(vector<Cashier>, int arraySize);
	void sortDate(vector<Cashier>, int arraySize);
	void sortUnits(vector<Cashier>, int arraySize);
	void sortWholesale(vector<Cashier>, int arraySize);
	void sortRetail(vector<Cashier>, int arraySize);
	//search functions
	int searchIsbn(vector<Cashier>, int numElems, string value);
	int searchTitle(vector<Cashier>, int numElems, string value);
	int searchAuthor(vector<Cashier>, int numElems, string value);
	int searchPublisher(vector<Cashier>, int numElems, string value);
	int searchDate(vector<Cashier>, int numElems, string value);
	int searchUnits(vector<Cashier>, int numElems, int value);
	int searchWholesale(vector<Cashier>, int numElems, double value);
	int searchRetail(vector<Cashier>, int numElems, double value);
};

#endif

/*
  1 abstraction & and data encapsualtion
  2 inheritance and redefinition
  3 polymorphism and overriding

  polymorphism when a base type takes the form of a child 
  */