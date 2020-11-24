#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e4,maxm=2e3;
int cnt,prime[maxm],tot[maxm];
bool vis[maxn+5];
void getprime()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1;i*prime[j]<=maxn;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int getpfn(int x,int p)
{	return x?getpfn(x/p,p)+x/p:0; }
void update(int x,int flag)
{
	for(int i=1;i<=cnt&&prime[i]<=x;i++)
		tot[i]+=getpfn(x,prime[i])*flag;
}
double qpow(double a,int b)
{
	double ans=1.0;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a,b>>=1;
	}
	return ans;
}
int main()
{
	getprime();
	int t,p,q,r,s;
	while(~scanf("%d%d%d%d",&p,&q,&r,&s))
	{
		memset(tot,0,sizeof(tot));
		update(p,1),update(p-q,-1),update(q,-1);
		update(r,-1),update(r-s,1),update(s,1);
		double ans=1.0;	
		for(int i=1;i<=cnt;i++)
			if(tot[i]>0) ans*=qpow(prime[i],tot[i]);
			else if(tot[i]<0) ans/=qpow(prime[i],-tot[i]);
		printf("%.5lf\n",ans);
	}
}