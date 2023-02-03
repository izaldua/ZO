#include <stdio.h>
#include <string.h>

void print_string(unsigned char a[], int len);
int egokia(unsigned char mezua[], int len);

int main()
{
    unsigned char cipher[1000] = "Pda Ywaown yeldan ywj xa awoehu xnkgaj araj ej w yeldanpatp-kjhu oyajwnek. Psk oepqwpekjo ywj xa ykjoezanaz: 1) wj wppwygan gjkso (kn cqaooao) pdwp okia oknp kb oeilha oqxopepqpekj yeldan dwo xaaj qoaz, xqp jkp olayebeywhhu pdwp ep eo w Ywaown oydaia; wjz 2) wj wppwygan gjkso pdwp w Ywaown yeldan eo ej qoa, xqp zkao jkp gjks pda odebp rwhqa. Ej pda benop ywoa, pda yeldan ywj xa xnkgaj qoejc pda owia paydjemqao wo bkn w cajanwh oeilha oqxopepqpekj yeldan, oqyd wo bnamqajyu wjwhuoeo kn lwppanj sknzo. Sdeha okhrejc, ep eo hegahu pdwp wj wppwygan sehh mqeyghu jkpeya pda nacqhwnepu ej pda okhqpekj wjz zazqya pdwp w Ywaown yeldan eo pda olayebey whcknepdi ailhkuaz.Ej pda oaykjz ejopwjya, xnawgejc pda oydaia eo araj ikna opnwecdpbknswnz. Oejya pdana wna kjhu w heiepaz jqixan kb lkooexha odebpo (26 ej Ajcheod), pdau ywj awyd xa paopaz ej pqnj ej w xnqpa bknya wppwyg. ";
    int len = strlen(cipher);

    unsigned char msg[len];
    unsigned char newChar;

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int lag = cipher[j];
            newChar = lag;
            if (lag == 90)
            {
                newChar = 65;
            }
            else if (lag == 122)
            {
                newChar = 97;
            }
            else if (lag > 64 && lag < 90)
            {
                newChar = lag + 1;
            }
            else if (lag > 96 && lag < 122)
            {
                newChar = lag + 1;
            }
            msg[j] = newChar;
            cipher[j] = newChar;
        }
        int flg = egokia(msg, len);
        if (flg == 1)
        {
            printf("\nJauzi kopurua : %d\n\n", i);
            print_string(msg, len);
        }
    }

    return 0;
}

void print_string(unsigned char a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n\n");
}

int egokia(unsigned char mezua[], int len)
{
    int alph[26];
    int flg = 0;
    for (int i = 0; i < 26; i++)
    {
        alph[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        int lag = mezua[i];
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

    if (max == 4)
    {
        flg = 1;
    }

    return flg;
}
