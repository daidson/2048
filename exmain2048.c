/***************************************************************************/
/* <<<<<<<<<< ATENCAO: este arquivo nao deve ser alterado!!! >>>>>>>>>>>>> */
/***************************************************************************
 *   exmain2048.c                             Version 20170503.222742      *
 *                                                                         *
 *   The 2048 game                                                         *
 *   Copyright (C) 2017         by Ruben Carlo Benante                     *
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
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $ gcc exmain2048.c ex2048.c -o ex2048.x -Wall -Wextra -g -O0 -DDEBUG=1
 *
 * opcoes extras: -ansi -pedantic-errors
 */

#include "ex2048.h" /* The 2048 game library */

/* ---------------------------------------------------------------------- */
/* This is the main game algorithm
 *
 * It has the game loop.
 *
 * <<<<< This file should not be changed! >>>>>
 * 
 * The main() function just returns EXIT_SUCCESS at the end
 */
int main(void)
{
    /* local declarations */
    int bd[BS][BS]={{0}}; /* the board */
    char m; /* the move: u, d, l or r (up, down, left or right). '\0' if no moves */
    int score=0; /* your score */

    welcome(); /* print a welcome message */
    addtile(bd); /* add the first tile */
    do
    {
        addtile(bd); /* add a tile each loop */
        print(bd); /* print the board */
        if((m = getmove(bd))) /* get the move 'u'p, 'd'own, 'l'eft, 'r'ight or '\0' if no moves left */
            score += applymove(m, bd); /* apply the given move to the board */
    }while(m); /* while there is a move */

    goodbye(score); /* print the goodbye message */

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
/* <<<<<<<<<< ATENCAO: este arquivo nao deve ser alterado!!! >>>>>>>>>>>> */
/**************************************************************************/
