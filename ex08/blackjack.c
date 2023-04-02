#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int counthand(char *str)
{
    char *numbers = "23456789T";
    char *face_cards = "JDK";
    int total = 0;
    bool cardCounted;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        cardCounted = false;
        for (int k = 0; numbers[k] != '\0' && cardCounted == false; ++k)
        {
            if (str[i] == numbers[k])
            {
                total = total + k + 2; //BECAUSE ARRAY STARTS FROM 0
                cardCounted = true; 
            }
        }
        for (int k = 0; face_cards[k] != '\0' && cardCounted == false; ++k)
        {
            if (str[i] == face_cards[k])
            {
                total += 10; //All face_cards are worth 10 points
                cardCounted = true; 
            }
        }
        if (str[i] == 'A')
        {
            if (total + 11 > 21)
                ++total;
            else
                total += 11;
            cardCounted = true;
        }
        if (cardCounted == false)
            return (-1);
    }
    return (total);
}

int main(int argc, char **argv)
{
    int total;

    if (argc != 2)
		return (-1);
    total = counthand(argv[1]);
    if (total == -1)
        printf("Not a valid hand.\n");
    else if (total == 21)
        printf("Blackjack!\n");
    else
        printf("%d\n", total);
}