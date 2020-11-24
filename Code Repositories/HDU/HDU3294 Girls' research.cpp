#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		char s[200005];
		scanf("%s",s);
		int cge=c-'a',len=strlen(s),maxlen=1,begin;
		for(int i=0;i<len;i++)
		{
			int j=i-1,k=i+1;
			while(j>=0&&k<len&&s[j]==s[k])
			{
				if(k-j+1>maxlen)
					maxlen=k-j+1,begin=j;
				j--,k++; 
			}
			j=i,k=i+1;
			while(j>=0&&k<len&&s[j]==s[k])
			{
				if(k-j+1>maxlen)
					maxlen=k-j+1,begin=j;
				j--,k++; 
			}
		}
		if(maxlen>1)
		{
			printf("%d %d\n",begin,begin+maxlen-1);
			for(int i=begin;i<begin+maxlen;i++)
				printf("%c",'a'+(s[i]-'a'+26-cge)%26);
			printf("\n");
		}
		else
			printf("No solution!\n");
		getchar();
	}	
}