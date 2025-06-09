 #include <iostream>
#include <map>

int main() {
    std::map<int, std::string> milestones = {
        {1822, "Charles Babbage proposes the Analytical Engine."},
        {1936, "Alan Turing introduces the concept of Turing Machine."},
        {1945, "ENIAC: First general-purpose electronic digital computer."},
        {1951, "UNIVAC I: First commercial computer."},
        {1971, "Intel 4004: First microprocessor."},
        {1983, "Internet born (TCP/IP protocol standard)."},
        {1991, "World Wide Web (WWW) by Tim Berners-Lee."},
        {2007, "iPhone released – mobile computing revolution."},
        {2015, "Deep learning and AI boom."},
        {2023, "ChatGPT and generative AI mainstream."},
        {2025, "Future tech: Quantum computing & AI expansion."}
    };

    std::cout << "Computer History from 1822 to 2025:\n\n";

    for (int year = 1822; year <= 2025; year++) {
        if (milestones.count(year))
            std::cout << year << ": " << milestones[year] << "\n";
    }

    return 0;
}