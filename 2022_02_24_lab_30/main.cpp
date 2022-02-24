#include <iostream>
#include <vector>
using namespace std;
int N = 5;
string gyumolcsok[] = {"citrom", "alma", "afonya", "korte", "kajszin"};

bool lehet(vector<string> koktel, string ujgyumi)
{
    for(int i = 0; i<koktel.size(); i++)
    {
        if (koktel[i] == ujgyumi)
        {
            return false;
        }
    }
    if (ujgyumi == "citrom")
    {
        bool vanmar = false;
        for(int i = 0; i<koktel.size(); i++)
        {
            if (koktel[i] == "korte")
            {
                vanmar = true;
            }
        }
        if (vanmar) { //!felvettem
            return false;
        }
    }

    if (ujgyumi == "korte")
    {
        bool vanmar = false;
        for(int i = 0; i<koktel.size(); i++)
        {
            if (koktel[i] == "citrom")
            {
                vanmar = true;
            }
        }
        if (vanmar) { //!felvettem
            return false;
        }
    }

    return true;
}
void kiir(vector<string> koktel)
{
    for(int i = 0; i<koktel.size(); i++)
    {
        cout << koktel[i] << " " ;
    }
    cout << endl;
    return;
}
void backtrack(vector<string> koktel, int index)
{
    if (koktel.size()< 5 && koktel.size()>1)
    {
        if(koktel[0]=="afonya" && koktel[koktel.size()-1]=="alma"){
            return;
        }else{

        kiir(koktel);}
        //return;
    }
    for(int i = 0; i<5; i++)
    {
        if (lehet(koktel, gyumolcsok[i]))
        {
            vector<string> tempkoktel;
            for(int j = 0; j<koktel.size(); j++)
            {
                tempkoktel.push_back(koktel[j]);
            }
            tempkoktel.push_back(gyumolcsok[i]);
            backtrack(tempkoktel, i);
        }
    }
}

int main()
{
    vector<string> koktel;
    backtrack(koktel, 0);
    return 0;
}
