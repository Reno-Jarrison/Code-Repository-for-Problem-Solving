#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int p[maxn];
set<int>st;
multiset<int>dif;
void solve()
{
	if(st.size()<2) 
	{	puts("0"); return; }
	int l=*st.begin(),r=*--st.end(),d=*--dif.end();
	printf("%d\n",r-l-d);
}
int main()
{
	int n,q,x,o;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		st.insert(p[i]);
	}
	sort(p+1,p+n+1);
	for(int i=2;i<=n;i++)
		dif.insert(p[i]-p[i-1]);
	solve();
	while(q--)
	{
		scanf("%d%d",&o,&x);
		if(o==1)
		{
			st.insert(x);
			auto it=st.find(x),pre=--st.find(x),suc=++st.find(x);
			if(it!=st.begin()&&suc!=st.end())
				dif.erase(dif.find(*suc-*pre));
			if(it!=st.begin())
				dif.insert(x-*pre);
			if(suc!=st.end())
				dif.insert(*suc-x);
		}
		else
		{
			auto it=st.find(x),pre=--st.find(x),suc=++st.find(x);
			if(it!=st.begin()&&suc!=st.end())
				dif.insert(*suc-*pre);
			if(it!=st.begin())
				dif.erase(dif.find(x-*pre));
			if(suc!=st.end())
				dif.erase(dif.find(*suc-x));
			st.erase(x);	
		}
		solve();
	}
}