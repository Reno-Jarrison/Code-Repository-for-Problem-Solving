#include<bits/stdc++.h>
using namespace std;
char s[10][10],nxt[5]="ACGT";
int n,len[10],cur[10];
bool ida(int pos,int dep)
{
	bool ok=true;
	for(int i=1;i<=n;i++)
	{
		if(pos+len[i]-cur[i]>dep) return false;
		if(cur[i]<len[i]) ok=false;
	}
	if(ok) return true;
	for(int i=0;i<4;i++)
	{
		int tmp[10];
		memcpy(tmp,cur,sizeof(cur));
		for(int j=1;j<=n;j++)
			if(s[j][cur[j]]==nxt[i]) cur[j]++;
		if(ida(pos+1,dep)) return true;
		memcpy(cur,tmp,sizeof(cur));
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int dep=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
			dep=max(dep,len[i]);			
		}
		memset(cur,0,sizeof(cur));
		while(true)
		{
			if(ida(0,dep)) break;
			dep++;
		}
		printf("%d\n",dep);
	}
}