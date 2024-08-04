/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:07:46 by emgul             #+#    #+#             */
/*   Updated: 2024/08/04 08:12:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H


// ERROR
# define ERR_ARG_COUNT "Usage: ./philo 5 800 200 200 7"

# define ERR_NOFILE "The file was not found."

# define ERR_FILEEXT "File extension must be: [.fdf::FILE]"
# define ERR_NAMELEN "File name must be at least 4 characters long."

# define ERR_FLAG "Invalid flag. For help, use -H flag."
# define ERR_MALLOC "Memory allocation failed."
# define ERR_OPEN "Unable to open map file."
# define ERR_MAP_SIZE "The map can only be square."
# define ERR_MAP_DIMENSION "Map dimensions are invalid."
# define ERR_COORD "Coordinates out of bounds."
# define ERR_LINE "Line is missing. Please check the map file."
# define ERR_INIT_MLX "Failed to initialize MiniLibX."
# define ERR_INIT_MLX_WIN "Failed to initialize MiniLibX window."
# define ERR_INIT_MLX_IMG "Failed to initialize MiniLibX image."
# define ERR_WIN_SIZE "Minimum window size is 1080x720."

// MESSAGE
# define MSG_EXIT "Program exited successfully."

#endif
