#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fib[55]={1,1};
void getfib()
{
	for(int i=2;i<=50;i++)
		fib[i]=fib[i-1]+fib[i-2]; 
}
int main()
{
	getfib();
	int n;
	while(cin>>n&&n)
	{
		int l=0,r=50,m;
		while(l<=r)
		{
			m=(l+r)>>1; 
			fib[m]>n?r=m-1:l=m+1;
		}
		printf(fib[r]!=n?"First win\n":"Second win\n");
	}
}
