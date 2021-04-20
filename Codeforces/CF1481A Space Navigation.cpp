#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int cnt[128];
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&x,&y,s);
		int len=strlen(s);
		cnt['L']=cnt['R']=cnt['U']=cnt['D']=0;
		for(int i=0;i<len;i++)
			cnt[(int)s[i]]++;
		if(x<0) swap(cnt['L'],cnt['R']),x=-x;
		if(y<0) swap(cnt['U'],cnt['D']),y=-y;
		puts(cnt['R']>=x&&cnt['U']>=y?"YES":"NO");
	}
}