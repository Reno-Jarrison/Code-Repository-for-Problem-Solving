#include<bits/stdc++.h>
using namespace std;
int n,a[10],tmp[10];
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=i) return false;
	 return true;
}
void update(int l,int r,int to)
{
	int len=r-l+1;
	memcpy(tmp,a,sizeof(a));
	if(to<l) for(int i=1;i<=l-to;i++)
		tmp[r-i+1]=a[l-i];
	else for(int i=1;i<=to-l;i++)
		tmp[l+i-1]=a[r+i];
	for(int i=1;i<=len;i++)
		tmp[to+i-1]=a[l+i-1];
	memcpy(a,tmp,sizeof(a));
}
int h()
{
	int cnt=0;
	for(int i=1;i<n;i++)
		if(a[i+1]!=a[i]+1) cnt++;
	return cnt;
}
bool dfs(int step,int lim)
{
	if(3*step+h()>3*lim) return false; 
	if(check()) return true;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=i+1;k<=n-j+i;k++)
			{
				update(i,j,k);
				if(dfs(step+1,lim)) return true;
				update(k,k+j-i,i);
			}
	return false;
}
int main()
{
	int ks=0;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int dep=0;
		while(true)
		{	if(dfs(0,dep)) break; dep++; }
		printf("Case %d: %d\n",++ks,dep);
	}
}