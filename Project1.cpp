/*
 * Project1.cpp
 * 
 * Name: Ima Student
 * EE312 Spring 2016
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
void Compare ( char dictionary [] );

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restrictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */

//simple test function to see if i could retrieve the first letter from the article passed to me
 void test (char article[]){
    int y = 0;
    int z = 0;
    z = article[y];
    printf("%c\n", z);
    //return ;

}//this function count the number of characters in the article string so that I can have the information to use in for loops
/*int TheArticleCount = 0;
int numberOfLettersInArticle(char article []){
    int count = 0;
    int index = 0;

    while(article[index] != '\0') {
        count++;
        index++;
    }
    TheArticleCount = count;
    return count;
}
int TheDictionaryCount = 0;
int numberOfLettersInDictionary(char dictionary []){
    int count = 0;
    int index = 0;

    while(dictionary[index] != '\0') {
        count++;
        index++;
    }
    TheDictionaryCount = count;
    return count;
}*/
/*
char** DictionaryArray;
void DictSeparate ( char dictionary[] ){
    int i = 0;
    int j = 0;
    int x = 0;
    int z = 0;
    for (x; x< TheDictionaryCount; x++){
        if(dictionary[x] != '\n'){
            DictionaryArray[i][j] = dictionary[x];
            j++;
        }
        else {
            i++;
            j = 0;
        }
    }
}

*/

char ConvertToLower (char article){
    if (article >= 'A' && article <= 'Z'){
        article += 0x20; // add hex 20 to convert the upper case charracters to lower case characters
    }
    return(article);// return to separate function with same character, but now in lower case
}

// this function is supposed to separate the article string into words and store them in a 2D array
char * i = 0;
int count = 0;
void separate ( char article[], char dictionary []){

    char * j= 0;
    int x = 0;
    int y = 0 ;

while ( article[x] != '\0') {
    count =0; //reset count
    if(( article [x] < 'A' || article [x] > 'Z' ) && (article [x] < 'a' || article[x] > 'z')){
        x++;
     }
    else if ((article[x] >= 'A' && article[x] <= 'Z') || (article[x] >= 'a' && article[x] <='z')){
        article[x] = ConvertToLower(article[x]);
        i = &article[x];
        x++;
        count ++;
        while ((article[x] >= 'A' && article[x] <= 'Z') || (article[x] >= 'a' && article[x] <='z')){
            article[x] = ConvertToLower(article[x]);// inside this while loop as the program traverses the article word it will check and convert upper case letters to lower case if needed.
            x++;
            count++;
        }
        if ( count > 1){
            Compare(dictionary);
            while ((article[x] >= 'A' && article[x] <= 'Z') || (article[x] >= 'a' && article[x] <='z')){
                x++; //after checking one word against the dictionary, return from above loop and move pointer to the next word n the article for examination
            }
        }

    }

  }
}


void Compare ( char dictionary [] ){
    int z =0; // dictionary index
    int y =0; // article index

    while( dictionary [z] != '\0'){ //iterate through the entire dictionary
        dictionary[z] = ConvertToLower(dictionary[z]);
        if (( y == count) && (dictionary[z] =='\n')){
            return;
        }
        if (i[y] == dictionary[z]){
            y++;
            z++;
        }
        else {
            while (dictionary [z] != '\n'){
                z++;
            }
            z++;
            y=0;
        }

    }

    for(y = 0; y < count; y++){
        printf("%c", i[y]);
    }
    printf("\n");
}







        /*for (y; y <= count; y++ ){
            dictionary[z] =ConvertToLower(dictionary[z]); // dont know if this will work becasue of how i decalare the parameters for the ConvertToLower function but i want to convert upper case letter to lower
            if (*i == dictionary [z]){ // this if statement loop only continues if the characters ccontinue to match
                i++;
                z++;
            }

                while ( dictionary[z] != '\n') {
                    z++;
                }
                i = address; // resets the article word pointer back to the first character
                z++;// increment z one last time so that when i go back to the top itll be point to the first lettter of the next dictionary word
                if (dictionary [z] == '\0'){
                    for(int index = 0; index < count; index++){
                        printf("%c", address[index]);
                    }
                    printf("\n");
                }
                //return(InTheLoop);// dont know if this will work but trying to return to the InTheLoop function within the compare function
            }



       }
        return; // return if the word matches with a word from the dictionary*/













void spellCheck(char article[], char dictionary[]) {
    separate(article, dictionary);
   // numberOfLettersInArticle(article);
   // printf( "%u\n",numberOfLettersInArticle(article));
   // separate(article);
    // test(article);
}
