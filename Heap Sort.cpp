#include<bits/stdc++.h>
using namespace std;

void heapify(int v[],int n,int i)
{
    int large = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && v[left]>v[large])
    {
        large = left;
    }
    if(right<=n && v[right]>v[large])
    {
        large = right;
    }
    if(large!=i)
    {
        swap(v[large],v[i]);
        heapify(v,n,large);
    }
}
void sortwala(int v[],int n)
{
    int t = n;

    while(t>1)
    {
        //step 1:
        swap(v[1],v[t]);
        t--;

        //step 2:send the root to correct pos
        heapify(v,t,1);

    }



}

int main()
{
    int n;
   cin>>n;
    int v[n] ;
    //vector<int>v(n);
    for(int i=1;i<=n;i++)
        cin>>v[i];


    for(int i=n/2;i>0;i--)
    {
        heapify(v,n,i);

    }

    sortwala(v,n);

    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

}
