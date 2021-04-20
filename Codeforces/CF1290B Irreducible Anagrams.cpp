#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int las[maxn][26];
int main()
{
	int n,q,l,r;
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			las[i][j]=las[i-1][j];
		las[i][s[i]-'a']=i;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		int cnt=0;
		for(int i=0;i<26;i++)
			if(las[r][i]>=l) cnt++;
		puts(l==r||(s[l]!=s[r]&&cnt>1)||cnt>2?"Yes":"No");
	}
}