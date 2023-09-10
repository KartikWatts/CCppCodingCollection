//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  vector<int> quadraticRoots(int a, int b, int c)
  {
    vector<int> roots;
    int commonRoot = pow(b, 2) - 4 * a * c;

    if (commonRoot < 0)
    {
      roots.emplace_back(-1);
      return roots;
    }
    else
    {
      double squareRootCommon = sqrt(commonRoot);
      int root1 = floor((-b + squareRootCommon) / (2 * a));
      int root2 = floor((-b - squareRootCommon) / (2 * a));
      if (root1 > root2)
      {
        roots.emplace_back(root1);
        roots.emplace_back(root2);
      }
      else
      {
        roots.emplace_back(root2);
        roots.emplace_back(root1);
      }
    }
    return roots;
  }
};

//{ Driver Code Starts.

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    Solution ob;
    vector<int> roots = ob.quadraticRoots(a, b, c);
    if (roots.size() == 1 && roots[0] == -1)
      cout << "Imaginary";
    else
      for (int i = 0; i < roots.size(); i++)
        cout << roots[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends