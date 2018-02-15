#include <iostream>
#include <algorithm>
using namespace std;
//a[i]<value for given array
int fbs(int a[],int high, int low,int x){
    if(low>high )return -1;
    
    if(x>a[high])
    return high;

    int mid=(low+high)/2;
    /*
    if(x==a[mid])
    return mid;
    */
    
    if(x<=a[mid] && mid>0)
    {
        if(x>a[mid-1])
        return mid-1;
        
        return fbs(a,mid-1,low,x);
    }
    
    
    if(x<a[mid])
    return fbs(a,mid-1,low,x);
    
    return fbs(a,high,mid+1,x);
}

int main()
{
    int n; cin>>n;
    int p;
    int arr[n];
    for (int i=0;i<n;i++) cin>>arr[i];
    int q; cin>>q;
    sort(arr,arr+n);
    while(q--){
        cin>>p;
        int t=fbs(arr,n-1,0,p);
        if(t==-1)cout<<"0\n";
        else if(arr[t]==p)cout<<t<<'\n';
        else cout<<t+1<<"\n";
    }
    return 0;
}
