#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[4];
	while(~scanf("%s",s))
	{
		sort(s,s+3);
		for(int i=0;i<3;i++)
			printf("%c%c",s[i],i==2?'\n':' ');
	}
}