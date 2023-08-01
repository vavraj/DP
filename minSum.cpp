// to find minimum sum of non adjacent elements

#include <iostream>
using namespace std;


// using recursion

int solve(vector<int>&nums,int n)
{
    // base case
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];

    // include
    int incl=solve(nums,n-2)+nums[n];
    // exclude
    int excl=solve(nums,n-1)+0;

    return max(incl,excl);    
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
}



// recursion + memoization  TC = O(N) SC= O(N) + O(N)

int solve(vector<int>&nums,int n,vector<int>&dp)
{
    // base case
    if(n<0)
        return 0;
    
    // step 3:
    if(dp[n]!=-1)
        return dp[n];
    // include
    int incl=solve(nums,n-2,dp)+nums[n];
    // exclude
    int excl=solve(nums,n-1,dp)+0;

    dp[n]= max(incl,excl); 
    return dp[n];   
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1,-1);
    int ans=solve(nums,n-1,dp);
    return ans;
}


// bottom up approach  TC=O(N)  SC=O(N)

int solve2(vector<int>&nums,int n)
{
    vector<int>dp(n,0);
    // base case
    dp[0]=nums[0];

    for(int i=1;i<n;i++)
    {

        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve2(nums,n);
    return ans;
}


// space optimization
// SC=O(N)

int solve2(vector<int>&nums,int n)
{
    // base case
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n;i++)
    {
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve2(nums,n);
    return ans;
}