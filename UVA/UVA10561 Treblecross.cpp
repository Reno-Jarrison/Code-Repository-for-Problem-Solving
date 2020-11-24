#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=205;
int sg[maxn],mex[maxn],vis[maxn];
char s[maxn];
vector<int>ans;
void getsg()
{	
	sg[0]=0,sg[1]=sg[2]=sg[3]=1;
	for(int i=4;i<=maxn-5;i++)
	{
		memset(mex,0,sizeof(mex));
		for(int j=3;j<=5;j++)
			if(i-j>=0) mex[sg[i-j]]=1;
		for(int j=1;i-j-5>=1;j++)
			mex[sg[j]^sg[i-j-5]]=1;
		for(int j=0;j<=maxn-5;j++)
			if(!mex[j]) { sg[i]=j; break; }
	}
}
void setvis(int x,int n)
{	if(x>=1&&x<=n) vis[x]=-1; }
int main()
{
	int t;
	getsg();
	scanf("%d",&t);
	while(t--)
	{
		ans.clear();
		memset(vis,0,sizeof(vis));
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			if(s[i]=='X') for(int j=-2;j<=2;j++) 
				setvis(i+j,len);
			if(i+2<=len&&s[i+1]=='X'&&s[i+2]=='X')
				ans.push_back(i);
			else if(i>2&&s[i-1]=='X'&&s[i-2]=='X')
				ans.push_back(i);
			else if(i>1&&i+1<=len&&s[i+1]=='X'&&s[i-1]=='X')
				ans.push_back(i);
		}
		if(ans.size()==0)
		{
			vis[0]=vis[len+1]=-1;
			int sum=0,tmp=0;
			for(int i=0;i<=len+1;i++)
			{
				if(vis[i]==-1)
				{
					for(int j=1;j<=tmp;j++) vis[i-j]=tmp;
					sum^=sg[tmp],tmp=0;
				}
				else tmp++;
			}
			if(!sum) { puts("LOSING\n"); continue; }
			for(int i=1;i<=len;i++)
				if(vis[i]>0)
				{
					int l=0,r=0,lpt=i-3,rpt=i+3;
					while(lpt>=1&&vis[lpt]==vis[i]) l++,lpt--;
					while(rpt<=len&&vis[rpt]==vis[i]) r++,rpt++;
					if((sum^sg[vis[i]]^sg[l]^sg[r])==0) ans.push_back(i);
				}
		}
		puts("WINNING");
		for(int i=0;i<(int)ans.size();i++)
			printf("%d%c",ans[i],i==(int)ans.size()-1?'\n':' ');
	}
}