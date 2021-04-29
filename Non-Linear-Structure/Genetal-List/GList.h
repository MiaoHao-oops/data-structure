#ifndef _GLIST_H_
#define _GLIST_H_

#include "main.h"

Status CreateGList(GList *L, HeString S);
    /*
     * CreateGList functions as follows:
     * create the general list L with the input string S
     * S: (a1, a2, ..., an) where a1, a2, ..., an are GLists
     */

Status PutGList(GList L);
    /*
     * PutGList functions as follows:
     * print the GList in the terminal as a string, where GList is in a pair of "()"
     */

Status DelAtom(GList *L, AtomType e);
#endif