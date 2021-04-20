#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int pre[maxn];
struct node
{	int y,res; }p[maxn];
bool operator <(const node& a,const node& b)
{	return a.y<b.y; }
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&p[i].y,&p[i].res);
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++)
		pre[i]=pre[i-1]+p[i].res;
	int mxv=0,ans=0;
	p[0].y=p[m+1].y=-1;
	for(int i=m;i;i--)
	{
		if(p[i].y==p[i-1].y)
			continue;
		int cnt=pre[m]-pre[i-1]+i-pre[i-1];
		if(cnt>mxv) mxv=cnt,ans=p[i].y;
	}
	printf("%d\n",ans);
}