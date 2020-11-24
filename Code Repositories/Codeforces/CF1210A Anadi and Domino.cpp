#include<bits/stdc++.h>
#define ll long long
using namespace std;
int u[200],v[200];
bool g[8][8];
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i],g[u[i]][v[i]]=g[v[i]][u[i]]=true;
	if(n<7) { cout<<m; return 0; } 
	for(int i=1;i<=7;i++)
	{
		int tmp=0,flag=0;
		for(int j=1;j<=m;j++)
			if(u[j]!=i&&v[j]!=i) tmp++;
		for(int j=1;j<=7;j++)
		{
			int sum=0;
			for(int k=1;k<=7;k++)
				if(g[i][k]&&!g[j][k]) sum++;
			flag=max(flag,sum);
		}
		ans=max(ans,tmp+flag);
	}
	cout<<ans;
}

