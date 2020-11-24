#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+5;
int t[maxn][2],s[maxn<<1],tp;
bool flag[maxn<<1];
vector<int>e[maxn<<1];
void link(int u,int a,int v,int b)
{
	int x=u*2+a,y=v*2+b;
	e[x].push_back(y^1);
	e[y].push_back(x^1);
}
bool dfs(int u)
{
	if(flag[u^1]) return false;
	if(flag[u]) return true;
	flag[s[++tp]=u]=true;
	for(int i=0;i<(int)e[u].size();i++)
		if(!dfs(e[u][i])) return false;
	return true;
}
bool twosat(int n)
{
	memset(flag,0,sizeof(flag));
	for(int i=2;i<=n<<1;i+=2)
		if(!flag[i]&&!flag[i+1])
		{
			tp=0;
			if(dfs(i)) continue;
			while(tp) flag[s[tp--]]=false;
			if(!dfs(i+1)) return false;
		}
	return true;
}
bool check(int mval,int n)
{
	for(int i=1;i<=n;i++) 
		e[i<<1].clear(),e[i<<1|1].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			for(int k1=0;k1<=1;k1++)
				for(int k2=0;k2<=1;k2++)
			if(abs(t[i][k1]-t[j][k2])<mval)
				link(i,k1,j,k2);
		}
	return twosat(n);
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int mxv=0,mnv=1e7;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&t[i][0],&t[i][1]);
			mxv=max(mxv,t[i][1]);
			mnv=min(mnv,t[i][0]);
		}
		int l=0,r=mxv-mnv,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			check(mid,n)?l=mid+1:r=mid-1;
		}
		printf("%d\n",r);
	}
}