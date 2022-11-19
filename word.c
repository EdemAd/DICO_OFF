//
// Created by edema on 17/11/2022.
//

#include "word.h"
#include "list_cell.h"


void readline (char* filename, tree_adv * treeAdv, tree_verbe * treeVerbe, tree_nom * treeNom, tree_adj * treeAdj)
{
    FILE * dico = fopen("test.txt","r");

    char line[MAX_LINE_SIZE];
    char delim[] ="\t \0\n";

    printf("etape 1.5\n");
    p_word_stock ws = malloc(sizeof(word_stock));

    ws->mot = malloc(MAX_SIZE_WORD*sizeof(char));
    ws->base = malloc(MAX_SIZE_WORD*sizeof(char));
    ws->explain = malloc(MAX_SIZE_WORD*sizeof(char));


    while(fgets(line,MAX_LINE_SIZE,dico) != NULL) {

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


        } /*else if (strcmp(categorie, "Ver") == 0) {
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

}
