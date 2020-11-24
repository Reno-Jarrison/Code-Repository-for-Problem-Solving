#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int main()
{
	int t,n,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		if(n>1LL*x*y||n<x+y-1)
			puts("NO");
		else
		{
			puts("YES");
			vector<int>ans;
			int tmp=y>1?(n-x)/(y-1):0,res=n-x-(y-1)*tmp,pt=n+1;
			for(int i=1;i<=tmp;i++,pt-=y)
				for(int j=y;j;j--)
					ans.push_back(pt-j);
			if(tmp<x)
			{
				for(int i=res+1;i;i--)
					ans.push_back(pt-i);
				pt-=res+1;
				for(int i=tmp+2;i<=x;i++)
					ans.push_back(--pt);
			}
			reverse(ans.begin(),ans.end());
			for(int i=0;i<n;i++)
				printf("%d%c",ans[i],i==n-1?'\n':' ');
		}
	}
}