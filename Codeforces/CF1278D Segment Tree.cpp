#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int tag[maxn],stk[maxn],f[maxn],tot;
vector<int>e[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void link(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv) f[fu]=fv,tot--;
}
int main()
{
	int n,l,r;
	scanf("%d",&n),tot=n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l,&r),tag[l]=i,tag[r]=-i,f[i]=i;
	int cnt=0,pt=0;
	for(int i=1;i<=2*n&&cnt<n;i++)
	{
		if(tag[i]>0) stk[++pt]=tag[i];
		else
		{
			int idx=pt;
			while(stk[idx]!=-tag[i]&&cnt<n)
				link(stk[idx],-tag[i]),idx--,cnt++;
			for(int j=idx;j<pt&&cnt<n;j++)
				stk[j]=stk[j+1];
			pt--;
		}
	}
	puts(cnt==n-1&&tot==1?"YES":"NO");
}