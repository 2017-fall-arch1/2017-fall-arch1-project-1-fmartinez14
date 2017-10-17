 
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
  char *temporal;
  temporal = malloc(sizeof(char) * strlen(employeename));
  strcpy(temporal,employeename);
  toAdd->name = temporal;
  toAdd->children1=NULL;
  toAdd->children2=NULL;
  leTree = addElement(leTree, leTree-> source, toAdd);
  return leTree;
}


tree *addElement(tree *leTree, tree_node *source, tree_node *toAddElement){
  if(source == NULL){
    leTree -> source = toAddElement;
    source =  toAddElement;
    printf("Added to source \n");
  }
  else{
    if(source -> children1 == NULL){
      source -> children1 = toAddElement;
      printf("Added to children 1 \n");
      
    }
   else if(source -> children2 == NULL){
     source -> children2=  toAddElement;
     printf("Added to children 2 \n");
    }
   else{
     leTree = addElement(leTree,source->children1,toAddElement);
   }
  }
  return leTree;
}


void printTree(tree_node *leRoot){
  if(leRoot == NULL)
    return;
  if(leRoot != NULL){
    printTree(leRoot->children1);
    printf("Employee name: %s \n",leRoot->name);
    printTree(leRoot->children2);
  }
}
