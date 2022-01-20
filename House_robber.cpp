int rob(vector<int>& a) {
        int n = a.size();
        if(n == 0) return 0;
        if(n == 1) return a[0];
        vector<int> v(n+1, 0);
        v[1] = a[0];
        for(int i = 1; i< n; i++){
            v[i+1] = max(v[i], v[i-1]+a[i]);
        }
        return v[n];
    }
