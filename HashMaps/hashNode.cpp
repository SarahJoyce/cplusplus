/*
 * hashNode.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sejoy
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hashNode.hpp"
using namespace std;

hashNode::hashNode(){
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}
hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}
hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
	addValue(v);
}
void hashNode::addValue(string v){
	if(valuesSize==0){
		valuesSize = 100;
		values = new string[valuesSize];
	}
	if(currSize>=valuesSize){
		dblArray();
	}
	values[currSize] = v;
	currSize++;
}
void hashNode::dblArray(){
	string *oldValues = values;
	int oldSize = valuesSize;
	valuesSize = valuesSize*2;
	values = new string[valuesSize];
	for(int i=0; i<valuesSize; i++){
		values[i]=oldValues[i];
	}
}
string hashNode::getRandValue(){
	int random = rand()%currSize;
	if(values == NULL){
		return "";
	}else{
		return values[random];
	}
}
