#define MySpellIni Ini_${Me.CleanName}_${Me.Class}.ini

|** 
v2.9 pete sampras 1/1/2014
- added /twist support for bards to /call Cast
-updated CastDoClickies to work with bards
-fixed CastInitialize
spell_routines.inc v2.8 - PeteSampras Edit
-Added CastInitialize routine to autoload from an INI.
To use just declare the 2 following variables, then /call the routine and it will search the INI:
Options= I want to use with "|" at the end and match up with type below it
OptionTypes= 1 = CastIfReady/No recast, 2=CastDuration/Yes recast, 3=CastOncePerMob
/declare Option string outer Nuke|Dot|Pet|AA|Harvest|SelfBuff|Buff|Snare|Jolt|Debuff|Command|ImHit|
/declare OptionType string outer 1|2|1|1|1|1|2|3|1|2|1|1|
Then /call CastInitialize
v2.7 - PeteSampras edit
-Updated /itemnotify to /useitem via:  /useitem ${FindItem[=item name].ItemSlot} ${FindItem[=item name].ItemSlot2}
-ImHit routine can now use normal Me.Abilities like Feign Death and Mend

-Updated InvSlots for 18 May 2013 patch.
-Added /useitem for items in slot 32 or less since it is an official EQ command now.

Added custom variables:
${GoM} - Do I have a form of Gift of Mana on?
${Twincast} - Do I have twincast on?
${NoGlobalTimer} - Are any of my spells ready?
${Named} - Is my target a named spawn?
${Banestrike} - Checks if mob is known immune to Banestrike AA so you can use it as a condition. !${Banestrike} means it will try it.

Added several generic routines to perform casting, medding, assisting, an event to check if you are hit.

This is a list of the routines, what they do, and the variables you need to declare and if those variables are optional to declare or not.
You may force memorization of a spell by placing a 1 at the end of the /call.

- DefaultGem is /declared in Sub SpellRoutinesLoad, this is the gem spells will force memorize with.

Example calls:
/call CastIfReady Nuke
/call CastDuration Dot 1
/call CastCommand Command
/call CastOnPets Pets 1
/call CastIfReady SelfBuffs 1
/call CastAutoClickies
/if (${Target.ID}!=${FightID} && ${Target.ID}==${TarID} && ${Target.ID}) /call CastDPS ${Target.ID}

-Sub CastAutoClickies - Routine to autocast clicky items that have buffs on them
/call CastAutoClickies

-Sub CastModRod - Routine to auto use mod rods if you have enough HP and need enough mana.
/call CastModRod

-Sub CastDPS - Routine to determine approximately how many seconds before mob dies. Adds FightTimeRemaining variable. This can be used in a condition, example to only cast a dot if more than 25 seconds remain:
/noparse /declare DotConditions1 string outer (${FightTimeRemaining}>25)
/if (${Target.ID}!=${FightID} && ${Target.ID}==${TarID} && ${Target.ID}) /call CastDPS ${Target.ID}

-Sub CastIfReady - Routine to cast spell if ready and conditions are met with no recast considerations. Color and conditions optional. Replace "Nuke" in example with any word to create your own.
/declare NukeColor string outer Red
/declare Nuke1 string outer Impel for Blood
/noparse /declare NukeConditions1 string outer (${Me.PctHPs}<40)

-Sub CastDuration - Routine to cast spells that have duration longer than gem refresh. ie. DoTs. Color and conditions optional. Replace "Dot" in example with any word to create your own.
/declare DotColor string outer Yellow
/declare Dot1 string outer Osalur's Flashblaze
/noparse /declare DotConditions1 string outer (${Range.Between[15,${AssistAt}:${Target.PctHPs}]})
/declare DotRecast1 timer outer 12s
/declare LastDot1 int outer

-Sub CastOncePerMob - Routine to cast spells once on a mob. Color and conditions optional. Replace "Snare" in example with any word to create your own.
/declare SnareColor string outer Green
/declare LastSnare int outer
/declare Snare string outer Encroaching Darkness
/noparse /declare SnareConditions string outer (${Target.PctHPs}<25 && ${Target.Fleeing}||!${Group})

-Sub CastCommand - Routine to perform any command. Conditions optional. Replace "Command" in example with any word to create your own.
/declare Command1 string outer /pet attack
/declare Command2 string outer /stand
/noparse /declare CommandConditions1 string outer (${TarID} && ${Target.ID} && ${Me.Pet.ID} && ${Me.Pet.Following.ID}!=${TarID} && ${Target.Distance}<100)
/noparse /declare CommandConditions2 string outer (${Me.PctHPs}>70 && ${Me.Feigning})

-Sub CastOnGroup - Routine to cast spells on group. Color, recast, and conditions are optional. Replace "Heal" in example with any word to create your own. ${i} checks group member 0-5 in the routine.
/declare HealColor string outer Teal
/declare Heal1 string outer Promised Renewal
/declare HealRecast1 timer outer 20s
/noparse /declare HealConditions1 (${Group.Member[${i}].PctHPs}<80 && ${Select[${Group.Member[${i}].Class.ShortName},SHM,NEC]})

-Sub CastOnPets - Routine to cast spell on pets in group. Color, Recast, and Conditions are optional. Replace "PetHeal" in example with any word to create your own. ${i} checks group member 0-5 in the routine.
/declare PetHealColor string outer Teal
/declare PetHeal1 string outer Algid Mending
/declare PetHealRecast1 timer outer 20s
/noparse /declare PetHealConditions1 (!${i} && ${Me.Pet.ID} && ${Me.Pet.PctHPs}<75)

-Sub CastOnXTarget - routine to cast spells on XTargets. Color, Recast, and Conditions are optional. Replace "XHeal" in example with any word to create your own. ${i} checks XTarget 1-10 in the routine.
/declare XHealColor string outer Teal
/declare XHeal1 string outer Promised Renewal
/declare XHealRecast1 timer outer 20s
/noparse /declare XHealConditions1 (${Spawn[${Me.XTarget[$[i}].ID}].PctHPs}<80 && ${Select[${Spawn[${Me.XTarget[${i}].ID}].Type},pc,pet,mercenary]} && ${Me.XTarget[${i}].Type.NotEqual[auto hater]})

- Sub CastTarget - Generic assist routine, must /declare a name and a % to assist at in your macro:
/declare Assist string outer name
/declare AssistAt int outer 99

-Sub Event_CastImHit - Routine for if you get hit. Must use ImHitX format. Color and conditions optional.
/declare ImHitColor string outer Pink
/declare ImHit1 string outer Improved Death Peace
/noparse /declare ImHitConditions1 string outer (${Me.PctHPs}<40)

-Sub CheckAggro - Routine to check aggro while casting any of the other sub routines. Must use JoltX format. Color and conditions optional.
/declare JoltColor string outer Teal
/declare Jolt1 string outer Death's Effigy
/noparse /declare JoltConditions1 string outer (${Me.PctAggro}>95 && ${Group})

- Sub CastMed - Generic med routine. Uses variables MedAt and MedTimer in Sub SpellRoutinesLoad 

v2.5 notes:
 - Added support for spell and disc rank 2/3 auto detection
 - Items will use /itemnotify unless they are Must Equip
 - Added support for /discs + rank detection:	 			/call Cast "Disc Name" disc
 - Added support for abilities:				 			/call Cast "Ability Name" ability
 - You will not /dismount if on a horse uness DismountToInterrupt=TRUE
 	-Added castReturn: Macro.Return.Equal[MOUNTED]
 - Detection and usage of project illusion
 - Added invulnerable castReturn: Macro.Return.Equal[CAST_INVULNERABLE]
 - Added announce options in Sub SpellRoutinesLoad section.  
	-Options will default to the INI defined: #define MySpellIni Bot_${Me.CleanName}_${Me.Class}.ini
	-You can manually change these or change them in whatever INI you define
	-If AnnounceSpellRoutinesChannel=cecho , then you will use colors designated in your call:
		-Example channels: echo, cecho, bc, group, chat, bct PeteSampras
		-/call Cast "Spell Name" gem3 Orange CheckHP 5
		-That will announce your spell in orange /cecho
		-/call Cast "Spell Name2" gem1 DarkBlue
		-That will announce your spell in DarkBlue /cecho
		-A full list of available colors is listed below in: /declare SpellRoutinesColorList
