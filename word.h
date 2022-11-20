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
p_node_nom ixtract_node_nom(p_node_nom nodeNom);
p_node_nom ixtract_ff_Pnom (tree_nom tree);



void add_adj(p_word_stock ws,tree_adj *tree);
void add_forme_flechie_adj(node_adj * new,p_word_stock ws);
p_node_adj createNode_adj(p_word_stock ws, int cpt);

void add_verbe(p_word_stock ws,tree_verbe *tree);
void add_forme_flechie_verbe(node_verbe * new,p_word_stock ,int test);
p_node_verbe createNode_verbe(p_word_stock ws, int cpt);

void add_adv(p_word_stock ws,tree_adv *tree);
p_node_adv createNode_adv(p_word_stock ws, int cpt);

void cree_phrase(tree_nom treenom,tree_adv treeadv,tree_verbe treeverbe,tree_adj treeadj);



#endif //DICO_OFF_WORD_H
