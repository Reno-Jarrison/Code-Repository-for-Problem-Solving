#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
};
bool operator <(const node& a,const node& b)
{	return a.x<b.x||(a.x==b.x&&a.y<b.y); }
multiset<node>::iterator it;
int main()
{
	int t,n,x,y,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		multiset<node>st;
		printf("Case #%d:\n",++ks);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			node tmp(x,y);
			it=st.lower_bound(tmp);
			if(it==st.begin()||(--it)->y>y)
			{
				st.insert(tmp);
				it=st.upper_bound(tmp);
				while(it!=st.end()&&y<=it->y)
					st.erase(it++);
			}
			printf("%d\n",st.size());
		}
		if(t) puts("");
	}
}