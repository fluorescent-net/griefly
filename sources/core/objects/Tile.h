#pragma once

#include <vector>

#include "turfs/Turf.h"
#include "MapObject.h"
#include "MaterialObject.h"
#include "core/atmos/AtmosHolder.h"
#include "core/SaveableOperators.h"

namespace kv
{

class CubeTile : public MapObject
{
public:
    DECLARE_SAVEABLE(CubeTile, MapObject);
    REGISTER_CLASS_AS(CubeTile);
    CubeTile();
    virtual bool AddObject(IdPtr<MapObject> item) override;
    virtual bool RemoveObject(IdPtr<MapObject> item) override;
    virtual IdPtr<MapObject> GetNeighbour(Dir direct) const override;
    IdPtr<CubeTile> GetNeighbourImpl(Dir direct) const;
    virtual void ForEach(std::function<void(IdPtr<MapObject>)> callback) override;
    virtual PassableLevel GetPassable(Dir direct) const override;
    virtual bool IsTransparent() const override;

    virtual bool CanTouch(IdPtr<MapObject> item) const override;
    virtual bool Contains(IdPtr<MapObject> item) const override;

    virtual void Bump(IdPtr<Movable> item) override;
    virtual void BumpByGas(Dir dir, bool inside = false) override;

    void SetPos(Position position)
    {
        position_ = position;
    }
    virtual Position GetPosition() const override
    {
        return position_;
    }
    virtual IdPtr<Turf> GetTurf()  override
    {
        return turf_;
    }
    virtual void SetTurf(IdPtr<Turf> turf) override
    {
        turf_ = turf;
        if (turf_.IsValid())
        {
            turf_->SetOwner(GetId());
        }
        UpdatePassable();
    }
    virtual void UpdatePassable() override;
    atmos::AtmosHolder* GetAtmosHolder() { return &atmos_holder_; }

    using InsideType = QVector<IdPtr<MaterialObject>>;
    InsideType& GetInsideList() { return inside_list_; }

    void UpdateAtmosPassable();
protected:
    virtual quint32 GetItemImpl(unsigned int hash) override;
private:
    bool CanTouch(IdPtr<MapObject> item, Dir dir) const;
    bool CanTouch(IdPtr<MapObject> item, Dir first_dir, Dir second_dir) const;

    void MoveToDir(Dir dir, Position* position) const;

    IdPtr<Turf> KV_SAVEABLE(turf_);

    atmos::AtmosHolder KV_SAVEABLE(atmos_holder_);

    Position KV_SAVEABLE(position_);

    InsideType KV_SAVEABLE(inside_list_);

    PassableLevel KV_SAVEABLE(sum_passable_all_);
    PassableLevel KV_SAVEABLE(sum_passable_up_);
    PassableLevel KV_SAVEABLE(sum_passable_down_);
    PassableLevel KV_SAVEABLE(sum_passable_left_);
    PassableLevel KV_SAVEABLE(sum_passable_right_);
};
END_DECLARE(CubeTile);

}
