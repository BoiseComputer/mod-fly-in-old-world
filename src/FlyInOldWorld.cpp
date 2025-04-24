/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "Config.h"
#include "ScriptMgr.h"
#include "Player.h"

class FlyInOldWorld : public PlayerScript
{
public:
    FlyInOldWorld() : PlayerScript("FlyInOldWorld") {}

    bool OnCanPlayerFlyInZone(Player *player, uint32 mapId, uint32 zoneId, SpellInfo const *bySpell) override
    {
        if (!sConfigMgr->GetBoolDefault("ModOldWorldFlying.Enable", true))
            return false;

        uint32 spellId = sConfigMgr->GetIntDefault("ModOldWorldFlying.SpellId", 200001);
        uint32 v_map = GetVirtualMapForMapAndZone(mapId, zoneId);
        if (v_map == 0 || v_map == 1)
        {
            if (!player->HasSpell(spellId))
            {
                return false;
            }
        }
        return true;
    }
};

// Add all scripts in one
void AddFlyInOldWorld()
{
    new FlyInOldWorld();
}
