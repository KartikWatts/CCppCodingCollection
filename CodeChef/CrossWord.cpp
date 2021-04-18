#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> splitStrings(string str, char dl)
{
    string word = "";

    // to count the number of split strings
    int num = 0;

    // adding delimiter character at the end
    // of 'str'
    str = str + dl;

    // length of 'str'
    int l = str.size();

    // traversing 'str' from left to right
    vector<string> substr_list;
    for (int i = 0; i < l; i++)
    {

        // if str[i] is not equal to the delimiter
        // character then accumulate it to 'word'
        if (str[i] != dl)
            word = word + str[i];

        else
        {

            // if 'word' is not an empty string,
            // then add this 'word' to the array
            // 'substr_list[]'
            if ((int)word.size() != 0)
                substr_list.push_back(word);

            // reset 'word'
            word = "";
        }
    }

    // return the splitted strings
    return substr_list;
}

map<int, vector<string>> getWordsMap(string wordsGroup)
{
    char dl = ';';
    vector<string> terms = splitStrings(wordsGroup, dl);
    map<int, vector<string>> termsMap;
    for (auto x : terms)
    {
        termsMap[x.length()].push_back(x);
    }
    for (auto it : termsMap)
    {
        cout << "\nFrequency: " << it.first << "\t";
        for (auto v : it.second)
        {
            cout << v << "\t";
        }
    }
    return termsMap;
}

bool findSpaces(string str[10], int &x, int &y)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i][j] == '-')
            {
                x = i, y = j;
                return true;
            }
        }
    }
    return false;
}

bool backTrackCross(string str[10], string wordsGroup, map<int, vector<string>> termsMap)
{
    int x, y;
    if (!findSpaces(str, x, y))
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << str[i][j];
            }
            cout << endl;
        }
        return;
    }
    int i = x, j = y, startX = x, startY = y;
    while (str[x][j] != '+' && j < 10)
    {
        j++;
    }
    while (str[x][j] != '+' && j >= 0)
    {
        startY--;
    }
    while (str[i][y] != '+' && i < 10)
    {
        i++;
    }
    while (str[i][y] != '+' && j >= 0)
    {
        startX--;
    }
    cout << "Ver. Spaces: " << startY - j << "\tHor. Spaces: " << startX - i << endl;
    if (termsMap.find(startY - j) != termsMap.end())
    {
        for (auto sv : termsMap[startY - j])
        {
            for (int k = 0; k < startY - j; k++)
            {
                str[startY][y + i] = sv[k];
            }
            char tStrX = str[x][y];

            if (termsMap.find(startX - i) != termsMap.end())
                for (auto sv2 : termsMap[startX - i])
                {
                    for (int k = 0; k < startX - i; k++)
                    {
                        str[startX][x + i] = sv[k];
                    }
                    if (str[x][y] == tStrX)
                    {
                        wordsGroup.erase(sv2);
                        wordsGroup.erase(sv);
                    }
                }
        }
    }
}

int main()
{
    string str[10], wordsGroup;
    for (int i = 0; i < 10; i++)
    {
        cin >> str[i];
    }
    cin >> wordsGroup;
    map<int, vector<string>> termsMap = getWordsMap(wordsGroup);
    backTrackCross(str, wordsGroup, termsMap);
}