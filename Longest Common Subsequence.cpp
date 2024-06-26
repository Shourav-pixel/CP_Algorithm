#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n= s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m,0));
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int len  = dp[n][m];
    cout<<"The length of the lcs is:";
    cout<<len<<endl;
    int ind =len-1;

    string ans = "";
    for(int i=0;i<len;i++)
    {
        ans+= '$';
    }
    int i=n,j=m;
    while(i>0 && j>0)
    {

        if(s1[i-1] == s2[j-1])
        {

            ans[ind] = s1[i-1];
            ind--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i = i-1;
        }
        else{
            j=j-1;
        }
    }

    cout<<ans<<endl;

}
