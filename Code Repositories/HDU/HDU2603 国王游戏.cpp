#include<bits/stdc++.h>
#define N 40005 
using namespace std;
struct P
{
	int l;
	int r;
	long long pro;
}p[10005];
int mul[N],temp[N],mlen;
char compare[N],getmax[N];

bool cmp(P a,P b)
{
	return a.pro<b.pro;
}
void multi(int x)
{
	int i;
	for(i=0;i<mlen;i++)
		mul[i]*=x;
	for(i=0;i<mlen;i++)
		mul[i+1]+=mul[i]/10,mul[i]%=10;
	while(mul[i])
		mul[i+1]+=mul[i]/10,mul[i]%=10,i++,mlen++;
}
void divide(int x)
{
	int k=0,mov=0;
	memset(compare,0,sizeof(compare));
	for(int i=0;i<mlen;i++)
		compare[i]=(temp[i]+k*10)/x,k=(temp[i]+k*10)%x;
	for(mov=0;mov<mlen;mov++)
		if(compare[mov])
			break;
	for(int i=0;i<mlen;i++)
		if(i<mlen-mov)
			compare[i]=compare[i+mov]+'0';
		else
			compare[i]=0;
}
void reversetotemp()
{
	memset(temp,0,sizeof(temp));
	for(int i=0;i<mlen;i++)
		temp[i]=mul[mlen-i-1];
}
int main()
{
	int n,a,b,clen,glen,tempa;
	cin>>n>>a>>b;
	tempa=a;
	while(tempa)
		tempa/=10,mlen++;
	for(int i=0;i<mlen;i++)
		mul[i]=a%10,a/=10;
	for(int i=0;i<n;i++)
		cin>>p[i].l>>p[i].r,p[i].pro=p[i].l*p[i].r;
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
	{
		reversetotemp();
		divide(p[i].r);			
		clen=strlen(compare);	
		glen=strlen(getmax);
		if(clen>glen||(clen==glen)&&(strcmp(compare,getmax)>0))
			strcpy(getmax,compare);
		multi(p[i].l);			
	}
	cout<<getmax;
}