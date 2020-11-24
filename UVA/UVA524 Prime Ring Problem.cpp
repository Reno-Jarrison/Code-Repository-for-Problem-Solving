#include<cstdio>
#include<vector>
using namespace std;
int p[15]={2,3,5,7,11,13,17,19,23,29,31},ans[20];
vector<int>s[20];
bool flag[20],isprime[35];
void dfs(int u,int step,int n)
{
	ans[step]=u;
	if(step==n)
	{
		if(isprime[u+1])
			for(int i=1;i<=n;i++)
				printf("%d%c",ans[i],i==n?'\n':' ');
		return;
	}
	int siz=s[u].size();
	for(int i=0;i<siz;i++)
		if(!flag[s[u][i]]&&s[u][i]<=n)
		{
			flag[s[u][i]]=true;
			dfs(s[u][i],step+1,n);
			flag[s[u][i]]=false;
		}
}
int main()
{
	int n,fst=1,ks=0;
	for(int i=0;i<=10;i++)
		isprime[p[i]]=true;
	for(int i=1;i<=16;i++)
		for(int j=0;j<=10;j++)
			if(i<p[j]&&p[j]-i<=16) s[i].push_back(p[j]-i);
	while(~scanf("%d",&n))
	{
		fst?fst=0:puts("");
		flag[1]=true;
		printf("Case %d:\n",++ks);
		dfs(1,1,n);
	}
}