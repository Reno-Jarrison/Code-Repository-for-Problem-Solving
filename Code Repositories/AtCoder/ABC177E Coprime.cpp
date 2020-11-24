#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int tot,p[maxn],vis[maxn],tag[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	init(1e6);
	int n,d,x,ok=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		d=i==1?x:gcd(d,x);
		for(int i=2;ok&&i*i<=x;i++) if(x%i==0)
		{
			if(tag[i]) ok=0;
			while(x%i==0) x/=i;
			tag[i]=1;
		}
		if(x>1) vis[x]?ok=0:vis[x]=1;
	}
	if(ok) puts("pairwise coprime");
	else if(d==1) puts("setwise coprime");
	else puts("not coprime");
}