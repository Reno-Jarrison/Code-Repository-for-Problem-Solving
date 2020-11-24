#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+5;
int a[maxn];
int main()
{
	int t,n,m,k,p,q,r,mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]);
		for(int i=k+1;i<=n;i++)
			a[i]=(1LL*p*a[i-1]+1LL*q*i+r)%mod;
		ll ans1=0,ans2=0;
		deque<int>que1,que2;
		for(int i=1;i<=n;i++)
		{
			if(!que1.empty()&&que1.front()+m-1<i) que1.pop_front();
			while(!que1.empty()&&a[i]>=a[que1.back()]) 
				que1.pop_back();
			que1.push_back(i);
			if(i>=m) ans1+=a[que1.front()]^(i-m+1);
		}
		for(int i=n;i;i--)
		{
			if(!que2.empty()&&que2.front()>i+m-1) que2.pop_front();
			while(!que2.empty()&&a[i]>=a[que2.back()]) 
				que2.pop_back();
			que2.push_back(i);
			if(i<=n-m+1) ans2+=que2.size()^i;
		}
		printf("%lld %lld\n",ans1,ans2);
	}
}