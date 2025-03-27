#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10  // Maximum number of items in the cart

int main() {
    char items[MAX_ITEMS][50];  // Array to store item names
    float prices[MAX_ITEMS];    // Array to store item prices
    int itemCount = 0;          // Track the number of items added to the cart
    int choice;
    float total = 0.0;
    float discount = 0.0;

    printf("Welcome to the Shopping Cart System!\n");
    printf("-------------------------------------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Item to Cart\n");
        printf("2. View Cart\n");
        printf("3. Calculate Total and Apply Discount\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To handle the newline left by scanf

        switch (choice) {
            case 1:  // Add item to cart
                if (itemCount < MAX_ITEMS) {
                    printf("Enter item name: ");
                    fgets(items[itemCount], 50, stdin);
                    items[itemCount][strcspn(items[itemCount], "\n")] = '\0';  // Remove newline

                    printf("Enter item price: ");
                    scanf("%f", &prices[itemCount]);
                    itemCount++;
                    printf("Item added to cart!\n");
                } else {
                    printf("Cart is full! Cannot add more items.\n");
                }
                break;

            case 2:  // View cart
                if (itemCount == 0) {
                    printf("Your cart is empty.\n");
                } else {
                    printf("Items in your cart:\n");
                    for (int i = 0; i < itemCount; i++) {
                        printf("%d. %s - $%.2f\n", i + 1, items[i], prices[i]);
                    }
                }
                break;

            case 3:  // Calculate total and apply discount
                total = 0.0;
                for (int i = 0; i < itemCount; i++) {
                    total += prices[i];
                }

                // Apply a discount based on total amount
                if (total > 100) {
                    discount = total * 0.10;  // 10% discount for total > $100
                    printf("You have earned a 10%% discount!\n");
                } else {
                    discount = 0.0;
                }

                printf("Total: $%.2f\n", total);
                printf("Discount: $%.2f\n", discount);
                printf("Final Total after Discount: $%.2f\n", total - discount);
                break;

            case 4:  // Exit
                printf("Thank you for using the Shopping Cart System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

    } while (choice != 4);  // Repeat menu until user chooses to exit

    return 0;
}
