#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int n,x,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++)
		scanf("%d",&x),d=gcd(d,x);
	printf("%d\n",d);
}