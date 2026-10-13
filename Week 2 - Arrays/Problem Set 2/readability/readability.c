#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Protótipos das funções
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // 1. Solicita o texto ao usuário:
    string text = get_string("Text: ");

    // 2. Conta os elementos
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // 3. Calcula L e S
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    // 4. Aplica a fórmula de Coleman-Liau e arredonda
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // 5. Exibe o resultado final de acordo com as regras
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Função para contar as letras:

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Função para contar as palavras:

int count_words(string text)
{
    int words = 1; // Começa em 1 porque a última palavra não tem espaço depois dela
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// Função para contar frases:

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
