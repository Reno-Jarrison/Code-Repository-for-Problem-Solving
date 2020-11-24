#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll fac[20],s[maxn];
int vis[20],perm[20];
void init(int n)
{
    fac[0]=1;
    for(int i=1;i<=15;i++)
        fac[i]=fac[i-1]*i;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+i;
}
void decantor(int n,ll rk)
{
    memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int cnt=rk/fac[n-i]+1,pt=1;
        for(int i=0;i<cnt;i++,pt++)
            while(vis[pt]) pt++;
        perm[i]=pt-1,vis[pt-1]=1;
		rk%=fac[n-i];
    }
}
int main()
{
	int n,q;
    ll rk=0;
    scanf("%d%d",&n,&q);
    init(n);
    while(q--)
    {
        int o,l,r,x;
        scanf("%d",&o);
        if(o==1)
        {
            scanf("%d%d",&l,&r);   
            int siz=min(n,15),pos=n-siz+1;
            decantor(siz,rk);
            for(int i=pos,j=1;i<=n&&j<=siz;i++,j++)
                s[i]=s[i-1]+perm[j]+n-siz;
            printf("%lld\n",s[r]-s[l-1]);
        }
        else scanf("%d",&x),rk+=x;
    }
}