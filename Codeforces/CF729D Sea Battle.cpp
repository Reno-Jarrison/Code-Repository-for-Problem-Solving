#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	int n,a,b,k,cur=0;
	scanf("%d%d%d%d%s",&n,&a,&b,&k,s+1);
	vector<int>pos;
	for(int i=1;i<b;i++)
		if(s[i]=='1') cur++;
	for(int i=b;i<=n;i++)
	{
		cur+=s[i]=='1';
		if(!cur)
		{
			s[i]='1',cur++;
			if(a==1)
				pos.push_back(i);
			else a--;
		} 
		cur-=s[i-b+1]=='1';
	}
	printf("%d\n",(int)pos.size());
	for(int x:pos)
		printf("%d ",x);
}