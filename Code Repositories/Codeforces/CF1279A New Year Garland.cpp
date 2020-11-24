#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,sum;
		cin>>a>>b>>c;
		sum=a+b+c;
		ll mxv=max(a,max(b,c));
		puts(mxv>sum-mxv+1?"No":"Yes");
	}	
}