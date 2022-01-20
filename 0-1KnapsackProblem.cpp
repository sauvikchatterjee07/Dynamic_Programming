#include<bits/stdc++.h>
using namespace std;


int knapSack(int w, int wt[], int val[], int n) 
    { 
        
        //Base case
        if(n == 0 or w == 0 )
            return 0;

        //choice diagram

        if (wt[n-1] <= w)
        {
            return max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1), knapSack(w, wt, val, n-1));
        }
        else if(wt[n-1]>w)
            return knapSack(w, wt, val, n-1);

    }


int main()
{   
        int N = 3;
        int W = 4;
        int values[] = {1,2,3};
        int weight[] = {4,5,1};
        cout<<knapSack(W, weight, values, N);


    return 0;
}
