#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN (1000000)
#define LOWER (0)
#define UPPER (1)
#define OTHER (2)

//int c[MN];
//char t[MN];
char frq[] = "etaoinshrdlcumwfgypbvkjxqz";

void init(char s[], int slen, char t[], int c[])
{
	for(int i=0; i<slen; ++i)
		t[i] = c[i] = 0;
	
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
//	for(int i=0; i<slen; ++i)
//		printf("\n %d %d",t[i],c[i]);
}

double getCI(char t[], int c[], int slen, int klen)
{
	int cnt[klen][26];
	for(int i=0; i<klen; ++i)
		for(int j=0; j<26; ++j)
			cnt[i][j] = 0;
	int sum[klen];
	for(int j=0; j<klen; ++j)
		sum[j]=0;
//	int sum = 0;
	for(int j=0, i=0; i<slen; ++i)
		if(c[i] != OTHER)
//			++sum,
			++sum[j%klen],
			++cnt[j++%klen][t[i]];
	
	double CI = 0;
	double SUM[klen];
	for(int i=0; i<klen; ++i)
		SUM[i] = (double)sum[i] * (sum[i]-1);
//	double SUM = (double)sum * (sum-1);
	for(int i=0; i<klen; ++i)
		for(int j=0; j<26; ++j)
			if(cnt[i][j] >= 1)
				CI += (double)cnt[i][j] * (cnt[i][j]-1) / SUM[i];
	CI /= klen;
//	printf(" C:CI=%f\n",CI);
	return CI;
}

typedef struct CNT{
	char ch;
	int c;
}CNT;
CNT cnt[26];

int cmp(const void *l, const void *r)
{
	return (*(CNT*)l).c < (*(CNT*)r).c ? 1 : -1;
}

char getK(char t[], int c[], int slen, int klen, int I)
{
	for(int i=0; i<26; ++i)
		cnt[i].ch = i,
		cnt[i].c = 0;
	for(int j=0, i=0; i<slen; ++i)
		if(c[i] != OTHER)
		{
			if(j == I)
				++cnt[t[i]].c;
			++j;
			j %= klen;
		}
	qsort(cnt, 26, sizeof(CNT), cmp);
//	for(int i=0; i<26; ++i)
//		printf("  %c:%d",cnt[i].ch+'a',cnt[i].c);
	int e = cnt[0].ch;
//	printf(" C: e=%d",e);
	return 
//		printf(" K %d = %c\n",I,'a' + (e-4+26) % 26),
		'a' + (e-4+26) % 26;
}

//void decrypt(char s[], int slen, char k[], int klen, char T[], int c[])
//{
//	for(int i=0; i<slen; ++i)
//		s[i<<1] = s[i<<1|1] = 0;
//	char t[slen];
//	for(int i=0; i<klen<<1; ++i)
//		if('a'<=k[i<<1] && k[i<<1]<='z')
//			k[i] = k[i<<1] - 'a';
//		else if('A'<=k[i<<1] && k[i<<1]<='Z')
//			k[i] = k[i<<1] - 'A';
//		//else ignored
//	
//	for(int j=0,i=0; i<slen; ++i)
//		if(c[i] != OTHER)
//			t[i] = (T[i] - k[j++%klen] + 26) % 26;
//		else
//			t[i] = T[i];
//	
//	for(int i=0; i<slen; ++i)
//	{
//		if(c[i] == LOWER)
//			s[i<<1] = t[i] + 'a';
//		else if(c[i] == UPPER)
//			s[i<<1] = t[i] + 'A';
//		else
//			s[i<<1] = t[i];
//	}
//}


int main(){
	int t = 3;
	int tt = t++%5;
	printf(" tt:%d\n",tt);
	printf("%d\n",0<<1);
	puts(" from C:");
	char s[] = "a b - d";
	char k[] = "b c b c";
//	encrypt(s, 4, k, 2);
	for(int i=0; i<8; ++i)
		putchar(s[i]);
	return 0;
}
