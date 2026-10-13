#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Matriz com os pontos de cada letra de A a Z
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicita a palavra de cada jogador
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");

    // Calcula a pontuação de cada um
    int score_one = compute_score(player_one);
    int score_two = compute_score(player_two);

    // Compara as pontuações e exibe o resultado
    if (score_one > score_two)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_two > score_one)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Função para calcular os pontos de uma palavra
int compute_score(string word)
{
    int score = 0;

    // Percorre cada caractere até o final da string ('\0')
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Se for uma letra maiúscula
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        // Se for uma letra minúscula
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
        // Sinais de pontuação e números somam 0 automaticamente
    }

    return score;
}
