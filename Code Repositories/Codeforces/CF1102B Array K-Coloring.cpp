#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int a[maxn],col[maxn];
vector<int>idx[maxn];
int main()
{
	int n,k,mxv=0,lim=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),idx[a[i]].push_back(i);
		mxv=max(mxv,(int)idx[a[i]].size()),lim=max(lim,a[i]);
	}
	if(mxv>k||k>n)
	{	puts("NO"); return 0; }
	for(int i=1,pt=0;i<=lim;i++)
		for(int x:idx[i]) col[x]=++pt,pt%=k;
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",col[i]);
}