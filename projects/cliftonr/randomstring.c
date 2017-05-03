//
//  randomstring.c
//  
//
//  Created by Robert Clifton on 5/2/17.
//
//  To compile:
//  gcc -o testme testme.c -Wall -fpic -coverage -lm
//
The two functions char and string use arrays containing the characters needed to cause the function to throw an error. This causes a limited but random variables to be generated for the program.  On each pass of the while loop a new random char and string variables are generated, and then they are then tested against the error causing if statements.  The nature of the “while” loop in testme() function, only breaking on error help with this testing,  allows for good coverage and a nearly unlimited number of tries to generate the needed error causing values.
This program, while being a random test, is able to produce an error relatively quick and reliably.

File 'testme.c'
Lines executed:97.14% of 35
testme.c:creating 'testme.c.gcov'

-:    0:Source:testme.c
-:    0:Graph:testme.gcno
-:    0:Data:testme.gcda
-:    0:Runs:4
-:    0:Programs:1
-:    1:#include<stdio.h>
-:    2:#include<string.h>
-:    3:#include<stdlib.h>
-:    4:#include<time.h>
-:    5:
-:    6:char inputChar()
-:    7:{
    -:    8:    const char array[] = "[({ ax})]";
    52652:    9:    char out = array[(rand() % (sizeof(array)-1))];
    26326:   10:    return out;
    -:   11:}
-:   12:
-:   13:char *inputString()
-:   14:{
    52652:   15:    char array[6] = {'r','e','s','e','t','\0'};
    26326:   16:    int size = 6;
    -:   17:    int i;
    -:   18:    char * out;
    26326:   19:    out =  malloc(sizeof(char) * (size +1));
    368564:   20:    for (i = 0; i < size; i++) {
        157956:   21:        out[i] = array[(rand() %  (size))];
        157956:   22:    }
    -:   23:
    26326:   24:    return out;
    -:   25:}
-:   26:
-:   27:void testme()
-:   28:{
    8:   29:  int tcCount = 0;
    -:   30:  char *s;
    -:   31:  char c;
    4:   32:  int state = 0;
    26326:   33:  while (1)
        -:   34:  {
            26326:   35:    tcCount++;
            26326:   36:    c = inputChar();
            26326:   37:    s = inputString();
            26326:   38:    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
            -:   39:
            29242:   40:    if (c == '[' && state == 0) state = 1;
            29215:   41:    if (c == '(' && state == 1) state = 2;
            29241:   42:    if (c == '{' && state == 2) state = 3;
            29308:   43:    if (c == ' '&& state == 3) state = 4;
            29289:   44:    if (c == 'a' && state == 4) state = 5;
            29319:   45:    if (c == 'x' && state == 5) state = 6;
            29226:   46:    if (c == '}' && state == 6) state = 7;
            29311:   47:    if (c == ')' && state == 7) state = 8;
            29145:   48:    if (c == ']' && state == 8) state = 9;
            30683:   49:    if (s[0] == 'r' && s[1] == 'e'
                                5993:   50:       && s[2] == 's' && s[3] == 'e'
                                324:   51:       && s[4] == 't' && s[5] == '\0'
                                19:   52:       && state == 9)
                -:   53:    {
                    4:   54:      printf("error ");
                    4:   55:      exit(200);
                    -:   56:    }
            -:   57:  }
#####:   58:}
    -:   59:
    -:   60:
    -:   61:int main(int argc, char *argv[])
    -:   62:{
        -:   63:
        4:   64:    srand(time(NULL));
        4:   65:    testme();
        4:   66:    return 0;
        -:   67:}
