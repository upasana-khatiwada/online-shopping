#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define ENTER 13
#define TAB 9

#define SPACE 32
#define BKSP 8

#define TRUE 1
#define FALSE 0

char *COMPANY_NAME = "ONLINE SHOPPING STORE";

//--------------------------------------function declare---------------------------------------------------
void signup(void);
void login(void);
void inventory();
void customerInventory();
void mainMenu();
int getDiscount(char *couponCode, int totalAmount);
void printBill(int totalItem, float discount, float totalAmount);
void customer();

FILE *fp, *p;

//---------------------------sructure-----------------------------------
struct user
{
    char username[20];
    char password[20];
} s, s1;

struct goods
{
    char name[30];
    char brand[30];
    int quantity;
    int rate;
} item, item1, deletingItem;

struct curr
{
    char name[30];
    char quantity;
} wish, wish1;

struct customer
{
    char name[30];
    char address[30];
} cust, cust1;
struct coupons
{
    char name[30];
    int amount;
} coupon;
// For Storing coupon and it's discount price
struct wishlist
{
    char name[30];
    char quantity;
    float amount;
    float rate;
} listOfWish[20];
// For holding all datas of wishlist to place and print order

//------------------------------===============MAIN FUNCTION-===========================================================
int main()
{
    printf("\t\t\t\t\t\tWelcome to ONLINE SHOPPING MANAGEMMENT SYSTEM\n");
    printf("\t\t\t\t\t\t**************************************************\n");
    printf("\n\nproject by:\n");
    printf("-----------------------------------------------------------------------------------------------------------");
    printf("\nName1:sova kushwaha\t\t\tName2:Rinjha sijapati\t\t\tName3:Upasana khatiwada");
    printf("\nID:5604             \t\t\tID: 5411                 \t\t\tID:   5425                  \n");
    printf("-----------------------------------------------------------------------------------------------------------");
    printf("\n\n\nGuided by:");
    printf("\n----------------------------------------------------------------------------------------------------------");

    printf("\nName:Mr.Prawesh dhungana\nLecturer,BIT Department\nKIST college(purbanchal university)");
    printf("\n-----------------------------------------------------------------------------------------------------------");

    printf("\n\n\n\t Enter any key to continue..................");
    getch();
    system("cls");

    mainMenu();
    return 0;
}

/*-------------===============================================---------------function definations------------------====================================------
===============================================================================================================================================================
========================================================================================================================================*/
void printMainMenu()
{
    system("cls");
    // used to clear screen
    printf("\n\n\n\n");
    printf("\t\t\t  ______             __  __                             ______    __                                         \n");
    printf("\t\t\t /      \\           /  |/  |                           /      \\  /  |                                        \n");
    printf("\t\t\t/$$$$$$  | _______  $$ |$$/  _______    ______        /$$$$$$  |_$$ |_     ______    ______    ______        \n");
    printf("\t\t\t$$ |  $$ |/       \\ $$ |/  |/       \\  /      \\       $$ \\__$$// $$   |   /      \\  /      \\  /      \\       \n");
    printf("\t\t\t$$ |  $$ |$$$$$$$  |$$ |$$ |$$$$$$$  |/$$$$$$  |      $$      \\$$$$$$/   /$$$$$$  |/$$$$$$  |/$$$$$$  |      \n");
    printf("\t\t\t$$ |  $$ |$$ |  $$ |$$ |$$ |$$ |  $$ |$$    $$ |       $$$$$$  | $$ | __ $$ |  $$ |$$ |  $$/ $$    $$ |      \n");
    printf("\t\t\t$$ \\__$$ |$$ |  $$ |$$ |$$ |$$ |  $$ |$$$$$$$$/       /  \\__$$ | $$ |/  |$$ \\__$$ |$$ |      $$$$$$$$/       \n");
    printf("\t\t\t$$    $$/ $$ |  $$ |$$ |$$ |$$ |  $$ |$$       |      $$    $$/  $$  $$/ $$    $$/ $$ |      $$       |      \n");
    printf("\t\t\t $$$$$$/  $$/   $$/ $$/ $$/ $$/   $$/  $$$$$$$/        $$$$$$/    $$$$/   $$$$$$/  $$/        $$$$$$$/    \n");
    printf("\n\n");
    // Generated from Ascii TEXT
    printf("\t\t\t\tWelcome to ONLINE SHOPPING MANAGEMMENT SYSTEM\n");
    printf("\n\t\t\t\t\t==========================");
    printf("\n\t\t\t\t\t||\tMAIN MENU\t||");
    printf("\n\t\t\t\t\t==========================");
    printf("\n\t\t\t\t\t||\t1.Administrator\t||");
    printf("\n\t\t\t\t\t||\t2.Customer\t||");
    printf("\n\t\t\t\t\t||\t3.Exit\t\t||");
    printf("\n\t\t\t\t\t==========================");
    printf("\n\t\t\t\t<press 1 if you are a manager>");
    printf("\n\t\t\t\t<press 2 if you want to visit to our shop>");
}
void mainMenu()
{
    // clearing wishlist for every customer

    int num, choice;

    char password[30];
    printMainMenu();
    printf("\n\n\t\t\t\tENTER YOUR CHOICE\t:-");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        system("cls");
        
        printf("\n\t\t\t\t\t===============================");
        printf("\n\t\t\t\t\t\t1.Administrator");
        printf("\n\t\t\t\t\t===============================");
        printf("\n1.signup");
        printf("\n2.login");
        printf("\n3.exit");
        printf("\n4.Return to Main Menu\n");
        printf("\n \nselect one option \n ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            signup();
        }

        if (choice == 2)
        {
            login();
        }
        if (choice == 4)
        {
            mainMenu();
        }

        break;
    case 2:
    	system("cls");

    printf("\n\t\t\t\t\t===============================");
    printf("\n\t\t\t\t\t\tCUSTOMER");
    printf("\n\t\t\t\t\t===============================");
        customer();

        break;
    case 3:
        exit(0);
        break;
    default:
        printf("\n\t\t\t\t\tENTER A VALID INPUT");
    }
}

