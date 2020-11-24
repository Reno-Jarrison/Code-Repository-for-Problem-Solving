#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int w[26],psum[maxn],len;
int nxt[maxn],extend1[maxn],extend2[maxn];
char s1[maxn],s2[maxn];
void getnxt(char *s)
{
	nxt[0]=len;
	int p0=1,mx=0;
	while(s[mx]==s[mx+1]&&mx+1<len) mx++;
	nxt[1]=mx;
	for(int i=2;i<len;i++)
	{
		if(i+nxt[i-p0]<p0+nxt[p0]) nxt[i]=nxt[i-p0];
		else
		{
			mx=max(p0+nxt[p0]-i,0);
			while(s[mx]==s[i+mx]&&i+mx<len) mx++;
			nxt[i]=mx,p0=i;
		}
	}
}
void exkmp(char *p,char *t,int *extend)
{
	getnxt(p);
	int p0=0,mx=0;
	while(t[mx]==p[mx]) mx++;
	nxt[0]=mx;
	for(int i=1;i<len;i++)
	{
		if(i+nxt[i-p0]<p0+extend[p0]) extend[i]=nxt[i-p0];
		else
		{
			mx=max(p0+extend[p0]-i,0);
			while(t[i+mx]==p[mx]&&i+mx<len) mx++;
			extend[i]=mx,p0=i;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<26;i++)
			scanf("%d",&w[i]);
		scanf("%s",s1);
		len=strlen(s1);
		for(int i=0;i<len;i++)
		{
			psum[i]=(i?psum[i-1]:0)+w[s1[i]-'a'];
			s2[i]=s1[len-1-i];
		}
		exkmp(s2,s1,extend1);
		exkmp(s1,s2,extend2);
		int ans=0;
		for(int i=0;i<len;i++)
		{
			int tmp=0;
			if(i+extend1[i]==len)
				tmp+=psum[len-1]-(i?psum[i-1]:0);
			int j=len-i;
			if(j<len&&j+extend2[j]==len)
				tmp+=psum[i-1];
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
}