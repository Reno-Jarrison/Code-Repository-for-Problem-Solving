#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int a[maxn],b[maxn],buf[maxn],len;
bool check()
{
	for(int i=1;i<=len;i++)
		if(a[i]!=b[i]) return false;
	return true;
}
int main()
{
	int k;
	scanf("%s%d",s+1,&k);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
		a[i]=s[i]-'0',b[i]=s[len-i+1]-'0';
	for(int i=0;i<k;i++)
	{
		if(check()) 
		{	k=i; break; }
		for(int j=1;j<=len;j++)
			buf[j]=a[j]+b[j];
		for(int j=1;j<=len;j++)
			if(buf[j]>9) buf[j+1]++,buf[j]-=10;
		if(buf[len+1]) len++;
		for(int j=1;j<=len;j++)
			b[j]=buf[j],a[j]=buf[len-j+1];
	}
	for(int i=1;i<=len;i++)
		printf("%d",a[i]);
	printf("\n%d\n",k);
}