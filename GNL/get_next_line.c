/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:26 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/05 17:01:25 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// Função para encontrar a posição de '\n' no buffer
static char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return (NULL);
}

// Função para concatenar strings (alocando nova memória)
static char *ft_strjoin(char *s1, const char *s2) {
    size_t len1 = 0;
    size_t len2 = 0;
    char *result;

    while (s1 && s1[len1]) len1++;
    while (s2 && s2[len2]) len2++;

    result = malloc(len1 + len2 + 1);
    if (!result) return (NULL);

    for (size_t i = 0; i < len1; i++) result[i] = s1[i];
    for (size_t i = 0; i < len2; i++) result[len1 + i] = s2[i];

    result[len1 + len2] = '\0';

    if (s1) free(s1);

    return result;
}

// Função principal para ler a próxima linha
char *get_next_line(int fd) {
    static char *buffer = NULL;
    char temp_buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    ssize_t bytes_read;
    char *newline_pos;

    if (fd == -1 || BUFFER_SIZE <= 0) return (NULL);

    // Se o buffer não está vazio, verifica se há uma linha pronta
    if (buffer && (newline_pos = ft_strchr(buffer, '\n'))) {
        *newline_pos = '\0';  // Termina a linha aqui
        line = ft_strdup(buffer);  // Aloca e copia a linha
        char *temp = ft_strdup(newline_pos + 1);  // Copia o restante após '\n'
        free(buffer);
        buffer = temp;
        return (line);
    }

    // Continuar lendo o arquivo até encontrar uma linha completa ou EOF
    while ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0) {
        temp_buffer[bytes_read] = '\0';  // Garante que a string esteja terminada
        buffer = ft_strjoin(buffer, temp_buffer);

        // Verificar se encontramos a nova linha
        if ((newline_pos = ft_strchr(buffer, '\n'))) {
            *newline_pos = '\0';  // Termina a linha aqui
            line = ft_strdup(buffer);  // Aloca e copia a linha
            char *temp = ft_strdup(newline_pos + 1);  // Copia o restante após '\n'
            free(buffer);
            buffer = temp;
            return (line);
        }
    }

    // Se não há mais dados e buffer não está vazio, retornar o que resta
    if (bytes_read == 0 && buffer && *buffer) {
        line = ft_strdup(buffer);
        free(buffer);
        buffer = NULL;
    }

    return (line);
}

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
