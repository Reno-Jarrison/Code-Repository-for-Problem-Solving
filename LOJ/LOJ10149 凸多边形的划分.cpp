#include<bits/stdc++.h>
#define ll long long
#define maxn 105
using namespace std;
struct hpnum 
{
	int len,num[50];
	void update()
	{
		for(int i=0;i<len;i++)
			if(num[i]>9)
				num[i+1]+=num[i]/10,num[i]%=10;
		while(num[len]) 
		{
			num[len+1]+=num[len]/10;
			num[len]=num[len]%10;
			len++;
		}
		while(num[len-1]==0&&len>1) len--;
	}
	void read() 
	{
		char tmp[50];
		scanf("%s",tmp),len=strlen(tmp);
		memset(num,0,sizeof(num));
		for(int i=len-1;i>=0;i--) num[i]=tmp[len-i-1]-'0';
	}
	void write()
	{ 	for(int i=len-1;i>=0;i--) putchar(num[i]+'0'); }
	void init() { len=40; for(int i=0;i<len;i++) num[i]=9; }
};
bool operator <(const hpnum& x,const hpnum& y)
{
	if(x.len<y.len) return true;
	else if(x.len==y.len)
	{
		for(int i=x.len-1;i>=0;i--)
			if(x.num[i]<y.num[i]) return true;
			else if(x.num[i]>y.num[i]) return false;
	}
	return false;
}
hpnum operator +(const hpnum& x,const hpnum& y)
{
	hpnum tmp=x;
	tmp.len=max(x.len,y.len); 
	for(int i=0;i<y.len;i++)
		tmp.num[i]+=y.num[i];
	tmp.update();
	return tmp;
}
hpnum operator *(const hpnum& x,const hpnum& y)
{
	hpnum tmp={x.len+y.len-1,{0}};
	for(int i=0;i<x.len;i++)
		for(int j=0;j<y.len;j++)
			tmp.num[i+j]+=x.num[i]*y.num[j];
	tmp.update();
	return tmp;	
} 
hpnum a[maxn],dp[maxn][maxn];
hpnum minnum(hpnum a,hpnum b) { return a<b?a:b; }
int main()
{
	int n;
	hpnum ans;
	ans.init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[i].read(),a[i+n]=a[i];
	for(int i=3;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n<<1;l++,r++)
		{
			dp[l][r].init();
			for(int m=l+1;m+1<=r;m++)
				dp[l][r]=minnum(dp[l][r],dp[l][m]+dp[m][r]+a[l]*a[m]*a[r]);
		}
	for(int i=1;i<=n;i++)
		ans=minnum(ans,dp[i][i+n-1]);
	ans.write();
}