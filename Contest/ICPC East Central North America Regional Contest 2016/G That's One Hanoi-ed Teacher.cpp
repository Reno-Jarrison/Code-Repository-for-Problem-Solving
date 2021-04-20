#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pos[55];
int main()
{
	int num,x,n=0;
	for(int i=1;i<=3;i++)
	{
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
			scanf("%d",&x),n++,pos[x]=i;
	}
	ll ans=0;
	int s=1,m=2,t=3,ok=1;
	for(int i=n;i&&ok;i--)
	{
		if(pos[i]==m) ok=0;
		else if(pos[i]==s)
			swap(m,t);
		else if(pos[i]==t)
			swap(s,m),ans|=(1LL<<(i-1));
	}
	if(ok) printf("%lld\n",(1LL<<n)-1-ans);
	else puts("No");
}