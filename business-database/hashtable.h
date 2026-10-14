#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"

// Define the structure for the hash table
typedef struct HashTable {
    size_t num_buckets;
    Customer **buckets;
} HashTable;

// Function prototypes
HashTable *create_table(size_t num_buckets);
void add_customer(HashTable *table, Customer *customer);
Customer *lookup_customer(HashTable *table, char *email);
void delete_customer(HashTable *table, char *email);
void list_customers(HashTable *table);
void free_table(HashTable *table);

#endif // HASHTABLE_H
