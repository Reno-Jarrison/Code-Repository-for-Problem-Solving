#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int mxv=0;
		string ans="",s;
		map<string,int>mp;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			if(++mp[s]>mxv)
				ans=s,mxv++;
		}
		cout<<ans<<endl;
	}
}