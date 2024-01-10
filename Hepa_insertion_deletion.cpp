#include<bits/stdc++.h>
using namespace std;


class heap{
    public:
    int a[100];
    int size;
    heap()
    {
        a[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
       size = size+1;
       int index = size;
       a[index] = val;
       //bohot hard bohot hard
       while(index>1)
       {
           if(a[index/2]<a[index])
           {
               swap(a[index/2],a[index]);
               index  = index / 2;
           }
           else{
            return ;
           }

       }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<a[i]<<" ";

        }
        cout<<endl;
    }

    void delet()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        //take last element to first
        a[1]= a[size];
        size--;//forget the last element
        //take the node to the correct position..
        int i=1;
        while(i<size)
        {
            int left = 2*i;
            int right = 2*i+1;
            if(left<size && a[i]<a[left])
            {
                swap(a[i],a[left]);
                i = left;
            }
            else if(right<size && a[i]<a[right])
            {
                swap(a[i],a[right]);
                    i  = right ;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    heap h;
    int n;
    cout<<"Kitna Put karne hai?::: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h.insert(x);
    }
   // h.insert(55);
    h.print();
    h.delet();
     h.print();
}
