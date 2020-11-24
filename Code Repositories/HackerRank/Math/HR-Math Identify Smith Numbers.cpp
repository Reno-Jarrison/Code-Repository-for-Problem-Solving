#include<iostream>
using namespace std;
int main()
{
    int n,sum1=0,sum2=0,tmp;
    cin>>n,tmp=n;
    while(tmp) sum1+=tmp%10,tmp/=10;
    tmp=n;
    for(int i=2;i*i<=tmp;i++)
        if(tmp%i==0) 
        {
            int tmpx=i,cnt=0;
            while(tmpx) cnt+=tmpx%10,tmpx/=10;
            while(tmp%i==0)
                sum2+=cnt,tmp/=i;
        }
    if(tmp>1) while(tmp)
        sum2+=tmp%10,tmp/=10;
    cout<<(sum1==sum2);
}