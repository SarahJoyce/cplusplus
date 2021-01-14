/*
 * main.cpp
 *
 *  Created on: May 9, 2019
 *      Author: sejoy
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	string k = "list";
	int n = k.length();
	int h = 0;
	for(int i = n-1; i>0; i--){
		h = (19*h + (int)k[i])%10;
	}
	cout << h << endl;
	return 0;
}


