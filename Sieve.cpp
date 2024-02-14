#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>prime;
void seive()
{
   ll  n=10000000;
    vector<bool>vis(n,0);
    for(ll i=3;i*i<=n;i+=2)
    {
        if(vis[i]==0)
        {

        for(ll j=i*i;j<n;j+=2*i)
        {
            vis[j]=1;
        }
        }
    }
 prime.push_back(2);
    for(ll i=3;i<=n;i+=2)
    {
        if(vis[i]==0)
            prime.push_back(i);
    }

}
int main()
{
    	seive();
       ll n;
       cin>>n;
       for(ll i =0;i<n;i++)
        cout<<prime[i]<<" ";
       cout<<endl;
}
