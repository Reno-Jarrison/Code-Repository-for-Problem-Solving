#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int tot,p[maxn],vis[maxn];
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
int main()
{
	init(1e5); 
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ll val=0;
			if(x%2==0) val++;
			while(x%2==0) x>>=1;
			for(int j=1;p[j]*p[j]<=x;j++)
				while(x%p[j]==0) val++,x/=p[j];
			if(x>1) val++;
			sum^=val;
		}
		puts(sum?"W":"L");
	}
}