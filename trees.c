#include<stdio.h>
#include<stdlib.h>

struct bst {
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst*node;

struct bst *createTree(struct bst *node, int data) {
    if(node == NULL) {
        struct bst *temp;
        temp = (struct bst *)malloc(sizeof(struct bst));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(data < node->data) {
        node->left = createTree(node->left, data);
    } else {
        node->right = createTree(node->right, data);
    }
    return node;
}

void inorder(struct bst *node) {
    if(node != NULL) {
        inorder(node->left);
        printf("\t%d\t",node->data);
        inorder(node->right);
    }
}

void preorder(struct bst *node) {
    if(node != NULL) {
        printf("\t%d\t",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct bst *node) {
    if(node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("\t%d\t",node->data);
    }
}

struct bst *search(struct bst *node, int key) {
    if(node == NULL) {
        return NULL;
    }
    if(key == node->data) {
        return node;
    } else if(key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

struct bst *insert(struct bst *node, int key) {
    if(node == NULL) {
        struct bst *temp;
        temp = (struct bst *)malloc(sizeof(struct bst));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(key < node->data) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

struct bst *deleteNode(struct bst *node, int key) {
    if(node == NULL) {
        return NULL;
    }
    if(key < node->data) {
        node->left = deleteNode(node->left, key);
    } else if(key > node->data) {
        node->right = deleteNode(node->right, key);
    } else {
        if(node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        } else if(node->left == NULL) {
            struct bst *temp = node->right;
            free(node);
            return temp;
        } else if(node->right == NULL) {
            struct bst *temp = node->left;
            free(node);
            return temp;
        } else {
            struct bst *temp = node->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

int height(struct bst *node) {
    if(node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
struct bst* inpre(struct bst* p)
{
   if (p == NULL || p->right == NULL) {
      return NULL;
   }
   p = p->right;
   while (p->left != NULL) {
      p = p->left;
   }
   return p;
}

struct bst* insucc(struct bst* p)
{
   if (p == NULL || p->right == NULL) {
      return NULL;
   }
   p = p->right;
   while (p->left != NULL) {
      p = p->left;
   }
   return p;
}
int main()
{
   int data, key, ans = 1, ch, i, n;
   struct bst* root = NULL;

   while (1) {
      printf("\n1.Insertion in Binary Search Tree");
      printf("\n2.Inorder\n3.Preorder\n4.Postorder");
      printf("\n5.Search Element in Binary Search Tree\n6.Insert in BST\n7.Delete anywhere\n8.Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &ch);
      switch (ch) {
      case 1:
         printf("\nEnter N value: ");
         scanf("%d", &n);
         printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2): \n");
         for (i = 0; i < n; i++) {
            scanf("%d", &data);
            root = createTree(root, data);
         }
         break;
      case 2:
         printf("\nInorder Traversal: \n");
         inorder(root);
         break;
      case 3:
         printf("\nPreorder Traversal: \n");
         preorder(root);
         break;
      case 4:
         printf("\nPostorder Traversal: \n");
         postorder(root);
         break;
      case 5:
         printf("Enter element to be searched: ");
         scanf("%d", &key);
         struct bst* n = search(root, key);
         if (n != NULL) {
            printf("Found: %d", n->data);
         }
         else {
            printf("Not found");
         }
         break;
      case 6:
         printf("Enter element to be inserted: ");
         scanf("%d", &key);
         root = insert(root, key);
         printf("Key inserted");
         break;
      case 7:
         printf("Enter element to be deleted: ");
         scanf("%d", &key);
         root = deleteNode(root, key);
         printf("%d key deleted", key);
         break;
      case 8:
         exit(0);
      default:
         printf("Wrong input/choice");
         break;
      }
   }
   return 0;
}
