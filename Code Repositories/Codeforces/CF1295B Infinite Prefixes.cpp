#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int num[maxn],sum[maxn];
int main()
{
	int t,n,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>(s+1);
		int tot=0,ans=0,sum=0,ok=1;
		for(int i=1;i<=n;i++)
			num[i]=(s[i]=='0'?1:-1),tot+=num[i];
		if(!x) ans++;
		for(int i=1;i<=n&&ok;i++)
		{
			sum+=num[i];
			int tmp=x-sum;
			if(!tmp&&!tot) ok=0;
			else if(tot&&1LL*tmp*tot>=0&&tmp%tot==0) ans++;
		}
		if(!ok) ans=-1;
		printf("%d\n",ans);
	}
}