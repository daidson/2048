/***************************************************************************
 *   ex2048.c                                 Version 20170503.222742      *
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
 *   Email:                                                                *
 *   Webpage:                                                              *
 *   Phone: +55 81                                                         *
 *                                                                         *
 *   Daidson Fonseca Alves                                                 * 
 *   Email:                                                                *
 *   Webpage:                                                              *
 *   Phone: +55 81                                                         *
 *                                                                         *
 *   Douglas Azevedo Pereira Dantas                                        * 
 *   Email:                                                                *
 *   Webpage:                                                              *
 *   Phone: +55 81                                                         *
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
    return;
}

/* ---------------------------------------------------------------------- */
/* add a tile */
void addtile(int bd[BS][BS])
{
    time_t seed;
    int r, c, tile;
    
    srand((unsigned) time(&seed));
    while(1)
    {
        r=rand()%BS;
        c=rand()%BS;

        if (!bd[r][c])
        {
            if (rand()%10)
                tile=2;
            else
                tile=4;
            bd[r][c]=tile;
            return;
        }
    }
}

/* ---------------------------------------------------------------------- */
/* print the board */
void print(int bd[BS][BS])
{
    int line=0, column=0;

    for(line=0; line<BS; ++line)
    {
        for(column=0; column<BS; ++column)
            if (bd[line][column])
                printf("|\t%d\t ", bd[line][column]);
            else
                printf("|\t  \t ");
        
        printf("|\n");
    }
    
    return;
}

/* ---------------------------------------------------------------------- */
/* get the move 'u'p, 'd'own, 'l'eft, 'r'ight or '\0' if no moves left */
char getmove(int bd[BS][BS])
{
    char in, clean;

    printf("Next move: \n");

    while(1)
    {
        in=getchar();
        while((clean=getchar()) != '\n' && clean != EOF);
        
        switch(in)
        {
            case 'u':
                return 'u';
            case 'd':
                return 'd';
            case 'l':
                return 'l';
            case 'r':
                return 'r';
            default:
                printf("Entrada invalida.\n");
        }
    }
    
    return '\0';
}

/* ---------------------------------------------------------------------- */
/* apply the move m to the board bd and return the partial score */
int applymove(char m, int bd[BS][BS])
{
    return 0;
}

/* ---------------------------------------------------------------------- */
/* print the goodbye message and congratulations on the score */
void goodbye(int score)
{
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
        case 'l':
            if (validleft(bd))
                return 1;
        case 'r':
            if (validright(bd))
                return 1;
        case 'u':
            if (validup(bd))
                return 1;
        case 'd':
            if (validdown(bd))
                return 1;
    }
}

int validleft(int bd[BS][BS])
{
    return 1;
}

int validright(int bd[BS][BS])
{
    return 1;
}

int validup(int bd[BS][BS])
{
    return 1;
}

int validdown(int bd[BS][BS])
{
    return 1;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

