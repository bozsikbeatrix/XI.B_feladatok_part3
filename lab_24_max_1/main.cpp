#include <iostream>

using namespace std;

/*
megoldas kiirasa
*/
void print_solution(int n,int x[])
{

    char c[100][100];
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            c[i][j]='-';
        }
    }

    for(i=1; i<=n; i++)
    {
        c[i][x[i]]='Q';
    }

    for( i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }

}

/*
Megvizsgalja, hogy le lehet-e tenni a kiralynot
*/
bool place(int x[],int k)
{
    int i;
    for(i=1; i<k; i++)
    {
        if((x[i]==x[k])||(i-x[i]==k-x[k])||(i+x[i]==k+x[k]))
        {
            return false;
        }
    }
    return true;
}

void nqueens(int n)
{
    int x[100];
    int count=0;
    int k=1;

    x[k]=0;

    while(k!=0)
    {

        x[k]=x[k]+1;
        while((x[k]<=n)&&(!place(x,k)))
        {

            x[k]=x[k]+1;
        }
        if(x[k]<=n)
        {
            if(k==n)
            {
                count++;
                cout << "\n" << count <<". adik megoldas" << "\n";
                print_solution(n,x);

            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
        {
            k--;
        }
    }
    return;
}


int main()
{
    int n;


    cout << " Kiralynok szama : ";
    cin >> n;
    cout << "Megoldasok:";
    nqueens(n);
    return 0;
}
