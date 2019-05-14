/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:32:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/05/10 15:43:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H


# define BAD_ALLOC "Error. Cannot allocate memory region."

# define BAD_FILE "Error. Bad access."

# define BAD_SKYBOX "Error. Cannot open skybox file."

# define BAD_VERTEX "Error. Invalid vertex."

# define BAD_VERTEX_VALIDATION "Error. Vertex validation error."

# define BAD_SECTOR_VALIDATION_BAD_VERTEX_PAIR "Error. Sector parse failed. No such vertex pair."

# define BAD_SECTOR_VALIDATION_NUM "Error. Sector validation error.Wrong parameters number."

# define BAD_SECTOR_VALIDATION_HEIGHT "Error. Sector validation error.Wrong height parameters."

# define BAD_VALIDATION_INT32_OVERLOAD "Error. Integer overloaded."

# define BAD_SECTOR_VALIDATION_VERTEX "Error. Sector validation error. Bad vertex parameters."

# define BAD_SECTOR_VALIDATION_TRANSIT "Error. Sector validation error. Bad transit parameters."

# define BAD_PLAYER_VALIDATION "Error. Player validation error. Bad coords."

# define BAD_PLAYER_VALIDATION_SECTOR_POS "Error. Player validation error. Undefined vector position."

#endif


