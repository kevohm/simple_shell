#include "simple_shell.h"

/**
 * null_init - fills an allocated block of memory with null bytes.
 * @buffer: a ptr to the block of memory to be initialized
 * @size: size of the block of memory
 *
 * Return: The ptr originally passed, otherwise NULL.
 */
char *null_init(char *buffer, int size)
{
	int i;

	if (!buffer)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		buffer[i] = '\0';
	}

	return (buffer);
}

/**
 * _realloc - reallocates the memory of block using malloc and free.
 * @ptr: pointer to the old block of memory
 * @old_size: size of the old block of memory
 * @new_size: size the new block of memory should be
 *
 * Return: New pointer to new block of memory if new_size differs from old_size
 * or ptr if new_size is equal to old_size
 * or NULL if new_size is zero and ptr is not NULL
 * else NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *buffer, *c_ptr;

	/* Return pointer if no change must be made */
	if (new_size == old_size)
		return (ptr);

	/* Free ptr and return NULL if new_size is 0 and ptr is not NULL */
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	/* Set new char pointer to the same element as ptr */
	c_ptr = (char *) ptr;

	/* Allocate memory for pointer of new block */
	buffer = malloc(new_size);
	if (!buffer)
		return (NULL);

	/* Return buffer if pointer is NULL */
	if (!ptr)
		return (buffer);

	null_init(buffer, new_size);
	/* Set new block memory to old block memory */
	for (i = 0; (i < old_size) && (i < new_size); i++)
	{
		buffer[i] = c_ptr[i];
	}

	/* Type cast new pointer back to void */
	buffer = (void *) buffer;

	free(ptr);
	return (buffer);
}

/**
 * mem_init - allocates memory with malloc and null checks the memory
 * @num: the number of arguments
 * Return: No Value
 */
void mem_init(int num, ...)
{
	va_list v_ls;
	char **v_arg;

	va_start(v_ls, num);
	for (; num; num -= 2)
	{
		v_arg = va_arg(v_ls, char **);
		*v_arg = malloc(sizeof(*v_arg) * (va_arg(v_ls, int) + 1));
		if (*v_arg == NULL)
			return;
	}
}

/**
 * minit2 - allocates memory with malloc and null checks the memory
 * @num: the number of arguments
 * Return: No Value
 */
void minit2(int num, ...)
{
	va_list v_ls;
	char ***v_arg;

	va_start(v_ls, num);
	for (; num; num -= 2)
	{
		v_arg = va_arg(v_ls, char ***);
		*v_arg = malloc(sizeof(char *) * (va_arg(v_ls, int) + 1));
		if (*v_arg == NULL)
			return;
	}
}
