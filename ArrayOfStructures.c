#include<stdio.h>

int main ()
{
    int i; // counter for the loop

    char name[4][20];
    char brand[4][20];
    float total_cost = 0, total_dc_amount = 0, total_cost_withdc = 0;
    float unit_price[4], discount_per[4], cost[4], discountedAmount[4], CostWithDiscount[4];
    int quant[4];

    // NOTE: Every for loop used in the program is deterministic and entry controlled

    /* Using for loop to input details*/
    for (i = 0; i < 4; i++)
    {
        printf ("\nPlease enter the name of the item : ");
        scanf ("%s",&name[i]);
        printf ("\nPlease enter the brand name : ");
        scanf ("%s",&brand[i]);
        printf ("\nPlease enter the unit price and and quantity respectfully : ");
        scanf ("%f %d", &unit_price[i], &quant[i]);

        // Discount based on quantity of item
        if (quant[i] >= 1 && quant[i] <= 3)
            discount_per[i] = 0.038;
        if (quant[i] >= 4 && quant[i] <= 7)
            discount_per[i] = 0.051;
        if (quant[i] >= 8 && quant[i] <= 12)
            discount_per[i] = 0.074;
        if (quant[i] >= 12)
            discount_per[i] = 0.098;

        // Calculate cost, discounted price & cost with discount
        cost[i] = unit_price[i] * quant[i];
        discountedAmount[i] = cost[i] * discount_per[i];
        CostWithDiscount[i] = cost[i] - discountedAmount[i];
    }

    // using for loop
    // calculate total cost, total discount & total cost with discount in bill
    for (i = 0; i < 4; i++)
    {
        total_cost = total_cost + cost[i];
        total_dc_amount = total_dc_amount + discountedAmount[i];
        total_cost_withdc = total_cost_withdc + CostWithDiscount[i];
    }
    FILE *fptr;
    fptr = fopen("ItemList.txt", "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "Item \t Brand \t Cost \t Discounted amount \t Cost with the discount\n");

    for (i = 0; i < 4; i++)
    {
        fprintf(fptr, "%s \t %s \t $%0.2f \t $%0.2f \t\t $%0.2f\n",name[i], brand[i], cost[i], discountedAmount[i],CostWithDiscount[i]);
    }

    fprintf(fptr, "\n\nThe total cost is $ %0.2f \n", total_cost);
    fprintf(fptr, "The total discounted amount is $ %0.2f \n", total_dc_amount);
    fprintf(fptr, "The total cost with the discount is $ %0.2f \n", total_cost_withdc);
    return 0;
}
