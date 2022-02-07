// MATRIX CHAIN MULTIPLICATION

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp (1000, vector<int>(1000, -1));

int MCM(vector<int>arr, int i, int j){
    
    int n = arr.size();
    int mn = INT_MAX;

    if(i>=j) return 0; //Base Condition

    if (dp[i][j] != -1)
        return dp[i][j];

    for(int k = i; k<j; k++){
        int tempans = (MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);

        mn = min(mn, tempans);
        // cout<<mn;
    }

    return dp[i][j] = mn;
}

int main()
{   
    vector<int> v = {40, 20, 30, 10, 30} ;
    cout<<MCM(v,1, v.size()-1);
    return 0;
}
