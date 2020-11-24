#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
vector<char>ans[2];
char s[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans[0].clear(),ans[1].clear();
		scanf("%s",s);		
		int len=strlen(s);
		for(int i=0;i<len;i++)
			ans[(s[i]-'0')%2].push_back(s[i]);
		int pt1=0,pt2=0,siz1=ans[0].size(),siz2=ans[1].size();
		while(pt1<siz1&&pt2<siz2)
		{
			if(ans[0][pt1]<ans[1][pt2])
				putchar(ans[0][pt1++]);
			else putchar(ans[1][pt2++]);
		}
		while(pt1<siz1) putchar(ans[0][pt1++]);
		while(pt2<siz2) putchar(ans[1][pt2++]);
		puts("");
	}
}

