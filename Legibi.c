#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string("Input your text: ");

    int letters = 0, words = 0, sentences = 0;


    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(s[i] != ' ' && s[i] != '!' && s[i] != '?' && s[i] != '.')
        {
            letters ++;

        }

        if(s[i] == ' ' || s[i] == '!' || s[i] == '?' || s[i] == '.')
        {

            if(s[i-1] != ' ' && s[i-1] != '!' && s[i-1] != '?' && s[i-1] != '.')
            {
                words ++;
            }

        }

          if(s[i] == '!' || s[i] == '?' || s[i] == '.')
        {

            if(s[i-1] != ' ' && s[i-1] != '!' && s[i-1] != '?' && s[i-1] != '.')
            {
                sentences ++;
            }

        }

    }


    float L = ((float)letters/(float)words)*100;

    float S = ((float)sentences/(float)letters)*100;

    int X = 0.0588 * L - 0.296 * S - 15.8;

    printf("Grade%i\n ",  X);

}