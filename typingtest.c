#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

char* text = "Brazil is a large country and it is rich in natural resources. People in Brazil are friendly and like to help. There are beautiful places to visit and good restaurants. The Brazilian food is one of the best in the world, especially the barbecue. Brazil has problems like any other country: violence, poverty, corruption, and so on. Brazilians are known for their determination and don't give up too easily. When things are tough they usually say: I'm Brazilian and I will never give up. Soccer is part of the culture and almost everyone loves it. Watching a soccer game is like going to a party.";
int currentChar = 0;

double calcPPM(clock_t start, clock_t end, int correctWords) {
    double cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    double minutes = cpuTimeUsed / 60.0;
    double ppm = (correctWords / minutes);
    return ppm;
}

int main() {
    char key;
    clock_t start, end;
    int correctWords = 0;

    printf("%s\n\n", text);
    start = clock();

    while (currentChar < strlen(text)) {
        key = getch();
        if (text[currentChar] == key) {
            printf("%c", text[currentChar]);
            currentChar++;
        }
        if (key == '\r') {
            break;
        }

        if (key == ' ') {

            if (strncmp(&text[currentChar - strlen(" ")], &text[currentChar - strlen(" ")], strlen(" ")) == 0) {
                correctWords++;
            }
        }

        end = clock();
        double ppm = calcPPM(start, end, correctWords);

        char title[100];
        sprintf(title, "title Teste de Digitacao - PPM: %.2f", ppm);

        system(title);

    }

    end = clock();
    double ppm = calcPPM(start, end, correctWords);

    printf("\nPalavras por minuto: %.2f PPM\n", ppm);
    system("PAUSE");
    return 0;
}
