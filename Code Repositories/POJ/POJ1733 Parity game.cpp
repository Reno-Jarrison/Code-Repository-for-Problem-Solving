#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int q[maxn<<1],dct[maxn<<1],f[maxn];
char s[maxn][5];
bool w[maxn];
int find(int x)
{
	if(x!=f[x])
	{
		int rt=find(f[x]);
		w[x]^=w[f[x]];
		f[x]=rt;
	}
	return f[x];
}
int main()
{
	int n,m,x,y,i,uni;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%s",&q[i],&q[i+m],s[i]);
		dct[i]=--q[i],dct[i+m]=q[i+m];
	}
	sort(dct+1,dct+m*2+1);
	uni=unique(dct+1,dct+m*2+1)-dct-1;
	for(i=1;i<=uni;i++) f[i]=i;
	for(i=1;i<=m;i++)
	{
		x=lower_bound(dct+1,dct+uni+1,q[i])-dct;
		y=lower_bound(dct+1,dct+uni+1,q[i+m])-dct;
		int fx=find(x),fy=find(y),flag=(s[i][0]=='o');
		if(fx!=fy) f[fx]=fy,w[fx]=w[x]^w[y]^flag;
		else if(w[x]^w[y]^flag) break;
	}
	printf("%d",i-1);
}
