#include<iostream>
#include<string>
using namespace std;
#define Maxn 3000
int cost[128],dp[Maxn][Maxn];
int main()
{
	int n,m,add,del,len;
	char alp;
	string s;
	cin>>n>>m>>s;
	while(n--)
		cin>>alp>>add>>del,cost[int(alp)]=min(add,del);
	len=s.size();
	for(int l=0;l<len;l++)
		for(int i=0,j=l;j<len;i++,j++)
		{
			dp[i][j]=INT_MAX;
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1];
			else
			{
				dp[i][j]=min(dp[i][j],dp[i+1][j]+cost[s[i]]);
				dp[i][j]=min(dp[i][j],dp[i][j-1]+cost[s[j]]);
			}
		}
	cout<<dp[0][len-1]<<endl;
}