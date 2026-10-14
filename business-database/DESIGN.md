# Homework 7: Design Document

  * author: Abrham Dawit
  * date: December 4, 2024

## introduction
In this final week homework, I will try to learn and write some short functions using strings, I/O, and hash tables to make an e-commerce businesses that sell both snacks and shoes. 

TODO(you): Even though I love C programming language, it has been getting a bit complex this past weeks but, it was still exciting. I Can't wait to finish this last c hw strongly. It has been fun.

## hash table design
### structure
My hash table will consist of an array of linked lists, with each linked list representing a bucket. Each node in the linked list will store customer information, including their email address, name, shoe size, and favorite food.

### hash function
The hash function will take a customer's email address as input and output an integer. This integer will then be used to determine the appropriate bucket for that customer in the hash table using the modulo operator (%). Also, the djb_hash function is a good option because it is fast, minimizes collisions, and generates very different hash values for similar input strings.

## functions to implement
### function 1: load_database
In this function, I'm going to read customer information from a file named customer.tsv and store it in the hash table. To do this, I will use fgets in the function to read each line of the file and then strock to split the line into individual fields.

### function 2: add_customer
In this function, I will prompt the user for an email address and search for the corresponding customer in the hash table. If a customer with the same email adress already exists, I will make the function update the existing customer's information. To replace the existing customer information, I need to first free the memory allocated for the existing customer's name, and favorite food using the free function.

### function 3: lookup_customer
In this function, I will prompt the user for an email address and search for the corresponding customer in the hash table. If the customer is found, I will make the function display their information. If the customer is not found, I will make the function display a message informing the user.

### function 4: deleter_customer
In this function, I will prompt the user for an email address and delete the corresponding customer from the hash table. If the customer is not found, I will make the function display a message informing the user. Also, similar to the add_customer function, I need to free the memory allocated for the customer's information using free.

### function 5: list_customers
In this function, I will display a list of all customers in the hash table. Then, I will make it iterate through each bucket of the hash table and display the information of every customer stored in the linked list of each bucket.

### function 6: save_database
In this function, I will write the current state of the hash table to the customers.tsv file. Then, I will make the function use fopen to open the file for writing and fprintf to write each customer's information to the file.

### function 7: quit_program
In this last function, I will free all dynamically allocated memory and exit the program. To do this, I need to make the function iterate through every customer stored in the hash table and free their information. And lastly, I need to free the memory allocated for the hash table itself.

## problems I'm going to face and how I'm going to handle it
I think one of the problems I'm going to face is, handling input validation, such as preventing the user from entering tabs in customer information. To handle this, I can make the program either complain and prompt the user to re-enter the information without tabs or simply remove the extra tabs from the input. Another problem I might face is ensuring that my program is not leaking memory when adding, deleting, or saving the database. To handle this, I can run valgrind to detect and fix any memory leaks.

## some pseudocodes for:
### function 1
1. Open the customer.tsv file for reading
2. For each line in the file:
    - Read the line from the file using fgets
    - Split the line into fields (email, name, shoe size, favorite food) using strtok.
    - Convert the shoe size field to an integer.
    - Create a new customer struct and populate it with the extracted fields.
    - Add the customer struct to the hash table using the add_customer function.

### function 2
1. If the customer's email address already exists in the hash table:
    - Free the memory allocated for the existing customer's name and favorite food.
    - Update the existing customer's information with the new data.
2. Otherwise:
    - Create a new customer struct and populate it with the provided data.
    - Calculate the hash value of the customer's email address.
    - Determine the appropriate bucket using the modulo operator.
    - Add the customer struct to the linked list in the corresponding bucket.

### function 3
1. Prompt the user for an email address.
2. Calculate the hash value of the email address.
3. Determine the bucket using the modulo operator.
4. Search the linked list in the corresponding bucket for the customer:
    - If the customer is found:
        * Display the customer's information (email, name, shoe size, favorite food).
    - Otherwise:
        * Display a message informing the user that the customer was not found.

### function 4
1. Prompt the user for an email address.
2. Calculate the hash value of the email address.
3. Determine the bucket using the modulo operator.
4. Search for the customer in the linked list of the bucket and remove them:
    - Free the memory allocated for the customer's information.

### function 5
1. For each bucket in the hash table:
    - For each customer in the linked list of that bucket:
        * Display the customer's information (email, name, shoe size, favorite food).

### function 6
1. Open the customers.tsv file for writing.
2. For each bucket in the hash table:
    - For each customer in the linked list of that bucket:
        * Write the customer's information (email, name, shoe size, favorite food) to the file using fprintf.
3. Close the file.

### function 7
1. For each bucket in the hash table:
    - For each customer in the linked list of the bucket:
        * Free the dynamically allocated memory for the customer's name and favorite food.
        * Free the customer struct.
2. Free the memory allocated for the hash table.
