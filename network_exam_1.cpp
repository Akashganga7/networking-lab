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

    int detect_class;

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

        if(i==0)
        {
            detect_class = intg;
        }

        if(intg >255)
        {
            valid_length = false;
            break;

        }

    }

    if(valid_content && valid_length)
    {
        if(detect_class>=0 && detect_class<=127)
        {
            cout<<"Class A"<<endl;
        }

        if(detect_class>=128 && detect_class<=191)
        {
            cout<<"Class B"<<endl;
        }

        if(detect_class>=192 && detect_class<=223)
        {
            cout<<"Class C"<<endl;
        }

        if(detect_class>=224 && detect_class<=239)
        {
            cout<<"Class D"<<endl;
        }

        if(detect_class>=240 && detect_class<=255)
        {
            cout<<"Class E"<<endl;
        }

    }

    else
    {
        cout << "IP address is invalid.";
    }

}

