#include "dog.h"
#include <stdio.h>

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to the struct dog variable to initialize
 * @name: Name to assign to the dog
 * @age: Age to assign to the dog
 * @owner: Owner to assign to the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

