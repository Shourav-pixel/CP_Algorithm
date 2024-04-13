#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n= s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m,0));
    int res  = 0;
    int startIdx = -1, endIdx = -1;
    int st = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                res  = max(res,dp[i][j]);
                endIdx = i - 1;


            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<"Length of the longest common substring is: ";
   cout<<res<<endl;
 string lcs = s1.substr(endIdx - res + 1, res);
        cout << lcs << endl;








}
