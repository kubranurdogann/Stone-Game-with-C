#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int oyuncu1[2][20];
int oyuncu2[2][20];
int hamle = 0, oyunBittiMi = 0;
int OyunKontrol(int, int, int);
int oyunBitti(int, int, int);

void Oyunbaslangic()
{
    int renk = 0;
    printf("----------------------------Oyuncu 1---------------------------------\n");
    printf("\n        | 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 2; i++)
    {
        if (renk == 0)
        {
            printf("Mavi    |");
            renk++;
        }
        else if (renk == 1)
        {
            printf("Kirmizi |");
        }

        for (int j = 0; j < 20; j++)
        {

            printf(" %d ", oyuncu1[i][j] = 1);
        }
        printf("\n");
    }
    renk = 0;
    printf("\n--------------------------Oyuncu 2-----------------------------------\n");
    printf("\n        | 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 2; i++)
    {
        if (renk == 0)
        {
            printf("Mavi    |");
            renk++;
        }
        else if (renk == 1)
        {
            printf("Kirmizi |");
        }
        for (int j = 0; j < 20; j++)
        {

            printf(" %d ", oyuncu2[i][j] = 1);
        }
        printf("\n");
    }
}

int Boards()
{
    int renk = 0;
    printf("--------------------------Oyuncu 1----------------------------------\n");
    printf("\n        | 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 2; i++)
    {
        if (renk == 0)
        {
            printf("Mavi    |");
            renk++;
        }
        else if (renk == 1)
        {
            printf("Kirmizi |");
        }
        for (int j = 0; j < 20; j++)
        {

            printf(" %d ", oyuncu1[i][j]);
        }
        printf("\n");
    }
    renk = 0;
    printf("\n---------------------------Oyuncu 2---------------------------------\n");
    printf("\n        | 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 2; i++)
    {
        if (renk == 0)
        {
            printf("Mavi    |");
            renk++;
        }
        else if (renk == 1)
        {
            printf("Kirmizi |");
        }
        for (int j = 0; j < 20; j++)
        {

            printf(" %d ", oyuncu2[i][j]);
        }
        printf("\n");
    }
}

int Oyun(int secoy, int renk, int sayi)
{
    if (oyunBittiMi == 0)
    {
        hamle++;
        printf("\n\n\n\n\n\n%d.HAMLE\n--------\n", hamle);
        printf("SECILEN OYUNCU -->%d\n", secoy + 1);

        if (renk == 0)
        {

            printf("SECILEN TAS --> MAVI %d\n\n\n", sayi + 1);
        }
        else
        {
            printf("SECILEN TAS --> KIRMIZI %d\n\n\n", sayi + 1);
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 20; j++)
            {

                if (secoy == 0 && renk == i && sayi == j)
                {

                    oyuncu1[i][j] -= 1;
                    oyuncu2[i][j] += 1;
                }
                else if (secoy == 1 && renk == i && sayi == j)
                {

                    oyuncu1[i][j] += 1;
                    oyuncu2[i][j] -= 1;
                }
            }
        }

        Boards();
        OyunKontrol(secoy, renk, sayi);
    }
}

int nextSecoy, nextRenk, nextSayi;

int OyunKontrol(int secoyKontrol, int renkKontrol, int sayiKontrol)
{
    int ilkdeger = (sayiKontrol + 1) * 2 - 1;
    int ikincideger = sayiKontrol - 4;

    if (secoyKontrol == 0)
    {
        nextSecoy = 1;
    }
    else
    {
        nextSecoy = 0;
    }

    if ((ilkdeger >= 0 && ilkdeger < 20) && (ikincideger >= 0 && ikincideger < 20))
    {
        if (nextSecoy == 0)
        {
            if ((oyuncu1[renkKontrol][ilkdeger] == 1 || oyuncu1[renkKontrol][ilkdeger] == 2) &&
                (oyuncu1[!renkKontrol][ikincideger] == 1 || oyuncu1[!renkKontrol][ikincideger] == 2))
            {
                int randSecSayi = rand() % 2;
                if (randSecSayi == 0)
                {
                    nextRenk = renkKontrol;
                    nextSayi = ilkdeger;
                }
                else
                {
                    if (renkKontrol == 0)
                        nextRenk = 1;
                    else
                        nextRenk = 0;
                    nextSayi = ikincideger;
                }
            }
            else if (oyuncu1[renkKontrol][ilkdeger] == 1 || oyuncu1[renkKontrol][ilkdeger] == 2)
            {
                nextRenk = renkKontrol;
                nextSayi = ilkdeger;
            }
            else if (oyuncu1[!renkKontrol][ikincideger] == 1 || oyuncu1[!renkKontrol][ikincideger] == 2)
            {
                if (renkKontrol == 0)
                    nextRenk = 1;
                else
                    nextRenk = 0;
                nextSayi = ikincideger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
        else
        {
            if ((oyuncu2[renkKontrol][ilkdeger] == 1 || oyuncu2[renkKontrol][ilkdeger] == 2) &&
                (oyuncu2[!renkKontrol][ikincideger] == 1 || oyuncu2[!renkKontrol][ikincideger] == 2))
            {
                int randSecSayi = rand() % 2;
                if (randSecSayi == 0)
                {
                    nextRenk = renkKontrol;
                    nextSayi = ilkdeger;
                }
                else
                {
                    if (renkKontrol == 0)
                        nextRenk = 1;
                    else
                        nextRenk = 0;
                    nextSayi = ikincideger;
                }
            }
            else if (oyuncu2[renkKontrol][ilkdeger] == 1 || oyuncu2[renkKontrol][ilkdeger] == 2)
            {
                nextRenk = renkKontrol;
                nextSayi = ilkdeger;
            }
            else if (oyuncu2[!renkKontrol][ikincideger] == 1 || oyuncu2[!renkKontrol][ikincideger] == 2)
            {
                if (renkKontrol == 0)
                    nextRenk = 1;
                else
                    nextRenk = 0;
                nextSayi = ikincideger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
    }
    else if (ilkdeger >= 0 && ilkdeger < 20)
    {
        if (nextSecoy == 0)
        {
            if (oyuncu1[renkKontrol][ilkdeger] == 1 || oyuncu1[renkKontrol][ilkdeger] == 2)
            {
                nextRenk = renkKontrol;
                nextSayi = ilkdeger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
        else
        {
            if (oyuncu2[renkKontrol][ilkdeger] == 1 || oyuncu2[renkKontrol][ilkdeger] == 2)
            {
                nextRenk = renkKontrol;
                nextSayi = ilkdeger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
    }
    else
    {

        if (nextSecoy == 0)
        {
            if (oyuncu1[!renkKontrol][ikincideger] == 1 || oyuncu1[!renkKontrol][ikincideger] == 2)
            {
                if (renkKontrol == 0)
                    nextRenk = 1;
                else
                    nextRenk = 0;
                nextSayi = ikincideger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
        else
        {
            if (oyuncu2[!renkKontrol][ikincideger] == 1 || oyuncu2[!renkKontrol][ikincideger] == 2)
            {
                if (renkKontrol == 0)
                    nextRenk = 1;
                else
                    nextRenk = 0;
                nextSayi = ikincideger;
            }
            else
            {
                oyunBittiMi = 1;
                oyunBitti(nextSecoy, ilkdeger, ikincideger);
            }
        }
    }
    Oyun(nextSecoy, nextRenk, nextSayi);
    return 0;
}

int randfonk()
{
    int secoy = rand() % 2;
    int renk = rand() % 2;
    int sayi = rand() % 10;
    Oyun(secoy, renk, sayi);
}
int oyunBitti(int kaybedenOyuncu, int ilkdeger, int ikincideger)
{
    printf("\n\nOYUN BITTI...\n");
    printf("\nTOPLAM YAPILAN HAMLE: %d\n", hamle);
    printf("%d.OYUNCU KAYBETTI.\n", kaybedenOyuncu + 1);

    if ((ilkdeger >= 0 && ilkdeger < 20) && (ikincideger >= 0 && ikincideger < 20))
    {
        printf("Elinde ayni renk, %d numarali tas veya farkli renk, %d numarali tas olmadigi icin kaybetti.\n", ilkdeger + 1, ikincideger + 1);
    }
    else if (ilkdeger >= 0 && ilkdeger < 20)
    {
        printf("Elinde ayni renk, %d numarali tas olmadigi icin kaybetti.\n", ilkdeger + 1);
    }
    else
    {
        printf("Elinde farkli renk, %d numarali tas olmadigi icin kaybetti.\n", ikincideger + 1);
    }
    return 0;
}

int main()
{

    printf("\n -WELCOME\n\n\n\n\n");
    
	srand(time(0));
    Oyunbaslangic();
    randfonk();

    return 0;
}
