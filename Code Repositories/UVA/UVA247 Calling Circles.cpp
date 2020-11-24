#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string name[30],s1,s2;
bool flag[30][30],vis[30];
int getid(string s,int& cnt)
{
	for(int i=1;i<=cnt;i++)
		if(name[i]==s) return i;
	name[++cnt]=s;
	return cnt;
}
void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				flag[i][j]|=(flag[i][k]&&flag[k][j]);
}
void dfs(int u,int n,int step)
{
	cout<<(step?", ":"")<<name[u],vis[u]=true;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&flag[u][i]&&flag[i][u])
			dfs(i,n,step+1);
}
int main()
{
	int n,m,cases=0;
	ios::sync_with_stdio(false);
	while(cin>>n>>m&&n&&m)
	{
		int cnt=0;
		memset(flag,0,sizeof(flag));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			cin>>s1>>s2;
			int u=getid(s1,cnt),v=getid(s2,cnt);
			flag[u][v]=true;
		}
		floyd(n);
		if(cases++) cout<<endl;
		cout<<"Calling circles for data set "<<cases<<":"<<endl;
		for(int i=1;i<=n;i++)
			if(!vis[i]) dfs(i,n,0),cout<<endl;
	}
}