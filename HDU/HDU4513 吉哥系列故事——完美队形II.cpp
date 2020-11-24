#include<iostream>
#define max(a,b) a>b?a:b
using namespace std;
int num[200005],p[400005];
int main()
{
	int t,n,j,k,temp;
	scanf("%d",&t);
	while(t--)
	{
		int maxr=0,mid=0,len=2,maxlen=0,temp;
		scanf("%d",&n);
		num[0]=-1,num[1]=0;
		for(int i=0;i<n;i++)
			scanf("%d",&num[len++]),num[len++]=0;
		num[len]=-2;
		for(int i=1;i<len;i++)
		{
			temp=num[i];
			if(!temp)
				temp=num[i-1];
			if(i<maxr) p[i]=min(p[(mid<<1)-i],maxr-i);
			else p[i]=1;
			while(num[i-p[i]]==num[i+p[i]]&&num[i-p[i]]<=temp)
				temp=num[i-p[i]]?num[i-p[i]]:temp,p[i]++;
			if(i+p[i]>maxr)
				maxr=i+p[i],mid=i;
			maxlen=max(maxlen,p[i]);
		}
		printf("%d\n",maxlen-1);
	}
 } 