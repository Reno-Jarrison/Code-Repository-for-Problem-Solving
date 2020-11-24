#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int l,s1,s2,t;
    scanf("%d%d%d",&l,&s1,&s2);
    double k=sqrt(2.0)/abs(s1-s2),q;
    scanf("%d",&t);
    while(t--)
        scanf("%lf",&q),printf("%.4lf\n",k*(l-sqrt(q)));
}