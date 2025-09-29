/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagwu <dagwu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:48:53 by dagwu             #+#    #+#             */
/*   Updated: 2025/09/16 13:33:53 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
// minishell.h
extern volatile sig_atomic_t	g_last_exit_status;

typedef struct s_dat
{
	struct s_variable_node		*av;
	struct s_variable_node		*ev;
	struct s_variable_node		*lo;
	char						**ln;
	char						**xln;
	char						*tmp1;
	char						*tmp2;
	size_t						i;
	size_t						j;
	size_t						k;
	size_t						tot;
	size_t						st;
	char						**avs;
	char						**evs;
	int							no_pipes;
	int							*qtypes;
}								t_dat;

typedef struct s_variable_node
{
	char						*name;
	char						*value;
	struct s_variable_node		*next;
}								t_va;

typedef struct s_redirections
{
	char						*in_file;
	char						*out_file;
	char						*append_file;
	char						*heredoc_delim;
}								t_rdr;

void							ft_free_string_array(char **str_array);
void							ft_increment_shlvl(t_va **env_list);
int								ft_create_shlvl(t_va **env_list);
t_dat							ft_duplicate_input_args(int argc, char **argv,
									char **env);
void							ft_cleanup_data(t_dat *data);
void							ft_cleanup_exit(t_dat *data, int flag);
t_va							*create_lst_frm_arr(char **arr, t_va *h, int i,
									t_va *(*f)(char *));
t_va							*ft_create_node(char *str);
t_va							*ft_create_var_node(char *str);
char							*ft_extract_var_name(char *str);
char							*ft_extract_var_value(char *str, char quote,
									size_t len);
void							ft_free_list(t_va *head);
int								ft_strisspace(char *str);
void							ft_set_main_signals(void);
int								ft_skip_quote(char *str, int i);
int								ft_skip_token(char *str, int i);
int								ft_count_tokens(char *str);
int								ft_get_token_end(char *str, int i);
void							ft_detect_quote_type(char *token,
									int *quote_type);
char							*ft_extract_token(char *str, t_dat *d,
									int *quote_type);
void							ft_reset_iterators(t_dat *data);
char							**ft_free_token_quote(char **tokens,
									int *quote_types);
char							**ft_tokenize_line(t_dat *d, char *str,
									int **quote_types_out);
char							*ft_get_var_value(t_va *list, const char *name);
char							*ft_extract_var_key(const char *str, size_t *i);
char							*ft_strjoin_char(const char *s, char c);
void							ft_expand_loop(char *token, t_dat *data,
									char **res, size_t *i);
char							*ft_expand_token(char *token, t_dat *data,
									int qt, size_t i);
char							**ft_expand_tokens(t_dat *d, char **tokens,
									int *qtypes, int i);
void							ft_strip_surrounding_quotes(char *s);
void							ft_strip_quotes_after_equal(char *s);
void							ft_strip_quotes_from_xln(t_dat *d);
int								ft_valid_var(char *str);
t_va							*ft_find_var(t_va *list, const char *name);
int								ft_update_var_value(t_va *node,
									const char *value);
int								ft_add_local_var(t_dat *data, char *str);
void							ft_update_local_variables(t_dat *d);
int								ft_all_valid_lvar(t_dat *data, char **arr);
int								ft_is_number(const char *str);
char							*ft_get_val_from_list(t_va *head,
									const char *key);
int								ft_update_existing_var(t_va *node,
									const char *name, const char *val);
void							ft_create_env_variable(t_dat *d,
									const char *name, const char *value);
void							ft_update_env_variable(t_dat *d,
									const char *name, const char *value);
void							ft_pwd(void);
void							ft_update_directories(t_dat *data,
									char *oldpwd);
void							ft_cd_error(char *path);
void							ft_change_directory(t_dat *data, size_t k);
void							ft_echo(char **arr, size_t k);
void							ft_exit_numeric_error(char *arg);
void							ft_exit(t_dat *data, size_t k);
void							ft_env(t_dat *data);
void							ft_unset_multi_var(t_dat *d, size_t k);
t_va							*ft_remove_variable_node(const char *key,
									t_va *head, t_va *prev);
int								ft_var_name_only(char *str);
void							ft_append_env_var(t_dat *data, char *key,
									char *value);
void							ft_export_type2(t_dat *data, char *str);
t_va							*ft_export_type1_ext(char *name, char *val);
void							ft_export_type1(t_va **head, char *s,
									char *name, char *val);
void							ft_print_export(t_va *head);
t_va							*ft_merge_sorted_lists(t_va *a, t_va *b);
void							ft_split_list(t_va *source, t_va **front,
									t_va **back);
void							ft_sort_list_by_name(t_va **head_ref);
t_va							*ft_duplicate_node(const t_va *node);
int								ft_append_dup_node(const t_va *cur, t_va **head,
									t_va **tail);
t_va							*ft_duplicate_list(const t_va *head);
void							ft_print_sorted_env(t_va *head);
void							ft_export_error(char *arg, char *message);
void							ft_export_multi_var(t_dat *data, size_t k);
int								ft_handle_builtin(t_dat *data, size_t k);
void							ft_check_var_assign_and_expand_line(t_dat *data,
									char *line);
int								ft_count_list(t_va *head);
void							ft_list_to_env_array(t_dat *data);
char							*ft_join_path(char *str1, char *cmd);
char							*ft_get_cmd_path(t_dat *d, const char *cmd,
									int i);
int								ft_count_pipes(char **tokens);
void							ft_cmd_not_found(char *cmd);
void							ft_external_functions(t_dat *data, char *line);
char							**ft_extract_tokens(t_dat *data, int start,
									int end);
char							***ft_clean_cmd(char ***cmd);
int								ft_parse_cmd_helper(t_dat *d, char ***cmd,
									int *idx, int *st_i);
char							***ft_parse_cmd(t_dat *d, int st, int i,
									int idx);
void							ft_free_fd(int **fd);
int								**init_fd_array(int tot);
int								ft_create_pipes(int **fd, int tot);
void							ft_setup_io(int **fd, size_t i, size_t total);
void							ft_exec_command(t_dat *d, char **cmd);
void							ft_child_process(t_dat *d, char ***cmd,
									int **fd, size_t i);
int								ft_syntax_error_msg(char *token);
// Replace lines 183-186 in minishell.h with:

int								ft_validate_segment(char **tokens, int start,
									int end);
void							ft_fork_children(t_dat *d, char ***cmd,
									int **fd, pid_t *pids);

void							ft_close_pipes(int **fd, int tot);
void							ft_wait_children(int tot, pid_t *pids);

void							ft_execute_pipeline(t_dat *d, char ***cmd);
int								ft_parse_redirection(char **tokens, t_rdr *r);
int								ft_redir_in(char *file);
int								ft_redir_out(char *file);
int								ft_redir_append(char *file);
int								ft_apply_redirections(t_rdr *r, char **tokens);
int								ft_remove_redirections(char ***tokens_ptr,
									int i, int j);
int								ft_remove_sing_redirections(char **t, int i,
									int j);
int								ft_is_redirection(char *str);
void							ft_free_redirection(t_rdr *r);
int								ft_syntax_error(char *token);
int								ft_check_redir(char **tokens, int i);
int								ft_check_pipe(char **tokens, int i);
int								ft_validate_syntax(char **tokens);
char							*ft_expand_exit_status(t_dat *d, char *token);
char							*append_char(char *res, char *token, int *i);
char							*append_exit_status(char *res, int status,
									int *i);
char							*ft_strjoin_free(char *s1, char *s2);
void							ft_set_child_signals(void);
void							ft_set_main_signals(void);
void							ft_child_sigint_handler(int sig);
void							ft_parent_sigint_handler(int sig);
void							ft_set_main_nested_signals(void);
void							ft_nested_sigint_handler(int sig);
int								ft_is_builtin(char *cmd);
void							ft_execute_builtin_in_child(t_dat *d,
									char **cmd);
void							*ft_free_error_expanded(char **expanded, int i);
char							*ft_get_cmd_path_nested(const char *cmd);
int								ft_strncmp(const char *s1, const char *s2,
									size_t n);
void							ft_nullify_pointers(t_dat *data);
void							ft_free_lines(t_dat *data);
void							ft_check_var_assign_helper(t_dat *data,
									char *line);
void							ft_cmd_error(t_dat *data, char *line);
int								ft_is_interactive(void);
void							ft_appropriate_child_signal(char *str);
void							ft_nested_minishell(t_dat *d, char **cmd,
									char *cmd_path);
void							ft_nested_child(t_dat *d, char **cmd,
									char *cmd_path, int s_stdin);
void							ft_nested_parent(t_dat *d, pid_t pid,
									int saved_stdin);
void							read_heredoc_content(int fd,
									const char *delimiter);
int								handle_heredoc(const char *delimiter);
void							heredoc_child_sigint(int sig);
void							heredoc_child(int pipe_fd[2],
									const char *delimiter);
int								ft_is_pipe_builtin(char *cmd);
int								ft_count_redirections(char **tokens);
int								handle_infile(char **tokens, int *i,
									int *last_in_fd);
int								handle_outfile_trunc(char **tokens, int *i,
									int *last_out_fd);
int								handle_outfile_append(char **tokens, int *i,
									int *last_out_fd);
int								handle_heredoc_redirect(char *heredoc_delim);
int								is_special_char(char c);
char							**ft_sub_tokenize_line(t_dat *d, char *str,
									int **quote_types_out);
char							*ft_extract_special_token(char *str, t_dat *d);
#endif
