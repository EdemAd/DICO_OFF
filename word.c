//
// Created by edema on 17/11/2022.
//

#include "word.h"
#include "list_cell.h"

p_word_stock createws()
{
    p_word_stock ws = malloc(sizeof(word_stock));

    ws->mot = malloc(MAX_SIZE_WORD*sizeof(char));
    ws->base = malloc(MAX_SIZE_WORD*sizeof(char));
    ws->explain = malloc(MAX_SIZE_WORD*sizeof(char));

    return ws;
}

void readline (char* filename, tree_adv * treeAdv, tree_verbe * treeVerbe, tree_nom * treeNom, tree_adj * treeAdj)
{
    FILE * dico = fopen("test.txt","r");

    char line[MAX_LINE_SIZE];
    char delim[] ="\t \0\n";

    printf("etape 1.5\n");



    while(fgets(line,MAX_LINE_SIZE,dico) != NULL)
    {

        p_word_stock ws = createws();

        printf("etape 2\n");


        printf("etape 2.5\n");


        printf("etape 3\n");

        strcpy(ws->mot, strtok(line, delim));
        strcpy(ws->base, strtok(NULL, delim));
        strcpy(ws->explain, strtok(NULL, "\n"));

        printf("etape 4\n");

        char categorie[4];

        for (int i = 0; i < 3; i++) {
            categorie[i] = ws->explain[i];
        }

        categorie[3] ='\0';



        if (strcmp(categorie,"Nom\0") == 0)
        {
            printf("yes\n");
            add_nom(ws,treeNom);


        }
        else if (strcmp(categorie, "Ver") == 0) {
            add_verbe(ws,treeVerbe);



        }
        else if (strcmp(categorie, "Adj\0") == 0) {
            printf("yes");
            add_adj(ws,treeAdj);


        }else if (strcmp(categorie, "Adv") == 0) {
            add_adv(ws,treeAdv);


        }


    }

}

///----------------------------------------nom------------------------------------------------------

void add_nom(p_word_stock ws,tree_nom *tree)
{

    printf("etape 5\n");

    int cpt = 0;
    int fin = 0;

    p_node_nom p_node = createNode_nom(ws,cpt);
    p_cell_nom pcell_node = createCell_nom(p_node);
    printf("%c\n",p_node->val);

    if (tree->root.liste_fils->head == NULL)
    {
        printf("etape 6.5\n");
        tree->root.liste_fils->head = pcell_node;
        tree->root.liste_fils->tail = pcell_node;
        printf("etape 6.6\n");
    }
    else
    {
        printf("etape 6.7\n");
        p_cell_nom tmp = tree->root.liste_fils->head;
        printf("etape 6.8\n");
        while(fin == 0)
        {
            printf("etape 6.83\n");
            if (tmp->node->val == p_node->val)
            {
                printf("etape 6.835\n");
                fin = 1;

            }
            else
            {
                if (tmp->next == NULL)
                {
                    printf("etape 6.84\n");
                    tmp->next = pcell_node;
                    fin = 1;
                    printf("etape 6.85\n");
                    tree->root.liste_fils->tail = tmp->next;
                    printf("etape 6.87\n");

                }
                tmp = tmp->next;
            }


        }
    }
    cpt++;
    printf("etape 7\n");
    p_cell_nom tmp_list_fils = pcell_node->node->liste_fils->head;
    while(ws->base[cpt] != '\0')
    {
        p_node_nom p_node1 = createNode_nom(ws,cpt);
        p_cell_nom pcell_node1 = createCell_nom(p_node1);
        printf("etape 8\n");
        fin = 0;
        if(tmp_list_fils == NULL)
        {
            printf("etape 8.7\n");
            printf("%c\n",p_node1->val);
            tmp_list_fils = pcell_node1;
            printf("etape 8.9\n");

        }
        else {
            p_cell_nom tmp1 = tmp_list_fils;
            while ((tmp1->next!=NULL)&&(fin==0))
            {
                printf("etape 9\n");
                if(tmp1->node->val == ws->base[cpt])
                {
                    fin = 1;
                    if (ws->base[cpt+1] =='\0')
                    {
                        printf("etape 9.3\n");
                        add_forme_flechie_nom(tmp1->node,ws);
                    }

                }
                else {
                    tmp1 = tmp1->next;
                }
            }
            if ((fin==0)&&(tmp1->node->val != ws->base[cpt]))
            {
                tmp1->node = p_node1;

            }

        }
        printf("etape 10\n");
        cpt++;
        tmp_list_fils = p_node1->liste_fils->head;

    }


}

