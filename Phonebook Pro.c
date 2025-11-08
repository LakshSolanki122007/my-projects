#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  // maximum number of contacts

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact book[MAX];
int count = 0;

// ========================
// Function Declarations
// ========================
void addContact();
void displayAll();
void searchContact();
void deleteContact();
void saveToFile();
void loadFromFile();
void clearBuffer();

// ========================
// Clear input buffer
// ========================
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ========================
// Add new contact
// ========================
void addContact() {
    if (count >= MAX) {
        printf("Phonebook is full!\n\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", book[count].name); // allow multi-word name
    clearBuffer();

    printf("Enter Phone: ");
    scanf("%s", book[count].phone);
    clearBuffer();

    count++;
    printf("Contact added successfully!\n\n");
}

// ========================
// Display all contacts
// ========================
void displayAll() {
    if (count == 0) {
        printf("Phonebook is empty!\n\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, book[i].name, book[i].phone);
    }
    printf("\n");
}

// ========================
// Search for a contact
// ========================
void searchContact() {
    if (count == 0) {
        printf("No contacts to search!\n\n");
        return;
    }

    char searchName[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    clearBuffer();

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, searchName) == 0) {
            printf("Found: %s - %s\n\n", book[i].name, book[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n\n");
    }
}

// ========================
// Delete a contact
// ========================
void deleteContact() {
    if (count == 0) {
        printf("No contacts to delete!\n\n");
        return;
    }

    char delName[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", delName);
    clearBuffer();

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, delName) == 0) {
            for (int j = i; j < count - 1; j++) {
                book[j] = book[j + 1];
            }
            count--;
            found = 1;
            printf("Contact deleted!\n\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n\n");
    }
}

// ========================
// Save contacts to file
// ========================
void saveToFile() {
    FILE *f = fopen("contacts.txt", "w");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s;%s\n", book[i].name, book[i].phone);
    }
    fclose(f);
    printf("Contacts saved to 'contacts.txt'!\n\n");
}

// ========================
// Load contacts from file
// ========================
void loadFromFile() {
    FILE *f = fopen("contacts.txt", "r");
    if (!f) {
        printf("No saved contacts found.\n\n");
        return;
    }

    count = 0;
    while (fscanf(f, " %49[^;];%14s", book[count].name, book[count].phone) == 2) {
        count++;
        if (count >= MAX) break;
    }

    fclose(f);
    printf("Contacts loaded from file! (%d total)\n\n", count);
}

// ========================
// Main Menu
// ========================
int main() {
    int choice;
    loadFromFile();

    do {
        printf("=== PHONEBOOK PRO ===\n");
        printf("1. Add Contact\n");
        printf("2. Display All\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearBuffer(); // remove leftover newline

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayAll(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: saveToFile(); break;
            case 6: saveToFile(); printf("Bye!\n"); break;
            default: printf("Invalid choice!\n\n");
        }

    } while (choice != 6);

    return 0;
}
