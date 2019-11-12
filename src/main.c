#include "header.h"

int main(int argc, char **argv)
{
    initscr();
    int charcolor = 2;
    if (argc == 2)
    {
        if (to_lowercase(argv[1]))
        {
            int color = get_color(argv[1]);
            if (color != -1)
                charcolor = color;
        }
    }
    setlocale(LC_ALL, "ja_JP.UTF-8");
    noecho();
    curs_set(false);
    keypad (stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, charcolor, COLOR_BLACK);
    intro_scene();
    rain_scene();
}
