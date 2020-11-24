#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int cnt[10],nxt[maxn][10];
char s[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>(s+1);
		int len=strlen(s+1),ans=0x3f3f3f3f;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=len;i++)
			cnt[s[i]-'0']++;
		for(int i=0;i<10;i++)
			nxt[len+1][i]=nxt[len+2][i]=len+1;
		for(int i=len;i;i--)
		{
			for(int j=0;j<10;j++)
				nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'0']=i;
		}
		for(int i=0;i<10;i++)
		{
			ans=min(ans,len-cnt[i]);
			for(int j=0;j<10;j++)
			{
				if(i==j) continue;
				int pt=0,tot=0;
				while(pt<=len)
				{
					pt=nxt[pt+1][i],pt=nxt[pt+1][j];
					if(pt<=len) tot++;
				}
				ans=min(ans,len-tot*2);
			}
		}
		cout<<ans<<endl;
	}	
}