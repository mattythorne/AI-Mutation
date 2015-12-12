#ifndef PHRASES_H
#define PHRASES_H

#include <string>
#include "characters.h"

/* Phrase handling class
 *
 * Generate a random phrase of X characters
 * Mutate a phrase by one character at random
 * Score a phrase
 */

using namespace std;

class phrases
{
public:
    
    string  generateRandom(int aLength);
    string  getPhrase();
    string  setPhrase(string aPhrase);
    int     mutate();
    int     score(string compare);
protected:
private:
    string phrase;
};

string phrases::setPhrase(string aPhrase)
{
    phrase = aPhrase;
    return phrase;
}

string phrases::getPhrase()
{
    return phrase;
}

/* Generate a random phrase of X characters */
string phrases::generateRandom(int aLength)
{
    phrase = "";
    characters myChars;
    for (int i=0;i<aLength;i++)
    {
        phrase.push_back(myChars.getRandomLetter());
    }
    return phrase;
}

/* Make a random character mutation at one position in the string */
int phrases::mutate()
{
    characters myChars;
    int mutationPosition = rand() % (phrase.length()-1);
    string randomLetter;
    randomLetter.push_back(myChars.getRandomLetter());
    phrase.replace(mutationPosition, 1, randomLetter);
    return mutationPosition;
}

/* Score a phrase against a target phrase
 * Each character is scored as follows...
 * 0 = character is correct and in correct position
 * n = character is correct but n places away from where it should be
 * length of phrase = character is not in phrase
 * All character scores are summed to provide an overall score for the phrase.
 */
int phrases::score(string compare)
{
    int score = 0;
    
    
    for(int i = 0; i < compare.length(); i++)
    {
        if (compare[i] == phrase[i])
        {
            score=score + 0;
        } else {
            for(int n =0; n < phrase.length(); n++)
            {
                if (compare[i]==phrase[n])
                {
                    if(i<n) score = score + (n-i);
                    if(i>n) score = score + (i-n);
                    //score = score + (n+1);
                    break;
                }
                if ((n+1) == phrase.length()) score=score + (unsigned int) phrase.length();
            }
        }
    }
    
    return score;
}
#endif // CHARACTERS_H
