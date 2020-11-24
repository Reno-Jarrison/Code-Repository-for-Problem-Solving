#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=4005;
int cnt,vis[maxn],p[maxn],p2[maxn];
ll qr()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
inline ll qpow(ll a,int b)
{
	ll ans=1;
	while(b--) ans*=a; 
	return ans;
}
bool check(ll n,int k)
{
	ll tmp=pow(n,1.0/k)-4;
	tmp<1?tmp=1:false; 
	while(qpow(tmp+1,k)<=n) tmp++;
	return qpow(tmp,k)==n;
}
int main()
{
	for(register int i=2;i<=maxn-5;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(register int j=1;j<=cnt&&p[j]*i<=maxn-5;j++)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0) break;
		}
	}
	int t,flag;
	ll n;
	scanf("%d",&t);
	while(t--)
	{
		n=qr(),flag=80;
		for(register int i=1;i<=cnt&&n>=p[i];i++)
			if(n%p[i]==0)
			{
				int tot=0;
				while(n%p[i]==0) n/=p[i],tot++;
				flag=min(flag,tot);
				if(tot==1) break;
			}
		if(flag>1&&n>1)
		{
			bool vis=false;
			for(int i=4;i>=2;i--)
				if(check(n,i))
				{	flag=min(flag,i),vis=true; break; }
			!vis?flag=1:false;
		}
		printf("%d\n",flag);
	}
}
