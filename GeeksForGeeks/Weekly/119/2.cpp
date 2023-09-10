//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  long long beauty(vector<int> &B, int beautyArray)
  {
  }

public:
  long long maximumBeauty(int N, int K, vector<int> &B)
  {
    int beautyArray[N];
    return beauty(B, N);
  }
};

//{ Driver Code Starts.

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, K;
    cin >> N >> K;
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
      cin >> B[i];
    }
    Solution obj;
    long long ans = obj.maximumBeauty(N, K, B);
    cout << ans << "\n";
  }
}
// } Driver Code Ends