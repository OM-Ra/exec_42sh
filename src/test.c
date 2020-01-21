#include "sh42.h"
// &&, ||
void 		combo0(void);
void		combo1(void);

static t_pars_list	*error_list(void)
{
	ft_putstr_fd("42sh: error malloc\n", 2);
	return (NULL);
}
// $> ls | wc -l
t_pars_list			*test9(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
t_pars_list			*test8(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
	list3->flag_file = 0;
	list3->name_file[0] = '\0';
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
t_pars_list			*test7(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
	list3->flag_file = 0;
	list3->name_file[0] = '\0';
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
t_pars_list			*test6(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
	list3->flag_file = 0;
	list3->name_file[0] = '\0';
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
t_pars_list			*test5(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
	list3->flag_file = 0;
	list3->name_file[0] = '\0';
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
t_pars_list			*test4(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
t_pars_list			*test3(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
	list2->flag_file = 0;
	list2->name_file[0] = '\0';
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
t_pars_list 		*test2(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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
t_pars_list			*test1(void)
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
	list0->flag_file = 0;
	list0->name_file[0] = '\0';
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
	list1->flag_file = 0;
	list1->name_file[0] = '\0';
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

	list0->right = list1;
	list1->left = list0;
	return (list0);
}

t_pars_list			*test(void)
{
	t_pars_list		*list;
	list = test9();			// $> ls | wc -l
	if (list)
	{
		ft_putstr("\n\n\n9>>> ls | wc -l\n");
		check_choice(&list);
		free_pars_list(list);
	}
	return (NULL);
}

void 		combo0(void)		// &&, ||
{
	t_pars_list		*list;

	list = test1();		// $> ls -l || pwd +
	if (list)
	{
		ft_putstr("\n\n\n1>>> ls -l || pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test2();		// $> ls -l && pwd +
	if (list)
	{
		ft_putstr("\n\n\n2>>> ls -l && pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test3();		// $> ls -l && pwd || ls +
	if (list)
	{
		ft_putstr("\n\n\n3>>> ls -l && pwd || ls\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test4();		// $> ls -l && pwd && ls +
	if (list)
	{
		ft_putstr("\n\n\n4>>> ls -l && pwd && ls\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test5();		// $> ls -l && pwd && ls || pwd +
	if (list)
	{
		ft_putstr("\n\n\n5>>> ls -l && pwd && ls || pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test6();		// $> ls -l && pwd && ls && pwd
	if (list)
	{
		ft_putstr("\n\n\n6>>> ls -l && pwd && ls && pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
}

void		combo1(void)
{
	t_pars_list		*list;

	list = test7();		// $> ls -l && pwd ; ls && pwd +
	if (list)
	{
		ft_putstr("\n\n\n7>>> ls -l && pwd ; ls && pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
	list = test8();		// $> ls -l || pwd ; ls ; pwd +
	if (list)
	{
		ft_putstr("\n\n\n8>>> ls -l || pwd ; ls ; pwd\n");
		check_choice(&list);
		free_pars_list(list);
	}
}	// &&, ||, ;
