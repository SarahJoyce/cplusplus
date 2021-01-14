/*
 * hashMap.hpp
 *
 *  Created on: May 3, 2019
 *      Author: sejoy
 */

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include "hashNode.hpp"

class hashMap {
	friend class makeSeuss;
	hashNode **map; //a single dimensional dynamically allocated array of pointers to hashNodes
	/********************************************************************************
	NOTE HERE: the map is a dynamically allocated array of nodes. Meaning it’s a pointer to an array of
	pointers to nodes. I did this so that I could move the addresses around without having to recreate
	nodes each time I rehashed. It looks complicated, but it’s not. We’ve seen this.
	To make the map, you’ll do something to the effect of:
	map = new hashNode*[mapSize];
	and then you can either set map[i] = NULL or map[i] = new hashNode(k,v);
	Make sure you originally set every address in the map array to NULL, and then when you rehash.
	*********************************************************************************/
	string first;
	int numKeys;
	int mapSize;
	bool h1;
	bool c1;
	int collisionct1;
	int collisionct2;
public:
	hashMap(bool hash1, bool coll1);
	void addKeyValue(string k, string v);
	int getIndex(string k);
	int calcHash(string k);
	int calcHash2(string k);
	int getClosestPrime(int mapSize);
	void reHash();
	int collHash1(int h, int i, string k);
	int collHash2(int h, int i, string k);
	int findKey(string k); //finds the key in the array and returns its index. If it's not in the array, returns -1
	//do NOT start at index zero and loop through the array- hash key to find index and return value??
	void printMap();
};



#endif /* HASHMAP_HPP_ */
