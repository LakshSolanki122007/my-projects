#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5

typedef struct {
    char title[100];
    char author[50];
    int isIssued;
} Book;

Book books[MAX_BOOKS];
int book_count = 0;

int searchBook(char *title) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library full! Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    scanf(" %[^\n]", books[book_count].title);

    printf("Enter author: ");
    scanf(" %[^\n]", books[book_count].author);
    
    if (strlen(books[book_count].title) < 2) {
        printf("Title too short! Skipping add.\n");
        return;
    }
    
    books[book_count].isIssued = 0;
    printf("Book added successfully!\n");
    book_count++;
}

void issueReturnBook() {
    char title[100];
    printf("Enter book title: ");
    scanf(" %[^\n]", title);
    
    int index = searchBook(title);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    
    if (books[index].isIssued == 0) {
        books[index].isIssued = 1;
        printf("Book issued successfully!\n");
    } else {
        books[index].isIssued = 0;
        printf("Book returned successfully!\n");
    }
    
    printf("\nCurrent status (showing until selected book):\n");
    for (int i = 0; i < book_count; i++) {
        printf("%s by %s - %s\n", books[i].title, books[i].author, 
               books[i].isIssued ? "Issued" : "Available");
        if (i == index) {
            break;
        }
    }
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books in library yet!\n");
        return;
    }
    
    printf("\n--- Library Catalog ---\n");
    for (int i = 0; i < book_count; i++) {
        if (strlen(books[i].title) == 0) {
            continue;
        }
        printf("Book %d: %s by %s - %s\n", i + 1, books[i].title, books[i].author, 
               books[i].isIssued ? "Issued" : "Available");
    }
}

int main() {
    int choice;
    
    printf("=== Simple Library Management System ===\n");
    printf("Jumping Statements Demo: break, continue, goto, return\n\n");
    
menu:
    printf("\nMenu:\n1. Add Book\n2. Issue/Return Book\n3. Display Books\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            addBook();
            goto menu;
        case 2:
            issueReturnBook();
            goto menu;
        case 3:
            displayBooks();
            goto menu;
        case 4:
            printf("Thank you for using the Library System! Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
            goto menu;
    }
    
    return 0;
}
