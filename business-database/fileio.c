#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"
#include "customer.h"
#include "hashtable.h"
#include "utils.h"

void load_customers(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256]; // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        char *email = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        int shoesize = atoi(strtok(NULL, "\t"));
        char *food = strtok(NULL, "\t");

        // Create a Customer struct
        Customer *customer = (Customer *)malloc(sizeof(Customer));
        if (!customer) {
            perror("Memory allocation failed");
            fclose(file);
            return;
        }

        customer->email = strdup(email);
        customer->name = strdup(name);
        customer->shoesize = shoesize;
        customer->food = strdup(food);

        add_customer(table, customer);
    }

    fclose(file);
}

void save_database(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    for (size_t i = 0; i < table->num_buckets; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            fprintf(file, "%s\t%s\t%d\t%s\n", current->email, current->name, current->shoesize, current->food);
            current = current->next;
        }
    }

    fclose(file);
}
