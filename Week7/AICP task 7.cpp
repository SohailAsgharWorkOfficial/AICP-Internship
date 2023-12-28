#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Charity {
    std::string name;
    double total;
};

void displayCharities(const std::vector<Charity>& charities) {
    std::cout << std::setw(25) << "Charity Number" << std::setw(25) << "Charity Name\n";
    for (size_t i = 0; i < charities.size(); ++i) {
        std::cout << std::setw(25) << i + 1 << std::setw(25) << charities[i].name << "\n";
    }
}

void displayTotals(const std::vector<Charity>& charities) {
    std::cout << "\nCharity Totals (Descending Order):\n";
    std::cout << std::setw(25) << "Charity Name" << std::setw(25) << "Total Donated\n";
    std::vector<Charity> sortedCharities = charities;
    std::sort(sortedCharities.begin(), sortedCharities.end(),
              [](const Charity& a, const Charity& b) { return a.total > b.total; });

    for (const auto& charity : sortedCharities) {
        std::cout << std::setw(25) << charity.name << std::setw(25) << "$" << charity.total << "\n";
    }
}

int main() {
    std::vector<Charity> charities = {{"Charity 1", 0.0}, {"Charity 2", 0.0}, {"Charity 3", 0.0}};
    double shoppingBill, donation;
    int choice;
    double grandTotal = 0.0;

    std::cout << "Welcome to the Charity Donation System!\n\n";

    for (auto& charity : charities) {
        std::cout << "Enter the name of " << charity.name << ": ";
        std::getline(std::cin, charity.name);
    }

    while (true) {
        std::cout << "\n";
        displayCharities(charities);

        std::cout << "\nEnter your choice (1, 2, 3) or -1 to show totals: ";
        std::cin >> choice;

        if (choice == -1) {
            std::cout << "\n";
            displayTotals(charities);

            grandTotal = charities[0].total + charities[1].total + charities[2].total;
            double donationFromTotal = 0.01 * grandTotal;

            std::cout << "\nGRAND TOTAL DONATED TO CHARITIES: $" << grandTotal << "\n";
            std::cout << "Your donation also contributes to the grand total. From the total amount, $"
                      << donationFromTotal << " will be donated to all charities collectively.\n";

            break;
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please choose 1, 2, 3, or -1 to show totals.\n";
            continue;
        }

        std::cout << "Enter your shopping bill amount: $";
        std::cin >> shoppingBill;

        donation = 0.01 * shoppingBill;

        charities[choice - 1].total += donation;

        std::cout << "\nThank you for your donation of $" << donation << " to " << charities[choice - 1].name << ".\n";
    }

    return 0;
}
//writen by Noor Fatima 
//AICP RASK WEEK 07
