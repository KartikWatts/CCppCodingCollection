#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string solve(int N, string S)
{
  int n = S.size();
  unordered_map<char, int> charCount;
  int maxFrequency = 0;
  string str = "";

  for (int i = 0; i < n; i++)
  {
    char currChar = S[i];
    charCount[currChar]++;
    if (charCount[currChar] >= maxFrequency)
    {
      maxFrequency = charCount[currChar];
      if (str.size() == 0)
      {
        str = currChar;
      }
      if (maxFrequency == charCount[str[0]])
      {
        if ((int(currChar) < int(str[0])))
          str = currChar;
      }
      else
      {
        str = currChar;
      }
    }
  }

  return str;
}

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;

  string smallestSubstring = solve(N, S);

  cout << smallestSubstring;

  return 0;
}
