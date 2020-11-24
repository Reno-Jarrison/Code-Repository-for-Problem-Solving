#include<iostream>
#define ll long long
using namespace std;
ll x[100],y[100];
int log(ll x)
{
	int ans=0;
	while(x) ans++,x/=10;
	return ans;
}
int main()
{
	int cnt=0,ans=0;
	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	x[++cnt]=x0,y[cnt]=y0;
	while(true)
	{
		if(log(x0)+log(ax)>18) break;
		if(log(y0)+log(ay)>18) break;
		x0=ax*x0+bx;
		y0=ay*y0+by;
		x[++cnt]=x0,y[cnt]=y0;
	}
	for(int i=1;i<=cnt;i++)
	{
		int tot=0,tag=-1;
		ll tmp=0,idx=i,xn=xs,yn=ys;
		while(tmp<=t&&idx<=cnt)
		{
			tmp+=abs(x[idx]-xn)+abs(y[idx]-yn);
			if(tmp<=t) tot++;
			xn=x[idx],yn=y[idx];
			if(idx==1) tag=1,idx=i;
			idx+=tag;
		}
		ans=max(ans,tot);
	}
	cout<<ans;
}