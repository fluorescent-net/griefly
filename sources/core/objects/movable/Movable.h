#pragma once

#include "core/objects/MaterialObject.h"

namespace kv
{

class Movable : public MaterialObject
{
public:
    DECLARE_SAVEABLE(Movable, MaterialObject);
    REGISTER_CLASS_AS(Movable);
    Movable();
    virtual bool TryMove(Dir direct);
    bool CheckMoveTime();
    virtual bool CheckPassable();
    bool MainMove();

    virtual bool Rotate(Dir dir);
    Dir GetDir() const { return direction_; }

    virtual void ProcessForce();
    virtual void ApplyForce(Vector force) override;

    virtual void Delete() override { MaterialObject::Delete(); }

    virtual void Represent() override;
    virtual void Bump(IdPtr<Movable> item) override;
    virtual void BumpByGas(Dir dir, bool inside = false) override;
public:
    Vector KV_SAVEABLE(force_);
    bool KV_SAVEABLE(anchored_);
    int KV_SAVEABLE(last_move_);
    int KV_SAVEABLE(tick_speed_);
private:
    Dir KV_SAVEABLE(direction_);
};
END_DECLARE(Movable);

}