void customer()
{
    int num = 0;
    char name[20];
    FILE *custfile, *custfile1;
    
	printf("\n\n========================================================================================================================");
    printf("\n<press 1 if you are visiting for the first time>");
    printf("\n<press 2 if you are not visiting for the first time>");
    
	printf("\n\n========================================================================================================================");
    printf("\n\n Enter here:");
    scanf("%d", &num);
    // If User is for first time that person should login providing username

    if (num == 1)
    {
    	system("cls");
        custfile = fopen("customer.txt", "a+");

        if (custfile == NULL)
        {
            printf("file cant be opened");
            exit(0);
        }
	
        printf("\n\n\t\t\t	PLEASE SIGNUP FIRST\n\t\t\t\t*********************\n\n\t\t\tprovide your name and address here\n");
        
        printf("\n========================================================================================================================");
        printf("\n\nEnter Your Name:    ");
        fflush(stdin);
        gets(cust.name);
        printf("\nEnter Address:    ");
        fflush(stdin);
        gets(cust.address);
        fwrite(&cust, sizeof(cust), 1, custfile);
        printf("customer added");
        fclose(custfile);
        
        customerInventory();
    }

    else if (num == 2)
    {
    label:
        custfile1 = fopen("customer.txt", "rb");
        if (custfile == NULL)
        {
            printf("file cant be opened");
            exit(0);
        }
        printf("\nprovide your name:");
        fflush(stdin);
        gets(name);
        
        fflush(stdin);
        
        rewind(custfile1);
        int matchingFlag = 0;
        // Flag for Checking if username exists or not
        while (fread(&cust1, sizeof(cust1), 1, custfile1))
        {
            if (strcmp(name, cust1.name) == 0)
            {
                printf("\ncustomer matched\n");
                strcpy(cust.name, cust1.name);
                strcpy(cust.address, cust1.address);
                customerInventory();
                break;
                // if User exists just show customer inventory
            }
            else
            {
                matchingFlag = 0;
            }
        }
        if (matchingFlag == 0)
        {
            printf("\n Customer Name didn't match\n please try again!!!!!\n\n");
            getch();
            // if user didn't matched then printing and waiting for key press
            goto label;
        }
        fclose(custfile1);
    }
}

