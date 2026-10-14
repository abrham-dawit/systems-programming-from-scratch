#ifndef FILEIO_H
#define FILEIO_H

#include "hashtable.h"

// Function prototypes
void load_customers(HashTable *table, const char *filename);
void save_database(HashTable *table, const char *filename);

#endif // FILEIO_H
