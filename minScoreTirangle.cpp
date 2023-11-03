#include<iostream>
#include<vector>
using namespace std;


// using recursion
class Solution {
public:
    int solve(int i,int j,vector<int>& values)
    {
        // base case
        if(i+1==j)
            return 0;
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
        ans=min(ans , values[i]*values[j]*values[k]+solve(i,k,values)+solve(k,j,values));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        return solve(0,values.size()-1,values);
    }
};


// using memoization+recursion

class Solution {
public:
    int solve(int i,int j,vector<int>& values,vector<vector<int> >&dp)
    {
        // base case
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
        ans=min(ans , values[i]*values[j]*values[k]+solve(i,k,values,dp)+solve(k,j,values,dp));
        dp[i][j]=ans;
        }
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int> >dp(n,vector<int>(n,-1));
        return solve(0,n-1,values,dp);
    }
};





// using tabulation
class Solution {
public:

    int solveTab(vector<int>& values)
    {
        int n=values.size();
        vector<vector<int> >dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    ans=min(ans , values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        
        return solveTab(values);
    }
};