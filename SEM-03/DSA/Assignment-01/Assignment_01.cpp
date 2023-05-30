#include <iostream>
using namespace std;

struct studentInfo
{
    string name;
    int roll;
    float sgpa;
};

void getStudentInfo(struct studentInfo s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << (i + 1) << endl;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter Roll No: ";
        cin >> s[i].roll;
        cout << "Enter SGPA: ";
        cin >> s[i].sgpa;
        cout << endl;
    }
}
void displayStudent(struct studentInfo s[], int n, int keyIndex)
{
    cout << "Name: " << s[keyIndex].name << endl;
    cout << "Roll No: " << s[keyIndex].roll << endl;
    cout << "SGPA: " << s[keyIndex].sgpa << endl;
    cout << endl;
}

void displayInfo(struct studentInfo s[], int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << "Name: " << s[i].name << endl;
        cout << "Roll No: " << s[i].roll << endl;
        cout << "SGPA: " << s[i].sgpa << endl;
        cout << endl;
    }
}

void bubbleSortForRollNum(struct studentInfo s[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                swap(s[j].roll, s[j + 1].roll);
                swap(s[j].name, s[j + 1].name);
                swap(s[j].sgpa, s[j + 1].sgpa);
            }
        }
    }
}

void bubbleSortForSGPA(struct studentInfo s[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (s[j].sgpa < s[j + 1].sgpa)
            {
                swap(s[j].roll, s[j + 1].roll);
                swap(s[j].name, s[j + 1].name);
                swap(s[j].sgpa, s[j + 1].sgpa);
            }
        }
    }
    if (n >= 10)
    {
        cout << "List of Top 10 Students According to SGPA\n\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "Rank : " << (i + 1) << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Roll No: " << s[i].roll << endl;
            cout << "SGPA: " << s[i].sgpa << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "List of Top Students According to SGPA\n\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Rank : " << (i + 1) << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Roll No: " << s[i].roll << endl;
            cout << "SGPA: " << s[i].sgpa << endl;
            cout << endl;
        }
    }
}

void bubbleSortForNames(struct studentInfo s[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (s[j].name > s[j + 1].name)
            {
                swap(s[j], s[j + 1]);
                // swap(s[j].roll, s[j + 1].roll);
                // swap(s[j].name, s[j + 1].name);
                // swap(s[j].sgpa, s[j + 1].sgpa);
            }
        }
    }
}

void searchStudentwrtSGPA(struct studentInfo s[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == key)
        {
            cout << "Student Info: \n"
                 << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Roll No: " << s[i].roll << endl;
            cout << "SGPA: " << s[i].sgpa << endl;
            cout << endl;
        }
    }
}

int searchStudentwrtName(struct studentInfo s[], string key, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (s[mid].name == key)
        {
            return mid;
        }
        else if (s[mid].name < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Student Information.\n"
         << endl;
    int n;
    cout << "Enter Number of Students: ";
    cin >> n;

    struct studentInfo s[n];

    getStudentInfo(s, n);

    while (true)
    {
        // Main Menu.
        cout << "Enter" << endl;
        cout << "1.Arrange List of Student According to Roll Numbers." << endl;
        cout << "2.Arrange List of Student Alphabetically." << endl;
        cout << "3.Arrange List of Student to Find Out First 10 Toppers of Class." << endl;
        cout << "4.Search Student According to SGPA." << endl;
        cout << "5.Search Student According to Name." << endl;
        cout << "6.Exit" << endl;
        cout << "\n";

        int ope;
        cout << "Enter Your Choice: ";
        cin >> ope;
        cout << "\n";

        if (ope == 1)
        {
            cout << "list of The Students According to Roll Numbers.\n\n";
            bubbleSortForRollNum(s, n);
            displayInfo(s, n);
        }
        else if (ope == 2)
        {
            bubbleSortForNames(s, n);
            displayInfo(s, n);
        }
        else if (ope == 3)
        {
            bubbleSortForSGPA(s, n);
        }
        else if (ope == 4)
        {
            cout << "Searching Student with SGPA.\n";
            float key;
            cout << "Enter SGPA: ";
            cin >> key;
            cout << "\n";

            searchStudentwrtSGPA(s, n, key);
        }
        else if (ope == 5)
        {
            bubbleSortForNames(s, n);
            cout << "Searching Student with Name." << endl;
            string key;
            cout << "Enter Name : ";
            cin >> key;
            cout << endl;
            int keyIndex = searchStudentwrtName(s, key, n);
            displayStudent(s, n, keyIndex);
        }
        else if (ope == 6)
        {
            break;
        }
        else
        {
            cout << "Enter Valid Input..";
        }
    }

    return 0;
}