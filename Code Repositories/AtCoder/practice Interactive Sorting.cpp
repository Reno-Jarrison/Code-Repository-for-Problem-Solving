#include<bits/stdc++.h>
using namespace std;
char s[3],ans[30];
int cmp[30][30];
bool cmpx(char x,char y)
{
	int a=x-'A',b=y-'A';
	if(cmp[a][b]!=-1) return cmp[a][b]; 
	printf("? %c %c\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	cmp[a][b]=s[0]=='>';
	cmp[b][a]=!cmp[a][b];
	return cmp[a][b];
}
void insert(int beg,int end,int x)
{
	for(int i=beg;i>end;i--)
		ans[i]=ans[i-1];
	ans[end]=x;
}
void solve(char x)
{
	if(cmpx(ans[1],x))
		cmpx(ans[0],x)?insert(4,0,x):insert(4,1,x);
	else cmpx(ans[2],x)?insert(4,2,x):insert(4,3,x);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	memset(cmp,-1,sizeof(cmp));
	if(n==26)
	{
		ans[0]='A';
		for(int i=1;i<26;i++)
		{
			int l=0,r=i-1,x='A'+i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(cmpx(ans[mid],x)) r=mid-1;
				else l=mid+1;
			}
			insert(i,l,x);
		}
	}
	else
	{
		for(int i=0;i<5;i++) ans[i]=i+'A';
		if(cmpx(ans[0],ans[1])) swap(ans[0],ans[1]);
		if(cmpx(ans[2],ans[3])) swap(ans[2],ans[3]);
		if(cmpx(ans[1],ans[3])) 
			swap(ans[0],ans[2]),swap(ans[1],ans[3]);
		char tmp=ans[2];
		if(cmpx(ans[1],ans[4]))
		{
			if(cmpx(ans[0],ans[4]))
				ans[2]=ans[1],ans[1]=ans[0],ans[0]=ans[4];
			else ans[2]=ans[1],ans[1]=ans[4];
		}
		else
		{
			if(cmpx(ans[3],ans[4])) ans[2]=ans[4];
			else ans[2]=ans[3],ans[3]=ans[4];
		}
		solve(tmp);
	}
	printf("! %s\n",ans);
	fflush(stdout);
}