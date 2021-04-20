#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[45][45],txt[20];
int len[25],cnt[25][26],buf[26],tag[45][45];
bool check(int id)
{
	for(int i=0;i<26;i++)
		if(cnt[id][i]!=buf[i])
			return false;
	return true;
}
int count(int x)
{
	int ans=0;
	while(x) ans+=x&1,x>>=1;
	return ans;
}
int main()
{
	int r,c,n;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		scanf("%s",s[i]+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",txt);
		len[i]=strlen(txt);
		for(int j=0;j<len[i];j++)
			cnt[i][txt[j]-'A']++;
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			for(int k=1;k<=n;k++)
			{
				memset(buf,0,sizeof(buf));
				int ok=1;
				for(int d=0;d<len[k];d++)
				{
					if(i+d>r) 
					{	ok=0; break; }
					buf[s[i+d][j]-'A']++;
				}
				if(ok&&check(k))
					for(int d=0;d<len[k];d++)
						tag[i+d][j]|=(1<<k);
				memset(buf,0,sizeof(buf)),ok=1;
				for(int d=0;d<len[k];d++)
				{
					if(j+d>c) 
					{	ok=0; break; }
					buf[s[i][j+d]-'A']++;
				}
				if(ok&&check(k))
					for(int d=0;d<len[k];d++)
						tag[i][j+d]|=(1<<k);
				memset(buf,0,sizeof(buf)),ok=1;
				for(int d=0;d<len[k];d++)
				{
					if(i+d>r||j+d>c) 
					{	ok=0; break; }
					buf[s[i+d][j+d]-'A']++;
				}
				if(ok&&check(k))
					for(int d=0;d<len[k];d++)
						tag[i+d][j+d]|=(1<<k);
				memset(buf,0,sizeof(buf)),ok=1;
				for(int d=0;d<len[k];d++)
				{
					if(i+d>r||j-d<1) 
					{	ok=0; break; }
					buf[s[i+d][j-d]-'A']++;
				}
				if(ok&&check(k))
					for(int d=0;d<len[k];d++)
						tag[i+d][j-d]|=(1<<k);
			}
	int ans=0;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			ans+=count(tag[i][j])>1;
	printf("%d\n",ans);
}