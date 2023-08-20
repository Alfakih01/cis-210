#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to calculate the year-end balance and earned interest for each year
void calculateYearlyBalance(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numYears) {
    double balance = initialInvestment;
    double earnedInterest;

    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int year = 1; year <= numYears; year++) {
        // Calculate the earned interest
        earnedInterest = balance * (annualInterestRate / 100.0);

        // Calculate the year-end balance
        balance += earnedInterest + (monthlyDeposit * 12);

        // Display the results for the current year
        cout << year << "\t$" << fixed << setprecision(2) << balance << "\t\t$" << earnedInterest << endl;
    }
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numYears;

    // Get user input
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest (%): ";
    cin >> annualInterestRate;

    cout << "Number of Years: ";
    cin >> numYears;

    // Calculate and display results without additional monthly deposits
    cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
    calculateYearlyBalance(initialInvestment, 0, annualInterestRate, numYears);

    // Calculate and display results with additional $50 monthly deposits
    cout << endl << "Balance and Interest With Additional $50 Monthly Deposits" << endl;
    calculateYearlyBalance(initialInvestment, 50, annualInterestRate, numYears);

    return 0;
}
