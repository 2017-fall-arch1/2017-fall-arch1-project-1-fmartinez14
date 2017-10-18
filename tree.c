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
    if(strcmp(source->name,toAddElement->name) == 1){
      printf("val: ",strcmp(source->name,toAddElement->name));
      if(source -> children1 == NULL){
	source -> children1 = toAddElement;
	source -> children1-> parent = source;
	printf("Added to children 1 \n");
      }
      else{
	leTree = addElement(leTree,source-> children1, toAddElement);
      }
    }
    else{
      if(source -> children2 == NULL){
       source -> children2=  toAddElement;
       source ->children2 -> parent = source;
       printf("Added to children 2 \n");
      }
      else{
       leTree = addElement(leTree,source->children2,toAddElement);
     }
   }
  }
  return leTree;
}

tree *deleteElement(tree *leTree,tree_node *leRoot){
  if(leRoot == NULL)
    return leTree;
  if (leRoot -> children1 == NULL && leRoot-> children2 == NULL && leRoot == leTree->source){
    leTree-> source = NULL;
    return leTree;
  }
  else if(leRoot-> children1 == NULL && leRoot -> children2 == NULL){
    leTree = deleteARoot(leTree,leTree->source,leRoot);
    return leTree;
  }
  else if(leRoot-> children1 == NULL && leRoot -> children2 != NULL){
    if(leRoot == leTree-> source)
      leTree-> source = leRoot->children2;
    leRoot = (leRoot -> children2);
    leTree = deleteElement(leTree,leRoot->children1);
    return leTree;
  }
  else if(leRoot -> children2 == NULL && leRoot -> children1 != NULL){
    if(leRoot == leTree-> source)
      leTree->source = leRoot->children1;
    leRoot = leRoot -> children1;
    leTree = deleteElement(leTree,leRoot->children1);
    return leTree;
  }
  else{
    leRoot = leRoot -> children2;
    leTree= deleteElement(leTree,leRoot->children2);
    return leTree;
  }
}


tree *deleteARoot(tree *leTree, tree_node *currentNode, tree_node *deleteMe){
  if(currentNode == NULL)
    return leTree;
  else if(currentNode-> children1 == deleteMe){
    currentNode-> children1 = NULL;
    return leTree;
}
  else if(currentNode-> children2 == deleteMe){
    currentNode->children2= NULL;
    return leTree;
  }
  else{
    int difference = strcmp(currentNode->name,deleteMe);
      if(difference ==1 && currentNode -> children1 != NULL)
	deleteARoot(leTree,currentNode->children1,deleteMe);
      else if(difference == -1 && currentNode -> children2 != NULL)
	deleteARoot(leTree,currentNode->children2,deleteMe);
      else
	return leTree;
    }
}

tree_node *findElement(tree_node *leRoot, char *findMe){
  if(leRoot == NULL){
    printf("No such name in tree!\n");
  }
  int difference = strcmp(leRoot->name, findMe);
  if(difference ==0)
    return leRoot;
  else if(difference == 1 && leRoot -> children1 != NULL){
    findElement(leRoot->children1, findMe);
  }
  else if(difference == -1 && leRoot-> children2 != NULL){
    findElement(leRoot->children2, findMe);
  }
  else
    return NULL;
}


void printTree(tree_node *leRoot){
  if(leRoot == NULL)
    return;
  if(leRoot != NULL && leRoot-> name != NULL ){
    printTree(leRoot->children1);
    printf("Employee name: %s \n",leRoot->name);
    printTree(leRoot->children2);
  }
}



void writeTree(tree_node *leRoot, FILE *leFile){
  if(leRoot == NULL)
    return;
  if(leRoot != NULL && leRoot-> name != NULL){
    char *writeMe = malloc(strlen(leRoot->name) +1);
    writeMe= strcat(leRoot->name,";");
    writeTree(leRoot->children1,leFile);
    fwrite(writeMe,1,strlen(writeMe),leFile);
    writeTree(leRoot->children2,leFile);
  }
}
