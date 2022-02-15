#include<stdio.h>

 void Breakfast(){
    printf(" WELCOME TO THE RAJDHANI HOTEL! \n");

    printf(" ALOO PARATHA                 =40Rs\n");
    printf(" PANEER PARATHA               =45Rs\n");
    printf(" CHHOLE BHATURE               =50Rs\n");
    


}
void Lunch()
{
   printf(" WELCOME TO THE RAJDHANI HOTEL! \n");
   
   printf("   RAJDHANI THALI SPECIAL            = 140Rs\n");
   printf("   FULL PLATE BIRYANI                = 100Rs\n");
   printf("   CHICKEN MASALA                    = 80Rs\n");
   printf("   EGG CURRY WITH CHAPATI            = 70Rs\n");
   printf("   VEG SPECIAL THALI                 = 100Rs\n");

}void Dinner ()
{
   printf(" WELCOME TO THE RAJDHANI HOTEL! \n");

   printf("  RAJDHANI THALI SPECIAL            = 140Rs\n");
   printf("  FULL PLATE BIRYANI                = 100Rs\n");
   printf("  CHICKEN MASALA                    = 80Rs\n");
   printf("  EGG CURRY WITH CHAPATI            = 70Rs\n");
   printf("  VEG SPECIAL THALI                 = 100Rs\n");


}
void Soft_Drink ()
{
    printf("   WELCOME TO THE RAJDHANI HOTEL! \n");
   
    printf("   COFFEE              = 50Rs\n");
    printf("   TANDORI TEA         = 40Rs\n");
    printf("    MILK SAKE          = 45Rs\n");
    printf("    COLD COFFEE        = 45Rs\n");
}

int main()
{
    char Choice;
    int Carry;
    int qty,rate,total;
    do{
        printf("Enter your choice\n");
        printf("Enter B for Breakfast\n");
        printf("Enter L FOR Lunch\n");
        printf("Enter D for Dinner\n");
        printf("Enter S for Soft Drink\n");
        printf("For online delivery call 999888777 \n");
        scanf("%c",&Choice);
        switch(Choice){
            case 'B':
            Breakfast();
            break;
            case 'L':
            Lunch();
            break;
            case 'D':
            Dinner();
            break;
            case 'S':
           
            Soft_Drink();
            printf(" YOU HAVE ENTER SOFT DRINK \n COFFEE");
            scanf("%d",&qty);
            rate=50;
            total=qty*rate ;
            printf("\n total amount :%dRs",total);
            break;
            printf("\n YOU HAVE ENTER SOFT DRINK \n TEA");
            scanf("%d",&qty);
            rate=40;
            total=qty*rate ;
            printf("\n total amount :%dRs",total);
            
            break;
            default:
            printf("Invalid Choice");
        }
 
        printf("\n Enter 0 for exit \n 1 for Continue");
        scanf("%d",&Carry);

    }while(Carry!=0);
    return 0;
}