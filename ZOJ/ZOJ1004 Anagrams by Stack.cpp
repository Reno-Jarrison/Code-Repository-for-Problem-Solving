#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn],t[maxn],o[maxn*2];
int cnt[26][2];
stack<int>stk;
bool check()
{
	for(int i=0;i<26;i++)
		if(cnt[i][0]!=cnt[i][1]) return false;
	return true;
}
void dfs(int pt1,int pt2,int step,int len)
{
	if(pt2==len)
	{
		for(int i=0;i<step;i++)
			printf("%c ",o[i]);
		puts("");
		return;
	}
	if(pt1<len)
	{
		stk.push(s[pt1]),o[step]='i';
		dfs(pt1+1,pt2,step+1,len);
		stk.pop();
	}
	if(pt1>pt2&&stk.top()==t[pt2])
	{
		char cur=stk.top();
		stk.pop(),o[step]='o';
		dfs(pt1,pt2+1,step+1,len);
		stk.push(cur);
	}
}
int main()
{
	while(~scanf("%s%s",s,t))
	{
		int lens=strlen(s),lent=strlen(t);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<lens;i++)
			cnt[s[i]-'0'][0]++;
		for(int i=0;i<lent;i++)
			cnt[t[i]-'0'][1]++;
		puts("[");
		if(check())
			dfs(0,0,0,lens);
		puts("]");
	}
}