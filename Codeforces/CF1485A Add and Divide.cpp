#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b)
{
	int ans=1e9;
	for(int i=0;i<=30;i++)
	{
		if(b+i==1) continue;
		int tmp=a,cnt=0;
		while(tmp) tmp/=(b+i),cnt++;
		ans=min(ans,cnt+i);
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",solve(a,b));
	}
}