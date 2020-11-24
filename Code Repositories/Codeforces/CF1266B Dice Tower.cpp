#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll x;
	int t; 
	cin>>t;
	while(t--)
	{
		cin>>x;
		if(x<=14) puts("NO");
		else x%=14,puts(x&&x<=6?"YES":"NO");
	}
}