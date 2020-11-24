#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5,inf=2e9;
ll a[maxn],stk[maxn];
int main()
{

    int n,k,x;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    a[0]=-inf,a[n+1]=inf;
    vector<int>id(1,0);
    for(int i=1;i<=k;i++)
        scanf("%d",&x),id.push_back(x);
    id.push_back(n+1);
    int ok=1,ans=0;
    for(int i=1;ok&&i<=k+1;i++)
    {
        int lid=id[i-1],rid=id[i],idx=0;
        ll l=a[lid],r=a[rid];
        if(r-l<rid-lid) ok=0;
        for(int j=lid+1;j<=rid-1;j++)
        {
            if(r-a[j]<rid-j||a[j]-l<j-lid) 
                continue;
            int pt=upper_bound(stk+1,stk+idx+1,a[j]-j)-stk;
            if(pt>idx) idx++;
            stk[pt]=a[j]-j;
        }
        ans+=rid-lid-1-idx;
    }

    if(!ok) ans=-1;
    printf("%d\n",ans);
}