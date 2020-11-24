#include<iostream>
#define ll long long
using namespace std;
ll num[100005];
ll query(int l1,int r1,int l2,int r2,int len)
{
	if(r1<l2)
	{
		if(len<=r1-l1+1) return num[l1+len-1];
		else return num[l2+len-r1+l1-2];
	}
	else if(r1>r2)
	{
		if(len<=l2-l1) return num[l1+len-1];
		else if(len>r2*2-l1-l2+2) return num[len-r2+l1+l2-2];
		else return num[l2+((len-l2+l1-1)>>1)];
	}
	else
	{
		if(len<=l2-l1) return num[l1+len-1];
		else if(len>r1*2-l1-l2+2) return num[len-r1+l1+l2-2];
		else return num[l2+((len-l2+l1-1)>>1)];
	}
}
int main()
{
	int t,n,m,l1,l2,r1,r2,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m); 
		for(int i=1;i<=n;i++)
			scanf("%lld",&num[i]);
		while(m--)
		{
			double mid;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			if(l1>l2) 
				l1^=l2^=l1^=l2,r1^=r2^=r1^=r2;
			len=r1-l1+r2-l2+2;
			if(len&1) mid=query(l1,r1,l2,r2,(len>>1)+1);
			else mid=(query(l1,r1,l2,r2,len>>1)+query(l1,r1,l2,r2,(len>>1)+1))/2.0;
			printf("%.1lf\n",mid);
		}
	}
} 