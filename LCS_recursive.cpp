#include<bits/stdc++.h>
using namespace std;

int LCSRecursive(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    //Base condition
    if(n == 0 or m == 0) return 0;

    //Choice Diagram
    if(s1[n-1] == s2[m-1]){
        s1 = s1.erase(s1.size() - 1);
        s2 = s2.erase(s2.size() - 1);
        return 1 + LCSRecursive(s1, s2);
    }
    else{
        
        string s3 = s1.erase(s1.size() - 1);
        string s4 = s2.erase(s2.size() - 1);

        return max(LCSRecursive(s3, s2), LCSRecursive(s1, s4));
    }
}


int main()
{
    string s1 = "abc";
    string s2 = "def";
    cout<<LCSRecursive(s1, s2);

    return 0;
}
