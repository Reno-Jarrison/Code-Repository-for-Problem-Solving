#include<bits/stdc++.h>
using namespace std;
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a,b>>=1;
	}
	return ans;
}
int main()
{
	int t,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=3) ans=qpow(26,n);
		else ans=26*25*24;
		printf("%d\n",ans);
	}
}