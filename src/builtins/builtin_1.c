/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:41:11 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/09/13 11:59:08 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_sh *sh, char *name, t_arg *arg)
{
	sh = sh;
	name = name;
	arg = arg;
	// if (ft_strcmp(name, "echo") == 0)
	// 	exec_echo(arg);
	// else if (ft_strcmp(name, "cd") == 0)
	// 	exec_cd(sh->env, arg);
	// else if (ft_strcmp(name, "pwd") == 0)
	// 	exec_pwd(arg);
	// else if (ft_strcmp(name, "export") == 0)
	// 	exec_export(sh->env, arg);
	// else if (ft_strcmp(name, "unset") == 0) //bunu atladim
	// 	exec_unset(sh->env, arg);
	// else if (ft_strcmp(name, "env") == 0) // burada kaldim
	// 	exec_env(name, *arg);
	// else if (ft_strcmp(name, "exit") == 0)
	// 	exec_exit(sh, arg);
	return (0);
}

int	is_builtin(char *name)
{
	if (ft_strcmp(name, "echo") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "cd") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "pwd") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "export") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "unset") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "env") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(name, "exit") == 0)
		return (2);
	else
		return (EXIT_FAILURE);
}
