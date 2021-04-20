#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int x[maxn],y[maxn],p[maxn],vis[maxn];
ll sqr(ll x)
{	return x*x; }
ll dist(int a,int b)
{	return sqr(x[a]-x[b])+sqr(y[a]-y[b]); }
int main()
{
	int n,pt=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	p[1]=pt,vis[pt]=1;
	for(int i=2;i<=n;i++)
	{
		ll mxv=0,nxt=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dist(pt,j)>mxv) 
				mxv=dist(pt,j),nxt=j;
		p[i]=pt=nxt,vis[pt]=1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
}