void add_forme_flechie_nom(node_nom * node, p_word_stock ws)
{

    printf("ff_1\n");
    int cpt = 0;
    forme_fleche_nom * ff_nom = create_ff_nom();
    printf("ff_1.5\n");
    strcpy(ff_nom->forme_flechie,ws->mot);
    printf("ff_2\n");
    printf("%s\n",ws->mot);
    node->nb_ff++;


    while (ws->explain[cpt]!=':') {
        cpt++;
    }
    cpt++;
    printf("ff_4\n");
    switch (ws->explain[cpt])
    {
        case 'M':
            ff_nom->genre = 1;
            printf("ff_5\n");
            break;
        case 'F':
            ff_nom->genre = 2;
            break;
        case 'I':
            ff_nom->genre = 3;
            break;
    }
    while (ws->explain[cpt]!='+'){
        cpt++;
    }
    cpt++;
    switch (ws->explain[cpt])
    {
        case 'S':
            printf("ff_6\n");
            ff_nom->nombre=4;
            break;
        case 'P' :
            ff_nom->nombre=5;
            break;
        case 'I':
            ff_nom->nombre=6;
            break;
    }
    p_cell_ff_nom cell_ff = createCell_ff_nom(ff_nom);
    printf("ff_7\n");
    if(node->liste_ffleche->head == NULL)
    {
        printf("ff_8\n");
        node->liste_ffleche->head = cell_ff;
    }
    else
    {
        p_cell_ff_nom tmp = node->liste_ffleche->head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = cell_ff;

    }
    printf("ff_final\n");

}


p_node_nom createNode_nom(p_word_stock ws, int cpt)
{
    p_node_nom node = malloc(sizeof(node_nom));
    node->val = ws->base[cpt];
    node->liste_fils = createList_nom();
    node->liste_ffleche = create_ff_list_nom();

    if (ws->base[cpt+1]=='\0')
    {
        printf("ff here\n");
        add_forme_flechie_nom(node,ws);
        printf("ff add\n");
    }
    printf("node nom create\n");

    return node;

}


///----------------------------------------------------adj----------------------------------------------------------
void add_adj(p_word_stock ws,tree_adj *tree)
{

    printf("etape 5\n");

    int cpt = 0;
    int fin = 0;

    p_node_adj p_node = createNode_adj(ws,cpt);

    p_cell_adj pcell_node = createCell_adj(p_node);
    printf("%c\n",p_node->val);

    if (tree->root.liste_fils->head == NULL)
    {
        printf("etape 6.5\n");
        tree->root.liste_fils->head = pcell_node;
        tree->root.liste_fils->tail = pcell_node;
        printf("etape 6.6\n");
    }
    else
    {
        printf("etape 6.7\n");
        p_cell_adj tmp = tree->root.liste_fils->head;
        printf("etape 6.8\n");
        while(fin == 0)
        {
            printf("etape 6.83\n");
            if (tmp->node->val == p_node->val)
            {
                printf("etape 6.835\n");
                fin = 1;

            }
            else
            {
                if (tmp->next == NULL)
                {
                    printf("etape 6.84\n");
                    tmp->next = pcell_node;
                    fin = 1;
                    printf("etape 6.85\n");
                    tree->root.liste_fils->tail = tmp->next;
                    printf("etape 6.87\n");

                }
                tmp = tmp->next;
            }


        }
    }
    cpt++;
    printf("etape 7\n");
    p_cell_adj tmp_list_fils = pcell_node->node->liste_fils->head;
    while(ws->base[cpt] != '\0')
    {
        p_node_adj p_node1 = createNode_adj(ws,cpt);
        p_cell_adj pcell_node1 = createCell_adj(p_node1);
        printf("etape 8\n");
        fin = 0;
        if(tmp_list_fils == NULL)
        {
            printf("etape 8.7\n");
            printf("%c\n",p_node1->val);
            tmp_list_fils = pcell_node1;
            printf("etape 8.9\n");

        }
        else {
            p_cell_adj tmp1 = tmp_list_fils;
            while ((tmp1->next!=NULL)&&(fin==0))
            {
                printf("etape 9\n");
                if(tmp1->node->val == ws->base[cpt])
                {
                    fin = 1;
                    if (ws->base[cpt+1] =='\0')
                    {
                        printf("etape 9.3\n");
                        add_forme_flechie_adj(tmp1->node,ws);
                    }

                }
                else {
                    tmp1 = tmp1->next;
                }
            }
            if ((fin==0)&&(tmp1->node->val != ws->base[cpt]))
            {
                tmp1->node = p_node1;

            }

        }
        printf("etape 10\n");
        cpt++;
        tmp_list_fils = p_node1->liste_fils->head;

    }


}

