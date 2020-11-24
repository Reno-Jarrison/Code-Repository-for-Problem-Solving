#include<cstdio>
const int maxn=2e5+6;
using namespace std;
char s[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,ok=1;
		scanf("%d%s",&n,s+1);
		s[0]=s[n+1]=s[n+2]='P';
		for(int i=0;i<=n-2;i++)
		{
			if(s[i]=='C'&&s[i+1]=='C'&&s[i+2]=='P'&&s[i+3]=='C') ans++;
			if(ok&&s[i]=='C'&&s[i+1]=='C'&&s[i+2]=='P'&&s[i+3]!='C') ok=0,ans++;
			if(ok&&s[i]!='C'&&s[i+1]=='C'&&s[i+2]=='P'&&s[i+3]=='C') ok=0,ans++;
			if(ok&&s[i]=='C'&&s[i+1]=='C'&&s[i+2]=='C'&&(s[i+3]!='P'||s[i+4]!='C')) ok=0,ans++;
		}
		printf("%d\n",ans);
	}
}