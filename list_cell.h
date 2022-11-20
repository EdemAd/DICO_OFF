//
// Created by edema on 17/11/2022.
//

#ifndef DICO_OFF_LIST_CELL_H
#define DICO_OFF_LIST_CELL_H



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

///----------------------------------------NOM------------------------------------------------

typedef struct node_nom
{
    char val;
    struct s_ht_nom_list * liste_fils;
    struct s_ht_ff_nom_list * liste_ffleche;
    int nb_ff;


}node_nom, * p_node_nom;

struct s_cell_nom
{
    p_node_nom node;
    struct s_cell_nom * next;

};
typedef struct s_cell_nom cell_nom, * p_cell_nom;



struct s_ht_nom_list
{
    p_cell_nom head;
    p_cell_nom tail;

};
typedef struct s_ht_nom_list t_ht_nom_list;



typedef struct s_cell_forme_flechie_nom{

    struct forme_fleche_nom * forme_flechie;
    struct s_cell_forme_flechie_nom *next;

}cell_fleche_nom, * p_cell_ff_nom;


struct s_ht_ff_nom_list
{
    p_cell_ff_nom head;
    p_cell_ff_nom tail;

};
typedef struct s_ht_ff_nom_list t_ht_ff_nom_list;


typedef struct forme_fleche_nom
{
    int nombre;
    int genre;
    char * forme_flechie;

}forme_fleche_nom,* p_forme_fleche_nom;

typedef struct tree_nom
{
    node_nom root;

}tree_nom;



///--------------------ADJECTIFS-------------------------------------------------

typedef struct node_adj
{
    char val;
    struct s_ht_adj_list * liste_fils;
    struct s_ht_ff_adj_list * liste_ffleche;
    int nb_ff;

}node_adj, * p_node_adj;

struct s_cell_adj
{
    p_node_adj node;
    struct s_cell_adj * next;

};
typedef struct s_cell_adj cell_adj, * p_cell_adj;



struct s_ht_adj_list
{
    p_cell_adj head;
    p_cell_adj tail;

};
typedef struct s_ht_adj_list t_ht_adj_list;



typedef struct s_cell_forme_flechie_adj{

    struct forme_fleche_adj * forme_flechie;
    struct s_cell_forme_flechie_adj * next;

}cell_fleche_adj, * p_cell_ff_adj;


struct s_ht_ff_adj_list
{
    p_cell_ff_adj head;
    p_cell_ff_adj tail;

};
typedef struct s_ht_ff_adj_list t_ht_ff_adj_list;


typedef struct forme_fleche_adj
{
    int nombre;
    int genre;
    char * forme_flechie;


}forme_fleche_adj,* p_forme_fleche_adj;

typedef struct tree_adj
{
    node_adj root;

}tree_adj;


///-------------------------------VERBES------------------------------------

typedef struct node_verbe
{
    char val;
    struct s_ht_verbe_list * liste_fils;
    struct s_ht_ff_verbe_list * liste_ffleche;
    int nb_ff;

}node_verbe, * p_node_verbe;

struct s_cell_verbe
{
    p_node_verbe node;
    struct s_cell_verbe * next;

};
typedef struct s_cell_verbe cell_verbe, * p_cell_verbe;



struct s_ht_verbe_list
{
    p_cell_verbe head;
    p_cell_verbe tail;

};
typedef struct s_ht_verbe_list t_ht_verbe_list;



typedef struct s_cell_forme_flechie_verbe{

    struct forme_fleche_verbe *forme_flechie;
    struct s_cell_forme_flechie_verbe *next;

}cell_fleche_verbe,* p_cell_ff_verbe;


struct s_ht_ff_verbe_list
{
    p_cell_ff_verbe head;
    p_cell_ff_verbe tail;

};
typedef struct s_ht_ff_verbe_list t_ht_ff_verbe_list;


typedef struct forme_fleche_verbe
{
    char * temps;
    int nombre;
    int genre;
    char * forme_flechie;


}forme_fleche_verbe,* p_forme_fleche_verbe;

typedef struct tree_verbe
{
    node_verbe root;

}tree_verbe;


///--------------------------ADVERBE------------


typedef struct node_adv
{
    char val;
    struct s_ht_adv_list * liste_fils;
    int fin_mot;

}node_adv, * p_node_adv;

struct s_cell_adv
{
    p_node_adv node;
    struct s_cell_adv * next;

};
typedef struct s_cell_adv cell_adv, * p_cell_adv;


struct s_ht_adv_list
{
    p_cell_adv head;
    p_cell_adv tail;

};
typedef struct s_ht_adv_list t_ht_adv_list;

typedef struct tree_adv
{
    node_adv root;

}tree_adv;


p_cell_nom createCell_nom(p_node_nom);
t_ht_nom_list * createList_nom();
forme_fleche_nom * create_ff_nom();
t_ht_ff_nom_list * create_ff_list_nom();
p_cell_ff_nom createCell_ff_nom(forme_fleche_nom *);


p_cell_adj createCell_adj(p_node_adj);
t_ht_adj_list * createList_adj();
forme_fleche_adj * create_ff_adj();
t_ht_ff_adj_list * create_ff_list_adj();
p_cell_ff_adj createCell_ff_adj(forme_fleche_adj *);


p_cell_verbe createCell_verbe(p_node_verbe);
t_ht_verbe_list * createList_verbe();
forme_fleche_verbe * create_ff_verbe();
t_ht_ff_verbe_list * create_ff_list_verbe();
p_cell_ff_verbe createCell_ff_verbe(forme_fleche_verbe *);

p_cell_adv createCell_adv();
t_ht_adv_list * createList_adv();







#endif //DICO_OFF_LIST_CELL_H
