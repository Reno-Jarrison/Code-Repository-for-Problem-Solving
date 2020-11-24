#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=505;
const double eps=1e-5;
struct node
{
	double vec[maxn];
	int cost,flag;
	friend bool operator <(const node& x,const node& y)
	{	return x.cost<y.cost; }
}a[maxn];
int idx[maxn];
bool cmp(int x,int y)
{	return a[x].flag<a[y].flag; }
int main()
{
	int n,m,cnt=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lf",&a[i].vec[j]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].cost);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt;j++) 
		{
			int id=idx[j],flag=a[id].flag;
			double tmp=a[i].vec[flag];
			for(int k=flag;k<=m;k++)
				a[i].vec[k]-=tmp*a[id].vec[k];
		}
		for(int j=1;j<=m;j++)
			if(fabs(a[i].vec[j])>=eps)
			{
				for(int k=j+1;k<=m;k++)
					a[i].vec[k]/=a[i].vec[j];
				a[i].vec[j]=1.0,a[i].flag=j;
				idx[++cnt]=i,ans+=a[i].cost;
				sort(idx+1,idx+cnt+1,cmp);
				break;
			}
	}
	printf("%d %d",cnt,ans);
}
 