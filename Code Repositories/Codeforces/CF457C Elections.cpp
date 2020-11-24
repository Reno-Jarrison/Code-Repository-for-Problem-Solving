#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 100005
#define mlr mid=(left+right)>>1,lson=root<<1,rson=lson|1
using namespace std;
struct vote
{
	int id,num,cost;
	bool operator <(const vote &v)
		{ return cost<v.cost; }
}v[maxn],tempnode;
struct Node
{
	int sum,cnt;
}node[maxn<<2];
int n,ans=INT_MAX,costsum=0,myvote=0,temp,Rank[maxn],used[maxn];
vector<vote> cand[maxn];

bool cmp(int x,int y)
	{ return cand[x].size()>cand[y].size(); }
void build(int left,int right,int root)
{
	if(left==right)
		{ node[root].sum=v[left].cost,node[root].cnt=1; return; }
	int mlr;
	build(left,mid,lson);
	build(mid+1,right,rson);
	node[root].sum=node[lson].sum+node[rson].sum;
	node[root].cnt=node[lson].cnt+node[rson].cnt;
}
void update(int left,int right,int root,int id)
{
	if(left==right)
		{ node[root].cnt=node[root].sum=0; return; }
	int mlr;
	if(id<=mid)
		update(left,mid,lson,id);
	else
		update(mid+1,right,rson,id);
	node[root].sum=node[lson].sum+node[rson].sum;
	node[root].cnt=node[lson].cnt+node[rson].cnt;
}
int query(int left,int right,int root,int counter)
{
	if(node[root].cnt==counter)
		return node[root].sum;
	int mlr;
	if(node[lson].cnt>=counter)
		return query(left,mid,lson,counter);
	else
		return node[lson].sum+query(mid+1,right,rson,counter-node[lson].cnt);   //全部左子树+剩余数量的右子树（左<右） 
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&v[i].num,&v[i].cost);
	sort(v+1,v+n+1);             //将每一票按花费排序 
	for(int i=1;i<=n;i++)
		v[i].id=i;               //id表示每一票按花费从低向高的顺序 
	for(int i=1;i<=n;i++)
		cand[v[i].num].push_back(v[i]);       //相同选票被放入相同的vector里 
	for(int i=0;i<maxn;i++)
		Rank[i]=i;            //Rank按票数高低顺序存放cand序号 
	sort(Rank,Rank+maxn,cmp);
	build(1,n,1);               //按花费高低建线段树 
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<maxn;j++)         //从票数最高的候选人开始遍历 
		{
			int index=Rank[j]; 
			if(cand[index].size()-used[index]>=i)
			{
				tempnode=cand[index][used[index]];
				costsum+=tempnode.cost;
				update(1,n,1,tempnode.id);
				used[index]++;
				myvote++; 
			}
			else break;
		}
			temp=costsum;
			if(myvote<i)
				temp+=query(1,n,1,i-myvote);
			ans=min(ans,temp);
	}
	cout<<ans<<endl; 
}