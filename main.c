#include <stdio.h>

typedef struct {
    const char *option;
} Menu;

typedef struct {
    const char *nom;
    Menu *menus;
    int nb_menus;
} Application;

void displayMenu(const Application* app) {
    printf("--- %s ---\n", app->nom);
    for (int i = 0; i < app->nb_menus; i++) {
        printf("%d. %s\n", i + 1, app->menus[i].option);
    }
    printf("Choisissez une option (0 pour quitter) : ");
}

void runApplication(const Application* app) {
    int choice = -1;
    while (choice != 0) {
        displayMenu(app);
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Vous avez quitté l'application.\n");
        } else if (choice > 0 && choice <= app->nb_menus) {
            printf("Vous avez sélectionné : %s\n", app->menus[choice - 1].option);
        } else {
            printf("Option invalide, veuillez choisir une option correcte.\n");
        }
    }
}

int main() {
    Menu photoMenus[] = {
        {"Regarder une photo"},
        {"Prendre une photo"}
    };
    Application photoApp = {"Photos", photoMenus, 2};
    runApplication(&photoApp);
    
    return 0;
}
