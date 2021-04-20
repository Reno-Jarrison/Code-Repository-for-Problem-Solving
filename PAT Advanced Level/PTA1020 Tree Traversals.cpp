#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int post[maxn],in[maxn],lson[maxn],rson[maxn];
int solve(int l1,int r1,int l2,int r2)
{
	int mid1,mid2,rt;
	for(int i=l1;i<=r1;i++)
		if(in[i]==post[r2]) mid1=i,rt=in[i];
	mid2=l2+mid1-l1-1;
	if(mid1>l1) lson[rt]=solve(l1,mid1-1,l2,mid2);
	if(mid1<r1) rson[rt]=solve(mid1+1,r1,mid2+1,r2-1);
	return rt;
}
void bfs(int rt)
{
	queue<int>que;
	que.push(rt);
	while(!que.empty())
	{
		int cur=que.front(); que.pop();
		if(cur!=rt) putchar(' ');
		printf("%d",cur);
		if(lson[cur]) que.push(lson[cur]);
		if(rson[cur]) que.push(rson[cur]);
	}
	puts("");
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&post[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i]);
	int rt=solve(1,n,1,n);
	bfs(rt);
}