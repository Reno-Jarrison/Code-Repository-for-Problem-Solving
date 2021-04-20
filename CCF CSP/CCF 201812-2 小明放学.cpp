#include<bits/stdc++.h>
#define ll long long
using namespace std;
int res[4],nxt[4]={0,3,1,2};
int main()
{
	int n,k,t,tot=0;
	ll cur=0;
	for(int i=1;i<=3;i++)
		scanf("%d",&res[i]),tot+=res[i];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&k,&t);
		if(k==0) cur+=t;
		else
		{
			int tmp=(cur-t+tot)%tot;
			k=nxt[k];
			while(tmp>=res[k])
				tmp-=res[k],k=nxt[k];
			if(!tmp) tmp=res[k];
			if(k==1) cur+=res[1]-tmp;
			if(k==2) cur+=res[2]-tmp+res[1];
		}
	}
	printf("%lld\n",cur);
}