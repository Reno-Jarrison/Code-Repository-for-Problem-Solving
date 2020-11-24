#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int p[maxn],f[maxn],ans=0x7fffffff;
int find(int x)
{
	if(f[x]!=x)
	{
		int fa=f[x];
		f[x]=find(fa);
		p[x]+=p[fa];
	}	
	return f[x];
}
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int f1=find(i),f2=find(x);
		if(f1!=f2) f[f1]=f2,p[i]=p[x]+1;
		else ans=min(ans,p[x]+1);
	}
	printf("%d",ans);
}