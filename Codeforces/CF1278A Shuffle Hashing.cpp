#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
char s[maxn],t[maxn];
int cnt[26],tmp[26];
bool check()
{
	for(int i=0;i<26;i++)
		if(cnt[i]!=tmp[i])
			return false;
	return true;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		int sn=strlen(s),tn=strlen(t),ok=0;
		memset(cnt,0,sizeof(cnt));
		memset(tmp,0,sizeof(tmp));
		if(sn<=tn)
		{
			for(int i=0;i<sn;i++) 
				cnt[s[i]-'a']++,tmp[t[i]-'a']++;			
			if(check()) ok=1;
			for(int i=sn;i<tn;i++)
			{
				tmp[t[i-sn]-'a']--;
				tmp[t[i]-'a']++;
				if(check()) ok=1;
			} 
		}
		puts(ok?"YES":"NO");
	}	
}