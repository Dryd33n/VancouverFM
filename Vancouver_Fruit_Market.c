/*
                                                             ____                           __  ___                           __
\ \ / /  __ _   _ _    __   ___   _  _  __ __  ___   _ _    | __|  _ _   _  _  (_) | |_    |  \/  |  __ _   _ _  | |__  ___  | |_
 \ V /  / _` | | ' \  / _| / _ \ | || | \ V / / -_) | '_|   | _|  | '_| | || | | | |  _|   | |\/| | / _` | | '_| | / / / -_) |  _|
  \_/   \__,_| |_||_| \__| \___/  \_,_|  \_/  \___| |_|     |_|   |_|    \_,_| |_|  \__|   |_|  |_| \__,_| |_|   |_\_\ \___|  \__|

*/

#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char nah[100];
char pbefore[3];
char pname[30];
int choice;
int daysp;//the amount of days the player will play
int daysplayed = 1;//the amount of days currently played
int movecounter;
int buychoice;
float buyamount;
int buyconfirm;
float currentbal = 5000;//player balance
float previbal = 5000;
float purchaseprice;//the price of the current supposed purchase
float fpeak = 0;//defines weather there is a current peak in one of the fruits
float mangop = 1.67;//price of one mango
float strawberryp = 5.97;//price of one lbs of strawberrys
float applep = 0.9;//price of one apple
float bananap = 0.3;//price of one banana
float grapep = 2.04;//price of one bag of grapes
float kiwip= 0.87;//price modifier of one kiwi
float mangom = 1.67;//price modifier of one mango
float strawberrym = 5.97;//price modifier of one lbs of strawberrys
float applem = 0.9;//price modifier of one apple
float bananam = 0.3;//price modifier of one banana
float grapem = 2.04;//price modifier of one bag of grapes
float kiwim = 0.87;//price modifier of one kiwi
float mangoi = 0;
float strawberryi = 0;
float applei = 0;
float banani = 0;
float grapei = 0;
float kiwii= 0;
float pmangoi = 0;
float pstrawberryi = 0;
float papplei = 0;
float pbanani = 0;
float pgrapei = 0;
float pkiwii= 0;
int mangob;
int strawberryb;
int appleb;
int bananab;
int grapeb;
int kiwib;
float a = 0.5;//for generating random float
float finalspike;//used to determine the finals size of the spike
int fruitspike;//determine what fruit has the spike
int spikepos;
float randomeffect;//determine whether the spike is positive or negative
float b = 0.2;//for generating random float 2
float pricevar;//determins the minor price fluctuation
//all prices from walmart.ca

void clearpurchase()
{
  buychoice = 0;
  purchaseprice = 0;
  buyamount = 0;
  choice = 0;
}


