#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int p[maxn],id[maxn];
int main()
{
	int t,n,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]),id[p[i]]=i;
		l=r=id[1];
		for(int i=1;i<=n;i++)
		{
			int ok=0;
			l=min(l,id[i]),r=max(r,id[i]);
			if(r-l+1==i) ok=1;
			printf("%d",ok);
		}
		puts("");
	}
}