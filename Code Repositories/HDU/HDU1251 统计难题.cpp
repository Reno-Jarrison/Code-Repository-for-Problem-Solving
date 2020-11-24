#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char wd[1000005][12]={0},ch[12];
int main()
{
	ios::sync_with_stdio(false);
	int k=0,j=0;
	while(1)
	{
		cin.getline(wd[k++],11);
		if(k&&(wd[k-1][0]=='\0'))
			break;
	}
	while(cin>>ch)
	{
		int len=strlen(ch),count=0;
		for(int i=0;i<k;i++)
		{
			int flag=0;
			for(int j=0;j<len;j++)
				if(ch[j]!=wd[i][j])
				{
					flag=1;
					break;
				}
			if(!flag)
				count++;
		}
		cout<<count<<endl; 
		memset(ch,0,sizeof(ch));
	}
}