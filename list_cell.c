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


t_ht_nom_list createList_nom()
{
    t_ht_nom_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}

p_node_nom createNode_nom(char lettre)
{
    p_node_nom node = malloc(sizeof(node_nom));
    node->val = lettre;
    node->liste_fils = NULL;
    node->liste_ffleche = NULL;

    return node;

}

t_ht_ff_nom_list create_ff_list_nom()
{
    t_ht_ff_nom_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}


p_cell_ff_nom createCell_ff_nom(forme_fleche_nom ff_nom)
{
    p_cell_ff_nom ff = malloc(sizeof(cell_fleche_nom));
    ff->forme_flechie = &ff_nom;
    ff->next = NULL;

    return ff;

}



p_cell_adj createCell_adj(p_node_adj node)
{
    p_cell_adj adj = malloc(sizeof(cell_adj));
    adj->node = node;
    adj->next = NULL;

    return adj;
}


t_ht_adj_list createList_adj()
{
    t_ht_adj_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}

p_node_adj createNode_adj(char lettre)
{
    p_node_adj node = malloc(sizeof(node_adj));
    node->val = lettre;
    node->liste_fils = NULL;
    node->liste_ffleche = NULL;

    return node;

}

t_ht_ff_adj_list create_ff_list_adj()
{
    t_ht_ff_adj_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}


p_cell_ff_adj createCell_ff_adj(p_forme_fleche_adj ff_adj)
{
    p_cell_ff_adj ff = malloc(sizeof(cell_fleche_adj));
    ff->forme_flechie = ff_adj;
    ff->next = NULL;

    return ff;

}


p_cell_verbe createCell_verbe(p_node_verbe node)
{
    p_cell_verbe verbe = malloc(sizeof(cell_verbe));
    verbe->node = node;
    verbe->next = NULL;

    return verbe;
}


t_ht_verbe_list createList_verbe()
{
    t_ht_verbe_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}

p_node_verbe createNode_verbe(char lettre)
{
    p_node_verbe node = malloc(sizeof(node_verbe));
    node->val = lettre;
    node->liste_fils = NULL;
    node->liste_ffleche = NULL;

    return node;

}

t_ht_ff_verbe_list create_ff_list_verbe()
{
    t_ht_ff_verbe_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}


p_cell_ff_verbe createCell_ff_verbe(p_forme_fleche_verbe ff_verbe)
{
    p_cell_ff_verbe ff = malloc(sizeof(cell_fleche_verbe));
    ff->forme_flechie = ff_verbe;
    ff->next = NULL;

    return ff;

}


p_cell_adv createCell_adv(p_node_adv node)
{
    p_cell_adv adverbe = malloc(sizeof(cell_adv));
    adverbe->node = node;
    adverbe->next = NULL;

    return adverbe;
}


t_ht_adv_list createList_adv()
{
    t_ht_adv_list L;
    L.head = NULL;
    L.tail = NULL;

    return L;
}

p_node_adv createNode_adv(char lettre)
{
    p_node_adv node = malloc(sizeof(node_adv));
    node->val = lettre;
    node->liste_fils = NULL;
    node->fin_mot = 0;

    return node;

}
