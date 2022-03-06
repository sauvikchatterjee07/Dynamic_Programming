class Solution {
public:
    int countOrders(int n) {
        vector<long> dp(501);
        int mod = pow(10, 9) + 7;
        dp[1] = 1;
        dp[2] = 6;
        for(int i = 3; i<=n; i++){
            int odd_no = 2*i-1;
            int permutation = (odd_no * (odd_no+1))/2;
            dp[i] = ((dp[i-1]*permutation) % mod);
        }
        return dp[n];
    }
};
