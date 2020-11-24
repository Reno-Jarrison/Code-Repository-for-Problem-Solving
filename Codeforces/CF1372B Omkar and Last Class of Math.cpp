#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,res=1,fct;
		cin>>n,fct=n;
		for(int i=2;i*i<=n;i++) if(n%i==0)
		{	res=n/i,fct=i; break; }
		cout<<res<<" "<<(fct-1)*res<<endl;
	}
}