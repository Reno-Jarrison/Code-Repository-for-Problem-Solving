#include<cstdio>
#include<cstring>
#include<algorithm>
#define ull unsigned long long
using namespace std;
const int maxn=1e6+5,base=233;
ull hlist[maxn],hval=0,power=1;
char s1[maxn],s2[maxn];
void gethash(int len,char *s)
{
	for(int i=1;i<=len;i++)
		hlist[i]=hlist[i-1]*base+s[i-1];
}
int main()
{
	scanf("%s%s",s1,s2);
	int len1=strlen(s1),len2=strlen(s2),ans=0;
	gethash(len1,s1);
	for(int i=0;i<len2;i++)
		hval=hval*base+s2[i],power*=base;
	for(int i=len2;i<=len1;i++)
		if(hlist[i]-hlist[i-len2]*power==hval) ans++;
	printf("%d",ans);
}