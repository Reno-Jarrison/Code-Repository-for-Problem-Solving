#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int num[maxn],st[maxn][15],lg2[maxn]={-1};
int getmin(int a,int b)
{	return num[a]<=num[b]?a:b; }
int query(int l,int r)
{
	int k=lg2[r-l+1];
	return getmin(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	for(int i=1;i<maxn;i++) lg2[i]=lg2[i>>1]+1;
	int n,m;
	while(~scanf("%s%d",s+1,&m))
	{
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			num[i]=s[i]-'0',st[i][0]=i;
		for(int i=1;i<=lg2[n];i++)
			for(int j=1;j+(1<<i)-1<=n;j++)
				st[j][i]=getmin(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		int pt=0;
		queue<int>que;
		for(int i=1;i<=n-m;i++)
		{
			int l=pt+1,r=m+i;
			pt=query(l,r);
			que.push(num[pt]);
		}
		while(!que.empty()&&!que.front()) que.pop();
		if(que.empty()) que.push(0);
		while(!que.empty()) 
			printf("%d",que.front()),que.pop();
		puts("");
	}
}