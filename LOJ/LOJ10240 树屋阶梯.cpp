#include<bits/stdc++.h>
using namespace std;
int ans[10005]={1},temp[10005];
int len=1;
void mul(int x)
{
	int i;
	for(i=0;i<len;i++)
		ans[i]*=x;
	for(i=0;i<len;i++)
		ans[i+1]+=ans[i]/10,ans[i]%=10;
	while(ans[i])
		ans[i+1]+=ans[i]/10,ans[i]%=10,i++,len++;
}
void div(int x)
{
	int k=0,mov;
	memset(temp,0,sizeof(temp));
	for(int i=0;i<len;i++)
		temp[i]=(ans[i]+k*10)/x,k=(ans[i]+k*10)%x;
	for(mov=0;mov<len;mov++)
		if(temp[mov])
			break;
	for(int i=0;i<len;i++)
		if(i<len-mov)
			temp[i]=temp[i+mov];
		else
			temp[i]=0;
	len-=mov;
	memcpy(ans,temp,len*sizeof(int));
}
int main()
{
	int n;
	cin>>n;
	for(int i=n+2;i<=2*n;i++)
		mul(i);
	for(int i=len-1;i>=0;i--)
		temp[len-i-1]=ans[i];
	memcpy(ans,temp,len*sizeof(int));
	for(int i=2;i<=n;i++)
		div(i);
	for(int i=0;i<len;i++)
		cout<<ans[i];	
 } 