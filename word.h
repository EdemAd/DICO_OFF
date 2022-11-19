//
// Created by edema on 17/11/2022.
//

#ifndef DICO_OFF_WORD_H
#define DICO_OFF_WORD_H

#define MAX_LINE_SIZE 150
#define MAX_SIZE_WORD 30

#include "list_cell.h"


typedef struct word_stock
{
    char *mot;
    char *base;
    char *explain;
}word_stock,*p_word_stock;


void readline (char *, tree_adv *, tree_verbe *, tree_nom *, tree_adj *);


void add_nom(p_word_stock ws,tree_nom *tree);


#endif //DICO_OFF_WORD_H