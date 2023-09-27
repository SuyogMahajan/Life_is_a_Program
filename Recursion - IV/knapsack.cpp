#include <iostream>
using namespace std;

// given some n products with there prices in a shop , roberr
// comes to rob the shop his bag capacity is w find max
// profit he can make.

int knapsack(int n, int cap, int till_now, int *price, int *wt)
{
    // base case
    if (n == 0 or cap == 0)
        return till_now;

    // there are 2 possibilities we include product or we dont
    // and then we will return max between them;
    int include_prod = 0, exclude_prod = 0;

    if (cap - wt[n - 1] >= 0)
    {
        include_prod = knapsack(n - 1, cap - wt[n - 1], till_now + price[n - 1], price, wt);
    }
    exclude_prod = knapsack(n - 1, cap, till_now, price, wt);

    return max(include_prod, exclude_prod);
}

int main()
{

    int n;
    cin >> n;

    int price[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int cap;
    cin >> cap;

    cout << knapsack(n, cap, 0, price, wt) << endl;

    return 0;
}