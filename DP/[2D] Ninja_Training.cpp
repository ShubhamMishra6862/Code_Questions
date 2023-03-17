#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// MEOIZATION --------------------------------------------------------------------
int DP(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (last != i)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            maxi = max(maxi, (points[day][i] + DP(day - 1, i, points, dp)));
        }
    }
    return dp[day][last] = maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
//    TABULATION PART-----------------------------------------------------
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
    for (int i = 1; i < n; i++)
    {
        for (int last = 0; last < 3; last++)
        {
            dp[i][last] = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                {
                    cout<< points[i][j] << ":" << dp[i - 1][j] << " ";
                    dp[i][last] = max(dp[i][last], points[i][j] + dp[i - 1][j]);
                }
            }
            cout << "=" << dp[i][last] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
