/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/08/26 22:02:10 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void check_rows()
{
    int i;
    size_t j;
    
    i = 0;
    // printf("%d\n", t_map.tmp_map[4][-12]);
    while (i < t_map.rows-2)
	{
        j = 1;
        if (t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 1] == '0' && t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 2] != '1' )
            ft_exit("Error: Open border!");
		while (j < ft_strlen(t_map.tmp_map[i]) - 2)
	    {
            if (t_map.tmp_map[i][j] == ' ')
                if (t_map.tmp_map[i][j + 1] == '0' || t_map.tmp_map[i][j - 1] == '0')
                    printf("Error: open border" );
            
            // printf("%zu", ft_strlen(t_map.tmp_map[i]));
          
            
            // if (t_map.tmp_map[i][j] == ' ')
            // {
            //     if (t_map.tmp_map[i][j+1] == '0' || t_map.tmp_map[i][j - 1] == '0')
            //         printf("Error: open border" );
                // if (t_map.tmp_map[i][j+1] == '0' || t_map.tmp_map[i][j - 1] == '0')
                // {
                //     printf("error [%d][%zu]- {%d}  [%d][%zu] - {%d}", i, j - 1,
                //                             t_map.tmp_map[i][j - 1], i, j + 1, t_map.tmp_map[i][j+1]  );
                // }
                
            //}
            
            // printf("%d", t_map.tmp_map[i][j]);
            j++;
		}
        // printf("\n");
        // while ((int)j < t_map.cols)
        //     t_map.matrix[i][j] = '-';
        // t_map.matrix[i][j] = '\0';
		i++;
    }



    
    // while (i < t_map.rows)
	// {
    //     j = 0;
	// 	while (j < ft_strlen(t_map.tmp_map[i]) - 1)
	//     {
    //         // if (t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i])] == '0')
    //         // {
    //         //     printf("\nError: Open border! %d %zu" ,i, j);
    //         //     break;
    //         // }
    //             // ft_exit("Error: Open border! %d %zu", i, j);
    //         // printf("%d", t_map.tmp_map[i][j]);

    //         if (t_map.tmp_map[i][j] == 32)
    //         {
    //              printf("[%d][%lu] %d\n", i, j + 1, t_map.tmp_map[i][j+1]);
    //              printf("[%d][%lu] %d\n", i, j + 1, t_map.tmp_map[i][j-1]);
                
                
    //             // if (t_map.tmp_map[i][j + 1] == 48 || t_map.tmp_map[i][j - 1] == 48)
    //             // {
    //             //     printf(" prev %c\n", t_map.tmp_map[i][j - 1]);
    //             //     printf(" aft %c", t_map.tmp_map[i][j + 1]);
    //             //     printf("\nError: Open border! %d %zu" ,i, j);
    //             //     break;
    //             // }
    //         }
    //                 // ft_exit("Error: Open border!");
    //         j++;
	// 	}
    //             printf("\n");
	// 	i++;
	// }
}