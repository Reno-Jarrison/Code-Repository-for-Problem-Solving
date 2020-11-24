#include<iostream>
#include<cstring>
#include<string>
#define lowbit(x) ((x)&(-x))
using namespace std;
int camp[50005];
void update(int pos,int max,int change)
{
	for(int i=pos;i<=max;i+=lowbit(i))
		camp[i]+=change;
}
int query(int pos)
{
	int sum=0;
	for(int i=pos;i;i-=lowbit(i))
		sum+=camp[i];
	return sum;
}
int main()
{
	int t,n,temp;
	string inst;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cout<<"Case "<<k+1<<':'<<endl;
		cin>>n;
		memset(camp,0,sizeof(camp));
		for(int i=1;i<=n;i++)
			cin>>temp,update(i,n,temp);
		while(cin>>inst&&inst!="End")
		{
			int i,j;
			cin>>i>>j;
			if(inst=="Add")
				update(i,n,j);
			else if(inst=="Sub")
				update(i,n,-j);
			else
				cout<<query(j)-query(i-1)<<endl;
		} 
	}
}