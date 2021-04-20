#include<bits/stdc++.h>
using namespace std;
int h[105];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		int pos;
		while(k--)
		{
			pos=-1;
			for(int i=1;i<n&&pos==-1;i++)
				if(h[i]<h[i+1])
					h[i]++,pos=i;
			if(pos==-1) break; 
		}
		printf("%d\n",pos);
	}
}