#pragma once

#include "Structure.h"

class Grille: public Structure
{
public:
    DECLARE_SAVED(Grille, Structure);
    DECLARE_GET_TYPE_ITEM(Grille);
    Grille();
};
ADD_TO_TYPELIST(Grille);
