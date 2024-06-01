#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calc_letters(string _text);
int calc_words(string _text);
int calc_sentences(string _text);

int main(void)
{
    // prompt user for text
    string text = get_string("Text: ");

    // number of letters
    int letters = calc_letters(text);

    // number of words
    int words = calc_words(text);

    // number of sentences
    int sentences = calc_sentences(text);

    // average number of letters
    float L = letters / (float) words * 100;

    // average number of sentences
    float S = sentences / (float) words * 100;

    // calculates Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // printing grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// function for number of letters
int calc_letters(string _text)
{
    int num_letters = 0;
    for (int i = 0, n = strlen(_text); i < n; i++)
    {
        if (isalpha(_text[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}

// function for number of words
int calc_words(string _text)
{
    int num_words = 0;
    for (int i = 0, n = strlen(_text); i < n; i++)
    {
        if (isblank(_text[i]))
        {
            num_words++;
        }
    }
    return num_words + 1;
}

// function for number of sentences
int calc_sentences(string _text)
{
    int num_sentences = 0;
    for (int i = 0, n = strlen(_text); i < n; i++)
    {
        if (_text[i] == '.' || _text[i] == '!' || _text[i] == '?')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}
