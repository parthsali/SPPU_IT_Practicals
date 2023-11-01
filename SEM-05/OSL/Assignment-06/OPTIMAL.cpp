#include <bits/stdc++.h>
using namespace std;

bool pageFound(int pageReferences, vector<int> &pageFrames);

int findOptimalReplacement(int currentIndex, vector<int> &pageReferences, vector<int> &pageFrames)
{
    int indexToReplace = -1;
    int farthestUse = INT_MIN;

    for (int i = 0; i < pageFrames.size(); i++)
    {
        int nextPageIndex = currentIndex + 1;
        while (nextPageIndex < pageReferences.size())
        {
            if (pageReferences[nextPageIndex] == pageFrames[i])
            {
                if (nextPageIndex > farthestUse)
                {
                    farthestUse = nextPageIndex;
                    indexToReplace = i;
                }
                break;
            }
            nextPageIndex++;
        }

        if (nextPageIndex == pageReferences.size())
        {
            return i;
        }
    }

    return indexToReplace;
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
    cout << endl;
    cout << "Number of Fault Generated are :- " << fault << endl;
    cout << "Number of hits are :- " << hit << endl;
}

int main()
{
    cout << "Enter the number of pages: ";
    int pageCount;
    cin >> pageCount;

    cout << "Enter the page reference : ";
    vector<int> pageReferences(pageCount);
    for (int i = 0; i < pageCount; i++)
    {
        cin >> pageReferences[i];
    }

    cout << "Enter the page frame size: ";
    int pageFrameSize;
    cin >> pageFrameSize;

    vector<int> pageFrames(pageFrameSize, -1);
    vector<char> pageStatus(pageCount, 'Y');
    vector<vector<int>> view;

    int hit = 0;
    int miss = 0;

    for (int i = 0; i < pageCount; i++)
    {
        if (pageFound(pageReferences[i], pageFrames))
        {
            pageStatus[i] = 'N';
            view.push_back(pageFrames);
        }
        else
        {
            int index = findOptimalReplacement(i, pageReferences, pageFrames);
            pageFrames[index] = pageReferences[i];
            view.push_back(pageFrames);
        }
    }

    for (int i = 0; i < pageCount; i++)
    {
        cout << pageReferences[i] << "\t";
    }
    cout << endl;
    

    for (int i = 0; i < pageFrameSize; i++)
    {
        for (int j = 0; j < view.size(); j++)
        {
            if (view[j][i] == -1)
                cout << "X"
                     << "\t";
            else
                cout << view[j][i] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < pageCount; i++)
    {
        cout << pageStatus[i] << "\t";
    }
    cout << endl;

    hitG(pageStatus);
}

bool pageFound(int pageReferences, vector<int> &pageFrames)
{
    for (int i = 0; i < pageFrames.size(); i++)
    {
        if (pageFrames[i] == pageReferences)
        {
            return true;
        }
    }
    return false;
}