void printInventoryText()
{
    system("cls");
    printf("\n\t\t\t\t\t===============================");
    printf("\n\t\t\t\t\t\tINVENTORY");
    printf("\n\t\t\t\t\t===============================");
    
    printf("\n========================================================================================================================\n");
    printf("\n\t\t1.Add an Entry for Item");
    printf("\n\t\t2.Modify Existing Entry");
    printf("\n\t\t3.Search an Entry");
    printf("\n\t\t4.Listing of all Entries");
    printf("\n\t\t5.Delete an Entry");
    printf("\n\t\t6.Show Bill Transaction/ SALES REPORT ");
    printf("\n\t\t7.Show customers details");
    printf("\n\t\t8.Add Discount / coupon Code");
    printf("\n\t\t9.EXIT");
    printf("\n\t\tm.Go to Main Menu");
    printf("\n========================================================================================================================");
    //     printf("\n\t\t6.Main Menu");
    printf("\n\n\t\tEnter your choice here to perform any operation: ");
}

void printCustomerInventoryText()
{
	system("cls");
	printf("\t\t\t----------------------------------------------");
    printf("\n\t\t\t Hello %s ! welcome to onlinestore.com...", cust.name);
    printf("\n\t\t\t----------------------------------------------");
	
	printf("\n\n\n========================================================================================================================");
    printf("\n\t\t1.Search a product");
    printf("\n\t\t2.Listing of all Products");
    printf("\n\t\t3.Add to Cart");
    printf("\n\t\t4.Show my Cart");
    printf("\n\t\t5.Place Order(you need to add any product to your cart first to place order )");
    printf("\n\t\t6.EXIT");
    printf("\n\t\tm.Return to main menu");
    printf("\n========================================================================================================================");
    

    //     printf("\n\t\t6.Main Menu");
    printf("\n\n\t\tEnter your choice here: ");
}

//----------------------------------------------------------------------------signup- section----------------------------------------------------------------------------

void signup()
{
    int i = 0;
    char c;
    fp = fopen("admins.txt", "a+");

    //	gotoxy(23,5);
    printf("\n\t\t\t\t\t===============================");
    printf("\n\t\t\t\t\t\tSIGNUP PAGE");
    printf("\n\t\t\t\t\t===============================");
    //	gotoxy(23,7);
    
	printf("\n====================================================================================================================");
    printf("\nset Username : ");
    fflush(stdin);

    gets(s.username);
    fflush(stdin);

    //	gotoxy(23,9);
    printf("\nset password : ");
    gets(s.password);
    fflush(stdin);
    //	gotoxy(23,11);
    printf("\npress Enter to continue..............");
    
    printf("\n========================================================================================================================");
    if (getch() == 13)
    {
        fwrite(&s, sizeof(s), 1, fp);
        //		gotoxy(23,13);
        printf("\ninformation saved.............");
    }

    //    fwrite(&s, sizeof(s), 1, fp);
    // printf("\n\t\t\t\t\t\tYou have entered %s as password.", s.password);
    // printf("\n\t\t\t\t\t\tYou have entered %s as username.", s.username);
    printf("\n\t\t\t\t\t\twritten in file successfully");
    
    fclose(fp);

    printf("\n\tplease login now\n");
    login();
}

//------------------------------------------------------------------login section----------------------------------------------------------------------------
void login()

{
    int i = 0;
    char username[20];
    char pass[20];
    char c;
    char chkp;
    char chku;
    system("cls");
    printf("\n\t\t\t\t\t===============================");
    printf("\n\t\t\t\t\t\tLOGIN PAGE");
    printf("\n\t\t\t\t\t===============================");

    p = fopen("admins.txt", "rb");
    printf("\n\n\n========================================================================================================================");

    printf("\nEnter UserName         :");
    fflush(stdin);

    gets(username);
    fflush(stdin);

    printf("\nEnter PassWord         :");
    fflush(stdin);
    char ch1;

    for (i = 0; i < 20; i++)
    {
        ch1 = getch();
        pass[i] = ch1;

        if (ch1 != 13) // 13 is ASCII of Enter key
            printf("*");

        if (ch1 == 13)
            break;
    }

    pass[i] = '\0';
    fflush(stdin);
    printf("\n========================================================================================================================");
    int flag = 0;
    rewind(p);
    while (fread(&s1, sizeof(s1), 1, p))
    {
        // printf("\npassword=%s", s1.password);
        // printf("\nusername=%s", s1.username);

        // printf("\npassword you entered=%s", pass);
        // printf("\nusername=%s", username);

        chku = strcmp(username, s1.username);

        chkp = strcmp(pass, s1.password);

        if (chku == 0 && chkp != 0)
        {
            printf("\nError! password didn't match\nPress any key to try again.");
            getch();
            login();

            break;
        }
        else if (chku != 0 && chkp == 0)
        {
            printf("\nError!Username didn't match\nPress any key to try again.");
            login();
            break;
        }
        else if (chku == 0 && chkp == 0)
        {

            printf("\n Login successful.......................");
            printf("\n\n_Hello %s Welcome  ", s.username);

            flag = 1;
            break;
        }
    }
    // flag here is for checking whole list of adminstrators
    if (flag == 1)
    {
        inventory();
    }
    else if (flag == 0)
    {
        printf("\n\n\t\tUser Credentials didn't match..................\n");
        printf("\t We are giving chance to re-login..................\nPress any key to try again");

        getch();
        login();
    }
    else
    {

        getch();
        login();
    }
    

    fclose(fp);

    getch();
}

