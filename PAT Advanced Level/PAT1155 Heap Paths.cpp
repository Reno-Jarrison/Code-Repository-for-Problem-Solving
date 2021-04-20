#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int heap[maxn],path[maxn],tag,n;
void dfs(int rt,int dep,int f)
{
	int lson=rt<<1,rson=lson|1,cur=heap[rt];
	path[dep]=cur;
	if(rt>1&&tag>0&&cur>f) tag=0;
	if(rt>1&&tag<0&&cur<f) tag=0;
	if(rson<=n) 
		dfs(rson,dep+1,cur);
	if(lson<=n) 
		dfs(lson,dep+1,cur);
	if(lson>n&&rson>n)
		for(int i=1;i<=dep;i++)
			printf("%d%c",path[i],i==dep?'\n':' ');
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	tag=heap[1]>heap[n]?1:-1;
	dfs(1,1,0);
	puts(tag?(tag>0?"Max Heap":"Min Heap"):"Not Heap");
}