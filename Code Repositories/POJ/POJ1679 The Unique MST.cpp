#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int f[105],t,n,m,cnt,flag;
ll ans,minm;
struct edge
{
    int x,y,w;
    bool operator <(const edge &x) const
    	{ return w<x.w; }
}e[200001];
vector<int>del;
int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void initset()
	{ for(int i=1;i<=n;i++) f[i]=i; }
void join(int x,int y) 
	{ f[find(x)]=find(y); }
void kruskal(int index)
{
	ans=cnt=0;
	initset();
	for(int i=0;i<m;i++)
        if(i!=index&&cnt<n-1&&find(e[i].x)!=find(e[i].y))
			join(e[i].x,e[i].y),ans+=e[i].w,cnt++;
	if(cnt==n-1&&ans==minm) flag=1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
	    scanf("%d%d",&n,&m);
	    for(int i=0;i<m;i++)
	        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	    sort(e,e+m);
	    del.clear();
	    initset();
    	minm=cnt=flag=0;
	    for(int i=0;i<m;i++)
	    	if(cnt<n-1&&find(e[i].x)!=find(e[i].y))
	    		join(e[i].x,e[i].y),minm+=e[i].w,cnt++,del.push_back(i);
	    for(int i=0;i<del.size();i++) 
			if(flag) break;
			else kruskal(del[i]);
	    if(flag) printf("Not Unique!\n");
		else printf("%lld\n",minm);
	}
}