#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,p,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		int sum=0,ans=0;
		set<int>st;
		st.insert(0);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum=(sum+x)%p;
			if(st.count(sum))
				st.clear(),ans++,sum=0;
			st.insert(sum);
		}
		printf("%d\n",ans);
	}
}