#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "bst.h"

Node* findMax(Node* root);

Node* insertNode(Node *root, int value) {

  Node* current = root;
   
  Node* new = NULL; 
  new = (Node*)malloc(sizeof(Node));
  new->data = value;
  new->right = new->left = NULL;

  if (root != NULL) {

  	while((current->left != new) || (current->right != new)) {

  		if (value > current->data) {

  			if (current->right != NULL) {
  				
  				current = current->right;
  				
  			} else {
  				
  				current->right = new;

  				break;
  			}

  		} else {

  			if (current->left != NULL) {
  				
  				current = current->left;
 				
  			} else {
  				
  				current->left = new;
  				break;
  			}
			
  		}
  	}
  } else {
  	root = new;
  }

	return root;

}

void printSubtree(Node *N) {

  if (N == NULL) {

    return;

  }

  if (N->left != NULL) {

    printSubtree(N->left);

  } else {

      printf("%d\n", N->data);

      if (N->right == NULL) {

        return;

      } else {

        printSubtree(N->right);

    return;

  }
}

  if ((N->left == NULL && N-> right == NULL) || 
    (N->left != NULL && N->right != NULL)) {

  printf("%d\n", N->data);

  }

  if (N->right != NULL) {

    printSubtree(N->right);

  } else {

    printf("%d\n", N->data);
    return;

  }	

}


int countNodes(Node *N) {


  int count = 0;

  if (N == NULL) {

  return 0;

  }

  if (N->left != NULL) {

    count += countNodes(N->left);

  } else {

      count++;

      if (N->right == NULL) {

        return count;

      } else {

        count += countNodes(N->right);
        return count;

      }
  }

  if ((N->left == NULL && N-> right == NULL) || 
    (N->left != NULL && N->right != NULL)) {

  count++;

  }

  if (N->right != NULL) {

    count += countNodes(N->right);

  } else {

    count++;
    return count;

  }

  return count;

}


Node* deleteNode(Node* root, int value) {

  if (root == NULL) {

    return NULL;

  }

  if (value > root->data) {

    root->right = deleteNode(root->right, value);

  } else if (value < root->data) {

    root->left = deleteNode(root->left, value);

  } else {

    if (root->left == NULL && root->right == NULL) {

      free(root);
      return NULL;

    } else if (root->left == NULL || root->right == NULL) {

      Node* temp = NULL;

      if (root->left == NULL) {

        temp = root->right;

      } else {

        temp = root->left;

      }

        free(root);
        return temp;

    } else {

      Node* temp2 = findMax(root->left);
      root->data = temp2->data;
      root->left = deleteNode(root->left, temp2->data);

      }

  }

  return root;

}


int sumSubtree(Node *N) {

  int total = 0;

  if (N == NULL) {

    return 0;

  }

  if (N->left != NULL) {

    total += sumSubtree(N->left);

  } else {

    total += N->data;

    if (N->right == NULL) {

      return total;

    } else {

      total += sumSubtree(N->right);
      return total;

    }
  }

  if ((N->left == NULL && N-> right == NULL) || 
    (N->left != NULL && N->right != NULL)) {

  total += N->data;

  }

  if (N->right != NULL) {

    total += sumSubtree(N->right);

  } else {

    total += N->data;
    return total;

  }

  return total;

}


Node* freeSubtree(Node* N) {

  if (N == NULL) {

    return N;

  }

  freeSubtree(N->left);

  freeSubtree(N->right);

  free(N);

  N = NULL;

  return N;
}


Node* findMax(Node* root) {

  if (root == NULL) {

    return NULL;

  } else if (root->right != NULL) {

    return findMax(root->right);

  }

  return root;

}
