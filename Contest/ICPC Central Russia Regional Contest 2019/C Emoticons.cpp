#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int cnt[300];
char s[maxn];
void print(const char *txt,int n)
{
	for(int i=1;i<=n;i++)
		printf("%s\n",txt);
	int len=strlen(txt);
	for(int i=0;i<len;i++)
		cnt[(int)txt[i]]-=n;
}
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
		cnt[(int)s[i]]++;
	print(":-\\",cnt['\\']);
	print(":-P",cnt['P']);
	print(":D",cnt['D']);
	print(":C",cnt['C']);
	print("8-0",cnt['8']);
	print(":-E",cnt['E']);
	print("%0",cnt['%']);
	print(":-X",cnt['X']);
	print(":~(",cnt['~']);
	print("[:|||:]",cnt['[']);
	print(":-0",cnt['0']);
	print(":-|",cnt['|']);
	print(";-)",min(cnt[';'],cnt[')']));
	print(":)",cnt[')']);
	print(";-(",cnt[';']);
	print(":(",cnt[':']);
	puts("LOL");
}