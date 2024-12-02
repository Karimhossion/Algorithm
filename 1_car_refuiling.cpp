#include<iostream>
using namespace std;
int min_refills(int x[], int L, int n)
{
    int num_refill=0 ,current_refil=0;
    while (current_refil<=n)
    {
        int last_refil=current_refil;
        while (current_refil<=n && x[current_refil+1]-x[last_refil]<=L)
        {
            current_refil=current_refil+1;
        }
        if (current_refil==last_refil)
        {
            return -1;
        }
        if (current_refil<=n)
        {
            num_refill=num_refill+1;
        }
    }
    return num_refill;
}
int main()
{
    int n,L,d;

    cout<<"Destination : ";
    cin>>d;
    
    cout<<"Ful tank : ";
    cin>>L;

    cout<<"Gas station Number : ";
    cin>>n;

    int x[n+1];
    
    cout<<"Station distance: ";
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
    }

    x[0]=0;
    x[n+1]=d;

    int result=min_refills(x,L,n);

    if (result==-1)
    {
        cout<<"Impossible";
    }
    else
    {
        cout<<"Minimum refill : "<<result;
    }
    return 0;
}