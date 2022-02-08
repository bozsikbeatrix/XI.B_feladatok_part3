#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, x;
    vector<int>tomb;
    cout << "n=";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "tomb[" << i << "]=";
        cin >> x;
        tomb.push_back(x);
    }
    cout << "k=";
    cin >> k;
    for(int i=0; i<k; i++){
        tomb.pop_back();
    }
    n=n-k;
    for(int i=0; i<n; i++){
        cout << tomb[i] << " ";
    }
    return 0;
}
