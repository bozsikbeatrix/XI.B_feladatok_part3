#include <iostream>
#include <vector>
using namespace std;
int N = 5;
int szamlalo=2;
string virag[] = {"PHP", "Java", "Python", "C++", "MatLab"};

bool lehet(vector<string> ruhak, string ujruha)
{
    for(int i = 0; i<ruhak.size(); i++)
    {
        if (ruhak[i] == ujruha)
        {
            return false;
        }
    }
    if (ujruha == "Java")
    {
        for(int i = 0; i<ruhak.size(); i++)
        {

            if (ruhak[i] == "Python")
            {
                return false;
            }
        }


    }
    if (ujruha == "Python")
    {
        for(int i = 0; i<ruhak.size(); i++)
        {
            if (ruhak[i] == "Java")
            {
               return false;
            }

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
void backtrack(vector<string> koktel, int index)
{

    if (koktel.size()%2 == 0)
    {

        kiir(koktel);

    }

    for(int i = 0; i<5; i++)
    {
        if (lehet(koktel, virag[i]))
        {

            vector<string> tempcsokor;
            for(int j = 0; j<koktel.size(); j++)
            {
                tempcsokor.push_back(koktel[j]);
            }
            tempcsokor.push_back(virag[i]);
            backtrack(tempcsokor, i);
        }
    }


}
int main()
{
    vector<string> koktel;

    backtrack(koktel, 0);
    return 0;
}
