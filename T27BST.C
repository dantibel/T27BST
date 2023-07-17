/* Belov Danil, 10-6, 17.11.21 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "bst.h"

VOID main ( VOID )
{
  BOOL run = TRUE;
  INT Key, i;
  TREE *Root = NULL;

  while (run)
  {
    printf("0 - exit | 1 - Add | 2 - Add | 3 - Del | 4 - Linearize\n"
        "8 - gremlin test | 9 - clear\n\n");
    if (Root != NULL)
      DrawTree(Root);
    else 
      printf("Tree is empty\n");
    printf("\n");
    switch (_getch())
    {
    case '0':
      run = FALSE;
      break;
    case '1':
      printf("Add(1): ");
      scanf("%d", &Key);
      AccessTreeRec(&Root, Key);
      break;
    case '2':
      printf("Add(2): ");
      scanf("%d", &Key);
      if (AccessTree(&Root, Key))
        printf("SUCCESS\n");
        break;
    case '3':
      printf("Del: ");
      scanf("%d", &Key);
      DelNode(&Root, Key);
      break;
    case '4':
      printf("%d\n", Linearize(&Root));
      break;
    case '8':
      srand(0);
      for (i = 0; i < 100; i++)
        AccessTree(&Root, rand() % 100);
      /*
      (for (i = 0; i < 100; i++)
        DelNode(&Root, rand() % 10000);
      */
      break;
    case'9':
      ClearTree(&Root);
      break;
    }
  }
  ClearTree(&Root);
}