#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,b,p,f,h,c;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>b>>p>>f>>h>>c;
		b>>=1;
		if(h>c) ans+=min(b,p)*h,b-=min(b,p),ans+=min(b,f)*c;
		else ans+=min(b,f)*c,b-=min(b,f),ans+=min(b,p)*h;
		cout<<ans<<endl;
	}
}