//---------------------------------------------------------------------------------inventory section------------------------------------------------------------
void inventory()
{
    char a, i_name[30], m;
    int f = 0, j = 1;

    FILE *file;

flag:
    file = fopen("goods.txt", "r+");
    if (file == NULL)
    {
        file = fopen("goods.txt", "w+");
        if (file == NULL)
        {
            printf("file cannot be created!!!!!!!!!!!!\n");
            exit(0);
        }
    }
    fclose(file);
    //   while (1)

    // {
    printInventoryText();
    fflush(stdin);
    m = getche();
    switch (m)
    {
    case '1':
        file = fopen("goods.txt", "r+");
        fseek(file, 0, SEEK_END);

        a = 'Y';
        while (a == 'Y' || a == 'y')
        {
        x:
            printf("\t\t\t\t\nAdd product\t\t\n");
            printf("\t\t*****************************************************\n");
            printf("\n\nEnter the name of the item:\t");
            gets(i_name);
            rewind(file);
            while (fread(&item, sizeof(item), 1, file) == 1)
            {
                if (strcmp(item.name, i_name) == 0)
                {
                    f = 1;
                    printf("\n\t\tTHIS ITEM ALREADY EXISTS. ENTER ANOTHER ONE");
                    goto x;
                }
            }
            if (f == 0 || fread(&item, sizeof(item), 1, file) == 0)
            {
                fseek(file, 0, SEEK_END);
                strcpy(item.name, i_name);
                fflush(stdin);
                printf("\nEnter the brand of product: ");
                scanf("%s", item.brand);
                fflush(stdin);
                printf("\nEnter the quantity of the Item: ");
                scanf("%d", &item.quantity);
                fflush(stdin);
                printf("\nEnter the rate of Item: ");
                scanf("%d", &item.rate);
                fflush(stdin);
                fwrite(&item, sizeof(item), 1, file);
                printf("\n----------------------------------------------------");
                printf("\nWant to add entry of the another Item(Y/N): ");
                fflush(stdin);
                a = getche();
                if (a == 'n' || a == 'N')
                {
                    fclose(file);
                    inventory();
                }
            }
        }

        break;

    case '2':
        a = 'Y';

        while (a == 'Y' || a == 'y')
        {
            printf("\nEnter the name of the item to modify: ");
            gets(i_name);
            file = fopen("goods.txt", "r+");
            rewind(file);
            FILE *modifiedFile;
            modifiedFile = fopen("temporary.txt", "w");
            while (fread(&item, sizeof(item), 1, file) == 1)
            {

                int cmpFlag = strcmp(item.name, i_name);
                if (cmpFlag == 0)
                {
                    printf("\nEnter the new name of the Item: ");
                    gets(item.name);
                    fflush(stdin);
                    printf("\nEnter the new brand of item: ");
                    scanf("%s", &item.brand);
                    fflush(stdin);
                    printf("\nEnter the new quantity of the Item: ");
                    scanf("%d", &item.quantity);
                    fflush(stdin);
                    printf("\nEnter the new price of One Item: ");
                    scanf("%d", &item.rate);
                    fflush(stdin);
                    fwrite(&item, sizeof(item), 1, modifiedFile);
                }
                else
                {
                    fwrite(&item, sizeof(item), 1, modifiedFile);
                }
            }
            fclose(file);
            fclose(modifiedFile);
            remove("goods.txt");
            rename("temporary.txt", "goods.txt");

            printf("\n----------------------------------------------------");
            printf("\nModify another Record(Y/N): ");
            fflush(stdin);
            a = getche();
            if (a == 'n' || a == 'N')
            {
                fclose(file);
                inventory();
            }
        }
        break;
    case '3':
        file = fopen("goods.txt", "r+");
        a = 'Y';
        while (a == 'Y' || a == 'y')
        {
            printf("\nEnter name of item to search: ");
            gets(i_name);
            rewind(file);
            while (fread(&item, sizeof(item), 1, file) == 1)
            {
                if (strcmp(item.name, i_name) == 0)
                {
                    printf("\nThe Name of the Item: ");
                    puts(item.name);
                    printf("\nThe brand of item: ");
                    puts(item.brand);
                    printf("\nquantity of the Item: %d", item.quantity);
                    printf("\nPrice of Item: %d", item.rate);
                    break;
                }
                else
                {
                    printf("this item doesn't exist..");
                }
            }
            printf("\n----------------------------------------------------");
            printf("\nSearch another Entry(Y/N): ");
            fflush(stdin);
            a = getche();
            if (a == 'n' || a == 'N')
            {
                fclose(file);
                inventory();
            }
        }
        break;
    case '4':
        printf("\nS.No.\t ITEM\t Brand\t quantity\t PRICE\t\t\n");
        printf("-----------------------------------------------------------------------------\n");
        file = fopen("goods.txt", "r+");
        rewind(file);
        // fseek(file,0,SEEK_SET);
        while (fread(&item, sizeof(item), 1, file) == 1)
        {
            printf("%d\t %s\t %s\t %d\t Rs.%d\t\t\n", j, item.name, item.brand, item.quantity, item.rate);
            j++;
        }
        getch();
        fclose(file);
        goto flag;
        break;
    case '5':
    {

        FILE *goodsFile, *fy;
        int x;
        a = 'Y';
        while (a == 'Y' || a == 'y')
        {
            printf("\nEnter the name of the Item to be deleted: ");
            gets(i_name);
            fflush(stdin);
            fy = fopen("temporary.txt", "w+");
            if (fy == NULL)
            {
                printf("Error! file can't  be opened");
                exit(0);
            }
            goodsFile = fopen("goods.txt", "r+");
            while (fread(&item1, sizeof(item1), 1, goodsFile) > 0)
            {
                if (strcmp(item1.name, i_name) != 0)
                {
                    fwrite(&item1, sizeof(item1), 1, fy);
                    
                }
                //                else
                //                {
                //                	continue;
                //
                //                }
            }

            fflush(fy);
            fflush(goodsFile);
            fclose(goodsFile);
            fclose(fy);

            if (remove("goods.txt") == 0)
            {
                printf("\n");
            }
//            else
//            {
//                printf("not deleted");
//            }
            // printf("\n\n\n%d -------------rename", renamed);

            x = rename("temporary.txt", "goods.txt");
//            if (x == 0)
//            {
//                printf("\n\n\n -------------renamed");
//            }
//            else
//            {
//                printf("\n\n\n ------------not renamed");
//            }
			printf("\nThe Record has been Deleted Successfully.");

            // goodsFile = fopen("goods.txt", "r");
            printf("\nDelete another record?(Y/N): ");
            fflush(stdin);

            a = getche();
            if (a == 'n' || a == 'N')
            {
                fclose(file);
                fclose(goodsFile);
                fclose(fy);
                inventory();
            }
        }
        break;
    }

    case '6':
    {
    	system("cls");
        FILE *openFile;
        openFile = fopen("transactions.txt", "r");
        if (openFile = NULL)
        {
            printf("\nWe can't open file correctly!! \n");
            openFile = fopen("transactions.txt", "a");
        }
        char line[500];
        // this is for max text per line
        // This way it reads the file line by line
        printf("\n\nAll Transactions till the date are: \n\n");
        fflush(stdin);
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
            fflush(stdin);
        }
        printf("\n");
        fclose(openFile);
        printf("\nEnter any keys to return to inventory page");

        getch();
        inventory();
        break;
    }
    
    case '7':
    {
        FILE *openFile;
        openFile = fopen("customer.txt", "r");
        if (openFile == NULL)
        {
            printf("\n can't open file");
            exit(0);
        }
        j = 0;
        printf("\n\nS.No\t Customer Name \t Address\n");
        printf("----------------------------------------------");
        while (fread(&cust1, sizeof(cust1), 1, openFile))
        {
            printf("\n%d\t %s\t %s\t \t\t\n", j, cust1.name, cust1.address);
            j++;
        }

        printf("\n\tpress any key to go back to inventory\n");
        getch();

        inventory();
        break;
    }
    case '8':
    {
        printf("\nEnter Coupon To add:  ");
        gets(coupon.name);
        printf("\nEnter Discount for the coupon:  ");
        scanf("%d", &coupon.amount);
        FILE *openCoupon;
        openCoupon = fopen("coupon.txt", "a");
        fwrite(&coupon, sizeof(coupon), 1, openCoupon);
        fclose(openCoupon);
        inventory();
        break;
    }
    case '9':
    {
        fclose(file);

        exit(0);
        break;
    }
    case 'm':
    {
        mainMenu();
        break;
    }
    }
    fclose(file);
    // break;
    //  }
}

