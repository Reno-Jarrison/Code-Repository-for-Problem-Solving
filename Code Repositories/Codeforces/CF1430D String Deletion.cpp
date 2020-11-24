#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int w[maxn],deq[maxn];
char s[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int cnt=0,las=-1,idx1=0,idx2=0;
		for(int i=1;i<=n;i++)
		{
			int cur=s[i]-'0';
			if(cur==las) cnt++;
			else
			{
				if(i>1)
				{
					w[++idx1]=cnt;
					if(cnt>1) deq[++idx2]=idx1;
				}
				cnt=1,las=cur;
			}
		}
		w[++idx1]=cnt;
		if(cnt>1) deq[++idx2]=idx1;	
		int ans=0,pt1=1,pt2=1;
		while(true)
		{
			ans++;
			while(pt2<=idx2&&(deq[pt2]<pt1||w[deq[pt2]]==1)) pt2++;
			if(pt2>idx2) pt1++;
			w[deq[pt2]]--,pt1++;
			if(pt1>idx1) break;
		}
		printf("%d\n",ans);
	}
}