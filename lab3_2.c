#include <stdio.h>

#define NUM_STORES 5
#define NUM_PRODUCTS 4
#define DAYS_IN_MONTH 30


void inputSalesData(float productsSales[NUM_STORES][NUM_PRODUCTS][DAYS_IN_MONTH]);
void calculateMonthlySales(float productsSales[NUM_STORES][NUM_PRODUCTS][DAYS_IN_MONTH], float monthlySalesPerStore[NUM_STORES], float monthlySalesPerProduct[NUM_PRODUCTS]);
void bestSellingProducts(float monthlySalesPerProduct[NUM_PRODUCTS]);
void highestEarningStores(float monthlySalesPerStore[NUM_STORES]);
void lowPerformingProducts(float monthlySalesPerProduct[NUM_PRODUCTS]);
void storesNeedingImprovement(float monthlySalesPerStore[NUM_STORES]);

int main() {

    float productsSales[NUM_STORES][NUM_PRODUCTS][DAYS_IN_MONTH] = {0};
    float monthlySalesPerStore[NUM_STORES] = {0}; 
    float monthlySalesPerProduct[NUM_PRODUCTS] = {0};  

    
    inputSalesData(productsSales);

    calculateMonthlySales(productsSales, monthlySalesPerStore, monthlySalesPerProduct);

   
    bestSellingProducts(monthlySalesPerProduct);
    highestEarningStores(monthlySalesPerStore);
    lowPerformingProducts(monthlySalesPerProduct);
    storesNeedingImprovement(monthlySalesPerStore);

    return 0;
}


void inputSalesData(float productsSales[NUM_STORES][NUM_PRODUCTS][DAYS_IN_MONTH]) {
    for (int store = 0; store < NUM_STORES; store++) {
        for (int product = 0; product < NUM_PRODUCTS; product++) {
            printf("\nEnter daily sales for Store %d, Product %d:\n", store + 1, product + 1);
            for (int day = 0; day < DAYS_IN_MONTH; day++) {
                printf("Day %d: ", day + 1);
                scanf("%f", &productsSales[store][product][day]);
            }
        }
    }
}


void calculateMonthlySales(float productsSales[NUM_STORES][NUM_PRODUCTS][DAYS_IN_MONTH], float monthlySalesPerStore[NUM_STORES], float monthlySalesPerProduct[NUM_PRODUCTS]) {
    for (int store = 0; store < NUM_STORES; store++) {
        for (int product = 0; product < NUM_PRODUCTS; product++) {
            float totalSales = 0;
            for (int day = 0; day < DAYS_IN_MONTH; day++) {
                totalSales += productsSales[store][product][day];
            }
            monthlySalesPerStore[store] += totalSales;  
            monthlySalesPerProduct[product] += totalSales;  
        }
    }
}


void bestSellingProducts(float monthlySalesPerProduct[NUM_PRODUCTS]) {
    float maxSales = 0;
    int bestProduct = 0;
    
    for (int product = 0; product < NUM_PRODUCTS; product++) {
        if (monthlySalesPerProduct[product] > maxSales) {
            maxSales = monthlySalesPerProduct[product];
            bestProduct = product;
        }
    }
    printf("\nBest-Selling Product: Product %d with total monthly sales of %.2f\n", bestProduct + 1, maxSales);
}


void highestEarningStores(float monthlySalesPerStore[NUM_STORES]) {
    float maxSales = 0;
    int bestStore = 0;
    
    for (int store = 0; store < NUM_STORES; store++) {
        if (monthlySalesPerStore[store] > maxSales) {
            maxSales = monthlySalesPerStore[store];
            bestStore = store;
        }
    }
    printf("Highest-Earning Store: Store %d with total monthly sales of %.2f\n", bestStore + 1, maxSales);
}


void lowPerformingProducts(float monthlySalesPerProduct[NUM_PRODUCTS]) {
    float minSales = monthlySalesPerProduct[0];
    int lowProduct = 0;
    
    for (int product = 1; product < NUM_PRODUCTS; product++) {
        if (monthlySalesPerProduct[product] < minSales) {
            minSales = monthlySalesPerProduct[product];
            lowProduct = product;
        }
    }
    printf("Low-Performing Product: Product %d with total monthly sales of %.2f\n", lowProduct + 1, minSales);
}

void storesNeedingImprovement(float monthlySalesPerStore[NUM_STORES]) {
    printf("\nStores Needing Improvement:\n");
    for (int store = 0; store < NUM_STORES; store++) {
        if (monthlySalesPerStore[store] < 500) {  
            printf("Store %d with total monthly sales of %.2f\n", store + 1, monthlySalesPerStore[store]);
        }
    }
}
