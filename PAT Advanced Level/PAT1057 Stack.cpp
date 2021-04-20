#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int stk[maxn];
int main()
{
	int n,x,top=0;
	scanf("%d",&n);
	multiset<int>st1,st2;
	for(int i=1;i<=n;i++)
	{
		char o[15];
		scanf("%s",o);
		if(!strcmp(o,"Pop"))
		{
			if(top)
			{
				int cur=stk[top--];
				if(cur<=*--st1.end())
					st1.erase(st1.find(cur));
				else st2.erase(st2.find(cur));
				printf("%d\n",cur);
			}
			else puts("Invalid");
		}
		else if(!strcmp(o,"PeekMedian"))
		{
			if(top) printf("%d\n",*--st1.end());
			else puts("Invalid");
		}
		else if(!strcmp(o,"Push"))
		{
			scanf("%d",&x),stk[++top]=x;
			if(!st1.size()||x<=*--st1.end()) 
				st1.insert(x);
			else st2.insert(x);
		}
		else puts("Invalid");
		if(st1.size()>st2.size()+1)
			st2.insert(*--st1.end()),st1.erase(--st1.end());
		if(st2.size()>st1.size())
			st1.insert(*st2.begin()),st2.erase(st2.begin());
	}
}