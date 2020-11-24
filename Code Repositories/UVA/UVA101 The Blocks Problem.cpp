#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int pos[25];
vector<int>v[25];
void pop(int x)
{
	int idx=pos[x],siz=v[idx].size();
	for(int i=siz-1;i>=0;i--)
	{
		int cur=v[idx][i];
		if(cur==x) break;
		v[idx].pop_back();
		v[cur].push_back(cur);
		pos[cur]=cur;
	}
}
void push(int x,int y)
{
	int idx=pos[x],idy=pos[y],siz=v[idx].size();
	stack<int>s;
	for(int i=siz-1;i>=0;i--)
	{
		int cur=v[idx][i];
		s.push(cur);
		v[idx].pop_back();
		pos[cur]=idy;
		if(cur==x) break;
	}
	while(!s.empty())
		v[idy].push_back(s.top()),s.pop();
}
int main()
{
	int n,a,b;
	char o1[5],o2[5];
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
		v[i].push_back(i),pos[i]=i;
	while(scanf("%s",o1)&&o1[0]!='q')
	{
		scanf("%d%s%d",&a,o2,&b);
		if(pos[a]==pos[b]) continue; 
		if(o1[0]=='m') pop(a);
		if(o2[1]=='n') pop(b);
		push(a,b);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		for(int j:v[i])
			printf(" %d",j);
		puts("");
	}
}