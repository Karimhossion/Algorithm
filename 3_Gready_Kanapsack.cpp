#include <iostream>
using namespace std;
void knapsack(int weights[], int values[], int length, int capacity, float *totalValue, float selectedWeights[]) {
    float valueSum = 0;
    for (int i = 0; i < length; i++) {
        if (capacity == 0) {
            *totalValue = valueSum;
            return;
        }
        int amount = min(weights[i], capacity);
        valueSum = valueSum + amount * (values[i] / weights[i]);
        weights[i] = weights[i] - amount;
        selectedWeights[i] = amount;      
        capacity = capacity - amount;
    }
    *totalValue = valueSum;
    return;
}
int main()
{
    int n;
    cout<<"Enter number of Items : ";
    cin>>n;
    int weight[n], price[n];

    cout<<"Enter weight of items : ";
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter price of items : ";
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }

    int W;
    cout<<"Enter Capacity : ";
    cin>>W;
    float totalvalue=0, selectedWeights[n];

    knapsack(weight, price, n, W, &totalvalue, selectedWeights);

    cout<<"Maximum Total value : "<<totalvalue<<endl;

  /*  cout << "Selected weights of items: ";
    for (int i = 0; i < n; i++) {
        cout << selectedWeights[i] << " ";
    }*/
    cout << endl;

    return 0;    
}