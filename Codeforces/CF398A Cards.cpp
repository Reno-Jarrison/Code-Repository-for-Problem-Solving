#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mxv(ll num,ll tot)
{	return (tot-num+1)*(tot-num+1)+num-1; }
ll mnv(ll num,ll tot)
{
	ll q=tot/num;
	return (q+1)*(q+1)*(tot%num)+q*q*(num-tot%num);
}
int main()
{
	ll a,b,ans=-1e12,p=0,q=0;
	scanf("%lld%lld",&a,&b);
	if(a*b==0)
	{
		printf("%lld\n",a*a-b*b);
		for(int i=1;i<=a+b;i++)
			putchar(a?'o':'x');
		return 0;
	}
	for(int i=1;i<=min(a,b);i++)
	{
		if(mxv(i,a)-mnv(i,b)>ans)
			ans=mxv(i,a)-mnv(i,b),p=i,q=i;
		if(i<a&&mxv(i+1,a)-mnv(i,b)>ans)
			ans=mxv(i+1,a)-mnv(i,b),p=i+1,q=i;
		if(i<b&&mxv(i,a)-mnv(i+1,b)>ans)
			ans=mxv(i,a)-mnv(i+1,b),p=i,q=i+1;
	}
	printf("%lld\n",ans);
	vector<int>cnt[2];
	cnt[0].push_back(a-p+1);
	for(int i=1;i<=p-1;i++)
		cnt[0].push_back(1);
	for(int i=1;i<=b%q;i++)
		cnt[1].push_back(b/q+1);
	for(int i=1;i<=q-b%q;i++)
		cnt[1].push_back(b/q);
	int tag=cnt[1].size()>cnt[0].size(),pt[2]={0};
	while(pt[0]<p||pt[1]<q)
	{
		for(int i=1;i<=cnt[tag][pt[tag]];i++)
			putchar(tag?'x':'o');
		pt[tag]++,tag^=1;
	}
	puts("");
}