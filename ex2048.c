/***************************************************************************
 *   ex2048.c                                 Version 20170610.221324      *
 *                                                                         *
 *   The 2048 game                                                         *
 *   Copyright (C) 2017         by Group Azaleia                           *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Bernardo de Azevedo Moreira                                           * 
 *   Email: bernardo.az.moreira@gmail.com                                  *
 *   Webpage: https://github.com/BAMoreira                                 *
 *   Phone: +55 81 99145-9271                                              *
 *                                                                         *
 *   Daidson Fonseca Alves                                                 * 
 *   Email: daidson.alves@gmail.com                                        *
 *   Webpage: https://github.com/daidson                                   *
 *   Phone: +55 81 99954-6310                                              *
 *                                                                         *
 *   Douglas Azevedo Pereira Dantas                                        * 
 *   Email: douglasazevedo839@gmail.com                                    *
 *   Webpage: https://github.com/DodoAz                                    *
 *   Phone: +55 81 99158-2473                                              *
 *                                                                         *
 *   Maria Eduarda Azevedo Saraiva de Moraes                               * 
 *   Email: eduardasaraivam@gmail.com                                      *
 *   Webpage: http://github.com/eduardasaraiva                             *
 *   Phone: +55 81 99952-0347                                              *
 *                                                                         *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* includes */

#include "ex2048.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* function bodies */

/* ---------------------------------------------------------------------- */
/* print a welcome message */
void welcome(void)
{
    int align=1+ceil(log10(pow(2,(1+BS*BS)))); /* taken from print() */
    char welcm[] = "2048 - Azaleia";
    int wellgt = strlen(welcm);

    printf("\e[f\e[J"); /* clear screen */
    
    if(1 < ((align*BS) - wellgt))
        printf("%*s%s\n",(align*BS-wellgt)/2,"",welcm);
    else
        printf("%s\n",welcm);
    return;
}

/* ---------------------------------------------------------------------- */
/* add a tile */
void addtile(int bd[BS][BS])
{
    time_t seed;
    int r, c, tile;
    int slots = 0;

    srand((unsigned) time(&seed));  /* srand() left here for more randomness */
    for (r = 0; r < BS; ++r)    /* counting available slots */
        for (c = 0; c < BS; ++c)
            if (0 == bd[r][c])
                ++slots;
    
    tile = rand() % slots;
    
    for (r = 0; r < BS; ++r)    /* adding the tile */
        for (c = 0; c < BS; ++c)
            if (0 == bd[r][c])
            {
                if (0 == tile)
                {
                    if(rand()%10)
                        bd[r][c] = 2;
                    else
                        bd[r][c] = 4;
                    return;
                }
                else
                    --tile;
            }
}

/* ---------------------------------------------------------------------- */
/* print the board */
void print(int bd[BS][BS])
{
    int r,c;
    int align=ceil(log10(pow(2,(1+BS*BS))));  /* 2^(BS*BS+1) is the highest tile number possible 
                                                * 1+ceil(log10(n)) converts that to the number of
                                                * columns needed to print it correctly centered
                                                */
    int width;
    int color;

    for(r = 0; r < BS; ++r)
    {
        for(c = 0; c < BS; ++c)
        {
            if(bd[r][c])
            {
                if(log2(bd[r][c]) < 7)
                    color = 47 - (int) log2(bd[r][c]);
                else
                    color = 41;
         
                printf("\e[%d;30m%*s\e[0m",color,align+1,"");
            }
            else
                printf("\e[47;30m%*s\e[0m",align+1,"");
        }
        printf("\n");
        
        for(c = 0; c < BS; ++c)
            if (bd[r][c])
            {
                if(log2(bd[r][c]) < 7)
                    color = 47 - (int) log2(bd[r][c]);
                else
                    color = 41;

                width =ceil(log10(bd[r][c]));  /* columns taken up by the tile */
                printf("\e[%d;30m%*s%d%*s\e[0m",color, (align-width)/2+(align-width)%2, "", bd[r][c], (align-width)/2+1, "");
            }
            else
                printf("\e[47;30m%*s%*s\e[0m", align/2+1,".",align/2+align%2,"");
        
        printf("\n");

        for(c = 0; c < BS; ++c)
            if(bd[r][c])
            {
                if(log2(bd[r][c]) < 7)
                    color = 47 - (int) log2(bd[r][c]);
                else
                    color = 41;
         
                printf("\e[%d;30m%*s\e[0m",color,align+1,"");
            }
            else
                printf("\e[47;30m%*s\e[0m",align+1,"");
        printf("\n");
    }

    return;
}

