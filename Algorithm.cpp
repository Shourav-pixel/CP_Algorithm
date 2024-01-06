#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
        ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll id=-1;

    for(int i=n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {
            id = i;
            break;
        }
    }
    if(id == -1)
    {
        reverse(v.begin(),v.end());
        for(auto i:v)
            cout<<i<<' ';
        cout<<endl;
    }
    else{

    ll mx  = INT_MAX;
    for(int i =n-1;i>=id;i--)
    {
        if(v[i]>v[id])
        {
            swap(v[i],v[id]);
            break;
        }
    }
    sort(v.begin()+id+1,v.end());
    for(auto i:v)
        cout<<i<<' ';
    cout<<endl;

    }

  }





}
