#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int id,pri;
	node() {}
	node(int i,int p):id(i),pri(p) {}
	bool operator <(const node &tnode) const
	{
		if(pri==tnode.pri)
			return id>tnode.id;
		return pri<tnode.pri;
	}
}; 
priority_queue<node>doc[3];
int main()
{
	ios::sync_with_stdio(false);
	int n,d,p,cnt;
	string event;
	while(cin>>n)
	{
		cnt=1;
		while(n--)
		{
			cin>>event>>d;
			if(event[0]=='I')
			{
				cin>>p;
				node temp(cnt++,p);
				doc[d-1].push(temp);
			}
			else 
			{
				if(doc[d-1].empty())
					cout<<"EMPTY"<<endl;
				else
				{
					node temp;
					temp=doc[d-1].top();
					cout<<temp.id<<endl;
					doc[d-1].pop();
				}
			}
		}
		for(int i=0;i<3;i++)
			while(!doc[i].empty())
				doc[i].pop();
	}
} 