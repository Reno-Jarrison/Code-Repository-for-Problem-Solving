#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
string s,dp[maxn][maxn],init[3];
int key[128],t,ks;
int main()
{
	key['(']=-1,key[')']=1,init[1]="()";
	key['[']=-2,key[']']=2,init[2]="[]";
	string tmp(205,' ');
	cin>>t;
	getchar();
	while(t--)
	{
		getline(cin,s);
		getline(cin,s);
		s=" "+s;
		int n=s.size();
		for(int i=1;i<=n;i++)
			dp[i][i]=init[abs(key[s[i]])];
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				string &val=dp[l][r]; val=tmp;
				int ldx=key[s[l]],rdx=key[s[r]];
				if(ldx+rdx==0&&ldx<0)
				{
					if(rdx==1) val="("+dp[l+1][r-1]+")";
					else val="["+dp[l+1][r-1]+"]";
				}
				for(int k=l;k<r;k++)
					if(val.size()>dp[l][k].size()+dp[k+1][r].size())
						val=dp[l][k]+dp[k+1][r];
			}
		if(ks++) puts("");
		cout<<dp[1][n]<<endl;
	}
}