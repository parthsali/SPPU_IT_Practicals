#include <bits/stdc++.h>
using namespace std;

// using forward Declaration

bool isPresentInFrame(int n, vector<int> &v);

bool isFrameFull(vector<int> &v);

void replacePage(int victim, int target, vector<int> &v);

void hitG(vector<char> &v);

int main()
{
    cout << "ENTER THE NUMBER OF PAGES :- ";
    int count;
    cin >> count;

    cout << "Enter the Pages :- ";

    vector<int> processes(count);
    for (int i = 0; i < count; i++)
    {
        cin >> processes[i];
    }

    cout << "Enter the page frame size :- ";
    int pageFrameSize;
    cin >> pageFrameSize;

    vector<int> pageframe(pageFrameSize, -1);
    vector<char> ispf(count, 'Y');
    queue<int> tempQueue;

    for (int i = 0; i < count; i++)
    {
        cout << processes[i] << "  ";
    }
    cout << endl;

    vector<vector<int>> ans;
    bool isf = 0;
    for (int i = 0; i < count; i++)
    {
        if (isPresentInFrame(processes[i], pageframe))
        {
            ispf[i] = 'N';
            ans.push_back(pageframe);
            continue;
        }

        tempQueue.push(processes[i]);

        if (isf == 1 || isFrameFull(pageframe))
        {
            isf = 1;
            int temp = tempQueue.front();
            tempQueue.pop();
            replacePage(temp, processes[i], pageframe);
        }
        else
        {
            pageframe[i] = processes[i];
        }

        ans.push_back(pageframe);
    }

    // Displaying Output
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << processes[i] << "  \t";
    }
    cout << endl;

    for (int i = 0; i < pageFrameSize; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j][i] == -1)
            {
                cout << "X"
                     << "  \t";
                continue;
            }
            else
            {

                cout << ans[j][i] << "  \t";
            }
        }
        cout << endl;
    }
    cout << endl;

    for (auto it : ispf)
        cout << it << "  \t";
    cout << endl;
    cout << endl;
    hitG(ispf);
}

bool isPresentInFrame(int n, vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
        {
            return true;
        }
    }
    return false;
}

bool isFrameFull(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == -1)
            return 0;
    }
    return 1;
}

void replacePage(int victim, int target, vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == victim)
        {
            v[i] = target;
            return;
        }
    }
}

void hitG(vector<char> &v)
{
    int fault = 0;
    int hit = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 'N')
        {
            fault++;
        }
        else
        {
            hit++;
        }
    }

    cout << "Number of Fault Generated are :- " << fault << endl;
    cout << "Number of hits are :- " << hit << endl;
}