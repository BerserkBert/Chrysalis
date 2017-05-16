#pragma once

#include "ICryMannequin.h"
#include <Actor/Animation/ActorAnimation.h>


class CActor;


class CActorAnimationActionCooperative : public CAnimationAction, public IEntityEventListener
{
public:

	DEFINE_ACTION("Cooperative")

	explicit CActorAnimationActionCooperative(CActor &sourceActor, EntityId targetEntityId, FragmentID fragmentID, TagState tagState,
		TagID targetTagID, const IAnimationDatabase* pTargetOptionalDatabase = nullptr);
	~CActorAnimationActionCooperative();

protected:
	// IAction
	void Install() override;
	void Enter() override;
	void Exit() override;
	// ~IAction

	// IEntityEventListener
	virtual void OnEntityEvent(IEntity *pEntity, SEntityEvent &event) override;
	// ~IEntityEventListener

	void AddTargetToSlaveContext();
	void RemoveTargetFromSlaveContext();
	void SendStateEventCoopAnim();

	CActor &m_sourceActor;
	EntityId m_targetEntityId { INVALID_ENTITYID };
	CActor* m_pTargetActor;
	TagID m_targetTagID;
	const IAnimationDatabase* m_pTargetOptionalDatabase;
	TagID m_scopeContextId;

private:
	// Prevent implementation.
	CActorAnimationActionCooperative();
};