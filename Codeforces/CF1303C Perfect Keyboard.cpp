#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
char s[maxn];
set<int>e[26];
void link(int u,int v)
{	e[u].insert(v),e[v].insert(u); }
void dfs(int u,int f)
{
	cout<<char(u+'a');
	for(int v:e[u])
		if(v!=f) dfs(v,u);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int len=strlen(s);
		for(int i=0;i<26;i++) e[i].clear();
		for(int i=1;i<len;i++)
			link(s[i]-'a',s[i-1]-'a');
		vector<int>ans;
		int ok=true,tag=0,beg=-1;
		for(int i=0;i<26;i++)
		{
			if(e[i].size()) tag=1;
			if(e[i].size()>2) ok=false;
			else if(e[i].size()==1) beg=i;
			else if(!e[i].size())
				ans.push_back(i+'a');
		}
		if(tag&&beg==-1) ok=false;
		if(!ok) { puts("NO"); continue; }
		puts("YES");
		if(tag) dfs(beg,-1);
		for(char x:ans) cout<<x;
		puts("");
	}
}