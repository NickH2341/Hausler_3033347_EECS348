#include <stdio.h>
#include <stdlib.h>

// Function to read monthly sales from an input file
void readSales(double sales[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error reading sales data.\n");
            exit(1);
        }
    }
    fclose(file);
}

// Function to calculate the minimum, maximum, and average sales
void calculateSummary(double sales[], int n, double *min, double *max, double *avg) {
    *min = sales[0];
    *max = sales[0];
    double sum = sales[0];
    
    for (int i = 1; i < n; i++) {
        if (sales[i] < *min) {
            *min = sales[i];
        }
        if (sales[i] > *max) {
            *max = sales[i];
        }
        sum += sales[i];
    }
    
    *avg = sum / n;
}

// Function to calculate the six-month moving averages
void calculateMovingAverages(double sales[], int n, double movingAverages[], int window) {
    for (int i = 0; i <= n - window; i++) {
        double sum = 0.0;
        for (int j = 0; j < window; j++) {
            sum += sales[i + j];
        }
        movingAverages[i] = sum / window;
    }
}

// Function to generate the sales report
void generateSalesReport(double sales[], int n, const char *months[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month         Sales\n");
    for (int i = 0; i < n; i++) {
        printf("%s", months[i]);
        printf("     $%.2f\n", sales[i]);
    }
}

// Function to generate the sales summary
void generateSalesSummary(double min, double max, double avg, const char *months[], int minIndex, int maxIndex) {
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: $%.2f\n", avg);
}

// Function to generate the sales report sorted from highest to lowest
void generateSortedSalesReport(double sales[], const char *months[], int n) {
    // Sort the sales and keep track of the corresponding months
    int indexes[n];
    for (int i = 0; i < n; i++) {
        indexes[i] = i;
    }
    
    // Bubble sort (simple sorting algorithm) based on sales
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap sales
                double tempSale = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSale;
                // Swap indexes
                int tempIndex = indexes[j];
                indexes[j] = indexes[j + 1];
                indexes[j + 1] = tempIndex;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month         Sales\n\n");
    for (int i = 0; i < n; i++) {
        printf("%s", months[i]);
        printf("     $%.2f\n", sales[i]);
    }
}

int main() {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const int numMonths = 12;
    double sales[numMonths];
    double minSale, maxSale, avgSale;

    // Read the sales data from the input file
    readSales(sales, numMonths, "monthly_sales.txt");

    // Calculate the minimum, maximum, and average sales
    calculateSummary(sales, numMonths, &minSale, &maxSale, &avgSale);

    // Calculate six-month moving averages
    const int windowSize = 6;
    int numMovingAverages = numMonths - windowSize + 1;
    double movingAverages[numMovingAverages];
    calculateMovingAverages(sales, numMonths, movingAverages, windowSize);

    // Generate and print the reports
    generateSalesReport(sales, numMonths, months);
    generateSalesSummary(minSale, maxSale, avgSale, months, 0, numMonths - 1);
    generateSortedSalesReport(sales, months, numMonths);

    return 0;
}
