/*
 * hashNode.hpp
 *
 *  Created on: May 3, 2019
 *      Author: sejoy
 */

#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class hashNode{
	friend class hashMap;
	string keyword;
	string *values;
	int valuesSize;
	int currSize;
public:
	hashNode();
	hashNode(string s);
	hashNode(string s, string v);
	void addValue(string v);
	void dblArray();
	string getRandValue();
};
#endif /* HASHNODE_HPP_ */
