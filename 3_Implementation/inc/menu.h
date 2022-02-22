#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getInvoiceId();
void createInvoice();
void showBillheader(char[], char[], int);
void showBillbody(char[], int, float);
float getDiscount(float, float);
float getGSTPrice(float);
float getGrandTotal(float, float);
void showBillFooter(float);
void showAllInvoices();
void searchInvoiceById();

struct items
{
    char item[20];
    float price;
    int qty;
};
struct orders
{
    char customer[50];
    char date[50];
    int numofitems;
    float total;
    int invoiceId;
    struct items itm[50];
};

struct orders ord[50];

#endif