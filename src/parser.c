/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:11:49 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/26 21:22:11 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_copywords(char const *s, int *i)
{
	char	*new;
	int		j;

	while (s[*i] != '\0' && (s[*i] == '\t' || s[*i] == ' '))
		(*i)++;
	j = *i;
	while (s[j] != '\0' && (s[*i] != '\t' && s[*i] != ' '))
		j++;
	new = ft_substr(s, *i, j - *i);
	if (!new)
		return (NULL);
	*i = j;
	return (new);
}

void	read_tokens(t_mini *mini, char *line)
{
	int		i;
	char	*word;
	t_token	*token;

	i = 0;
	while (line[i])
	{
		word = ft_copywords(line, &i);
		token = create_token(word);
		add_token(&mini->data, token);
	}
}
