#include<bits/stdc++.h>
#define inf 0x7fffffff
#define ll long long
using namespace std;
const int maxn=1e6+5;
bool vis1[maxn],vis2[maxn];
int main()
{
	ll l,r;
	while(scanf("%lld%lld",&l,&r)!=EOF)
	{
		int cnt=0,last=-1,maxm=0,minm=inf,maxid,minid;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		l=max(2LL,l);
		for(ll i=2;i*i<=r;i++)
		{
			for(ll j=2*i;j*j<=r;j+=i) vis1[j]=true;
			for(ll j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i)
				vis2[j-l]=true;
		}
		for(int i=0;i<=r-l;i++)
			if(!vis2[i])
			{
				if(last!=-1)
				{
					i-last+l>maxm?maxm=i-last+l,maxid=last:0;
					i-last+l<minm?minm=i-last+l,minid=last:0;
				}
				last=i+l,cnt++;
			}
		if(cnt<2) printf("There are no adjacent primes.\n");
		else printf("%d,%d are closest, %d,%d are most distant.\n",minid,minid+minm,maxid,maxid+maxm);
	}
}