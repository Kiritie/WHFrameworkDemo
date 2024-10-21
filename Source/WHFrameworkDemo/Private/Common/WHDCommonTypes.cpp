#include "Common/WHDCommonTypes.h"

namespace GameplayTags
{
	////////////////////////////////////////////////////
	// Input_Player
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Interact1, "Input.Player.Interact1", "Interact1");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Interact2, "Input.Player.Interact2", "Interact2");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Interact3, "Input.Player.Interact3", "Interact3");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Interact4, "Input.Player.Interact4", "Interact4");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Interact5, "Input.Player.Interact5", "Interact5");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Dodge, "Input.Player.Dodge", "Dodge");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ToggleCrouch, "Input.Player.ToggleCrouch", "Toggle Crouch");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ToggleControlMode, "Input.Player.ToggleControlMode", "Toggle Control Mode");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ToggleLockSightTarget, "Input.Player.ToggleLockSightTarget", "Toggle LockSight Target");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ChangeHand, "Input.Player.ChangeHand", "ChangeHand");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Primary, "Input.Player.Primary", "PrimaryAction");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Secondary, "Input.Player.Secondary", "Secondary");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ReleaseSkillAbility1, "Input.Player.ReleaseSkillAbility1", "Release Skill Ability1");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ReleaseSkillAbility2, "Input.Player.ReleaseSkillAbility2", "Release Skill Ability2");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ReleaseSkillAbility3, "Input.Player.ReleaseSkillAbility3", "Release Skill Ability3");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_ReleaseSkillAbility4, "Input.Player.ReleaseSkillAbility4", "Release Skill Ability4");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_UseInventoryItem, "Input.Player.UseInventoryItem", "Use Inventory Item");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_DiscardInventoryItem, "Input.Player.DiscardInventoryItem", "Discard Inventory Item");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_PrevInventorySlot, "Input.Player.PrevInventorySlot", "Prev Inventory Slot");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_NextInventorySlot, "Input.Player.NextInventorySlot", "Next Inventory Slot");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot1, "Input.Player.SelectInventorySlot1", "Select Inventory Slot1");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot2, "Input.Player.SelectInventorySlot2", "Select Inventory Slot2");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot3, "Input.Player.SelectInventorySlot3", "Select Inventory Slot3");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot4, "Input.Player.SelectInventorySlot4", "Select Inventory Slot4");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot5, "Input.Player.SelectInventorySlot5", "Select Inventory Slot5");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot6, "Input.Player.SelectInventorySlot6", "Select Inventory Slot6");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot7, "Input.Player.SelectInventorySlot7", "Select Inventory Slot7");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot8, "Input.Player.SelectInventorySlot8", "Select Inventory Slot8");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot9, "Input.Player.SelectInventorySlot9", "Select Inventory Slot9");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_SelectInventorySlot10, "Input.Player.SelectInventorySlot10", "Select Inventory Slot10");
	
	////////////////////////////////////////////////////
	// Input_System
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_OpenInventoryPanel, "Input.System.OpenInventoryPanel", "Open Inventory Panel");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_OpenGeneratePanel, "Input.System.OpenGeneratePanel", "Open Generate Panel");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_PauseGame, "Input.System.PauseGame", "Pause Game");

	////////////////////////////////////////////////////
	// State_Character
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Dodging, "State.Character.Dodging", "Character Dodging");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Sprinting, "State.Character.Sprinting", "Character Sprinting");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Crouching, "State.Character.Crouching", "Character Crouching");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Swimming, "State.Character.Swimming", "Character Swimming");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Floating, "State.Character.Floating", "Character Floating");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Climbing, "State.Character.Climbing", "Character Climbing");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Riding, "State.Character.Riding", "Character Riding");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Flying, "State.Character.Flying", "Character Flying");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Attacking, "State.Character.Attacking", "Character Attacking");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_NormalAttacking, "State.Character.NormalAttacking", "Character NormalAttacking");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_FallingAttacking, "State.Character.FallingAttacking", "Character FallingAttacking");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_SkillAttacking, "State.Character.SkillAttacking", "Character SkillAttacking");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Defending, "State.Character.Defending", "Character Defending");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Interrupting, "State.Character.Interrupting", "Character Interrupting");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_Exhausted, "State.Character.Exhausted", "Character Exhausted");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_FreeToAnim, "State.Character.FreeToAnim", "Character FreeToAnim");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_LockRotation, "State.Character.LockRotation", "Character LockRotation");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Character_BreakAllInput, "State.Character.BreakAllInput", "Character BreakAllInput");
}
