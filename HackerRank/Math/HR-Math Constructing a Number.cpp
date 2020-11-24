#include<iostream>
using namespace std;
int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            while(x) ans=(ans+x%10)%3,x/=10;
        }
        puts(ans?"No":"Yes");
    }
}