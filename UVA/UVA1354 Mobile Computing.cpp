#include<cstdio>
#include<algorithm>
using namespace std;
struct tree
{	double l,r; int w; }t[10];
int s,tag[10];
double ans,r;
void dfs(int step)
{
	if(step==s) for(int i=1;i<=s;i++)
		if(!tag[i]) 
		{
			double tmp=t[i].l+t[i].r;
			if(tmp<r&&ans<tmp) ans=tmp; 
		}
	for(int i=1;i<=s;i++) if(!tag[i])
		for(int j=1;j<=s;j++) if(!tag[j]&&i^j)
			{
				tree t1=t[i],t2=t[j],tmp;
				int a=t1.w,b=t2.w;
				tmp.l=max(t1.l+1.0*b/(a+b),t2.l-1.0*a/(a+b));
				tmp.r=max(t2.r+1.0*a/(a+b),t1.r-1.0*b/(a+b));
				if(tmp.l+tmp.r>=r) continue;
				tmp.w=a+b,t[i]=tmp,tag[j]=true;
				dfs(step+1),t[i]=t1,tag[j]=false;
			}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%d",&r,&s);
		for(int i=1;i<=s;i++)
			scanf("%d",&t[i].w);
		ans=-1,dfs(1);
		if(ans<0) puts("-1");
		else printf("%.10lf\n",ans);
	}
}