#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s,ans="NONE";
	map<string,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>s,mp[s]++;
		if(mp[s]*2>n) ans=s;
	}
	cout<<ans;
}