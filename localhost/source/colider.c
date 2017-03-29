/****************************************************************************
 * colider.c
 *
 * Computer Science 50
 * Final Project
 *
 * Randomly pairs words and writes them to a file. Also, checks for
 * valid words.
 ***************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// default dictionary
#define DICTIONARY "/home/jharvard/vhosts/localhost/bin/small.txt"
#define MAXSTRING 90

int main(int argc, char* argv[])
{
    //check for correct number of args
    if (argc != 4 && argc !=5)
    {
        printf("arg_error");
        return 0;
    }
    //process arguments
    
    // n number of collisions
    int n = atoi(&argv[1][0]);
    
    char seedbuffer[MAXSTRING +1];
    
    // parts of speech loaded
    char* v1 = &argv[2][0];
    char* v2 = &argv[3][0];
    //seed flag defaults to 1 or true
    int seed = 1;
    //make sure random calls are different for each run using a seed modifier
    int xs = 0;
    //If there is no seed set seed flag to 0
    if(isdigit(argv[4][0]))
    {
        seed = atoi(&argv[4][0]);
    }
    
    //otherwise there is a seed word or phrase so remove underscores
    else
    {
        char* text = argv[4];
        
        char c;
        int l = strlen(text);
        for(int i= 0; i < l; i++)
        {
            c = text[i];
            if(isalpha(c) || c == '\'')
            {
                seedbuffer[i] = c;
            }
            else
            {
                seedbuffer[i] = ' ';
            }
        }
        seedbuffer[l] = '\0';
    }
    
    // determine dictionary to use. Use passed in dictionary or else default dictionary.
    char* dictionary = (argc == 6) ? argv[5] : DICTIONARY;

    // load dictionary
    bool loaded = load(dictionary);
    // abort if dictionary not loaded
    if (!loaded)
    {
        printf("load_error");
        return 0;
    }
    
    
    
    //If there is no seed then pull 2 words from the dictionary
    if(seed == 0)
    {
        // pull 2 random words from dictionary and print them
        char* result1;
        char* result2;
        for( int i =0; i < n; i++)
        {
            result1 = randomword(v1, xs);
            xs++;
            result2 = randomword(v2, xs);
            xs++;
            printf("%s %s\n",result1, result2);
        }
    }
    //Otherwise there is a seed word or phrase (seed == string)
    else
    {  
        //Pull a random word from dictionary and pair it with seed and print them
        char* result1;
        for( int i =0; i < n; i++)
        {
            result1 = randomword(v1, xs);
            xs++;
            printf("%s %s\n",result1, seedbuffer);
        }
    }
    // unload dictionary
    
    bool unloaded = unload();
    

    // abort if dictionary not unloaded
    if (!unloaded)
    {
        printf("unload_error");
        return 0;
    }



    // that's all folks
    
    return 0;
}

