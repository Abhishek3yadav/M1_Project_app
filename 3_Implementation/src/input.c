
#include "../inc/menu.h"

int ordersProcessed;

void createInvoice()
{

    printf("\nPlease enter the name of the customer::");
    fgets(ord[ordersProcessed].customer, 50, stdin);
    ord[ordersProcessed].customer[strlen(ord[ordersProcessed].customer) - 1] = 0;
    strcpy(ord[ordersProcessed].date, __DATE__);
    printf("\nPlease enter the number of items::");
    scanf("%d", &ord[ordersProcessed].numofitems);
    ord[ordersProcessed].invoiceId = getInvoiceId();

    for (int i = 0; i < ord[ordersProcessed].numofitems; i++)
    {
        fgetc(stdin);
        printf("\n\n");
        printf("please enter the item %d::", i + 1);
        fgets(ord[ordersProcessed].itm[i].item, 20, stdin);
        ord[ordersProcessed].itm[i].item[strlen(ord[ordersProcessed].itm[i].item) - 1] = 0;
        printf("\n please enter the quantity::");
        scanf("%d", &ord[ordersProcessed].itm[i].qty);
        printf("\n please enter the unit price::");
        scanf("%f", &ord[ordersProcessed].itm[i].price);
    }

    showBillheader(ord[ordersProcessed].customer, __DATE__, ordersProcessed);
    int total = 0;
    for (int i = 0; i < ord[ordersProcessed].numofitems; ++i)
    {
        total += (ord[ordersProcessed].itm[i].qty * ord[ordersProcessed].itm[i].price);
        showBillbody(ord[ordersProcessed].itm[i].item, ord[ordersProcessed].itm[i].qty, ord[ordersProcessed].itm[i].price);
    }

    showBillFooter(total);
}
