#include "shell.h"

/**
 *_realloc -  reallocates memory block
 *
 *@ptr: pointer
 *@old_size: previous size of the pointer
 *@new_size: new size of the pointer
 *Return: void pointer rellocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * free_all - frees memory block
 *  
 * @cmd:Array Pointer
 * @line:Char Pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy byte
 * 
 * @dest: Destination
 * @src: Source
 * @n: number of bytes
 *Return: Void
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - fill an array by constant byte
 * 
 * @a: Void Pointer
 * @el: int
 * @len: length int
 *Return: Void
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc -  allocates memory for an array.
 * 
 * @size: Size
 * Return: Void
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
		
	if (a == NULL)
		return (NULL);
	
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
