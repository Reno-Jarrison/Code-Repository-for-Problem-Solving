#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=1e6+5;
int a[maxn],cnt[maxm]; 
int main()
{
	int t,n,k,d;
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d%d",&n,&k,&d);
		int ans=d,tmp=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=d;i++)
			if(!cnt[a[i]]++) tmp++;
		ans=min(ans,tmp);
		for(int i=d+1;i<=n;i++)
		{
			if(--cnt[a[i-d]]==0) tmp--;
			if(!cnt[a[i]]++) tmp++;
			ans=min(ans,tmp);	
		}
		printf("%d\n",ans);
	}
}

