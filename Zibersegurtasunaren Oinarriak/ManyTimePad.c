#include <stdio.h>
#include <string.h>

int hexToDec(unsigned char hex[]);

int main()
{
    unsigned char zifratu[116][14];

    for (int i = 0; i < 116; i++)
        for (int j = 0; j < 14; j++)
            zifratu[i][j] = 0;

    unsigned char c0[116] = "1a1617451a411517490b061b0f08535404044e17450c1c45326222420a00340006544816170b54030b55020d530046";
    unsigned char c1[116] = "184f184f0a081a000016071a00010017090b00100416010054530e060c52301b0c000a131304430e0a0640";
    unsigned char c2[116] = "09001a5248041b04490a4f060b05850601115953116c010007000604134f2b4f01481a0417115348";
    unsigned char c3[116] = "7926114506151f1159461b1d0b025454010850120617014542104b08104c35061a4e48201b00520f0c1400170e";
    unsigned char c4[116] = "0c3c5547071713174e0b0a1b1a445018090b5353110c5216044505015904685a5542010d1a0c4f084f1a0044430d0a005200000007171d54124b";
    unsigned char c5[116] = "1a001c4e480c1f0b490808551e1645070d0b5400450252071d474b020b4f2e1b1d00010f560659040a070d1649190d4b";
    unsigned char c6[116] = "0d0710003d32560c5346211a4e550000091747161143140a06001f040b473c1b1044480002114105040640";
    unsigned char c7[116] = "1c02054c0718130000080a12020d47110606455306021c45174f06116b4f34060645480f131157091d1e4e1745171d1749071c4d";
    unsigned char c8[116] = "103b55530d02031749121655070a541104094914000d1100544918450c4e3d0a05851c081a0c5a030b5b";
    unsigned char c9[116] = "120a1050010f1145410a03551d0b46001f0452164516020115540e0159492a4f14441e0805004448";
    unsigned char c10[116] = "793b024f48151f0845461f140a444907480b4f074510170601520e4959552a0a5541480f1312000d0a0c4e0141170045541a08065c";
    unsigned char c11[116] = "163b55530d020317491216551e1645070d0b54004502520b11574b161c54790013000b0917094c0301120b170e";
    unsigned char c12[116] = "100021000c04000c43031c550d054e54010b43010002010054530e060c52301b0c001e141a0b45140e17070849000100535d";
    unsigned char c13[116] = "793b1d451a04560c53460e550d1d42111a4553160616000c00594b161249350306001b0919158407081040";

    for (int i = 0; i < 116; i++)
    {
        zifratu[i][0] = c0[i];
        zifratu[i][1] = c1[i];
        zifratu[i][2] = c2[i];
        zifratu[i][3] = c3[i];
        zifratu[i][4] = c4[i];
        zifratu[i][5] = c5[i];
        zifratu[i][6] = c6[i];
        zifratu[i][7] = c7[i];
        zifratu[i][8] = c8[i];
        zifratu[i][9] = c9[i];
        zifratu[i][10] = c10[i];
        zifratu[i][11] = c11[i];
        zifratu[i][12] = c12[i];
        zifratu[i][13] = c13[i];
    }

    int zifratuDec[58][14];

    for (int i = 0; i < 115; i = i + 2)
    {
        for (int j = 0; j < 14; j++)
        {
            unsigned char lag[2];

            lag[0] = zifratu[i][j];
            lag[1] = zifratu[i + 1][j];

            int dec = hexToDec(lag);

            zifratuDec[i / 2][j] = dec;
        }
    }

    int tarteak[58][14];

    for (int i = 0; i < 58; i++)
        for (int j = 0; j < 14; j++)
            tarteak[i][j] = 0;

    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            for (int z = 0; z < 14; z++)
            {
                if (j != z)
                {
                    int lag1 = zifratuDec[i][j] ^ zifratuDec[i][z];
                    if (lag1 > 64 && lag1 < 91)
                    {
                        tarteak[i][j]++;
                        tarteak[i][z]++;
                    }
                    else if (lag1 > 96 && lag1 < 123)
                    {
                        tarteak[i][j]++;
                        tarteak[i][z]++;
                    }
                }
            }
        }
    }

    int gakoa[58];

    for (int i = 0; i < 58; i++)
    {
        int max = 0;

        for (int j = 0; j < 14; j++)
        {
            if (tarteak[i][j] > tarteak[i][max])
            {
                max = j;
            }
        }

        int lag2 = zifratuDec[i][max] ^ 32;

        if (i < 30)
        {
            gakoa[i] = lag2;
        }
        else
        {
            gakoa[i] = gakoa[i-30];
        }

        printf("%c", gakoa[i]);
    }

    for (int i = 0; i < 14; i++)
    {
        printf("\n\nm%d mezua: ", i);
        for (int j = 0; j < 58; j++)
        {
            printf("%c", gakoa[j] ^ zifratuDec[j][i]);
        }
    }

    printf("\n\n");

    return 0;
}

int hexToDec(unsigned char hex[])
{
    int buelta = 0;
    if (hex[0] > 47 && hex[0] < 58)
    {
        buelta += (hex[0] - 48) * 16;
    }
    else if (hex[0] > 96 && hex[0] < 103)
    {
        buelta += (hex[0] - 87) * 16;
    }
    if (hex[1] > 47 && hex[1] < 58)
    {
        buelta += (hex[1] - 48);
    }
    else if (hex[1] > 96 && hex[1] < 103)
    {
        buelta += (hex[1] - 87);
    }

    return buelta;
}