/* Belov Danil, 10-6, 17.11.21 */

#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/* Prifix output tree function */
VOID PutTree( TREE *T )
{
  if (T == NULL)
    printf("*");
  else
  {
    printf("%d(", T->Key);
    PutTree(T->Less);
    printf(",");
    PutTree(T->More);
    printf(")");
  }
} /* End of 'PutTree' function */

/* Infix output tree function */
VOID PutTree2( TREE *T )
{
  if (T == NULL)
    printf("* ");
  else
  {
    PutTree2(T->Less);
    printf("%d ", T->Key);
    PutTree2(T->More);
  }
} /* End of 'Puttree2' function */

/* Draw tree function */
VOID DrawTree( TREE *T )
{
  static INT Level;

  if (T != NULL)
  {
    Level++;
    DrawTree(T->More);
    printf("%*c%d\n", Level * 5, ' ', T->Key);
    DrawTree(T->Less);
    Level--;
  }
} /* End of 'DrawTree' function */

/* Add new element to tree function (recursion)*/
BOOL AccessTreeRec( TREE **T, INT Key )
{
  if (*T == NULL)
  {
    *T = malloc(sizeof(TREE));
    if (*T == NULL)
    {
      printf("FAIL: No enough memeory\n\n");
      return FALSE;
    }
    (*T)->Key = Key;
    (*T)->Less = NULL;
    (*T)->More = NULL;
    return TRUE;
  }
  if ((*T)->Key == Key)
  {
    printf("FAIL: %d already exist\n\n", Key);
    return FALSE;
  }
  else if ((*T)->Key < Key)
    AccessTreeRec(&(*T)->More, Key);
  else
    AccessTreeRec(&(*T)->Less, Key);
  return TRUE;
} /* End of 'AccessTreeRec' function */

/* Add new element to tree function */
BOOL AccessTree( TREE **T, INT Key )
{
  while (*T != NULL && (*T)->Key != Key)
    if ((*T)->Key < Key)
      T = &(*T)->More;
    else
      T = &(*T)->Less;
  
  if (*T == NULL)
  {
    if ((*T = malloc(sizeof(TREE))) != NULL)
    {
      (*T)->Key = Key;
      (*T)->Less = NULL;
      (*T)->More = NULL;
      return TRUE;
    }
    printf("FAIL: No enough memeory\n\n");
    return FALSE;
  }
  else
  {
    printf("FAIL: %d already exist\n\n", Key);
    return FALSE;
  }
} /* End of 'AccesTree' function */

/* Delete node from tree function */
BOOL DelNode( TREE **T, INT Key )
{
  TREE **P, *Old = NULL;
  
  while (*T != NULL && (*T)->Key != Key)
    if ((*T)->Key < Key)
      T = &(*T)->More;
    else
      T = &(*T)->Less;
  
  if (*T == NULL)
  {
    printf("FAIL: No this node in the tree\n\n");
    return FALSE;
  }

  Old = *T;
  P = &(*T)->Less;
  while ((*P) != NULL)
    P = &(*P)->More;
  *P = Old->More;
  *T = Old->Less;
  free(Old);
  Old = NULL;
  return TRUE;
} /* End of 'DelNode' function */

/* Linearize tree function */
INT Linearize( TREE **T )
{
  INT n = 0;
  TREE **P, **ptr;

  while (*T != NULL)
  {
    while ((*T)->Less != NULL)
    {
      P = ptr = &(*T)->Less;
      while ((*P)->More != NULL)
        P = &(*P)->More;
      (*P)->More = *T;
      *T = *ptr;
    }

    T = &(*T)->More;
    n++;
  }
  return n;
} /* End of 'Linarize' function */

/* Clear tree function */
VOID ClearTree( TREE **T )
{
  if (*T != NULL)
  {
    ClearTree(&(*T)->Less);
    ClearTree(&(*T)->More);
    free(*T);
    *T = NULL;
  }
} /* End of 'ClearTree' function */