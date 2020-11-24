#include<cstdio>
#include<cstring>
#define ull unsigned long long
using namespace std;
const int maxn=3e4+5,base1=131,base2=139,mod=1e5+7;
ull hlist[maxn];
struct edge
{
	int nxt; ull val;
	edge(int nxt=0,ull val=0):nxt(nxt),val(val){}
}e[maxn];
int head[mod],cnt;
void init()
{	memset(head,-1,sizeof(head)),cnt=0; }
void add(int val1,ull val2)
{	e[cnt]=edge(head[val1],val2),head[val1]=cnt++; }
bool find(int val1,ull val2)
{
	for(int i=head[val1];~i;i=e[i].nxt)
		if(e[i].val==val2) return true;
	return false;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	char cmd[5],s[205];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",cmd);
		gets(s);
		int len=strlen(s);
		ull hval1=0,hval2=0;
		for(int i=0;i<len;i++)
			(hval1*=base1)+=s[i],(hval2*=base2)+=s[i];
		if(cmd[0]=='a') add(hval1%mod,hval2);	
		else printf(find(hval1%mod,hval2)?"yes\n":"no\n");
	}
}