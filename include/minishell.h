/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:36 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/27 19:29:01 by gavivas-         ###   ########.fr       */
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
# include <stdint.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>

//------------------------------------STRUCT------------------------------------

typedef struct s_token
{
	char			*token;
	struct s_token	*next;
}	t_token;

typedef struct s_envp
{
	char			*value;
	char			*key;
	struct s_envp	*next;
	
}	t_envp;

typedef struct s_mini
{
	t_token	*data;
	t_envp	*envp;
}	t_mini;

//------------------------------------START------------------------------------
void	start_shell(t_mini *mini);
void	read_tokens(t_mini *mini, char *line);

//------------------------------------UTILS------------------------------------
t_token	*create_token(char *content);
t_token	*last_token(t_token *lst);
void	add_token(t_token **lst, t_token *new);


#endif