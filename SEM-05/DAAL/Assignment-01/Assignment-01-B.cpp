#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);
 
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}
 
void quicksort(int arr[], int start, int end)
{
    if (start < end) {
        int pi = partition(arr, start, end);
 
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

pair<int, vector<int>> knapsack_01(int W, int n, vector<vector<int>> data){
    vector<vector<int>> table;
    vector<int> row(W+1, 0);
    for(int i=0; i<=n; i++){
        table.push_back(row);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if (j < data[i-1][0]){
                table[i][j] = table[i-1][j];
            }else{
                table[i][j] = max(table[i-1][j], data[i-1][1] + table[i-1][j - data[i-1][0]]);
            }
        }
    }

    cout << "\nTable" << endl;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    pair<int, vector<int>> ans;
    ans.first = table[n][W];

    vector<int> select;

    int k = W;
    for(int i=n; i>0; i--){
        if (table[i-1][k] != table[i][k]){
            select.push_back(i);
            k -= data[i-1][0];
        }
    }
    ans.second = select;
    return ans;
}



int main(){
    vector<vector<float>> list;
    vector<vector<int>> list_dp;
    cout << "Enter Total Capacity of Sack: ";
    int W;
    cin >> W;
    cout << endl;
    cout << "Enter Number of Items: ";
    int n;
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++){
        int item, weight, profit;
        float pw;
        item = i+1;
        cout << "Enter Weight for Item " << item << " :";
        cin >> weight;
        cout << "Enter Profit for Item " << item << " :";
        cin >> profit;
        pw = float(profit)/float(weight);
        vector<int> temp_dp;
        vector<float> temp;
        temp.push_back(pw);
        temp.push_back(item);
        temp.push_back(weight);
        temp.push_back(profit);
        list.push_back(temp);
        temp_dp.push_back(weight);
        temp_dp.push_back(profit);
        list_dp.push_back(temp_dp);
        cout << endl;
    }
    cout << endl;

    cout << "Entered Details are: "<< endl;
    cout << "Item\tWeight\tProfit\tP/W" <<endl;
    for(int i=0; i<n; i++){
        cout << list[i][1] << "\t" << list[i][2] <<"\t"<<list[i][2]<<"\t"<<list[i][0];
        cout << endl;
    }
    cout << endl;

    int choice=0;
    while(choice != -1){
        cout << "\nSelect The Method to Solve: 1 for Fractional Knapsack\t2 to Compare DP to Greedy\n-1 to Exit" << endl;
        cin >> choice;
        if (choice == 1){
            sort(list.begin(),list.end());

            float pro = 0;
            int curr_w = 0;
            vector<float> select(n,0);
            for(int i=n-1; i>=0; i--){
                if (curr_w + list[i][2] <= W){
                    curr_w += list[i][2];
                    pro += list[i][3];
                    select[int(list[i][1])-1] = 1;
                }else{
                    pro += (W-curr_w)*list[i][0];
                    select[int(list[i][1])-1] = (W-curr_w)/list[i][2];
                    curr_w = W;
                }
            }
            cout << "Max Profit : " << pro << endl;
            cout << endl;
            cout << "Selected Items: " << endl;
            for(int i=0; i<n; i++){
                cout << select[i] << " ";
            }
            cout << endl;

        }else if(choice == 2){
            sort(list.begin(),list.end());
            cout << "Greedy 0/1 Approach" << endl;
            float pro = 0;
            int curr_w = 0;
            vector<float> select(n,0);
            for(int i=n-1; i>=0; i--){
                if (curr_w + list[i][2] <= W){
                    curr_w += list[i][2];
                    pro += list[i][3];
                    select[int(list[i][1])-1] = 1;
                }
            }
            cout << "Max Profit : " << pro << endl;
            cout << endl;
            cout << "Selected Items: " << endl;
            for(int i=0; i<n; i++){
                cout << select[i] << " ";
            }
            cout << endl;

            cout << "DP 0/1 Approach" << endl;
            pair<int, vector<int>> ans = knapsack_01(W, n, list_dp);

            cout << "Maximum Profit Possible for given Knapsack is : " << ans.first << endl;
            cout << "Selected Items Numbers are : " << endl;
            for(int i=0; i<ans.second.size(); i++){
                cout << ans.second[i] << " ";
            }
            cout << endl;
            cout << "From this Example it can be concluded that DP approach will always provide Optimal solution from Greedy." << endl;
        }else if (choice == -1){
            cout << "Exiting ....." << endl;
        }else{
            cout << "Enter Valid Choice: " << endl;
        }
    }
}