#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int p[maxn]; 
int main()
{
	int q,h,n;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&h,&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		int ans=0;
		if(n==2&&p[1]>2&&(p[1]==p[2]+1||p[2]>1)) ans=1; 
		else if(n>2)
		{
			int i=1;
			for(i=1;i<n-1;i++)
			{	
				if(p[i+1]==p[i+2]+1) i++;
				else ans++;
			}
			if(i==n-1&&p[i]>2&&(p[i]==p[i+1]+1||p[i+1]>1)) ans++;
		}
		printf("%d\n",ans);
	}
}

