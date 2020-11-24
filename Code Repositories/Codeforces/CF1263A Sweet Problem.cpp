#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[3];
		for(int i=0;i<3;i++)
			cin>>a[i];
		sort(a,a+3);
		int ans=min(a[2]-a[1],a[0]);
		a[0]-=ans,a[2]-=ans;
		if(!a[0]) ans+=min(a[1],a[2]);
		else ans+=a[0]/2*2+a[1]-a[0]/2;
		cout<<ans<<endl;
	}	
}