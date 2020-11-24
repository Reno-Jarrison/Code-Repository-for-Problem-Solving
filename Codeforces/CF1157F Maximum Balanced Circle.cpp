#include<iostream>
using namespace std;
int a[200005],vis[200005];
int main()
{
	int n,maxm=0,ans=0,cnt=0,minid=1,maxid=1,pt=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),vis[a[i]]++,maxm=max(a[i],maxm);
		for(int i=1;i<=maxm;i++)
		{
			if(vis[i]>1||vis[i-1]>1) 
			{
				if(vis[i-1]==0) pt=i;
				cnt+=vis[i];
			}
			else
			{
				if(vis[i]==1&&vis[i-1]==1&&vis[i-2]<=1) 
				{
					cnt++;
					if(ans<cnt) ans=cnt,minid=pt,maxid=i;
				}
				cnt=vis[i],pt=i;
			} 
			if(ans<cnt) ans=cnt,minid=pt,maxid=i;
		}
		printf("%d\n",ans);
	for(int i=minid;i<=maxid;i++)
		printf("%d ",i),vis[i]--;
	for(int i=maxid;i>=minid;i--)
		while(vis[i])
			printf("%d ",i),vis[i]--;
}