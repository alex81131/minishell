/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:45:43 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/10 17:45:43 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>

//	COLORS
# define BLUE "\033[0;38;5;123m"
# define LIGHT_PINK "\033[0;38;5;200m"
# define PINK "\033[0;38;5;198m"
# define DARK_BLUE "\033[1;38;5;110m"
# define GREEN "\033[1;32;111m"
# define LIGHT_GREEN "\033[0;38;5;121m"
# define LIGHT_RED "\033[0;31;5;110m"
# define FLASH_GREEN "\033[33;32m"
# define WHITE_BOLD "\033[37m"
# define GREY "\033[3;90m"
# define ORANGE "\033[3;91m"
# define YELLOW "\033[0;33m"
# define YELLOW_BOLD "\033[1;33m"
# define RESET   "\033[0m"
# define WHITESPACES " \t\n\v\f\r"

//	STRUCTURE
typedef struct	s_sh
{
	char		**key;
	char		**value;
	char		***cmd;
	char		**path;
	t_hash		*hash;
	t_hash		*env;
	t_hash		*add;
	char		printed;
	short		question_mark;
	char		*redir;
	int			fd[2];
	char		*target_file;
	int			stdin_bkp;
}				t_sh;

typedef struct		s_hash
{
	char			*key;
	void			*value;
	char			*type;
	struct s_hash	*top;
	struct s_hash	*before;
	struct s_hash	*next;
	struct s_hash	*(*new)(char *, void *, char *);
	void			(*del)(struct s_hash **, struct s_hash *, struct s_hash *);
	void			(*print)(struct s_hash *, char *);
	void			(*add_back)(struct s_hash **, struct s_hash *);
	void			(*add_front)(struct s_hash **, struct s_hash *);
	void			(*del_all)(struct s_hash **);
	void			*(*search)(struct s_hash *, char *);
	size_t			(*len)(struct s_hash *);
	void			(*change)(struct s_hash *, char *, void *, char *);
	void			(*sort_key)(struct s_hash **, struct s_hash *);
	void			(*rsort_key)(struct s_hash **, struct s_hash *);
	void			(*sort_val)(struct s_hash **, struct s_hash *);
	void			(*rsort_val)(struct s_hash **, struct s_hash *);
	struct s_hash	*(*find)(struct s_hash *, char *);
}					t_hash;

typedef struct		s_strhash
{
	char	*key;
	char	*value;
}					t_strhash;

//	HASH
void		ft_hashadd_front(t_hash **hash, t_hash *new);
void		ft_hashadd_back(t_hash **hash, t_hash *new);
void		ft_hashdel(t_hash **hash, t_hash *before, t_hash *next);
void		ft_hash_display(t_hash *hash, char *name);
void		ft_hash_free(t_hash **hash);
void		*ft_hash_search_value(t_hash *hash, char *key);
void		ft_hash_change_value(t_hash *hash, char *key, \
								void *value, char *type);
void		ft_hash_sort_key(t_hash **alst, t_hash *hash);
void		ft_hash_revsort_key(t_hash **alst, t_hash *hash);
void		ft_hash_sort_value(t_hash **alst, t_hash *hash);
void		ft_hash_revsort_value(t_hash **alst, t_hash *hash);
size_t		ft_hashlen(t_hash *hash);
t_hash		*ft_hash_init(void);
t_hash		*ft_hashnew(char *key, void *value, char *type);
t_hash		*ft_hash_find(t_hash *hash, char *key);

//	EXEC CMD
void		exec_cmd(t_sh *sh, char **cmd);
int			ft_fork_process(t_sh *sh, char **cmd);
void		ft_exec(size_t i);
void		replace_question_mark(char **cmd);

//	BUILTIN
void		builtin_export(t_sh *sh, char **key);
void		exec_builtin(t_sh *sh, size_t j);
void		builtin_env(t_sh *sh, t_hash *env);
void		builtin_cd(t_sh *sh, char **cmd);
void		get_env_var(t_sh *sh, char **env, size_t i);
void		replace_env_var(t_sh *sh, char **cmd, size_t i);
void		builtin_echo(char **cmd);
void		builtin_unset(t_sh *sh, char **key, size_t j);
int			is_builtin(char *cmd);

//	SIGNAL
void		handle_sigint(int sig);
void		child_sigint(int sig);

//	PARSING
char		parsing(char *str);
char		***alloc_commands(char *str, size_t *nb);
size_t		bloc_counter(char *s, size_t i, size_t block);
char		**parse(char *s);
char		**fill_cmd(char *s, char **cmd, size_t i, size_t j);
char		*double_quote_allocator(char **s, size_t *j);
char		*simple_quote_allocator(char *s, size_t *j);
char		*non_special_allocator(char **s, size_t *j);
char		*quote_checker(char *s, size_t quote, size_t dquote);
size_t		separator_counter(char *s, size_t i, size_t block);
void		quotes_splitter(char *s, size_t *i, char c);
char		*complete_cmd(char *s, char c);
char		*found_redir(char *s, size_t *j, size_t *i, size_t nb);
size_t		separator_counter(char *s, size_t i, size_t block);
int			analyser(char *str, char *tok, size_t i);
int			quotes_error(char *s);
char		*fill_str_with_var(char *s, size_t i, size_t j, char *var);
char		*join_quotes(char *s, size_t i, size_t j);
char		**fill_cmd(char *s, char **cmd, size_t i, size_t j);

//	DISPLAY
void		print_prompt(t_hash *hash);
void		printf_welcome(void);

//	REDIRECTIONS
void		ft_pipe(int i, int in_fd);
void		redirections(int i, int in_fd);
void		redir_counter(void);
void		right_redir(int *i);
int			lonely_command(int i, int in_fd);
void		redirect(int oldfd, int newfd);
void		left_redir(int *i);
void		final_redir(int i, int in_fd);

//	UTILS
void		change_sh_path(t_hash *env, t_hash *hash);
void		free_string(char **arr);
void		ft_exit(int exit_code, int i);
t_hash		*ft_hash_initialize(void);
char		*ft_strclean(char *str, const char *charset, int free);
t_sh		*sh(void);

#endif