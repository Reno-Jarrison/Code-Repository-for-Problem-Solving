#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct point
{	int x,y; }p[maxn];
bool operator <(const point& a,const point& b)
{	return a.x<b.x; }
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1);
	int b1=p[1].y-p[1].x,b2=p[1].y+p[1].x;
	for(int i=2;i<=n;i++)
	{
		int x=p[i].x,y=p[i].y;
		int d1=abs(y-(x+b1)),d2=abs(y-(-x+b2));
		ans=max(ans,max(d1,d2));
		b1=max(b1,y-x),b2=min(b2,y+x);
	}
	printf("%d\n",ans);
}