#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
*_strdup - Duplicates a string in memory
*@str: The string to duplicate
*Return: Pointer to the duplicated string or NULL if memory allocation fails
*/
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	i = 0;
	while (i <= length)
	{
		duplicate[i] = str[i];
		i++;
	}

	return (duplicate);
}

/**
*new_dog - Creates a new dog
*@name: Name of the dog
*@age: Age of the dog
*@owner: Owner of the dog
*Return: Pointer to the new dog structure, or NULL if memory allocation fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name = _strdup(name);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->age = age;

	new_dog->owner = _strdup(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	return (new_dog);
}

