#include"game.h"

void menu()
{
    printf("************************\n");
    printf("******   1. start   ****\n");
    printf("******   0. exit    ****\n");
    printf("************************\n");
}

void game(char mine[ROWS][COLS], char show[ROWS][COLS])
{
    int x, y;
    int end = ROW * COL - COUNT;
    init_board(mine, '0');
    init_board(show, '*');
    set_mine(mine);
    //circle? only end when variable-end under(-1,boom) or equal to zero( all mine explosed, win).
    while(end>0)
    {
        display_board(show);
        printf("input the coordination:\n");
        scanf("%d%d", &x, &y);
        find_mine(mine, show, x, y,&end);//judge lose , win, write (x, y);
    }
    if (end == 0)
        printf("you win.\n");
    else
        printf("mine explode. you lose game.\n");
}

int main()
{
    int input;
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    srand((unsigned int)time(NULL));

    do
    {
        menu();
        printf("input choice\n");
        scanf("%d", &input);
        switch (input)
        {
            case 0:
                printf("end game.\n");
                break;
            case 1:
                printf("start game.\n");
                game(mine, show);
                break;
            default :
                printf("worng input. try again.\n");
                break;
        }
    } while (input);
    return 0;
}
