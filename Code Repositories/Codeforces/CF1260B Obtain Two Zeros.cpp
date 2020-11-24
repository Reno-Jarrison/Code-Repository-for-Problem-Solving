#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	ll a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<b) swap(a,b);
		if((a+b)%3==0)
		{
			int k=(a+b)/3;
			if(a>=k&&b>=k) 
			{	puts("YES"); continue; } 
		}
		puts("NO");
	}
}

