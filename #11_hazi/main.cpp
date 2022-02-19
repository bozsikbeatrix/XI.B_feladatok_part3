#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, hossz, pos, x;
    vector<int>tomb;
    cout << "n=";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "tomb[" << i << "]=";
        cin >> x;
        tomb.push_back(x);
    }
    cout << "pos=";
    cin >> pos;
    cout << "hossz=";
    cin >> hossz;
    for(int i=0; i<pos; i++){
        tomb. erase( tomb. begin() + pos, tomb. begin()+ pos + hossz );

    }
    for(int i=0; i<tomb.size(); i++){
        cout << tomb[i] << " ";
    }


    return 0;
}
