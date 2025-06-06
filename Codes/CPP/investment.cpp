#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct InvestmentOption {
    string name;
    double rate;
    double futureValue = 0.0;
};

double calculateCompound(double principal, double rate, int years) {
    return principal * pow(1 + rate / 100.0, years);
}

// Future value of SIP using compound interest formula
double calculateSIP(double monthly, double rate, int years) {
    double r = rate / (12 * 100.0); // monthly rate
    int n = years * 12;
    return monthly * ((pow(1 + r, n) - 1) / r) * (1 + r);
}

vector<InvestmentOption> getOptionsByRisk(string riskLevel) {
    if (riskLevel == "low") {
        return {
            {"Fixed Deposit (Safe)", 6},
            {"Gold Investment (Stable)", 8}
        };
    } else if (riskLevel == "medium") {
        return {
            {"Mutual Funds (Balanced)", 10},
            {"Stock Market Index", 12}
        };
    } else if (riskLevel == "high") {
        return {
            {"Crypto Assets", 18},
            {"Aggressive Growth Stocks", 20}
        };
    } else {
        return {};
    }
}

int main() {
    double principal, monthlySIP;
    int years;
    string risk;

    cout << "===== Intelligent Investment Planner =====\n\n";

    // Input
    cout << "Enter lump-sum investment amount (₹): ";
    cin >> principal;

    cout << "Enter monthly SIP amount (₹): ";
    cin >> monthlySIP;

    cout << "Enter duration (in years): ";
    cin >> years;

    cout << "Enter risk appetite (Low / Medium / High): ";
    cin >> risk;

    // Convert to lowercase for consistency
    transform(risk.begin(), risk.end(), risk.begin(), ::tolower);

    // Get options based on risk level
    auto options = getOptionsByRisk(risk);
    if (options.empty()) {
        cout << "Invalid risk category entered.\n";
        return 1;
    }

    cout << "\nCalculating returns for " << risk << " risk investment options...\n\n";

    // Calculate returns
    for (auto& opt : options) {
        double lumpSumValue = calculateCompound(principal, opt.rate, years);
        double sipValue = calculateSIP(monthlySIP, opt.rate, years);
        opt.futureValue = lumpSumValue + sipValue;
    }

    // Sort and display
    sort(options.begin(), options.end(), [](InvestmentOption a, InvestmentOption b) {
        return a.futureValue > b.futureValue;
    });

    cout << fixed << setprecision(2);
    for (const auto& opt : options) {
        cout << opt.name << ": ₹" << opt.futureValue << " (@" << opt.rate << "% annual)\n";
    }

    cout << "\n>>> Suggested Investment Plan: " << options[0].name << " <<<\n";
    cout << "Estimated Final Value: ₹" << options[0].futureValue << " after " << years << " years.\n";

    return 0;
}
