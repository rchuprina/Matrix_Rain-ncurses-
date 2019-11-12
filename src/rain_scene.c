#include "header.h"

static scr *create_scr()
{
    scr *temp = (scr *)malloc(sizeof(scr));
    int h, w;
    getmaxyx(stdscr, h, w);
    list **rain = (list **)malloc(w * sizeof(list));
    char **map = (char **)malloc(h * sizeof(char *));

    for (int i = 0; i < h; i++)
    {
        map[i] = (char *)malloc(w * sizeof(char));    
        for (int j = 0; j < w; j++)
            map[i][j] = rand() % 93 + 33;
    }
    temp->rain = rain;
    temp->map = map;
    temp->h = h;
    temp->w = w;
    return temp;
}

static void quit(scr *temp)
{
    for (int i = 0; i < temp->w; i++)
    {
        while (temp->rain[i])
            pop_front(&temp->rain[i]);
    }
    free(temp);
    endwin();
    exit(1);
}

static void update_scene(scr *temp)
{
    int ref = 1;

    for (int i = 0; i < temp->w; i++)
    {
        ref = rand() % 70;
        if (temp->rain[i])
        {
            for (list *p = temp->rain[i]; p; p = p->next)
            {
                for (int j = 0; j < 6; j++)
                    p->arr[j]++;
            }
        }
        if (ref == 18 && i % 2 == 0)
            add_back(&temp->rain[i]);
    }
}

static void print_scene(scr *temp)
{
    update_scene(temp);
    for (int i = 0; i < temp->w; i++)
    {
        if (temp->rain[i])
        {
            for (list *p = temp->rain[i]; p; p = p->next)
            {
                char ch = rand() % 80 + 40;
                attron(COLOR_PAIR(1));
                if (p->arr[0] >= 0 && p->arr[0] < temp->h)
                    mvaddch(p->arr[0], i , ch | A_BOLD);
                if (p->arr[1] >= 0 && p->arr[1] < temp->h)
                    mvaddch(p->arr[1], i , ch | A_NORMAL);
                attron(COLOR_PAIR(2));
                if (p->arr[2] >= 0 && p->arr[2] < temp->h)
                    mvaddch(p->arr[2], i , temp->map[p->arr[2]][i] | A_BOLD);
                if (p->arr[3] >= 0 && p->arr[3] < temp->h)
                    mvaddch(p->arr[3], i , temp->map[p->arr[3]][i] | A_NORMAL);
                if (p->arr[4] >= 0 && p->arr[4] < temp->h)
                    mvaddch(p->arr[4], i , temp->map[p->arr[4]][i] | A_DIM);
                if (p->arr[5] >= 0 && p->arr[5] < temp->h)
                    mvaddch(p->arr[5], i, ' ');
                if (temp->rain[i]->arr[5] >= temp->h)
                    pop_front(&temp->rain[i]);
            }
        }
    }
}

void rain_scene()
{
    scr *temp = create_scr();
    int speed = 60;
    while (true)
    {
        print_scene(temp);
		timeout(speed);
        switch (getch())
        {
        case 'q':
            quit(temp);
            break;
        case KEY_UP:
            if (speed > 10)
                speed -= 10;
            break;
        case KEY_DOWN:
            if (speed < 160)
                speed += 10;
            break;
        }
        refresh();
    }
}
