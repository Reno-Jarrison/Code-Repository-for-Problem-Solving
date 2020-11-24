#include<cstdio>
using namespace std;
int ans[100],n,l,idx;
bool flag[100][30];
bool check(int n)
{
	bool ok=true;
	for(int i=1;i*2<=n;i++)
	{
		bool flag=false;
		for(int j=1;j<=i;j++)
			if(ans[n-j+1]!=ans[n-i-j+1])
				flag=true;
		ok&=flag;
	}
	return ok;
}
void dfs(int pos)
{
	if(idx>n) return;
	else if(idx==n)
	{
		for(int i=1;i<=pos;i++)
		{
			printf("%c",'A'+ans[i]);
			if(i%64==0&&i<pos) puts("");
			else if(i%4==0&&i<pos) putchar(' ');
		}
		printf("\n%d\n",pos);
	}
	for(int i=0;i<l;i++)
	{
		ans[pos+1]=i;
		if(check(pos+1)) idx++,dfs(pos+1);
	}
}
int main()
{
	while(scanf("%d%d",&n,&l)&&n&&l)
		idx=0,dfs(0); 
}