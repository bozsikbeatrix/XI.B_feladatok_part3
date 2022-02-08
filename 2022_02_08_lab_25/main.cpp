#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int>tomb;
    cout << "n=";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "tomb[" << i << "]=";
        int aux;
        cin >> aux;
        tomb.push_back(aux);
    }
    for(int i=0; i<n; i++){
        cout << tomb[i] << " ";
    }
    return 0;
}
