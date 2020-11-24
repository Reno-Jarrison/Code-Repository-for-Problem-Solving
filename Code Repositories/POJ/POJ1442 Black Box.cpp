#include<iostream>
#include<queue> 
#define maxn 30005
using namespace std;
int add[maxn],get[maxn],t=1;
priority_queue< int,vector<int>,less<int> >maxq;
priority_queue< int,vector<int>,greater<int> >minq;
void insert(int x)
{
	if(!maxq.empty()&&maxq.top()>x)
		minq.push(maxq.top()),maxq.pop(),maxq.push(x);
	else minq.push(x);  
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(register int i=1;i<=m;i++)
		scanf("%d",&add[i]);
	for(register int i=1;i<=n;i++)
		scanf("%d",&get[i]);
	for(register int i=1;i<=m;i++)
	{
		insert(add[i]);
		while(get[t]==i)
		{
			maxq.push(minq.top()),minq.pop();
			cout<<maxq.top()<<endl,t++;
		}
	}
} 