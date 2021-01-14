/*
 * Book.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: sejoy
 */

#include "Book.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Book::Book(){}
Book::Book(string first, string last, string book, int y){
	firstname = first;
	lastname = last;
	int *ratings = new int[10];
	for(int i=0; i<10; i++){
		ratings[i] = 0;
	}
	bookname = book;
	year = y;
}
Book::Book(string first, string last, string book, int y, int arr[10]){
	firstname = first;
	lastname = last;
	ratings = arr;
	bookname = book;
	year = y;
}
Book::~Book(){
	delete [] ratings;
}
double Book::averageRating(){
	int sum = 0;
	for(int i=0; i<10; i++){
		sum+=ratings[i];
	}
	double average = sum/10;
	return average;
}
void Book::printRating(){
	double average = averageRating();
	if(average==0){
		cout << "No ratings yet." << endl;
	}else{
		cout << "Rating: " << average << endl;
	}
}
void Book::printInfo(){
	cout << "Book: " << bookname << endl;
	cout << "Author's name: " << firstname << " " << lastname << endl;
	cout << "Year of Publication: " << year << endl;
	printRating();
}
//Check this later- does it work?
bool Book::operator<(Book b){
	return b.bookname<bookname;
}
