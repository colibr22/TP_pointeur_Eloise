#include <stdio.h>

struct Menu{
    const char *option;
} ;

struct Application{
    const char *nom;
    struct Menu *menus;
    int nb_menus;
};


