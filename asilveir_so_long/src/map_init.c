/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:02:51 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/09 16:30:48 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

char	**read_map(char *argv)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 1024);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	*join_strings(char const *s1, char const *s2)
{
	char	*arr;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!arr)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		arr[len_s1] = s2[i];
		len_s1++;
		i++;
	}
	arr[len_s1] = '\0';
	return (arr);
}

char	**parse_map(char **map, int argc, char **argv)
{	
	char	*path;

	if (argc < 2)
	{
		write(1, "Error\nMap file name is missing!\n", 32);
		exit(EXIT_FAILURE);
	}
	check_if_map_file_is_ber(argv[1]);
	path = join_strings("./maps/", argv[1]);
	map = read_map(path);
	free(path);
	if (!map)
	{
		write(1, "Error\nFailure reading the map, file name is invalid!\n", 52);
		exit(EXIT_FAILURE);
	}
	execute_map_validations(map);
	return (map);
}

int	check_if_map_file_is_ber(char *argv)
{
	char	*file_type;
	char	*file_type_expected;
	int		i;
	int		string_length;
	int		j;

	j = 0;
	file_type_expected = ".ber";
	if (!argv || ft_strlen(argv) == 0)
		return (1);
	string_length = ft_strlen(argv);
	i = string_length - 4;
	file_type = ft_substr(argv, i, 4);
	if (!file_type)
	{
		free(file_type);
		return (1);
	}
	if (!ft_strnstr(file_type, file_type_expected, 4))
	{
		write(1, "Error!\nMap file is not \".ber\"", 29);
		exit(EXIT_FAILURE);
	}
	free(file_type);
	return (0);
}

void	execute_map_validations(char **map)
{
	check_if_map_is_rectangular(map);
	map_is_surrounded_by_walls(map);
	search_exit(map);
	search_collectible(map);
	search_player(map);
	search_forbidden_character(map);
	only_one_player(map);
	only_one_exit(map);
}
