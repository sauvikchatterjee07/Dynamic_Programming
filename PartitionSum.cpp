#include<bits/stdc++.h>
using namespace std;


bool subsetSum(vector<int>arr, int sum, int n){

    vector<vector<bool>>dp(n+1, vector<bool>(sum+1));

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

bool equal_partition_sum(vector<int>arr){


    int n = arr.size();
    int sum = 0;
    for(auto i: arr)
        sum+=i;

    if (sum%2 != 0)
        return false;
    else
        return subsetSum(arr,sum/2, n);
}



int main()
{   
    vector<int>v = {100,100,100,100,100,100,100,100};
    cout<<equal_partition_sum(v);
    return 0;
}
