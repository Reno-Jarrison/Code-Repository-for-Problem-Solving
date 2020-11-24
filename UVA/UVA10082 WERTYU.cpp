#include<bits/stdc++.h>
using namespace std;
char *s1="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	char c,*s;
	while((c=getchar())!=EOF)
	{
		if(s=strchr(s1,c))
			printf("%c",*(s-1));
		else 
			printf("%c",c);	
	}	
}