#include<bits/stdc++.h>
using namespace std;
int cnt[26],sg[45];
int getsg(int x)
{
	if(!x) return 0;
	if(~sg[x]) return sg[x];
	int s[4]={0},mex=0;
	if(x>=1) s[getsg(x-1)]=1;
	if(x>=2) s[getsg(x-2)]=1;
	while(s[++mex]);
	return sg[x]=mex;
}
int main()
{
	char s[50];
	scanf("%s",s);
	int len=strlen(s),SG=0;
	for(int i=0;i<len;i++)
		cnt[s[i]-'A']++;
	memset(sg,-1,sizeof(sg));
	for(int i=0;i<26;i++)
		SG^=getsg(cnt[i]);
	puts(SG?"Alice":"Bob");
}