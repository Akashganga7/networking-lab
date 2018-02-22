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

int main()
{
    string ip[4];
    char ch;

    int k=0;
    while(scanf("%c",&ch)&&ch!='\n')
    {
        if(ch=='.')
        {
            k++;
        }
        else ip[k]+=ch;
    }

    bool valid_content = true,valid_length = true;
    stringstream ss;



    for(int i=0; i<4; i++)
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
