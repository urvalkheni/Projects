#include <stdio.h>

int main() {
    int year;
    printf("Computer History from 1822 to 2025:\n\n");

    for (year = 1822; year <= 2025; year++) {
        if (year == 1822)
            printf("%d: Charles Babbage proposes the Analytical Engine (first mechanical computer).\n", year);
        else if (year == 1936)
            printf("%d: Alan Turing introduces the concept of the Turing Machine.\n", year);
        else if (year == 1945)
            printf("%d: ENIAC completed – first general-purpose electronic digital computer.\n", year);
        else if (year == 1951)
            printf("%d: UNIVAC I – first commercial computer.\n", year);
        else if (year == 1971)
            printf("%d: Intel 4004 – First microprocessor released.\n", year);
        else if (year == 1983)
            printf("%d: Internet officially born (TCP/IP protocol standard).\n", year);
        else if (year == 1991)
            printf("%d: World Wide Web (WWW) launched by Tim Berners-Lee.\n", year);
        else if (year == 2007)
            printf("%d: First iPhone released, revolutionizing smartphones.\n", year);
        else if (year == 2015)
            printf("%d: AI and ML rise, Deep Learning grows rapidly.\n", year);
        else if (year == 2023)
            printf("%d: Generative AI tools like ChatGPT gain mainstream use.\n", year);
        else if (year == 2025)
            printf("%d: Future of Quantum Computing and AI expansion.\n", year);
    }

    return 0;
}