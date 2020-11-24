#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
struct node
{	int l,r; }p[maxn];
bool operator <(const node& x,const node& y)
{	
	if(x.l>x.r&&y.l<=y.r) return true;
	if(x.l>x.r&&y.l>y.r) return x.r<y.r;
	if(x.l<=x.r&&y.l>y.r) return false;
	if(x.l<=x.r&&y.l<=y.r) return x.l>y.l;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			int len=strlen(s),l=0,r=0;
			for(int j=0;j<len;j++)
			{
				if(s[j]=='(') l++;
				else if(l) ans+=2,l--;
				else r++;
			}
			p[i].l=l,p[i].r=r;
		}
		sort(p+1,p+n+1);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=min(cnt,p[i].r);
			ans+=tmp*2,cnt+=p[i].l-tmp;
		}
		printf("%d\n",ans);	
	}
}