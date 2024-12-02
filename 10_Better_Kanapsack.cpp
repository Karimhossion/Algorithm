#include <bits/stdc++.h>
using namespace std;
int kanapsack(int W, int w[], int v[], int n)
{
    int V=0;
    for (int i = 0; i < n; i++)
    {
        if (W==0)
        {
            return V;
        }
        int a = min(w[i], W);
        V = V + a*(v[i]/w[i]);
        w[i]=w[i] - a;
        W=W-a;
    }
    return V;
}
int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int weight[n], item[n];
    cout<<"Enter Weight : ";
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter Item : ";
    for (int i = 0; i < n; i++)
    {
        cin>>item[i];
    }

    int W;
    cout<<"W : ";
    cin>>W;
    int result = kanapsack(W, weight,item, n);
    cout<<"Price : "<< result<<endl;
    return 0; 
}