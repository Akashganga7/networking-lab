#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    ///freopen("in2.txt","rt",stdin);
    ///freopen("out.txt","wt",stdout);

    cout<<"input the number of rows and columns"<<endl;
    lli row,col;
    cin>>row>>col;

    string txt[row+1];

    for(lli i=0;i<row;i++)
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
            txt[i].insert(col,1,'0');
        }
        else
        {
            txt[i].insert(col,1,'1');
        }

    }

    for(lli i=0;i<col+1;i++)
    {
        lli num_i = 0;

        for(lli j=0;j<row;j++)
        {
            if(txt[j][i] == '1')
            {
                num_i++;
            }
        }

        if(num_i%2 == 0)
        {
            txt[row].insert(i,1,'0');
            //txt[4][i] == '0';
        }
        else
        {
            txt[row].insert(i,1,'1');
            //txt[4][i] == '1';
        }
    }

    for(lli i=0;i<row+1;i++)
    {
        cout<<txt[i]<<endl;
    }

    return 0;
}

