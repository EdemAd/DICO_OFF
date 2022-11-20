#include <stdio.h>
#include "word.h"
#include "list_cell.h"

int main() {
    tree_adj treeAdj;
    tree_nom treeNom;
    tree_verbe treeVerbe;
    tree_adv treeAdv;

    treeAdv.root.liste_fils = createList_adv();
    treeVerbe.root.liste_fils=createList_verbe();
    treeNom.root.liste_fils = createList_nom() ;
    treeAdj.root.liste_fils= createList_adj();

    printf("etape 1\n");
    readline("test.txt",&treeAdv,&treeVerbe,&treeNom,&treeAdj);
    printf("fin\n");

    /*p_forme_fleche_nom ff_nom = extract_ff_nom(treeNom);
    printf("%s",ff_nom->base);*/


}
