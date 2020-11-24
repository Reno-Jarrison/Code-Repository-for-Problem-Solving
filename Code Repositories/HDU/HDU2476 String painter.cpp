#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int dp1[maxn][maxn],dp2[maxn];
char a[maxn],b[maxn];
int main()
{
    while(cin>>(a+1)>>(b+1))
    {
        int n=strlen(a+1);
        for(int i=1;i<=n;i++) dp1[i][i]=1;
        for(int i=2;i<=n;i++) 
            for(int l=1,r=l+i-1;r<=n;l++,r++)
            {
                dp1[l][r]=dp1[l+1][r]+1;
                for(int k=l+1;k<=r;k++) if(b[l]==b[k])
                    dp1[l][r]=min(dp1[l][r],dp1[l+1][k-1]+dp1[k][r]);
            }
        for(int i=1;i<=n;i++)
        {
            dp2[i]=dp1[1][i];
            if(a[i]==b[i]) dp2[i]=dp2[i-1];
            else for(int j=1;j<i;j++)
                dp2[i]=min(dp2[i],dp2[j]+dp1[j+1][i]);
        }
        cout<<dp2[n]<<endl;
    }
}