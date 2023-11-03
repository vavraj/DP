/*
you-are-given-an-array-of-distinct-integers-and-you-have-to-tell-how-many-
different-ways-of-selecting-the-elements-from-the-array-are-there-such-that-the-
sum-of-chosen-elements-is-equal-to-the-target-number-tar
*/

#include <iostream>
using namespace std;

int solve(vector<int> &num, int tar)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans = ans + solve(num, tar - num[i]);
    }
    return ans;

}
int findWays(vector<int> &num, int tar)
{

    return solve(num, tar);
}





// recursion + memoization

int solve(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    if (dp[tar] != -1)
    {
        return dp[tar];
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans = ans + solve(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, -1);
    return solve(num, tar, dp);
}






// tabulation
int solve(vector<int> &num, int tar)
{

    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] = dp[i] + dp[i - num[j]];
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar) { return solve(num, tar); }