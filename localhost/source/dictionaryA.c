check50/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "dictionary.h"

#define HASHSIZE 7


//Structure for Linked List Hash Table
typedef struct node
{
    char word[LENGTH +1];
    char p[2];
    struct node* next;
}
node;
// Hashtable
node* hashtable[HASHSIZE];
//Variable to hold Dicionary size
int Size = 0;
//Variable to hold index location
unsigned long hindex = 0;

//prototypes
//DJB2 hash functon. An algorithm produced by Professor Daniel J. Bernstein.
unsigned long Hash(const char *str);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //clean the input word and make it lowercase
    char Word[LENGTH+1];
    for (int i = 0; i < (strlen(word)+1); i++)
    {
        Word[i] = tolower(word[i]);   
    }
    
    //then see if it is in the table and thus dictionary
    for(node* cursor = hashtable[Hash(Word)]; cursor != NULL; cursor = cursor->next)
    {
        if (strcmp(Word, cursor->word)== 0)
        {
            return true;
        }
    }
    
    return false;
}
/**
 * Returns a single random word from dictionary.  Either a verb, noun or a word that can be both.
 */
char* randomword(const char* s, const int xs)
{
    //If we care about what type of word we want
    
    if(strcmp(s, "v") == 0|| strcmp(s,"n") == 0)
    { 
        
        //set up Variables for while loop and initialise so compiler doesn't complain
        int r1 = 0;
        int lsize = 0;
        int r2 = 0;
        node* cursor = hashtable[r1];
        
        // seed pseudorandom number generator
        srand(time(NULL)+ xs);
        
        //while we havent found a word from the right part of speech (parts of speech 'n' noun,'v' verb, or both 'b')
        while (true)
        {
            
            // pull a random number in range of hashtable
            r1 = rand()% HASHSIZE;
            //find the length of  the list at that place in the hashtable.
            lsize = 0;
            for(node* cursorl = hashtable[r1]; cursorl != NULL; cursorl = cursorl->next)
            {
                lsize ++;
            }
            //pull random word from that list
            r2 = rand()% lsize;
            cursor = hashtable[r1];
            for(int i = 0; i < r2; i++)
            {
                cursor = cursor->next;
                
            }
            //If it is the right part of speech we want, then we are done.
            if (strcmp(cursor->p, s) == 0|| strcmp(cursor->p, "b") == 0)
            {
                break;
            }
            //reset
            //r1 = 0;
            //r2 = 0;
        }
        return cursor->word;
    }
    
    //otherwise we don't care just return a random word
    else 
    {
            // seed pseudorandom number generator
            srand(time(NULL)+ xs);
            // pull a random number in range of hashtable
            int r1 = rand()% HASHSIZE;
            //find the length of  the list at that place in the hashtable.
            int lsize = 0;
            for(node* cursorl = hashtable[r1]; cursorl != NULL; cursorl = cursorl->next)
            {
                lsize ++;
            }
            //pull random word from that list
            int r2 = rand()% lsize;
            node* cursor = hashtable[r1];
            for(int i = 0; i < r2; i++)
            {
                cursor = cursor->next;
                
            }
        return cursor->word;
    }
    /*else
    {
        return "Error";
    }*/
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* fpD = fopen(dictionary, "r");
    if (fpD == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
   
    //load the hash table with NULL
    for(int i =0; i< HASHSIZE; i++)
    {
        hashtable[i] = NULL;
    }
    
    //Make Hashtable Linked Lists, load a word and run a loop
    while (!feof(fpD))
    {
        hindex = 0;
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fprintf(stderr, "out of memory.\n");
            return false;
        }
        //load word, p in node and check for EOF
        new_node->next = NULL;
        
        if (fscanf(fpD, "%s %c", new_node->word, new_node->p) == EOF)
        {
            free(new_node);
            break;
        }
        //printf("Word: %s Part: %s\n", new_node->word, new_node->p);
        
        hindex = Hash(new_node->word);
       
       
        //Prepend node at hashtable[index]
        if (hashtable[hindex] == NULL)
        {
            hashtable[hindex] = new_node;
            new_node->next = NULL;
        }
        else if (hashtable[hindex] != NULL)
        {
            new_node->next = hashtable[hindex];
            hashtable[hindex] = new_node;
        }
        Size++;
    }
        
    fclose(fpD);
    return true; 
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return Size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i= 0; i < HASHSIZE; i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            node* next = cursor->next;
            free(cursor);
            cursor = next;
        }
    } 
    return true;
}



unsigned long Hash(const char *str)
{
        unsigned long hash = 5381;
        int c;

        while ((c = *str++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash%HASHSIZE;
}


