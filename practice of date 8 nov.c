#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100  // Maximum contacts array can hold

// Structure for a contact
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Global array and counter
Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

// Function to insert a new contact
void insertContact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    
    contacts[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully!\n");
}

// Function to search a contact by name
void searchContact() {
    if (num_contacts == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found: Name - %s, Phone - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;  // Assuming unique names, stop after first match
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact() {
    if (num_contacts == 0) {
        printf("No contacts to delete.\n");
        return;
    }
    
    char del_name[50];
    printf("Enter name to delete: ");
    scanf("%s", del_name);
    
    int found_index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, del_name) == 0) {
            found_index = i;
            break;
        }
    }
    
    if (found_index == -1) {
        printf("Contact not found.\n");
        return;
    }
    
    // Shift remaining contacts left
    for (int i = found_index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    
    num_contacts--;
    printf("Contact deleted successfully!\n");
}

// Function to display all contacts
void displayAll() {
    if (num_contacts == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    
    printf("\n--- All Contacts ---\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("--------------------\n");
}

// Main menu
int main() {
    int choice;
    
    printf("=== Simple Phone Book Management System ===\n");
    printf("Using Insertion, Deletion, and Searching operations.\n\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                displayAll();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}