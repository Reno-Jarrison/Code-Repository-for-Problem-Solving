#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
char s[maxn];
int num[10],ans[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		memset(num,0,sizeof(num));
		for(int i=0;i<len;i++)
			num[s[i]-'0']++;
		if(len-num[0]<=1) puts("Uncertain");
		else
		{
			int x=0,pt=0;
			for(int i=1;i<=9&&!x;i++)
				if(num[i]) num[i]--,x=i;
			for(int i=9;~i;i--)
				while(num[i]--) ans[++pt]=i;
			ans[pt]+=x,ans[0]=0;
			for(int i=pt;i;i--)
				ans[i-1]+=ans[i]/10,ans[i]%=10;
			for(int i=!ans[0];i<=pt;i++)
				putchar(ans[i]+'0');
			puts("");
		}
	}
}