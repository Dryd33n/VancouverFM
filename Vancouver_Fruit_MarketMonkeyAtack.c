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
int secchoice;
int securitylvl;
int stealamnt;
int taxchoice;
int attackeffectiveness;
float taxamount;
int taxfraud;
float fruitsold;
float fruitpurchased;
int attackmove;//determines what the player will do about the monkeys
int attackpick;//used to determine the fruit that will be attacked by the monkeys
int monkeyattackcheck;//used to determin wether a monkey attack will take place or not
int monkeyattack;//used to determine weather a monkey attack is in progress
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
  int mangoia = (float)mangoi;
  int strawberryia = (float)strawberryi;
  int appleia = (float)applei;
  int bananaia = (float)banani;
  int grapeia = (float)grapei;
  int kiwiia = (float)kiwii;
}

void gamestats()
{
printf("You play for %d Days\n",daysplayed);
printf("You ended with %0.2f$\n",currentbal);
printf("You purchased a total of %.0f Fruit.\n",fruitpurchased);
printf("You sold a total of %.0f Fruit\n",fruitsold);
printf("You finished with a total of %.0f fruit in your inventory\n",mangoi + strawberryi + applei + banani + grapei + kiwii);
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
      if(taxfraud == 1)
      {
      printf("The government is at your door\nYou're being taken to jail for tax fraud...");
      sleep(2);
      system("cls");
      printf(". . .\n");
      sleep(1);
      system("cls");
      printf("GAME OVER\n\n");
      gamestats();

      return 0;
      }


      srand((unsigned int)time(NULL));//initiates the seed for rand()

      int mangoia = (float)mangoi;
      int strawberryia = (float)strawberryi;
      int appleia = (float)applei;
      int bananaia = (float)banani;
      int grapeia = (float)grapei;
      int kiwiia = (float)kiwii;
      int attackchance = securitylvl * 10 + 5;
      //printf("%d attack chance\n",attackchance);//DEBUG CODE
      //getch();//DEBUG CODE

      //monkeyattackcheck = rand() % attackchance;//generates a random number to determine attack chance
      //monkeyattackcheck = 1;//DEBUG CODE TO GET A MONKEY ATTACK EVERY TIME
      if (monkeyattackcheck == 1)
      {
        //printf("Intiate Monkey Attck\n");//DEBUG CODE
        //monkeyattack = 1;//DEBUG CODE TO GET A MONKEY ATTACJ EVERYTIME
        attackpick = rand() % 6;
        //attackpick = 1;//DEBUG CODE TO GET MANGO EVERY TIME
      if (mangoi < 8 && strawberryi < 8 && applei < 8 && banani < 8 && grapei < 8 && kiwii < 8)
      {
        attackpick = 7;
      }
        attacktop:
        switch (attackpick)
        {
        case 1://mangosteal
        stealamnt = rand() % mangoia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
          if (mangoi < 4)//check to see if you have enough mangos for this to work.
          {
            attackpick = 2;
            goto attacktop;
          }
          printf("%d steal amount\n",stealamnt);
          printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
          scanf("%d",&attackmove);
          system("cls");
          switch (attackmove)
          {
          case 1:
            mangoi = mangoi - stealamnt;
            printf("You ignored the monkeys...\nThey stole %d of your Mangos\nYou now have %.0f Mangos",stealamnt,mangoi);
            monkeyattack = 0;
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          break;

          case 2:
            attackeffectiveness = rand() % 3;
            printf("%d\n",attackeffectiveness);
            if (attackeffectiveness == 1)
            {
              printf("Your attack was not very effective.\n");
              sleep(1);
              system("cls");
              mangoi = mangoi - stealamnt;
              printf("The monkeys took your fruit despite your best efforts\nThey took %d of your mangos.\nYou now have only %.0f mangos\n",stealamnt,mangoi);
              printf("Press any key to continue...\n");
              getch();
              system("cls");
              goto aftermonkey;
            }
            if(attackeffectiveness == 2 || attackeffectiveness == 3)
            {
            printf("Your attack was effective...\n");
            sleep(1);
            system("cls");
            printf("The monkeys left...\n");
            printf("Press any key to continue...\n");
            system("cls");
            getch();
            goto aftermonkey;
            }
          break;

          case 3:
            if (currentbal > 2000)
            {
            printf("The exterminators got rid of the monkeys...\n");
            currentbal = currentbal - 2000;
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
            }
            else
            {
            printf("You wasted your time calling the exterminators without the proper funds...\n");
            sleep(1);
            system("cls");
            mangoi = mangoi - stealamnt;
            printf("The monkeys took your fruits\nThey took %d mangos\n you now have %.0f Mangos",stealamnt,mangoi);
            goto aftermonkey;
            }
          break;

          }
        break;

        case 2://strawberry steal
        stealamnt = rand() % strawberryia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
        if (strawberryi < 4)//check to see if you have enough strawberrys for this to work.
        {
          attackpick = 3;
          goto attacktop;
        }
        printf("%d steal amount\n",stealamnt);
        printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
        scanf("%d",&attackmove);
        system("cls");
        switch (attackmove)
        {
        case 1:
          strawberryi = strawberryi - stealamnt;
          printf("You ignored the monkeys...\nThey stole %d of your Strawberrys\nYou now have %.0f Strawberrys",stealamnt,strawberryi);
          monkeyattack = 0;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
        break;

        case 2:
          attackeffectiveness = rand() % 3;
          printf("%d\n",attackeffectiveness);
          if (attackeffectiveness == 1)
          {
            printf("Your attack was not very effective.\n");
            sleep(1);
            system("cls");
            strawberryi = strawberryi - stealamnt;
            printf("The monkeys took your fruit despite your best efforts\nThey took %d of your strawberrys.\nYou now have only %.0f strawberrys\n",stealamnt,strawberryi);
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          }
          if(attackeffectiveness == 2 || attackeffectiveness == 3)
          {
          printf("Your attack was effective...\n");
          sleep(1);
          system("cls");
          printf("The monkeys left...\n");
          printf("Press any key to continue...\n");
          system("cls");
          getch();
          goto aftermonkey;
          }
        break;

        case 3:
          if (currentbal > 2000)
          {
          printf("The exterminators got rid of the monkeys...\n");
          currentbal = currentbal - 2000;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
          }
          else
          {
          printf("You wasted your time calling the exterminators without the proper funds...\n");
          sleep(1);
          system("cls");
          strawberryi = strawberryi - stealamnt;
          printf("The monkeys took your fruits\nThey took %d strawberrys\n you now have %.0f Strawberrys",stealamnt,strawberryi);
          goto aftermonkey;
          }
        break;

        }
        break;

        case 3://apple steal
        stealamnt = rand() % appleia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
        if (applei < 4)//check to see if you have enough apples for this to work.
        {
          attackpick = 4;
          goto attacktop;
        }
        printf("%d steal amount\n",stealamnt);
        printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
        scanf("%d",&attackmove);
        system("cls");
        switch (attackmove)
        {
        case 1:
          applei = applei - stealamnt;
          printf("You ignored the monkeys...\nThey stole %d of your Apples\nYou now have %.0f Apples",stealamnt,applei);
          monkeyattack = 0;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
        break;

        case 2:
          attackeffectiveness = rand() % 3;
          printf("%d\n",attackeffectiveness);
          if (attackeffectiveness == 1)
          {
            printf("Your attack was not very effective.\n");
            sleep(1);
            system("cls");
            applei = applei - stealamnt;
            printf("The monkeys took your fruit despite your best efforts\nThey took %d of your Apples.\nYou now have only %.0f apples\n",stealamnt,applei);
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          }
          if(attackeffectiveness == 2 || attackeffectiveness == 3)
          {
          printf("Your attack was effective...\n");
          sleep(1);
          system("cls");
          printf("The monkeys left...\n");
          printf("Press any key to continue...\n");
          system("cls");
          getch();
          goto aftermonkey;
          }
        break;

        case 3:
          if (currentbal > 2000)
          {
          printf("The exterminators got rid of the monkeys...\n");
          currentbal = currentbal - 2000;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
          }
          else
          {
          printf("You wasted your time calling the exterminators without the proper funds...\n");
          sleep(1);
          system("cls");
          applei = applei - stealamnt;
          printf("The monkeys took your fruits\nThey took %d Apples\n you now have %.0f Apples",stealamnt,applei);
          goto aftermonkey;
          }
        break;

        }
        break;

        case 4://banana steal
        stealamnt = rand() % bananaia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
        if (applei < 4)//check to see if you have enough apples for this to work.
        {
          attackpick = 5;
          goto attacktop;
        }
        printf("%d steal amount\n",stealamnt);
        printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
        scanf("%d",&attackmove);
        system("cls");
        switch (attackmove)
        {
        case 1:
          banani = banani - stealamnt;
          printf("You ignored the monkeys...\nThey stole %d of your Bananas\nYou now have %.0f Bananas",stealamnt,banani);
          monkeyattack = 0;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
        break;

        case 2:
          attackeffectiveness = rand() % 3;
          printf("%d\n",attackeffectiveness);
          if (attackeffectiveness == 1)
          {
            printf("Your attack was not very effective.\n");
            sleep(1);
            system("cls");
            banani = banani - stealamnt;
            printf("The monkeys took your fruit despite your best efforts\nThey took %d of your Bananas.\nYou now have only %.0f Bananas\n",stealamnt,banani);
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          }
          if(attackeffectiveness == 2 || attackeffectiveness == 3)
          {
          printf("Your attack was effective...\n");
          sleep(1);
          system("cls");
          printf("The monkeys left...\n");
          printf("Press any key to continue...\n");
          system("cls");
          getch();
          goto aftermonkey;
          }
        break;

        case 3:
          if (currentbal > 2000)
          {
          printf("The exterminators got rid of the monkeys...\n");
          currentbal = currentbal - 2000;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
          }
          else
          {
          printf("You wasted your time calling the exterminators without the proper funds...\n");
          sleep(1);
          system("cls");
          banani = banani - stealamnt;
          printf("The monkeys took your fruits\nThey took %d Bananas\n you now have %.0f Bananas",stealamnt,banani);
          goto aftermonkey;
          }
        break;

        }
        break;

        case 5://grape steal
        stealamnt = rand() % grapeia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
        if (grapei < 4)//check to see if you have enough apples for this to work.
        {
          attackpick = 6;
          goto attacktop;
        }
        printf("%d steal amount\n",stealamnt);
        printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
        scanf("%d",&attackmove);
        system("cls");
        switch (attackmove)
        {
        case 1:
          grapei = grapei - stealamnt;
          printf("You ignored the monkeys...\nThey stole %d of your Grapes\nYou now have %.0f Grapes",stealamnt,grapei);
          monkeyattack = 0;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
        break;

        case 2:
          attackeffectiveness = rand() % 3;
          printf("%d\n",attackeffectiveness);
          if (attackeffectiveness == 1)
          {
            printf("Your attack was not very effective.\n");
            sleep(1);
            system("cls");
            grapei = grapei - stealamnt;
            printf("The monkeys took your fruit despite your best efforts\nThey took %d of your Grapes.\nYou now have only %.0f Grapes\n",stealamnt,grapei);
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          }
          if(attackeffectiveness == 2 || attackeffectiveness == 3)
          {
          printf("Your attack was effective...\n");
          sleep(1);
          system("cls");
          printf("The monkeys left...\n");
          printf("Press any key to continue...\n");
          system("cls");
          getch();
          goto aftermonkey;
          }
        break;

        case 3:
          if (currentbal > 2000)
          {
          printf("The exterminators got rid of the monkeys...\n");
          currentbal = currentbal - 2000;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
          }
          else
          {
          printf("You wasted your time calling the exterminators without the proper funds...\n");
          sleep(1);
          system("cls");
          grapei = grapei - stealamnt;
          printf("The monkeys took your fruits\nThey took %d Grapes\n you now have %.0f Grapes",stealamnt,grapei);
          goto aftermonkey;
          }
        break;

        }
        break;

        case 6://kiwi steal
        stealamnt = rand() % kiwiia;
        stealamnt = stealamnt + 4;
        stealamnt = stealamnt / 4;
        if (kiwii < 4)//check to see if you have enough apples for this to work.
        {
          attackpick = 1;
          goto attacktop;
        }
        printf("%d steal amount\n",stealamnt);
        printf("Oh No! The monkeys have arived! What will you do.\n1. Ignore them\n2. Try and fend them off\n3. Hire exterminators(2000$) you have %0.2f\n",currentbal);
        scanf("%d",&attackmove);
        system("cls");
        switch (attackmove)
        {
        case 1:
          kiwii = kiwii - stealamnt;
          printf("You ignored the monkeys...\nThey stole %d of your Kiwis\nYou now have %.0f Kiwis",stealamnt,kiwii);
          monkeyattack = 0;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
        break;

        case 2:
          attackeffectiveness = rand() % 3;
          printf("%d\n",attackeffectiveness);
          if (attackeffectiveness == 1)
          {
            printf("Your attack was not very effective.\n");
            sleep(1);
            system("cls");
            kiwii = kiwii - stealamnt;
            printf("The monkeys took your fruit despite your best efforts\nThey took %d of your Kiwis.\nYou now have only %.0f Kiwis\n",stealamnt,kiwii);
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            goto aftermonkey;
          }
          if(attackeffectiveness == 2 || attackeffectiveness == 3)
          {
          printf("Your attack was effective...\n");
          sleep(1);
          system("cls");
          printf("The monkeys left...\n");
          printf("Press any key to continue...\n");
          system("cls");
          getch();
          goto aftermonkey;
          }
        break;

        case 3:
          if (currentbal > 2000)
          {
          printf("The exterminators got rid of the monkeys...\n");
          currentbal = currentbal - 2000;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          goto aftermonkey;
          }
          else
          {
          printf("You wasted your time calling the exterminators without the proper funds...\n");
          sleep(1);
          system("cls");
          grapei = grapei - stealamnt;
          printf("The monkeys took your fruits\nThey took %d Kiwis\n you now have %.0f Kiwis",stealamnt,kiwii);
          goto aftermonkey;
          }
        break;

        }
        break;

        case 7://No fruit
        printf("The monkeys came but could not find enough fruit...\nPress any key to continue...");
        getch();
        system("cls");
        goto aftermonkey;
        break;

        default:
        printf("Something wrong\n");
        break;
        //break;
        }

      }
      else
      {
        goto aftermonkey;
      }



      aftermonkey:
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

      int taxchance = rand() % 40;
      taxchance = 1;//DEBUG CODE TO GET TAX REQUEST EVERYTIME
      if(taxchance == 1)//checks to see if there will be a tax collection
      {
        printf("The government is asking for you to pay your taxes\n");
        printf("What will you do?\n1. Pay up!\n2. Commit Tax Fraud.\n");
        scanf("%d",&taxchoice);
        switch (taxchoice)
        {
          case 1:
          taxamount = currentbal * 13 / 100;
          printf("You pay %0.2f$ of taxes.\n",taxamount);
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          currentbal = currentbal - taxamount;
          taxamount = 0;
          break;

          case 2:
          printf("You commited tax fraud...\nThis will not end up well for you\n");
          taxfraud = 1;
          printf("Press any key to continue...\n");
          getch();
          system("cls");
          break;
        }

      }

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
        printf("What would you like to do today?\n\nSleep(1)\nBuy(2)\nSell(3)\nView Prices(4)\nView Inventory(5)\nView Balance(6)\nUpgrade Security(7)\nExit(8)\n");
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
              fruitpurchased = fruitpurchased + buyamount;
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
                  fruitpurchased = fruitpurchased + buyamount;
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
                  fruitpurchased = fruitpurchased + buyamount;
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
                fruitpurchased = fruitpurchased + buyamount;
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
                fruitpurchased = fruitpurchased + buyamount;
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
                fruitpurchased = fruitpurchased + buyamount;
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
                  fruitsold = fruitsold + buyamount;
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
                  fruitsold = fruitsold + buyamount;
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
                  fruitsold = fruitsold + buyamount;
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
                  fruitsold = fruitsold + buyamount;
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
                      fruitsold = fruitsold + buyamount;
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
                      fruitsold = fruitsold + buyamount;
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
  printf("%0.2f$\n",currentbal);
  printf("\n\nPress any key to continue\n");
  getch();
  goto looptop;
break;

case 7://start of upgrade Security
  system("cls");
  printf("Are you sure you would like to upgrade security to level %d for 4500$.\nYou currently have %0.2f$\n1. Yes\n2. No\n",securitylvl + 1,currentbal);
  scanf("%d",&secchoice);
  switch (secchoice)
  {
    case 1:
      if (currentbal < 4500)
      {
        system("cls");
        printf("You do not have the required funs to complete this transaction\n");
        printf("Press any key to continue...\n");
        getch();
        system("cls");
        goto looptop;
      }
      else
      {
        currentbal = currentbal - 4500;
        securitylvl = securitylvl + 1;
        printf("Transaction complete!\nCurrent security level %d\nCurrent balance %0.2f\nMonkey attack level 1 in %d\nPress any key to continue...",securitylvl,currentbal,securitylvl * 10 + 5);
        getch();
        system("cls");
        movecounter++;
        goto looptop;
      }
    break;
  }
break;

case 8://start of quit
printf(" Are you sure you want to quit, progress will not be saved!(y or n)\n");
if (getch() == 'y')
{
  printf("Goodbye...\n");
  sleep(1);
  gamestats();
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
  printf("GAME OVER\n");
  gamestats();

  return 0;
}
