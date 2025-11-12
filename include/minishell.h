/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:36 by gavivas-          #+#    #+#             */
/*   Updated: 2025/11/12 21:31:28 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//-------------------------------------LIBS-------------------------------------

# include <libft.h>
# include <pipex.h>
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
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_mini
{
	t_token	*data;
	t_envp	*envp;
}	t_mini;

typedef enum e_rtype
{
	R_IN,
	R_OUT_TRUNC,
	R_OUT_APPEND,
	R_HEREDOC
}	t_rtype;

typedef struct s_redir
{
	t_rtype			type;
	char			*file;
	int				fd;
	struct s_redir	*next;
}	t_redir;

//------------------------------------START------------------------------------
void	start_shell(t_mini *mini);
void	read_tokens(t_mini *mini, char *line);

//------------------------------------TOKEN------------------------------------
t_token	*create_token(char *content);
t_token	*last_token(t_token *lst);
void	add_token(t_token **lst, t_token *new);

//------------------------------------ENVP------------------------------------
t_envp	*env_last(t_envp *lst);
t_envp	*env_new(char *key, char *value);
void	env_add(t_envp **lst, t_envp *new);
void	extract_envp(t_mini *mini, char **envp);
t_envp	*find_variable_key(t_envp *dct, char *key);
t_envp	*add_variable(t_envp **env, char *key, char *value);
int		ft_str_isalnum(char *str);
void	work_with_env(t_mini *mini, char *line);

//------------------------------------REDIR------------------------------------
t_redir	*redir_new(t_rtype type, char *file);
t_redir	*redir_last(t_redir *lst);
void	redir_add(t_redir **lst, t_redir *new);
void	redir_clear(t_redir **lst);

#endif