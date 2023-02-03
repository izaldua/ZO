#include <stdio.h>
#include <string.h>

void print_string(unsigned char a[], int len);

int main()
{
    unsigned char cipher[1000] = "Yd shofjewhqfxo, q Squiqh syfxuh, qbie ademd qi q Squiqh'i syfxuh, jxu ixyvj syfxuh, Squiqh'i Setu eh Squiqh Ixyvj, yi edu ev jxu iycfbuij qdt ceij mytubo-ademd udshofjyed jusxdygkui. Yj yi q jofu ev ikrijyjkjyed syfxuh yd mxysx uqsx bujjuh yd jxu fbqydjunj yi hufbqsut ro q bujjuh iecu vynut dkcruh ev feiyjyedi vkhjxuh temd jxu qbfxqruj. Veh unqcfbu, myjx q ixyvj ev 3, Q mekbt ru hufbqsut ro T, R mekbt rusecu U, qdt ie ed. Jxu cujxet yi dqcut qvjuh Zkbyki Squiqh, mxe kiut yj je secckdysqju myjx xyi wuduhqbi.";
    // Rellenar el c�digo aqu�
    int len = strlen(cipher);
    int alph[26];
    for (int i = 0; i < 26; i++)
    {
        alph[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        int lag = cipher[i];
        // printf("%d\n", lag); // Debugger
        if (lag > 64 && lag < 91)
        {
            alph[lag - 65]++;
        }
        else if (lag > 96 && 123)
        {
            alph[lag - 97]++;
        }
    }

    int max = 0;

    for (int i = 0; i < 26; i++)
    {
        if (alph[i] > alph[max])
        {
            max = i;
        }
    }

    int saltoa;
    int flg;

    if (max < 4)
    {
        saltoa = 4 - max;
        flg = 0;
    }
    else if (max > 4)
    {
        saltoa = max - 4;
        flg = 1;
    }
    else
    {
        perror("Mezua ondo dago dagoeneko.");
    }

    unsigned char msg[len];
    unsigned char newChar;

    if (flg == 0)
    {
        for (int i = 0; i < len; i++)
        {
            int lag2 = cipher[i];
            newChar = lag2;
            if (lag2 > 64 && lag2 < 91)
            {
                if ((lag2 + saltoa) > 90)
                {
                    newChar = (lag2 + saltoa) - 26;
                }
                else
                {
                    newChar = lag2 + saltoa;
                }
            }
            else if (lag2 > 96 && lag2 < 123)
            {
                if ((lag2 + saltoa) > 122)
                {
                    newChar = (lag2 + saltoa) - 26;
                }
                else
                {
                    newChar = lag2 + saltoa;
                }
            }
            msg[i] = newChar;
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            int lag2 = cipher[i];
            newChar = lag2;
            if (lag2 > 64 && lag2 < 91)
            {
                if ((lag2 - saltoa) < 65)
                {
                    newChar = (lag2 - saltoa) + 26;
                }
                else
                {
                    newChar = lag2 - saltoa;
                }
            }
            else if (lag2 > 96 && lag2 < 123)
            {
                if ((lag2 - saltoa) < 97)
                {
                    newChar = (lag2 - saltoa) + 26;
                }
                else
                {
                    newChar = lag2 - saltoa;
                }
            }
            msg[i] = newChar;
        }
    }

    print_string(msg, len);

    return 0;
}

void print_string(unsigned char a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
}