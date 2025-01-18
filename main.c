#include <stdio.h>

typedef struct{
    const char *option;
} Menu;

typedef struct{
    const char *nom;
    Menu* menus;
    int nb_menus;
}Application;

void displayMenu(const Application* app) {
    printf("--- %s ---\n", app->nom);
    for (int i = 0; i < app->nb_menus; i++) {
        printf("%d. %s\n", i + 1, app->menus[i].option);
    }
    printf("Choisissez une option (0 pour quitter) : ");
}

int main() {
    Menu photoMenus[] = {
        {"Regarder une photo"},
        {"Prendre une photo"}
    };
    Application photoApp = {"Photos", photoMenus, 2};

    displayMenu(&photoApp);
    return 0;
}
