   
   //FIBONACCI MEMORIZED
   
   
   int fibmemo(int n, vector<int> dp){
        
        if(n == 0 || n == 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        int fibn1 = fibmemo(n-1, dp);
        int fibn2 = fibmemo(n-2, dp);
        
        dp[n] = fibn1 + fibn2;
        return dp[n];
    }
    
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibmemo(n, dp);
        
    }
    
    
    
    //FIBONACCI BOTTOM UP
    
        int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    
    
    
    
