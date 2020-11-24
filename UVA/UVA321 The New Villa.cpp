#include<bits/stdc++.h>
#define N 150
#define M 15
using namespace std;
bool vis[M][1<<M];
struct node
{
	node(){}
	node(int r,int l,string a):room(r),light(l),ans(a){}
	int light,room;
	string ans;
}; 
vector<int>e[N],l[N];
queue<node>q;
string solve;
inline void init()
{
	for(int i=1;i<=N;i++) 
		e[i].clear(),l[i].clear();
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
}
bool bfs(int end)
{
	int rpt,lpt,next,nextlt,len;
	string nexts,step;
	node start(1,1,"");
	vis[1][1]=1;
	q.push(start); 
	while(!q.empty())
	{
		node temp=q.front();
		rpt=temp.room,lpt=temp.light;
		step=temp.ans;
		q.pop();
		if(rpt==end&&lpt==1<<(end-1))
		{
			solve=step;
			return true;
		}
		len=e[rpt].size();
		for(int i=0;i<len;i++)
		{
			next=e[rpt][i];
			if(!vis[next][lpt]&&(lpt&(1<<(next-1))))
			{
				nexts=step+'m';
				nexts+=next;
				node nextpt(next,lpt,nexts);
				q.push(nextpt);
				vis[next][lpt]=1;
			}
		}
		len=l[rpt].size();
		for(int i=0;i<len;i++)
		{
			next=l[rpt][i],nextlt=lpt^(1<<(next-1));
			if(next==rpt||vis[rpt][nextlt]) continue;
			nexts=step;
			nexts+=(lpt&(1<<(next-1)))?'f':'n';
			nexts+=next;
			node nextpt(rpt,nextlt,nexts);
			q.push(nextpt);
			vis[rpt][nextlt]=1;
		}
	}
	return false;
}
int main()
{
	int r,d,s,a,b,cases=0;
	while(scanf("%d%d%d",&r,&d,&s)!=EOF)
	{
		if(!r&&!d&&!s) break;
		init();
		for(int i=0;i<d;i++)
			scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a); 
		for(int i=0;i<s;i++)
			scanf("%d%d",&a,&b),l[a].push_back(b); 
        for(int i=1;i<=d;i++)
            sort(e[i].begin(),e[i].end());
		for(int i=1;i<=s;i++)
            sort(l[i].begin(),l[i].end());
		printf("Villa #%d\n",++cases);
		if(bfs(r))
		{
			int len=solve.size();
			printf("The problem can be solved in %d steps:\n",len>>1);
			for(int i=0;i<len;i+=2)
			{
				if(solve[i]=='m') printf("- Move to room %d.\n",solve[i+1]); 
				if(solve[i]=='n') printf("- Switch on light in room %d.\n",solve[i+1]); 
				if(solve[i]=='f') printf("- Switch off light in room %d.\n",solve[i+1]); 
			}
		}
		else printf("The problem cannot be solved.\n");
		printf("\n");
	}
	return 0;
}