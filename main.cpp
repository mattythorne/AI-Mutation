#include <algorithm>
#include <iostream>
#include <map>

#include "characters.h"
#include "phrases.h"

#define RANDOMISE srand( (unsigned int) time(NULL) );

/*    AI Mutation Algorythm - Infinite Monkeys
 *
 *    Premise : If you have an infinite number of monkeys with typewriters
 *              then given enough time one will write War and Peace.
 *              Can we significantly improve upon this randomness with
 *              a genetic mutation algorthm?
 *
 *    Experiment : 1. Start with 200 random strings of characters
 *                 2. Score each one on closeness of each character to actual character position in the target string
 *                 3. Let the bottom 150 scorers die
 *                 4. Repopulate the 200 phrases of the list by randomly mutating one character of each of the top 50
 *                 5. Rinse and repeat
 */

using namespace std;

string searchPhrase = "it was the best of times";

int main()
{
    RANDOMISE;
    
    map<int, string> phraseList;
    map<int, string>::iterator it;
    phrases myPhrases;
    string lastPhrase = "";
    
    //Generate a list of 200 random phrases and score them against the search phrase
    for(int n = 0; phraseList.size()<200; n++)
    {
        myPhrases.generateRandom((unsigned int) searchPhrase.length());
        phraseList.insert(pair<int, string> (myPhrases.score(searchPhrase), myPhrases.getPhrase() ));
    }
    int i=0;
    //print the top 50
    cout << "Initial List : " << endl;
    for ( it=phraseList.begin(); i<50; it++ )
    {
        i++;
        cout << (*it).first << " => " << (*it).second << endl;
    }
    
    
    for(int iter = 1; iter>0; iter++)
    {
        //Have we solved the phrase
        string closestMatch = phraseList.begin()->second;
        if(closestMatch!=lastPhrase)
            cout << "Iteration : " << iter << " Best Match : " << closestMatch << " Score : " << phraseList.begin()->first << endl;
        lastPhrase = closestMatch;
        if (closestMatch==searchPhrase) break;
        
        //Take the top 50 phrases
        for(int x=0; x<150; x++)
        {
            it=phraseList.end();
            it--;
            phraseList.erase(it);
        }
        
        
        //Generate a mutation for each of the top 50 and repopulate the list
        for(int n=0; phraseList.size()<200; n++)
        {
            for ( it=phraseList.begin() ; it != phraseList.end(); it++ )
            {
                myPhrases.setPhrase((*it).second);
                myPhrases.mutate();
                phraseList.insert(pair<int, string> (myPhrases.score(searchPhrase), myPhrases.getPhrase() ));
            }
        }
        
    }
    return 0;
}
