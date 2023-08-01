/*  
    to find the minimum cost of climbing stairs such that you can only climb either 
     one or two stairs after paying the price of a stair.
          
*/

#include<iostream>
using namespace std;

// top down approach using recursion + memoization
class Solution {

    int solve(vector<int>cost,int n,vector<int>&dp)
    {
        // Base case
        if(n==0 || n==1)
            return cost[n];
        // step 3
        if(dp[n]!=-1)
            return dp[n];

        // step 2
        dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
        return dp[n]; 
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int>dp(n,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};



// bottom up approach using tabulation
class Solution {

    int solve(vector<int>cost,int n)
    {
        // creating a 1-D array
        vector<int>dp(n+1);
        
        // intialising base condition
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        // step 3
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
    }
};

// space optimization
class Solution {
      
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++)
        {
            int curr=min(prev2,prev1)+cost[i];
            prev2=prev1;
            prev1=curr;
        }
        int ans=min(prev2,prev1);
        
        return ans;
    }
};