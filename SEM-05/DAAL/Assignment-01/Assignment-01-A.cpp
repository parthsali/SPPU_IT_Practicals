#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void printTable(vector<vector<float>> items, bool isResult)

{

    const int cellWidth = 10;

    cout << setw(cellWidth) << left << "Profit     |";
    cout << setw(cellWidth) << left << "Weight     |";
    if (isResult)
        cout << setw(cellWidth) << left << "Fraction    |";
    else
        cout << setw(cellWidth) << left << "P/W        |";

    cout << endl;

    for (int i = 0; i < 3; ++i)
        cout << "+----------+";

    cout << endl;
    for (int i = 0; i < items.size(); i++)
    {

        cout << setfill(' ') << setw(cellWidth) << left << items[i][1] << " |";
        cout << setw(cellWidth) << left << items[i][2] << " |";
        cout << setw(cellWidth) << left << items[i][0] << " |";
        cout << endl;
    }
    cout << endl;
}

void takeInput(vector<vector<float>> &items, int &n, float &weight)
{

    cout << "Enter number of items :- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float profit, weight, pw;
        cout << "Enter profit for " << i + 1 << " item : ";
        cin >> profit;
        cout << "Enter Weight for " << i + 1 << " item : ";
        cin >> weight;
        cout << endl;
        pw = profit / weight;

        vector<float> item;

        item.push_back(pw);
        item.push_back(profit);
        item.push_back(weight);

        items.push_back(item);
    }

    cout << "Enter maximum weigth allowed : ";
    cin >> weight;
    cout << endl;
    return;
}

int main()
{
    vector<vector<float>> items;
    int n;
    float weight;
    takeInput(items, n, weight);

    cout << "Entered Elements are :   " << endl;
    printTable(items, false);

    sort(items.begin(), items.end());

    vector<vector<float>> result = items;
    float profit = 0;

    for (int i = n - 1; i >= 0; i--)
    {

        if (items[i][2] <= weight)
        {
            weight -= items[i][2];
            profit += items[i][1];
            result[i][0] = 1;
        }
        else
        {
            profit += items[i][1] * (weight / items[i][2]);
            result[i][0] = (weight / items[i][2]);

            weight = 0;
        }
    }

    cout << "Final Result : " << endl;
    printTable(result, true);

    cout << "Final Profit : " << profit << endl;
}