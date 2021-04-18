#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> splitStrings(string str, char dl)
{
    string word = "";
    int num = 0;
    str = str + dl;
    int l = str.size();

    vector<string> substr_list;
    for (int i = 0; i < l; i++)
    {
        if (str[i] != dl)
            word = word + str[i];
        else
        {
            if ((int)word.size() != 0)
                substr_list.push_back(word);
            word = "";
        }
    }

    return substr_list;
}

vector<string> getWordsMap(string wordsGroup)
{
    char dl = ';';
    vector<string> terms = splitStrings(wordsGroup, dl);
    return terms;
}

bool isValidVertical(string str[10], string term, int row, int col)
{
    if (row + term.length() > 10)
    {
        return false;
    }
    for (int i = 0; i < term.length(); i++)
    {
        if (str[row + i][col] != '-' && str[row + i][col] != term[i])
        {
            return false;
        }
    }
    return true;
}

bool isValidHorizontal(string str[10], string term, int row, int col)
{
    if (col + term.length() > 10)
    {
        return false;
    }
    for (int i = 0; i < term.length(); i++)
    {
        if (str[row][col + i] != '-' && str[row][col + i] != term[i])
        {
            return false;
        }
    }
    return true;
}

bool backTrackCross(string str[10], vector<string> terms, int index)
{

    if (index == terms.size())
    {
        cout << "\n\nFINAL ANSWER:\n";
        for (int i = 0; i < 10; i++)
        {
            cout << str[i] << endl;
        }

        return true;
    }
    cout << "Index: " << index << "\t Term: " << terms[index] << endl;
    cout << "Current CrossWord looks like: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << endl;
    }
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (str[row][col] == '-' || str[row][col] == terms[index][0])
            {
                if (isValidVertical(str, terms[index], row, col))
                {
                    string term = terms[index];
                    cout << "The Term `" << term << "` may be filled at " << row << ", " << col << endl;
                    int len = term.length();
                    bool helper[len];
                    for (int i = 0; i < len; i++)
                    {
                        if (str[row + i][col] == '-')
                        {
                            str[row + i][col] = term[i];
                            helper[i] = true;
                        }
                        else
                        {
                            helper[i] = false;
                        }
                    }
                    index++;
                    if (backTrackCross(str, terms, index))
                    {
                        cout << "Success: The Term `" << term << "` filled succesfully at " << row << ", " << col << endl;
                        return true;
                    }
                    else
                    {
                        index--;
                        cout << "Failure: The Term `" << term << "` can't be filled at " << row << ", " << col << endl;
                        for (int i = 0; i < len; i++)
                        {
                            if (helper[i] == true)
                            {
                                str[row + i][col] = '-';
                            }
                        }
                    }
                }
                if (isValidHorizontal(str, terms[index], row, col))
                {
                    string term = terms[index];
                    cout << "The Term `" << term << "` may be filled at " << row << ", " << col << endl;
                    int len = term.length();
                    bool helper[len];
                    for (int i = 0; i < len; i++)
                    {
                        if (str[row][col + i] == '-')
                        {
                            str[row][col + i] = term[i];
                            helper[i] = true;
                        }
                        else
                        {
                            helper[i] = false;
                        }
                    }
                    index++;
                    if (backTrackCross(str, terms, index))
                    {
                        cout << "Success: The Term `" << term << "` filled succesfully at " << row << ", " << col << endl;
                        return true;
                    }
                    else
                    {
                        index--;
                        cout << "Failure: The Term `" << term << "` can't be filled at " << row << ", " << col << endl;
                        for (int i = 0; i < len; i++)
                        {
                            if (helper[i] == true)
                            {
                                str[row][col + i] = '-';
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    string str[10], wordsGroup;
    for (int i = 0; i < 10; i++)
    {
        cin >> str[i];
    }
    cin >> wordsGroup;
    vector<string> terms = getWordsMap(wordsGroup);
    backTrackCross(str, terms, 0);
}