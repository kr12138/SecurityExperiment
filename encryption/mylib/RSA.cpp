#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN (1000000)
#include <iostream>
using namespace std;

char t[MN];
typedef long long ll;
ll p, q;
ll n, phin;
ll d, e;
ll m, c;

inline ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if(!b) return x=1, y=0, a;
	ll d = exgcd(b, a%b, x, y);
	ll z=x; x=y; y=z-a/b*y;
	return d;
}

inline ll inv(ll a, ll p)
{
	ll x, y;
	if(exgcd(a, p, x, y) != 1) return -1;
	return (x%p+p) % p;
}

ll qpow(ll a, ll b, ll p)
{
	ll ans = 1;
	for(; b; b>>=1, a=a*a%p)
		if(b&1) ans=ans*a%p;
	return ans;
}

inline ll getD()
{
	return inv(e, phin);
}


void encrypt()
{
	
}

void decrypt()
{
	
}


int main(){
	p = 13;
	q = 17;
	n = p * q;
	phin = (p-1) * (q-1);
	e = 19;
	d = getD();
	m = 113;
	c = qpow(m, e, n);
	cout<<"D:"<<d<<'\n';
	cout<<"C:"<<c<<'\n';
	cout<<qpow(c, d, n);
	
	return 0;
}
