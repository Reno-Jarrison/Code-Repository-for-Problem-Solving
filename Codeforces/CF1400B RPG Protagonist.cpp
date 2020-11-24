#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,p,f,cs,cw,s,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&p,&f,&cs,&cw,&s,&w);
		int ans=0;
		if(s>w) swap(cs,cw),swap(s,w);
		for(int i=0;i<=min(cs,p/s);i++)
		{
			int resp=p-i*s,ress=cs-i,resw=cw-min(cw,resp/w),tmp=i+cw-resw;
			tmp+=min(ress,f/s)+min(resw,(f-min(ress,f/s)*s)/w);
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
} 