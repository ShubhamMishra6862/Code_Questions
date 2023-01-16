#include <bits/stdc++.h>
using namespace std;

int countdiff(vector<int> &nums, int diff)
{

    int gcount = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int high = i - 1;
        int low = 0;
        int count = i;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[i] - nums[mid] > diff)
            {
                low = mid + 1;
            }
            else
            {
                count = mid;
                high = mid - 1;
            }
        }
        gcount += (i - count);
    }
    return gcount;
}
int kthSmall(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int high = nums[nums.size() - 1] - nums[0];
    int low = 0;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = countdiff(nums, mid);
        cout << mid << " || " << count << endl;
        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{1, 3, 1};
    int k = 1;
    cout << kthSmall(nums, k);
}
