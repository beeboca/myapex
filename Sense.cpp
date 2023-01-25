#pragma once
#include <vector>
#include "LocalPlayer.cpp"
#include "Player.cpp"
#include "Math.cpp"
#include "Level.cpp"
#include "X11Utils.cpp"
#include "ConfigLoader.cpp"

class Sense
{
private:
    ConfigLoader *m_configLoader;
    Level *m_level;
    LocalPlayer *m_localPlayer;
    std::vector<Player *> *m_players;
    X11Utils *m_x11Utils;

public:
    Sense(ConfigLoader *configLoader,
          Level *level,
          LocalPlayer *localPlayer,
          std::vector<Player *> *players,
          X11Utils *x11Utils)
    {
        m_configLoader = configLoader;
        m_level = level;
        m_localPlayer = localPlayer;
        m_players = players;
        m_x11Utils = x11Utils;
    }
    void update(int counter)
    {
        if (!m_level->isPlayable())
            return;
        for (int i = 0; i < m_players->size(); i++)
        {
            Player *player = m_players->at(i);
            if (!player->isValid())
                continue;
            if (player->getTeamNumber() == m_localPlayer->getTeamNumber())
                continue;
            if (player->isVisible())
            {
                player->setGlowEnable(5);
                player->setGlowThroughWall(1);
            }
            else
            {
                player->setGlowEnable(7);
                player->setGlowThroughWall(2);
            }
        }
        
        for (size_t i = 0; i < 15; i++) {
		int index = (counter * 15) + i;
		long ent_base = mem::ReadLong(offsets::REGION + offsets::ENTITY_LIST + ((index + 1) << 5));
		if (ent_base == 0) {
			continue;
		}
		std::string class_name = mem::get_client_class_name(ent_base);

		if (class_name != "CPropSurvival" && class_name != "CWeaponX") {
			continue;
		}      
		int itemID = mem::ReadInt(ent_base + 0x1648);
		switch (itemID) {
			case 1:   // Kraber
			case 27:  // VK-47 Flatline
			case 47:  // r99
			case 57:  // volt
			case 67:  // charge rifle
			case 72:  // spitfire
			case 77:  // R-301 Carbine
			case 127: // rampage
		 	case 128: // car
			case 172: // Shield (Level 3 / Purple)
			case 176: // Evo Shield (Level 3 / Purple)
			case 177: // Evo Shield (Level 5 / red)
		 	case 171: // Helmet (Level 4 / Gold)
			case 184: //backpack level 2
			case 185: // Backpack (Level 3 / Purple)
			case 186: // Backpack (Level 4 / Gold)
			case 167: // Head Level 3 / Purple
		 	case 168: // Head Level 4 / Gold
		    case 163: // shield battery
		    case 210: //light mag level 3
			case 211: //light mag level 4
			case 214: //heavy mag level 3
			case 215: //heavy mag level 4
			case 222: //sniper mag level 3
			case 223: //sniper mag level 4
			case 182: //knockdown shield level 4
			
		    mem::WriteInt(ent_base + 0x02c0, 1363184265);

		    break;
		    }
		}
    }
};
