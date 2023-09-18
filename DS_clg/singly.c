#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CityNode {
    char city[50];
    char district[30];
    int population;
    struct CityNode* next;
};

void addCity(struct CityNode** head, char city[], char district[], int population) {
    struct CityNode* newCity = (struct CityNode*)malloc(sizeof(struct CityNode));
    if (!newCity) {
        printf("Memory allocation failed\n");
        return;
    }

    strncpy(newCity->city, city, sizeof(newCity->city));
    strncpy(newCity->district, district, sizeof(newCity->district));
    newCity->population = population;
    newCity->next = *head;
    *head = newCity;
}

void insertCityByPopulation(struct CityNode** head, char city[], char district[], int population) {
    struct CityNode* newCity = (struct CityNode*)malloc(sizeof(struct CityNode));
    if (!newCity) {
        printf("Memory allocation failed\n");
        return;
    }

    strncpy(newCity->city, city, sizeof(newCity->city));
    strncpy(newCity->district, district, sizeof(newCity->district));
    newCity->population = population;

    if (*head == NULL || population >= (*head)->population) {
        newCity->next = *head;
        *head = newCity;
    } else {
        struct CityNode* current = *head;
        while (current->next != NULL && population < current->next->population) {
            current = current->next;
        }
        newCity->next = current->next;
        current->next = newCity;
    }
}

void displayCities(struct CityNode* head) {
    struct CityNode* current = head;
    while (current != NULL) {
        printf("City: %s, District: %s, Population: %d\n", current->city, current->district, current->population);
        current = current->next;
    }
}

int main() {
    struct CityNode* head = NULL;
    char city[50];
    char district[30];
    int population;
    int choice;

    addCity(&head, "Chennai", "Chennai", 8696010);
    addCity(&head, "Coimbatore", "Coimbatore", 1643255);

    do {
        printf("\nMenu:\n");
        printf("1. Add City\n");
        printf("2. Insert City by Population\n");
        printf("3. Display Cities\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		struct CityNode* current = head;

        switch (choice) {
            case 1:
                printf("Enter city name: ");
                scanf("%s", city);
                printf("Enter district: ");
                scanf("%s", district);
                printf("Enter population: ");
                scanf("%d", &population);
                addCity(&head, city, district, population);
                break;

            case 2:
                printf("Enter city name: ");
                scanf("%s", city);
                printf("Enter district: ");
                scanf("%s", district);
                printf("Enter population: ");
                scanf("%d", &population);
                insertCityByPopulation(&head, city, district, population);
                break;

            case 3:
                displayCities(head);
                break;

            case 4:
                while (current != NULL) {
                    struct CityNode* next = current->next;
                    free(current);
                    current = next;
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

