/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:31:09 by gavivas-          #+#    #+#             */
/*   Updated: 2025/11/05 19:11:57 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	handle_command(t_pipex *px, char *cmd, int input_fd, int output_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		exit_with_error("dup2 input", NULL, NULL, 1);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		exit_with_error("dup2 output", NULL, NULL, 1);
	close(input_fd);
	close(output_fd);
	close(px->infile);
	close(px->outfile);
	close(px->pipefd[0]);
	exec_cmd(cmd, px->envp);
}
