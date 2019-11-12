#ifndef HEADER_H
#define HEADER_H

#define MAX_LINES 4
#define PHRS 6

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>

typedef struct r_list
{
    int *arr;
    struct r_list *next;
}list;

typedef struct r_scr
{
    char **map;
    list **rain;
    int w;
    int h;
}scr;

bool to_lowercase(char *str);
int get_color(char *str);
char *mx_strdup (const char *s);
void intro_scene();
void rain_scene();
void add_back(list **temp);
void pop_front(list **temp);
int size_list(list *temp);

#endif
