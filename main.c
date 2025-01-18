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
    Menu menu1 = {"Option 1"};
    Menu menus[] = {menu1};
    Application app = {"Mon Application", menus, 1};
    printf("Application: %s\n", app.nom);
    printf("Nombre de menus: %d\n", app.nb_menus);
    for (int i = 0; i < app.nb_menus; i++) {
        printf("Menu %d: %s\n", i + 1, app.menus[i].option);
    }

    return 0;
}
