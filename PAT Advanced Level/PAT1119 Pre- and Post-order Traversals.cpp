#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int pre[maxn],post[maxn],ans[maxn],ok=1,idx;
void solve(int l1,int r1,int l2,int r2)
{
	if(l1==r1)
	{	ans[++idx]=pre[l1]; return; }
	int mid1=r1,mid2=r2-1;
	while(pre[l1+1]!=post[mid2]) mid2--,mid1--;
	solve(l1+1,mid1,l2,mid2);
	ans[++idx]=pre[l1];
	if(mid2+1==r2) ok=0;
	else solve(mid1+1,r1,mid2+1,r2-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&pre[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&post[i]);
	solve(1,n,1,n);
	puts(ok?"Yes":"No");
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i],i==n?'\n':' ');
}