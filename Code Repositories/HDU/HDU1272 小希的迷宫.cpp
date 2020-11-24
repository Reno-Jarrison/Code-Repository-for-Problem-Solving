#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,lim=1e5;
int f[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
set<int>st;
int main()
{
	int u,v,ok=1;
	for(int i=1;i<=lim;i++) f[i]=i;
	while(true)
	{
		scanf("%d%d",&u,&v);
		if(u==-1) break;
		if(!u)
		{
			if(st.size())
			{
				int rt=find(*st.begin());
				for(int x:st) 
					if(find(x)!=rt) ok=0;
			}
			puts(ok?"Yes":"No");
			ok=1,st.clear();
			for(int i=1;i<=lim;i++) f[i]=i;
			continue;
		}
		st.insert(u),st.insert(v);
		int fu=find(u),fv=find(v);
		if(fu==fv) ok=0;
		else f[fu]=fv;
	}
}