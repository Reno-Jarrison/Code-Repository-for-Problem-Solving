#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a[3];
	cin>>t;
	while(t--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+2);
		int ans=0;
		for(int i=0;i<3;i++)
			if(a[i]) ans++,a[i]--;
		if(a[2]&&a[1]) ans++,a[2]--,a[1]--;
		if(a[2]&&a[0]) ans++,a[2]--,a[0]--;
		if(a[1]&&a[0]) ans++,a[1]--,a[0]--;
		if(a[0]&&a[1]&&a[2]) ans++;
		cout<<ans<<endl;
	}
}