    int countSubsets(vector<int>& nums, int target) {
    
    int n = nums.size();
    vector<vector<int>>dp(n+1, vector<int>(target+1));

    for(int i = 0; i<= n; i++){
        for(int j = 0; j<= target; j++){
            if(i == 0)  dp[i][j] = 0; //No subset is present
            if(j == 0)  dp[i][j] = 1; //Null subset is present of sum 0
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=target; j++){
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][target];
}

int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(auto i: nums)
            sum+= i;
        if(sum < abs(target) or (sum+target)%2 != 0)
            return 0;
        int Ntarget = (sum + target)/2;

        return countSubsets(nums, Ntarget);

    }
