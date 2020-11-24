#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
int ans,n,g[6];
struct node
{
	int x[6];
	node(){	memset(x,0,sizeof(x)); }
}base;
bool check(node a,int step)
{
	for(int i=1;i<=5;i++)
		if((a.x[i]>>step)&base.x[i]) 
			return false;
	return true;
}
node update(node a,int step)
{
	node tmp;
	for(int i=1;i<=5;i++)
		tmp.x[i]=(a.x[i]>>step)|base.x[i];
	return tmp;
}
void dfs(node u,int t,int step,int mnv)
{
	if(t+mnv*(10-step)+n-1>=ans) return;
	if(step==10)
	{	ans=min(ans,t+n-1); return; }
	for(int i=1;i<=n;i++)
		if(check(u,i))
		{
			node v=update(u,i);
			dfs(v,t+i,step+1,min(i,mnv));
		}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		char s[25];
		for(int i=1;i<=5;i++)
		{
			scanf("%s",s),base.x[i]=0;
			for(int j=0;j<n;j++)
				if(s[j]=='X') base.x[i]|=1<<j;
		}
		ans=inf,dfs(base,1,1,n);
		printf("%d\n",ans);
	}
}
