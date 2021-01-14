/*
 * booth.c
 *
 *  Created on: Feb 24, 2019
 *      Author: sejoy
 */
#include <stdio.h>
#include <math.h>

int multBooth(int x, int y);
void shift();
void add(int x[]);
void convertToBinary(int x, int arr[]);
void convertToInt(int x[]);

int y[16];
int shifted[16];
int aArr[16], bArr[16], cArr[16];

void main() {
	 int a, b, c;
	 printf("Enter an integer:\n");
	 scanf("%d", &a);
	 printf("Enter an integer:\n");
	 scanf("%d", &b);
	 c = 0; // product, initialized as 0.
	 // the code of your subroutine multBooth is called below
	 c = multBooth(a,b);
	 printf("the product = %d\n", c);
}

void convertToBinary(int x, int arr[]){
	for(int i=0; i<=16; i++){
		arr[i]=x%2;
		x=x/2;
	}//cout << arr << endl;
}

void convertToInt(int x[]){
	int n = 0;
	int length = sizeof(x)/sizeof(*x);
	for (int j=0; j<length; j++) {
	  n = 10*n + x[j];
	}
	int tmp = n;
	int num = 0;
	int mult = 1;
	for(int i=0; x>0; i++){
		num+=(tmp%10)*mult;
		mult *= 2;
		tmp /= 10;
	}
}

void shift(){
	 int a = y[15], b = y[0];
	 for(int i=1; i<16; i++){
		 y[i - 1] = y[i];
	 }y[15] = a;
	 for(int j = 1; j<5; j++){
		 shifted[j - 1] = shifted[j];
	 }shifted[15] = b;
}

void add(int x[]){
	int n = 0;
	for(int i = 0; i <= 16; i++){
		y[i] = y[i] + x[i] + n;
	    if(y[i]>=2){
	    	n = 1;
	    }else{
	        n = 0;
	    }y[i] = y[i]%2;
	}
}

int multBooth(int x, int y){
	convertToBinary(x, aArr);
	convertToBinary(y, bArr);
	int num = 0;

	for(int i = 0; i<=16; i++){
		if(aArr[i] == num){
			shift();
			num = aArr[i];
	    }else if(aArr[i] == 1 && num == 0){
	    	add(aArr);
	    	shift();
	    	num = aArr[i];
	    }else{
	    	add(y);
	    	shift();
	    	num = aArr[i];
	    }
	}return 0;
}
