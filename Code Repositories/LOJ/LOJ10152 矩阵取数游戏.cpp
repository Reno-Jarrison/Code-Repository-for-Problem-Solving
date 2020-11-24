#include<bits/stdc++.h>
using namespace std;
struct hpnum
{
	int len,num[50];
	hpnum() { len=1,memset(num,0,sizeof(num)); }
	void update()
	{
		for(int i=0;i<len;i++)
			num[i+1]+=num[i]/10,num[i]%=10;	
		while(num[len])
		{
			num[len+1]+=num[len]/10;
			num[len]%=10;
			len++;
		}
		while(num[len-1]==0&&len>1) len--;
	}	
	friend istream& operator>>(istream& hpin,hpnum& x)
	{
		char tmp[50];
		hpin>>tmp,x.len=strlen(tmp);
		memset(x.num,0,sizeof(x.num));
		for(int i=x.len-1;i>=0;i--)
			x.num[i]=tmp[x.len-i-1]-'0';
		return hpin;
	}
	friend ostream& operator<<(ostream& hpout,const hpnum& x)
	{
		for(int i=x.len-1;i>=0;i--)
			cout<<char(x.num[i]+'0');
		return hpout; 		
	}
}a[85][85],dp[85][85],ans,base[85];
bool operator >(const hpnum& x,const hpnum& y)
{
	if(x.len>y.len) return true;
	else if(x.len==y.len)
	{
		for(int i=x.len-1;i>=0;i--)
			if(x.num[i]>y.num[i]) return true;
			else if(x.num[i]<y.num[i]) return false;
	}
	return false;
}
hpnum operator +(const hpnum& x,const hpnum& y)
{
	hpnum tmp=x;
	for(int i=0;i<y.len;i++)
		tmp.num[i]+=y.num[i];
	tmp.update();
	return tmp;
}
hpnum operator *(const hpnum& x,const hpnum& y)
{
	hpnum tmp;
	tmp.len=x.len+y.len-1;
	for(int i=0;i<x.len;i++)
		for(int j=0;j<y.len;j++)
			tmp.num[i+j]+=x.num[i]*y.num[j];
	tmp.update();
	return tmp;
}
hpnum maxnum(const hpnum& x,const hpnum& y)
{	return x>y?x:y; }
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	base[1].num[0]=2;
	for(int i=2;i<=m+1;i++) 
		base[i]=base[i-1]*base[1];
	for(int row=1;row<=n;row++)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++)
			dp[i][i]=a[row][i]*base[m];
		for(int i=m-1;i;i--)
			for(int l=1,r=l+m-i;r<=m;l++,r++)
			{
				dp[l][r]=maxnum(dp[l][r],dp[l+1][r]+a[row][l]*base[i]);
				dp[l][r]=maxnum(dp[l][r],dp[l][r-1]+a[row][r]*base[i]);
			}
		ans=ans+dp[1][m];
	}
	cout<<ans;
}