#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer {
    char *email;
    char *name;
    int shoesize;
    char *food;
    struct Customer *next;
} Customer;

#endif //CUSTOMER_H
