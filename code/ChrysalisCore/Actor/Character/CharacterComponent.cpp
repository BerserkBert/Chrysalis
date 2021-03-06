#include <StdAfx.h>

#include "CharacterComponent.h"
#include <CryCore/StaticInstanceList.h>
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"
#include <Actor/ActorComponent.h>
#include <Actor/Movement/StateMachine/ActorStateEvents.h>
#include <Actor/Movement/StateMachine/ActorStateUtility.h>
#include <Actor/Character/CharacterAttributesComponent.h>


namespace Chrysalis
{
static void RegisterCharacterComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CCharacterComponent));
		// Functions
		{
		}
	}
}


void CCharacterComponent::ReflectType(Schematyc::CTypeDesc<CCharacterComponent>& desc)
{
	desc.SetGUID("{33E4A852-B605-4DEB-881F-D3EC252A9EDB}"_cry_guid);
	desc.SetEditorCategory("Actors");
	desc.SetLabel("Character");
	desc.SetDescription("No description.");
	desc.SetIcon("icons:ObjectTypes/light.ico");
	desc.SetComponentFlags({IEntityComponent::EFlags::Singleton});
}


void CCharacterComponent::Initialize()
{
	// All characters are actors.
	m_pActorComponent = m_pEntity->GetOrCreateComponent<CActorComponent>();

	// Manage attributes.
	m_pCharacterAttributesComponent = m_pEntity->GetOrCreateComponent<CCharacterAttributesComponent>();

	// Get it into a known state.
	OnResetState();
}


void CCharacterComponent::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
		// Physicalize on level start for Launcher
		case EEntityEvent::LevelStarted:

			// Editor specific, physicalize on reset, property change or transform change
		case EEntityEvent::Reset:
		case EEntityEvent::EditorPropertyChanged:
		case EEntityEvent::TransformChangeFinishedInEditor:
			OnResetState();
			break;

		case EEntityEvent::Update:
			break;
	}
}


void CCharacterComponent::OnResetState()
{
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCharacterComponent)
}