#include "shell.h"

/**
 * _getenv_var - gets enviroment variable
 *@name: enviroment variable name.
 *@env_var: enviroment variables
 *
 *Return: the variable value.
 */

char *_getenv_var(const char *name, char **env_var)
{
	char *val_env, *name_env;
	unsigned int i = 0, len;

	len = _conststrlen(name);

	name_env = malloc(sizeof(char) * len + 1);
	if (name_env == NULL)
		return (NULL);

	_conststrncpy(name_env, name, len);

	val_env = strtok(env_var[i], "=");
	while (env_var[i])
	{
		if (_strcmp(val_env, name_env))
		{
			val_env = strtok(NULL, "\n");
			free(name_env);
			return (val_env);
		}
		i++;
		val_env = strtok(env_var[i], "=");
	}
	free(name_env);
	return (NULL);
}

/**
  *envp_print - Print all enviroment variables
  *@env_var: enviroment variables for the user
  *
  *Return: (void)
  */

void envp_print(char **env_var)
{
	unsigned int i = 0, len;

	while (env_var[i])
	{
		len = _strlen(env_var[i]);
		write(STDOUT_FILENO, env_var[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
