#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int dp[201]={0,0,0,3,4,4,6,7};
int tmax(int a,int b,int c)
{
	return max(max(a,b),c);
}
int main()
{
	int t;
	cin>>t;
	for(int i=8;i<201;i++)
		dp[i]=tmax(dp[i-3]+3,dp[i-4]+4,dp[i-7]+7);
	while(t--)
	{
		int n;
		cin>>n;
		cout<<n-50*dp[n/50]<<endl;	
	}
} 