int main(int argc, char const *argv[])
{
    printf("Vancouver Fruit Market \n-A .exe Production");//Show title
    sleep(2); //Wait 2 secs before clearing
    system("cls"); //Ignore Warning & Command to Clear Screen
    printf("Have you played Vancouver Fruit Market Before\ny\nn\n\n");
    if(getchar() == 'n')
    {
      printf("\nWelcome to Vancouver Fruit Market\n");
      printf("The aim of this games it to get as rich as possible!\n");
      printf("You will achieve this by buying, selling and trading fruit.\n");
      printf("Prices fluctuate so remember to play smart!\n");
      printf("In case you get los youcan always call for help by typing in chat 'help'\n");
      printf("\n\nPress Any Key To Continue...\n");
      getch();//waits for user input
    }
    system("cls");//Clear screen for the second time to wipe potential instructions
    printf("Welcome to Vancouver Fruit Market, what is your name?\n");
    scanf("%s", &pname);
    system("cls");//clear screen
    printf("Hi %s, how many days do you want to play for?\n",pname);
    scanf("%d",&daysp);
    system("cls");
    printf("Let's Begin\n");
    sleep(1);
    printf("You will start with 5000$\n");
    sleep(1);
    system("cls");
    /*
       __  __       _                                        _                _
     |  \/  |     (_)                                      | |              (_)
    | \  / | __ _ _ _ __     __ _  __ _ _ __ ___   ___    | |__   ___  __ _ _ _ __
   | |\/| |/ _` | | '_ \   / _` |/ _` | '_ ` _ \ / _ \   | '_ \ / _ \/ _` | | '_ \
  | |  | | (_| | | | | | | (_| | (_| | | | | | |  __/   | |_) |  __/ (_| | | | | |
 |_|  |_|\__,_|_|_| |_|  \__, |\__,_|_| |_| |_|\___|   |_.__/ \___|\__, |_|_| |_|
                          __/ |                                   __/ |
                         |___/                                   |___/
    */
    while (daysp + 1 > daysplayed)//check to see if current day is equal to the amount of days wanted to play
    {
      srand((unsigned int)time(NULL));//initiates the seed for rand()

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      mangom = mangop * pricevar ;
      pricevar = 0;

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      strawberrym = strawberryp * pricevar ;
      pricevar = 0;

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      applem = applep * pricevar ;
      pricevar = 0;

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      bananam = bananap * pricevar ;
      pricevar = 0;

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      grapem = grapep * pricevar ;
      pricevar = 0;

      pricevar = (float)rand()/(float)(RAND_MAX) * b + 0.9;//gives effect of slight price randomization
      kiwim = kiwip * pricevar ;
      pricevar = 0;

      int spikechance = rand() % 2;//determines wether there is a spike in a price
      //printf("Spike Chance Number: %d\n",spikechance );//USE FOR DEBUG ONLY!!!
      if( spikechance == 1)
      {
        spikepos = rand() % 3;
        if (spikepos == 1)
        {
          //printf("Spike Pos=%d\n",spikepos);//COMENT!!! USED FOR DEBUG
          randomeffect = (float)rand()/(float)(RAND_MAX) * a + 1.4;//positive boost, negative boost would be + 0.4
          //printf("Random Effect = %f\n",randomeffect );//COMMENT LATER!!! USED FOR DEBUG
          //randomeffect = floor(100*randomeffect)/100;
        }
        else
        {
          //printf("Spike Pos=%d\n",spikepos);//COMENT!!! USED FOR DEBUG
          randomeffect = (float)rand()/(float)(RAND_MAX) * a + 0.4;//negative boost
          //printf("Random Effect = %f\n",randomeffect );//COMMENT LATER!!! USED FOR DEBUG
          //randomeffect = floor(100*randomeffect)/100;
        }
      fruitspike = rand() % 6;
      //printf("Fruit spike = %d\n",fruitspike);//USE FOR DEBUG ONLY!!!
      switch (fruitspike)
      {
          case 0:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Mango has drastically increased by %.0f percent!\n",randomeffect * 100);
            mangom = mangop * randomeffect;
            printf("The current price of Mango now sits at %0.2f tommorow the price will return to usual so act fast!\n",mangom);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Mango has drastically decreased by %.0f percent!\n",randomeffect * 100);
            mangom = mangop * randomeffect;
            printf("The current price of Mango now sits at %0.2f tommorow the price will return to usual so act fast!\n",mangom);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          case 1:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Strawberrys has drastically increased by %.0f percent!\n",randomeffect * 100);
            strawberrym = strawberryp * randomeffect;
            printf("The current price of Strawberrys now sits at %0.2f tommorow the price will return to usual so act fast!\n",strawberrym);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Strawberrys has drastically decreased by %.0f percent!\n",randomeffect * 100);
            strawberrym = strawberryp * randomeffect;
            printf("The current price of Strawberrys now sits at %0.2f tommorow the price will return to usual so act fast!\n",strawberrym);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          case 2:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Apples has drastically increased by %.0f percent!\n",randomeffect * 100);
            applem = applep * randomeffect;
            printf("The current price of Apples now sits at %0.2f tommorow the price will return to usual so act fast!\n",applem);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Apples has drastically decreased by %.0f percent!\n",randomeffect * 100);
            applem = applep * randomeffect;
            printf("The current price of Apples now sits at %0.2f tommorow the price will return to usual so act fast!\n",applem);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          case 3:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Bananas has drastically increased by %.0f percent!\n",randomeffect * 100);
            bananam = bananap * randomeffect;
            printf("The current price of Bananas now sits at %0.2f tommorow the price will return to usual so act fast!\n",bananam);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Bananas has drastically decreased by %.0f percent!\n",randomeffect * 100);
            bananam = bananap * randomeffect;
            printf("The current price of Bananas now sits at %0.2f tommorow the price will return to usual so act fast!\n",bananam);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          case 4:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Grapes has drastically increased by %.0f percent!\n",randomeffect * 100);
            grapem = grapep * randomeffect;
            printf("The current price of Grapes now sits at %0.2f tommorow the price will return to usual so act fast!\n",grapem);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Grapes has drastically decreased by %.0f percent!\n",randomeffect * 100);
            grapem = grapep * randomeffect;
            printf("The current price of Grapes now sits at %0.2f tommorow the price will return to usual so act fast!\n",grapem);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          case 5:
          if (spikepos == 1)
          {
            printf("Hello! It seems that the price of Kiwis has drastically increased by %.0f percent!\n",randomeffect);
            kiwim = kiwip * randomeffect;
            printf("The current price of Kiwi now sits at %0.2f tommorow the price will return to usual so act fast!\n",kiwim);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          else
          {
            printf("Hello! It seems that the price of Kiwis has drastically decreased by %.0f percent!\n",randomeffect );
            kiwim = kiwip * randomeffect;
            printf("The current price of Kiwis now sits at %0.2f tommorow the price will return to usual so act fast!\n",kiwim);
            printf("\nPress any key to continue...\n");
            getch();
            goto looptop;
            system ("cls");
          }
          break;

          default:
          printf("Ya done fucked it\n\n");
          break;

      }//contains the entire switch statement that shows the player the spike has happened
      }
      else
      {
        goto looptop;
      }
      looptop:
        mangob = (float)currentbal / (float)mangom;
        strawberryb = (float)currentbal / (float)strawberrym;
        appleb = (float)currentbal / (float)applem;
        bananab = (float)currentbal / (float)bananam;
        grapeb = (float)currentbal / (float)grapem;
        kiwib = (float)currentbal / (float)kiwim;


        int waketime = rand() % 50;
        printf("Day %d\n8:%d\n",daysplayed,waketime + 10);
        printf("What would you like to do today?\n\nSleep(1)\nBuy(2)\nSell(3)\nView Prices(4)\nView Inventory(5)\nView Balance(6)\nQuit(7)\n");
        scanf("%d",&choice);
        choicetop:
        switch (choice)
{
case 1://start of sleep
          system("cls");
          printf("You went to bed...\n");
          sleep (1);
          system("cls");
          goto choicebottom;
break;//end of sleep

case 2://start of buy
          system("cls");
          if (movecounter >= 3 )//limits the amount of moves
            {
              printf("Sorry! You've done too many things today, you should sleep through the night... \n");
              goto looptop;
            }
            choicebuy:
            printf("What do you want to purchase \n");
            printf("Mangos: %0.2f$. You can buy %d (1)\n",mangom,mangob);
            printf("Strawberry: %0.2f$. You can buy %d (2)\n",strawberrym,strawberryb);
            printf("Apple: %0.2f$. You can buy %d (3)\n",applem,appleb);
            printf("Banana: %0.2f$. You can buy %d (4)\n",bananam,bananab);
            printf("Grape: %0.2f$. You can buy %d (5)\n",grapem,grapeb);
            printf("Kiwi: %0.2f$. You can buy %d (6)\n",kiwim,kiwib);
            printf("Back (7)\n");
            scanf("%d",&buychoice);
            switch (buychoice)
            {
            case 1:
              system("cls");
              printf("How many Mangos do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * mangom;//calculates the price of the mangos X mango current price.

              if(purchaseprice > currentbal){
              printf("Sorry, you do not have the required funds to complete this transaction.\n");
              printf("Press Any key to continue");
              getch();
              system("cls");
              goto choicebuy;
            }

            printf("Are you sure you would like to buy %0.2f Mangos for %0.2f(y or n)\n\n",buyamount,purchaseprice);

            if(getch() == 'y')
            {
              mangoi = mangoi + buyamount;
              system("cls");
              currentbal = previbal - purchaseprice;//subtracts money from balance
              previbal = currentbal;//sets previous balance to current balance
              printf(" Purchase Confirmed!\n\n%0.2f Mangos Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.0f Mangos in inventory",buyamount,purchaseprice,currentbal,mangoi);
              printf("\n\nPress any key to Continue...\n");
              getch();
              system("cls");
              movecounter ++;
              clearpurchase();
              goto looptop;
            }
            else
            {
              goto choicebuy;//goes back to top of purchase menu
              system("cls");
            }
          break;

          case 2:
              system("cls");
              printf("How many Strawberrys do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * strawberrym;//calculates the price of the mangos X mango current price.
              if(purchaseprice > currentbal)
              {
                printf("Sorry, you do not have the required funds to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicebuy;
              }
              printf("Are you sure you would like to buy %0.2f Strawberrys for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                  strawberryi = strawberryi + buyamount;
                  system("cls");
                  currentbal = previbal - purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Strawberrys Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.0f Strawberrys in inventory",buyamount,purchaseprice,currentbal,strawberryi);
                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
              }
              else
              {
                  goto choicebuy;//goes back to top of purchase menu
                  system("cls");
              }
            break;

            case 3:
              system("cls");
              printf("How many Apples do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * applem;//calculates the price of the mangos X mango current price.
              if(purchaseprice > currentbal)
              {
                printf("Sorry, you do not have the required funds to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicebuy;
              }
              printf("Are you sure you would like to buy %0.2f Apples for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                  applei = applei + buyamount;
                  system("cls");
                  currentbal = previbal - purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Apples Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.0f Apples in inventory",buyamount,purchaseprice,currentbal,applei);
                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
              }
              else
              {
                  goto choicebuy;//goes back to top of purchase menu
                  system("cls");
              }
            break;

            case 4:
              system("cls");
              printf("How many Bananas do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * bananam;//calculates the price of the mangos X mango current price.
              if(purchaseprice > currentbal)
              {
                printf("Sorry, you do not have the required funds to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicebuy;
              }
              printf("Are you sure you would like to buy %0.2f Bananas for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                system("cls");
                banani = banani + buyamount;
                currentbal = previbal - purchaseprice;//subtracts money from balance
                previbal = currentbal;//sets previous balance to current balance
                printf(" Purchase Confirmed!\n\n%0.2f Bananas Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.02f Bananas in inventory",buyamount,purchaseprice,currentbal,banani);
                printf("\n\nPress any key to Continue...\n");
                getch();
                system("cls");
                movecounter ++;
                clearpurchase();
                goto looptop;
              }
                else
              {
                goto choicebuy;//goes back to top of purchase menu
                system("cls");
              }
            break;

            case 5:
              system("cls");
              printf("How many Grapes do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * grapem;//calculates the price of the mangos X mango current price.
              if(purchaseprice > currentbal)
              {
                printf("Sorry, you do not have the required funds to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicebuy;
              }
              printf("Are you sure you would like to buy %0.2f Grapes for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                system("cls");
                grapei = grapei + buyamount;
                currentbal = previbal - purchaseprice;//subtracts money from balance
                previbal = currentbal;//sets previous balance to current balance
                printf(" Purchase Confirmed!\n\n%0.2f Grapes Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.0f Grapes in inventory\n",buyamount,purchaseprice,currentbal,grapei);
                printf("\n\nPress any key to Continue...\n");
                getch();
                system("cls");
                movecounter ++;
                clearpurchase();
                goto looptop;
              }
                else
              {
                goto choicebuy;//goes back to top of purchase menu
                system("cls");
              }
            break;

            case 6:
              system("cls");
              printf("How many Kiwis do you wish to buy\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * kiwim;//calculates the price of the mangos X mango current price.
              if(purchaseprice > currentbal)
              {
                printf("Sorry, you do not have the required funds to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicebuy;
              }
              printf("Are you sure you would like to buy %0.2f Kiwis for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                kiwii = kiwii + buyamount;
                system("cls");
                currentbal = previbal - purchaseprice;//subtracts money from balance
                previbal = currentbal;//sets previous balance to current balance
                printf(" Purchase Confirmed!\n\n%0.2f Kiwis Purchased\n%0.2f$ Removed from your balance.\nCurrent Balance:%0.2f\n%.0f Kiwis in inventory\n",buyamount,purchaseprice,currentbal,kiwii);
                printf("\n\nPress any key to Continue...\n");
                getch();
                system("cls");
                movecounter ++;
                clearpurchase();
                goto looptop;
              }
              else
              {
                goto choicebuy;//goes back to top of purchase menu
                system("cls");
              }
            break;

            case 7:
              system("cls");
              goto looptop;
            break;

            default:
              printf("Sorry, that is not a valid choice.\n");
              sleep(1);
              goto looptop;
            break;
          }//end of buy switch statemt


break;//end of buy

case 3://start of sell
            system("cls");
            if (movecounter >= 3 )//limits the amount of moves
              {
                printf("Sorry! You've done too many things today, you should sleep through the night... \n");
                goto looptop;
              }
              choicesell:
            printf("What do you want to sell?\n");
            printf("Mangos: %0.2f$. You have %.0f (1)\n",mangom,mangoi );
            printf("Strawberry: %0.2f$. You have %.0f (2)\n",strawberrym,strawberryi );
            printf("Apple: %0.2f$. You have %.0f (3)\n",applem,applei );
            printf("Banana: %0.2f$. You have %.0f (4)\n",bananam,banani );
            printf("Grape: %0.2f$. You have %.0f (5)\n",grapem,grapei );
            printf("Kiwi: %0.2f$. You have %.0f (6)\n",kiwim,kiwii );
            printf("Back (7)\n");
            scanf("%d",&buychoice);
            switch (buychoice) {
            case 1:
              system("cls");
              printf("How many Mangos do you wish to sell\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * mangom;//calculates the price of the mangos X mango current price.

              if(mangoi < buyamount)
              {
                printf("Sorry, you do not have the required mango to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicesell;
              }
              printf("Are you sure you would like to Sell %0.2f Mangos for %0.2f(y or n)\n\n",buyamount,purchaseprice);
              if(getch() == 'y')
              {
                  mangoi = mangoi - buyamount;
                  system("cls");
                  currentbal = previbal + purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Mangos Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Mangos in inventory",buyamount,purchaseprice,currentbal, mangoi);


                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
                }
                  else
                {
                  system("cls");
                  goto choicesell;//goes back to top of purchase menu
                }

              break;

              case 2:
                system("cls");
                printf("How many Strawberrys do you wish to sell\n");
                scanf("%f",&buyamount);
                purchaseprice = buyamount * strawberrym;//calculates the price of the mangos X mango current price.
                if(strawberryi < buyamount)
                {
                  printf("Sorry, you do not have the required Strawberrys to complete this transaction.\n");
                  printf("Press Any key to continue");
                  getch();
                  system("cls");
                  goto choicesell;
                }
                printf("Are you sure you would like to Sell %0.2f Strawberrys for %0.2f(y or n)\n\n",buyamount,purchaseprice);
                if(getch() == 'y')
                {
                  strawberryi = strawberryi - buyamount;
                  system("cls");
                  currentbal = previbal + purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Strawberrys Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Strawberrys in inventory",buyamount,purchaseprice,currentbal, strawberryi);
                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
                }
                else
                {
                  system("cls");
                  goto choicesell;//goes back to top of purchase menu
                }

              break;

              case 3:
              system("cls");
              printf("How many Apples do you wish to sell\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * applem;//calculates the price of the mangos X mango current price.

              if(applei < buyamount){
              printf("Sorry, you do not have the required Apples to complete this transaction.\n");
              printf("Press Any key to continue");
              getch();
              system("cls");
              goto choicesell;
              }

              printf("Are you sure you would like to Sell %0.2f Apples for %0.2f(y or n)\n\n",buyamount,purchaseprice);

              if(getch() == 'y')
              {//scans for n || if n is pressed go back to top
                  applei = applei - buyamount;
                  system("cls");
                  currentbal = previbal + purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Apples Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Apples in inventory",buyamount,purchaseprice,currentbal, applei);


                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
              }
              else
              {
                  system("cls");
                  goto choicesell;//goes back to top of purchase menu
              }

          break;

          case 4:
              system("cls");
              printf("How many Bananas do you wish to sell\n");
              scanf("%f",&buyamount);
              purchaseprice = buyamount * bananam;//calculates the price of the mangos X mango current price.
              if(banani < buyamount)
              {
                printf("Sorry, you do not have the required Bananas to complete this transaction.\n");
                printf("Press Any key to continue");
                getch();
                system("cls");
                goto choicesell;
              }
              printf("Are you sure you would like to Sell %0.2f Bananas for %0.2f(y or n)\n\n",buyamount,purchaseprice);

              if(getch() == 'y'){//scans for n || if n is pressed go back to top
                  banani = banani - buyamount;
                  system("cls");
                  currentbal = previbal + purchaseprice;//subtracts money from balance
                  previbal = currentbal;//sets previous balance to current balance
                  printf(" Purchase Confirmed!\n\n%0.2f Bananas Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Bananas in inventory",buyamount,purchaseprice,currentbal, banani);


                  printf("\n\nPress any key to Continue...\n");
                  getch();
                  system("cls");
                  movecounter ++;
                  clearpurchase();
                  goto looptop;
                }
                  else
                {
                  system("cls");
                  goto choicesell;//goes back to top of purchase menu
                }
                break;


                case 5:
                  system("cls");
                  printf("How many Grapes do you wish to sell\n");
                  scanf("%f",&buyamount);
                  purchaseprice = buyamount * grapem;//calculates the price of the mangos X mango current price.
                  if(grapei < buyamount)
                  {
                    printf("Sorry, you do not have the required Grapes to complete this transaction.\n");
                    printf("Press Any key to continue");
                    getch();
                    system("cls");
                    goto choicesell;
                  }
                  printf("Are you sure you would like to Sell %0.2f Grapes for %0.2f(y or n)\n\n",buyamount,purchaseprice);
                  if(getch() == 'y')
                  {
                      grapei = grapei - buyamount;
                      system("cls");
                      currentbal = previbal + purchaseprice;//subtracts money from balance
                      previbal = currentbal;//sets previous balance to current balance
                      printf(" Purchase Confirmed!\n\n%0.2f Grapes Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Grapes in inventory",buyamount,purchaseprice,currentbal, grapei);
                      printf("\n\nPress any key to Continue...\n");
                      getch();
                      system("cls");
                      movecounter ++;
                      clearpurchase();
                      goto looptop;
                    }
                    else
                    {
                      system("cls");
                      goto choicesell;//goes back to top of purchase menu
                    }
                break;

                case 6:
                  system("cls");
                  printf("How many Kiwis do you wish to sell\n");
                  scanf("%f",&buyamount);
                  purchaseprice = buyamount * kiwim;//calculates the price of the mangos X mango current price.
                  if(kiwii < buyamount)
                  {
                    printf("Sorry, you do not have the required Kiwis to complete this transaction.\n");
                    printf("Press Any key to continue");
                    getch();
                    system("cls");
                    goto choicesell;
                  }
                  printf("Are you sure you would like to Sell %0.2f Kiwis for %0.2f(y or n)\n\n",buyamount,purchaseprice);
                  if(getch() == 'y')
                  {
                      kiwii = kiwii - buyamount;
                      system("cls");
                      currentbal = previbal + purchaseprice;//subtracts money from balance
                      previbal = currentbal;//sets previous balance to current balance
                      printf(" Purchase Confirmed!\n\n%0.2f Kiwis Sold\n%0.2f$ Added to your balance.\nCurrent Balance:%0.2f\n%.0f Kiwis in inventory",buyamount,purchaseprice,currentbal, kiwii);
                      printf("\n\nPress any key to Continue...\n");
                      getch();
                      system("cls");
                      movecounter ++;
                      clearpurchase();
                      goto looptop;
                    }
                    else
                    {
                      system("cls");
                      goto choicesell;//goes back to top of purchase menu
                    }
                break;

                case 7:
                  system("cls");
                  goto looptop;
                break;

                default:
                  printf("That is not a valid choice!\n");
                  sleep(1);
                  system ("cls");
                  goto choicesell;
                break;
              }//end of sell switch statement
break;//end of sell

case 4://start of view Prices
  system("cls");
  printf("The current prices for selling and buying fruit are at\n\n");
  printf("Mango: %0.2f$\n",mangom);
  printf("Strawberry: %0.2f$\n",strawberrym);
  printf("Apple: %0.2f$\n",applem);
  printf("Banana: %0.2f$\n",bananam);
  printf("Grape: %0.2f$\n",grapem);
  printf("Kiwi: %0.2f$\n",kiwim);
  printf("\nPress any key to continue...\n");
  getch();
  system("cls");
  goto looptop;
break;//end of view prices

case 5://start of view inventory
  system("cls");
  printf("In your invetory you have:\n\n");
  printf("Mango: %0.2f\n",mangoi);
  printf("Strawberry: %0.2f\n",strawberryi);
  printf("Apple: %0.2f\n",applei);
  printf("Banana: %0.2f\n",banani);
  printf("Grape: %0.2f\n",grapei);
  printf("Kiwi: %0.2f\n",kiwii);
  printf("\nPress any key to continue...\n");
  getch();
  system("cls");
  goto looptop;
break;//end of view inventory

case 6://start of view Balance
  system("cls");
  printf("In your bank you currently have:\n\n");
  printf("%0.2f\n",currentbal);
  printf("\n\nPress any key to continue\n");
  getch();
  goto looptop;
break;

case 7://start of quit
printf(" Are you sure you want to quit, progress will not be saved!(y or n)\n");
if (getch() == 'y')
{
  printf("Goodbye...\n");
  sleep(1);
  return 0;
}
else
{
  system("cls");
  goto looptop;
}
break;//endofquit

default:
  system("cls");
  printf("Sorry, that is not a valid choice!\n");
  goto looptop;//start of default
break;//end of default

}//end of switch



        choicebottom:
        movecounter = 0;
      daysplayed ++;
      system("cls");
      sleep(1);
      printf("The night passes...\n");
      sleep(1);
      system("cls");
      sleep(1);

  }//end of loop

  return 0;
}
