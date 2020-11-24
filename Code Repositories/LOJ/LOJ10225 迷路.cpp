#include<iostream>
#include<cstring>
using namespace std;
#define mod 2009
struct matrix
{
	int len,m[100][100];
	matrix()
		{ memset(m,0,sizeof(m)); }
	void init()
		{ for(int i=1;i<=len;i++) m[i][i]=1; }
	matrix operator *(matrix &tmat)
	{
		matrix temp;
		temp.len=len;
		for(int i=1;i<=len;i++)
			for(int j=1;j<=len;j++)
			{
				for(int k=1;k<=len;k++)
					temp.m[i][j]+=m[i][k]*tmat.m[k][j];
				temp.m[i][j]%=mod;
			}
		return temp;
	}
}mat;
matrix qmpow(matrix &mat,int p)
{
	matrix ansm;
	ansm.len=mat.len;
	ansm.init();
	while(p)
	{
		if(p&1) ansm=ansm*mat;
		p>>=1;
		mat=mat*mat;
	}
	return ansm;
}
int main()
{
	int n,t;
	string s;
	cin>>n>>t;
	mat.len=n*9;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<9;j++)
		mat.m[i*9+j][i*9+j+1]=1;
		cin>>s;
		for(int j=0;j<n;j++)
		{ 
			s[j]-='0';
			if(s[j])
				mat.m[i*9+s[j]][j*9+1]=1;
		}
	}
	mat=qmpow(mat,t);
	cout<<mat.m[1][(n-1)*9+1];
 } 