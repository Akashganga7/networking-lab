#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    freopen("in.txt","rt",stdin);

    string txt[5];

    for(lli i=0;i<=3;i++)
    {
        cin>>txt[i];

        lli num_i = 0;

        for(lli j=0;j<txt[i].size();j++)
        {
            if(txt[i][j] == '1')
            {
                num_i++;
            }
        }

        if(num_i%2 == 0)
        {
            txt[i].insert(7,1,'0');
        }
        else
        {
            txt[i].insert(7,1,'1');
        }

    }

    for(lli i=0;i<8;i++)
    {
        lli num_i = 0;

        for(lli j=0;j<=3;j++)
        {
            if(txt[j][i] == '1')
            {
                num_i++;
            }
        }

        if(num_i%2 == 0)
        {
            txt[4].insert(i,1,'0');
            //txt[4][i] == '0';
        }
        else
        {
            txt[4].insert(i,1,'1');
            //txt[4][i] == '1';
        }
    }

    for(lli i=0;i<5;i++)
    {
        cout<<txt[i]<<endl;
    }

    return 0;
}
