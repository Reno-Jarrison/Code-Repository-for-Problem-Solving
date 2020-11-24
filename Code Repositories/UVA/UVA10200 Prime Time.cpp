#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4;
const double eps=1e-9;
int sum[maxn+5];
bool check(ll x)
{
	for(int i=2;(ll)i*i<=x;i++)
		if(x%i==0) return false;
	return true; 
}
void getsum()
{
	sum[0]=1;
	for(int i=1;i<40;i++)
		sum[i]=sum[i-1]+1;
	for(int i=40;i<=maxn;i++)
	{
		sum[i]=sum[i-1];
		ll x=i*i+i+41;
		if(check(x)) sum[i]++;
	}
}
int main()
{
	getsum();
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		double ans=(double)(sum[b]-(a?sum[a-1]:0))/(double)(b-a+1);
		printf("%.2lf\n",(ans+eps)*100.0);
	}
}
