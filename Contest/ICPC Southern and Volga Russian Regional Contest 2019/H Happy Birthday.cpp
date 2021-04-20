#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char ans[maxn],s[maxn];
int main()
{
	int t,c[10];
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<10;i++)
			scanf("%d",&c[i]);
		ans[0]='1';
		for(int i=1;i<=c[0]+1;i++) ans[i]='0';
		ans[c[0]+2]=0;
		for(int i=1;i<=9;i++)
		{
			for(int j=0;j<=c[i];j++) 
				s[j]='0'+i;
			s[c[i]+1]=0;
			if(strlen(s)>strlen(ans)) continue;
			if(strlen(s)<strlen(ans)||strcmp(s,ans)<0)
				strcpy(ans,s);
		}
		printf("%s\n",ans);
	}
}