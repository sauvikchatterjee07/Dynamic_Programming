    int deleteAndEarn(vector<int>& nums) {
        
        int n = 10005;
        vector<int> sum(n, 0);
        
        for(auto num: nums){
            sum[num] += num;
        }
        //sum.erase(remove(sum.begin(), sum.end(), 0), sum.end());
        
        int sz = sum.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = sum[1];
        for (int i = 2; i < sz; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + sum[i]);
        }
        return dp[sz-1];
    }
