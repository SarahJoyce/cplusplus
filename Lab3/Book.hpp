/*
 * Book.hpp
 *
 *  Created on: Mar 8, 2019
 *      Author: sejoy
 */

#ifndef BOOK_HPP_
#define BOOK_HPP_
#include <string>
using namespace std;

class Book{
	string firstname;
	string lastname;
	int *ratings = new int[10];
	string bookname;
	int year;
public:
	Book();
	Book(string first, string last, string book, int y);
	Book(string first, string last, string book, int y, int arr[]);
	~Book();
	double averageRating();
	void printRating();
	void printInfo();
	bool operator<(Book b);
};
#endif /* BOOK_HPP_ */
