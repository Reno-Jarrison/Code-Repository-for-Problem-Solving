#include<iostream>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
int g[30][30],dist[30],ans,minm,n;
bool flag[30];
void prim(int index)
{
	flag[index]=0;
	for(int i=0;i<n;i++)
		dist[i]=g[index][i];
	while(1)
	{
		index=-1,minm=inf;
		for(int i=0;i<n;i++)
			if(flag[i]&&dist[i]<minm)
				minm=dist[i],index=i;
		if(index!=-1)
		{
			flag[index]=0;
			ans+=dist[index];
			for(int i=0;i<n;i++)
			dist[i]=min(dist[i],g[index][i]);
		}
		else break;
	}
	
}
int main()
{
	int num,cost,tail,front;
	char s[10];
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		memset(g,0x3f,sizeof(g));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<n;i++)
		{
			scanf("%s",s);
			tail=s[0]-'A';
			scanf("%d",&num);
			while(num--)
			{
				scanf("%s",&s);
				front=s[0]-'A';
				scanf("%d",&cost);
				if(cost<g[tail][front])
					g[tail][front]=g[front][tail]=cost;
				flag[tail]=flag[front]=1;
			}
		}
		for(int i=0;i<n;i++)
			if(flag[i]) { prim(i); break; }
		printf("%d\n",ans);
	}
}