#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ok=0;
		for(int i=0;!ok&&i*7<=n;i++)
			for(int j=0;!ok&&i*7+j*5<=n;j++)
			{
				int res=n-i*7-j*5;
				if(res%3==0) 
					printf("%d %d %d\n",res/3,j,i),ok=1;
			}
		if(!ok) puts("-1");
	}
}