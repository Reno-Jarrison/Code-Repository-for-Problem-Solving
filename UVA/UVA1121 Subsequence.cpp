#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,s;
	while(~scanf("%d%d",&n,&s))
	{
		int ans=n+1,sum=0;
		deque<int>deq;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum+=x;
			deq.push_front(x);
			while(sum-deq.back()>=s)
				sum-=deq.back(),deq.pop_back();
			if(sum>=s) ans=min(ans,(int)deq.size());
		}
		if(ans==n+1) ans=0;
		printf("%d\n",ans);
	}
}