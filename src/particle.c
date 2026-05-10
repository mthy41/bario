#include <raylib.h>
#include "particle.h"

static Atom *newAtomPtr(Atom* aptr){
    Atom* a     = (Atom*)malloc(sizeof(Atom));
    a->size     = aptr->size;
    a->lifeTime = aptr->lifeTime;
    a->color    = aptr->color;
    a->shape    = aptr->shape;
    a->pos      = aptr->pos;
    a->dir      = aptr->dir;

    return a;
}

static Atom* newRandCircleAtom(){
}
