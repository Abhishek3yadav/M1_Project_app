#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int invoiceGenerated=0;
int ordersProcessed=0;

 struct items{
     char item[50];
     float price;
     int qty;
 };
 struct orders{
     char customer[50];
     char date[50];
     int numofitems;
     float total;
     int invoiceId;
     struct items itm[50];
 };

struct orders ord[50];

 
 int getInvoiceId(){
   return invoiceGenerated;
 }

void showBillheader(char name[50],char date[50],int orderIndex){
    printf("\n\n");
    printf("\t       RAJDHANI RESTURANT");
    printf("\n\t     --------------------");
    printf("\nDate:%s",date);
    printf("\nInvoice To: %s", name);
    printf("\nInvoice Id:%d",ord[orderIndex].invoiceId);
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n----------------------------------------------------");
    printf("\n\n");
}
 void showBillbody(char item[50],int qty,float price){
      printf("%s\t\t",item);
       printf("%d\t\t",qty);
        printf("%.2f\t\t",qty*price);
         printf("\n");
 }
 
 float getDiscount(float total,float discountPercent){
     float discount = ((100-discountPercent)/100)*total;
     return discount;
 }
 
 float getGSTPrice(float netTotal){
     float gstSlab = 0.09;
     float gst = gstSlab * netTotal;
     return gst;
 }
 
 float getGrandTotal(float netTotal,float gstPrice){
     return netTotal+ (2*gstPrice);
 }
 
 void showBillFooter(float total){
      printf("\n");
      float discount = 10;
      float netTotal = getDiscount(total,discount);
      float gst = getGSTPrice(netTotal);
      float grandTotal = getGrandTotal(netTotal,gst);
       printf("----------------------------------------------------");
       printf("\nSub Total\t\t\t%.2f",total);
        printf("\nDiscount @10%s\t\t\t%.2f","%",total-netTotal);
        printf("\n\t\t\t\t--------");
        printf("\nNetTotal\t\t\t%.2f",netTotal);
        printf("\nCGST @9%s\t\t\t%.2f","%",gst);
        printf("\nSGST @9%s\t\t\t%.2f","%",gst);
        printf("\n----------------------------------------------------");
        printf("\nGrand Total\t\t\t%.2f\n",grandTotal);
 }

 
 void createInvoice(){
     
     printf("\nPlease enter the name of the customer::");
         fgets(ord[ordersProcessed].customer,50,stdin);
         ord[ordersProcessed].customer[strlen(ord[ordersProcessed].customer)-1] =0;
         strcpy(ord[ordersProcessed].date,__DATE__);
         printf("\nPlease enter the number of items::");
         scanf("%d",&ord[ordersProcessed].numofitems);
         ord[ordersProcessed].invoiceId = getInvoiceId();

         for(int i=0;i<ord[ordersProcessed].numofitems;i++){
             fgetc(stdin);
             printf("\n\n");
             printf("please enter the item %d::",i+1);
             fgets(ord[ordersProcessed].itm[i].item,20,stdin);
             ord[ordersProcessed].itm[i].item[strlen(ord[ordersProcessed].itm[i].item)-1]=0;
             printf("\n please enter the quantity::");
             scanf("%d",&ord[ordersProcessed].itm[i].qty);
             printf("\n please enter the unit price::");
             scanf("%f",&ord[ordersProcessed].itm[i].price);

         }
         
        showBillheader(ord[ordersProcessed].customer,__DATE__,ordersProcessed);
         int total = 0 ;
         for(int i=0;i<ord[ordersProcessed].numofitems;++i){
             total += (ord[ordersProcessed].itm[i].qty * ord[ordersProcessed].itm[i].price);
             showBillbody(ord[ordersProcessed].itm[i].item,ord[ordersProcessed].itm[i].qty,ord[ordersProcessed].itm[i].price);
         }
         
        showBillFooter(total);

 }
 
 
 void showAllInvoices(){

    for(int orderIndex=0;orderIndex<ordersProcessed;++orderIndex){
        showBillheader(ord[orderIndex].customer,__DATE__,orderIndex);
         int total = 0 ;
         for(int itemIndex=0;itemIndex<ord[orderIndex].numofitems;++itemIndex){
             total += (ord[orderIndex].itm[itemIndex].qty * ord[orderIndex].itm[itemIndex].price);
             showBillbody(ord[orderIndex].itm[itemIndex].item,ord[orderIndex].itm[itemIndex].qty,ord[orderIndex].itm[itemIndex].price);
         }
        showBillFooter(total);
    }
 }

 void searchInvoiceById(){
     int invoiceId;
     printf("\nEnter Invoice Id::");
     scanf("%d",&invoiceId);
     int invoiceFound = 0;

     for(int orderIndex=0;orderIndex<ordersProcessed;++orderIndex){
         if(ord[orderIndex].invoiceId == invoiceId){
            invoiceFound = 1; 
            showBillheader(ord[orderIndex].customer,__DATE__,orderIndex);
            int total = 0 ;
            for(int itemIndex=0;itemIndex<ord[orderIndex].numofitems;++itemIndex){
                total += (ord[orderIndex].itm[itemIndex].qty * ord[orderIndex].itm[itemIndex].price);
                showBillbody(ord[orderIndex].itm[itemIndex].item,ord[orderIndex].itm[itemIndex].qty,ord[orderIndex].itm[itemIndex].price);
            }
            showBillFooter(total);
         }
     }

     if(invoiceFound == 0){
        printf("\nNo Invoice with this Invoice Id\n\n");
     }
 }
 
 int main(){
    int opt;
    
    do{
     // DASHBOARD
     printf("\n\t       RAJDHANI RESTURANT         ");
     printf("\n1.Generate Invoice");
     printf("\n2.Show all Invoices");
     printf("\n3.Search Invoice");
     printf("\n4.Exit");

     printf("\n\nPlease select your prefered operation:\t");
     scanf("%d",&opt);
     
     fgetc(stdin);
     switch(opt){
         
        case 1: invoiceGenerated++;
                createInvoice();
                ordersProcessed++;
                //printf("\norderProcessed::%d",ordersProcessed);
                break;
                 
        case 2: showAllInvoices(); 
                break;
        case 3: searchInvoiceById();
                break;                
         
     }
    }while(opt!=4);
          
          printf("\n\n");
     

     return 0;
      
 }
