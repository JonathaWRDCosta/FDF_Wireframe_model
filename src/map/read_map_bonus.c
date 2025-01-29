/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:55 by jonatha          #+#    #+#             */
/*   Updated: 2025/01/29 00:53:23 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	read_file(int fd, char **map, char **buf)
{
	ssize_t	r_bytes;
	char	*temp;

	if (!map || !buf)
		return (-1);
	*map = NULL;
	r_bytes = 1;
	while (r_bytes > 0)
	{
		*buf = ft_calloc(1, BUFFER_SIZE + 1);
		if (!*buf)
		{
			free(*map);
			return (-1);
		}
		r_bytes = read(fd, *buf, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(*map);
			free(*buf);
			return (-1);
		}
		(*buf)[r_bytes] = '\0';
		temp = ft_strjoin(*map, *buf); // Cria uma nova string concatenada
		*map = temp;                   // Atualiza o mapa
		if (!*map)
			return (-1); // Falha ao concatenar
	}
	return (0);
}

char	*get_raw_map(char *filename)
{
	char	*buf;
	char	*map;
	int		fd;

	if (!filename)
		return (NULL); // Verifica se o nome do arquivo é válido
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL); // Retorna NULL se não conseguir abrir o arquivo
	if (read_file(fd, &map, &buf) == -1)
	{
		close(fd); // Fecha o descritor em caso de erro
		return (NULL);
	}
	close(fd);    // Fecha o descritor de arquivo após a leitura
	return (map); // Retorna o mapa completo
}
