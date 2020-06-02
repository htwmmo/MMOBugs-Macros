| MQ2Cast.inc - Version 0.2 (beta) - 12/24/17
| 
| Format: /call Cast "SpellName" gem#|alt|item GiveUpTimerValue Attempts MySubroutineName
| 
Sub Cast(string SpellName, string SpellType, int GiveUpValue, int Attempts, string MySub)
  /declare DEBUG  bool  local FALSE
  /if ( ${DEBUG} ) /echo Called: ${SpellName} - ${SpellType} - ${GiveUpValue} - ${Attempts} - ${MySub}
  /if ( ( ${SpellType.Equal[item]} && !${FindItem[${SpellName}].ID} ) || ( ${SpellType.Left[3].Equal[gem]} && !${Me.Book[${Spell[${SpellName}].RankName}]} ) || ( ${SpellType.Equal[alt]} && !${Me.AltAbility[${SpellName}]} ) ) {
    /beep
    /echo \arUnknown: ${SpellName}\ay
    /return CAST_UNKNOWNSPELL
  }
  /while ( ${Cursor.ID} ) {
    /autoinventory
    /delay 10
  }
  /if ( ${SpellType.Left[3].Equal[gem]} ) {
    /varset SpellName ${Spell[${SpellName}].RankName}
    /if ( ${Me.CurrentMana} < ${Spell[${SpellName}].Mana} ) /return CAST_OUTOFMANA    
    /if ( !${Me.Gem[${SpellName}]} ) {
      /memspell ${SpellType.Right[-3]} "${SpellName}"
      /delay 50 !${Window[SpellBookWnd].Open}
      /delay 20
    }
  }
  /if ( ${Window[SpellBookWnd].Open} ) {
    /book
    /delay 50 !${Window[SpellBookWnd].Open}
    /delay 5
  }
  /if ( ${GiveUpValue} ) /declare GiveUpTimer timer local ${GiveUpValue}
  /if ( ${SpellType.Left[3].Equal[gem]} ) {
    /while ( ${Me.GemTimer[${Me.Gem[${SpellName}]}]} ) {
      /if ( !${GiveUpTimer} || ( ${Math.Calc[${Me.GemTimer[${Me.Gem[${SpellName}]}]} / 100].Int} > ${GiveUpTimer} ) ) {
        /if ( ${DEBUG} ) /echo ${SpellName} - ${Math.Calc[${Me.GemTimer[${Me.Gem[${SpellName}]}]} / 100].Int} > ${GiveUpTimer} - Not Ready
        /return CAST_NOTREADY
      }
    /delay 5
    }
    /goto :CastIt
  } 
  /if ( ${SpellType.Equal[item]} ) {
    /while ( ${FindItem[${SpellName}].Timer} ) {
      /if ( !${GiveUpTimer} || ( ${Math.Calc[${FindItem[${SpellName}].Timer} * 60].Int} > ${GiveUpTimer} ) ) {
        /if ( ${DEBUG} ) /echo ${SpellName} - ${Math.Calc[${FindItem[${SpellName}].Timer} * 60].Int} > ${GiveUpTimer} - Not Ready
        /return CAST_NOTREADY
      }
    /delay 5
    }
    /goto :CastIt
  }
  /if ( ${SpellType.Equal[alt]} ) {
    /while ( ${Me.AltAbilityTimer[${SpellName}]} ) {
      /if ( !${GiveUpTimer} || ( ${Math.Calc[${Me.AltAbilityTimer[${SpellName}]} / 100].Int} > ${GiveUpTimer} ) ) {
        /if ( ${DEBUG} ) /echo ${SpellName} - ${Math.Calc[${Me.AltAbilityTimer[${SpellName}]} / 100].Int} > ${GiveUpTimer} - Not Ready
        /return CAST_NOTREADY
      }
    /delay 5
    }
  }
  :CastIt
  /if ( ${Me.Ducking} ) {
    /keypress duck
    /delay 5
  }
  /while ( ${Me.Casting.ID} || ${Me.Moving} ) {
|   /if ( ${Bool[${MySub}]} ) /call ${MySub}
    /delay 5
  }
  /casting "${SpellName}" ${SpellType}
  /delay 5
  /while (${Cast.Status.Find[C]}) {
    /delay 5
  }
  /if ( ${Select[${Cast.Result},CAST_RESIST],CAST_FIZZLE,CAST_STUNNED,CAST_INTERRUPTED]} ) {
    /varcalc Attempts ${Attempts} - 1
    /if ( !${Attempts} ) /return ${Cast.Result}
    /goto :CastIt
  }
/return ${Cast.Result}