#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],vis[maxn];
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int d=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[i]=0,d=max(d,a[i]);
		for(int i=1;i<=n;i++)
		{
			int id=0,mnv=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				if(gcd(d,a[j])>mnv) 
					id=j,mnv=gcd(d,a[j]);
			}
			vis[id]=1,d=mnv;
			printf("%d ",a[id]);
		}
		puts("");
	}
}