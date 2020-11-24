#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node
{	int l,r; }p[maxn];
int ans[maxn];
bool operator <(const node& x,const node& y)
{	return x.l<y.l; }
set<int>st;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int i=1;i<=1e5;i++) st.insert(i);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&p[i].l,&p[i].r);
		sort(p+1,p+m+1);
		int l=1,r=1;
		for(int i=1;i<=m;i++)
		{
			while(r<p[i].l) ans[r++]=1;
			while(l<p[i].l) st.insert(ans[l++]);
			while(r<=p[i].r)
				ans[r]=*st.begin()++,st.erase(ans[r++]);
		}
		while(r<=n) ans[r++]=1;
		while(l<=n) st.insert(ans[l++]);
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
}