void add_forme_flechie_adj(node_adj * node, p_word_stock ws)
{

    printf("ff_1\n");
    int cpt = 0;
    forme_fleche_adj *ff_adj = create_ff_adj();
    printf("ff_1.5\n");
    strcpy(ff_adj->forme_flechie,ws->mot);
    printf("ff_2\n");
    printf("%s\n",ws->mot);
    node->nb_ff++;



    while (ws->explain[cpt]!=':') {
        cpt++;
    }
    cpt++;
    printf("ff_4\n");
    switch (ws->explain[cpt])
    {
        case 'M':
            ff_adj->genre = 1;
            printf("ff_5\n");
            break;
        case 'F':
            ff_adj->genre = 2;
            break;
        case 'I':
            ff_adj->genre = 3;
            break;
    }
    while (ws->explain[cpt]!='+'){
        cpt++;
    }
    cpt++;
    switch (ws->explain[cpt])
    {
        case 'S':
            printf("ff_6\n");
            ff_adj->nombre=4;
            break;
        case 'P' :
            ff_adj->nombre=5;
            break;
        case 'I':
            ff_adj->nombre=6;
            break;
    }
    p_cell_ff_adj cell_ff = createCell_ff_adj(ff_adj);
    printf("ff_7\n");
    if(node->liste_ffleche->head == NULL)
    {
        printf("ff_8\n");
        node->liste_ffleche->head = cell_ff;
    }
    else
    {
        p_cell_ff_adj tmp = node->liste_ffleche->head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = cell_ff;

    }
    printf("ff_final\n");

}


p_node_adj createNode_adj(p_word_stock ws, int cpt)
{
    p_node_adj node = malloc(sizeof(node_adj));
    node->val = ws->base[cpt];
    node->liste_fils = createList_adj();
    node->liste_ffleche = create_ff_list_adj();

    if (ws->base[cpt+1]=='\0')
    {
        printf("ff here\n");
        add_forme_flechie_adj(node,ws);
        printf("ff add\n");
    }
    printf("node adj create\n");

    return node;

}

///-------------------------------------------------------verbe------------------------------------------------------

