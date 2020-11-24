#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	char s[5][20];
	node(){	memset(s,' ',sizeof(s)); }
}base;
bool ok;
bool read()
{
	gets(base.s[0]);
	if(base.s[0][0]=='0') return false;
	for(int i=1;i<5;i++) gets(base.s[i]);
	return true;
}
node update(node tmp,int id)
{
	node ans=tmp;
	int x=id/3,y=id%3*2;
	ans.s[x][y+1]=ans.s[x][y+3]='_';
	ans.s[x+2][y+1]=ans.s[x+2][y+3]='_';
	ans.s[x+1][y]=ans.s[x+2][y]='|';
	ans.s[x+1][y+4]=ans.s[x+2][y+4]='|';
	ans.s[x+1][y+2]=ans.s[x+2][y+2]=' ';
	ans.s[x+1][y+1]=ans.s[x+1][y+3]=' ';
	return ans;
}
bool check(node x)
{
	for(int i=0;i<5;i++)
		for(int j=0;j<8;j++)
			if(x.s[i][j]!=base.s[i][j])
				return false;
	return true;
}
void dfs(node x,int step)
{
	if(step==6)
	{	if(check(x)) ok=true; return; }
	for(int i=0;i<9;i++)
		dfs(update(x,i),step+1);
}
int main()
{
	int ks=0;
	while(read())
	{
		ok=false;
		node newnode;
		dfs(newnode,0);
		printf("Case %d: %s\n",++ks,ok?"Yes":"No");
	}
}