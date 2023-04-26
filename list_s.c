#include "main.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to the new head node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (*head);
}
/**
 * free_sep_list - frees a sep_list
 *
 * @head: head of the linked list.
 *
 * Return: no return.
 */
void free_sep_list(list_t **head)
{
	list_t *temp;
	list_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp->str);
			free(temp);
		}
		*head = NULL;
	}
}
/**
 * add_line_node_end - adds a command line at the end
 * of a list.
 * @head: address of pointer to head node
 * @line: command line
 *
 * Return: pointer to the head of the list
 */
list_t *add_line_node_end(list_t **head, char *line)
{
	list_t *new_node, *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->line = line;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_node;
	}

	return (*head);
}
/**
 * free_line_list - frees a list
 * @head: address of pointer to head node
 *
 * This function frees the memory allocated for each node in the list,
 * starting from the head node.
 */
void free_line_list(list_t **head)
{
	list_t *temp, *current;

	if (!head)
		return;

	current = *head;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}

	*head = NULL;
}
