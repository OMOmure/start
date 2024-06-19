#include<iostream>
using namespace std;
int main()
{
    int n ;
    cin>>n; 
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int m=0;
    while (m < n)
    {
        int len=0;      
        for ( int q = 0; q < m; q++)
        {
            if(a[m]>a[q]) len++;   
        }
        cout<<len<<" ";
        m++;
    }
    return 0;
}