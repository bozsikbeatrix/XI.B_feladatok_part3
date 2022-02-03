#include <iostream>

using namespace std;

const int N = 8;

int kontor = 0;




bool lehet(int sor, int oszlop,  char board[][N])
{
    int i = sor;
    int j = oszlop;

    //ellenorizzuk, hogy a bal oldali atlon felfele van-e kiralyno
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j--;
    }

    i = sor;
    j = oszlop;
    //ellenorizzuk, hogy a jobb oldali atlon felfele van-e kiralyno
    while(i >= 0 && j < N)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j++;
    }

    i = sor;
    j = oszlop;
    //ellenorizzuk, hogy a jelenlegi oszlopban van-e meg kiralyno
    while(i >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }

        i--;
    }

    return true;
}

void uresit( char board[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = 'X';
        }
    }
}

void kiir( char board[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool backtracking(int sor, char board[][N] )
{
    //ha eljutottunk az utolso sorig, akkor vegso megoldas, irassuk ki
    if(sor == N)
    {
        kontor++;

        kiir(board);
        cout << endl;

        return true;
    }
    //ha nem, kezdjuk az elso oszloptol, s probaljuk meg lerakni valahova a kovetkezo kiralynot
    for(int oszlop = 0; oszlop < N; oszlop++)
    {
        //ha le lehet tenni a jelenlegi helyre a kiralynot
        if(lehet(sor, oszlop,  board))
        {
            //hozzunk letre egy ideiglenes tablat, amibe atmasoljuk az eddigit
            char tempboard[N][N];
            for(int i = 0; i< N; i++){
                for(int j = 0; j < N; j++){
                    tempboard[i][j] = board[i][j];
                }
            }
            //az ideiglenes tablara tegyuk le a kiralynot
            tempboard[sor][oszlop] = 'Q';
            //hivjuk meg a backtraking fuggvenyt a kovetkezo sorra
            backtracking(sor + 1, tempboard);
        }

    }
}


int main()
{
    //sakktabla letrehozasa
    char board[N][N];
    //sakktabla inicializalasa
    uresit(board);
    //backtracking inditasa a 0. sorbol
    backtracking(0, board);

    cout << kontor << endl;
    return 0;
}
