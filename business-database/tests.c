#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "customer.h"
#include "fileio.h"
#include "utils.h"

void test_hash_table(void) {
    HashTable *table = create_table(10);

    Customer *c1 = (Customer *)malloc(sizeof(Customer));
    c1->email = strdup("sammy@ucsc.edu");
    c1->name = strdup("Sammy the Slug");
    c1->shoesize = 27;
    c1->food = strdup("bananas");
    add_customer(table, c1);

    Customer *c2 = (Customer *)malloc(sizeof(Customer));
    c2->email = strdup("bimmy@ucsc.edu");
    c2->name = strdup("Bimmy");
    c2->shoesize = 4;
    c2->food = strdup("vegan jerky");
    add_customer(table, c2);

    // Test lookup
    Customer *found_c1 = lookup_customer(table, "sammy@ucsc.edu");
    if (found_c1 && strcmp(found_c1->name, "Sammy the Slug") == 0) {
        printf("Test lookup: PASS\n");
    } else {
        printf("Test lookup: FAIL\n");
    }

    // Test delete
    delete_customer(table, "sammy@ucsc.edu");
    Customer *deleted_c1 = lookup_customer(table, "sammy@ucsc.edu");
    if (!deleted_c1) {
        printf("Test delete: PASS\n");
    } else {
        printf("Test delete: FAIL\n");
    }

    // Test listing
    printf("Listing customers:\n");
    list_customers(table);

    free_table(table);
}
