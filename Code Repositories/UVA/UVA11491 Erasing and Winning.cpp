#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char str[maxn];
bool flag[maxn];
int main()
{
	int d,n;
	while(scanf("%d%d",&d,&n)&&d)
	{
		scanf("%s",str+1);
		memset(flag,0,sizeof(flag));
		stack<int>s;
		for(int i=1;i<=d&&n;i++)
		{
			while(!s.empty()&&n&&str[i]>str[s.top()])
				flag[s.top()]=true,s.pop(),n--;
			s.push(i);
		}
		int pt=d;
		while(n) 
		{
			if(!flag[pt]) flag[pt]=true,n--;
			pt--;
		}
		for(int i=1;i<=d;i++)
			if(!flag[i]) printf("%c",str[i]);
		puts("");
	}
}