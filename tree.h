#ifndef tree_included
#define tree_included



typedef struct tree_node{
  char *name;
  struct tree_node *children1;
  struct tree_node *children2;
  struct tree *parent;
}tree_node;
typedef struct tree{
  tree_node *source;
  int sizeTree;
}tree;

extern int llDoCheck;




 tree *treeAlloc();

tree *treeAdder(tree *leTree,char *employeename);
tree *addElement(tree *leTree, tree_node *source, tree_node *toAddElement);
void printTree(tree_node *leRoot);

#endif
