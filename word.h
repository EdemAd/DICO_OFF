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
    char * mot;
    char * base;
    char * explain;
}word_stock,*p_word_stock;


void readline (char *, tree_adv *, tree_verbe *, tree_nom *, tree_adj *);


void add_nom(p_word_stock ws,tree_nom *tree);
p_word_stock createws();
void add_forme_flechie_nom(node_nom * new,p_word_stock ws);
p_node_nom createNode_nom(p_word_stock ws, int cpt);
p_node_nom extract_node_nom(node_nom);
p_forme_fleche_nom extract_ff_nom(tree_nom);


#endif //DICO_OFF_WORD_H
