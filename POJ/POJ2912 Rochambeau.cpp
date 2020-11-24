#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1505,maxm=2e3+5;
int f[maxn],eu[maxm],ev[maxm],ew[maxm];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void merge(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv) f[fu]=fv;
}
int main()
{
	int n,m,u,v; char c;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%d%c%d",&u,&c,&v),u++,v++;
			if(c=='<') swap(u,v);
			eu[i]=u,ev[i]=v,ew[i]=(c!='=');
		}
		int cnt=0,mxv=0,id=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				f[j]=j,f[j+n]=j+n,f[j+2*n]=j+2*n;
			int ok=1;
			for(int j=1;ok&&j<=m;j++)
			{
				if(eu[j]==i||ev[j]==i) continue;
				u=eu[j],v=ev[j];
				if(find(u)==find(v+(ew[j]+1)%3*n)) ok=0;
				if(find(u)==find(v+(ew[j]+2)%3*n)) ok=0;
				if(ok) for(int k=0;k<3;k++)
					merge(u+k*n,v+(k+ew[j])%3*n);
				if(!ok) mxv=max(mxv,j); 
			}
			if(ok) cnt++,id=i-1;
		}
		if(!cnt) puts("Impossible");
		else if(cnt>1) puts("Can not determine");
		else printf("Player %d can be determined to be the judge after %d lines\n",id,mxv);
	}
}