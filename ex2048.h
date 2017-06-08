/***************************************************************************
 *   ex2048.h                                 Version 20170606.201555      *
 *                                                                         *
 *   The 2048 game library                                                 *
 *   Copyright (C) 2017         by Group Azaleia                           *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
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
 *   Webpage: github.com/BAMoreira                                         *
 *   Phone: +55 (81) 99145-9271                                            *
 *                                                                         *
 *   Daidson Fonseca Alves                                                 *
 *   Email:                                                                *
 *   Webpage:                                                              *
 *   Phone: +55 (81)                                                       *
 *                                                                         *
 *   Douglas Azevedo Pereira Dantas                                        *
 *   Email: douglasazvedo839@gmail.com                                     *
 *   Webpage: https://github.com/DodoAz                                    *
 *   Phone: +55 (81) 99158-2473                                             *
 *                                                                         *
 *   Maria Eduarda Azevedo Saraiva de Moraes                               *
 *   Email: eduardasaraivam@gmail.com                                      *
 *   Webpage: https://github.com/eduardasaraiva                            *
 *   Phone: +55 (81) 99952-0347                                            *
 *                                                                         *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file 2048.h
 * \ingroup Group Azaleia
 * \brief The 2048 game library
 * \details This program really do a nice job as a template, and template only!
 * \version 20170606.201555
 * \date 2017-06-06
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2017 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 */

#ifndef _2048_H
#define _2048_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h> /* Time and date functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <getopt.h> */ /* get options from system argc/argv */
#include <math.h> /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="1.0.160612.142628" */
#define VERSION "20170606.201555" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define BS 4 /**< board size */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void welcome(void); /* print a welcome message */
void addtile(int bd[BS][BS]); /* add a tile */
void print(int bd[BS][BS]); /* print the board */
char getmove(int bd[BS][BS]); /* get the move 'u'p, 'd'own, 'l'eft, 'r'ight or '\0' if no moves left */
int applymove(char m, int bd[BS][BS]); /* apply the move m to the board bd and return the partial score */
int applyright(int bd[BS][BS]);
int applyleft(int bd[BS][BS]);
int applydown(int bd[BS][BS]);
int applyup(int bd[BS][BS]);
void goodbye(int score); /* print the goodbye message and congratulations on the score */

/* add more of your own prototypes here */
int validmove(char m, int bd[BS][BS]); /* move validation */
/*int validup(int bd[BS][BS]);
int validdown(int bd[BS][BS]);i*/
int validleft(int bd[BS][BS]);
int validright(int bd[BS][BS]);

#endif /* NOT def _2048_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

