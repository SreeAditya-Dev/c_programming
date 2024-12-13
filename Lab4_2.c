#include <stdio.h>

int main()
{
    int storecount, productcount, dayscount;

    printf("Enter the number of stores: ");
    scanf("%d", &storecount);
    printf("Enter the number of products: ");
    scanf("%d", &productcount);
    printf("Enter the number of days: ");
    scanf("%d", &dayscount);

    float data[storecount][productcount][dayscount];
    float productdata[productcount];
    float storedata[storecount];

    for (int i = 0; i < productcount; i++)
    {
        productdata[i] = 0.0;
    }
    for (int i = 0; i < storecount; i++)
    {
        storedata[i] = 0.0;
    }

    for (int i = 0; i < storecount; i++)
    {
        printf("Enter the details for store - %d:\n", i + 1);
        for (int j = 0; j < productcount; j++)
        {
            printf("Product number-%d:\n", j + 1);
            for (int k = 0; k < dayscount; k++)
            {
                printf("Day-%d: ", k + 1);
                scanf("%f", &data[i][j][k]);
            }
        }
    }

    for (int i = 0; i < storecount; i++)
    {
        for (int j = 0; j < productcount; j++)
        {
            float sum = 0;
            for (int k = 0; k < dayscount; k++)
            {
                sum += data[i][j][k];
            }
            productdata[j] += sum;
            storedata[i] += sum;
        }
    }

    float promax = productdata[0];
    int bestprocount = 0;
    for (int i = 0; i < productcount; i++)
    {
        if (productdata[i] > promax)
        {
            promax = productdata[i];
            bestprocount = i;
        }
    }

    float storemax = storedata[0];
    int beststorecount = 0;
    for (int j = 0; j < storecount; j++)
    {
        if (storedata[j] > storemax)
        {
            storemax = storedata[j];
            beststorecount = j;
        }
    }

    printf("The best-selling product is %d with sales of Rs. %.2f.\n", bestprocount + 1, promax);
    printf("The highest-earning store is %d with sales of Rs. %.2f.\n", beststorecount + 1, storemax);

    float promin = productdata[0];
    int worstprocount = 0;
    for (int i = 0; i < productcount; i++)
    {
        if (productdata[i] < promin)
        {
            promin = productdata[i];
            worstprocount = i;
        }
    }

    float storemin = storedata[0];
    int worststorecount = 0;
    for (int j = 0; j < storecount; j++)
    {
        if (storedata[j] < storemin)
        {
            storemin = storedata[j];
            worststorecount = j;
        }
    }

    printf("The lowest performing product is %d with sales of Rs. %.2f.\n", worstprocount + 1, promin);
    printf("The lowest earning store is %d with sales of Rs. %.2f.\n", worststorecount + 1, storemin);

    float total_sales = 0;
    for (int j = 0; j < storecount; j++)
    {
        total_sales += storedata[j];
    }
    float store_average = total_sales / storecount;

    float threshold = store_average * 0.5;
    int c = 0;
    printf("Stores that need improvement (sales below Rs. %.2f):\n", threshold);
    for (int j = 0; j < storecount; j++)
    {
        if (storedata[j] < threshold)
        {
            printf("Store %d needs improvement with sales of Rs. %.2f.\n", j + 1, storedata[j]);
            c = 1;
        }
    }
    if (!c)
    {
        printf("No store has sales below threshold value.\n");
    }

    return 0;
}
