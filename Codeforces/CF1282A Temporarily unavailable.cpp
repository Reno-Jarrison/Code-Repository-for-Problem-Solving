#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,r;
		cin>>a>>b>>c>>r;
		if(a>b) swap(a,b);
		ll L=max(a,c-r),R=min(b,c+r),ans;
		if(L>b||R<a) ans=b-a;
		else ans=b-a-R+L;
		cout<<ans<<endl;
	}	
}