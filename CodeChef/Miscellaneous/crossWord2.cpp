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

vector<string> getWordsMap(string wordsGroup)
{
    char dl = ';';
    vector<string> terms = splitStrings(wordsGroup, dl);
    return terms;
}

bool isValidVertical(int r, int c, string str[11], string term)
{
    if (term.length() + r > 10)
    {
        return false;
    }

    for (int i = r; i < term.length() + r; i++)
    {
        if (str[i][c] != '-' && str[i][c] != term[i - r])
        {
            return false;
        }
    }
    return true;
}

bool isValidHorizontal(int r, int c, string str[11], string term)
{
    if ((term.length() + c) > 10)
    {
        return false;
    }

    for (int i = c; i < term.length() + c; i++)
    {
        // cout << "Checking for row " << r << "col " << i << " Str: " << str[r][i] << " Term index:" << term[i - c] << endl;
        if (str[r][i] != '-' && str[r][i] != term[i - c])
        {
            return false;
        }
    }
    return true;
}

void setVertical(int r, int c, string str[11], string term)
{
    for (int i = r; i < r + term.length(); i++)
    {
        if (str[i][c] == '-')
        {
            str[i][c] = term[i - r];
        }
    }
}

void setHorizontal(int r, int c, string str[11], string term)
{
    for (int i = c; i < c + term.length(); i++)
    {
        if (str[r][i] == '-')
        {
            str[r][i] = term[i - c];
        }
    }
}

void resetHorizontal(int r, int c, string str[11], bool *helper, int len)
{
    cout << "Resetting from point: " << r << " " << c << endl;
    cout << "helper function is as : \t";
    for (int i = 0; i < len; i++)
    {
        cout << helper[i] << " ";
    }

    cout << "String Before\n";
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << endl;
    }

    for (int i = c; i < c + len; i++)
    {
        if (helper[i - c] == true)
        {
            str[r][i] = '-';
        }
    }
    cout << "String Later\n";
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << endl;
    }
}

void resetVertical(int r, int c, string str[11], bool *helper, int len)
{
    cout << "Resetting from point: " << r << " " << c << endl;
    cout << "helper function is as : \t";
    for (int i = 0; i < len; i++)
    {
        cout << helper[i] << " ";
    }
    cout << "String Before\n";
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << endl;
    }

    for (int i = r; i < r + len; i++)
    {
        if (helper[i - r] == true)
        {
            str[i][c] = '-';
        }
    }
    cout << "String Later\n";
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << endl;
    }
}

bool backTrackCross(string str[11], vector<string> terms, int index)
{
    if (index == terms.size())
    {
        for (int i = 0; i < 10; i++)
        {
            cout << str[i] << endl;
        }
        return true;
    }

    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (str[r][c] == '-' || str[r][c] == terms[index][0])
            {
                // cout << "Checking for term: " << terms[index] << " at Point " << r << " " << c << endl;

                if (isValidVertical(r, c, str, terms[index]))
                {
                    int len = terms[index].length();
                    bool helper[len];
                    for (int i = r; i < r + terms[index].length(); i++)
                    {
                        if (str[i][c] == '-')
                        {
                            str[i][c] = terms[index][i - r];
                            helper[i - r] = true;
                        }
                        else
                        {
                            helper[i - r] = false;
                        }
                    }
                    setVertical(r, c, str, terms[index]);
                    for (int i = 0; i < 10; i++)
                    {
                        cout << str[i] << endl;
                    }
                    for (int i = 0; i < terms[index].length(); i++)
                    {
                        cout << helper[i] << " ";
                    }
                    cout << endl;

                    index++;
                    if (backTrackCross(str, terms, index) == true)
                    {
                        return true;
                    }
                    else
                    {
                        resetVertical(r, c, str, helper, len);
                        cout << "String Later\n";
                        for (int i = 0; i < 10; i++)
                        {
                            cout << str[i] << endl;
                        }
                    }
                }

                if (isValidHorizontal(r, c, str, terms[index]))
                {

                    int len = terms[index].length();
                    bool helper[len];
                    for (int i = c; i < c + terms[index].length(); i++)
                    {
                        if (str[r][i] == '-')
                        {
                            str[r][i] = terms[index][i - c];
                            helper[i - c] = true;
                        }
                        else
                        {
                            helper[i - c] = false;
                        }
                    }
                    setHorizontal(r, c, str, terms[index]);
                    for (int i = 0; i < 10; i++)
                    {
                        cout << str[i] << endl;
                    }
                    for (int i = 0; i < terms[index].length(); i++)
                    {
                        cout << helper[i] << " ";
                    }
                    cout << endl;
                    index++;
                    if (backTrackCross(str, terms, index) == true)
                    {
                        return true;
                    }
                    else
                    {
                        cout << "String Before\n";
                        for (int i = 0; i < 10; i++)
                        {
                            cout << str[i] << endl;
                        }
                        resetVertical(r, c, str, helper, len);
                        cout << "String Later\n";
                        for (int i = 0; i < 10; i++)
                        {
                            cout << str[i] << endl;
                        }
                        index--;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    string str[11], wordsGroup;
    for (int i = 0; i < 10; i++)
    {
        cin >> str[i];
    }
    cin >> wordsGroup;
    vector<string> terms = getWordsMap(wordsGroup);
    backTrackCross(str, terms, 0);
}