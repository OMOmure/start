#include<iostream>
using namespace std;
int n,a[100];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <=n; i++)
    {
        int len=0;
        for(int j = i;j>=1 ;j--)
        {
            if(a[i]>a[j]) len++;  
        }
        cout<<len<<" ";
    }
    return 0;
}