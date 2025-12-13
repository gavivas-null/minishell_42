/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:27:17 by gavivas-          #+#    #+#             */
/*   Updated: 2025/12/13 00:58:07 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redir = NULL;
	cmd->next = NULL;
	return (cmd);
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
		i++;
	return (i);
}

int	cmd_add_arg(t_cmd *cmd, char *word)
{
	char	**new_argv;
	char	*dup;
	int		len;
	int		i;

	if (!cmd || !word)
		return (-1);
	dup = ft_strdup(word);
	if (!dup)
		return (-1);
	len = argv_len(cmd->argv);
	new_argv = malloc(sizeof(char *) * (len + 2));
	if (!new_argv)
		return (free(dup), -1);
	i = 0;
	while (i < len)
	{
		new_argv[i] = cmd->argv[i];
		i++;
	}
	new_argv[len] = dup;
	new_argv[len + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
	return (0);
}

int	cmd_add_redir(t_cmd *cmd, t_rtype type, char *file)
{
	t_redir	*new;

	if (!cmd)
		return (-1);
	if (!file || !*file)
		return (-1);
	new = redir_new(type, file);
	if (!new)
		return (-1);
	if (cmd->redir == NULL)
		cmd->redir = new;
	else
		redir_add(&cmd->redir, new);
	return (0);
}

void	cmd_clear(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	while (cmd->argv && cmd->argv[i])
	{
		free(cmd->argv[i]);
		i++;
	}
	free(cmd->argv);
	redir_clear(&cmd->redir);
	free(cmd);
}
