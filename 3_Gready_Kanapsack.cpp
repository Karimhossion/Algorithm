#include <iostream>
using namespace std;
void Knapsack(int w[], int v[], int length, int W, float *tv, float sw[])
{
    float vs=0;
    for (int i = 0; i < length; i++)
    {
        if (W==0)
        {
            *tv=vs;
            return;
        }
        int a=min(w[i],W);
        vs=vs+a*(v[i]/w[i]);
        w[i]=w[i]-a;
        sw[i]=a;
        W=W-a;
    }
    *tv=vs;
    return;
}
int main()
{
    int n;
    cout<<"Enter number of Items : ";
    cin>>n;

    int weight[n],price[n];
    cout<<"Enter weight of Iteam w: ";
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter Price of Iteam v : ";
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }

    int W;
    cout<<"Enter Capacity W : ";
    cin>>W;

    float tv=0, sw[n];
    Knapsack(weight, price, n, W, &tv, sw);

    cout<<"Minimum Total value : "<<tv<<endl;
    return 0;
}