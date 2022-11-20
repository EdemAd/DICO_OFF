//
// Created by edema on 17/11/2022.
//

#include "list_cell.h"
#include "word.h"



p_cell_nom createCell_nom(p_node_nom node)
{
    p_cell_nom nom = malloc(sizeof(cell_nom));
    nom->node = node;
    nom->next = NULL;

    return nom;
}


t_ht_nom_list * createList_nom()
{
    t_ht_nom_list * L = malloc(sizeof(t_ht_nom_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}

t_ht_ff_nom_list * create_ff_list_nom()
{
    t_ht_ff_nom_list * L = malloc(sizeof(t_ht_ff_nom_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}

forme_fleche_nom * create_ff_nom()
{
    forme_fleche_nom * ff_nom = malloc(sizeof(forme_fleche_nom));
    ff_nom->forme_flechie = malloc(MAX_SIZE_WORD*sizeof(char ));
    ff_nom->base = malloc(MAX_SIZE_WORD* sizeof(char));
    ff_nom->genre = 0;
    ff_nom->nombre = 0;


    return ff_nom;
}


p_cell_ff_nom createCell_ff_nom(forme_fleche_nom * ff_nom)
{
    p_cell_ff_nom ff = malloc(sizeof(cell_fleche_nom));
    ff->forme_flechie = ff_nom;
    ff->next = NULL;

    return ff;

}


///---------------------------adj---------------------------------------------------------------------------------
p_cell_adj createCell_adj(p_node_adj node)
{
    p_cell_adj adj = malloc(sizeof(cell_adj));
    adj->node = node;
    adj->next = NULL;

    return adj;
}


t_ht_adj_list * createList_adj()
{
    t_ht_adj_list * L= malloc(sizeof(t_ht_adj_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}



t_ht_ff_adj_list * create_ff_list_adj()
{
    t_ht_ff_adj_list * L = malloc(sizeof(t_ht_ff_adj_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}


p_cell_ff_adj createCell_ff_adj(p_forme_fleche_adj ff_adj)
{
    p_cell_ff_adj ff = malloc(sizeof(cell_fleche_adj));
    ff->forme_flechie = ff_adj;
    ff->next = NULL;

    return ff;

}

forme_fleche_adj * create_ff_adj()
{
    forme_fleche_adj * ff_adj = malloc(sizeof(forme_fleche_adj));
    ff_adj->forme_flechie = malloc(MAX_SIZE_WORD*sizeof(char ));
    ff_adj->base = malloc(MAX_SIZE_WORD*sizeof(char ));
    ff_adj->genre = 0;
    ff_adj->nombre = 0;


    return ff_adj;
}



///--------------------------------------------verbe-----------------------------------------------------------------

p_cell_verbe createCell_verbe(p_node_verbe node)
{
    p_cell_verbe verbe = malloc(sizeof(cell_adj));
    verbe->node = node;
    verbe->next = NULL;

    return verbe;
}


t_ht_verbe_list * createList_verbe()
{
    t_ht_verbe_list * L= malloc(sizeof(t_ht_verbe_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}



t_ht_ff_verbe_list * create_ff_list_verbe()
{
    t_ht_ff_verbe_list * L = malloc(sizeof(t_ht_ff_verbe_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}


p_cell_ff_verbe createCell_ff_verbe(p_forme_fleche_verbe ff_verbe)
{
    p_cell_ff_verbe ff = malloc(sizeof(cell_fleche_verbe));
    ff->forme_flechie = ff_verbe;
    ff->next = NULL;

    return ff;

}

forme_fleche_verbe * create_ff_verbe()
{
    forme_fleche_verbe * ff_verbe = malloc(sizeof(forme_fleche_verbe));
    ff_verbe->forme_flechie = malloc(MAX_SIZE_WORD*sizeof(char ));
    ff_verbe->base = malloc(MAX_SIZE_WORD*sizeof(char ));
    ff_verbe->genre = 0;
    ff_verbe->nombre = 0;


    return ff_verbe;
}


///-------------------------------------------------------------------adv-------------------------------------------

p_cell_adv  createCell_adv(p_node_adv node)
{
    p_cell_adv  adverbe = malloc(sizeof(cell_adv));
    adverbe->node = node;
    adverbe->next = NULL;

    return adverbe;
}


t_ht_adv_list * createList_adv()
{
    t_ht_adv_list * L=malloc(sizeof(t_ht_adv_list));
    L->head = NULL;
    L->tail = NULL;

    return L;
}
