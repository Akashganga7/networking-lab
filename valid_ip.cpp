#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool find_char(string str)
{
    for(lli i=0; i<str.size(); i++)
    {
        for(char c = 'a'; c<='z'; c++)
        {
            if(str[i]== c)
            {
                //cout<<c<<" hi"<<endl;

                return false;
            }
        }

        for(char c = 'A'; c<='Z'; c++)
        {
            if(str[i]== c)
            {
                //cout<<c<<" hi"<<endl;

                return false;
            }
        }
    }

    return true;
}

vector<string> spilt_by_char(string line)
{
    stringstream ss(line);
    string parts;
    vector<string> tokens;

    while(getline(ss,parts,'.'))
    {
        tokens.push_back(parts);
    }

    return tokens;
}

int main()
{
    string input_ip;
    getline(cin,input_ip);

    vector<string> ip = spilt_by_char(input_ip);

    /*
    for(lli i=0;i<ip.size();i++)
    {
        cout<<ip[i]<<endl;
    } */

    bool valid_content = true,valid_length = true;
    stringstream ss;

    for(int i=0; i<ip.size(); i++)
    {
        ss.clear();

        if((ip[i][0]=='0' && ip[i].size() != 1) || ip[i].size() == 0)
        {
            valid_content = false;
            break;
        }

        bool temp = find_char(ip[i]);

        if(!temp)
        {
            valid_content=false;
            break;
        }

        ///string to int conversion

        ss<<ip[i];

        int intg;

        ss>>intg;

        if(intg >254)
        {
            valid_length = false;
            break;

        }

    }

    if(valid_content && valid_length)
    {
        cout << "IP address is valid.";
    }

    else
    {
        cout << "IP address is invalid.";
    }

    return 0;
}