/* ---------------------------------------------------------------------- */
/* get the move 'u'p, 'd'own, 'l'eft, 'r'ight or '\0' if no moves left */
char getmove(int bd[BS][BS])
{
    char in, clean;
    char valu = 0;
    char vald = 0;
    char vall = 0;
    char valr = 0;
    int align=1+ceil(log10(pow(2,(1+BS*BS)))); /* taken from print() */

    char valmsg[80] = "Valid moves: ";
    int vallgt;

    if(validmove('u',bd))
    {
        valu = 1;
        strcat(valmsg,"u");
    }
    if(validmove('d',bd))
    {
        vald = 1;
        strcat(valmsg,"d");
    }
    if(validmove('l',bd))
    {
        vall = 1;
        strcat(valmsg,"l");
    }
    if(validmove('r',bd))
    {
        valr = 1;
        strcat(valmsg,"r");
    }
    
    if (!(valu||vald||vall||valr))
    {
        strcat(valmsg,"None.");
        vallgt = strlen(valmsg);
        if(1 < align*BS-vallgt)
            printf("%*s%s\n",(align*BS-vallgt)/2,"",valmsg);
        else
            printf("%s\n",valmsg);
        return '\0';
    }

    vallgt = strlen(valmsg);
    if(1 < align*BS-vallgt)
        printf("%*s%s\n",(align*BS-vallgt)/2,"",valmsg);
    else
        printf("%s\n",valmsg);
    
    if(1 < align*BS-11) /* this 10-char string+1 */
        printf("%*s%s",(align*BS-11)/2,"","Next move:");
    else
        printf("Next move:");
    
    while(1)
    {
        in=getchar();
        while((clean=getchar()) != '\n' && clean != EOF);
        
        switch(in)
        {
            case 'u':
                if (valu)
                {
                    printf("\e[f\e[J");
                    return 'u';
                }
                break;
            case 'd':
                if (vald)
                {
                    printf("\e[f\e[J");
                    return 'd';
                }
                break;
            case 'l':
                if (vall)
                {
                    printf("\e[f\e[J");
                    return 'l';
                }
                break;
            case 'r':
                if (valr)
                {
                    printf("\e[f\e[J");
                    return 'r';
                }
                break;
        }

        /*printf("Invalid Input.\n");*/
        char invalid[] = "Invalid Input.";
        int invlgt = strlen(invalid);

        if(1 < (align*BS-invlgt))
            printf("%*s%s\n", (align*BS-invlgt)/2,"", invalid);
        else
            printf("%s\n", invalid);
    }
    
}

/* ---------------------------------------------------------------------- */
/* apply the move m to the board bd and return the partial score */
int applymove(char m, int bd[BS][BS])
{
    if (m == 'r')
        return applyright(bd);
    if (m == 'l')
        return applyleft(bd);
    if (m == 'd')
        return applydown(bd);
    if (m == 'u')
        return applyup(bd);
    return 0;
}
int applyright(int bd[BS][BS])
{
    int a = 0;      /* score */
    int r, c;       /* rows and columns for loop */
    int zerocount;  /* variable to store the amount of zeros scanned */
    int last;       /* stores last valid scanned number */
    
    for (r = 0; r < BS; ++r)
    {
        zerocount = 0;  /* reset the count */
        last = 0;       /* reset the last read number */
        for (c = (BS-1); c >= 0; --c)
        {
            if (bd[r][c])   /* if the tile is not empty */
            {
                if (bd[r][c] & last)    /* if the current number is fuse-able
                                           with the last valid number(equal&not 0) */
                {
                    bd[r][c] *= 2;      /* doubles the tile's number to represent fusion */
                    a += bd[r][c];      /* score setting */

                    ++zerocount;        /* a fusion makes an empty slot, and this sets the
                                           move code to replace the fused number */
                    
                    last = 0;           /* stops double-fusing by disabling fusions on the
                                           next scan */
                }
                else
                    last = bd[r][c];    /* update the last scan after a failed fusion */
                
                if (zerocount)          /* if there are zeroes before the current number
                                           it needs to be moved */
                {
                    bd[r][c+zerocount] = bd[r][c];  /* moves the number to the last zero */
                    bd[r][c] = 0;                   /* and replces the previous tile with 0 */
                }
            }
            else
                ++zerocount;            /* adds to the zero-counter after finding an empty tile */
        }
    }
 
    return a;
}

