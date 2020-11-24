#include<cstdio>
#include<cstring>
using namespace std;
char s[105];
int main()
{
	while(~scanf("%s",s))
	{
		int len=strlen(s),a=0,b=0,c=0;
		for(int i=0;i<len;i++)
			if(s[i]=='0') b++,a+=s[(i+1)%len]=='1';
			else c++;
		if(a*len==c*b) puts("EQUAL");
		else puts(a*len<c*b?"SHOOT":"ROTATE");
	}
}