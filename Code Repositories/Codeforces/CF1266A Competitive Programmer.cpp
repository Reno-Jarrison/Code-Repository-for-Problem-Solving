#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>(s+1);
		int n=strlen(s+1),ok=0;
		int cnt[2]={0},zero=0,mod3=0;
		for(int i=1;i<=n;i++)
		{
			int x=s[i]-'0';
			cnt[x&1]++;
			zero+=(!x);
			mod3=(mod3+x)%3;
		}
		if(zero==n) ok=1;
		if(zero&&!mod3&&cnt[0]>1) ok=1;
		puts(ok?"red":"cyan");
	}
}