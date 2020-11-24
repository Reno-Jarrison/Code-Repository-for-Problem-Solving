#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{	return b?gcd(b,a%b):a; }
int main()
{
	int t,a,b,k;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>k;	
		if(a>b) swap(a,b);
		if(b%a==0) puts(b/a-1<k?"OBEY":"REBEL");
		else
		{
			int d=gcd(a,b);
			a/=d,b/=d;
			puts(b/a+((b-1)%a>0)<k?"OBEY":"REBEL");
		}
	}
}

