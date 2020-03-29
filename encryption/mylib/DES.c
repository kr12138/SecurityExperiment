#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN (10000)
typedef unsigned int uint;

int SB1[]=
{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
;

int sb(int i, int b)
{
	int b1 = b & 0b100000;
	int b2 = (b & 1) << 4;
	int b3 = (b & 0b11110) >> 1;
	b = b1 | b2 | b3;
	return SB1[b];
}

void encrypt(char s[], int slen, char k[], int klen)
{
	for(int i=0; i<8; ++i)
		printf("%d ",s[i]);
}

void decrypt(char s[], int slen, char k[], int klen)
{
	
}


int main(){
//	for(int i=0; i<64; ++i) printf("%d ",SB1[i]);
	printf("%d",sb(0, 0b100010 ^ 0b010111));
//	char s[8] = "²âÊÔÓÃ´®";
//	char k[] = "b c b c";
//	encrypt(s, 4, k, 2);
//	for(int i=0; i<8; ++i)
//		putchar(s[i]);
	return 0;
}