**|
| Originally Written by Rusty~
| Upkeep performed by A_Druid_00
|
| Includes MQ2Exchange integration for item swapping by BrainDeath
| Also includes FD fix that would cause an endless loop if you were hit by FD mid-cast by A_Druid_00
|
| Features:
| - Casts spells, clicks items, or uses AA abilities for you
| - Allows back to back casting without waiting on spell gems to pop all the way up
| - Will interrupt spell if target dies while casting. If on a mount, it will dismount and duck if the time left
|   is greater than 7 seconds, else it will move forward a bit to interrupt, then move you back
|
|    ** IMPORTANT: if you don't want to interrupt a spell while mounted, put this at the top of your macro: **
|    **   /declare noInterrupt int outer 1                                                                  **
|
| - Allows you to use items in bags. Equips item, clicks it, then returns it to its previous location
| - Lets you set how long you want to keep trying to cast the spell (defaults to 0)
|   If the spell is interrupted before the given time, it will recast, else it will return CAST_INTERRUPTED
| - Lets you call a custom subroutine while waiting for spell to finish casting
|   Try to keep custom subroutines very small. A common use would be to interrupt the spell if a certain condition is true
| - This file also includes a sub named Interrupt. You can call this to interrupt any spell you're casting instantly.
| - You can also use the SwapItem sub included in this to swap items to certain slots
| - Added EquipItem sub to easily equip items in your main Inventory slots.
|
|    ** IMPORTANT:  if you don't want this to cast spells while you're invis, in your main macro have this at the top:
|    **   /declare noInvis int outer 1
|   This will make it return CAST_INVIS if you're invis
|
|  Below is a list of outer scope variables you can access in your macros:
|      refreshTime        - How much time is left till you're done recovering from casting
|      castEndTime        - How much time left till you're done casting the current spell... usable in custom spell Subs
|      spellNotHold       - 1 if your last spell didn't take hold, 0 otherwise
|      spellRecastTime1-12 - How much time left till that spell is back up
|
|======================================================================================================================
|  EquipItem:  An easier way to equip items you have in bags ( useful for weapons or focus items )
|              slot name is optional. If not given, it will equip it in the first possible spot
|
|    Usage:   
|        /call EquipItem "item name|slotname"
|
|        Returns: "old item name|slotname"
|    Examples:
|   
|    To Equip Sharp Ended Broken Lever when you have Serpent of Vindication equiped:
|        /call EquipItem "Sharp Ended Broken Lever"
|    It will return "Staff of Vindication|mainhand"
|    To reequip the original item, you can save the return in a variable, and then use it later like this:
|       /varset oldPrimary ${Macro.Return}
|       | ... do stuff here with your new item equiped
|       /call EquipItem ${oldPrimary}
|
|======================================================================================================================
|  SwapItem:  a subroutine which is used in the Cast sub itself. You don't need to do this to cast an item in a bag
|             but you can call it in your macro to SwapItems (such as weapons or focus items)
|    Usage:   
|        /call SwapItem "item name" slotname|slotID
|    Examples:
|   
|    To swap Darkblade of the Warlord to your main hand:
|        /call SwapItem "Darkblade of the Warlord" mainhand
|
|    To swap stat food in one bag with other food in another bag:
|        /call SwapItem "Bristlebanes Party Platter" ${FindItem[halas 10lb meat pie].InvSlot}
|
|======================================================================================================================
|  Cast: the main subroutine that casts spells or items for you
|     Usage:
|        /call Cast "spellname|itemname|AAname|AA#" [item|alt|gem#] [give up time][s|m] [custom subroutine name]
|     Examples:
|
|     To cast Howl of Tashan and mem it in slot 3 if not memmed:
|       /call Cast "Howl of Tashan" gem3
|
|     To cast Arcane Rune and keep trying for 7 seconds, in case of interrupts.
|       /call Cast "Arcane Rune" gem5 7s
|
|     To click Grim Aura earring that's in a bag:
|       /call Cast "Shrunken Goblin Skull Earring" item
|
|     To use AA ability Eldritch Rune:
|       /call Cast "Eldritch Rune" alt
|         or
|       /call Cast "173" alt
|
|     To call a subroutine that interrupts CH if target gets healed before it lands:
|       /call Cast "Complete Healing" gem1 0 CheckHP
|     Then in your macro have somewhere:
|       Sub CheckHP
|          /if ( ${Target.PctHPs}>=80 ) /call Interrupt
|       /return
|
| Returns these values:
|----------------------+----------------------------------------------------------------------+
| CAST_CANCELLED       | Spell was cancelled by ducking (either manually or because mob died) |
| CAST_CANNOTSEE       | You can't see your target                                            |
| CAST_IMMUNE          | Target is immune to this spell                                       |
| CAST_INTERRUPTED     | Casting was interrupted and exceeded the given time limit            |
| CAST_INVIS           | You were invis, and noInvis is set to true                           |
| CAST_INVULNERABLE    | You were invulnerable                           |
| CAST_NOTARGET        | You don't have a target selected for this spell                      |
| CAST_NOTMEMMED       | Spell is not memmed and you gem to mem was not specified             |
| CAST_NOTREADY        | AA ability or spell is not ready yet                                 |
| CAST_OUTOFMANA       | You don't have enough mana for this spell!                           |
| CAST_OUTOFRANGE      | Target is out of range                                               |
| CAST_RESISTED        | Your spell was resisted!                                             |
| CAST_SUCCESS         | Your spell was cast successfully! (yay)                              |
| CAST_UNKNOWNSPELL    | Spell/Item/Ability was not found                                     |
| CAST_NOTHOLD         | Spell woundn't take hold on target                                   |
| MOUNTED			   | You were mounted during an interrupt attempt						  |
|----------------------+----------------------------------------------------------------------+

#Event BeginCast "You begin casting#*#"
#Event Collapse "Your gate is too unstable, and collapses.#*#"
#Event FDFail "#1# has fallen to the ground.#*#"
#Event Fizzle "Your spell fizzles#*#"
#Event Immune "Your target is immune to changes in its attack speed#*#"
#Event Immune "Your target is immune to changes in its run speed#*#"
#Event Immune "Your target cannot be mesmerized#*#"
#Event Interrupt "Your casting has been interrupted#*#"
#Event Interrupt "Your spell is interrupted#*#"
#Event Invulnerable "You can't cast spells while invulnerable#*#"
#Event Invulnerable "You cannot cast spells while invulnerable#*#"
#Event Invulnerable "You *CANNOT* cast spells while invulnerable#*#"
#Event NoHold "Your spell did not take hold#*#"
#Event NoHold "Your spell would not have taken hold#*#"
#Event NoHold "You must first target a group member#*#"
#Event NoHold "Your spell is too powerful for your intended target#*#"
#Event NoLOS "You cannot see your target.#*#"
#Event NoMount "#*#You can not summon a mount here.#*#"
#Event NoTarget "You must first select a target for this spell!#*#"
#Event NotReady "Spell recast time not yet met.#*#"
#Event OutOfMana "Insufficient Mana to cast this spell!#*#"
#Event OutOfRange "Your target is out of range, get closer!#*#"
#Event Recover "You haven't recovered yet...#*#"
#Event Recover "Spell recovery time not yet met#*#"
#Event Resisted "Your target resisted the #1# spell#*#"
#Event Resisted2 "You resist the #1# spell#*#"
#Event Standing "You must be standing to cast a spell#*#"
#Event Stunned "You are stunned#*#"
#Event Stunned "You can't cast spells while stunned!#*#"
#Event Stunned "You *CANNOT* cast spells, you have been silenced!#*#"

Sub SpellRoutinesLoad
/if (${spell_routines_loaded}) /return
/declare spell_routines_loaded int outer 1
/if (${Plugin[mq2cecho].Name.NotEqual[mqc2echo]}) /squelch /plugin mq2cecho
/if (!${Defined[DismountToInterrupt]}) /declare DismountToInterrupt bool outer ${Ini[MySpellIni,Settings,DismountToInterrupt,FALSE]}
/if (!${Defined[AnnounceSpellRoutines]}) /declare AnnounceSpellRoutines bool outer ${Ini[MySpellIni,Settings,AnnounceSpellRoutines,FALSE]}
/if (!${Defined[HaveVOA]}) /declare HaveVOA bool outer ${Ini[MySpellIni,Settings,HaveVOA,${If[${Me.HaveExpansion[Veil of Alaris]},TRUE,FALSE]}]}
/if (!${Defined[AnnounceSpellRoutinesChannel]}) /declare AnnounceSpellRoutinesChannel string outer ${Ini[MySpellIni,Settings,AnnounceSpellRoutinesChannel,cechob]}
/if (!${Defined[SpellRoutinesColorList]}) /declare SpellRoutinesColorList string outer |Black|Blue|Brown|Cyan|Gray|Green|Pink|Orange|Purple|Red|Teal|White|Yellow|DarkGreen|DarkPink|DarkPurple|DarkRed|DarkCyan|DarkBlue|DarkYellow|
/if (!${Defined[SpellRoutinesColorCode]}) /declare SpellRoutinesColorCode string outer |\ab|\au|\a-o|\at|\a-w|\ag|\am|\ao|\ap|\ar|\at|\aw|\ay|\a-b|\a-m|\a-p|\a-r|\a-t|\a-u|\a-y|
/if (!${Defined[TempTargetID]}) /declare TempTargetID int outer
/if (!${Defined[DefaultGem]}) /declare DefaultGem string outer ${Ini[MySpellIni,Settings,DefaultGem,gem1]}
/if (!${Defined[MedAt]}) /declare MedAt int outer ${Ini[MySpellIni,Settings,MedAt,30]}
/if (!${Defined[MedTimer]}) /declare MedTimer timer outer ${Ini[MySpellIni,Settings,MedTimer,5s]}
/if (!${Defined[TarID]}) /declare TarID int outer
/if (!${Defined[CurrentSub]}) /declare CurrentSub string outer
/if (!${Defined[ReAssist]}) /declare ReAssist timer outer 1s
/if (!${Defined[GoM]}) {
/noparse /declare GoM string outer (${Me.Song[Gracious Mana].ID}||${Me.Song[Gift of Mana].ID}||${Me.Song[Gift of Radiant Mana].ID}||${Me.Song[Gift of Dreamlike Exquisite Radiant Mana].ID}||${Me.Song[Gift of Exquisite Radiant Mana].ID}||${Me.Song[Gift of Amazing Exquisite Radiant Mana].ID}||${Me.Song[Gift of Phantasmal Exquisite Radiant Mana].ID})
}
/if (!${Defined[Twincast]}) {
/noparse /declare Twincast string outer (${Me.Song[Twincast].ID}||${Me.Song[Twincast Rk. II].ID}||${Me.Song[Twincast Rk. III].ID}||${Me.Song[Improved Twincast].ID}||${Me.Buff[Twincast].ID}||${Me.Buff[Improved Twincast].ID})
}
/if (!${Defined[Named]}) {
/noparse /declare Named string outer (${Target.Named}||${Target.Name.Find[#]} && !${Target.Master.ID})
}
/if (!${Defined[NoGlobalTimer]}) {
/noparse /declare NoGlobalTimer string outer (${Me.SpellReady[1]}||${Me.SpellReady[2]}||${Me.SpellReady[3]}||${Me.SpellReady[4]}||${Me.SpellReady[5]}||${Me.SpellReady[6]}||${Me.SpellReady[7]}||${Me.SpellReady[8]})
}
/return

Sub Cast(spellName,spellType,giveUpValue,mySub,int ResistTotal)
/if (!${Defined[spell_routines_loaded]}) /call SpellRoutinesLoad
/declare castTime float local
/if (${giveUpValue.Length} && ${Defined[colorChoice]}) /varset colorChoice
/if (!${Defined[castReturn]}) /declare castReturn string outer CAST_CANCELLED
/call DoCastingEvents
/varset castReturn X
/if (${Me.Invis} && ${noInvis}) /return
/if (${spellType.Equal[item]}) {
/if (!${FindItem[${spellName}].ID}) {
   /return CAST_UNKNOWNSPELL
}
  /varset castTime ${FindItem[${spellName}].CastTime}
} else /if (${spellType.Equal[disc]}) {
  /if (!${Me.CombatAbilityReady[${spellName}]} && !${Me.CombatAbilityReady[${spellName} Rk. II]} && !${Me.CombatAbilityReady[${spellName} Rk. III]}||${Melee.DiscID}) /return CAST_NOTREADY
  /if (${Me.CombatAbilityReady[${spellName} Rk. III]}) /varset spellName ${spellName} Rk. III
  /if (${Me.CombatAbilityReady[${spellName} Rk. II]}) /varset spellName ${spellName} Rk. II
  /varset castTime 0
} else /if (${spellType.Equal[alt]}) {
  /if (!${Me.AltAbilityReady[${spellName}]}) /return CAST_NOTREADY
  /varset castTime ${Me.AltAbility[${spellName}].Spell.CastTime}
} else {
  /if (!${Me.Book[${spellName}]} && !${Me.Book[${spellName} Rk. II]} && !${Me.Book[${spellName} Rk. III]} && !${Me.Book[${spellName} Rk II]} && !${Me.Book[${spellName} Rk II]} && !${Me.Book[${spellName} Rk.III]} && !${Me.Book[${spellName} Rk III]} && !${Me.Book[${spellName} Rk. II ]} && !${Me.Book[${spellName} Rk. III ]}) /return CAST_UNKNOWNSPELL
  /if (${Me.Book[${spellName} Rk. III]}) /varset spellName ${spellName} Rk. III
  /if (${Me.Book[${spellName} Rk. II]}) /varset spellName ${spellName} Rk. II
  /if (${Me.Book[${spellName} Rk. III ]}) /varset spellName "${spellName} Rk. III "
  /if (${Me.Book[${spellName} Rk. II ]}) /varset spellName "${spellName} Rk. II "
  /if (${Me.Book[${spellName} Rk.III]}) /varset spellName ${spellName} Rk.III
  /if (${Me.Book[${spellName} Rk.II]}) /varset spellName ${spellName} Rk.II
  /if (${Me.Book[${spellName} Rk III]}) /varset spellName ${spellName} Rk III
  /if (${Me.Book[${spellName} Rk II]}) /varset spellName ${spellName} Rk II  
  /declare spellID int local ${Me.Book[${Me.Book[${spellName}]}].ID}
  /varset castTime ${Spell[${spellName}].CastTime}
  /if (${Me.CurrentMana}<${Spell[${spellID}].Mana}) /return CAST_OUTOFMANA
}
/if (${castTime}>0.1) {
  /if (${Stick.Status.Equal[ON]}) /stick pause
  /if (${FollowFlag}) /call PauseFunction
  /if (${Me.Moving}) /keypress back
}
/if (!${Defined[spellType]}) /declare spellType string local spell
/if (!${Defined[spellRecastTime1]}) {
  /if (!${Defined[noInterrupt]}) /declare noInterrupt int outer 0
  /declare ResistCounter int outer
  /declare moveBack bool outer false
  /declare selfResist int outer
  /declare selfResistSpell string outer
  /declare giveUpTimer timer outer
  /declare castEndTime timer outer
  /declare refreshTime timer outer
  /declare itemRefreshTime float outer
  /declare TwistCastTimer timer outer
  /declare i int local
  /declare spellNotHold int outer
  /declare colorChoice string outer
  /delay 5
  |---- Spell Gem Slots
  /for i 1 to 12
  /declare spellRecastTime${i} timer outer
  /if (${Me.SpellReady[${i}]}) {
    /varset spellRecastTime${i} 0
  } else {
    /varcalc spellRecastTime${i} 10*${Me.Gem[${i}].RecastTime}
  }
  /next i
  |---- Spell Gem Slots
}
/if (${Defined[giveUpValue]} && !${SpellRoutinesColorList.Find[${giveUpValue}]}) /varset giveUpTimer ${giveUpValue}
/if (${Defined[giveUpValue]} && ${SpellRoutinesColorList.Find[${giveUpValue}]} && ${AnnounceSpellRoutinesChannel.Find[cecho]}) {
		/varset colorChoice
		/if (!${Defined[i]}) /declare i int local
			/varset giveUpTimer 1s
			/for i 2 to ${SpellRoutinesColorCode.Count[|]} {
				/if (${SpellRoutinesColorList.Arg[${i},|].Equal[${giveUpValue}]}) {
							/varset colorChoice ${SpellRoutinesColorCode.Arg[${i},|]}
							/goto :skipcolor
				}
		
			}
			/next i
	}
:skipcolor
/if (${Defined[ResistTotal]}) /varset ResistCounter ${ResistTotal}
/varset spellNotHold 0
/varset selfResist 0
:wait_for_stop
/if (${Me.Casting.ID} || (${Me.Moving} && ${castTime}>0.1)) {
  /if (${Bool[${mySub}]}) /call ${mySub} ${spellID}
  /goto :wait_for_stop
}
/if (${Window[SpellBookWnd].Open}) /keypress spellbook
/if (${Me.Ducking}) /keypress duck
/if (${spellType.Equal[item]} && ${FindItem[${spellName}].EffectType.NotEqual[Click Inventory]}) /call ItemCast "${spellName}" "${mySub}"
/if (${spellType.Equal[item]} && ${FindItem[${spellName}].EffectType.Equal[Click Inventory]}) {
	/if (${HaveVOA}) /useitem ${FindItem[=${spellName}].ItemSlot} ${FindItem[=${spellName}].ItemSlot2}
	/if (!${HaveVOA})  /call ItemCast "${spellName}" "${mySub}"
	/if (${AnnounceSpellRoutines}) /docommand /${AnnounceSpellRoutinesChannel} ${colorChoice} ${spellName} ${If[${Target.ID} && ${Spell[${spellName}].TargetType.NotEqual[self]},\aw--> ${Target.CleanName},]}
	/call DoCastingEvents
	}
/if (${spellType.Equal[alt]}) /call AltCast "${spellName}" "${mySub}"
/if (${spellType.Equal[disc]}) /call DiscCast "${spellName}"
/if (${spellType.Equal[ability]} && ${Me.AbilityReady[${spellName}]}) /doability "${spellName}"
/if (${spellType.NotEqual[item]} && ${spellType.NotEqual[alt]} && ${spellType.NotEqual[ability]} && ${spellType.NotEqual[disc]} && ${Me.Gem[${spellName}]} && ${Me.Class.ShortName.Equal[BRD]} && !${TwistCastTimer}) /call TwistCast "${spellName}"
/if (${spellType.NotEqual[item]} && ${spellType.NotEqual[alt]} && ${spellType.NotEqual[ability]} && ${spellType.NotEqual[disc]}) /call SpellCast "${spellType}" "${spellName}" "${mySub}" "${spellID}" "${giveUpValue}"
/if (${Stick.Status.Equal[PAUSED]}) /squelch /stick unpause
/if (${PauseFlag}) /call PauseFunction
/varset giveUpTimer 0
/varset ResistCounter 0
/return ${castReturn}

Sub TwistCast(spellName)
/varset TwistCastTimer 33
/twist once ${Me.Gem[${spellName}]}
/return

Sub SpellCast(spellType,spellName,mySub,int spellID,giveUpValue)
:cast_spell
/if (!${Me.Gem[${spellName}]}) {
  /if (${Cursor.ID}) /call ClearCursor
  /if (${spellType.Left[3].Equal[gem]}) {
   /if (${spellType.Length}==4) /memspell ${spellType.Right[1]} "${spellName}"
   /if (${spellType.Length}==5) /memspell ${spellType.Right[2]} "${spellName}"
  } else {
    /return CAST_NOTMEMMED
  }
  /if (${Bool[${mySub}]}) /call ${mySub} ${spellID}
  /delay 6s ${Me.Gem[${spellName}]}
  /if (${Me.Gem[${spellName}]}) /varcalc spellRecastTime${Me.Gem[${spellName}]} 10*${Spell[${spellID}].RecastTime}
  /if (!${Me.Gem[${spellName}]}) /return CAST_INTERRUPTED
  :wait_for_mem
  /if (${Bool[${mySub}]}) /call ${mySub} ${spellID}
  /delay 15s ${Me.SpellReady[${spellName}]}
  /if (!${Me.SpellReady[${spellName}]}) {
    /if (${giveUpTimer}) /goto :wait_for_mem
    /return CAST_NOTREADY
  }
}
/varset spellType spell
/if (${spellName.Find[illusion: ]} && ${Me.AltAbilityReady[project illusion]}) /call Cast "project illusion" alt
/varset giveUpTimer ${giveUpValue}
/declare recoverWaitTime timer local 30
/if (${AnnounceSpellRoutines}) /docommand /${AnnounceSpellRoutinesChannel} ${colorChoice} ${spellName} ${If[${Target.ID} && ${Spell[${spellName}].TargetType.NotEqual[self]},\aw--> ${Target.CleanName},]}
:cast_spell_loop
/if (!${Me.SpellReady[${spellName}]} && (${spellRecastTime${Me.Gem[${spellName}]}}<${giveUpTimer} || ${refreshTime}>0 || ${castReturn.Equal[CAST_RESISTED]})) {
  /if (${Bool[${mySub}]}) /call ${mySub} ${spellID}
  /goto :cast_spell_loop
} else {
  /if (!${Me.SpellReady[${spellName}]} && !${castReturn.Equal[CAST_RESISTED]}) /return CAST_NOTREADY
}
/call Event_BeginCast
/cast "${spellName}"
/if (${Me.Casting.ID}) {
  /varset spellID ${Me.Casting.ID}
  /varcalc castEndTime ${Me.Casting.CastTime}*10
  /if (${castEndTime}<${Math.Calc[${Me.Casting.CastTime}*5]}) /varcalc castEndTime ${Me.Casting.CastTime}*5
}
/varset moveBack false
/call WaitCast ${mySub} ${spellID}
/if (${moveBack}) {
  /keypress back hold
  /delay 8
  /keypress back
  /delay 15 !${Me.Moving}
}
/if (${castReturn.Equal[CAST_CANCELLED]}) /return CAST_CANCELLED
/call DoCastingEvents
/if (!${castReturn.Equal[CAST_SUCCESS]}) {
  /if (${castReturn.Equal[CAST_RECOVER]}) {
    /if (!${recoverWaitTime}) {
      /varcalc spellRecastTime${Me.Gem[${spellName}]} 10*${Spell[${spellID}].RecastTime}
      /if (!${giveUpTimer}) /return CAST_NOTREADY
    }
    /goto :cast_spell_loop
  }
  /if (${castReturn.Equal[CAST_RESTART]} || ${castReturn.Equal[CAST_STUNNED]} || ${castReturn.Equal[CAST_FIZZLE]} || ${castReturn.Equal[CAST_COLLAPSE]} || (${castReturn.Equal[CAST_INTERRUPTED]} && ${giveUpTimer}) || (${castReturn.Equal[CAST_RESISTED]} && ${ResistCounter})) /goto :cast_spell_loop
}
/if (!${castReturn.Equal[CAST_CANNOTSEE]} && !${castReturn.Equal[CAST_OUTOFRANGE]} && !${castReturn.Equal[CAST_OUTOFMANA]} && !${castReturn.Equal[CAST_NOTARGET]} && !${castReturn.Equal[CAST_INTERRUPTED]}) {
  /varcalc refreshTime 10*${Spell[${spellID}].RecoveryTime}
  /varcalc spellRecastTime${Me.Gem[${spellName}]} 10*${Spell[${spellID}].RecastTime}
}
/return

Sub ItemCast(spellName,mySub)
/declare charges       int    local
/declare oldItemName       string    local
/declare slotName       string    local
/declare swapItemBack       bool    local    FALSE
/declare needSwap      bool    local    FALSE
/declare itemInBag      bool    local    FALSE
/declare eqLoop         int    local    0
/declare equippedArray[33]   string    local
   /varset equippedArray[0] charm
   /varset equippedArray[1] head
   /varset equippedArray[2] face
   /varset equippedArray[3] neck
   /varset equippedArray[4] rightear
   /varset equippedArray[5] leftear
   /varset equippedArray[6] arms
   /varset equippedArray[7] hands
   /varset equippedArray[8] rightwrist
   /varset equippedArray[9] leftwrist
   /varset equippedArray[10] rightfinger
   /varset equippedArray[11] leftfinger
   /varset equippedArray[12] shoulder
   /varset equippedArray[13] back
   /varset equippedArray[14] chest
   /varset equippedArray[15] waist
   /varset equippedArray[16] legs
   /varset equippedArray[17] feet
   /varset equippedArray[18] mainhand
   /varset equippedArray[19] offhand
   /varset equippedArray[20] ranged
   /varset equippedArray[21] ammo
   /varset equippedArray[22] powersource
   /varset equippedArray[23] pack1
   /varset equippedArray[24] pack2
   /varset equippedArray[25] pack3
   /varset equippedArray[26] pack4
   /varset equippedArray[27] pack5
   /varset equippedArray[28] pack6
   /varset equippedArray[29] pack7
   /varset equippedArray[30] pack8
   /varset equippedArray[31] pack9
   /varset equippedArray[32] pack10
   
:cast_item
/varset itemInBag TRUE
/varset needSwap FALSE
/varset swapItemBack FALSE

/for eqLoop 0 to 32
     /if (${Me.Inventory[${equippedArray[${eqLoop}]}].ID}==${FindItem[${spellName}].ID} && !${Me.Inventory[${equippedArray[${eqLoop}]}].Container}) {
    /varset itemInBag FALSE
    /varset slotName ${equippedArray[${eqLoop}]}
    /if (${eqLoop}>22 && ${FindItem[${spellName}].WornSlot[1]} && ${FindItem[${spellName}].EffectType.Find[worn]}) {
             /varset slotName ${FindItem[${spellName}].WornSlot[1].Name}
             /varset swapItemBack TRUE
        /varset needSwap TRUE
         }
     }
/next eqLoop

/if (${itemInBag}) {
    /if (${FindItem[${spellName}].WornSlot[1]} && ${FindItem[${spellName}].EffectType.Find[worn]}) {
   /varset slotName ${FindItem[${spellName}].WornSlot[1].Name}
    } else {
   /varset slotName pack8
    }
   /varset swapItemBack TRUE
   /varset needSwap TRUE
}

/if (${needSwap}) {
   /varset oldItemName ${Me.Inventory[${slotName}].Name}
   /call SwapItem "${spellName}" ${slotName}
}
/if (${AnnounceSpellRoutines}) /docommand /${AnnounceSpellRoutinesChannel} ${colorChoice} ${spellName} ${If[${Target.ID} && ${Spell[${spellName}].TargetType.NotEqual[self]},\aw--> ${Target.CleanName},]}
:wait_item_loop
/if (${itemRefreshTime}>${MacroQuest.Running}) /goto :wait_item_loop
/varset itemRefreshTime ${Math.Calc[${MacroQuest.Running}+000]}
/varset charges ${FindItem[${spellName}].Charges}
/if (${FindItem[${spellName}].Spell.Name.Find[illusion: ]} && ${Me.AltAbilityReady[project illusion]}) /call Cast "project illusion" alt
/cast item "${spellName}"
/if (${Me.Casting.ID}) /varcalc castEndTime ${FindItem[${spellName}].CastTime}*10
/delay 1s ${FindItem[${spellName}].Charges}!=${charges}
/call WaitCast ${mySub}
/call Event_BeginCast
/if (${FindItem[${spellName}].CastTime}<0.5) /delay 5
/if (${swapItemBack} && ${FindItem[${oldItemName}].ID}) /call SwapItem "${oldItemName}" ${slotName}
/if (${castReturn.Equal[CAST_CANCELLED]}) /return CAST_CANCELLED
/call DoCastingEvents
/if (${castReturn.Equal[CAST_RESTART]} || ${castReturn.Equal[CAST_STUNNED]} || (${castReturn.Equal[CAST_INTERRUPTED]} && ${giveUpTimer}) || ${castReturn.Equal[CAST_COLLAPSE]} || (${castReturn.Equal[CAST_RESISTED]} && ${ResistCounter})) /goto :cast_item
/return

Sub AltCast(spellName,mySub)
/if (${AnnounceSpellRoutines}) /docommand /${AnnounceSpellRoutinesChannel} ${colorChoice} ${spellName} ${If[${Target.ID} && ${Spell[${spellName}].TargetType.NotEqual[self]},\aw--> ${Target.CleanName},]}
:cast_alt
/alt activate ${Me.AltAbility[${spellName}].ID}
/delay 5 ${Me.Casting.ID}
/call WaitCast ${mySub}
/if (${castReturn.Equal[CAST_CANCELLED]}) /return CAST_CANCELLED
/call DoCastingEvents
/if (${castReturn.Equal[CAST_RESTART]} || ${castReturn.Equal[CAST_STUNNED]} || (${castReturn.Equal[CAST_INTERRUPTED]} && ${giveUpTimer}) || (${castReturn.Equal[CAST_RESISTED]} && ${ResistCounter})) /goto :cast_alt
/return

Sub DiscCast(spellName)
/if (${AnnounceSpellRoutines}) /docommand /${AnnounceSpellRoutinesChannel} ${colorChoice} ${spellName} ${If[${Target.ID} && ${Spell[${spellName}].TargetType.NotEqual[self]},\aw--> ${Target.CleanName},]}
:cast_disc
/disc ${spellName}
/return

Sub ClearCursor
/declare i int local
:auto_inv
/if (${Cursor.ID}) {
  /if (${Cursor.Container}) {
    |---- Inventory Bag Slots
    /for i 1 to 10   
    /if (!${InvSlot[pack${i}].Item.Container}) /nomodkey /itemnotify pack${i} leftmouseup
    /next i
    |---- Inventory Bag Slots   
  } else {
    /timed 5 /autoinventory
  }
  /goto :auto_inv
}
/return

Sub DoCastingEvents
/doevents Recover
/doevents BeginCast
/doevents Fizzle
/doevents Interrupt
/doevents Standing
/doevents FDFail
/doevents OutOfRange
/doevents OutOfMana
/doevents NoLOS
/doevents Resisted2
/doevents Resisted
/doevents Immune
/doevents Stunned
/doevents Collapse
/doevents NoTarget
/doevents NotReady
/doevents NoHold
/return

Sub EquipItem(WhatWhere)
/declare DestName string local
/declare ItemName string local ${WhatWhere.Arg[1,|]}
/declare SlotName string local ${WhatWhere.Arg[2,|]}
/if (${SlotName.Equal[NULL]}) /varset SlotName ${InvSlot[${FindItem[=${ItemName}].WornSlot[1]}].Name}
/if (${FindItem[=${ItemName}].InvSlot}<23 || !${FindItem[=${ItemName}].WornSlot[${SlotName}]}) /return
/if (!${InvSlot[${SlotName}].Item.Name.Equal[NULL]}) /varset DestName "${InvSlot[${SlotName}].Item.Name}|${SlotName}"
/call SwapItem "${ItemName}" "${SlotName}"
/return ${DestName}

Sub Interrupt
|/if (!${Defined[DismountToInterrupt]}) /declare DismountToInterrupt bool outer ${Ini[MySpellIni,Settings,DismountToInterrupt,FALSE]}
|/if (${Me.Mount.ID} && !${Dismount}) /goto :skipinterrupt
|/if (${Me.Mount.ID}) /dismount
/delay 1s !${Me.Mount.ID}
/stopcast
/if (${Defined[castReturn]}) /varset castReturn CAST_CANCELLED
|:skipinterrupt
/if (${Me.Mount.ID}) /varset castReturn MOUNTED
/return ${castReturn}

Sub SwapItem(itemName,slotName)
/declare i int local
/if (${Cursor.ID}) /call ClearCursor
/exchange "${itemName}" ${slotName}
|/delay 5s ${InvSlot[${slotName}].Item.Name.Equal[${itemName}]}
/delay 5s ${Me.Inventory[${slotName}].Name.Equal[${itemName}]}
/if (${Cursor.ID}) /call ClearCursor
/return

Sub WaitCast(mySub,int spellID)
/declare currentTarget int local ${Target.ID}
/declare currentTargetType string local ${Target.Type}
:wait_cast_loop
/if (${Bool[${mySub}]}) /call ${mySub} ${spellID}
/if (${Me.Casting.ID}) {
  /if (${currentTarget} && !${Spawn[${currentTarget}].Type.Equal[${currentTargetType}]}) {
    /if (!${Me.Casting.TargetType.Equal[PB AE]} && !${Me.Casting.TargetType.Equal[self]} && !${moveBack} && (!${Me.Mount.ID} || !${noInterrupt})) {
    	/stopcast
    	|**
      /if (!${Me.Mount.ID} || ${castEndTime}>70) {
        /call Interrupt
      } else /if (${Me.Casting.RecastTime}>3) {
        /varset castReturn CAST_CANCELLED
        /keypress forward hold
        /delay 6
        /keypress forward
        /varset moveBack true
      }
      **|
    }
  }
  /if (${Me.State.Equal[DUCK]}) /varset castReturn CAST_CANCELLED
  /goto :wait_cast_loop
}
/return

Sub Event_BeginCast
/if (${Defined[castReturn]}) /varset castReturn CAST_SUCCESS
/return

Sub Event_Collapse
/if (${Defined[castReturn]}) /varset castReturn CAST_COLLAPSE
/varset giveUpTimer 200
/return

Sub Event_FDFail(line,name)
/if (${name.Equal[${Me.Name}]} && ${Defined[castReturn]}) {
  /if (!${Me.Standing}) /stand
  /varset castReturn CAST_RESTART
}
/return

Sub Event_Fizzle
/if (${Defined[castReturn]}) /varset castReturn CAST_FIZZLE
/return

Sub Event_Immune
/if (${Defined[castReturn]}) /varset castReturn CAST_IMMUNE
/return

Sub Event_Interrupt
/if (${Defined[castReturn]}) /varset castReturn CAST_INTERRUPTED
/return

Sub Event_Invulnerable
/if (${Defined[castReturn]}) /varset castReturn CAST_INVULNERABLE
/return

Sub Event_NoHold
/if (${Defined[spellNotHold]}) /varset spellNotHold 1
/if (${Defined[castReturn]}) /varset castReturn CAST_NOTHOLD
/return

Sub Event_NoLOS
/if (${Defined[castReturn]}) /varset castReturn CAST_CANNOTSEE
/return

Sub Event_NoMount
/if (${Defined[castReturn]}) /varset castReturn CAST_NOMOUNT
/return

Sub Event_NoTarget
/if (${Defined[castReturn]}) /varset castReturn CAST_NOTARGET
/return

Sub Event_NotReady
/if (${Defined[castReturn]}) /varset castReturn CAST_NOTREADY
/return

Sub Event_OutOfMana
/if (${Defined[castReturn]}) /varset castReturn CAST_OUTOFMANA
/return

Sub Event_OutOfRange
/if (${Defined[castReturn]}) /varset castReturn CAST_OUTOFRANGE
/return

Sub Event_Recover
/if (${Defined[castReturn]}) /varset castReturn CAST_RECOVER
/return

Sub Event_Resisted(line,name)
/if (${selfResist} && ${name.Equal[${selfResistSpell}]}) /varset selfResist 0
/if (${ResistCounter}) /varcalc ResistCounter ${ResistCounter}-1
/if (${Defined[castReturn]}) /varset castReturn CAST_RESISTED
/return

Sub Event_Resisted2(line,name)
/if (${Defined[selfResist]}) {
  /varset selfResist 1
  /varset selfResistSpell ${name}
}
/return

Sub Event_Standing
/stand
/if (${Defined[castReturn]}) /varset castReturn CAST_RESTART
/return

Sub Event_Stunned
/if (${Me.Stunned}) {
  /delay 3s !${Me.Stunned}
} else {
  /delay 7
}
/if (${Defined[castReturn]}) /varset castReturn CAST_STUNNED
/return

|-- Generic routines to cast several types of spells

Sub CastTarget
/varset CurrentSub CastTarget
/if (!${Spawn[${TarID}].Type.Equal[NPC]}||${Spawn[${TarID}].Master.Type.Equal[NPC]}) /varset TarID 0
/if ((!${Target.ID} || ${Target.Type.Equal[PC]} || !${ReAssist}) && ${SpawnCount[${Assist} radius 300]}) {
/assist ${Assist}
/varset ReAssist ${ReAssist.OriginalValue}
}
/if (${Target.ID} && (${Target.Type.Equal[NPC]}||${Target.Master.Type.Equal[NPC]}) && ${Target.ID}!=${TarID} && ${Target.PctHPs}<=${AssistAt}) {
/varset TarID ${Target.ID}
}
/return

Sub CastCommand(subname)
/varset CurrentSub ${subname}
/declare i int local
/for i 1 to 20
/if (!${Defined[${CurrentSub}${i}]}) /return
	/if (${${CurrentSub}Conditions${i}.Find[\]}) /goto :con1
	/if (${${CurrentSub}Conditions${i}}||!${Defined[${CurrentSub}Conditions${i}]}) /goto :ready
	/goto :skip
	:con1
	/if (!${${CurrentSub}Conditions${i}.Replace[\,]}) /goto :skip
	:ready
	/docommand ${${CurrentSub}${i}}
	:skip
/next i
/return


Sub CastDuration(subname,int force)
/varset CurrentSub ${subname}
/declare i int local
/for i 1 to 20
/if (!${Defined[${subname}${i}]}) /return
	/if (${${CurrentSub}Recast${i}} && ${Last${CurrentSub}${i}}==${Target.ID}) /goto :skip
	/if (${${CurrentSub}Conditions${i}.Find[\]}) /goto :con1
	/if (!${Defined[${subname}Conditions${i}]}||${${CurrentSub}Conditions${i}}) /goto :ready
	/goto :skip
	:con1
	/if (!${${CurrentSub}Conditions${i}.Replace[\,]}) /goto :skip
	:ready
	/if (${FindItem[${${subname}${i}}].InvSlot} && !${FindItem[${${subname}${i}}].Timer}  && !${Me.Casting.ID}) {
				/call Cast "${${CurrentSub}${i}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/varset Last${CurrentSub}${i} ${Target.ID}
						/varset ${CurrentSub}Recast${i} ${${CurrentSub}Recast${i}.OriginalValue}
					}
				}
	/if (${Me.AltAbilityReady[${${subname}${i}}]}  && !${Me.Casting.ID}) {
			/call Cast "${${CurrentSub}${i}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]} CheckAggro
			/varset Last${CurrentSub}${i} ${Target.ID}
			/varset ${CurrentSub}Recast${i} ${${CurrentSub}Recast${i}.OriginalValue}
			}
	/if (${Me.SpellReady[${${subname}${i}}]}||${Me.Book[${${subname}${i}}]} && ${force} && !${Me.AltAbility[${${subname}${i}}]} && !${Me.GemTimer[${Me.Gem[${${CurrentSub}${i}}]}]} && ${NoGlobalTimer} && !${Me.Casting.ID}) {
			/call Cast "${${CurrentSub}${i}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]} CheckAggro
			/delay 5 ${Me.Casting.ID}
				/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
					/varset Last${CurrentSub}${i} ${Target.ID}
					/varset ${CurrentSub}Recast${i} ${${CurrentSub}Recast${i}.OriginalValue}
				}
			}
:skip
/next i
/return


Sub CastIfReady(subname,int force)
/varset CurrentSub ${subname}
/declare i int local
/for i 1 to 30
/if (!${Defined[${CurrentSub}${i}]}) /return
	/if (${${CurrentSub}Conditions${i}.Find[\]}) /goto :con1
	/if (${${CurrentSub}Conditions${i}}||!${Defined[${CurrentSub}Conditions${i}]}) /goto :ready
	/goto :skip
	:con1
	/if (!${${CurrentSub}Conditions${i}.Replace[\,]}) /goto :skip
	:ready
	/if (${FindItem[${${CurrentSub}${i}}].InvSlot} && !${FindItem[${${CurrentSub}${i}}].Timer}  && !${Me.Casting.ID}) /call Cast "${${CurrentSub}${i}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
	/if (${Me.AltAbilityReady[${${CurrentSub}${i}}]}  && !${Me.Casting.ID}) /call Cast "${${CurrentSub}${i}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]} CheckAggro
	/if (${Me.SpellReady[${${CurrentSub}${i}}]}||${Me.Book[${${CurrentSub}${i}}]} && ${force} && !${Me.AltAbility[${${CurrentSub}${i}}]} && !${Me.GemTimer[${Me.Gem[${${CurrentSub}${i}}]}]} && !${Me.Casting.ID}) /call Cast "${${CurrentSub}${i}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]} CheckAggro
	/if (${Me.CombatAbilityReady[${${CurrentSub}${i}}]} && (!${Melee.DiscID}||!${Spell[${${CurrentSub}${i}}].Duration})) /call Cast "${${CurrentSub}${i}}" disc ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
	:skip
/next i
/return

Sub CastOncePerMob(subname,int force)
/if (${Last${subname}}==${Target.ID}) /return
/varset CurrentSub ${subname}
/if (!${Defined[${subname}]}) /return
	/if (${${CurrentSub}Conditions.Find[\]}) /goto :con1
	/if (${${CurrentSub}Conditions}||!${Defined[${CurrentSub}Conditions]}) /goto :ready
	/goto :skip
	:con1
	/if (!${${CurrentSub}Conditions.Replace[\,]}) /goto :skip
	:ready
	/if (${FindItem[${${CurrentSub}}].InvSlot} && !${FindItem[${${CurrentSub}}].Timer}  && !${Me.Casting.ID}) /call Cast "${${CurrentSub}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
	/if (${Me.AltAbilityReady[${${CurrentSub}}]}  && !${Me.Casting.ID}) {
			/call Cast "${${CurrentSub}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
			/varset Last${CurrentSub} ${Target.ID}
		}
	/if (${Me.SpellReady[${${CurrentSub}}]}||${Me.Book[${${CurrentSub}}]} && ${force} && !${Me.AltAbility[${${CurrentSub}}]}  && !${Me.Casting.ID}) /call Cast "${${CurrentSub}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]} CheckAggro
	/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) /varset Last${CurrentSub} ${Target.ID}

	:skip
	
/return

Sub CheckAggro
/if (${CurrentSub.Equal[Jolt]}||${Me.PctAggro}<90) /return
/varset CurrentSub CheckAggro
/declare i int local
/for i 1 to 20
/if (!${Defined[Jolt${i}]}) /return
	/if (${JoltConditions${i}.Find[\]}) /goto :con1
	/if (${JoltConditions${i}}||!${Defined[JoltConditions${i}]}) /goto :ready
	/goto :skip
	:con1
	/if (!${JoltConditions${i}.Replace[\,]}) /goto :skip
	:ready
	/if (${FindItem[${Jolt${i}}].InvSlot} && !${FindItem[${Jolt${i}}].Timer}) {
		/call Interrupt
		/call Cast "${Jolt${i}}" item
	}
	/if (${Me.AltAbilityReady[${Jolt${i}}]}) {
		/call Interrupt
		/alt act ${Me.AltAbility[${Jolt${i}}].ID}
	}
	/if (${Me.SpellReady[${Jolt${i}}]}) {
		/call Interrupt
		/call Cast "${Jolt${i}}" ${DefaultGem} 5s
	}
:skip
/next i
/return

Sub CastMed
  /if (${Me.PctMana}<${MedAt} && !${MedTimer} && !${Me.Mount.ID} && ${Me.State.Equal[STAND]} && (${Me.CombatState.Equal[ACTIVE]}||${Me.CombatState.Equal[DEBUFFED]} && !${Debuff.Count})) {
  		/sit
		/varset MedTimer ${MedTimer.OriginalValue}
		}
/return


|#event CastImHit     "#*# YOU for #*#"
|#event CastImHit     "#*# YOU, but #*#"

Sub Event_CastImHit
/declare i int local
/for i 1 to 20
/if (!${Defined[ImHit${i}]}) /return
	/if (${ImHitConditions${i}.Find[\]}) /goto :con1
	/if (${ImHitConditions${i}}||!${Defined[ImHitConditions${i}]}) /goto :ready
	/goto :skip
	:con1
	/if (!${ImHitConditions${i}.Replace[\,]}) /goto :skip
	/goto :ready
	:ready
	/if (${FindItem[${ImHit${i}}].InvSlot} && !${FindItem[${ImHit${i}}].Timer}) /call Cast "${ImHit${i}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
	/if (${Me.AltAbilityReady[${ImHit${i}}]}) /call Cast "${ImHit${i}}" alt ${If[${Defined[ImHitColor]},${ImHitColor},Orange]}
	/if (${Me.SpellReady[${ImHit${i}}]}) /call Cast "${ImHit${i}}" ${DefaultGem} ${If[${Defined[ImHitColor]},${ImHitColor},Orange]}
	/if (${Me.CombatAbilityReady[${ImHit${i}}]}) /call Cast "${ImHit${i}}" disc ${If[${Defined[ImHitColor]},${ImHitColor},Orange]}
	/if (${Me.AbilityReady[${ImHit${i}}]}) /call Cast "${ImHit${i}}" ability ${If[${Defined[ImHitColor]},${ImHitColor},Orange]}
	
	:skip
/next i
/return

Sub CastOnGroup(subname,int force)
/varset CurrentSub ${subname}
/declare i int local
/declare x int local
/if (${Target.ID} && ${Target.ID}==${TarID}) /varset TempTargetID ${Target.ID}
/for x 1 to 20
/if (!${Defined[${CurrentSub}${x}]}||!${Group}) /return
	/for i 0 to 5
		/if (${${CurrentSub}${x}${Group.Member[${i}].ID}}||!${Group.Member[${i}].ID}) /goto :skip
		/if (${${CurrentSub}Conditions${x}.Find[\]}) /goto :con1
		/if (${${CurrentSub}Conditions${x}}||!${Defined[${CurrentSub}Conditions${x}]}) /goto :ready
		/goto :skip
		:con1
		/if (!${${CurrentSub}Conditions${x}.Replace[\,]}) /goto :skip
		:ready
		/if (${Spell[${${CurrentSub}${x}}].TargetType.NotEqual[self]}) /squelch /tar id ${Group.Member[${i}].ID}
		/delay 1s ${Target.ID}==${Group.Member[${i}].ID}
			/if (${FindItem[${${CurrentSub}${x}}].InvSlot} && !${FindItem[${${CurrentSub}${x}}].Timer}) {
				/call Cast "${${CurrentSub}${x}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}
			/if (${Me.AltAbilityReady[${${CurrentSub}${x}}]}) {
				/call Cast "${${CurrentSub}${x}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
				}	
			/if (${Me.SpellReady[${${CurrentSub}${x}}]}||${Me.Book[${${CurrentSub}${x}}]} && ${force} && !${Me.AltAbility[${${CurrentSub}${x}}]} && ${NoGlobalTimer}) {
				/call Cast "${${CurrentSub}${x}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}				
	:skip
	
	/next i
/next x
/if (${TempTargetID} && !${Me.Casting.ID} && ${Spawn[${TempTargetID}].Type.Equal[npc]} && ${Target.ID}!=${TempTargetID}) /squelch /tar id ${TempTargetID}
/return

Sub CastOnPets(subname, int force)
/varset CurrentSub ${subname}
/declare i int local
/declare x int local
/if (${Target.ID} && ${Target.ID}==${TarID}) /varset TempTargetID ${Target.ID}
/for x 1 to 20
/if (!${Defined[${CurrentSub}${x}]}) /return
	/for i 0 to 5
	/if (!${Group.Member[${i}].Pet.ID}||${${CurrentSub}${x}${Group.Member[${i}].Pet.ID}}) /goto :skip
	/if (${${CurrentSub}Conditions${x}.Find[\]}) /goto :con1
	/if (${${CurrentSub}Conditions${x}}||!${Defined[${CurrentSub}Conditions${x}]}) /goto :ready
	/goto :skip
	:con1
	/if (!${${CurrentSub}Conditions${x}.Replace[\,]}) /goto :skip
		:ready
		/squelch /tar id ${Group.Member[${i}].Pet.ID}
		/delay 1s ${Target.ID}==${Group.Member[${i}].Pet.ID}
			/if (${FindItem[${${CurrentSub}${x}}].InvSlot} && !${FindItem[${${CurrentSub}${x}}].Timer}) {
				/call Cast "${${CurrentSub}${x}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].Pet.ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}
			/if (${Me.AltAbilityReady[${${CurrentSub}${x}}]}) {
				/call Cast "${${CurrentSub}${x}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].Pet.ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} ${${CurrentSub}Recast${x}.OriginalValue}
				}	
			/if (${Me.SpellReady[${${CurrentSub}${x}}]}||${Me.Book[${${CurrentSub}${x}}]} && ${force} && !${Me.AltAbility[${${CurrentSub}${x}}]} && ${NoGlobalTimer}) {
				/call Cast "${${CurrentSub}${x}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Group.Member[${i}].Pet.ID}]}) /declare ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Group.Member[${i}].Pet.ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}				
		:skip
	
	/next i
/next x
/if (${TempTargetID} && !${Me.Casting.ID} && ${Spawn[${TempTargetID}].Type.Equal[npc]} && ${Target.ID}!=${TempTargetID}) /squelch /tar id ${TempTargetID}
/return

Sub CastOnXTarget(subname,int force)
/varset CurrentSub ${subname}
/declare i int local
/declare x int local
/if (${Target.ID} && ${Target.ID}==${TarID}) /varset TempTargetID ${Target.ID}
/for x 1 to 20
/if (!${Defined[${CurrentSub}${x}]}) /return
	/for i 1 to 10
		/if (${${CurrentSub}${x}${Me.XTarget[${i}].ID}}||!${Me.XTarget[${i}].ID}) /goto :skip
		/if (${${CurrentSub}Conditions${x}.Find[\]}) /goto :con1
		/if (${${CurrentSub}Conditions${x}}||!${Defined[${CurrentSub}Conditions${x}]}) /goto :ready
		/goto :skip
		:con1
		/if (!${${CurrentSub}Conditions${x}.Replace[\,]}) /goto :skip
		:ready
		/if (${Spell[${${CurrentSub}${x}}].TargetType.NotEqual[self]}) /squelch /tar id ${Me.XTarget[${i}].ID}
		/delay 1s ${Target.ID}==${Me.XTarget[${i}].ID}
			/if (${FindItem[${${CurrentSub}${x}}].InvSlot} && !${FindItem[${${CurrentSub}${x}}].Timer}) {
				/call Cast "${${CurrentSub}${x}}" item ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Me.XTarget[${i}].ID}]}) /declare ${CurrentSub}${x}${Me.XTarget[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Me.XTarget[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}
			/if (${Me.AltAbilityReady[${${CurrentSub}${x}}]}) {
				/call Cast "${${CurrentSub}${x}}" alt ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
						/if (!${Defined[${CurrentSub}${x}${Me.XTarget[${i}].ID}]}) /declare ${CurrentSub}${x}${Me.XTarget[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Me.XTarget[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
				}	
			/if (${Me.SpellReady[${${CurrentSub}${x}}]}||${Me.Book[${${CurrentSub}${x}}]} && ${force} && !${Me.AltAbility[${${CurrentSub}${x}}]} && ${NoGlobalTimer}) {
				/call Cast "${${CurrentSub}${x}}" ${DefaultGem} ${If[${Defined[${CurrentSub}Color]},${${CurrentSub}Color},Orange]}
					/if (${Macro.Return.Equal[CAST_SUCCESS]}||${Macro.Return.Equal[CAST_NOTHOLD]}) {
						/if (!${Defined[${CurrentSub}${x}${Me.XTarget[${i}].ID}]}) /declare ${CurrentSub}${x}${Me.XTarget[${i}].ID} timer outer
						/if (${Defined[${CurrentSub}Recast${x}]}) /varset ${CurrentSub}${x}${Me.XTarget[${i}].ID} ${${CurrentSub}Recast${x}.OriginalValue}
					}
				}				
	:skip
	
	/next i
/next x
/if (${TempTargetID} && !${Me.Casting.ID} && ${Spawn[${TempTargetID}].Type.Equal[npc]} && ${Target.ID}!=${TempTargetID}) /squelch /tar id ${TempTargetID}
/return

Sub CastModRod
/varset CurrentSub CastModRod
/if (${Me.Hovering}) /return
/if (${Select[${Cursor.ID},9963,76504,79322,79321,79320,6346,64953,64954,64955,64979,64980,64981,64982,64983,64984,52817,64951,52709,3426,57264,52674,76503,121336,64978,77613,77678,77681,57265,52818,52710,77679,64952,77682,52701,76501]}) /autoinventory
|update alert
/if (!${Defined[ModRodList]}) /declare ModRodList string outer |Summoned: Large Modulation Shard|Summoned: Medium Modulation Shard|Summoned: Small Modulation Shard|Rod of Arcane Transvergence|Rod of Spectral Transvergence|Rod of Ethereal Transvergence|Rod of Prime Transvergence|Wand of Elemental Transvergence|Rod of Mystical Transvergence|Summoned: Modulating Rod|Wand of Phantasmal Modulation|
/declare i int local
/for i 1 to ${Math.Calc[${ModRodList.Count[|]}-1]} {
	/if (${FindItem[${ModRodList.Arg[${i},|]}].InvSlot} && !${FindItem[${ModRodList.Arg[${i},|]}].Timer} && ${Me.CurrentHPs}>${Math.Abs[${Spell[${FindItem[${ModRodList.Arg[${i},|]}].Spell.ID}].Base[1]}]} && ${Math.Calc[${Me.MaxMana}-${Me.CurrentMana}]}>=${Spell[${FindItem[${ModRodList.Arg[${i},|]}].Spell.ID}].Base[2]}) {
		/if (${Me.HaveExpansion[Veil of Alaris]}) /call Cast "${FindItem[${ModRodList.Arg[${i},|]}].InvSlot}" item Green
		}
/next i
/return

Sub CastDPSLoad
/if (${DPSLoaded}) /return
/declare DPSLoaded int outer 1
/declare FightID int outer
/declare FightStartTime float outer
/declare FightTotalTime float outer
/declare FightTimeRemaining float outer
/declare FightTimer timer outer
/declare AnnounceTimeRemaining bool outer ${Ini[MySpellIni,Settings,AnnounceTimeRemaining,TRUE]}
/declare AnnouncedTimer timer outer ${Ini[MySpellIni,Settings,AnnouncedTimer,10s]}
/return

Sub CastDPS(int dpsID)
/varset CurrentSub CastDPS
/if (${Me.Hovering}||!${Spawn[id ${dpsID}].Type.Equal[npc]} && !${Spawn[id ${dpsID}].Master.Type.Equal[npc]}||!${dpsID}) /return
  /if (!${DPSLoaded}) /call CastDPSLoad
  /if (${dpsID}!=${FightID}) {
	/varset FightID ${dpsID}
	/varset FightStartTime ${MacroQuest.Running}
	}
  /varcalc FightTotalTime (${MacroQuest.Running}-${FightStartTime})/1000
  /varcalc FightTimeRemaining (100/((100-${Target.PctHPs})/(${FightTotalTime}+.0001))-${FightTotalTime})
  /varset FightTimer ${Math.Calc[${FightTimeRemaining}].Int}s
  /if (${AnnounceTimeRemaining} && !${AnnouncedTimer} && ${FightTimeRemaining}>1) {
	/echo Time until ${Target.CleanName} dies: ~${FightTimeRemaining} Seconds
	/varset AnnouncedTimer ${AnnouncedTimer.OriginalValue}
	}
/return

Sub CastAutoClickies
/varset CurrentSub CastAutoClickies
/if (!${Defined[AutoClickiesLoad]}) /call CastAutoClickiesLoad
/call CastDoClickies
/if (${FindItem[Chalandria's Fang].InvSlot} && !${FindItem[Chalandria's Fang].Timer}) {
		/if (${Me.VOA}) /useitem ${FindItem[=Chalandria's Fang].ItemSlot} ${FindItem[=Chalandria's Fang].ItemSlot2} 
		/if (!${Me.VOA}) /casting "Chalandria's Fang"|item
		/delay 1s
		/autoinventory
		}
/return


Sub CastAutoClickiesLoad
/varset CurrentSub CastAutoClickiesLoad
/if (${AutoClickiesLoaded}) /return
/if (!${Defined[AutoClickiesLoad]}) /declare AutoClickiesLoad int outer 1
/declare iBuffTotal int outer 17
/declare ClickyArray[${iBuffTotal},4] string outer 0
/declare sBuff1 string outer Ancestral Memories
/declare sBuffClass1 string outer |BER|BST|BRD|MNK|PAL|RNG|ROG|SHD|WAR|
/declare sBuff2 string outer Taelosian Guard
/declare sBuffClass2 string outer |BER|BST|BRD|MNK|PAL|RNG|ROG|SHD|WAR|
/declare sBuff3 string outer Might of Stone
/declare sBuffClass3 string outer |BER|BST|BRD|MNK|PAL|RNG|ROG|SHD|WAR|
/declare sBuff4 string outer Form of Defense
/declare sBuffClass4 string outer |PAL|SHD|WAR|
/declare sBuff5 string outer Prismatic Ward
/declare sBuffClass5 string outer |BER|BST|BRD|CLR|DRU|ENC|MAG|MNK|NEC|PAL|RNG|ROG|SHD|SHM|WAR|WIZ|
/declare sBuff6 string outer Form of Endurance
/declare sBuffClass6 string outer |BER|BST|BRD|CLR|DRU|ENC|MAG|MNK|NEC|PAL|RNG|ROG|SHD|SHM|WAR|WIZ|
/declare sBuff7 string outer Myrmidon's Skill
/declare sBuffClass7 string outer |BER|BST|BRD|CLR|DRU|ENC|MAG|MNK|NEC|PAL|RNG|ROG|SHD|SHM|WAR|WIZ|
/declare sBuff8 string outer Knowledge of the Past
/declare sBuffClass8 string outer |BST|CLR|DRU|ENC|MAG|NEC|PAL|RNG|SHD|SHM|WIZ|
/declare sBuff9 string outer Soothing Breath
/declare sBuffClass9 string outer |BST|CLR|DRU|ENC|MAG|NEC|PAL|RNG|SHD|SHM|WIZ|
/declare sBuff10 string outer Illusionary Spikes
/declare sBuffClass10 string outer |
/declare sBuff11 string outer Geomantra
/declare sBuffClass11 string outer |
/declare sBuff12 string outer Expanding Mind
/declare sBuffClass12 string outer |BST|CLR|DRU|ENC|MAG|NEC|PAL|RNG|SHD|SHM|WIZ|
/declare sBuff13 string outer Symphony of Battle
/declare sBuffClass13 string outer |BRD|
/declare sBuff14 string outer Twitching Speed
/declare sBuffClass14 string outer |BER|BST|MNK|PAL|RNG|ROG|SHD|WAR|
/declare sBuff15 string outer Aura of Pure Arcanum
/declare sBuffClass15 string outer |BER|BST|BRD|CLR|DRU|ENC|MAG|MNK|NEC|PAL|RNG|ROG|SHD|SHM|WAR|WIZ|
/declare sBuff16 string outer Aura of Rage
/declare sBuffClass16 string outer |BER|BST|MNK|PAL|RNG|ROG|SHD|WAR|
/declare sBuff17 string outer Ancient Flames
/declare sBuffClass17 string outer |BER|BST|BRD|CLR|DRU|ENC|MAG|MNK|NEC|PAL|RNG|ROG|SHD|SHM|WAR|WIZ|

/declare BuffRank string outer , I , II , III , IV , V , VI , VII , VIII , IX , X , XI , XII , XII , XIV , XV , XVI , XVII , XVIII , XIX , XX , XXI , XXII , XXIII , XXIV , XXV ,
/call CastGetEquipment
/call CastCalculateBest
/return

Sub CastCalculateBest
/varset CurrentSub CastCalculateBest
/declare CalculateBest int outer 1
|Soothing vs KotP
|${Spell[Knowledge of the Past].Slot[8].Left[-9].Right[-17]}

/if (${ClickyArray[9,1]} && ${ClickyArray[8,1]}) {
	/if (${Spell[${ClickyArray[8,2]}].Slot[8].Left[-9].Right[-17]}>${Spell[${ClickyArray[9,2]}].Slot[8].Left[-9].Right[-17]}) {
		/varset ClickyArray[9,1] 0
		|/echo ${ClickyArray[8,2]} is best
		} else {
		/varset ClickyArray[8,1] 0
		|/echo ${ClickyArray[9,2]} is best
		}
}

|FoD vs Pris Ward
|${Spell[name].Slot[10].Left[-15]}

/if (${ClickyArray[4,1]} && ${ClickyArray[5,1]}) {
	/if (${Spell[${ClickyArray[4,2]}].Slot[10].Right[-15]}>${Spell[${ClickyArray[5,2]}].Slot[10].Right[-15]}) {
		/varset ClickyArray[5,1] 0
		|/echo ${ClickyArray[4,2]} is best
		} else {
		/varset ClickyArray[4,1] 0
		|/echo ${ClickyArray[5,2]} is best
	}
}
|Taelosian vs AM
|${Spell[Ancestral Memories III].Slot[1].Left[-1].Right[-21]}
/if (${ClickyArray[2,1]} && ${ClickyArray[1,1]}) {
	/if (${Spell[${ClickyArray[1,2]}].Slot[1].Left[-1].Right[-21]}>${Spell[${ClickyArray[2,2]}].Slot[1].Left[-1].Right[-21]}) {
		/varset ClickyArray[2,1] 0
		|/echo ${ClickyArray[1,2]} is best
		} else {
		/varset ClickyArray[1,1] 0
		|/echo ${ClickyArray[2,2]} is best
	}
}
/return


Sub CastDoClickies
/if (${Me.Hovering}||!${MMOBugs.FreeBuffs} && ${MMOBugs}||${Me.Casting.ID} && !${Me.Class.ShortName.Equal[BRD]}) /return
/varset CurrentSub CastDoClickies
/declare i int local
/for i 1 to ${iBuffTotal}
/if (${ClickyArray[${i},1]} && ${Spell[${ClickyArray[${i},2]}].Stacks} && !${Me.Buff[${ClickyArray[${i},2]}].ID} && (!${Me.Invis}||${AutoBreakInvis} && ${AutoInvis}) && !${Me.Sitting} && (!${Me.Moving}||${Me.Class.ShortName.Equal[BRD]}) && (!${Me.Song[Commanding Voice].ID} && !${Me.Buff[Commanding Voice].ID} && !${Me.Song[Guardian Circle I Effect].ID} && !${Me.Song[Guardian Circle II Effect].ID} && !${Me.Song[Guardian Circle III Effect].ID}||${i}!=7)) {
	/if (${Me.Hovering}||!${MMOBugs.FreeBuffs} && ${MMOBugs}||${Me.Casting.ID} && !${Me.Class.ShortName.Equal[BRD]}) /return
	/if (${Twist.Twisting}) {
		/declare twisttemp bool local
		/twist off
		/delay 2
		}
	/if (${FindItem[${ClickyArray[${i},3]}].EffectType.Equal[Click Inventory]} && ${Me.VOA} && (${Me.Subscription.Equal[GOLD]}||${FindItem[=${ClickyArray[${i},3]}].InvSlot}<33)) /useitem ${FindItem[=${ClickyArray[${i},3]}].ItemSlot} ${FindItem[=${ClickyArray[${i},3]}].ItemSlot2}
	/if (${FindItem[${ClickyArray[${i},3]}].EffectType.Equal[Click Worn]}||!${Me.VOA}||${Me.Subscription.NotEqual[GOLD]}) /casting "${ClickyArray[${i},3]}"|item
	/delay 1s ${Me.Casting.ID}
	/if (${Plugin[mq2cecho].Name.Equal[mq2cecho]}) /cechob \au${ClickyArray[${i},3]} \aw--> ${ClickyArray[${i},2]}
	/if (!${Plugin[mq2cecho].Name.Equal[mq2cecho]}) /echo ${ClickyArray[${i},3]} --> ${ClickyArray[${i},2]}
	/delay 10s !${Me.Casting.ID}
	/if (${twisttemp}) /twist on
	}
/next i
/return


Sub CastGetEquipment
/varset CurrentSub CastGetEquipment
/declare GetEquipment int outer 1
/declare sTempName string local
/declare i int local
/declare ii int local
/declare iSlot int outer
/declare iItemNum int outer
/declare sItemName string outer
/declare iClickyRank int outer
   	/for iSlot 1 to 32
	|top level inventory
	/if (${InvSlot[${iSlot}].Item.Name.NotEqual[NULL]}) {
			/varset sItemName ${InvSlot[${iSlot}].Item.Spell.Name}
			/if (${sItemName.NotEqual[NULL]} && ${InvSlot[${iSlot}].Item.EffectType.Find[Click]} && ${Me.Level}>=${Me.Inventory[${iSlot}].RequiredLevel} && ${Me.Inventory[${iSlot}].Class[${Me.Class}].Name.Equal[${Me.Class}]} && (!${Me.Inventory[${iSlot}].Attuneable}||${Me.Inventory[${iSlot}].Attuneable} && ${Me.Inventory[${iSlot}].NoDrop})) {
			/for i 1 to ${iBuffTotal} {
				
				/if (${Me.Inventory[${iSlot}].Spell.Name.Find[${sBuff${i}}]} && (${Me.Subscription.Equal[GOLD]}||!${Me.Inventory[${iSlot}].Item.Prestige})) {
						/if (${Me.Inventory[${iSlot}].Spell.Name.Equal[${sBuff${i}}]}) {
							/varset iClickyRank 26
							/goto :skipii
							}
						/varcalc iClickyRank ${Me.Inventory[${iSlot}].Spell.Rank}+1
						:skipii	
						/if (${sBuffClass${i}.Find[${Me.Class.ShortName}]} && ${iClickyRank}>${ClickyArray[${i},4]}) {
							/varset ClickyArray[${i},1] 1
							/varset ClickyArray[${i},2] ${Me.Inventory[${iSlot}].Spell}
							/varset ClickyArray[${i},3] ${Me.Inventory[${iSlot}]}
							/varset ClickyArray[${i},4] ${iClickyRank}
						}
					}
				}
			/next i
			}			
		}
	|Bag inventory
      	/if (${InvSlot[${iSlot}].Item.Container}>0) {
         /for iItemNum 1 to ${InvSlot[${iSlot}].Item.Container}
            /if (${Me.Inventory[${iSlot}].Item[${iItemNum}].ID} && ${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell.ID} && ${Me.Inventory[${iSlot}].Item[${iItemNum}].CastTime} && ${Me.Inventory[${iSlot}].Item[${iItemNum}].WornSlots} && ${Me.Level}>=${Me.Inventory[${iSlot}].Item[${iItemNum}].RequiredLevel} && ${Me.Inventory[${iSlot}].Item[${iItemNum}].Class[${Me.Class}].Name.Equal[${Me.Class}]} && ${Spell[${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell}].Duration}>50 && (!${Me.Inventory[${iSlot}].Item[${iItemNum}].Attuneable}||${Me.Inventory[${iSlot}].Item[${iItemNum}].Attuneable} && ${Me.Inventory[${iSlot}].Item[${iItemNum}].NoDrop}) && (${Me.Subscription.Equal[GOLD]}||!${Me.Inventory[${iSlot}].Item[${iItemNum}].Prestige})) {
			/for i 1 to ${iBuffTotal} {
				/if (${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell.Name.Find[${sBuff${i}}]}) {
						/if (${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell.Name.Equal[${sBuff${i}}]}) {
							/varset iClickyRank 26
							/goto :skipiii
						}
						/varcalc iClickyRank ${Me.Inventory[${iSlot}].Spell.Rank}+1
						:skipiii
						/if (${sBuffClass${i}.Find[${Me.Class.ShortName}]} && ${iClickyRank}>${ClickyArray[${i},4]}) {
							/varset ClickyArray[${i},1] 1
							/varset ClickyArray[${i},2] ${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell}
							/varset ClickyArray[${i},3] ${Me.Inventory[${iSlot}].Item[${iItemNum}].Name}
							/varset ClickyArray[${i},4] ${iClickyRank}
							|/echo ${Me.Inventory[${iSlot}].Item[${iItemNum}].Name} - ${Me.Inventory[${iSlot}].Item[${iItemNum}].Spell}
						}
					}
				}
			/next i
            		}
         	/next iItemNum
	}
	/next iSlot

/return


#event Banestrike "Your Banestrike fails because you have not yet mastered slaying this race."
Sub Event_Banestrike
/if (!${Defined[Banestrike]}) /declare Banestrike string outer |
/if (${Target.ID} && !${Banestrike.Find[|${Target.Race}|]}) /varset Banestrike ${Banestrike}${Target.Race}|
/return

Sub CastInitialize
/varset CurrentSub CastInitialize
/if (!${Defined[Option]}) /return
/declare i int local
/declare x int local
/if (!${Defined[CurrentSub]}) /declare CurrentSub string outer CastInitiliaze
/call SpellRoutinesLoad
/for x 1 to ${Option.Count[|]}
/declare ${Option.Arg[${x},|]}Total int outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Total]}
/if (${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Color].Length}) /declare ${Option.Arg[${x},|]}Color string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Color]}
/if (${OptionType.Arg[${x},|]}==3) /goto :option3
/if (!${${Option.Arg[${x},|]}Total}) /goto :skipx
    /for i 1 to ${${Option.Arg[${x},|]}Total}
        /declare ${Option.Arg[${x},|]}Use${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Use${i}]}
        /if (!${Defined[${Option.Arg[${x},|]}${i}]}) /declare ${Option.Arg[${x},|]}${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}SpellName${i}]}
        /if (!${Defined[${Option.Arg[${x},|]}SpellName${i}]}) /declare ${Option.Arg[${x},|]}SpellName${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}SpellName${i}]}
        /declare ${Option.Arg[${x},|]}Conditions${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Conditions${i},123456]}
        /if (${${Option.Arg[${x},|]}Conditions${i}.Equal[123456]}) /deletevar ${Option.Arg[${x},|]}Conditions${i}
        /if (${OptionType.Arg[${x},|]}==2) /declare ${Option.Arg[${x},|]}Recast${i} timer outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Recast${i}]}
        /if (${OptionType.Arg[${x},|]}==2) /declare Last${Option.Arg[${x},|]}${i} timer outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Recast${i}]}
        /goto :skipi
        :option3
        /declare ${Option.Arg[${x},|]}Use${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Use${i}]}
        /declare ${Option.Arg[${x},|]}${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}SpellName${i}]}
        /declare ${Option.Arg[${x},|]}Conditions${i} string outer ${Ini[MySpellIni,${Option.Arg[${x},|]},${Option.Arg[${x},|]}Conditions${i},123456]}
        /if (${${Option.Arg[${x},|]}Conditions.Equal[123456]}) /deletevar ${Option.Arg[${x},|]}Conditions    
        /declare Last${OptionType.Arg[${x},|]} int outer
        :skipi
    /next i
:skipx
/next x
/return