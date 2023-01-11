int minEatingSpeed(vector<int> &arr, int h)
{
  int maxE = arr[0];
  for (int i = 0; i < arr.size(); i++)
  {
    maxE = max(maxE, arr[i]);
  }

  int ans;
  
  int high = maxE, low = 1;
  while (low <= high)
  {
    int mid = (low + high)/2;
    int countH = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      countH += ceil((double)arr[i] /(double)mid);
    }
    if (countH == h)
    {
      return mid;
    }
    if (countH < h)
    {
      ans = min(ans,mid);
      high = mid - 1;
    }
    if (countH > h)
    {
      low = mid + 1;
    }
  }
  return ans;
}
int main()
{
  vector<int> arr{3,6,7,11};
  cout << minEatingSpeed(arr,8);
}
