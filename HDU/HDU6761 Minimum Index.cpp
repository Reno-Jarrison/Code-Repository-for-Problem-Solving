#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5,mod=1e9+7;
char s[maxn];
int pos[maxn],len;
ll duval(char *s)
{
	ll ans=0;
	len=strlen(s);
	int i=0,j=0,k=1;
	pos[0]=1;
	for(int pt=1;pt<len;pt++)
	{
		if(s[pt]==s[j])
		{
			pos[pt]=pt-j+pos[j],j++;
			if(j==k) j=i;
		}
		else if(s[pt]>s[j])
			j=i,k=pt+1,pos[pt]=j+1;
		else
		{
			int tot=k-i;
			i+=(pt-i)/tot*tot;
			pt=j=i,k=i+1;
			pos[pt]=i+1;
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		duval(s);
		ll ans=0;
		for(int i=len-1;~i;i--) ans=(ans*1112+pos[i])%mod;
		printf("%lld\n",ans);
	}
}