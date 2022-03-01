#include <iostream>
#include <vector>
using namespace std;
int N = 5;
string virag[] = {"golyostoll", "ceruza", "toltotoll", "ecset", "toll"};

bool lehet(vector<string> ruhak, string ujruha)
{
    for(int i = 0; i<ruhak.size(); i++)
    {
        if (ruhak[i] == ujruha)
        {
            return false;
        }
    }

    if (ujruha == "toltotoll")
    {
        int szamlalo = 0;
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "ceruza")
            {
                szamlalo++;
            }

        }
        if (szamlalo < 1 ) {
            return false;
        }
    }
    if (ujruha == "golyostoll")
    {
        int szamlalo = 0;
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "ceruza")
            {
                szamlalo++;
            }

        }
        if (szamlalo < 1 ) {
            return false;
        }
    }

    return true;
}
void kiir(vector<string> csokor)
{
    for(int i = 0; i<csokor.size(); i++)
    {
        cout << csokor[i] << " " ;
    }
    cout << endl;
    return;
}
void backtrack(vector<string> csokor, int index)
{
    if (csokor.size() == N)
    {
        kiir(csokor);
        return;
    }
    for(int i = 0; i<5; i++)
    {
        if (lehet(csokor, virag[i]))
        {
            vector<string> tempcsokor;
            for(int j = 0; j<csokor.size(); j++)
            {
                tempcsokor.push_back(csokor[j]);
            }
            tempcsokor.push_back(virag[i]);
            backtrack(tempcsokor, i);
        }
    }
}

int main()
{
    vector<string> csokor;
    backtrack(csokor, 0);
    return 0;
}
