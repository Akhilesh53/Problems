#include<bits/stdc++.h>
using namespace std;

/*
    In this problem, you are required to determine how many times a sentence can be fitted on a screen. 
    The screen has dimensions defined by rows and cols where rows represent the number of lines on the screen and 
    cols stand for the number of characters that can fit in a single line. 
    The sentence is represented as a list of strings where each string is a word from the sentence.
    
    A few rules need to be followed while placing the sentence on the screen:
    - Words must be put on the screen in the same order as they appear in the sentence.
    - No word should be split over two lines. If a word does not fit at the end of a line, it should be moved to the next line.
    - There must be a single space between two consecutive words on the same line.
    
    The aim is to count the total number of times the sentence can be repeated on the screen under these constraints.
*/


/*
   Approach: https://algo.monster/liteproblems/418
   1. First, we will create a single string from the list of words.
    2. We will keep track of the length of the sentence.
    3. We will iterate over the rows and keep adding the number of columns to the count.
    4. If the character at the count % sentenceLength is a space, we will increment the count.
    5. If the character at the count % sentenceLength is not a space, we will keep decrementing the count until we find a space.
    6. We will return the count divided by the sentence length.
*/

int countNum(vector<string>& words){
    int r = words.size();
    int c = words[0].size();

    string wordSentence = "";
    for (string w : words){
        wordSentence += w + " ";
    }

    int sentenceLength = wordSentence.size();
    int count = 0;
    while(r--){
        count += c;

        if(wordSentence[count % sentenceLength] == ' '){
            count++;
        } else {
            while(count > 0 && wordSentence[(count - 1) % sentenceLength] != ' '){
                count--;
            }
        }
    }
    return count / sentenceLength;
}