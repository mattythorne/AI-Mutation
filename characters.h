#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

/* Set up a list of valid letters (lowercase only + space)
 * Provide a method to retrieve a random letter from the list
 */

class characters
{
public:
    characters();
    char getElement(int element);
    char getRandomLetter();
protected:
private:
    char chars [27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
};

characters::characters()
{
    // chars = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
}

char characters::getElement(int element)
{
    return chars[element];
}

char characters::getRandomLetter()
{
    
    return chars[rand() % ARRAY_SIZE(chars)];
}

#endif // CHARACTERS_H