int applyleft(int bd[BS][BS])
{
    int a = 0;      /* score */
    int r, c;       /* rows and columns for loop */
    int zerocount;  /* variable to store the amount of zeros scanned */
    int last;       /* stores last valid scanned number */
    
    for (r = 0; r < BS; ++r)
    {
        zerocount = 0;  /* reset the count */
        last = 0;       /* reset the last read number */
        for (c = 0; c < BS; ++c)
        {
            if (bd[r][c])   /* if the tile is not empty */
            {
                if (bd[r][c] & last)    /* if the current number is fuse-able
                                           with the last valid number(equal&not 0) */
                {
                    bd[r][c] *= 2;      /* doubles the tile's number to represent fusion */
                    a += bd[r][c];      /* score setting */

                    ++zerocount;        /* a fusion makes an empty slot, and this sets the
                                           move code to replace the fused number */
                    
                    last = 0;           /* stops double-fusing by disabling fusions on the
                                           next scan */
                }
                else
                    last = bd[r][c];    /* update the last scan after a failed fusion */
                
                if (zerocount)          /* if there are zeroes before the current number
                                           it needs to be moved */
                {
                    bd[r][c-zerocount] = bd[r][c];  /* moves the number to the last zero */
                    bd[r][c] = 0;                   /* and replces the previous tile with 0 */
                }
            }
            else
                ++zerocount;            /* adds to the zero-counter after finding an empty tile */
        }
    }

    return a;
}

int applydown(int bd[BS][BS])
{
    int a = 0;      /* score */
    int r, c;       /* rows and columns for loop */
    int zerocount;  /* variable to store the amount of zeros scanned */
    int last;       /* stores last valid scanned number */
    
    for (c = 0; c < BS; ++c)
    {
        zerocount = 0;  /* reset the count */
        last = 0;       /* reset the last read number */
        for (r = (BS-1) ; r >= 0; --r)
        {
            if (bd[r][c])   /* if the tile is not empty */
            {
                if (bd[r][c] & last)    /* if the current number is fuse-able
                                           with the last valid number(equal&not 0) */
                {
                    bd[r][c] *= 2;      /* doubles the tile's number to represent fusion */
                    a += bd[r][c];      /* score setting */

                    ++zerocount;        /* a fusion makes an empty slot, and this sets the
                                           move code to replace the fused number */
                    
                    last = 0;           /* stops double-fusing by disabling fusions on the
                                           next scan */
                }
                else
                    last = bd[r][c];    /* update the last scan after a failed fusion */
                
                if (zerocount)          /* if there are zeroes before the current number
                                           it needs to be moved */
                {
                    bd[r+zerocount][c] = bd[r][c];  /* moves the number to the last zero */
                    bd[r][c] = 0;                   /* and replces the previous tile with 0 */
                }
            }
            else
                ++zerocount;            /* adds to the zero-counter after finding an empty tile */
        }
    }

    return a;
}

int applyup(int bd[BS][BS])
{
    int a = 0;      /* score */
    int r, c;       /* rows and columns for loop */
    int zerocount;  /* variable to store the amount of zeros scanned */
    int last;       /* stores last valid scanned number */
    
    for (c = 0; c < BS; ++c)
    {
        zerocount = 0;  /* reset the count */
        last = 0;       /* reset the last read number */
        for (r = 0; r < BS; ++r)
        {
            if (bd[r][c])   /* if the tile is not empty */
            {
                if (bd[r][c] & last)    /* if the current number is fuse-able
                                           with the last valid number(equal&not 0) */
                {
                    bd[r][c] *= 2;      /* doubles the tile's number to represent fusion */
                    a += bd[r][c];      /* score setting */

                    ++zerocount;        /* a fusion makes an empty slot, and this sets the
                                           move code to replace the fused number */
                    
                    last = 0;           /* stops double-fusing by disabling fusions on the
                                           next scan */
                }
                else
                    last = bd[r][c];    /* update the last scan after a failed fusion */
                
                if (zerocount)          /* if there are zeroes before the current number
                                           it needs to be moved */
                {
                    bd[r-zerocount][c] = bd[r][c];  /* moves the number to the last zero */
                    bd[r][c] = 0;                   /* and replces the previous tile with 0 */
                }
            }
            else
                ++zerocount;            /* adds to the zero-counter after finding an empty tile */
        }
    }

    return a;
}

