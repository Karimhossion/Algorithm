#include <bits/stdc++.h>
using namespace std;
void sorting (int name[], int s[], int f[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (f[i]>f[j])
            {
                temp = name[i];
                name[i]= name[j];
                name[j]=temp;

                temp = s[i];
                s[i] = s[j];
                s[j] = temp;

                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }
}

void activity (int name[], int s[], int f[], int n)
{
    int act[n], act_count=0;

    act[act_count]=name[0];
    int k=0;
    for (int i = 1; i < n; i++)
    {
        if (s[i]>=f[k])
        {
            act[++act_count]=name[i];
            k=i;
        }
    }

    cout<<"Activity name : ";
    for (int i = 0; i <= act_count; i++)
    {
        cout<<act[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of activity : ";
    cin>>n;

    int name[n], s[n],f[n];

    cout<<"Enter name of activity : ";
    for (int i = 0; i < n; i++)
    {
        cin>>name[i];
    }
    cout<<"Enter start of activity : ";
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    cout<<"Enter finish of activity : ";
    for (int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    sorting(name, s,f,n);
    activity(name, s, f, n);  
}