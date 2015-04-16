#include <stdio.h>
#include "naryTree.h"

#define TEST_DEPTH 8

struct naryTree* root = NULL;

struct naryTree* newTree() {
  struct naryTree* newNode = malloc(sizeof (struct naryTree));
  newNode->firstChild = newNode->nextSibling = newNode;
  return newNode;
}

struct naryTree* addChild(struct naryTree* node) {
  printf("C+");
  struct naryTree* newNode = malloc(sizeof (struct naryTree));
  newNode->firstChild = newNode->nextSibling = newNode;
  node->firstChild = newNode;
  return newNode;
}

struct naryTree* addSibling(struct naryTree* node) {
  printf("S+");
  struct naryTree* newNode = malloc(sizeof (struct naryTree));
  newNode->firstChild = newNode->nextSibling = newNode;
  node->nextSibling = newNode;
  return newNode;
}

struct naryTree* getFirstChid(struct naryTree* node) {
  return node->firstChild;
}

struct naryTree* getNextSibling(struct naryTree* node) {
  return node->nextSibling;
}

void deleteFirstChild(struct naryTree* node) {
  struct naryTree* child = node->firstChild;
  if(node != child) {       // If the is no child, nothing to do
    struct naryTree* grandChild = child->firstChild;
    if(child == grandChild) {
      node->firstChild = node;    // There is no grandchild
    } else {
      node->firstChild = grandChild;
    }
    printf("C-");
    free(child);
  }
}

void deleteNextSibling(struct naryTree* node) {
  struct naryTree* nextSibling = node->nextSibling;
  if(node != nextSibling) {       // If there is no sibling, nothing to do
    struct naryTree* nextNextSibling = nextSibling->nextSibling;
    if(nextSibling == nextNextSibling) {
      node->nextSibling = node;    // There is no nextNextSibling
    } else {
      node->nextSibling = nextNextSibling;
    }
    printf("S-");
    free(nextSibling);
  }
}

/*
 * This function will delete an entire tree or a sub-tree defined by the node passed in
 */
void deleteTree(struct naryTree* root) {
  while(node->nextSibling != node || node->firstChild != node) {
    deleteNextSibling(node);
    deleteFirstChild(node
}

/*void deleteTree(struct naryTree* root) {
  struct naryTree* node = root;
  if(node->nextSibling != node) {
    deleteTree(node->nextSibling);
    deleteNextSibling(node);
  }
  if(node->firstChild != node) {
    deleteTree(node->firstChild);
    deleteFirstChild(node);
  }
}*/

int main() {
  struct naryTree* root = NULL;
  struct naryTree* childNode = NULL;
  struct naryTree* siblingNode = NULL;
  struct naryTree* descNode = NULL;

  printf("Test 1\n");
  root = newTree();
  deleteTree(root);

  printf("Test 2\n");
  root = newTree();
  addChild(root);
  addSibling(root);
  deleteTree(root);
  printf("\n");

  printf("Test 3\n");
  root = newTree();
  childNode = root;
  for(int i = 0; i < TEST_DEPTH; i++) {
    childNode = addChild(childNode);
    siblingNode = childNode;
    for(int j = 0; j < TEST_DEPTH; j++) {
      siblingNode = addSibling(siblingNode);
      descNode = siblingNode;
      for(int k = 0; k < TEST_DEPTH; k++) {
        descNode = addChild(descNode);
        addSibling(descNode);
      }
    }
  }
  printf("\n\n");
  deleteTree(root);
  printf("\n\n");
}
