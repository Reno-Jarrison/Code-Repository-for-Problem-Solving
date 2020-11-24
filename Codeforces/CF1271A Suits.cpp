#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,ans=0;
void f1()
{
	int cnt=min(a,d);
	a-=cnt,d-=cnt,ans+=cnt*e;
}
void f2()
{
	int cnt=min(b,min(c,d));
	b-=cnt,c-=cnt,d-=cnt,ans+=cnt*f;
}
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	if(e>f) f1(),f2();
	else f2(),f1();
	cout<<ans;
}