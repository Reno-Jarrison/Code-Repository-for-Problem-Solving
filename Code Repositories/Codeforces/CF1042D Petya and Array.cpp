#include<iostream>
#include<algorithm>
#define maxn 200005
#define lowbit(x) ((x)&(-x))
using namespace std;
int n;
long long sum[maxn],num[maxn],tree[maxn];
void update(int pos)
{
	while(pos<=n+1)
		tree[pos]++,pos+=lowbit(pos);
}
long long query(int pos)
{
	long long sum=0;
	while(pos)
		sum+=tree[pos],pos-=lowbit(pos);
	return sum;
}
int main()
{
	long long t,sumt=0;
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%lld",&sum[i]),sum[i]+=sum[i-1],num[i]=sum[i];
	sort(num,num+n+1);
	for(int i=1;i<=n;i++)
	{
		update(lower_bound(num,num+n+1,sum[i-1])-num+1);
		sumt+=i-query(upper_bound(num,num+n+1,sum[i]-t)-num);
	}
	printf("%lld",sumt);
}