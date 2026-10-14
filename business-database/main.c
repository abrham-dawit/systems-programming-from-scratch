#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "fileio.h"
#include "customer.h"
#include "utils.h"

int main(void) {
    HashTable *customers = create_table(1000);

    load_customers(customers, "customers.tsv");

    while (1) {
        // Main interaction loop
        printf("Enter command: ");
        char command[256];
        fgets(command, sizeof(command), stdin);
        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            // Prompt for customer details and add to the hash table
            char email[256];
            char name[256];
            int shoesize;
            char food[256];

            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = 0; // Remove trailing newline

            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove trailing newline

            printf("Enter shoesize: ");
            scanf("%d", &shoesize);
            getchar(); // Consume the newline character left by scanf

            printf("Enter favorite food: ");
            fgets(food, sizeof(food), stdin);
            food[strcspn(food, "\n")] = 0; // Remove trailing newline

            // Create and add the customer
            Customer *new_customer = (Customer *)malloc(sizeof(Customer));
            if (!new_customer) {
                perror("Memory allocation failed");
                continue;
            }
            new_customer->email = strdup(email);
            new_customer->name = strdup(name);
            new_customer->shoesize = shoesize;
            new_customer->food = strdup(food);

            add_customer(customers, new_customer);

        } else if (strcmp(command, "lookup") == 0) {
            // Prompt for email and lookup the customer
            char email[256];
            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = 0; // Remove trailing newline

            Customer *found_customer = lookup_customer(customers, email);
            if (found_customer) {
                printf("email: %s\n", found_customer->email);
                printf("name: %s\n", found_customer->name);
                printf("shoesize: %d\n", found_customer->shoesize);
                printf("food: %s\n\n", found_customer->food);
            } else {
                printf("Customer not found!\n");
            }

        } else if (strcmp(command, "delete") == 0) {
            // Prompt for email and delete the customer
            char email[256];
            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = 0; // Remove trailing newline

            delete_customer(customers, email);

        } else if (strcmp(command, "list") == 0) {
            // List all customers
            list_customers(customers);
        } else if (strcmp(command, "save") == 0) {
            // Save the database to file
            save_database(customers, "customers.tsv");
        } else {
            printf("Unknown command\n");
        }
    }

    free_table(customers);
    return 0;
}
