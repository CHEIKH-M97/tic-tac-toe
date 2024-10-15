#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // declaring this globally bc it will be modified in the functions.
void print_screen(char arr[3][3])
{
    printf("******************\nWelcome to X/O Game\n******************\n\n");
    for (int i = 0 ; i<3 ; i++)
    {
        if (i >0)
        {
            printf("%s","----------\n");
        }
        for (int j= 0 ; j<3 ; j++)
        {
            if (j==2)
            {
               printf("%c",arr[i][j]);
               continue;
            }
            printf("%c | ",arr[i][j]);
        }
        printf("\n");
    }
}
int play_is_valid(int row , int column)
{
    return (row<3 && column <3 && arr[row][column] == ' ');
}
void play(char player[])
{
    int row , column;
    while (1)
    {
        printf("\nPlayer %c to play :\n --> Choose your row : ",player[0]);
        scanf("%d",&row);
        printf("\nPlayer %c to play :\n --> Choose your column : ",player[0]);
        scanf("%d",&column);
        if (play_is_valid(row,column)==1) //int function that returns whether or not the desired play is valid
        {
            arr[row][column] = player[1];
            break;
        }
        else
        {
            printf("Invalid choice ! Please try again");
        }
    }

}
int check_for_free_space()
{
    for (int i = 0 ; i<3 ; i++)
    {
        for (int j = 0 ; j<3 ; j++)
        {
           if (arr[i][j] == ' ')
           {
               return 1;
           }
        }
    }
    return 0;
}
int checkforwinner()
{
    bool poss1 = (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O');
    bool poss2 = (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O');
    bool poss3 =(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O');
    bool poss4 =(arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O');
    bool poss5 =(arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O');
    bool poss6 =(arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O');
    bool poss7 =(arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X');
    bool poss8 =(arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X');
    bool poss9 =(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X');
    bool poss10 =(arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X');
    bool poss11 =(arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X');
    bool poss12 =(arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X');
    bool poss13 =(arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O');
    bool poss14 =(arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X');
    if (poss1 || poss2|| poss3|| poss4|| poss5|| poss6 || poss13)
    {
        return 2;
    }
    else if (poss7 || poss8|| poss9|| poss10|| poss11|| poss12 || poss14)
        {
            return 1;
        }
    else
    {
        return 0;
    }

}
int main()
{
    char player1[] = "1X";
    char player2[] = "2O";
    int det = 0; // Variable to determine which player plays.
    while (checkforwinner() == 0 && check_for_free_space())
        {
            system("cls");
            print_screen(arr);
            det += 1;

            if (det % 2 == 0)
            {
                play(player2); // Player 2's turn
            }
            else
            {
                play(player1); // Player 1's turn
            }
        }
    system("cls");
    print_screen(arr);
    printf("\n");
    int winner = checkforwinner();

    if (winner == 0 && !check_for_free_space()) // No winner and no spaces left (draw)
    {
        printf("No winner. This is a DRAW.\n");
    }
    else if (winner == 1) // Player 1 wins
    {
        printf("Congrats ! \n --> Player 1 wins.\n");
    }
    else if (winner == 2) // Player 2 wins
    {
        printf("Congrats ! \n --> Player 2 wins.\n");
    }
    system("pause");
    return 0;
}








