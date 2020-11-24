#include<iostream>
#define lowbit(x) ((x)&(-x))
#define maxn 32005
using namespace std;
int star[32005],level[15005];
void update(int pos)
{
	while(pos<=maxn)
		star[pos]++,pos+=lowbit(pos);
}
int query(int pos)
{
	int sum=0;
	while(pos)
		sum+=star[pos],pos-=lowbit(pos);
	return sum;
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x,&y),level[query(++x)]++,update(x);
	for(int i=0;i<n;i++)
		cout<<level[i]<<endl;
} 