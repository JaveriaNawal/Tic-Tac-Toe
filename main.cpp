#include<iostream>
#include<windows.h>
using namespace std;
#include<conio.h>
#include<math.h>

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void printboard(char X[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<X[i][j]<<" ";
        }
        cout<<endl;
    }

}
bool win(char X[3][3],char player)
{
for(int i=0;i<3;i++)
{
    if(X[0][i]==player&&X[1][i]==player&&X[2][i]==player||X[i][0]==player&&X[i][1]==player&&X[i][2]==player)
        return true;
}
    if(X[0][0]==player&&X[1][1]==player&&X[2][2]==player||X[0][2]==player&&X[1][1]==player&&X[2][0]==player)
    {
        return true;
    }
    return false;
}
bool draw(char X[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(X[i][j]==' ')
            {
                return false;
            }
        }
        }
        return true;

}
int main()
{    int a=1;
int r,c;
    char J[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ' ,' '}};
    char Player='Z';
    gotoRowCol(0,57);
    cout<<"Following are the rows and columns for the game: "<<endl;
gotoRowCol(1,57);
cout<<" 00 | 01 | 02 "<<endl;
gotoRowCol(2,57);
cout<<"----------------"<<endl;
gotoRowCol(3,57);
cout<<" 10 | 11 | 12 "<<endl;
gotoRowCol(4,57);
cout<<"----------------"<<endl;
gotoRowCol(5,57);
cout<<" 20 | 21 | 22 "<<endl;


   do
    {
    do{
        a=1;
    cout<<"Board"<<endl;
    printboard(J);

    cout<<"Player: "<<Player<<endl<<"Enter Row and Column"<<endl;
    cin>>r>>c;
    if(r<0||c<0||r>=3||c>=3||J[r][c]!=' ')
    {
        cout<<"Invalid move";
        a++;

    }}
    while(a==2);
    J[r][c]=Player;
    if((win(J,Player)))
       {
           printboard(J);
           cout<<"Player "<<Player<<" is a Winner!"<<endl;
           break;
       }
       if (draw(J))
        {
            printboard(J);
            cout<<"GAME IS DRAW!"<<endl;
            break;
        }
        if(Player=='Z')
        {
            Player='O';
        }
        else if(Player=='O')
        {
            Player='Z';
        }
   }
   while(true);
    return 0;
}
