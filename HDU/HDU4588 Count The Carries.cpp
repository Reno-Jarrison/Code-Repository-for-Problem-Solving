#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
ll ans[75];
void getans(int x,int flag)
{
	for(int i=1;i<=30;i++)
	{
		int bit=1<<(i-1);
		ans[i]+=1LL*(x>>i)*bit*flag;
		if(x&bit) ans[i]+=1LL*((x&((1<<i)-1))+1-bit)*flag;
	}
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		memset(ans,0,sizeof(ans));
		getans(b,1),getans(a-1,-1);
		ll res=0;
		for(int i=1;i<=70;i++)
			ans[i]>>=1,res+=ans[i],ans[i+1]+=ans[i];
		printf("%lld\n",res);
	}
}