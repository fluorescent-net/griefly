#include "Sign.h"

using namespace kv;

WallSign::WallSign()
{
    transparent = true;
    SetPassable(Dir::ALL, passable::FULL);
    v_level = 6;

    SetSprite("icons/decals.dmi");
    SetState("bluecross2"); 

    name = "Sign";

    sign_type_ = "bluecross2";
}

void WallSign::AfterWorldCreation()
{
    MaterialObject::AfterWorldCreation();
    SetState(sign_type_);
}

void WallSign::AttackBy(IdPtr<Item> item)
{
}
