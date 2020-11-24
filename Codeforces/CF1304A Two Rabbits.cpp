#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,x,y,a,b,ans;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b)) ans=-1;
		else ans=(y-x)/(a+b);
		cout<<ans<<endl;
	}
}