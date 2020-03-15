#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN (10000)
#define LOWER (0)
#define UPPER (1)
#define OTHER (2)

int c[MN];
char t[MN];

void init(char s[], int slen, char k[], int klen)
{
//	char *t = (char*)calloc(sizeof(char), slen<<1);
	memset(t, 0, sizeof t);
	memset(c, 0, sizeof c);
	
	for(int i=0; i<slen<<1; ++i)
		if('a'<=s[i<<1] && s[i<<1]<='z')
			t[i] = s[i<<1] - 'a',
			c[i] = LOWER;
		else if('A'<=s[i<<1] && s[i<<1]<='Z')
			t[i] = s[i<<1] - 'A',
			c[i] = UPPER;
		else
			t[i] = s[i<<1],
			c[i] = OTHER;
	
	for(int i=0; i<klen<<1; ++i)
		if('a'<=k[i<<1] && k[i<<1]<='z')
			k[i] = k[i<<1] - 'a';
		else if('A'<=k[i<<1] && k[i<<1]<='Z')
			k[i] = k[i<<1] - 'A';
		//else ignored
}

void final(char s[], int slen)
{
	for(int i=0; i<slen; ++i)
		if(c[i] == LOWER)
			s[i<<1] = t[i] + 'a';
		else if(c[i] == UPPER)
			s[i<<1] = t[i] + 'A';
		else
			s[i<<1] = t[i];
}

void encrypt(char s[], int slen, char k[], int klen)
{
	init(s, slen, k, klen);
	
	for(int j=0,i=0; i<slen; ++i)
		if(c[i] != OTHER)
			t[i] = (t[i] + k[j++%klen]) % 26;
	
	final(s, slen);
}

void decrypt(char s[], int slen, char k[], int klen)
{
	init(s, slen, k, klen);
	
	for(int j=0,i=0; i<slen; ++i)
		if(c[i] != OTHER)
			t[i] = (t[i] - k[j++%klen] + 26) % 26;
	
	final(s, slen);
}


int main(){
	char s[] = "a b - d";
	char k[] = "b c b c";
	encrypt(s, 4, k, 2);
	for(int i=0; i<8; ++i)
		putchar(s[i]);
	return 0;
}
