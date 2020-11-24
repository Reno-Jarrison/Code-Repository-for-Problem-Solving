#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n;
	string x;
	cin>>t;
	while(t--)
	{
		map<string,int>mp;
		set<int>s[2];
		int scnt[2]={0};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			int len=x.size();
			if(x[0]==x[len-1]) 
			{	scnt[x[0]-'0']++; continue; }
			string y=x;
			reverse(y.begin(),y.end()),mp[x]=i;
			if(mp[y]) s[y[0]-'0'].erase(mp[y]);
			else s[x[0]-'0'].insert(i);
		}
		if(scnt[0]+scnt[1]==n&&scnt[0]&&scnt[1])
		{	cout<<-1<<endl; continue; }
		int id=s[1].size()>s[0].size()?1:0;
		int ans=s[id].size()-s[id^1].size(),cnt=1;
		ans>>=1,cout<<ans<<endl;
		for(int i:s[id]) if(cnt<=ans)
			cout<<i<<" ",cnt++;
		puts("");
	}
}