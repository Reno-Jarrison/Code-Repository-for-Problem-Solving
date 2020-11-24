#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ans[15];
bool ac[15];
int main()
{
	int t,n,m,id,min,sec,time;
	char s[5];
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0,penal=0;
		scanf("%d%d",&n,&m);
		memset(ac,0,sizeof(ac));
		memset(ans,0,sizeof(ans));
		while(m--)
		{
			scanf("%d",&id);
			scanf("%d:%d",&min,&sec);
			scanf("%s",s);
			id-=1000;
			if(s[0]=='A')
			{
				time=min*60+sec;
				if(!ac[id])
					ans[id]+=time,ac[id]=1,cnt++,penal+=ans[id];
			}
			else if(!ac[id])
				ans[id]+=20;
		}
		printf("%d %d\n",cnt,penal);
	}
} 