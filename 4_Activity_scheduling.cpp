// C++ program for activity selection problem.

// The following implementation assumes that the activities
// are already sorted according to their finish time
#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    cout << "Following activities are selected" << endl;

    // The first activity always gets selected
    i = 0;
    cout << i+1 << " ";

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i]) {
            cout << j << " ";
            i = j;
        }
    }
}

// Driver code
int main()
{
    cout << "Enter the number of activities: " << endl;
    int n;
    cin>>n;
    int s[n];
    int f[n];
    cout << "Start times: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    cout << "Finish times: ";
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    
    // Function call
    printMaxActivities(s, f, n);
    return 0;
}