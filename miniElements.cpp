/* you are given an array of n distinct integers and an integer x representing the target sum you 
 have to tell the minimum number of elements you have to take to reach the target sum x */

// here 1 coin is counted as a single entity

#include <iostream>
using namespace std;


// using recursion --> top down approach

int solve(vector<int> num, int x) {
    // base case
  if (x == 0)
    return 0;
  if (x < 0)
    return INT_MAX;
  int mini = INT_MAX;

  
    for(int i=0;i<num.size();i++)
    {
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans=solve(num,x);
    if(ans!=INT_MAX)
        return ans;
    return -1;
}




// applying memoization -->top down approach
int solve(vector<int> num, int x, vector<int>&dp) {
  // base case
  if (x == 0)//it means for amount 0 , 0 coins is required
    return 0;
  if (x < 0)
    return INT_MAX;

// step 3
  if (dp[x] != -1)
    return dp[x];

  int mini = INT_MAX;

// step 2
  for (int i = 0; i < num.size(); i++) {
    int ans = solve(num, x - num[i],dp);
    if (ans != INT_MAX) {
      mini = min(mini, ans + 1);//one is added for current coin
    }
  }
  dp[x]=mini;
  return mini;
}
int minimumElements(vector<int> &num, int x) {// x = amount
  // Write your code here.
  int n = num.size();
  vector<int> dp(x+1, -1);// it basically denotes the minimum number of coins required to form the amount x
  int ans = solve(num, x, dp);
  if (ans != INT_MAX)
    return ans;
  return -1;
}




// bottom up approach using tabulation method

int solve(vector<int> num, int x) {

  vector<int> dp(x + 1, INT_MAX);
  // base case
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < num.size(); j++) {
      if (i - num[j] >= 0 /*whether its a valid index*/ && dp[i - num[j]] != INT_MAX /*to avoid integer overflow*/)
      {
        dp[i] = min(dp[i], dp[i - num[j]] + 1);
      }
    }
  }
  if (dp[x] == INT_MAX)
    return -1;

  return dp[x];
}
int minimumElements(vector<int> &num, int x) {
  // Write your code here.
  return solve(num, x);
  
}