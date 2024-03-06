/* This project "FRUIT SHOP" was created by
Laiba Hamayun    FA23-BCS-074
Maham Shahid     FA23-BCS-079
Mashal Shakeel   FA23-BCS-187
Section B

It displays menu of a fruit shop along with the prices per amount. Then prompts user/costumer to input which fruit they wish to buy, along with the amount.
The user may continue to buy until they wish to stop. After this, a receipt is generated in a separate text file.
This program makes use of basic C as well as structs, arrays and file handling. */

#include <stdio.h>

// Structure to store fruit information
typedef struct Fruit
{
    char name[50];//storing name of the fruit
    float pricePerKg;//storing price per kilogram
    int quantity;//storing quantity
} Fruit;

// Function to display available fruits
void displayFruits()
{
    printf("\n**WELCOME TO THE FRUIT SHOP**\n");
    printf("_________________________________\n");
    printf("|   FRUITS    QUANTITY     RATES|\n");
    printf("---------------------------------\n");
    printf("|1) Apple      1 Kg       Rs.299|\n");
    printf("|2) Banana     1 dozen    Rs.157|\n");
    printf("|3) Orange     1 Kg       Rs.150|\n");
    printf("|4) Mangoes    1 Kg       Rs.160|\n");
    printf("|5) Grapes     1 Kg       Rs.200|\n");
    printf("|6) Guavas     1 Kg       Rs.100|\n");
    printf("---------------------------------\n");
}

// Function to update fruit quantity and calculate cost
float updateFruit(Fruit fruits[], int fruitIndex, int quantity)//array of fruit,index of selected fruit in array,quantity
{
    if (quantity > 0)
    {
        fruits[fruitIndex].quantity += quantity;//adding purchased quantity to existing quantity using member access operator
        return fruits[fruitIndex].pricePerKg * quantity;//cost of the purchase
    }
    else
    {
        printf("Invalid quantity.\n");
        return 0.0;//cost is zero
    }
}

// Function to display bill and write receipt to a file
void displayBill(Fruit fruits[], int numFruits, float totalBill)//array of fruit,number of fruits,bill
{
    // Use a fixed receipt file name
    const char *receiptFileName = "receipt.txt";//giving our file a const name

    // Open the receipt file for writing
    FILE *receiptFile = fopen(receiptFileName, "w");//opening receipt file for writing


    if (receiptFile != NULL)//if file opened successfully
    {
        fprintf(receiptFile, "Receipt generated\n");//header in file
        fprintf(receiptFile, "----------------------------------------\n");

        // Check if any items were purchased
        int itemsPurchased = 0;

        for (int i = 0; i < numFruits; i++)
        {
            if (fruits[i].quantity > 0)//checking if quantity is more than 0
            {
                if (!itemsPurchased)//conditionally printing information in file,execute if no item purchased
                {
                    fprintf(receiptFile, "%-15s%-10s%-10s%-10s\n", "Fruit", "Quantity", "Price/kg", "Total");
                    fprintf(receiptFile, "------------------------------------------------\n");
                }

                fprintf(receiptFile, "%-15s%-10d%-10.2f%-10.2f\n", fruits[i].name, fruits[i].quantity, fruits[i].pricePerKg, fruits[i].quantity * fruits[i].pricePerKg);

                itemsPurchased = 1;//flag value at least one value purchased
            }
        }

        if (itemsPurchased)//item is purchased
        {
            fprintf(receiptFile, "------------------------------------------------\n");
            fprintf(receiptFile, "%-35s%.2f\n", "Total:", totalBill);
        }
        else
        {
            fprintf(receiptFile, "No items purchased.\n");
        }

        // Close the receipt file
        fclose(receiptFile);//closing the file

        printf("Receipt saved to %s\n", receiptFileName);
    }
    else
    {
        printf("Error opening receipt file for writing.\n");
    }

    // Now, display the bill on the console
    printf("\nYour Bill:\n");

    // Check if any items were purchased
    int itemsPurchased = 0;

    for (int i = 0; i < numFruits; i++)
    {
        if (fruits[i].quantity > 0)
        {
            if (!itemsPurchased)
            {
                printf("%-15s%-10s%-10s%-10s\n", "Fruit", "Quantity", "Price/kg", "Total");
                printf("------------------------------------------------\n");
            }

            printf("%-15s%-10d%-10.2f%-10.2f\n", fruits[i].name, fruits[i].quantity, fruits[i].pricePerKg, fruits[i].quantity * fruits[i].pricePerKg);

            itemsPurchased = 1;
        }
    }

    if (itemsPurchased)
    {
        printf("------------------------------------------------\n");
        printf("%-35s%.2f\n", "Total:", totalBill);
    }
    else
    {
        printf("No items purchased.\n");
    }
}

// Function to read fruit information from a file
void readFruitsFromFile(Fruit fruits[], int numFruits)
{
    FILE *file = fopen("fruit.txt", "r");//opening file for reading,returning pointer to a file

    if (file != NULL)//checks if file is successfully opened
    {
        for (int i = 0; i < numFruits; i++)
        {
            fscanf(file, "%s%f%d", fruits[i].name, &fruits[i].pricePerKg, &fruits[i].quantity);
        }

        fclose(file);//closing file after reading data required
    }
}

// Function to write default fruit information to a file
void writeDefaultFruitsToFile(Fruit fruits[], int numFruits)
{
    FILE *file = fopen("fruit.txt", "w");//open file for writing

    if (file != NULL)
    {
        for (int i = 0; i < numFruits; i++)
        {
            fprintf(file, "%s %.2f %d\n", fruits[i].name, fruits[i].pricePerKg, 0);//format and write data to file
        }

        fclose(file);
    }
}

int main()
{
    // Define available fruits
    Fruit fruits[] =
        {
            {"Apple", 299, 0}, {"Banana", 157, 0}, {"Orange", 150, 0}, {"Mangoes", 160, 0}, {"Grapes", 200, 0},
            {"Guavas", 100, 0}};

    // Number of fruits
    const int numFruits = sizeof(fruits) / sizeof(fruits[0]);

    // Write default fruit information to file
    writeDefaultFruitsToFile(fruits, numFruits);

    // Read fruit information from file
    readFruitsFromFile(fruits, numFruits);

    // Welcome message and display fruits
    printf("Welcome to the Fruit Shop!\n");
    displayFruits();

    // User input variables
    int choice, quantity;
    float totalBill = 0.0;
    int continueShopping = 1;

    // Shopping loop
    do
    {
        // Get user input
        printf("\nChoose a fruit (1-%d): ", numFruits);
        scanf("%d", &choice);
        if (choice < 1 || choice > numFruits)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        // Get quantity
        printf("Enter quantity (kg): ");
        scanf("%d", &quantity);

        // Update fruit and calculate cost
        totalBill += updateFruit(fruits, choice - 1, quantity);

        // clear input buffer
        while ((getchar()) != '\n')
            ;

        // Continue shopping?
        char yesNo;
        printf("Continue shopping (y/n): ");
        scanf(" %c", &yesNo);
        if (yesNo == 'n' || yesNo == 'N')
        {
            continueShopping = 0;
        }
        else if (yesNo != 'y' && yesNo != 'Y')
        {
            printf("Invalid input. Exiting shopping.\n");
            continueShopping = 0;
        }
    } while (continueShopping);

    // Display bill and save receipt to file
    displayBill(fruits, numFruits, totalBill);

    return 0;
}
