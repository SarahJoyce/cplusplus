/*
 * hashMap.cpp
 *
 *  Created on: May 3, 2019
 *      Author: sejoy
 */

#include "hashMap.hpp"

hashMap::hashMap(bool hash1, bool coll1){
	first = "";
	numKeys = 0;
	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;
	mapSize = 10;
	map = new hashNode*[mapSize];
	for (int i = 0; i < mapSize; i++) {
	    map[i] = NULL;
	}
}
void hashMap::addKeyValue(string k, string v){
	if(0.7*mapSize<numKeys){
		this->reHash();
	}
	int index = getIndex(k);
	hashNode *tmp = new hashNode(k,v);
	if(map[index]==NULL){
		map[index] = tmp;
		numKeys++;
	}else{
		map[index]->addValue(v);
	}
}
int hashMap::getIndex(string k){
	int index = 0;

	if(h1==true){
		index = calcHash(k);
	}else{
		index = calcHash2(k);
	}

	if(map[index]==NULL){
		return index;
	}else if(map[index]->keyword == k){
		return index;
	}else{
		//rehash keys
		collisionct1++;
		if(c1 == true){
			index = collHash1(1, index+1, k);
		}else{
			index = collHash2(1,index+1, k);
		}
	}
	return index;
}
//n characters hash
int hashMap::calcHash(string k){
	int n = k.length();
	int h = 0;
	for(int i = 0; i<n; i++){
		h = (19*h + int(k[i]))%this->mapSize;
	}
	return h;
}
int hashMap::calcHash2(string k){
	int n = k.length();
	int h = 0;
	for(int i = 0; i<n; i++){
		h = (17*h + int(k[i]))%this->mapSize;
	}
	return h;
}
int hashMap::getClosestPrime(int mapSize){
	if (mapSize < 2)
			mapSize = 2;
		for (int i = mapSize -1; i>1; i--) {
			if (mapSize % i == 0) {
				return this->getClosestPrime(mapSize + 1);
			}
		}
		return mapSize;
}
void hashMap::reHash(){
	int index = 0;
	hashNode **oldMap = map;
	int originalSize = mapSize;
	mapSize = getClosestPrime(mapSize*2);
	map = new hashNode *[mapSize];
	for (int i = 0; i < mapSize; i++) {
	    map[i] = NULL;
	}
	for(int i=0; i<originalSize; i++){
		if(oldMap[i]!=NULL){
			index = this->getIndex(oldMap[i]->keyword);
			map[index] = oldMap[i];
		}
	}
}
//linear probing
int hashMap::collHash1(int h, int i, string k){
	if (map[i] == NULL || map[i]->keyword == k) {
			return i;
		} else {
			h++;
			if (i >= mapSize -1) {
				i = -1;
			}
			collisionct2 += h +1;
			return collHash1(h, i +1, k);
	}
}
//quadratic probing
int hashMap::collHash2(int h, int i, string k){
	if (map[i] == NULL || map[i]->keyword == k) {
		return i;
	} else {
		h++;
		i += h * h;
		while (i >= mapSize) {
			i -= mapSize;
		}
		collisionct2 += h +1;
		return collHash2(h, i, k);
	}
}
int hashMap::findKey(string k){
	int index = 0;
	int ct = 0;
	if(h1==true){
		index = calcHash(k);
	}else{
		index = calcHash2(k);
	}
	while(ct<numKeys){
		if(map[index]==NULL){
			return -1;
		}else if(map[index]->keyword == k){
			return index;
		}else{
		//calculate collision handling
			if(c1==true){
				index = collHash1(1, index+1, k);
			}else{
				index = collHash2(1, index+1, k);
			}

			if(map[index]->keyword == k){
				return index;
			}else{
				return -1;
			}

			ct++;
		}
	}return -1;
}
void hashMap::printMap(){
	for(int i=0; i<mapSize; i++){
		cout << i << " ";
		if(map[i]==NULL){
			cout << "NULL";
		}else{
			cout << map[i]->keyword << " ";
			for (int j=0; j<map[i]->currSize; j++){
				cout << map[i]->values[j]<< ", ";
			}
		}cout << endl;
	}cout << endl;
}
