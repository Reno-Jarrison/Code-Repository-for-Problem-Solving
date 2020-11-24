#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<16;
int n,cnt,p[maxn],vis[maxn]={1,1};
int main()
{
	for(int i=2;i<=maxn-5;i++)
	{
		!vis[i]?p[++cnt]=i:false;
		for(int j=1;p[j]*i<=maxn-5;j++)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0) break;
		}
	}
	while(scanf("%d",&n)&&n)
	{
		int l=2,r=cnt,m,ans=0;
		while(l<=r) m=(l+r)>>1,p[m]>n?r=m-1:l=m+1;
		while(n-p[r]<=p[r]) 
			(!vis[n-p[r]])&&(!vis[p[r]])?ans++:0,r--;
		printf("%d\n",ans);
	}
}