void add_verbe(p_word_stock ws,tree_verbe *tree)
{

    printf("etape 5\n");

    int cpt = 0;
    int fin = 0;

    p_node_verbe p_node = createNode_verbe(ws,cpt);

    p_cell_verbe pcell_node = createCell_verbe(p_node);
    printf("%c\n",p_node->val);

    if (tree->root.liste_fils->head == NULL)
    {
        printf("etape 6.5\n");
        tree->root.liste_fils->head = pcell_node;
        tree->root.liste_fils->tail = pcell_node;
        printf("etape 6.6\n");
    }
    else
    {
        printf("etape 6.7\n");
        p_cell_verbe tmp = tree->root.liste_fils->head;
        printf("etape 6.8\n");
        while(fin == 0)
        {
            printf("etape 6.83\n");
            if (tmp->node->val == p_node->val)
            {
                printf("etape 6.835\n");
                fin = 1;

            }
            else
            {
                if (tmp->next == NULL)
                {
                    printf("etape 6.84\n");
                    tmp->next = pcell_node;
                    fin = 1;
                    printf("etape 6.85\n");
                    tree->root.liste_fils->tail = tmp->next;
                    printf("etape 6.87\n");

                }
                tmp = tmp->next;
            }


        }
    }
    cpt++;
    printf("etape 7\n");
    p_cell_verbe tmp_list_fils = pcell_node->node->liste_fils->head;
    while(ws->base[cpt] != '\0')
    {
        p_node_verbe p_node1 = createNode_verbe(ws,cpt);
        p_cell_verbe pcell_node1 = createCell_verbe(p_node1);
        printf("etape 8\n");
        fin = 0;
        if(tmp_list_fils == NULL)
        {
            printf("etape 8.7\n");
            printf("%c\n",p_node1->val);
            tmp_list_fils = pcell_node1;
            printf("etape 8.9\n");

        }
        else {
            p_cell_verbe tmp1 = tmp_list_fils;
            while ((tmp1->next!=NULL)&&(fin==0))
            {
                printf("etape 9\n");
                if(tmp1->node->val == ws->base[cpt])
                {
                    fin = 1;
                    if (ws->base[cpt+1] =='\0')
                    {
                        printf("etape 9.3\n");
                        add_forme_flechie_verbe(tmp1->node,ws,0);
                    }

                }
                else {
                    tmp1 = tmp1->next;
                }
            }
            if ((fin==0)&&(tmp1->node->val != ws->base[cpt]))
            {
                tmp1->node = p_node1;

            }

        }
        printf("etape 10\n");
        cpt++;
        tmp_list_fils = p_node1->liste_fils->head;

    }


}

void add_forme_flechie_verbe(node_verbe * node, p_word_stock ws,int test)
{


    printf("ff_1\n");
    int cpt = 0,a=0;
    forme_fleche_verbe *ff_verbe = create_ff_verbe();
    printf("ff_1.5\n");
    strcpy(ff_verbe->forme_flechie,ws->mot);
    printf("ff_2\n");
    printf("%s\n",ws->mot);
    node->nb_ff++;

    for (int i=0;i<test+1;i++) {
        while (ws->explain[cpt] != ':') {
            cpt++;
        }
        cpt++;
    }

    printf("ff_4\n");
    while(ws->explain[cpt]!='\0'&&ws->explain[cpt]!='+'){

        ff_verbe->temps[a];
        printf("%c\n",ws->explain[cpt]);
        cpt++;
        a++;
    }



    if (ws->explain[cpt]=='\0')
    {

        ff_verbe->nombre=0;
        ff_verbe->genre=0;

    }

    else {
        while (ws->explain[cpt] != '+') {
            cpt++;
        }
        cpt++;
        switch (ws->explain[cpt]) {
            case 'S':
                printf("ff_6\n");
                ff_verbe->nombre = 4;
                break;
            case 'P' :
                ff_verbe->nombre = 5;
                break;
            case 'I':
                ff_verbe->nombre = 6;
                break;
        }
        while (ws->explain[cpt] != '+') {
            cpt++;
        }
        cpt++;
        cpt++;
        switch (ws->explain[cpt]) {
            case '1':
                printf("ff_6\n");
                ff_verbe->nombre = 7;
                break;
            case '2' :
                ff_verbe->nombre = 8;
                break;
            case '3':
                ff_verbe->nombre = 9;
                break;
        }
        while(ws->explain[cpt]!='\0'&&ws->explain[cpt]!=':'){
            cpt++;
        }
        if (ws->explain[cpt])
            add_forme_flechie_verbe(node,ws,test+1);



    }
    p_cell_ff_verbe cell_ff = createCell_ff_verbe(ff_verbe);
    printf("ff_7\n");
    if(node->liste_ffleche->head == NULL)
    {
        printf("ff_8\n");
        node->liste_ffleche->head = cell_ff;
    }
    else
    {
        p_cell_ff_verbe tmp = node->liste_ffleche->head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = cell_ff;

    }
    printf("%d\n\n\n\n\n\n",node->nb_ff);
    printf("ff_final\n");

}


