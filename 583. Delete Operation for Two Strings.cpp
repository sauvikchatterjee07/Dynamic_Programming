class Solution {
public:
    int LCS(string a, string b){

    int m = a.size(), n = b.size();
    int dp[m+1][n+1];
    for(int i = 0; i<= m; i++){
        for(int j = 0; j<= n; j++){
            if(i==0 or j ==0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i<= m; i++){
        for(int j = 1; j<= n; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int minDistance(string word1, string word2) {

    int len1 = word1.size();
    int len2 = word2.size();

    int len_lcs = LCS(word1, word2);

    int del = len1 - len_lcs;
    int ins = len2 - len_lcs;

    return del+ins;     
}
