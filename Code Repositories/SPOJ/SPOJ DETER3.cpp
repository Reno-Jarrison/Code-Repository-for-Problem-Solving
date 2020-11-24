#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=205;
ll mat[maxn][maxn];
ll det(int n,int p)
{
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			while(mat[j][i])
			{
				ll t=mat[i][i]/mat[j][i];
				for(int k=i;k<=n;k++)
				{
					mat[i][k]=(mat[i][k]-mat[j][k]*t%p+p)%p;
					swap(mat[i][k],mat[j][k]);
				}
				ans=(p-ans)%p;
			}
		ans=ans*mat[i][i]%p;
	}
	return ans;
}
int main()
{
	int n,p,x;
	while(~scanf("%d%d",&n,&p))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&x),mat[i][j]=(x%p+p)%p;
		printf("%lld\n",det(n,p));
	}
}