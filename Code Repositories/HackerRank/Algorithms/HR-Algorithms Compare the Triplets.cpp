#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a[3],b[3],ans1=0,ans2=0;
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    for(int i=0;i<3;i++) 
        ans1+=a[i]>b[i],ans2+=a[i]<b[i];
    cout<<ans1<<" "<<ans2;
}