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
        /*else if (strcmp(categorie, "Ver") == 0) {
            add_verbe(ws,treeVerbe);



        }
        else if (strcmp(categorie, "Adj") == 0) {
            add_adj(ws,treeAdj);


        }else if (strcmp(categorie, "Adv") == 0) {
            add_adv(ws,treeAdv);


        }*/


    }

}

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
    strcpy(ff_nom->base,ws->base);
    printf("ff_2\n");
    printf("%s\n",ws->mot);
    ff_nom->nb_ff++;


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

node_nom * extract_node_nom(node_nom nodeNom)
{

    srand(time(NULL));

    int first = rand()%35;

    printf("ext 2.1\n");
    cell_nom * temp = nodeNom.liste_fils->head;
    printf("%d\n",first);

    for(int k = 0; k<first; k++)
    {
        printf("ext 2.2\n");
        if(temp == NULL)
        {
            printf("ext 2.25\n");
            temp = nodeNom.liste_fils->head;
        }
        else
        {
            temp = temp->next;
        }
    }
    if(temp == NULL)
    {
        temp = nodeNom.liste_fils->head;
    }
    printf("ext 2.3\n");
    if(temp->node == NULL)
    {
        printf("NULL NULL");
    }
    printf("%c\n",temp->node->val);
    return temp->node;
}


/***char * extract_word_nom(node_nom root)
{
    p_node_nom temp_node;
    printf("ext 1\n");
    char * word = malloc(MAX_SIZE_WORD* sizeof(char));
    printf("ext 2\n");
    temp_node = extract_char_nom(root);
    printf("ext 3\n");

    strcpy(word,&temp_node->val);
    printf("%s\n",word);
    printf("ext 4\n");

    int fin = 0;
    do
    {
        printf("ext 5\n");
        temp_node = extract_char_nom(*temp_node);
        printf("ext 5.5\n");
        strcat(word,&temp_node->val);
        printf("ext 6\n");
        if(temp_node->liste_ffleche != NULL)
        {
            int pile_face = rand()%2;
            if(pile_face == 1)
            {
                fin = 1;
            }
        }

    }while ((temp_node->liste_fils == NULL)||(fin == 0));

    printf("ext 5\n");
    printf("%s",word);

    return word;
}***/


p_forme_fleche_nom extract_ff_nom(tree_nom tree)
{

    p_node_nom temp_node;
    temp_node = extract_node_nom(tree.root);
    printf("ext 3\n");
    p_forme_fleche_nom ff_nom;
    int fin = 0;
    printf("ext 4\n");
    do
    {
        if(temp_node->liste_ffleche != NULL)
        {
            printf("ext 5\n");

            int pile_face = rand()%2;
            if(pile_face == 1)
            {
                fin = 1;
                ff_nom = temp_node->liste_ffleche->head->forme_flechie;
            }
        }
        else
        {
            temp_node = extract_node_nom(*temp_node);
        }

    }while ((temp_node->liste_fils == NULL)||(fin == 0));


    return ff_nom;

}

