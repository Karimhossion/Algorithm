#include <bits/stdc++.h>
using namespace std;
void lcsAlgom(char *s1, char *s2, int m, int n)
{
    int lcsTable[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                lcsTable[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            }
            else
            {
                lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
    }

    int lcs_length = lcsTable[m][n];
    char lcs[lcs_length + 1];
    lcs[lcs_length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[lcs_length - 1] = s1[i - 1];
            i--;
            j--;
            lcs_length--;
        }
        else if (lcsTable[i - 1][j] > lcsTable[i][j - 1] - 1)
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    lcs_length = lcsTable[m][n];
    cout << "The Lcs : " << lcs << endl;
    cout << "LCS length : " << lcs_length;
}
int main()
{
    int m=0,n=0;
    cout<<"Enter length of 1st sequence : ";
    cin>>m;
    cout<<"Enter first sequence : ";
    char s1[m];
    for (int i = 0; i < m; i++)
    {
        cin>>s1[i];
    }

    cout<<"Enter length of 2nd sequence : ";
    cin>>n;
    cout<<"Enter second sequence : ";
    char s2[n];
    for (int i = 0; i < n; i++)
    {
        cin>>s2[i];
    }

    lcsAlgom(s1, s2, m, n);
    
    
}