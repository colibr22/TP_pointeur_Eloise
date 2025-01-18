#include <stdio.h>

typedef struct{
    const char *option;
} Menu;

typedef struct{
    const char *nom;
    Menu* menus;
    int nb_menus;
}Application;

int main() {
    Menu photoMenus[] = {
        {"Regarder une photo"},
        {"Prendre une photo"}
    };
    Application photoApp = {"Photos", photoMenus, 2};
    
    return 0;
}
