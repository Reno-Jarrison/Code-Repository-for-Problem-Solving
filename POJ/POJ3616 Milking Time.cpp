#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
int w[maxn],tot[maxn],dp[maxn],ans;
vector<int>vec[maxn];
int main()
{
	int n,m,t,l,r;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&w[i]);
		tot[i]=r-l+1;
		vec[r].push_back(i);
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=0;j<vec[i].size();j++)
		{
			int id=vec[i][j],tmp=dp[i-tot[id]+1]+w[id];
			ans=max(tmp,ans);
			if(i+t<=n) dp[i+t]=max(dp[i+t],tmp);
		}
		if(vec[i].size()) vec[i].clear();
	}
	printf("%d\n",ans);
}