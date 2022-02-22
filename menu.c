
#include "./3_Implementation/inc/menu.h"

int invoiceGenerated = 0;
int ordersProcessed = 0;

int getInvoiceId()
{
    return invoiceGenerated;
}

void showBillheader(char name[50], char date[30], int orderIndex)
{
    printf("\n\n");
    printf("\t       RAJDHANI RESTURANT");
    printf("\n\t     --------------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\nInvoice Id:%d", ord[orderIndex].invoiceId);
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n----------------------------------------------------");
    printf("\n\n");
}
void showBillbody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

float getDiscount(float total, float discountPercent)
{
    float discount = ((100 - discountPercent) / 100) * total;
    return discount;
}

float getGSTPrice(float netTotal)
{
    float gstSlab = 0.09;
    float gst = gstSlab * netTotal;
    return gst;
}

float getGrandTotal(float netTotal, float gstPrice)
{
    return netTotal + (2 * gstPrice);
}

void showBillFooter(float total)
{
    printf("\n");
    float discount = 10;
    float netTotal = getDiscount(total, discount);
    float gst = getGSTPrice(netTotal);
    float grandTotal = getGrandTotal(netTotal, gst);
    printf("----------------------------------------------------");
    printf("\nSub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", total - netTotal);
    printf("\n\t\t\t\t--------");
    printf("\nNetTotal\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", gst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", gst);
    printf("\n----------------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f\n", grandTotal);
}

void showAllInvoices()
{

    for (int orderIndex = 0; orderIndex < ordersProcessed; ++orderIndex)
    {
        showBillheader(ord[orderIndex].customer, __DATE__, orderIndex);
        int total = 0;
        for (int itemIndex = 0; itemIndex < ord[orderIndex].numofitems; ++itemIndex)
        {
            total += (ord[orderIndex].itm[itemIndex].qty * ord[orderIndex].itm[itemIndex].price);
            showBillbody(ord[orderIndex].itm[itemIndex].item, ord[orderIndex].itm[itemIndex].qty, ord[orderIndex].itm[itemIndex].price);
        }
        showBillFooter(total);
    }
}

void searchInvoiceById()
{
    int invoiceId;
    printf("\nEnter Invoice Id::");
    scanf("%d", &invoiceId);
    int invoiceFound = 0;

    for (int orderIndex = 0; orderIndex < ordersProcessed; ++orderIndex)
    {
        if (ord[orderIndex].invoiceId == invoiceId)
        {
            invoiceFound = 1;
            showBillheader(ord[orderIndex].customer, __DATE__, orderIndex);
            int total = 0;
            for (int itemIndex = 0; itemIndex < ord[orderIndex].numofitems; ++itemIndex)
            {
                total += (ord[orderIndex].itm[itemIndex].qty * ord[orderIndex].itm[itemIndex].price);
                showBillbody(ord[orderIndex].itm[itemIndex].item, ord[orderIndex].itm[itemIndex].qty, ord[orderIndex].itm[itemIndex].price);
            }
            showBillFooter(total);
        }
    }

    if (invoiceFound == 0)
    {
        printf("\nNo Invoice with this Invoice Id\n\n");
    }
}

int main()
{
    int opt;

    do
    {
        // DASHBOARD
        printf("\n\t       RAJDHANI RESTURANT         ");
        printf("\n1.Generate Invoice");
        printf("\n2.Show all Invoices");
        printf("\n3.Search Invoice");
        printf("\n4.Exit");

        printf("\n\nPlease select your prefered operation:\t");
        scanf("%d", &opt);

        fgetc(stdin);
        switch (opt)
        {

        case 1:
            invoiceGenerated++;
            createInvoice();
            ordersProcessed++;
            break;

        case 2:
            showAllInvoices();
            break;
        case 3:
            searchInvoiceById();
            break;
        }
    } while (opt != 4);

    printf("\n\n");

    return 0;
}