#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
string dp[maxn][maxn],emt="",inf(200,' ');
string tonum(int x)
{
	if(!x) return emt;
	return tonum(x/10)+(char)(x%10+'0');
}
bool check(int l,int r,int k)
{
	int pt=l;
	for(int i=l;i<=r;i++,pt++)
	{
		if(s[i]!=s[pt]) return false;
		if(pt==k) pt=l-1;
	}
	return true;
}
int main()
{
	while(~scanf("%s",s+1))
	{
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
			dp[i][i]=emt+s[i];
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				string &val=dp[l][r];
				val=inf;
				for(int k=l;k<r;k++)
				{
					if(val.size()>dp[l][k].size()+dp[k+1][r].size())
						dp[l][r]=dp[l][k]+dp[k+1][r];
					if(i%(k-l+1)==0&&check(l,r,k))
					{
						string tmp=tonum(i/(k-l+1))+"("+dp[l][k]+")";
						if(tmp.size()<val.size()) val=tmp;
					}
				}
			}
		cout<<dp[1][n]<<endl;
	}
}