int tribonacci(int n) {
    vector<int>a(n+1, 0);
        if (n <= 1) return n;
        if (n == 2) return 1;

        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            a[i] = a[i-3]+a[i-2]+a[i-1];
        }
        return a[n];
    }
