#pragma once

#include "Components.h"


namespace Chrysalis::ECS
{
struct ItemClass : public IComponent
{
	ItemClass() = default;
	virtual ~ItemClass() = default;


	virtual const entt::hashed_string& GetHashedName() const
	{
		static constexpr entt::hashed_string nameHS {"item-class"_hs};

		return nameHS;
	}


	bool Serialize(Serialization::IArchive& archive) override final
	{
		archive(maxStackSize, "maxStackSize", "maxStackSize");
		archive(animationTag, "animationTag", "animationTag");
		archive(isUniqueInventory, "isUniqueInventory", "isUniqueInventory");
		archive(isUniqueEquipment, "isUniqueEquipment", "isUniqueEquipment");
		archive(isDroppable, "isDroppable", "isDroppable");
		archive(isAutoDroppable, "isAutoDroppable", "isAutoDroppable");
		archive(isPickable, "isPickable", "isPickable");
		archive(isAutoPickable, "isAutoPickable", "isAutoPickable");
		archive(isUsable, "isUsable", "isUsable");
		archive(isTradable, "isTradable", "isTradable");
		archive(isConsumable, "isConsumable", "isConsumable");

		return true;
	}


	/** How many items may be placed into a stack. */
	uint32 maxStackSize {1};

	/** A tag(s) to apply to mannequin when this item is in use. */
	string animationTag;

	/** true if this item is unique within an inventory. */
	bool isUniqueInventory {true};

	/** true if this item is unique when equipped. */
	bool isUniqueEquipment {true};

	/** Is this entity droppable? */
	bool isDroppable {true};

	/** Is this entity droppable automatically? */
	bool isAutoDroppable {false};

	/** true if this object is able to be picked up. */
	bool isPickable {true};

	/** true if this object is automatically able to be picked up. */
	bool isAutoPickable {true};

	/** true if this object is usable. */
	bool isUsable {true};

	/** Is this entity able to be bought / picked up / given / traded to a character? */
	bool isTradable {true};

	/** Is this entity consumable? */
	bool isConsumable {false};
};
}