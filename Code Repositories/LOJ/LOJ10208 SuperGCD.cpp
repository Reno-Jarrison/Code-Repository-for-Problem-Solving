#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1200,base=1e9;
struct hpnum
{
	int len,num[maxn];
	friend istream& operator >>(istream& hpin,hpnum& x)
	{
		char tmp[10005];
		memset(x.num,0,sizeof(x.num));
		hpin>>tmp,x.len=1;
		int tlen=strlen(tmp),w=1;
		for(int i=0;i<tlen;i++)
		{
			if(w==base) x.len++,w=1;
			x.num[x.len-1]+=w*(tmp[tlen-i-1]-'0'),w*=10; 
		}
		return hpin;
	}
	friend ostream& operator <<(ostream& hpout,hpnum x)
	{
		hpout<<x.num[x.len-1];
		for(int i=x.len-2;i>=0;i--)
			hpout<<setw(9)<<setfill('0')<<x.num[i];
		return hpout;
	} 
}x,y,tmp;
hpnum operator -(const hpnum& x,const hpnum& y)
{
	hpnum tmp=x;
	for(int i=tmp.len-1;i>=0;i--)
		tmp.num[i]-=y.num[i];
	for(int i=0;i<tmp.len;i++)
		tmp.num[i]<0?tmp.num[i]+=base,tmp.num[i+1]--:0;
	while(!tmp.num[tmp.len-1]&&tmp.len>1) tmp.len--;
	return tmp;
}
bool operator <(const hpnum& x,const hpnum& y)
{
	if(x.len<y.len) return true;
	else if(x.len==y.len)
		for(int i=x.len-1;i>=0;i--)
			if(x.num[i]<y.num[i]) return true;
			else if(x.num[i]>y.num[i]) return false;
	return false; 
}
hpnum operator %(const hpnum& x,const hpnum& y)
{
	hpnum tmp=x;
	while(!(tmp<y)) tmp=tmp-y;
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>x>>y;
	while(!(y.len==1&&y.num[0]==0))
		tmp=y,y=x%y,x=tmp;
	cout<<x;
}