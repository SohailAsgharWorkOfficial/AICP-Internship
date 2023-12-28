#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <limits> // for cin.ignore()

struct Boat {
    bool isAvailable;
    double moneyTaken;
    double totalHoursHired;
    time_t returnTime;
};

const int NUM_BOATS = 10;
const double COST_PER_HOUR = 20.0;
const double COST_PER_HALF_HOUR = 12.0;
const time_t OPENING_TIME = 10 * 60 * 60; // 10:00 in seconds
const time_t CLOSING_TIME = 17 * 60 * 60; // 17:00 in seconds

void initializeBoats(std::vector<Boat>& boats) {
    for (int i = 0; i < NUM_BOATS; ++i) {
        boats.push_back({true, 0.0, 0.0, OPENING_TIME});
    }
}

void displayBoats(const std::vector<Boat>& boats) {
    std::cout << std::setw(15) << "Boat Number" << std::setw(15) << "Available" << std::setw(20) << "Return Time\n";
    for (int i = 0; i < NUM_BOATS; ++i) {
        std::cout << std::setw(15) << i + 1 << std::setw(15) << (boats[i].isAvailable ? "Yes" : "No");
        std::cout << std::setw(20) << (boats[i].isAvailable ? "N/A" : std::asctime(std::localtime(&boats[i].returnTime)));
        std::cout << "\n";
    }
}

void hireBoat(std::vector<Boat>& boats, int boatNumber, double hireDuration) {
    time_t currentTime = std::time(0);
    
    if (boatNumber < 1 || boatNumber > NUM_BOATS) {
        std::cout << "Invalid boat number. Please choose a number between 1 and " << NUM_BOATS << ".\n";
        return;
    }

    if (!boats[boatNumber - 1].isAvailable) {
        std::cout << "Boat " << boatNumber << " is not available. It will be available at ";
        std::cout << std::asctime(std::localtime(&boats[boatNumber - 1].returnTime));
        return;
    }

    if (currentTime < OPENING_TIME || currentTime > CLOSING_TIME) {
        std::cout << "Boats can only be hired between 10:00 and 17:00.\n";
        return;
    }

    double cost;
    if (hireDuration == 0.5) {
        cost = COST_PER_HALF_HOUR;
    } else if (hireDuration == 1.0) {
        cost = COST_PER_HOUR;
    } else {
        std::cout << "Invalid hire duration. Please choose 0.5 or 1.0 hours.\n";
        return;
    }

    boats[boatNumber - 1].isAvailable = false;
    boats[boatNumber - 1].moneyTaken += cost;
    boats[boatNumber - 1].totalHoursHired += hireDuration;
    boats[boatNumber - 1].returnTime = currentTime + hireDuration * 60 * 60;

    std::cout << "Boat " << boatNumber << " has been hired for " << hireDuration << " hours.\n";
}

void calculateTotalMoneyAndHours(const std::vector<Boat>& boats) {
    double totalMoney = 0.0;
    double totalHours = 0.0;
    int boatsNotUsed = 0;
    int mostUsedBoat = 0;

    for (int i = 0; i < NUM_BOATS; ++i) {
        totalMoney += boats[i].moneyTaken;
        totalHours += boats[i].totalHoursHired;

        if (boats[i].totalHoursHired == 0.0) {
            boatsNotUsed++;
        }

        if (boats[i].totalHoursHired > boats[mostUsedBoat].totalHoursHired) {
            mostUsedBoat = i;
        }
    }

    std::cout << "\nEnd of Day Report:\n";
    std::cout << "Total Money Taken: $" << totalMoney << "\n";
    std::cout << "Total Hours Hired: " << totalHours << " hours\n";
    std::cout << "Boats Not Used: " << boatsNotUsed << "\n";
    std::cout << "Most Used Boat: Boat " << mostUsedBoat + 1 << " (" << boats[mostUsedBoat].totalHoursHired << " hours)\n";
}

int main() {
    std::vector<Boat> boats;
    initializeBoats(boats);

    int choice;
    int boatNumber;
    double hireDuration;

    std::cout << "Welcome to the River Boat Hire System!\n";

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Hire a Boat\n";
        std::cout << "2. Display Boat Availability\n";
        std::cout << "3. Calculate Total Money and Hours\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the boat number (1-" << NUM_BOATS << "): ";
                std::cin >> boatNumber;
                std::cout << "Enter the hire duration (0.5 or 1.0 hours): ";
                std::cin >> hireDuration;
                hireBoat(boats, boatNumber, hireDuration);
                break;
            case 2:
                displayBoats(boats);
                break;
            case 3:
                calculateTotalMoneyAndHours(boats);
                break;
            case 4:
                std::cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}

