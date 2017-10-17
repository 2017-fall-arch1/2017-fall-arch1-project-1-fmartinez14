 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"



tree_node mySource;
tree *treeAlloc(){
  tree *leTree = (tree *) malloc(sizeof(tree));
  leTree->source = NULL;
  return leTree;
}

tree *treeAdder(tree *leTree, char *employeename){
  tree_node *toAdd = (tree_node *) malloc(sizeof(tree_node));
  toAdd->name = employeename;
  toAdd->children1=NULL;
  toAdd->children2=NULL;
  if(leTree-> source == NULL){
    leTree-> source = toAdd;
  }
  else{
    leTree->source->children1 = toAdd;
  }
  printf("Added new employee: %s \n",toAdd->name);
  return leTree;
}


void printTree(tree *leTree){
  tree_node *temp = (tree_node *) malloc(sizeof(tree_node));
  temp = leTree ->source;
  while(temp != NULL){
    printf("%s \n", temp->name);
    if(temp->children1 != NULL){
      temp = temp->children1;
    }
    else if(temp-> children2 != NULL){
      temp = temp->children2;
    }
    else{
      break;
    }
  }
}
