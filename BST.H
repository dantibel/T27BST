/* Belov Danil, 10-6, 17.11.21 */

#ifndef __LIST_H_
#define __LIST_H_

#define VOID void

#include <commondf.h>

/* Debug memory allocation support */
#ifndef _NDEBUG
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#  define SetDbgMemHooks() \
     _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
       _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else /* _DEBUG */
#  define SetDbgMemHooks() ((void)0)
#endif /* _DEBUG */
#include <stdlib.h>

#define STR_MAX 100

typedef struct tagTREE TREE;
struct tagTREE
{
  INT Key;
  struct tagTREE *Less, *More;
};

VOID DrawTree( TREE *T );
VOID PutTree( TREE *T );
VOID PutTree2( TREE *T );
BOOL AccessTreeRec( TREE **T, INT Key );
BOOL AccessTree( TREE **T, INT Key );
BOOL DelNode( TREE **T, INT Key );
INT Linearize( TREE **T );
VOID ClearTree( TREE **T );
//VOID Display( TREE *T );

#endif