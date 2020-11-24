#include<cstdio>
using namespace std;
int ans[20005][2];
int main()
{
	int k;
	while(~scanf("%d",&k))
	{
		int cnt=0;
		for(int y=k+1;y<=k*2;y++)
		{
			int x=1.0*k*y/(y-k)+0.5;
			if(k*(x+y)==x*y)
				ans[++cnt][0]=x,ans[cnt][1]=y;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,ans[i][0],ans[i][1]);
	}
}