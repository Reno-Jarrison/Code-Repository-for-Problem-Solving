#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
char s[maxn];
int las[26];
int main()
{
	int t,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s),ans=inf;
		memset(las,-inf,sizeof(las));
		for(int i=0;i<n;i++)
		{
			int cur=s[i]-'a';
			ans=min(ans,i-las[cur]);
			las[cur]=i;
		}
		if(ans>=maxn) ans=-1;
		printf("Case #%d: %d\n",++ks,ans);
	}
}