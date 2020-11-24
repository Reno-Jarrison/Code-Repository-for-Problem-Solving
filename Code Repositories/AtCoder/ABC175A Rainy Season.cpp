#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[5];
	scanf("%s",s),s[3]='S';
	int cur=0,ans=0;
	for(int i=0;i<=3;i++)
	{
		if(s[i]=='R') cur++;
		else ans=max(ans,cur),cur=0;
	}
	printf("%d",ans);
}