/*
    test cl5642BH mounted on test board
    
*/


#define DIGIT0 10
#define DIGIT1 11
#define DIGIT2 12
#define DIGIT3 13

#define SEGMENTA 2
#define SEGMENTB 3
#define SEGMENTC 4
#define SEGMENTD 5
#define SEGMENTE 6
#define SEGMENTF 7
#define SEGMENTG 8

#define SEGMENTX 9

int segments[] = {SEGMENTA, SEGMENTB, SEGMENTC, SEGMENTD, SEGMENTE, SEGMENTF, SEGMENTG };
int digits[] = {DIGIT0, DIGIT1, DIGIT2, DIGIT3 };
char sigils[] = 
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'b', 'C', 'd', 'E', 'F', ' '};
int sigilcodes[] = 
    {63,6,91,79,102,109,125,7,127,111,119,124,57,94,121,113,0};

int last_sigil = 17;

void setup() {
  // put your setup code here, to run once:
    pinMode(DIGIT0, OUTPUT);
    pinMode(DIGIT1, OUTPUT);
    pinMode(DIGIT2, OUTPUT);
    pinMode(DIGIT3, OUTPUT);

    pinMode(SEGMENTA, OUTPUT);
    pinMode(SEGMENTB, OUTPUT);
    pinMode(SEGMENTC, OUTPUT);
    pinMode(SEGMENTD, OUTPUT);
    pinMode(SEGMENTE, OUTPUT);
    pinMode(SEGMENTF, OUTPUT);
    pinMode(SEGMENTG, OUTPUT);
    pinMode(SEGMENTX, OUTPUT);

    digitalWrite(SEGMENTA, HIGH);
    digitalWrite(SEGMENTB, HIGH);
    digitalWrite(SEGMENTC, HIGH);
    digitalWrite(SEGMENTD, HIGH);
    digitalWrite(SEGMENTE, HIGH);
    digitalWrite(SEGMENTF, HIGH);
    digitalWrite(SEGMENTG, HIGH);
    digitalWrite(SEGMENTX, HIGH);

    digitalWrite(DIGIT0, HIGH);
    digitalWrite(DIGIT1, HIGH);
    digitalWrite(DIGIT2, HIGH);
    digitalWrite(DIGIT3, HIGH);

}

void loop() {
    int test_nr = 1234;
//    for(int digit = 0;  digit < 4; digit++) {
        light_digit(-1);
        set_sigil((test_nr/1000) %10);
        light_digit(0);
        light_digit(-1);
        set_sigil((test_nr/100) %10);
        light_digit(1);
        light_digit(-1);
        set_sigil((test_nr/10) %10);
        light_digit(2);
        light_digit(-1);
        set_sigil((test_nr/1) %10);
        light_digit(3);


/*        
        for (int sigil_nr = 0; sigil_nr < last_sigil; sigil_nr++) {
            set_sigil(sigil_nr);
            delay(500);
        }
*/
//    }
}

void set_sigil(int sigil) {
    int sigilcode = sigilcodes[sigil];
    for(int i=0; i<8; i++) {
        if(sigilcode & 1<<i) {
            digitalWrite(segments[i], LOW);
        } else {
            digitalWrite(segments[i], HIGH);
        }
    }
}

void light_digit(int digit) {
    for(int curdigit = 0;  curdigit < 4; curdigit++) {
        if(curdigit == digit) {
            digitalWrite(digits[curdigit], HIGH);
        } else {
            digitalWrite(digits[curdigit], LOW);
        }
    }
}