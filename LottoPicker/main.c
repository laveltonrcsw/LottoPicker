//
//  main.c
//  LottoPicker - Powerball
//  URL: http://www.powerball.com
//
//  Created by LaVelton R. Carroway on 06/16/2014.
//  Copyright (c) 2014 Rochee Software, LLC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>

const char * LottoQuickPick();

int main(int argc, const char * argv[])
{
//    const char *szProjectPath = "/Volumes/WDPP2TB/Development/Xcode/PRG/LottoPicker/OtherData";
//    chdir(szProjectPath);
//    system("curl -sS -O http://www.powerball.com/powerball/winnums-text.txt");

    FILE *fp;
    chdir("/Volumes/WDPP2TB/Development/Xcode/PRG/LottoPicker");
    if ((fp = fopen("LottoPicker.txt", "a+")) == NULL ) fprintf(stderr, "File Access Denied\n");


    // Display The Lotto Picks
    fprintf(fp,"FLORIDA LOTTERY - POWERBALL LOTTERY PICKER\n");
    fprintf(fp,"The Florida Lottery offers fun and excitement for all who play, with new games, bigger prizes, and more winners.\n");
    fprintf(fp,"Printed: %s Time: %s\n\n", __DATE__, __TIME__);

    for (int TicketCount = 1; TicketCount < 4; TicketCount++)
    {
        fprintf(fp, "TICKET: %d\n", TicketCount);
        fprintf(fp,"Quick Pick Panel A: %s\n", LottoQuickPick());
        fprintf(fp,"Quick Pick Panel B: %s\n", LottoQuickPick());
        fprintf(fp,"Quick Pick Panel C: %s\n", LottoQuickPick());
        fprintf(fp,"Quick Pick Panel D: %s\n", LottoQuickPick());
        fprintf(fp,"Quick Pick Panel E: %s\n\n", LottoQuickPick());
    }

    fprintf(fp, "Have A Good Day.\n\n");
    fclose(fp);

    // system("open /Applications/textedit.app LottoPicker.txt");

    return 0;
}

const char * LottoQuickPick()
{
    int lottoPick01 = 0;
    int lottoPick02 = 0;
    int lottoPick03 = 0;
    int lottoPick04 = 0;
    int lottoPick05 = 0;
    int lottoPickPB = 0;

    /*
     * POWERBALL 7.0 BEGINS OCTOBER 7, 2015
     * HIGHER JACKPOTS; MORE OVERALL WINNERS
     * The number of white balls rises to 69, while the number of red balls drops to 26. This change means higher average jackpot won and more overall winners.
     */

    /*
     * Select five numbers from 1 through 69 in the upper play area, or mark the QP (Quick Pick) box and let the
     * terminal randomly pick some or all of your numbers.
     */
    int lottoPickMax = 69;

    /*
     * Select your Powerball number from 1 through 26 in the lower play area, or mark the QP (Quick Pick) box for
     * the terminal to randomly select your Powerball number.
     */
    int lottoPickPBMax = 26;

    int sortedLottoPick[6], sortedCounter01, sortedCounter02, NumberOfPicks, tempLottoPickArrayLocation;
    static char fullLottoPicks[30];

    /*
     *  Generate The Lotto Picks
     */

    // Number Slot 1
    lottoPick01 = arc4random_uniform(lottoPickMax);
    if (lottoPick01 == 0)
    {
        do
        {
            lottoPick01 = arc4random_uniform(lottoPickMax);
        } while (lottoPick01 == 0);
    }

    // Number Slot 2
    lottoPick02 = arc4random_uniform(lottoPickMax);
    if (lottoPick02 == lottoPick01 || lottoPick02 == 0)
    {
        do
        {
            lottoPick02 = arc4random_uniform(lottoPickMax);
        } while (lottoPick02 == lottoPick01 || lottoPick02 == 0);
    }

    // Number Slot 3
    lottoPick03 = arc4random_uniform(lottoPickMax);
    if (lottoPick03 == lottoPick02 || lottoPick03 == lottoPick01 || lottoPick03 == 0)
    {
        do
        {
            lottoPick03 = arc4random_uniform(lottoPickMax);
        } while (lottoPick03 == lottoPick02 || lottoPick03 == lottoPick01 || lottoPick03 == 0);
    }

    // Number Slot 4
    lottoPick04 = arc4random_uniform(lottoPickMax);
    if (lottoPick04 == lottoPick03 || lottoPick04 == lottoPick02 || lottoPick04 == lottoPick01 || lottoPick04 == 0)
    {
        do
        {
            lottoPick04 = arc4random_uniform(lottoPickMax);
        } while (lottoPick04 == lottoPick03 || lottoPick04 == lottoPick02 || lottoPick04 == lottoPick01 || lottoPick04 == 0);
    }

    // Number Slot 5
    lottoPick05 = arc4random_uniform(lottoPickMax);
    if (lottoPick05 == lottoPick04 || lottoPick05 == lottoPick03 || lottoPick05 == lottoPick02 || lottoPick05 == lottoPick01 || lottoPick05 == 0)
    {
        do
        {
            lottoPick05 = arc4random_uniform(lottoPickMax);
        } while (lottoPick05 == lottoPick04 || lottoPick05 == lottoPick03 || lottoPick05 == lottoPick02 || lottoPick05 == lottoPick01 || lottoPick05 == 0);
    }

    // Powerball Number
    lottoPickPB = arc4random_uniform(lottoPickPBMax);
    if (lottoPickPB == 0)
    {
        do
        {
            lottoPickPB = arc4random_uniform(lottoPickPBMax);
        } while (lottoPickPB == 0);
    }

    // Sort The Lotto Picks
    NumberOfPicks = 5;
    sortedLottoPick[0] = lottoPick01;
    sortedLottoPick[1] = lottoPick02;
    sortedLottoPick[2] = lottoPick03;
    sortedLottoPick[3] = lottoPick04;
    sortedLottoPick[4] = lottoPick05;

    for(sortedCounter01 = 0; sortedCounter01 < NumberOfPicks; sortedCounter01++)
    {
        for(sortedCounter02 = sortedCounter01; sortedCounter02 < NumberOfPicks; sortedCounter02++)
        {
            if(sortedLottoPick[sortedCounter01] > sortedLottoPick[sortedCounter02])
            {
                tempLottoPickArrayLocation = sortedLottoPick[sortedCounter01];
                sortedLottoPick[sortedCounter01] = sortedLottoPick[sortedCounter02];
                sortedLottoPick[sortedCounter02] = tempLottoPickArrayLocation;
            }
        }
    }

    sprintf(fullLottoPicks, "%02d - %02d - %02d - %02d - %02d (%02d)", sortedLottoPick[0], sortedLottoPick[1], sortedLottoPick[2], sortedLottoPick[3], sortedLottoPick[4], lottoPickPB);
    return fullLottoPicks;
}
