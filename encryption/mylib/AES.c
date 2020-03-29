#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN (10000)
typedef unsigned int uint;

int a[][4] =
{
    {2,3,1,1},
    {1,2,3,1},
    {1,1,2,3},
    {3,1,1,2}
};

void mc(int x[][4])
{
	int rt[4][4];
	memset(rt, 0, sizeof rt);
	for(int j=0; j<4; ++j)
		for(int i=0; i<4; ++i)
			for(int k=0; k<4; ++k)
			{
				int t = x[k][j];
				if(a[i][k] & 1)
					rt[i][j] ^= t;
				if(a[i][k] & 2)
				{
					t <<= 1;
					if(t & 0x100)
						t ^= 0x11B;
					rt[i][j] ^= t;
				}
			}
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			x[i][j] = rt[i][j];
}

int sb(int x)
{
	
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
//²âÊÔÑùÀý²Î¿¼https://blog.csdn.net/qq_31962349/article/details/80008174
//	int s[4][4]={
//		{0xad,0x32,0xb4,0x41},
//		{0xe6,0x1c,0xe6,0x27},
//		{0x5d,0x6e,0x11,0x98},
//		{0xfb,0x4e,0x27,0x39}
//	};
	int s[4][4]={
		{5},
		{0x14},
		{0xa1},
		{0xcb}
	};
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			printf("%3x%c",s[i][j]," \n"[j==3]);
	mc(s);
	puts("");
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			printf("%3x%c",s[i][j]," \n"[j==3]);
	return 0;
}
