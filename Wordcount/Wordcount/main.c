//
//  main.c
//  Wordcount
//
//  Created by David Fritz on 21.11.17.
//  Copyright © 2017 David Fritz. All rights reserved.
//

#include <stdio.h>




// Ueberspringe alle Leerzeichen
// Rueckgabe ist Zeiger auf das erste Nichtleerzeichen
char* leerzeichen(char* line) {
    
    while(*line == ' '){
        line++;
    
    }
    return line;
}

// Scanne durch string solange bis wir auf ein
// Leerzeichen oder das Ende des Strings treffen.
// Effektiv ueberspringen wir ein Wort.
// Rueckgabe: Zeiger auf Ende oder Leerzeichen.
char* zeichen(char* line) {
    while(*line != '\0' && *line != ' ')
        line++;
    return line;
}


// Solange das Ende nicht erreicht ist:
// 1. Ueberspringe alle Leerzeichen
// 2. Falls Zeichen gefunden
//     (a) setze Zaehler hoch
//     (b) Gehe zu Wortende
int count(char* line) {
    int cnt = 0;
   
    while(*line != '\0') {
        line = leerzeichen(line);
        if(*line != '\0') {
            cnt++;
            line = zeichen(line);
        }

    }
    
    return cnt;
}



int breakIntoWords(char *line, int maxWords, char *words[]){
   char *p = line;
    int numberWords = 0;
    
    while(1){
  
        while(*p == ' '){
            p++;
        }
            
        if(*p == '\0'){
            return numberWords;
        }
            words[numberWords]= p;
            numberWords++;
            
            
    
        
        while((*p != ' ') && (p != '\0')){
            p++;
        
        
            if(*p == '\0'){
            return numberWords;
        
       
        }
            else if (*p== ' '){
                *p='\0';
                p++;
                break;
            }

        }
        if(numberWords >= maxWords){
        return numberWords;
    }
    }
}




int main(int argc, const char * argv[]) {
    
    int wordCounter = 0;
    int maxWords = 5;
    char *words[maxWords];
    char line[] = "Dies ist Test Nr. 1";
    wordCounter = breakIntoWords(line, maxWords, words);
printf(" %s\n", "Standardtest:");
    for (int i = 0; i < wordCounter; i++) {
        printf("%i: %s\n",i, words[i] );
    }
 printf("%s\n", "-----------------" );
    
    
    
    
    int wordCounter2 = 0;
    int maxWords2 = 2;
    char *words2[maxWords];
    char line2[] = "Dies ist Test Nr. 2";
    wordCounter2 = breakIntoWords(line2, maxWords2, words2);
     printf(" %s\n","Mehr wörter als Grenze: ");
    for (int i = 0; i < wordCounter2; i++) {
        printf("%i: %s\n", i,words2[i] );
    }
     printf("%s\n", "-----------------" );
    
    int wordCounter3 = 0;
    int maxWords3 = 2;
    char *words3[maxWords];
    char line3[] = "";
    wordCounter3 = breakIntoWords(line3, maxWords3, words3);
        printf(" %s\n", "Leerer Test:" );
    for (int i = 0; i < wordCounter3; i++) {
        printf("%i: %s\n",i, words3[i] );
    }
      printf("%s\n", "-----------------" );
    
    int wordCounter4 = 0;
    int maxWords4 = 3;
    char *words4[maxWords];
    char line4[] = "    Leerzeichen vorne";
    wordCounter4 = breakIntoWords(line4, maxWords4, words4);
    printf(" %s\n", "Leerzeichen vorne: " );
    for (int i = 0; i < wordCounter4; i++) {
        printf("%i: %s\n", i,words4[i] );
    }
    printf("%s\n", "-----------------" );
    
    
    return 0;
}
