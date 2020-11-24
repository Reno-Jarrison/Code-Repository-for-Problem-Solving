#include<iostream>
using namespace std;
int a[1000005],b[10005];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		int nxt[10005]={-1};
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		int i=0,j=-1,flag=0;
		while(i<m)
			if(j==-1||b[i]==b[j])
				nxt[++i]=++j;
			else
				j=nxt[j];
		i=j=0;
		while(i<n)
		{
			if(j==-1||a[i]==b[j])
				i++,j++;
			else
				j=nxt[j];
			if(j==m)
				{ flag=i-j+1; break; }
		}
		if(flag)
			printf("%d\n",flag);
		else
			printf("-1\n");
	}
}