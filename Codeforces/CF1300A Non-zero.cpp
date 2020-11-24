#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0,ans=0;
		for(int i=1;i<=n;i++) 
			cin>>a,ans+=(a==0),sum+=a;
		sum+=ans;
		if(!sum) ans++;
		cout<<ans<<endl;
	}
}