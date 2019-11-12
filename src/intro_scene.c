#include "header.h"

static void quit(char **phrase)
{
    for (int i = 0; i < PHRS; i++)
        free(phrase[i]);
    free(phrase);
    endwin();
    exit(1);
}

static char **get_phrases()
{
    char **phrase = (char **)malloc(PHRS * sizeof(char *));

    phrase[0] = mx_strdup("Wake up, Neo...");
    //phrase[0] = mx_strdup("ボタンを押して速度を上げます");
    phrase[1] = mx_strdup("The Matrix has you...");
    phrase[2] = mx_strdup("Follow the white rabbit.");
    phrase[3] = mx_strdup("Knock, knock, Neo.");
    phrase[4] = mx_strdup("Press Q for exit.");
    phrase[5] = mx_strdup("Use Key Up and Key Down for speed control.");
    return phrase;
}

void intro_scene()
{
    char **phrase = get_phrases();
    int h, w;

    getmaxyx(stdscr, h, w);
    attron(COLOR_PAIR(2));
    for (int i = 0; i < PHRS; i++)
    {
        move(h / 6, w / 10);
        for (int j = 0; phrase[i][j]; j++)
        {
            addch(phrase[i][j] | A_DIM);
            timeout(60);
            switch (getch())
            {
            case 'q':
                quit(phrase);
                break;
            case '\n':
                clear();
                return;
                break;
            }
        }
        for (int j = 0; j < 20; j++)
        {
            timeout(60);
            switch (getch())
            {
            case 'q':
                quit(phrase);
                break;
            case '\n':
                clear();
                return;
                break;
            }
        }
        clear();
    }
}
