#include <iostream>
#include <cstdlib>

typedef struct node {
        std::string car_brand;
        int car_price;
        struct node * next;
} node_t;

void add_node_to_end(node_t * head, std::string brand, int price)
{
       node_t * current = head;
       while(current->next != NULL) {
                current = current->next;
       }
       current->next = new node_t;
       current->next->car_brand = brand;
       current->next->car_price = price;
       current->next->next = NULL;
}

void add_node_to_start(node_t ** head, std::string brand, int price)
{
        node_t * new_elem = new node_t;
        new_elem->car_brand = brand;
        new_elem->car_price = price;
        new_elem->next = *head;
        *head = new_elem;
}

void del_from_end(node_t * head)
{
        node_t * current = head;
        node_t * previous = NULL;
        while (current->next != NULL) {
                previous = current;
                current = current->next;
        }
        free(current);
        if (previous != NULL) {
                previous->next = NULL;
        }
}

void del_from_start(node_t ** head)
{
        node_t * current = *head;
        node_t * next = current->next;
        free(*head);
        *head = next;
}

void print_list(node_t * head)
{
        node_t * current = head;
        while (current != NULL) {
              std::cout << "Car: " << current->car_brand 
                << "Price: " << current->car_price << "\n";
              current = current->next;
        }
}

int main()
{
        node_t * head = NULL;
        head = new node_t;
        head->car_brand = "Ferrari";
        head->car_price = 1000000;
        head->next = new node_t;
        head->next->car_brand = "Porsche";
        head->next->car_price = 999999;
        head->next->next = NULL;

        add_node_to_end(head, "Lamborghini", 10000000);
        add_node_to_start(&head, "Chevrolette", 900000);
        
        del_from_start(&head);
        del_from_end(head);
        print_list(head);

        return 1;
}
