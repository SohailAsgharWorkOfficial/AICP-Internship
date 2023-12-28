#include <iostream>
#include <unordered_map>

// Constants for weight limits
const double CEMENT_MIN_WEIGHT = 24.9;
const double CEMENT_MAX_WEIGHT = 25.1;
const double GRAVEL_SAND_MIN_WEIGHT = 49.9;
const double GRAVEL_SAND_MAX_WEIGHT = 50.1;

// Constants for sack prices
const double CEMENT_PRICE = 3.0;
const double GRAVEL_PRICE = 2.0;
const double SAND_PRICE = 2.0;
const double SPECIAL_PACK_PRICE = 10.0;

// Function to check a single sack
std::string checkSack(char contents, double weight) {
    // Check contents
    if (contents != 'C' && contents != 'G' && contents != 'S') {
        return "Invalid contents";
    }

    // Check weight
    if ((contents == 'C' && (weight <= CEMENT_MIN_WEIGHT || weight >= CEMENT_MAX_WEIGHT)) ||
        ((contents == 'G' || contents == 'S') && (weight <= GRAVEL_SAND_MIN_WEIGHT || weight >= GRAVEL_SAND_MAX_WEIGHT))) {
        return "Invalid weight";
    }

    return "Sack accepted - Contents: " + std::string(1, contents) + ", Weight: " + std::to_string(weight) + " kg";
}

// Function to check a customer's order
void checkOrder(std::unordered_map<char, int>& order, double& totalWeight, int& sacksRejected) {
    for (const auto& entry : order) {
        char contents = entry.first;
        int quantity = entry.second;

        for (int i = 0; i < quantity; ++i) {
            double weight;
            std::cout << "Enter the weight for a " << contents << " sack: ";
            std::cin >> weight;

            std::string result = checkSack(contents, weight);

            if (result.find("accepted") != std::string::npos) {
                totalWeight += weight;
            } else {
                std::cout << result << std::endl;
                sacksRejected++;
            }
        }
    }
}

// Function to calculate the price for a customer's order
void calculatePrice(const std::unordered_map<char, int>& order) {
    double regularPrice = 0;
    int specialPacks = std::min({order.at('C'), order.at('S') / 2, order.at('G') / 2});

    // Calculate regular price
    regularPrice += order.at('C') * CEMENT_PRICE;
    regularPrice += order.at('G') * GRAVEL_PRICE;
    regularPrice += order.at('S') * SAND_PRICE;

    // Calculate discount price for special packs
    double discountPrice = specialPacks * SPECIAL_PACK_PRICE;

    // Calculate total price
    double totalPrice = regularPrice - discountPrice;

    std::cout << "Regular Price: $" << regularPrice << std::endl;
    if (specialPacks > 0) {
        std::cout << "Discount Price: $" << discountPrice << std::endl;
        std::cout << "New Price: $" << totalPrice << std::endl;
        std::cout << "Amount Saved: $" << discountPrice << std::endl;
    } else {
        std::cout << "No special packs in the order." << std::endl;
    }
}

int main() {
    // Task 1 - Check the contents and weight of a single sack
    char sackContents;
    double sackWeight;

    std::cout << "Enter the contents of the sack (C, G, S): ";
    std::cin >> sackContents;

    std::cout << "Enter the weight of the sack in kilograms: ";
    std::cin >> sackWeight;

    std::cout << checkSack(sackContents, sackWeight) << std::endl;

    // Task 2 - Check a customer's order for delivery
    std::unordered_map<char, int> customerOrder = {{'C', 2}, {'G', 3}, {'S', 4}}; // Example order
    double totalWeight = 0;
    int sacksRejected = 0;

    checkOrder(customerOrder, totalWeight, sacksRejected);

    std::cout << "Total Weight of Order: " << totalWeight << " kg" << std::endl;
    std::cout << "Sacks Rejected from Order: " << sacksRejected << std::endl;

    // Task 3 - Calculate the price for a customer's order
    calculatePrice(customerOrder);

    return 0;
}