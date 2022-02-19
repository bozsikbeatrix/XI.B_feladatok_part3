#include <iostream>

#include <fstream>



using namespace std;



//A lehetseges koordinatak legeneralasa

short xlehet[] = {0,0,-1, 1};

short ylehet[] = {-1,1, 0, 0};

int minlepes=100000;

int minimumtomb[100][100];

/**
Fuggvent a labirintus kiirasara
*/

void kiir(int tomb[100][100], int n, int m)

{
    if(minlepes>tomb[n-1][m-1])
    {
        minlepes=tomb[n-1][m-1];
        for(int i=0; i<n; i++)

        {

            for(int j=0; j<m; j++)

            {

                minimumtomb[i][j]=tomb[i][j];

            }



        }
    }




}

/**
Lehet fuggveny, ami hamist fog visszateriteni,
ha
    - falba utkozunk
    - voltunk mar ott, ahova lepni szeretnenk
    - kilepnenk a labirintusbol
*/

bool lehet(int tomb[100][100], int n, int m, int xpos, int ypos)

{

    //ha a megadott pozicio nincs a labirintusba,

    //teristsunk vissza hamisat

    //elobb az x koordinatara

    if (xpos <0 )

    {

        return false;

    }

    if (xpos > n-1)

    {

        return false;



    }

    //aztan az y koordinatara

    if (ypos <0 )

    {

        return false;

    }

    if (ypos > m-1)

    {

        return false;



    }



    //a falat 1 essel jeloltuk, szoval ha 1 esre lepnenk,

    //akkor teritsunk vissza hamisat

    if (tomb[xpos][ypos] == 1)

    {

        return false;

    }



    if (tomb[xpos][ypos] > 2)

    {

        return false;

    }

    //ha semmi sem akadalyoz meg minket abban, hogy ide lepjunk, akkor teritsunk vissza igazat

    return true;

}



void backtrack(int tomb[100][100], int n, int m, int xpos, int ypos, int lepes)

{

    //a leallasi feltetel az lesz, hogy a labirintus vegen vagyunk

    if ((xpos == n-1) && (ypos == m-1))

    {

        kiir(tomb, n, m);

        return ;

    }

    for(int i = 0; i<4; i++)

    {



        if (lehet(tomb, n, m, xpos+xlehet[i], ypos+ylehet[i]))

        {



            int tempxpos = xpos+xlehet[i];

            int tempypos = ypos+ylehet[i];

            int templabirintus[100][100];

            //az ideiglenes labirintusban atmasoljuk az eger helyet

            for(int i=0; i<n; i++)

            {

                for(int j=0; j<m; j++)

                {

                    templabirintus[i][j] = tomb[i][j];

                }



            }

            //az ideiglenes labirintusban frissitjuk az eger helyet

            templabirintus[tempxpos][tempypos] = lepes+1;

            backtrack(templabirintus,  n,  m,  tempxpos,  tempypos, lepes+1);




        }

    }



}



int main()

{

    int a[100][100];

    ifstream inputfile("labirintus.in");

    int n, m;

    //beolvassuk az n es m erteket

    inputfile >> n >> m;

    //beolvassuk a labirintust

    for(int i=0; i<n; i++)

    {

        for(int j=0; j<m; j++)

        {

            inputfile >> a[i][j];

        }



    }

    //az egeret a 0 0  helyre tesszuk

    //feltetelezzuk, hogy az eger helyzetet 2 essel jeloljuk

    a[0][0] = 2;



    //meghivjuk a backtrack fuggvenyt

    backtrack(a,  n,  m,  0,  0, 2);
    for(int i=0; i<n; i++)

        {

            for(int j=0; j<m; j++)

            {

                cout << minimumtomb[i][j] << " ";

            }

     cout << endl;

        }

    return 0;

}
