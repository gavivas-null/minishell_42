/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:54:57 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/27 21:13:26 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	find_eq(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		return (i);
	else
		return (-1);
}

t_envp	*env_new(char *key, char *value)
{
	t_envp	*new;

	new = malloc(sizeof(t_envp));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

t_envp	*env_last(t_envp *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	env_add(t_envp **lst, t_envp *new)
{
	t_envp	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = env_last(*lst);
	last->next = new;
}

void	extract_envp(t_mini *mini, char **envp)
{
	int		i;
	int		eq;
	char	*key;
	char	*val;
	t_envp	*node;

	i = 0;
	mini->envp = NULL;
	while (envp[i])
	{
		eq = find_eq(envp[i]);
		if (eq >= 0)
		{
			key = ft_substr(envp[i], 0, eq);
			val = ft_substr(envp[i], eq + 1, ft_strlen(envp[i]) - (eq + 1));
			if (!key || !val)
				return (free(key), free(val));
			node = env_new(key, val);
			if (!node)
				return (free(key), free(val));
			env_add(&mini->envp, node);
		}
		i++;
	}
}
