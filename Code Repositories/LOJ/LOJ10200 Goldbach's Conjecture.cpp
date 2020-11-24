#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
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
		if(n&1) 
		{ printf("Goldbach's conjecture is wrong.\n"); continue; }
		int l=2,r=cnt,m;
		while(l<=r) m=(l+r)>>1,p[m]>n?r=m-1:l=m+1;
		while(vis[n-p[r]]) r--;
		printf("%d = %d + %d\n",n,n-p[r],p[r]);
	}
}