void customerInventory()
{
    char a, i_name[30], m;
    int f = 0, j = 1;

    FILE *file, *fy, *readFile;
    system("cls");

flag1:
    file = fopen("goods.txt", "r+");
    if (file == NULL)
    {
        file = fopen("goods.txt", "w+");
        if (file == NULL)
        {
            printf("file cannot be created!!!!!!!!!!!!\n");
            exit(0);
        }
    }
    fclose(file);
    //   while (1)

    // {

    printCustomerInventoryText();
    fflush(stdin);
    m = getche();
    switch (m)
    {
    case '1':
        a = 'Y';
        while (a == 'Y' || a == 'y')
        {
            printf("\nEnter name of item to search: ");
            gets(i_name);
            file = fopen("goods.txt", "r+");
            rewind(file);
            while (fread(&item, sizeof(item), 1, file) == 1)
            {
                if (strcmp(item.name, i_name) == 0)
                {
                    printf("\nThe Name of the Item: ");
                    puts(item.name);
                    printf("\nThe brand of item: ");
                    puts(item.brand);
                    printf("\nquantity of the Item: %d", item.quantity);
                    printf("\nPrice of Item: %d", item.rate);
                }
            }
            printf("\n----------------------------------------------------");
            printf("\nSearch another Entry(Y/N): ");
            fflush(stdin);
            a = getche();
            if (a == 'n' || a == 'N')
            {
                // On pressing N, it reloads customerInventory
                customerInventory();
            }
        }
        break;
    case '2':
        printf("\nS.No.\t ITEM\t Brand\t quantity\t PRICE\t\t\n");
        printf("-----------------------------------------------------------------------------\n");
        file = fopen("goods.txt", "r+");

        rewind(file);
        while (fread(&item, sizeof(item), 1, file) == 1)
        {
            printf("%d\t %s\t %s\t %d\t Rs.%d\t\t\n", j, item.name, item.brand, item.quantity, item.rate);
            j++;
        }
        fclose(file);
        getch();
        goto flag1;
        break;
    case '3':
        a = 'Y';
        while (a == 'Y' || a == 'y')
        {
            int quantity;
            printf("\nEnter the name of the Item to be added: ");
            gets(wish.name);
            printf("\nEnter the quantity of the Item to be added: ");
            fflush(stdin);
            scanf("%d", &wish.quantity);
            char fileName[30] = "";

            strcat(fileName, cust.name);
            strcat(fileName, ".wish");
            fy = fopen(fileName, "a");
            fwrite(&wish, sizeof(wish), 1, fy);

            //            fprintf(fy, "%s \t %d \n", i_name, quantity);
            // in format ITEM_NAME     QUANTITY

            fclose(fy);
            printf("\nAdd another product?(Y/N): ");
            fflush(stdin);
            a = getche();
            if (a == 'N' || a == 'n')
            {
                customerInventory();
            }
        }
        break;
    case '4':
    {

        char fileName[30] = "";
        strcat(fileName, cust.name);
        strcat(fileName, ".wish");
        readFile = fopen(fileName, "r+");
        if (readFile == NULL)
        {
            readFile = fopen(fileName, "a");
        }
        printf("\n\t ITEM\t  quantity\n");
        printf("--------------------------------\n");

        rewind(readFile);
        while (fread(&wish1, sizeof(wish1), 1, readFile) == 1)
        {
            printf("\t%s\t  %d\t \n", wish1.name, wish1.quantity);
        }
        fclose(readFile);

        getch();
        customerInventory();
        break;
    }
    case '5':
    {
    	int currentIndex ;
        int listIndex = 0;
        char couponCode[15];
        int discount = 0;
        float totalAmount = 0;
        char c;
        char fileName[30] = "";

        strcat(fileName, cust.name);
        strcat(fileName, ".wish");
        readFile = fopen(fileName, "r+");

        if (readFile == NULL)
        {
            readFile = fopen(fileName, "a");
        }
        printf("\n ITEM\tQuantity\tRate\tAmount \n");
        printf("------------------------------------------------\n");

        file = fopen("goods.txt", "r+");
        rewind(readFile);
        rewind(file);
        while (fread(&wish1, sizeof(wish1), 1, readFile) == 1)
        {
            // if item is not found skip by saying your item is not found so removing it from list....
            // get the amount of item and save in amount of listOfWish
            int matchingFlag = 0;
            rewind(file);
            while (fread(&item, sizeof(item), 1, file) == 1)
            {
                if (strcmp(item.name, wish1.name) == 0)
                {
                    matchingFlag = 1;
                    // if item is found
                    if (item.quantity >= wish1.quantity)
                    {
                        int priceOfWish = item.rate;
                        listOfWish[listIndex].rate = item.rate;
                        listOfWish[listIndex].amount = wish1.quantity * priceOfWish;
                        // here 20 is obtained from reading file
                        totalAmount += listOfWish[listIndex].amount;
                        strcpy(listOfWish[listIndex].name, wish1.name);
                        listOfWish[listIndex].quantity = wish1.quantity;
                        printf("%s\t%d\t\t%0.2f\t\t %0.2f\n", wish1.name, listOfWish[listIndex].quantity, listOfWish[listIndex].rate, listOfWish[listIndex].amount);
                        listIndex++;
                        // Decrease quantity in goods.txt
                    }
                    else
                    {
                        printf("\n\nITEM %s is not in STOCK, so we are skipping it.\n\n", item.name);
                        getch();
                    }
                    break;
                }
                else
                {
                    matchingFlag = 0;
                }
            }
            if (matchingFlag == 0)
            {
                printf("\n\nITEM %s is not FOUND IN STORE, so we are skipping it.\n\n", wish1.name);
                getch();
            }
            matchingFlag = 0;
        }
        fclose(readFile);
        fflush(file);
        fclose(file);

        for ( currentIndex = 0; currentIndex < listIndex; currentIndex++)
        {
            FILE *openGoodsFile;
            FILE *modifiedFile;
            modifiedFile = fopen("temporary.txt", "w");
            openGoodsFile = fopen("goods.txt", "r+");
            while (fread(&item, sizeof(item), 1, openGoodsFile) == 1)
            {

                if (strcmp(item.name, listOfWish[currentIndex].name) == 0)
                {
                    item.quantity = item.quantity - listOfWish[currentIndex].quantity;
                    fwrite(&item, sizeof(item), 1, modifiedFile);
                }
                else
                {
                    fwrite(&item, sizeof(item), 1, modifiedFile);
                }
            }
            fflush(openGoodsFile);
            fflush(modifiedFile);
            fclose(openGoodsFile);
            fclose(modifiedFile);
            remove("goods.txt");
            rename("temporary.txt", "goods.txt");
        }

        printf("\n\nDo you have coupon code? (Y/N)");
        c = getche();
        if (c == 'y' || c == 'Y')
        {
            printf("\n\n\tEnter coupon code:   ");
            scanf("%s", &couponCode);
        }
        // Here check coupon code
        discount = getDiscount(couponCode, totalAmount);

        printBill(listIndex, discount, totalAmount);

        break;
    }
    case '6':
    {
        fclose(file);
        exit(0);
    }
    case 'm':
        mainMenu();
        break;
    }
    fclose(file);
}
int getDiscount(char *couponCode, int totalAmount)
{
    int totalDiscount = 0;
    int couponDiscount = 0;
    int priceDiscount = 0;
    FILE *readFile;
    readFile = fopen("coupon.txt", "r");
    if (readFile == NULL)
    {
        readFile = fopen("coupon.txt", "a");
    }
    while (fread(&coupon, sizeof(coupon), 1, readFile))
    {
        if (strcmp(coupon.name, couponCode) == 0)
        {
            couponDiscount = coupon.amount;
            break;
        }
    }

    if (couponDiscount > 0)
    {
        printf("\n\n\t\tEntered coupon code is valid!!!\n\n");
        getch();
    }
    else
    {
        printf("\n\n\t\tEntered coupon code is invalid!!!\n\n");
        getch();
    }

    // for discount based on amount
    if (totalAmount >= 500000)
    {
        priceDiscount = 25;
    }
    else if (totalAmount >= 250000)
    {
        priceDiscount = 20;
    }
    else if (totalAmount >= 100000)
    {
        priceDiscount = 13;
    }
    else if (totalAmount >= 50000)
    {
        priceDiscount = 10;
    }
    else if (totalAmount >= 5000)
    {
        priceDiscount = 3;
    }

    if (couponDiscount > 0)
    {
        printf("\nAdditional Discount of %d percent for applying coupon code '%s' \n", couponDiscount, couponCode);
    }

    if (priceDiscount > 0)
    {
        printf("\nWe are giving additional discount of %d percent for buying products worth: RS.%d ", priceDiscount, totalAmount);
    }
    totalDiscount = couponDiscount + priceDiscount;
    return totalDiscount;
}