p_node_verbe createNode_verbe(p_word_stock ws, int cpt)
{
    p_node_verbe node = malloc(sizeof(node_verbe));
    node->val = ws->base[cpt];
    node->liste_fils = createList_verbe();
    node->liste_ffleche = create_ff_list_verbe();

    if (ws->base[cpt+1]=='\0')
    {
        printf("ff here\n");
        add_forme_flechie_verbe(node,ws,0);
        printf("ff add\n");
    }
    printf("node verbe create\n");

    return node;

}
///----------------------------------------------------adv-----------------------------------------------------------
void add_adv(p_word_stock ws,tree_adv *tree)
{

    printf("etape 5\n");

    int cpt = 0;
    int fin = 0;

    p_node_adv p_node = createNode_adv(ws,cpt);

    p_cell_adv pcell_node = createCell_adv(p_node);
    printf("%c\n",p_node->val);

    if (tree->root.liste_fils->head == NULL)
    {
        printf("etape 6.5\n");
        tree->root.liste_fils->head = pcell_node;
        tree->root.liste_fils->tail = pcell_node;
        printf("etape 6.6\n");
    }
    else
    {
        printf("etape 6.7\n");
        p_cell_adv tmp = tree->root.liste_fils->head;
        printf("etape 6.8\n");
        while(fin == 0)
        {
            printf("etape 6.83\n");
            if (tmp->node->val == p_node->val)
            {
                printf("etape 6.835\n");
                fin = 1;

            }
            else
            {
                if (tmp->next == NULL)
                {
                    printf("etape 6.84\n");
                    tmp->next = pcell_node;
                    fin = 1;
                    printf("etape 6.85\n");
                    tree->root.liste_fils->tail = tmp->next;
                    printf("etape 6.87\n");

                }
                tmp = tmp->next;
            }


        }
    }
    cpt++;
    printf("etape 7\n");
    p_cell_adv tmp_list_fils = pcell_node->node->liste_fils->head;
    while(ws->base[cpt] != '\0')
    {
        p_node_adv p_node1 = createNode_adv(ws,cpt);
        p_cell_adv pcell_node1 = createCell_adv(p_node1);
        printf("etape 8\n");
        fin = 0;
        if(tmp_list_fils == NULL)
        {
            printf("etape 8.7\n");
            printf("%c\n",p_node1->val);
            tmp_list_fils = pcell_node1;
            printf("etape 8.9\n");

        }
        else {
            p_cell_adv tmp1 = tmp_list_fils;
            while ((tmp1->next!=NULL)&&(fin==0))
            {
                printf("etape 9\n");
                if(tmp1->node->val == ws->base[cpt])
                {
                    fin = 1;
                    if (ws->base[cpt+1] =='\0')
                    {
                        printf("etape 9.3\n");
                        ///-----------------------------------------------------------------------
                    }

                }
                else {
                    tmp1 = tmp1->next;
                }
            }
            if ((fin==0)&&(tmp1->node->val != ws->base[cpt]))
            {
                tmp1->node = p_node1;

            }

        }
        printf("etape 10\n");
        cpt++;
        tmp_list_fils = p_node1->liste_fils->head;

    }


}

p_node_adv createNode_adv(p_word_stock ws, int cpt)
{
    p_node_adv node = malloc(sizeof(node_adv));
    node->val = ws->base[cpt];
    node->liste_fils = createList_adv();
    node->fin_mot = 0;

    if (ws->base[cpt+1]=='\0')
    {
        node->fin_mot=1;
    }
    printf("node verbe create\n");

    return node;

}