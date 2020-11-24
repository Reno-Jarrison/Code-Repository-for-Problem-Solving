#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[10],tmp;
bool read()
{
	bool ok=false;
	for(int i=1;i<=6;i++)
		scanf("%lld",&num[i]),ok|=num[i];
	return ok;
}
int main()
{
	while(read())
	{
		ll ans=num[6]+num[5]+num[4],cnt[3]={0};
		cnt[1]+=num[5]*11; 
		cnt[2]+=num[4]*5;
		ans+=num[3]/4,num[3]%=4;
		if(num[3]==1) cnt[2]+=5,cnt[1]+=7,ans++;
		if(num[3]==2) cnt[2]+=3,cnt[1]+=6,ans++;
		if(num[3]==3) cnt[2]+=1,cnt[1]+=5,ans++;
		tmp=min(num[2],cnt[2]);
		num[2]-=tmp,cnt[2]-=tmp;
		ans+=num[2]/9,num[2]%=9;
		if(num[2]) cnt[1]+=(9-num[2])*4,ans++;
		cnt[1]+=cnt[2]*4;
		num[1]-=min(num[1],cnt[1]);
		ans+=num[1]/36,num[1]%=36;
		if(num[1]) ans++;
		printf("%lld\n",ans);
	}
}