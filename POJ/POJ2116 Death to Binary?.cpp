#include<iostream>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;
ll fib[55]={1,2}; 
void getfib()
{
	for(int i=2;i<=50;i++)
		fib[i]=fib[i-1]+fib[i-2];
}
int convert(string& s,ll x)
{
	int bit=0;
	s.clear();
	for(int i=50;i>=0;i--)
		if(x>=fib[i]) x-=fib[i],s+='1',bit=max(bit,i);
		else if(i<=bit) s+='0';
	return bit;
}
int main()
{
	getfib();
	string a,b,ans;
	while(cin>>a>>b)
	{
		int lena=a.size(),lenb=b.size(),bit;
		ll suma=0,sumb=0,sum;
		reverse(a.begin(),a.end());
		while(lena&&a[lena-1]=='0') a[--lena]=0;
		reverse(b.begin(),b.end());
		while(lenb&&b[lenb-1]=='0') b[--lenb]=0;
		for(int i=0;i<lena;i++) suma+=a[i]=='1'?fib[i]:0;
		for(int i=0;i<lenb;i++) sumb+=b[i]=='1'?fib[i]:0;
		sum=suma+sumb;
		lena=convert(a,suma);
		lenb=convert(b,sumb);
		bit=convert(ans,sum);
		for(int i=0;i<bit+2-lena;i++) cout<<" ";
		for(int i=0;i<=lena;i++) cout<<a[i]; 
		cout<<endl<<'+';
		for(int i=0;i<bit+1-lenb;i++) cout<<" ";
		for(int i=0;i<=lenb;i++) cout<<b[i]; 
		cout<<endl<<"  ";
		for(int i=0;i<=bit;i++) cout<<'-';
		cout<<endl<<"  ";
		for(int i=0;i<=bit;i++) cout<<ans[i];
		cout<<endl<<endl;
	}
}
