int dp[1001][1001];

class Solution {
public:
    int helper(string &text1,string &text2,int len1, int len2){
        if(len1 == 0 or len2 == 0) return 0;
        
        if(dp[len1][len2] != -1) return dp[len1][len2];
        else{
            if(text1[len1-1] == text2[len2-1]) {
                return dp[len1][len2] = 1 + helper(text1,text2,len1-1,len2-1);
            }
            else{
                return dp[len1][len2] =  max(helper(text1,text2,len1,len2-1),helper(text1,text2,len1-1,len2));
            }
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        
        memset(dp,-1,sizeof(dp));
        
        return helper(text1,text2,len1,len2);
    }
};
