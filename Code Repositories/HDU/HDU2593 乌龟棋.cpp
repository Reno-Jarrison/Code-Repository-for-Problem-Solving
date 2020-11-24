#include<iostream>
using namespace std;
int score[355],card[5],dp[335][45][45][45];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,temp;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>score[i]; 
	for(int i=0;i<m;i++) cin>>temp,card[temp]++; 
	dp[0][0][0][0]=score[0];
	for(int step=1;step<n;step++)
	for(int b=0;b<=card[2];b++)
	for(int c=0;c<=card[3];c++)
	for(int d=0;d<=card[4];d++)
	{
		int a=step-(2*b+3*c+4*d);
		if(a<0||a>card[1]) continue;
		if(a) dp[step][b][c][d]=max(dp[step][b][c][d],dp[step-1][b][c][d]+score[step]);
		if(b&&step>1) dp[step][b][c][d]=max(dp[step][b][c][d],dp[step-2][b-1][c][d]+score[step]);
		if(c&&step>2) dp[step][b][c][d]=max(dp[step][b][c][d],dp[step-3][b][c-1][d]+score[step]);
		if(d&&step>3) dp[step][b][c][d]=max(dp[step][b][c][d],dp[step-4][b][c][d-1]+score[step]);
	}
	cout<<dp[n-1][card[2]][card[3]][card[4]];
}