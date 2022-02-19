#include <iostream>
using namespace std;
int N = 3;
string virag[] = {"rozsa", "tulipan", "gerbera","orchidea", "liliom"};
/**
A lehet fuggveny, amiben csak azt kell vizsgaljuk,
hogy a megadott uj virag megvan-e mar az ideiglenes csokorban.
Ha igen, akkor hamisat terit vissza,
kulonben igazat
args:
csokor - az ideiglenes csokor, amelyikbe mar lehetnek viragok
n - az ideiglenes csokor nagysaga
ujvirag - az uj viragnak a neve, amit bele szeretnenk tenni a csokorba
*/
bool lehet(string csokor[], int n, string ujvirag)
{
    //vegigmegyunk a tombon, s megnezzuk, hogy barmelyik elem megegyezik-e
    //a uj viraggal, mert ha igen, akkor nem tehetjuk bele a csokorba
    for(int i = 0; i<n; i++)
    {
        if (csokor[i] == ujvirag)
        {
            return false;
        }
    }
    return true;
}
/**
Kiir fuggveny, kiir egy string tombot, aminek n a hossza
*/
void kiir(string csokor[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << csokor[i] << " " ;
    }
    cout << endl;
    return;
}
/**
a backtrack fuggveny, amely megprobalja osszerakni a mennyasszonyi csokrot
args:
csokor - az ideiglenes csokor, amelyikkel probalkozunk
n - az ideiglenes csokor hossza
index - az a szam, ahanyadik viragnal tartunk a virag tombbol (pl index = 1, akkor csak a tulipant, s az azutani viragokat probaljuk a csokorba tenni)
*/
void backtrack(string csokor[], int n, int index)
{
    //ha az ideiglenes csokor hossza N, amennyi viragra szuksegunk van
    //akkor ez megoldas, leallunk, s kiirjuk
    if (n == N)
    {
        kiir(csokor, n);
        return;
    }
    //megprobaljuk az osszes lehetseges variaciot a viragokkal,
    //ezert kezdjuk az elso szamnal, az indexnel, ahonnan probalkozzunk, s megyunk vegig a virag tombon
    for(int i = index; i<5; i++)
    {
        //megvizsgaljuk. hogy bele lehet e tenni az aktualis uj viragot a mar meglevo csokorba
        if (lehet(csokor, n, virag[i]))
        {
            //ha igen, letrehozunk egy ideiglenes csokrot, aminek N=3 lesz a hossza,
            //mivel max akkora kell legyen a menyasszonyi csokrunk
            string tempcsokor[N];
            //atmasoljuk az eddigi csokrot az ideiglenes csokorba
            for(int j = 0; j<n; j++)
            {
                tempcsokor[j] = csokor[j];
            }
            //az n-1 edik helyig másoltunk, uh a következo helyre kell tegyuk
            //az uj viragot. Pl ha az eddigi csokor = {rozsa, tulipan}, akkor n = 2
            //az uj csokor {rozsa tulipan gerbera} kell legyen, tehat az n. indexre kell tenni az uj viragot
            tempcsokor[n] = virag[i];
            //meghivjuk a backtrack fuggvenyt az uj ideiglenes csokorra, s mivel hozzaadtunk egy viragot, ezert az n et noveljuk 1 el
            //mivel vizsgaljuk a lehet fuggvenyben, hogy ne legyen ket ugyanolyan virag, ezert az i erteket nem muszaj novelni.
            backtrack(tempcsokor, n+1, i);
        }
    }
}

int main()
{
    //letrehozunk egy ures csokrot, mivel meg nem tudjuk milyen viragok lesznek a menyasszonyi csokorban
    string csokor[] = {""};
    //mivel meg nem tettunk egy viragot sem sehova, ezert az eddigi csokorban 0 virag van, tehat n=0,
    //s minden viragbol szeretnenk, ha lenne a csokorban, ezert az indexet is 0 rol inditjuk
    //nezzuk meg, hogy ha 1 rol inditjuk, akkor rozsa nem lesz a csokrokban, ha 2 rol, rozsa s tulipan sem...
    backtrack(csokor, 0, 0);
    return 0;
}
