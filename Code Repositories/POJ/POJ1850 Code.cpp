#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll cnt[12][27],sum[12];
int main()
{
	for(int i=1;i<=26;i++)
		cnt[1][i]=1,sum[1]++;
	for(int i=2;i<=10;i++)
		for(int j=1;j<=26;j++)
			for(int k=j+1;k<=26;k++)
				cnt[i][j]+=cnt[i-1][k],sum[i]+=cnt[i-1][k];
	for(int i=2;i<=12;i++)
		sum[i]+=sum[i-1];
	char s[12];
	scanf("%s",s+1);
	int n=strlen(s+1),las=0,ok=1;
	for(int i=2;ok&&i<=n;i++)
		if(s[i]<=s[i-1]) ok=0;
	if(!ok)
	{	puts("0"); return 0; }
	ll ans=sum[n-1];
	for(int i=1;i<=n;i++)
	{
		int cur=s[i]-'a'+1;
		for(int j=las;j<cur;j++)
			ans+=cnt[n-i+1][j];
		las=cur+1;
	}
	printf("%lld\n",ans+1);
}