    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;

    int  main()
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
        ll mx = INT_MIN;
        ll sum=0,l=0;
        ll st,start,en;
          for(int i=0;i<n;i++)
          {
              if(sum == 0)
              {
                  st = i;
              }
             sum+=v[i];
             if(sum<0)
             {
               sum =0 ;
             }
             if(sum>mx)
             {
                  start = st;
                 en = i;
             }

             mx = max(mx,sum);
          }
          for(int i =start;i<=en;i++)
            cout<<v[i]<<" ";
          cout<<endl;
          cout<<mx<<endl;
       }



    }
