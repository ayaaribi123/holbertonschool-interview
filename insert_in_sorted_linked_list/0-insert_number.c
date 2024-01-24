#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head list
 * @number: node to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newNode = malloc(sizeof(listint_t));
				listint_t *prevNode = *head;
    if (!newNode)
        return NULL;

    newNode->n = number;
    newNode->next = NULL;

    if (*head == NULL || (*head)->n >= newNode->n)
    {
        newNode->next = *head;
        *head = newNode;
        return newNode;
    }

    while (prevNode->next && prevNode->next->n < newNode->n)
    {
        prevNode = prevNode->next;
    }

    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return newNode;
}
