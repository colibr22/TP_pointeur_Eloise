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
        } 
        else if (choice > 0 && choice <= app->nb_menus) {
            printf("Vous avez sélectionné : %s\n", app->menus[choice - 1].option);
        } 
        else {
            printf("Option invalide, veuillez choisir une option correcte.\n");
        }
    }
}

void updateMenu(Application* app, int menuIndex, const char* newOption) {
    if (menuIndex >= 0 && menuIndex < app->nb_menus) {
        app->menus[menuIndex].option = newOption;
        printf("Option modifiée avec succès !\n");
    } else {
        printf("Index invalide.\n");
    }
}

void updateApplication(Application* app, const char* newName, Menu* newMenus, int newMenuCount) {
    app->nom = newName;
    app->menus = newMenus;
    app->nb_menus = newMenuCount;
    printf("Application modifiée avec succès !\n");
}

void runPhone(Application* app1, Application* app2) {
    int choice = -1;
    while (choice != 0) {
        printf("--- Applications ---\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("0. Quitter\n");
        printf("Choisissez une application (0 pour quitter) : ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Vous avez quitté le téléphone.\n");
        } 
        else if (choice == 1) {
            printf("Lancement de l'application %s...\n", app1->nom);
            runApplication(app1);
        } 
        else if (choice == 2) {
            printf("Lancement de l'application %s...\n", app2->nom);
            runApplication(app2);
        } 
        else {
            printf("Option invalide, veuillez choisir une application correcte.\n");
        }
    }
}



int main() {
    Menu photoMenus[] = {
        {"Regarder une photo"},
        {"Prendre une photo"}
    };
    Application photoApp = {"Photos", photoMenus, 2};

    Menu messageMenus[] = {
        {"Lire un message"},
        {"Envoyer un message"}
    };
    Application messageApp = {"Messages", messageMenus, 2};

    runPhone(&photoApp, &messageApp);
    
    return 0;
}
