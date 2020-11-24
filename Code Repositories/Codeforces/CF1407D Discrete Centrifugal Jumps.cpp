#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int h[maxn],dp[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	stack<int>stk1,stk2;
	for(int i=1;i<=n;i++)
	{
		dp[i]=(i>1?dp[i-1]+1:0);
		int ok1=1,ok2=1;
		while(!stk1.empty()&&h[stk1.top()]>=h[i])
		{
			dp[i]=min(dp[i],dp[stk1.top()]+1);
			if(h[i]==h[stk1.top()]) ok1=0;
			stk1.pop();
		}
		if(!stk1.empty()&&ok1) dp[i]=min(dp[i],dp[stk1.top()]+1);
		while(!stk2.empty()&&h[stk2.top()]<=h[i])
		{
			dp[i]=min(dp[i],dp[stk2.top()]+1);
			if(h[i]==h[stk2.top()]) ok2=0;
			stk2.pop();
		}
		if(!stk2.empty()&&ok2) dp[i]=min(dp[i],dp[stk2.top()]+1);
		stk1.push(i),stk2.push(i);
	}
	printf("%d\n",dp[n]);
}