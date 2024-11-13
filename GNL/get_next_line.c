/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:26 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/12 17:37:52 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


char *get_next_line(int fd)
{
	char 		*buffer;
	char		**stack;
	static int	stack_position;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	stack = get_string_array(buffer, fd, stack);
	if (!stack)
		return (NULL);
	// while (stack[stack_position])
	// {
	// 	stack_position++;
	// 	printf("%s\n", stack[stack_position]);
	// }
	if (stack_position == 0)
	{
		stack_position++;
		return (stack[0]);
	}
	return (stack[stack_position]);
}

char **get_string_array(char *buffer, int fd, char **stack)
{
	int stack_position_i;
	int bytes_read;
	char *line;
	int line_size;

	stack = malloc(get_n_times(fd) * sizeof(char *));
	if (!stack)
		return (NULL);
	stack_position_i = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line_size = get_substring_size(fd);
		line = malloc(line_size * sizeof(char));
		if (!line)
			return (NULL);
		if (*buffer == '\n')
		{
			ft_memmove(stack[stack_position_i], line, line_size + 1);
			stack_position_i++;
			free(line);
		}
	}
	return (stack);
}

int get_n_times(int fd)
{
	char	*temp_buf;
	int		size;
	int		i;
	int		bytes_read;

	temp_buf = malloc(BUFFER_SIZE);
	size = 0;
	i = 0;
	while ((bytes_read = read(fd, temp_buf, BUFFER_SIZE)) > 0)
			if (*temp_buf == '\n')
				i++;
	return (i);
}
int get_substring_size(int fd)
{
	char	*temp_buffer;
	int		size;
	int		bytes_read;

	temp_buffer = malloc(BUFFER_SIZE);
	size = 0;
	while ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
	{
		if (*temp_buffer == '\n')
			break ;
		size++;
	}
	return (size);
}

// char *get_next_line(int fd)
// {
// 	static char *buffer;
// 	static int buffer_position;
// 	static int bytes_in_buffer;
// 	char *line;
// 	char *temp_line;
// 	int line_size = 0;

// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
// 		return (NULL);
// 	if (!buffer)
// 	{
// 		buffer = malloc(BUFFER_SIZE);
// 		if (!buffer)
// 			return (NULL);
// 	}
// 	while (1)
// 	{
// 		if (buffer_position >= bytes_in_buffer)
// 		{
// 			buffer_position = 0;
// 			bytes_in_buffer = read(fd, buffer, BUFFER_SIZE);
// 			if (bytes_in_buffer <= 0)
// 			{
// 				free(buffer);
// 				buffer = NULL;
// 				if (line_size > 0)
// 					return (line);
// 				else
// 					return (NULL);
// 			}
// 		}
// 		temp_line = malloc(line_size + 2);
// 		if (!temp_line)
// 		{
// 			free(line);
// 			return (NULL);
// 		}
// 		if (line)
// 		{
// 			ft_strlcpy(temp_line, line, line_size + 1);
// 			free(line);
// 		}
// 		line = temp_line;
// 		line[line_size] = buffer[buffer_position];
// 		line[line_size + 1] = '\0';
// 		if (buffer[buffer_position] == '\n')
// 		{
// 			buffer_position++;
// 			return (line);
// 		}
// 		buffer_position++;
// 		line_size++;
// 	}
// }



int main(void) {
	int fd;
	char *line;

	fd = open("teste.txt", O_RDONLY);
	if (fd == -1) {
		perror("Erro ao abrir arquivo");
		return 1;
	}

	line = get_next_line(fd);
	printf("Linha 1: %s\n", line ? line : "(null)");
	free(line);

	line = get_next_line(fd);
	printf("Linha 2: %s\n", line ? line : "(null)");
	free(line);

	line = get_next_line(fd);
	printf("Linha 3: %s\n", line ? line : "(null)");
	free(line);

	line = get_next_line(fd);
	printf("Linha 4: %s\n", line ? line : "(null)");
	free(line);

	line = get_next_line(fd);
	printf("Linha 5: %s\n", line ? line : "(null)");
	free(line);

	line = get_next_line(fd);
	printf("Linha 6: %s\n", line);
	free(line);

	close(fd);
	return 0;
}

//     static char    *buffer;
//     static int     bytes_read;
//     static int     buffer_position;
//     char           *line;
//     int            length;

//     // Inicializa a linha como NULL e o comprimento como 0
//     line = NULL;
//     length = 0;

//     // Aloca o buffer estático para leitura
//     if (!buffer)
//         buffer = malloc(BUFFER_SIZE);

//     if (buffer == NULL)
//         return (NULL); // Retorna NULL se não puder alocar memória para o buffer

//     while (1)
//     {
//         // Se o buffer foi lido completamente, recarrega os dados
//         if (buffer_position >= bytes_read)
//         {
//             bytes_read = read(fd, buffer, BUFFER_SIZE);
//             if (bytes_read <= 0)
//             {
//                 if (length == 0)  // Se nada foi lido e comprimento é 0, fim do arquivo
//                     return (NULL);
//                 line[length] = '\0';  // Adiciona o final da string
//                 break ;
//             }
//             buffer_position = 0;  // Reinicia a posição no buffer
//         }

//         // Pega o caractere atual
//         char c = buffer[buffer_position++];

//         // Se encontrou uma nova linha, termina a leitura da linha
//         if (c == '\n')
//         {
//             line[length] = '\0';  // Finaliza a linha
//             break ;
//         }

//         // Se necessário, aloca mais memória para a linha
//         if (length == 0) // Inicializa a linha na primeira vez
//         {
//             line = malloc(sizeof(char) * (length + 2)); // Aloca 2 bytes (1 para o caractere e 1 para o terminador '\0')
//             if (!line)
//                 return (NULL); // Se não conseguir alocar memória, retorna NULL
//         }
//         else // Quando precisar aumentar a linha, aloca mais memória
//         {
//             char *temp_line = malloc(sizeof(char) * (length + 2)); // +1 para o caractere e +1 para '\0'
//             if (!temp_line)
//                 return (NULL); // Se falhar na alocação, retorna NULL

//             // Copia os dados da linha para o novo espaço alocado
//             for (int i = 0; i < length; i++)
//                 temp_line[i] = line[i];
//             free(line); // Libera o espaço antigo de linha
//             line = temp_line; // Atualiza o ponteiro de linha
//         }

//         line[length++] = c;  // Adiciona o caractere à linha
//     }

//     return (line);  // Retorna a linha lida
// }
