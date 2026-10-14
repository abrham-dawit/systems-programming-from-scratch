#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "utils.h"
#include "customer.h"

// Hash Function (You can use the djb_hash function provided in the instructions)
unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while (*str != '\0') {
        c = *str;
        hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
        str++;
    }
    return hash;
}

// Create a new hash table
HashTable *create_table(size_t num_buckets) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (!table) {
        perror("Memory allocation failed");
        return NULL;
    }

    table->buckets = (Customer **)calloc(num_buckets, sizeof(Customer *));
    if (!table->buckets) {
        perror("Memory allocation failed");
        free(table);
        return NULL;
    }

    table->num_buckets = num_buckets;
    return table;
}

// Add a customer to the hash table
void add_customer(HashTable *table, Customer *customer) {
    size_t bucket = hash(customer->email) % table->num_buckets;

    // Check if the customer already exists in the hash table
    Customer *current = table->buckets[bucket];
    while (current) {
        if (strcmp(current->email, customer->email) == 0) {
            // Customer already exists, update the information
            free(current->name);
            free(current->food);
            current->name = strdup(customer->name);
            current->shoesize = customer->shoesize;
            current->food = strdup(customer->food);
            free(customer); // Free the memory allocated for the new customer
            return;
        }
        current = current->next;
    }

    // Customer does not exist, add it to the front of the linked list
    customer->next = table->buckets[bucket];
    table->buckets[bucket] = customer;
}

// Lookup a customer in the hash table
Customer *lookup_customer(HashTable *table, char *email) {
    size_t bucket = hash(email) % table->num_buckets;

    Customer *current = table->buckets[bucket];
    while (current) {
        if (strcmp(current->email, email) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Delete a customer from the hash table
void delete_customer(HashTable *table, char *email) {
    size_t bucket = hash(email) % table->num_buckets;

    Customer *current = table->buckets[bucket];
    Customer *previous = NULL;
    while (current) {
        if (strcmp(current->email, email) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                table->buckets[bucket] = current->next;
            }
            free(current->email);
            free(current->name);
            free(current->food);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// List all customers in the hash table
void list_customers(HashTable *table) {
    for (size_t i = 0; i < table->num_buckets; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            printf("email: %s\n", current->email);
            printf("name: %s\n", current->name);
            printf("shoesize: %d\n", current->shoesize);
            printf("food: %s\n\n", current->food);
            current = current->next;
        }
    }
}

// Free the memory allocated for the hash table
void free_table(HashTable *table) {
    for (size_t i = 0; i < table->num_buckets; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            Customer *next = current->next;
            free(current->email);
            free(current->name);
            free(current->food);
            free(current);
            current = next;
        }
    }
    free(table->buckets);
    free(table);
}
