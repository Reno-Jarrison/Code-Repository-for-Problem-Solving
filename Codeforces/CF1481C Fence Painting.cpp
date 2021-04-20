#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],ans[maxn],pos[maxn];
stack<int>res[maxn];
int main()
{
	int t,n,m,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		fill(pos+1,pos+n+1,0);
		for(int i=1;i<=n;i++)
			while(!res[i].empty())
				res[i].pop();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			pos[b[i]]=i;
			if(a[i]!=b[i])
				res[b[i]].push(i);
		}
		vector<int>buf;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&c);
			if(pos[c])
			{
				int cur=pos[c];
				if(!res[c].empty())
					cur=res[c].top(),res[c].pop(); 
				ans[i]=cur;
				for(int x:buf)
					ans[x]=cur;
				buf.clear();
			}
			else buf.push_back(i);
		}
		int ok=buf.empty();
		for(int i=1;i<=n;i++)
			ok&=res[i].empty();
		if(!ok) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=m;i++)
				printf("%d%c",ans[i],i==m?'\n':' ');
		}
	}
}