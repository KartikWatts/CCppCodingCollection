#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

vector<string> getFolderNames(vector<string> &names)
{
    map<string, vector<int>> dir;
    vector<string> res;
    std::vector<int>::iterator f;

    for (auto it : names)
    {
        cout << it << endl;
        long long first = 0, last = 0;
        first = it.find("(");
        last = it.find(")");
        // cout<<first<<" "<<last<<endl;
        long long fileVersion;
        string fileName;
        //Agar () hai else nahi hai
        if (first != -1 && last != -1)
        {
            string name = it.substr(0, first);
            fileName = name;
            string ver = it.substr(first + 1, last - first - 1);
            cout << name << " " << ver << endl;
            long long version = stoi(ver);
            f = find(dir[fileName].begin(), dir[fileName].end(), version);
            //Agar() vala version phle se nahi hai else hai
            if (f != dir[fileName].end())
            {
                bool named = false;
                while (named == false)
                {
                    f = find(dir[fileName].begin(), dir[fileName].end(), version);
                    if (f != dir[fileName].end())
                    {
                        version++;
                    }
                    else
                    {
                        fileVersion = version;
                        dir[fileName].push_back(version);
                        named = true;
                    }
                }
            }
            else
            {
                fileVersion = version;
                dir[fileName].push_back(version);
            }
        }
        else
        {
            fileName = it;
            long long ver = 0;
            bool named = false;
            while (named == false)
            {
                f = find(dir[it].begin(), dir[it].end(), ver);
                if (f != dir[it].end())
                {
                    ver++;
                }
                else
                {
                    fileVersion = ver;
                    dir[it].push_back(ver);
                    named = true;
                }
            }
        }

        string fileVersionStr = "", fileNameUltimate;
        if (fileVersion != 0)
        {
            fileVersionStr = to_string(fileVersion);
        }
        if (fileVersion != 0)
        {
            fileNameUltimate = fileName + "(" + fileVersionStr + ")";
        }
        else
        {
            fileNameUltimate = fileName;
        }
        res.push_back(fileNameUltimate);
    }
    return res;
}

int main()
{
    vector<string> names = {"kaido", "kaido(1)", "kaido", "kaido(1)"}, res;
    res = getFolderNames(names);
    cout << "RESULT:::\n";
    for (auto it : res)
        cout << it << endl;
}