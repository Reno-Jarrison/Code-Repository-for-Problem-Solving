#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int len=strlen(s),wssum=0,adsum=0;
		int mw=0,ms=0,ma=0,md=0;
		int dw=0,ds=0,da=0,dd=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='W') 
			{
				wssum++;
				mw=max(mw,wssum);
				dw=max(dw,wssum-ms);
			}
			else if(s[i]=='S') 
			{
				wssum--;
				ms=min(ms,wssum);
				ds=max(ds,mw-wssum);
			}
			else if(s[i]=='A') 
			{
				adsum++;
				ma=max(ma,adsum);
				da=max(da,adsum-md);
			}
			else if(s[i]=='D') 
			{
				adsum--;
				md=min(md,adsum);
				dd=max(dd,ma-adsum);
			}
		}
		int h=mw-ms+1,w=ma-md+1;
		ll ans=1LL*h*w;
		if(ds!=dw&&(mw||ms)&&h>2)
			ans=min(ans,1LL*(h-1)*w);
		if(da!=dd&&(ma||md)&&w>2)
			ans=min(ans,1LL*h*(w-1));
		cout<<ans<<endl;
	}
}

