 #include <iostream>
using namespace std;

// top down approach --> using recursion
int fib(int n, int *ar)
{
    if (n == 1 || n == 0)
        return n;

    if (ar[n] != -1)
        return ar[n];

    ar[n] = fib(n - 1, ar) + fib(n - 2, ar);
    return ar[n];
}
int main()
{
    int n;
    cin >> n;
    int *ar = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ar[i] = -1;
    }
    cout << fib(n, ar);
    return 0;
}



// bottom up approach--> using tabulation
void fib()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}


// space optimaization --> TC=O(1)
void fib()
{
    int n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << n;
        return;
    }

    int ans = 0;
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    cout << ans;
}