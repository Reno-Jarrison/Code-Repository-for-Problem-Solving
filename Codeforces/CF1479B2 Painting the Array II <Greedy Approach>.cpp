#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],nxt[maxn],pos[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[i]=n+1;
	pos[0]=n+1;
	for(int i=n;~i;i--)
		nxt[i]=pos[a[i]],pos[a[i]]=i;
	int pt0=0,pt1=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[pt0]==a[i]) 
			pt0=i;
		else if(a[pt1]==a[i]) 
			pt1=i;
		else if(nxt[pt0]>=nxt[pt1])
			ans++,pt0=i;
		else
			ans++,pt1=i;
	}
	printf("%d\n",ans);
}