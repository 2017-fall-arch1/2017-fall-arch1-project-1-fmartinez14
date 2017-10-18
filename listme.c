
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"


tree *myTree; //declaring the data structures.
tree_node *myRoot;


main(){
  treeAction();
  return 0;
}


void treeAction(){ //Menu selection screen.
  myTree = treeAlloc();
  int selection=0;
  char fname[128];
  char employeename;
  FILE *leFile;
  FILE *leFileRead;
  char fnameRead[128];
  int loopCheck = 1;
  while(loopCheck == 1){ //Keep program running until user stops it.
  printf("Hello!! Please select an option below.\n");
  printf("1- Add a new employee.\n");
  printf("2- Delete an employee\n");
  printf("3- List all employees \n");
  printf("4- Write all employees to a text file\n");
  printf("5- Read employees from a text file \n");
  printf("6- Exit program\n");
  printf("Make your selection: ");
  scanf("%d",&selection);
  if(selection == 1){ //Insertion method.
    scanf("%s",&employeename);
    myTree =  treeAdder(myTree,&employeename);
    printf("Employee added!\n");
  }
  if(selection ==2){ //Delete method.
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
  if(selection==3){ //Print tree method.
    if(myTree == NULL)
      printf("No employees \n");
    else{
    printf("Listing employees:\n");
    printTree(myTree->source);
    }
  }
  if(selection==4){ //Write to file method.
    printf("Write the filename, please!:              ");
    scanf("%s",fname);
    leFile= fopen(fname,"w");
    if(leFile != NULL){
    printf("Writing to file..\n");
    writeTree(myTree->source,leFile);
    }
    else{
      printf("Invalid file name! \n");
    }
  }
  if(selection==5){ //Read from file method.
    printf("Write the filename, please!:               ");
    scanf("%s",fnameRead);
    leFileRead= fopen(fnameRead,"r");
    if(leFileRead != NULL){
    printf("Reading from file.. \n");
    readTree(myTree,leFileRead);
    }
    else{
      printf("Invalid file name! \n");
    }
  }
  if(selection ==6){ //Close program.
    printf("Thank you for using our product today!\n");
    loopCheck =0;
  }//Persistance to menu until input '6' is given.
  if(selection != 1 && selection != 2 && selection != 3 && selection !=4 && selection != 5 && selection != 6){
    printf("Invalid input! Try again.\n");
  }
  }
}


