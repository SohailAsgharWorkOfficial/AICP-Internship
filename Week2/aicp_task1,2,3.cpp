#include <iostream>
#include <map>

std::map<std::string, std::map<std::string, int>> journeys = {
    {"09:00", {{"up", 0}, {"down", 0}, {"revenue", 0}}},
    {"11:00", {{"up", 0}, {"down", 0}, {"revenue", 0}}},
    {"13:00", {{"up", 0}, {"down", 0}, {"revenue", 0}}},
    {"15:00", {{"up", 0}, {"down", 0}, {"revenue", 0}}}
};

void displayHeader() {
    std::cout << "*****************" << std::endl;
    std::cout << "      Welcome to the Ticket Management System       " << std::endl;
    std::cout << "*****************" << std::endl;
}

void purchaseTickets() {
    std::string journey_time;
    std::cout << "Enter the journey time (in HH:MM format): ";
    std::cin >> journey_time;

    int num_passengers;
    std::cout << "Enter the number of passengers: ";
    std::cin >> num_passengers;

    if (journeys.find(journey_time) == journeys.end()) {
        std::cout << "Invalid journey time." << std::endl;
        return;
    }

    auto& journey = journeys[journey_time];

    if (num_passengers * 2 > 80 * 6) {
        std::cout << "Not enough seats available." << std::endl;
        return;
    }

    int price_per_ticket = 25;
    int total_price = num_passengers * price_per_ticket;

    if (num_passengers >= 10 && num_passengers <= 80) {
        int free_tickets = num_passengers / 10;
        total_price -= free_tickets * price_per_ticket;
    }

    journey["up"] += num_passengers;
    journey["revenue"] += total_price;

    std::cout << "Tickets purchased successfully." << std::endl;
    std::cout << "Total amount paid: $" << total_price << std::endl;
}

void endOfDay() {
    int total_passengers = 0;
    int total_revenue = 0;
    int max_passengers = 0;
    std::string max_journey_time = "";

    std::cout << "End of the day report:" << std::endl;

    for (const auto& [journey_time, journey] : journeys) {
        total_passengers += journey.at("up");
        total_revenue += journey.at("revenue");

        std::cout << "Journey Time: " << journey_time << std::endl;
        std::cout << "Passengers: " << journey.at("up") << std::endl;
        std::cout << "Revenue collected: " << journey.at("revenue") << std::endl;
        std::cout << "---------------------------------" << std::endl;

        if (journey.at("up") > max_passengers) {
            max_passengers = journey.at("up");
            max_journey_time = journey_time;
        }
    }

    std::cout << "Total passengers for the day: " << total_passengers << std::endl;
    std::cout << "Total revenue collected for the day: $" << total_revenue << std::endl;
    std::cout << "Journey with the most passengers: " << max_journey_time << " with " << max_passengers << " passengers." << std::endl;
}

void displayJourneyTimes() {
    std::cout << "Available Journey Times:" << std::endl;
    for (const auto& journey_time : journeys) {
        std::cout << journey_time.first << std::endl;
    }
}

void displayMenu() {
    std::cout << "\nOptions:" << std::endl;
    std::cout << "1. Purchase Tickets" << std::endl;
    std::cout << "2. End of Day Report" << std::endl;
    std::cout << "3. Display Journey Times" << std::endl;
    std::cout << "q. Quit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    displayHeader();
    std::cout << "Start of the day." << std::endl;

    while (true) {
        displayMenu();

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            purchaseTickets();
        } else if (choice == "2") {
            endOfDay();
        } else if (choice == "3") {
            displayJourneyTimes();
        } else if (choice == "q") {
            std::cout << "Thank you for using the Ticket Management System. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "\nInvalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
