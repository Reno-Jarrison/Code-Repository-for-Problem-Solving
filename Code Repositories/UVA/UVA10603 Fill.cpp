#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{	
	int a,b,c,d; 
	node(int a,int b,int c,int d):
		a(a),b(b),c(c),d(d){}
};
bool operator <(const node& x,const node& y)
{	return x.d>y.d; }
int tag[205][205][205],lim[3],d,des=-1,ans;
void pus(priority_queue<node>& q,int* t,int dis)
{	q.push(node(t[0],t[1],t[2],dis)); }
void dijstra()
{
	priority_queue<node>q;
	q.push(node(0,0,lim[2],0));
	while(!q.empty())
	{
		node u=q.top(); q.pop();
		if(tag[u.a][u.b][u.c]) continue;
		//printf("a %d %d %d %d\n",u.a,u.b,u.c,u.d);
		tag[u.a][u.b][u.c]=true;
		int tmp[3]={u.a,u.b,u.c};
		for(int i=0;i<3;i++)
			if(tmp[i]<=d&&tmp[i]>des) ans=u.d,des=tmp[i];
			else if(tmp[i]<=d&&tmp[i]==des) ans=min(ans,u.d);
		for(int i=0;i<3;i++)
		{
			if(!tmp[i]) continue;
			for(int j=1;j<=2;j++)
			{
				int id=(i+j)%3,p=min(tmp[i],lim[id]-tmp[id]);
				if(!p) continue;
				tmp[i]-=p,tmp[id]+=p;
				pus(q,tmp,u.d+p);
				tmp[i]+=p,tmp[id]-=p;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(tag,0,sizeof(tag)),des=-1;
		scanf("%d%d%d%d",&lim[0],&lim[1],&lim[2],&d);
		dijstra(),printf("%d %d\n",ans,des);
	}
}
