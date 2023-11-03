from prettytable import PrettyTable

item_data = [
    ["A1", "Compact", 75.00],
    ["A2", "Tower", 150.00],
    ["B1", "8 GB", 79.99],
    ["B2", "16 GB", 149.99],
    ["B3", "32 GB", 299.99],
    ["C1", "1 TB HDD", 49.99],
    ["C2", "2 TB HDD", 89.99],
    ["D1", "240 GB SSD", 59.99],
    ["D2", "480 GB SSD", 119.99],
    ["E1", "1 TB HDD", 49.99],
    ["E2", "2 TB HDD", 89.99],
    ["E3", "4 TB HDD", 129.99],
    ["F1", "DVD/Blu-Ray Player", 50.00],
    ["F2", "DVD/Blu-Ray Re-writer", 100.00],
    ["G1", "Standard Version", 100.00],
    ["G2", "Professional Version", 175.00],
]

basic_set_price = 200.00
chosen_case = None
chosen_ram = None
chosen_hdd = None
total_price = 0

table = PrettyTable()
table.field_names = ["Item code", "Description", "Price ($)"]

for item in item_data:
    item_code, description, price = item
    table.add_row([item_code, description, price])

print("Computer Component Options:")
print(table)

try:
    chosen_case = input("Choose a case (Enter item code, e.g., 'A1' for Compact): ")
    chosen_ram = input("Choose RAM (Enter item code, e.g., 'B1' for 8 GB): ")
    chosen_hdd = input("Choose Main Hard Disk Drive (Enter item code, e.g., 'C1' for 1 TB HDD): ")
except ValueError:
    print("Invalid input. Please enter a valid item code for your selection.")
    exit()

chosen_case_price = next((price for code, desc, price in item_data if code == chosen_case), 0)
chosen_ram_price = next((price for code, desc, price in item_data if code == chosen_ram), 0)
chosen_hdd_price = next((price for code, desc, price in item_data if code == chosen_hdd), 0)
total_price = basic_set_price + chosen_case_price + chosen_ram_price + chosen_hdd_price

print("Total Price (Before Additional Items): ${:.2f}".format(total_price))

def choose_additional_items(item_data, total_price):
    additional_items = []
    
    while True:
        print("\nAdditional Component Options:")
        table = PrettyTable()
        table.field_names = ["Item code", "Description", "Price ($)"]
        
        for item in item_data:
            item_code, description, price = item
            table.add_row([item_code, description, price])
        
        print(table)
        
        additional_item = input("Choose an additional item (Enter item code, or 'done' to finish): ")
        
        if additional_item.lower() == 'done':

            break

        item_price = next((price for code, desc, price in item_data if code == additional_item), None)
        if item_price is not None:
            total_price += item_price
            additional_items.append(additional_item)

    return additional_items, total_price

additional_items, total_price = choose_additional_items(item_data, total_price)

if additional_items:
    print("Additional Items:")
    for item in additional_items:
        item_price = next((price for code, desc, price in item_data if code == item), None)
        print(f"{item}: ${item_price:.2f}")
    print("New Total Price: ${:.2f}".format(total_price))
else:
    print("No additional items selected. The total price remains ${:.2f}".format(total_price))
