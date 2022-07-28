#include <iostream>
using namespace std;

int mostFrequent(int& arr[], int n)
{
    
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

// driver program
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
  
    cout << mostFrequent(arr, n);
    return 0;
}
