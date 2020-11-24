#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4],sum=0,ok=0;
	for(int i=0;i<4;i++)
		scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<16;i++)
	{
		int x=i,tmp=0;
		for(int j=0;j<4;j++,x>>=1)
			if(x&1) tmp+=a[j];
		ok|=(tmp*2==sum);
	}
	puts(ok?"Yes":"No");
}