/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:36 by gavivas-          #+#    #+#             */
/*   Updated: 2026/01/18 20:44:44 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//-------------------------------------LIBS-------------------------------------

# include <libft.h>
# include <pipex.h>
# include <lexer.h>
# include <parser.h>
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

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_mini
{
	t_envp			*envp;
}	t_mini;

//------------------------------------START------------------------------------
void			start_shell(t_mini *mini);

//------------------------------------ENVP------------------------------------
t_envp			*env_last(t_envp *lst);
t_envp			*env_new(char *key, char *value);
void			env_add(t_envp **lst, t_envp *new);
void			extract_envp(t_mini *mini, char **envp);
t_envp			*find_variable_key(t_envp *dct, char *key);
t_envp			*add_variable(t_envp **env, char *key, char *value);
int				ft_str_isalnum(char *str);
void			work_with_env(t_mini *mini, char *line);

#endif