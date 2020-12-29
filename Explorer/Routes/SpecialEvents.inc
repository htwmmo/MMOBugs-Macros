|-----------------------------------------------------------------------------------------------------------
|                                    Special Events Route
|                                     Started: 16/10/2020
|-----------------------------------------------------------------------------------------------------------

|- Required: Dragoncrypt

|-----------------------------------------------------------------------------------------------------------
| Travel Loop - SpecialEvents
|-----------------------------------------------------------------------------------------------------------
	
Sub SpecialEvents

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,SpecialEvents]}==1) /return
	
	/lazyfind on
    /declare dcrypt 		int outer 0
    /declare LoyaltyTokens	int outer 0
	/declare pokspec		int outer 0
	
	/varset completed 0
		
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Special Events${Teal}**
|-----------------------------------------------------------------------------------------------------------
			

		
|-----------------------------------------------------------------------------------------------------------

:Special	
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PokSpecial
	/if (${Zone.ID}==187)						/call shadowrest 
	
	
	/delay 2m !${Navigation.Active}
/goto :Special	
	
Sub PokSpecial
	/delay 1s
	/if (${pokspec}==0) 		{
								/nav spawn npc Devin_Traical
								/delay 2m !${Navigation.Active}
								/makemevisible
								/delay 2s
								/if (${SpawnCount[npc Devin radius 18]}) /target npc Devin_traical
								/delay 5s ${Target.ID}
								/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Devin Traical]}) /say travel
	} else /if (${pokspec}==1) 	{
								/delay 1s
								/call checkLoyaltyTokens
								/if (${LoyaltyTokens}<864 && !${FindItemCount[=Forgotten Crypt Key]}) 	{
																										/echo ${Red}You do not have enough Loyalty Tokens to visit Dragoncrypt.
																										/echo ${White}You currently have ${Yellow}${LoyaltyTokens}${White} tokens. You need ${Green}864.
																										/delay 1s
																										/ini "${RouteIniFileName}" "CompletedRoutes" "SpecialEvents" "1"
																										/delay 2s
																										/return
																										}
								/if (!${FindItemCount[=Forgotten Crypt Key]}) 	{
																				/call getCryptKey
																				}
								/if (${FindItemCount[=Forgotten Crypt Key]}) 	{
																				/call goCrypt
																				}
								}
	/return
																				
																				
																				
Sub goCrypt												
								/squelch /nav spawn npc Tierna_Morganna
								/call Navigating
								/makemevisible
								/while (${Me.Invis}) 	{
														/delay 1
														}
								/squelch /target npc Tierna_Morganna
								/delay 10s ${Target.ID}
								/while (!${Window[TaskSelectWnd].Open}) {
																		/say I wish to venture into his lair.
																		/delay 5s (${Window[TaskSelectWnd].Open})
																		}
								/if (${Window[TaskSelectWnd].Open}) /notify TaskSelectWnd TSEL_AcceptButton leftmouseup
								
								/delay 3s
								/while (${Zone.ShortName.Equal[poknowledge]}) 	{
																				/delay 30s
																				/say ready
																				/delay 30s (!${Zone.ShortName.Equal[poknowledge]})
																				/if (!${Zone.ShortName.Equal[poknowledge]}) /break
																				}
								/if (${Zone.ID}==495) 	{
														/delay 4s
														/call SEComplete
														}
								}
/return
		
Sub shadowrest
	/delay 5s
	/varset pokspec 1
	/delay 1s
	/nav door ID 2 click
	/delay 8s !${Zone.ShortName.Equal[shadowrest]}
/return


| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub SEComplete	
	/echo ${White}You have completed Exploring: ${Green}Special Events. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "SpecialEvents" "1"
	/delay 1s
	/call Completed
/return
		

| -------------------------------------------------------------------------------------
| SUB: checkLoyaltyTokens
| ------------------------------------------------------------------------------------- 
Sub checkLoyaltyTokens
    /declare InvOpen bool local 0
    /declare AltCurrancyTab int local 0

    /if (${Window[InventoryWindow]}) {
        /varset InvOpen true
        /if (${Window[InventoryWindow].Child[IW_StatPage]}) {
            /varset AltCurrancyTab 2
        } else /if (${Window[InventoryWindow].Child[IW_AltCharProgPage]}) {
            /varset AltCurrancyTab 3
        } else /if (${Window[InventoryWindow].Child[IW_AltCurrPage]}) {
            /varset AltCurrancyTab 4
        } else /if (${Window[InventoryWindow].Child[IW_MercenaryInvPage]}) {
            /varset AltCurrancyTab 5
        }
    }

    /if (${Window[InventoryWindow].DoOpen}) {
        /notify InventoryWindow IW_Subwindows tabselect 4
        /delay 2s
        /delay 5s ${Window[InventoryWindow].Child[IW_AltCurrPage].Child[IW_AltCurr_PointList].Items} > 0
        /varset LoyaltyTokens ${Window[InventoryWindow].Child[IW_AltCurrPage].Child[IW_AltCurr_PointList].List[${Window[InventoryWindow].Child[IW_AltCurrPage].Child[IW_AltCurr_PointList].List[Loyalty Tokens,2]},4]}
        /if (!${LoyaltyTokens} && ${FindItemCount[=Forgotten Crypt Key]})	{
																			/echo ${Red}Could not find any Loyalty Tokens. ${White}Skipping ${Green}Dragoncrypt
																			/call SEComplete
																			}
																	}
	
    /if (${InvOpen})	{
						/notify InventoryWindow IW_Subwindows tabselect ${AltCurrancyTab}
						} else {
						/invoke ${Window[InventoryWindow].DoClose}
    }
/return



| -------------------------------------------------------------------------------------
| SUB: getCryptKey
|code from @ChatWithThisName
| ------------------------------------------------------------------------------------- 
Sub getCryptKey

	/squelch /target clear
    /squelch /nav spawn npc Alerynril_the_Loyal
	/call Navigating
	/target npc Alerynril_the_Loyal
	/delay 3s ${Target.ID}
    /click right target
	/delay 10s ${Merchant.ItemsReceived}
    /if (${Merchant.Open}) {
							/declare Key int local ${Window[MerchantWnd].Child[ItemList].List[=Forgotten Crypt Key,2]}
							/delay 1s
							/notify MerchantWnd MW_ItemList listselect ${Key}
							/nomodkey /ctrlkey /notify MerchantWnd MW_Buy_Button leftmouseup
							/delay 1s
							/if (${Window[ConfirmationDialogBox]}) 	{
																	/notify ConfirmationDialogBox CD_Yes_Button leftmouseup
																	}
							/doevents
							}
/return