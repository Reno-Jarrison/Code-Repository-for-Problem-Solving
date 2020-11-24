#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
struct hpnum
{
	int len,num[maxn];
	void update()
	{
		for(int i=0;i<len;i++)
		{
			while(num[i]<0) num[i]+=10,num[i+1]--;
			num[i+1]+=num[i]/10,num[i]%=10;
		}
		while(num[len]) 
			num[len+1]+=num[len]/10,num[len++]%=10;
		while(len>1&&!num[len-1]) len--;
	}
	bool iseven() { return !(num[0]&1); }
	friend istream& operator >>(istream& hpin,hpnum& x)
	{
		char tmp[maxn];
		hpin>>tmp,x.len=strlen(tmp);
		memset(x.num,0,sizeof(x.num));
		for(int i=x.len-1;i>=0;i--)
			x.num[i]=tmp[x.len-i-1]-'0';
		return hpin;
	}
	friend ostream& operator <<(ostream& hpout,hpnum x)
	{
		for(int i=x.len-1;i>=0;i--)
			hpout<<char(x.num[i]+'0');
		return hpout;
	}
};
bool operator ==(hpnum& x,hpnum& y)
{
	if(x.len!=y.len) return false;
	for(int i=0;i<x.len;i++)
		if(x.num[i]!=y.num[i]) return false;
	return true;
}
bool operator <(hpnum& x,hpnum& y)
{
	if(x.len<y.len) return true;
	else if(x.len==y.len)
		for(int i=x.len-1;i>=0;i--)
			if(x.num[i]<y.num[i]) return true;
			else if(x.num[i]>y.num[i]) return false;
	return false;
}
hpnum operator -(const hpnum& x,const hpnum& y)
{
	hpnum tmp=x;
	for(int i=0;i<tmp.len;i++)
		tmp.num[i]-=y.num[i];
	tmp.update();
	return tmp;
}
hpnum half(hpnum x)
{
	int tmp,m=0;
	for(int i=x.len-1;i>=0;i--)	
		tmp=m*10+x.num[i],x.num[i]=tmp>>1,m=tmp&1;
	x.update();
	return x;
}
hpnum doub(hpnum x)
{
	for(int i=0;i<x.len;i++) x.num[i]<<=1;
	x.update();
	return x;
}
hpnum bgcd(hpnum x,hpnum y)
{
	int cnt=0;
	while(!(x==y))
	{
		if(x.iseven()&&y.iseven()) 
			x=half(x),y=half(y),cnt++;
		else if(x.iseven()&&!y.iseven()) x=half(x);
		else if(!x.iseven()&&y.iseven()) y=half(y);
		else if(x<y) swap(x,y); 
		else x=x-y;
	}
	while(cnt--) x=doub(x);
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
	hpnum x,y;
	cin>>x>>y;
	cout<<bgcd(x,y);
}