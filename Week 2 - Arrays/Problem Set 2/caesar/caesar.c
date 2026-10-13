#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipo da função que verifica se a string contém apenas dígitos
bool only_digits(string s);

int main(int argc, string argv[])
{
    // 1. Verifica se o programa recebeu exatamente 1 argumento adicional (a chave)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Verifica se a chave contém apenas números
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 3. Converte a string da chave para um número inteiro
    int key = atoi(argv[1]);

    // 4. Solicita o texto puro (plaintext) ao usuário
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // 5. Percorre cada caractere do texto original
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Se for uma letra maiúscula
        if (isupper(c))
        {
            // Substitui usando a base ASCII de 'A' (65)
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        // Se for uma letra minúscula
        else if (islower(c))
        {
            // Substitui usando a base ASCII de 'a' (97)
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        // Se não for uma letra (espaço, pontuação, etc.), imprime sem alterar
        else
        {
            printf("%c", c);
        }
    }

    // Imprime a quebra de linha obrigatória no final
    printf("\n");
    return 0;
}

// Função auxiliar para validar se a string informada é puramente numérica
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
