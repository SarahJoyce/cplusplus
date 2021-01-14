/*
 * Lab7main.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sejoy
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.hpp"
#include "hashNode.hpp"
#include "makeSeuss.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	makeSeuss seuss1("DrSeuss.txt", "output.txt", true , true);
	//makeSeuss seuss2("DrSeuss.txt", "output.txt", false , true);
	//makeSeuss seuss3("DrSeuss.txt", "output.txt", true , false);
	//makeSeuss seuss4("DrSeuss.txt", "output.txt", false , false);
	return 0;
}
