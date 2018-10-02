#include "lem_in.h"

#define STARTS l->m.starts_tunnels
#define END l->m.end_tunnels
#define NBCASES l->map.nbcases

int	count_new_childs(t_lemin *l, t_nodelist *nl, t_path *p)
{
	int count;
	int i;

	i = 0;
	while (i < l->map.nbcases)
	{
		if (i && l->map.graph[p->curr][i] != 0 && check_nodelist(nl, i))
			count++;
		i++;
	}
	p->new_nodes = count;
	return (1);
}


void sort_paths(t_lemin *l, t_nodelist *nl, t_pathlist *paths)
{
	t_path *tmp1;
	t_nodelist *tmpnl;
	int					tmpcurr;
	int					tmpnew_nodes;

	tmp1 = paths->start;
	while (tmp1->next)
	{
		if (tmp1->new_nodes > tmp1->next->new_nodes))
		{
			tmpcurr = tmp1->curr;
			tmpnew_nodes = tmp1->new_nodes;
			tmpnl = tmp1->nodes;
			tmp1->nodes = tmp1->next->nodes;
			tmp1->next->nodes = tmpnl;
			tmp1->next->curr = tmpcurr;
			tmp1->next->new_nodes = tmpnew_nodes;
			tmp1 = paths->start;
		}
		else
			tmp1 = tmp1->next;
	}
}

t_pathlist	*new_paths(t_lemin *l, t_nodelist *nl, t_path *path)
{
	int					i;
	int					new_childs;
	t_path			*new_paths;

	i = 0;
	has_new_childs = 0;
	while (i < l->m.nbcases)
	{
		if (i && l->map.graph[p->curr][i] && !check_nodelist(nl, i))
		{
			add_path(path, new_path(path), new_node(i));
			add_node(nl, new_node(i));
			new_childs++;
		}
	}
	return (new_path);
}

void new_path_list(t_lemin *l, t_nodelist *nl, t_pathlist *paths)
{
	t_path *tmp;
	t_path *new_paths;
	tmp = paths->start;
	while (tmp)
	{
		if (new_paths = add_new_paths(l, nl, tmp))
		{

		}
		else
			tmp = tmp->next;
	}
}
int	update_paths(t_lemin *l, t_nodelist *nl, t_pathlist *paths)
{
	t_path *tmp;

	tmp = paths->start;
	while (tmp)
	{
		count_new_childs(l, nl, tmp);
		tmp = tmp->next;
	}
	sort_paths(l, nl, paths);
	tmp = paths->start;
	while (tmp->next)
	{

	}
}

void findpathlist(t_lemin *l, t_nodelist *nl, t_pathlist *paths)
{
	t_path *path;

	if (!paths->start)
	{
		path = new_path(NULL);
		add_path(paths->start, path);
	}
	else
	{
		if (update_paths(l, nl, paths->start))
			return ;
	}
	findpathlist(l, nl, paths);
}

int	path(t_lemin *l)
{
		t_nodelist	nl;
		t_pathlist	paths;

		findpathlist(l, &nl, &paths);
}
