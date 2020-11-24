#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int f[maxn],w[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	for(int i=1;i<maxn;i++) f[i]=i,w[i]=1;
	int n,t;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			map<string,int>mp;
			int idx=0;
			for(int i=1;i<=n;i++)
			{
				string s1,s2;
				cin>>s1>>s2;
				if(!mp[s1]) mp[s1]=++idx;
				if(!mp[s2]) mp[s2]=++idx;
				int fu=find(mp[s1]),fv=find(mp[s2]);
				if(fu!=fv) f[fu]=fv,w[fv]+=w[fu];
				printf("%d\n",w[fv]);
			}
			for(int i=1;i<=idx;i++) f[i]=i,w[i]=1;
		}
	}
}