/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:56 by jonatha          #+#    #+#             */
/*   Updated: 2025/01/18 03:24:58 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static size_t	ulong_arr_len(unsigned long *arr)
{
	size_t	i;

	if (!arr)
		return (0); // Retorna 0 se o array for nulo

	i = 0;
	while (arr[i])
		i++;
	return (i); // Retorna o tamanho do array
}

static unsigned long	get_point(char *point)
{
	unsigned long	ret;
	unsigned int	color;
	char			**point_attrs;
	int				z;

	if (!point)
		return (ULONG_MAX); // Retorna ULONG_MAX para entrada inválida

	point_attrs = ft_split(point, ','); // Divide o ponto em atributos (z e cor)
	if (!point_attrs)
		return (ULONG_MAX);

	z = ft_atoi(point_attrs[0]); // Converte a coordenada z
	if (*(point_attrs + 1))
		color = atoi_hex(*(point_attrs + 1));
	else
		color = LINE_COLOR; // Usa a cor padrão se não houver cor
	
	ret = (((unsigned long)z) << 32) | color; // Combina z e cor em um único unsigned long

	free_str_arr(point_attrs); // Libera os atributos alocados
	return (ret);
}




static unsigned long	*get_map_row(char *map_row)
{
	unsigned long	*row;
	char			**str_row;
	size_t			row_len;
	size_t			i;

	if (!map_row)
		return (NULL); // Verifica se a entrada é nula

	str_row = ft_split(map_row, ' '); // Divide a linha em elementos
	if (!str_row)
		return (NULL);

	row_len = ulong_arr_len((unsigned long *)str_row); // Calcula o tamanho da linha
	row = malloc(sizeof(unsigned long) * (row_len + 1));
	if (!row)
	{
		free_str_arr(str_row); // Libera a memória em caso de erro
		return (NULL);
	}

	i = 0;
	while (str_row[i])
	{
		row[i] = get_point(str_row[i]); // Converte cada elemento para unsigned long
		i++;
	}
	row[row_len] = ULONG_MAX; // Marca o final do array
	free_str_arr(str_row); // Libera a memória alocada para str_row
	return (row);
}


unsigned long	**split_raw_map(char *raw_map)
{
	unsigned long	**map;
	char			**str_map;
	size_t			col_size;
	size_t			i;

	if (!raw_map)
		return (NULL); // Verifica se a entrada é válida

	str_map = ft_split(raw_map, '\n'); // Divide o mapa em linhas
	if (!str_map)
		return (NULL);

	col_size = ulong_arr_len((unsigned long *)str_map); // Calcula o número de colunas
	map = malloc((col_size + 1) * sizeof(unsigned long *));
	if (!map)
	{
		free_str_arr(str_map); // Libera memória em caso de erro
		return (NULL);
	}

	i = 0;
	while (i < col_size)
	{
		map[i] = get_map_row(str_map[i]); // Converte cada linha para um array de unsigned long
		if (!map[i]) // Verifica falhas ao processar uma linha
		{
			while (i > 0)
				free(map[--i]); // Libera as linhas já processadas
			free(map);
			free_str_arr(str_map);
			return (NULL);
		}
		i++;
	}
	map[col_size] = NULL; // Marca o final do array
	free_str_arr(str_map); // Libera a memória de str_map
	return (map);
}

