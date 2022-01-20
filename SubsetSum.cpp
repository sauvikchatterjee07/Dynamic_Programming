#include<bits/stdc++.h>
using namespace std;


bool subsetSum(vector<int>arr, int sum, int n){

    // wt array == arr[]
    // weight == sum

    vector<vector<bool>>dp(n+1, vector<bool>(n+1));

    for (int i = 0; i <=n ; i++) //Initialization
    {
        for (int j = 0; j <= sum; j++){
            if(i == 0) dp[i][j] = false;
            if (j == 0) dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}


int main()
{   
    vector<int>v = {3, 34, 4, 12, 7, 1};
    int sum = 32;
    int n = v.size();
    cout<<subsetSum(v, sum, n);
    return 0;
}
