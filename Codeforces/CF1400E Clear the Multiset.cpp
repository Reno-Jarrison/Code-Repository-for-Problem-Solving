#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int a[maxn];
int solve(int l,int r)
{
	int mnv=1e9;
	for(int i=l;i<=r;i++) 
		mnv=min(mnv,a[i]);
	for(int i=l;i<=r;i++) a[i]-=mnv;
	int ans=mnv,las=l;
	for(int i=l;i<=r;i++)
	{
		if(a[i]&&(!a[i+1]||i==r))
			ans+=solve(las,i);
		if(!a[i]&&a[i+1]) las=i+1;
	}
	return min(ans,r-l+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d",solve(1,n));
}