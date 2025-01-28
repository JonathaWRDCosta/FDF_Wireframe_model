/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:44 by jonatha          #+#    #+#             */
/*   Updated: 2025/01/18 03:25:00 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_row_size(unsigned long **map)
{
	int	row_size;

	row_size = 0;
	while (map[0][row_size] != ULONG_MAX)
		row_size++;
	return (row_size);
}

static int	get_col_size(unsigned long **map)
{
	int	col_size;

	col_size = 0;
	while (map[col_size])
		col_size++;
	return (col_size);
}

static void	init_map_props(t_vars *vars)
{
	if (!vars || !vars->map || !vars->map[0])
		return; // Verifica se os ponteiros são válidos

	vars->row_size = get_row_size(vars->map); // Calcula o tamanho da linha
	vars->anchor_x = vars->row_size / 2; // Define o ponto de ancoragem no eixo X

	vars->col_size = get_col_size(vars->map); // Calcula o tamanho da coluna
	vars->anchor_y = vars->col_size / 2; // Define o ponto de ancoragem no eixo Y
}


int	init_map(t_vars *vars, char *filename)
{
	char	*raw_map;

	if (!vars || !filename)
		return (-1); // Verifica entradas nulas

	raw_map = get_raw_map(filename); // Lê o mapa bruto do arquivo
	if (!raw_map)
		return (-1); // Retorna erro se não conseguir ler o arquivo

	vars->map = split_raw_map(raw_map); // Divide o mapa em linhas
	free(raw_map); // Libera o mapa bruto após usá-lo

	if (!vars->map)
		return (-1); // Retorna erro se não conseguir processar o mapa

	init_map_props(vars); // Inicializa as propriedades do mapa
	return (0); // Retorna sucesso
}

