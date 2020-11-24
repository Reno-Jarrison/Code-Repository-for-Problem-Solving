#include<cstdio>
using namespace std;
int a[20];
int main()
{
	int t,tmp,x;
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0,num=0;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				scanf("%d",&tmp);
				if(!tmp) x=i;
				else 
				{
					a[++cnt]=tmp;
					for(int k=1;k<cnt;k++)
						a[k]>tmp?num++:false;
				}
			}
		printf((4-x+num)&1?"No\n":"Yes\n");
	}
}