void printBill(int totalItem, float discount, float totalAmount)
{
    int i = 0;
    FILE *file;
    file = fopen("transactions.txt", "a");
    float finalAmount = totalAmount - (totalAmount * discount) / 100.0;
    float vatAmount = (finalAmount * 13.0) / 100;
    finalAmount = finalAmount + vatAmount;
    printf("\n\n|------------------------------------------------------------------------|\n");
    fprintf(file, "\n\n|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    fprintf(file, "|                                                                        |\n");
    printf("|\t                   %s                                  |\n", COMPANY_NAME);
    fprintf(file, "|\t                   %s                                  |\n", COMPANY_NAME);
    printf("|                                                                        |\n");
    fprintf(file, "|                                                                        |\n");
    printf("|  Kathmandu, Nepal                                                      |\n");
    fprintf(file, "|  Kathmandu, Nepal                                                      |\n");
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");
    printf("  %s\n", cust.name);
    fprintf(file, "  %s\n", cust.name);
    printf(" %s\n", cust.address);
    fprintf(file, " %s\n", cust.address);
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");
    printf("|- Item      -|-    Quantity     -|-    Rate     -|-   Amount           -|\n");
    fprintf(file, "|- Item      -|-    Quantity     -|-    Rate     -|-   Amount           -|\n");
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");

    for (i = 0; i < totalItem; i++)
    {
        printf("  %s \t\t %d \t\t %0.2f \t\t %0.2f \n", listOfWish[i].name, listOfWish[i].quantity, listOfWish[i].rate, listOfWish[i].amount);
        fprintf(file, "  %s \t\t   %d \t\t\t %0.2f \t\t %0.2f \n", listOfWish[i].name, listOfWish[i].quantity, listOfWish[i].rate, listOfWish[i].amount);
    }
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");
    printf("|-\t\tTotal Amt:\t %0.2f   \n", totalAmount);
    fprintf(file, "|-\t\tTotal Amt:\t %0.2f   \n", totalAmount);
    printf("|-\t\tDiscount:\t %0.2f\%\n", discount);
    fprintf(file, "|-\t\tDiscount:\t %0.2f\%\n", discount);
    printf("|-\t\tVAT Amt:\t %0.2f\n", vatAmount);
    fprintf(file, "|-\t\tVAT Amt:\t %0.2f\n", vatAmount);
    printf("|-\t\tGrand Total:\tRS.%0.2f  \n", finalAmount);
    fprintf(file, "|-\t\tGrand Total:\tRS.%0.2f  \n", finalAmount);
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    fprintf(file, "|                                                                        |\n");
    printf("|\t                   Thank You for visiting us!                    |\n");
    fprintf(file, "|\t                   Thank You for visiting us!                    |\n");
    printf("|                                                                        |\n");
    fprintf(file, "|                                                                        |\n");
    printf("|------------------------------------------------------------------------|\n");
    fprintf(file, "|------------------------------------------------------------------------|\n");
    fprintf(file, "\n\n####################################################################################################################################\n");
    printf("\n\n\n");
    fprintf(file, "\n\n\n");

    FILE *wishFile;
    char fileName[30] = "";

    strcat(fileName, cust.name);
    strcat(fileName, ".wish");
    wishFile = fopen(fileName, "w");
    fclose(wishFile);
    fclose(file);

    printf("\n\nKEEP YOUR BILL\n");
    printf("We are taking you back to store....\n");
    getch();

    customerInventory();
}

/*
MODIFY
MODIFY QUANTITY AFTER ORDERING on line 664

FOR decreasing quantity
    READ QUANTITY
    Subtract quantity if it is greater than existing quantity
    Write data with new quantity

*/
