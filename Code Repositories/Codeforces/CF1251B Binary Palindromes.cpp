#include<bits/stdc++.h>
using namespace std;
char s[55];
int l[55];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int idx=0,ans=0,cnt[2]={0};
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			int len=strlen(s);
			if((len&1)==0) l[++idx]=len;
			for(int i=0;i<len;i++)
				cnt[s[i]-'0']++;
		}
		sort(l+1,l+idx+1);
		for(int j=1;j<=idx;j++)
		{
			int tmp=l[j]>>1,a,b;
			a=min(cnt[0]>>1,tmp),tmp-=a;
			b=min(cnt[1]>>1,tmp),tmp-=b;
			if(tmp==0) cnt[0]-=(a<<1),cnt[1]-=(b<<1),ans++;
			else break;			
		}
		printf("%d\n",ans+n-idx);
	}
}

