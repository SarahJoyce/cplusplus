/* Sarah Joyce
 * Professor Yarrington
 * CISC220: Data Structures
 * 3/21/19
 * BookMain.cpp
 */
#include "Book.hpp"

Book greatest(Book arr[], int size);

int main(){
	int five[10] = {5,5,5,5,5,5,5,5,5,5};
	int four[10] = {4,4,4,4,4,4,4,4,4,4};
	int three[10] = {3,3,3,3,3,3,3,3,3,3};
	Book bookArray[5];
	bookArray[0] = Book("Emily","Chang","Brotopia",2018,five);
	bookArray[1] = Book("Sheryl","Sandberg","Lean In",2013,four);
	bookArray[2] = Book("Jason","Fagone","The Woman Who Smashed Codes",2017,three);
	bookArray[3] = Book("Samantha","Walravens","Geek Girl Rising",2017,three);
	bookArray[4] = Book("Sydney","Padua","The Thrilling Adventures of Lovelace and Babbage",2015,four);
	Book a = greatest(bookArray, 5);
	a.printInfo();
	Book *rise = new Book("Nathalia","Holt","Rise of the Rocket Girls",2016,four);
	rise->printInfo();
	Book *bookArray2 = new Book[2];
	bookArray2[0] = Book("Amie", "Kaufman", "Illuminae", 2015, five);
	bookArray2[1] = Book("Amie", "Kaufman", "Gemina", 2016, five);
	for(int i=0; i<2; i++){
		bookArray2[i].printInfo();
	}
	return 0;
}

Book greatest(Book arr[], int size){
	Book result=arr[0];
	for(int i=1; i<size; i++){
		if(result.averageRating()<arr[i].averageRating()){
			result = arr[i];
		}
	}return result;
}