/* ---------------------------------------------------------------------- */
/* print the goodbye message and congratulations on the score */
void goodbye(int score)
{
    int align=1+ceil(log10(pow(2,(1+BS*BS))));  /* taken from print */
    char gdb[] = "No moves left! You lose!";
    int gdblgt = strlen(gdb);
    char scrmsg[]= "Score:";
    int scrlgt = strlen(scrmsg);
    int scrlg;
    scrlg = (int)ceil(log10(score)); /* score length size plus the score */

    if(1 < (align*BS - gdblgt))
        printf("%*s%s\n", (align*BS-gdblgt)/2,"", gdb);
    else
        printf("%s\n", gdb);

    if(1 < (align*BS - scrlgt))
        printf("%*s%s%d\n", (align*BS-scrlgt)/2,"", scrmsg, scrlg);
    else
        printf("%s%d\n", scrmsg, score);
    /*  Old goodbye message below
    printf("No moves left: You lose!\n");
    printf("Score: %d\n", score);
    printf("Try again later.\n");
    */
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "2048", "The 2048 game");
    printf("\nUsage: %s\n\n", "2048");
    printf("This program does...\n");
    /* add more stuff here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information 
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "2048", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2017, "Ruben Carlo Benante", "rcb@beco.cc");
    return;
}

/* ---------------------------------------------------------------------- */
/* add more of your own functions here */
int validmove(char m, int bd[BS][BS])
{
    switch(m)
    {
        case 'u':
            return validup(bd);
        case 'd':
            return validdown(bd);
        case 'l':
            return validleft(bd);
        case 'r':
            return validright(bd);
    }
    return 0;
}

int validleft(int bd[BS][BS])
{
    int r, c;
    int curnt = 0;
    int oldt = 0;
    int i;

    for (r = 0; r < BS; ++r)
    {
        oldt = 0;
        for (c = 0; c < BS; ++c)
        {
            curnt = bd[r][c];
            if(curnt & oldt)
                return 1;

            oldt = curnt;
            if(!bd[r][c])
                for (i = c + 1; i < BS; i++)
                    if (bd[r][i])
                        return 1;
        }
    }
    return 0;
}

int validright(int bd[BS][BS])
{
    int r, c;
    int curnt = 0;
    int oldt = 0;
    int i;

    for (r = 0; r < BS; ++r)
    {
        oldt = 0;
        for (c = (BS-1); c >= 0; --c)
        {
            curnt = bd[r][c];
            if(curnt & oldt)
                return 1;

            oldt = curnt;
            if (!bd[r][c])
                for (i = c - 1; i >= 0; i--)
                    if (bd[r][i])
                        return 1;
        }
    }
    return 0;
}

int validup(int bd[BS][BS])
{
    int r, c;
    int curnt = 0;
    int oldt = 0;
    int i;

    for (c = 0; c < BS; ++c)
    {
        oldt = 0;
        for (r = 0; r < BS; ++r)
        {
            curnt = bd[r][c];
            if(curnt & oldt)
                return 1;

            oldt = curnt;
            if (!bd[r][c])
                for (i = r + 1; i < BS; i++)
                    if (bd[i][c])
                        return 1;
        }
    }
    return 0;
}

int validdown(int bd[BS][BS])
{
    int r, c;
    int curnt = 0;
    int oldt = 0;
    int i;

    for (c = 0; c < BS; ++c)
    {
        oldt = 0;
        for (r = (BS - 1); r >= 0; --r)
        {
            curnt = bd[r][c];
            if(curnt & oldt)
                return 1;

            oldt = curnt;
            if (!bd[r][c])
                for (i = r - 1; i >= 0; i--)
                    if (bd[i][c])
                        return 1;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

