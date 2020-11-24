#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn=105;
struct node
{	int id; ll d; }p[maxn];
bool operator <(const node& x,const node& y)
{	return x.d<y.d; }
int main()
{
	int t,n;
	ll R,r,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%lld",&n,&R,&r);
		ll lim=R-2*r,las; lim*=lim;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x,&y);
			p[i].id=i,p[i].d=x*x+y*y;
		}
		sort(p+1,p+n+1);
		vector<int>ans;
		int ok=1,siz;
		ans.push_back(p[1].id),las=p[1].d;
		for(int i=2;i<=n&&ok;i++)
		{
			if(p[i].d==las||p[i].d<=lim) 
				ans.push_back(p[i].id);
			else ok=0;
			las=p[i].d;
		}
		sort(ans.begin(),ans.end()),siz=ans.size();
		printf("%d\n",siz);
		for(int i=0;i<siz;i++)
			printf("%d%c",ans[i],i==siz-1?'\n':' ');
	}
}