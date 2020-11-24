#include<cstdio>
#define ll long long
#define mod 1000003
#define maxn mod+5
using namespace std;
ll ans[maxn]={1};
int main()
{
	int n;
	for(ll i=1;i<mod;i++) ans[i]=ans[i-1]*i%mod;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",n<mod?ans[n]:0);
}
