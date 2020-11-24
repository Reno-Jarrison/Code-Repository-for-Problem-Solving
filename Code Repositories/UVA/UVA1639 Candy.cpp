#include<cstdio>
#include<cmath>
#define ld long double
using namespace std;
const int maxn=4e5;
ld lnf[maxn+5];
void getlnf()
{
    for(int i=1;i<=maxn;i++)
        lnf[i]=lnf[i-1]+log(i);
}
ld lnc(int m,int n)
{   return lnf[m]-lnf[n]-lnf[m-n]; }
int main()
{
    getlnf();
    int n,cases=0;
    ld p,q,pow1,pow2;
    while(~scanf("%d%Lf",&n,&p))
    {
        q=1.0-p;
        ld ans=0;
        for(int i=1;i<=n;i++)
        {
            pow1=lnc(2*n-i,n)+(n+1)*log(p)+(n-i)*log(q);
            pow2=lnc(2*n-i,n)+(n+1)*log(q)+(n-i)*log(p);
            ans+=(exp(pow1)+exp(pow2))*i;
        }
        printf("Case %d: %.6Lf\n",++cases,ans);
    }    
}