
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"


tree *myTree;
tree_node *myRoot;


main(){
  treeAction();
  return 0;
}


void treeAction(){
  myTree = treeAlloc();
  int selection=0;
  char fname[128];
  char employeename;
  FILE *leFile;
  int loopCheck = 1;
  //myTree-> source.name = ("%s","CheeseBalls");
  while(loopCheck == 1){
  printf("Hello! Please select an option below.\n");
  printf("1- Add a new employee.\n");
  printf("2- Delete an employee\n");
  printf("3- List all employees \n");
  printf("4- Write all employees to a text file\n");
  printf("5- Read employees from a text file \n");
  printf("6- Exit program\n");
  printf("Make your selection: ");
  scanf("%d",&selection);
  if(selection == 1){
    scanf("%s",&employeename);
    myTree =  treeAdder(myTree,&employeename);
    printf("Employee added!\n");
  }
  if(selection ==2){
    scanf("%s",&employeename);
    tree_node *deleteMe;
    deleteMe= findElement(myTree->source,&employeename);
    if(deleteMe == NULL)
      printf("No such employee with this name!");
    else{
      myTree= deleteElement(myTree, deleteMe);
      printf("Employee deleted!\n");
    }
  }
  if(selection==3){
    if(myTree == NULL)
      printf("No employees \n");
    else{
    printf("Listing employees:\n");
    printTree(myTree->source);
    }
  }
  if(selection==4){
    printf("Write the filename, please!:              ");
    scanf("%s",fname);
    leFile= fopen(fname,"w");
    printf("Writing to file..\n");
    writeTree(myTree->source,leFile);
  }
  if(selection==5){
    printf("Reading from file.. \n");
  }
  if(selection ==6){
    printf("Thank you for using our product today!\n");
    loopCheck =0;
  }
  if(selection != 1 && selection != 2 && selection != 3 && selection !=4 && selection != 5 && selection != 6){
    printf("Invalid input! Try again.\n");
  }
  }
}


