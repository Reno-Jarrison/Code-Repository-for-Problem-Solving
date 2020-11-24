#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll h[maxn];
bool vis[maxn];
struct node
{
	int id;
	node(int id=0):id(id){}
};
bool operator <(const node& a,const node& b)
{	return h[a.id]<h[b.id]; }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		ll ans=0,sum=0;
		priority_queue<node>q;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&h[i]),sum+=h[i],vis[i]=true;
		for(int i=1;i<=n;i++)
			if(!vis[i<<1]&&!vis[i<<1|1]) q.push(node(i));
		bool flag=true;
		while(!q.empty())
		{
			node x=q.top(); q.pop();
			if(flag) ans+=h[x.id];
			flag^=1,vis[x.id]=false;
			int fat=x.id>>1;
			if(fat&&!vis[fat<<1]&&!vis[(fat<<1)|1]) 
				q.push(node(fat)),vis[fat]=true; 
		}	
		printf("%lld %lld\n",ans,sum-ans);
	}
}
