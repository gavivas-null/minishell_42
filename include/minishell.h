/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:36 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/26 21:19:17 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//-------------------------------------LIBS-------------------------------------

# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
	char			*token;
	struct s_token	*next;
}	t_token;

typedef struct s_mini
{
	t_token	*data;
}	t_mini;

//------------------------------------START------------------------------------
void	start_shell(t_mini *mini);

//token
void	read_tokens(t_mini *mini, char *line);

//etc
t_token	*create_token(char *content);
t_token	*last_token(t_token *lst);
void	add_token(t_token **lst, t_token *new);

#endif