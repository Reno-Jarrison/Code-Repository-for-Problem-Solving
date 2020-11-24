#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
char s[maxn];
ll key[30];
int add(int x)
{
	int cnt=0;
	while(x) cnt+=(x&1),x>>=1;
	return cnt;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			int len=strlen(s),cnt[26]={0};
			ll tmp=0;
			for(int j=0;j<len;j++)
				cnt[s[j]-'A']^=1;
			for(int j=0;j<26;j++)
				tmp<<=1,tmp|=cnt[j];
			key[i]=tmp;
		}
		map<ll,int>mp;
		int m=n>>1,ans=0,a=0,b=0;
		for(int i=0;i<(1<<m);i++)
		{
			ll tmp=0;	
			for(int j=0;j<m;j++)
				if(i&(1<<j)) tmp^=key[j];
			mp[tmp]=i;
		}
		for(int i=0;i<(1<<(n-m));i++)
		{
			ll tmp=0;
			for(int j=0;j<n-m;j++)
				if(i&(1<<j)) tmp^=key[j+m];
			if(mp.count(tmp)&&add(mp[tmp])+add(i)>ans)
				ans=add(mp[tmp])+add(i),a=mp[tmp],b=i;
		}
		printf("%d\n",ans);
		for(int i=0;i<m;i++,a>>=1)
			if(a&1) printf("%d ",i+1);
		for(int i=0;i<n-m;i++,b>>=1)
			if(b&1) printf("%d ",i+m+1);
		puts(""); 
	}
}