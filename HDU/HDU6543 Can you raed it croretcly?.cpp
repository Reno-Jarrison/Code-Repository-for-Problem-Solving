#include<bits/stdc++.h>
using namespace std;
int cnt[2][26];
int main()
{
	char s1[25],s2[25];
	while(~scanf("%s%s",s1,s2))
	{
		int len1=strlen(s1),len2=strlen(s2);
		if(len1!=len2)
		{	puts("No"); continue; }
		int n=len1,ok=2;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			if(s1[i]!=s2[i]) ok=1;
			cnt[0][s1[i]-'a']++,cnt[1][s2[i]-'a']++;
		}
		for(int i=0;i<26;i++)
			if(cnt[0][i]!=cnt[1][i]) ok=0;
		if(s1[0]!=s2[0]||s1[n-1]!=s2[n-1]) ok=0; 
		puts(ok?(ok==1?"Yes":"Equal"):"No");
	}
}