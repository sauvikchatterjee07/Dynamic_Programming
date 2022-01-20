#include<bits/stdc++.h>
using namespace std;




int knapSack(int wt[], int val[], int w, int n) {
	vector<vector<int>>dp(1001, vector<int>(1001)); // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) // base case
				dp[i][j] = 0;
        }
    }    

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if (wt[i - 1] <= j) { // current wt can fit in bag
				int val1 = val[i - 1] + dp[i - 1][j - wt[i - 1]]; // take current wt
				int val2 = dp[i - 1][j]; // skip current wt
				dp[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				dp[i][j] = dp[i - 1][j];
        }
        
    }
    return dp[n][w];
}




int main()
{   
        int N = 3;
        int W = 4;
        int values[] = {1,2,3};
        int weight[] = {4,5,1};
        cout<<knapSack(weight, values,W, N);


    return 0;
}
