/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:04:59 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:05:00 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void 		combo0(void);
void		combo1(void);
void		combo2(void);
void		combo_checklist(void);

static t_pars_list	*error_list(void)
{
	ft_putstr_fd("42sh: error malloc\n", 2);
	return (NULL);
}
// $> ls -l &
t_pars_list			*test100(void)
{
	t_pars_list		*list0;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;

	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 1;
	list0->nbr_ampersant = 1;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	return (list0);
}
// $> true ; false
static t_pars_list			*test16(void)
{
	t_pars_list		*list0, *list1;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "true");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("true");
	list0->pars_args[1] = NULL;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 1;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "false");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("false");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	list0->right = list1;
	list1->left = list0;
	return (list0);
}
//$> mkfifo fifo ; ls -lR /usr >fifo 2>&1 & ; jobs
static t_pars_list			*test15(void)
{
	t_pars_list		*list0, *list1, *list2;
	t_red_stream	*std_list0, *std_list1;

	if(!(std_list0 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list0->stream_a = 1;
	std_list0->stream_in = -1;
	std_list0->fd_file = -1;
	ft_strcat(std_list0->stream_name, "./fifo");
	std_list0->flag_file = 1;
	std_list0->next = NULL;
	std_list0->left = NULL;

	if(!(std_list1 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list1->stream_a = 2;
	std_list1->stream_in = 1;
	std_list1->fd_file = -1;
	std_list1->stream_name[0] = '\0';
	std_list1->flag_file = 0;
	std_list1->next = NULL;
	std_list1->left = NULL;

	std_list0->next = std_list1;
	std_list1->left = std_list0;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "mkfifo");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("mkfifo");
	list0->pars_args[1] = ft_strdup("fifo");;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 1;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "ls");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("ls");
	list1->pars_args[1] = ft_strdup("-lR");
	list1->pars_args[2] = ft_strdup("/usr");
	list1->pars_args[3] = NULL;
	list1->status = 0;
	list1->stream_list = std_list0;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "jobs");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("jobs");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	list0->right = list1;
	list1->left = list0;

	list1->right = list2;
	list2->left = list1;

	list2->right = NULL;
	return (list0);
}
// $> ls doesnotexist . >/dev/null 2>&1
static t_pars_list			*test14(void)
{
	t_pars_list		*list0;
	t_red_stream	*std_list0, *std_list1;

	if(!(std_list0 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list0->stream_a = 1;
	std_list0->stream_in = -1;
	std_list0->fd_file = -1;
	ft_strcat(std_list0->stream_name, "/dev/null");
	std_list0->flag_file = 1;
	std_list0->next = NULL;
	std_list0->left = NULL;

	if(!(std_list1 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list1->stream_a = 2;
	std_list1->stream_in = 1;
	std_list1->fd_file = -1;
	std_list1->stream_name[0] = '\0';
	std_list1->flag_file = 0;
	std_list1->next = NULL;
	std_list1->left = NULL;

	std_list0->next = std_list1;
	std_list1->left = std_list0;


	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("doesnotexist");
	list0->pars_args[2] = ft_strdup(".");
	list0->pars_args[3] = NULL;
	list0->status = 0;
	list0->stream_list = std_list0;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	return(list0);
}
// $> ls doesnotexist . 2>&1 >/dev/null
static t_pars_list			*test13(void)
{
	t_pars_list		*list0;
	t_red_stream	*std_list0, *std_list1;

	if(!(std_list0 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list0->stream_a = 2;
	std_list0->stream_in = 1;
	std_list0->fd_file = -1;
	std_list0->stream_name[0] = '\0';
	std_list0->flag_file = 0;
	std_list0->next = NULL;
	std_list0->left = NULL;

	if(!(std_list1 = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list1->stream_a = 1;
	std_list1->stream_in = -1;
	std_list1->fd_file = -1;
	ft_strcat(std_list1->stream_name, "/dev/null");
	std_list1->flag_file = 1;
	std_list1->next = NULL;
	std_list1->left = NULL;

	std_list0->next = std_list1;
	std_list1->left = std_list0;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("doesnotexist");
	list0->pars_args[2] = ft_strdup(".");
	list0->pars_args[3] = NULL;
	list0->status = 0;
	list0->stream_list = std_list0;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	return(list0);
}
// $> cat <&4
static t_pars_list			*test12(void)
{
	t_pars_list		*list0;
	t_red_stream	*std_list;

	if(!(std_list = (t_red_stream *)malloc(sizeof(t_red_stream))))
		return (error_list());
	std_list->stream_a = 4;
	std_list->stream_in = 1;
	std_list->fd_file = -1;
	std_list->stream_name[0] = '\0';
	std_list->next = NULL;
	std_list->left = NULL;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "cat");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("cat");
	list0->pars_args[1] = NULL;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = std_list;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	return(list0);
}
// $> ls  | grep "sh" | wc -l | cat -e
static t_pars_list			*test11(void)
{
	t_pars_list		*list0, *list1, *list2, *list3;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = NULL;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 1;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "grep");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("grep");
	list1->pars_args[1] = ft_strdup("sh");
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 1;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "wc");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("wc");
	list2->pars_args[1] = ft_strdup("-l");
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 1;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	if (!(list3 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list3->name_func, "cat");
	list3->name_run_func[0] = '\0';
	list3->pars_args[0] = ft_strdup("cat");
	list3->pars_args[1] = ft_strdup("-e");
	list3->pars_args[2] = NULL;
	list3->status = 0;
	list3->stream_list = NULL;
	list3->echo_status = 0;
	list3->str_status[0][0] = '\0';
	list3->flag_ampersant = 0;
	list3->nbr_ampersant = 0;
	list3->flag_pipe = 0;
	list3->flag_semicolon = 0;
	list3->flag_and = 0;
	list3->flag_or = 0;
	list3->right = NULL;
	list3->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	list2->right = list3;
	list3->left = list2;
	return (list0);
}
// $> ls | wc -l | cat -e
static t_pars_list			*test10(void)
{
	t_pars_list		*list0, *list1, *list2;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = NULL;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 1;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "wc");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("wc");
	list1->pars_args[1] = ft_strdup("-l");
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 1;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "cat");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("cat");
	list2->pars_args[1] = ft_strdup("-e");
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	return (list0);
}
// $> ls | wc -l
static t_pars_list			*test9(void)
{
	t_pars_list		*list0, *list1;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = NULL;
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 1;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "wc");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("wc");
	list1->pars_args[1] = ft_strdup("-l");
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	list0->right = list1;
	list1->left = list0;
	return (list0);
}
// $> ls -l || pwd ; ls ; pwd
static t_pars_list			*test8(void)
{
	t_pars_list		*list0, *list1, *list2, *list3;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 1;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 1;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 1;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	if (!(list3 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list3->name_func, "pwd");
	list3->name_run_func[0] = '\0';
	list3->pars_args[0] = ft_strdup("pwd");
	list3->pars_args[1] = NULL;
	list3->pars_args[2] = NULL;
	list3->status = 0;
	list3->stream_list = NULL;
	list3->echo_status = 0;
	list3->str_status[0][0] = '\0';
	list3->flag_ampersant = 0;
	list3->nbr_ampersant = 0;
	list3->flag_pipe = 0;
	list3->flag_semicolon = 0;
	list3->flag_and = 0;
	list3->flag_or = 0;
	list3->right = NULL;
	list3->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	list2->right = list3;
	list3->left = list2;
	return (list0);
}
// $> ls -l && pwd ; ls && pwd
static t_pars_list			*test7(void)
{
	t_pars_list		*list0, *list1, *list2, *list3;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 1;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 1;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	if (!(list3 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list3->name_func, "pwd");
	list3->name_run_func[0] = '\0';
	list3->pars_args[0] = ft_strdup("pwd");
	list3->pars_args[1] = NULL;
	list3->pars_args[2] = NULL;
	list3->status = 0;
	list3->stream_list = NULL;
	list3->echo_status = 0;
	list3->str_status[0][0] = '\0';
	list3->flag_ampersant = 0;
	list3->nbr_ampersant = 0;
	list3->flag_pipe = 0;
	list3->flag_semicolon = 0;
	list3->flag_and = 0;
	list3->flag_or = 0;
	list3->right = NULL;
	list3->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	list2->right = list3;
	list3->left = list2;
	return (list0);
}
// $> ls -l && pwd && ls && pwd
static t_pars_list			*test6(void)
{
	t_pars_list		*list0, *list1, *list2, *list3;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 1;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 1;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	if (!(list3 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list3->name_func, "pwd");
	list3->name_run_func[0] = '\0';
	list3->pars_args[0] = ft_strdup("pwd");
	list3->pars_args[1] = NULL;
	list3->pars_args[2] = NULL;
	list3->status = 0;
	list3->stream_list = NULL;
	list3->echo_status = 0;
	list3->str_status[0][0] = '\0';
	list3->flag_ampersant = 0;
	list3->nbr_ampersant = 0;
	list3->flag_pipe = 0;
	list3->flag_semicolon = 0;
	list3->flag_and = 0;
	list3->flag_or = 0;
	list3->right = NULL;
	list3->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	list2->right = list3;
	list3->left = list2;
	return (list0);
}
// $> ls -l && pwd && ls || pwd
static t_pars_list			*test5(void)
{
	t_pars_list		*list0, *list1, *list2, *list3;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 1;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 1;
	list2->right = NULL;
	list2->left = NULL;

	if (!(list3 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list3->name_func, "pwd");
	list3->name_run_func[0] = '\0';
	list3->pars_args[0] = ft_strdup("pwd");
	list3->pars_args[1] = NULL;
	list3->pars_args[2] = NULL;
	list3->status = 0;
	list3->stream_list = NULL;
	list3->echo_status = 0;
	list3->str_status[0][0] = '\0';
	list3->flag_ampersant = 0;
	list3->nbr_ampersant = 0;
	list3->flag_pipe = 0;
	list3->flag_semicolon = 0;
	list3->flag_and = 0;
	list3->flag_or = 0;
	list3->right = NULL;
	list3->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	list2->right = list3;
	list3->left = list2;
	return (list0);
}
// $> ls -l && pwd && ls
static t_pars_list			*test4(void)
{
	t_pars_list		*list0, *list1, *list2;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 1;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	return (list0);
}
// $> ls -l && pwd || ls
static t_pars_list			*test3(void)
{
	t_pars_list		*list0, *list1, *list2;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 1;
	list1->right = NULL;
	list1->left = NULL;

	if (!(list2 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list2->name_func, "ls");
	list2->name_run_func[0] = '\0';
	list2->pars_args[0] = ft_strdup("ls");
	list2->pars_args[1] = NULL;
	list2->pars_args[2] = NULL;
	list2->status = 0;
	list2->stream_list = NULL;
	list2->echo_status = 0;
	list2->str_status[0][0] = '\0';
	list2->flag_ampersant = 0;
	list2->nbr_ampersant = 0;
	list2->flag_pipe = 0;
	list2->flag_semicolon = 0;
	list2->flag_and = 0;
	list2->flag_or = 0;
	list2->right = NULL;
	list2->left = NULL;

	list0->right = list1;
	list1->left = list0;
	list1->right = list2;
	list2->left = list1;
	return (list0);
}
// $> ls -l && pwd
static t_pars_list			*test2(void)
{
	t_pars_list		*list0, *list1;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 1;
	list0->flag_or = 0;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	list0->right = list1;
	list1->left = list0;
	return (list0);
}
// $> ls -l || pwd
static t_pars_list			*test1(void)
{
	t_pars_list		*list0, *list1;

	if (!(list0 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list0->name_func, "ls");
	list0->name_run_func[0] = '\0';
	list0->pars_args[0] = ft_strdup("ls");
	list0->pars_args[1] = ft_strdup("-l");
	list0->pars_args[2] = NULL;
	list0->status = 0;
	list0->stream_list = NULL;
	list0->echo_status = 0;
	list0->str_status[0][0] = '\0';
	list0->flag_ampersant = 0;
	list0->nbr_ampersant = 0;
	list0->flag_pipe = 0;
	list0->flag_semicolon = 0;
	list0->flag_and = 0;
	list0->flag_or = 1;
	list0->right = NULL;
	list0->left = NULL;

	if (!(list1 = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	ft_strcat(list1->name_func, "pwd");
	list1->name_run_func[0] = '\0';
	list1->pars_args[0] = ft_strdup("pwd");
	list1->pars_args[1] = NULL;
	list1->pars_args[2] = NULL;
	list1->status = 0;
	list1->stream_list = NULL;
	list1->echo_status = 0;
	list1->str_status[0][0] = '\0';
	list1->flag_ampersant = 0;
	list1->nbr_ampersant = 0;
	list1->flag_pipe = 0;
	list1->flag_semicolon = 0;
	list1->flag_and = 0;
	list1->flag_or = 0;
	list1->right = NULL;
	list1->left = NULL;

	list0->right = list1;
	list1->left = list0;
	return (list0);
}

t_pars_list			*test(void)
{
	t_pars_list		*list;
	t_exec execlist;

	ft_strcat(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki");

	combo0();
	combo1();
	combo2();
	combo_checklist();





/**
*** Для тестирования необходимо добавить команду jobs
**/
//	list = test15();		// $> mkfifo fifo ; ls -lR /usr >fifo 2>&1 & ; jobs
//	{
//		ft_putstr("\n\n\n15>>> mkfifo fifo ; ls -lR /usr >fifo 2>&1 & ; jobs\n");
//		ft_putstr("nid>> {{Сообщение, указывающее, что команда \"ls\" выполняется}}\n");
//		check_choice(&list);
//		free_pars_list(list);
//	}
	return (NULL);
}

void 		combo0(void)		// &&, ||
{
	t_pars_list		*list;
	t_pars_list		**buflist;
	t_exec execlist;

	ft_strcat(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki");

	list = test16();		// $> true ; false
	buflist = &list;
	{
		ft_putstr("\n\n\n16>>> true ; false\n");
		ft_putstr("nid>> {{}}\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}

	list = test1();		// $> ls -l || pwd +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n1>>> ls -l || pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test2();		// $> ls -l && pwd +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n2>>> ls -l && pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test3();		// $> ls -l && pwd || ls +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n3>>> ls -l && pwd || ls\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test4();		// $> ls -l && pwd && ls +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n4>>> ls -l && pwd && ls\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test5();		// $> ls -l && pwd && ls || pwd +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n5>>> ls -l && pwd && ls || pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test6();		// $> ls -l && pwd && ls && pwd
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n6>>> ls -l && pwd && ls && pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
}

void		combo1(void)		// &&, ;, ||
{
	t_pars_list		*list;
	t_pars_list		**buflist;
	t_exec execlist;

	ft_strcat(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki");

	list = test7();		// $> ls -l && pwd ; ls && pwd +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n7>>> ls -l && pwd ; ls && pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}

	list = test8();		// $> ls -l || pwd ; ls ; pwd +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n8>>> ls -l || pwd ; ls ; pwd\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
}

void		combo2(void)		// |
{
	t_pars_list		*list;
	t_pars_list		**buflist;
	t_exec execlist;

	ft_strcat(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki");

	list = test9();				// $> ls | wc -l +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n9>>> ls | wc -l\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test10();			// $> ls | wc -l | cat -e +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n10>>> ls | wc -l | cat -e\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
	list = test11();		// $> ls  | grep "sh" | wc -l | cat -e +
	buflist = &list;
	if (list)
	{
		ft_putstr("\n\n\n11>>> ls | grep \"sh\" | wc -l | cat -e\n");
		check_choice(execlist, buflist);
		free_pars_list(list);
	}
}

void		combo_checklist(void)
{
	t_pars_list	*list;
	t_exec execlist;

	ft_strcat(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki");

	list = test12();		// $> cat <&4 +
	{
		ft_putstr("\n\n\n12>>> cat <&4\n");
		ft_putstr("nid>> {{Сообщение об ошибке, указывающее, что дескриптор файла недействителен}}\n");
		check_choice(execlist, &list);
	}

	list = test13();		// $> ls doesnotexist . 2>&1 >/dev/null +
	{
		ft_putstr("\n\n\n13>>> ls doesnotexist . 2>&1 >/dev/null\n");
		ft_putstr("nid>> {{ls: doesnotexist: No such file or directory}}\n");
		check_choice(execlist, &list);
	}

	list = test14();		// $> ls doesnotexist . >/dev/null 2>&1 +
	{
		ft_putstr("\n\n\n14>>> ls doesnotexist . >/dev/null 2>&1\n");
		ft_putstr("nid>> {{}}\n");
		check_choice(execlist, &list);
	}
}
