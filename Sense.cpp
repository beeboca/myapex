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
			//case 2:     // Mastiff 
                        //case 82:     // EVA 8  
                        //case 87:     // Peacekeeper  
                        //case 92:     // Mozambique  
                        //case 123:     // Shotguns Shells  

                        //case 52:     // Prowler  
                        //case 22:     // Triple Take  
                        case 1:     // Kraber  

                        case 113:     // Bocek Bow  
                        //case 129:     // Arrows  

                        //case 7:     // L-Star  
                        //case 12:     // Havoc  
                        //case 17:     // Devotion  
                        case 57:     // Volt  
                        //case 122:     // Energy Ammo  

                        //case 27:     // Flatline  
                        //case 32:     // Hemlok  
                        //case 72:     // Spitfire  

                        case 127:     // Rampage LMG  
                        //case 128:     // C.A.R SMG  
                        //case 115:     // Repeater  
                        //case 124:     // Heavy Ammo  

                        //case 37:     // Scout  
                        //case 42:     // Alternator  
                        //case 47:     // R-99  
                        case 77:     // R-301  
                        //case 102:     // P2020  
                        case 107:     // RE-45  
                        //case 121:     // Light Ammo  

                        //case 62:     // Longbow  
                        //case 67:     // Charge  
                        //case 97:     // Wingman  
                        //case 108:     // Sentinel  
                        //case 125:     // Sniper Ammo  

                        //case 174:     // Evo Shield 1  
                        //case 175:     // Evo Shield 2  
                        case 176:     // Evo Shield 3  
                        case 177:     // Evo Shield 4  

                        //case 169:     // Shield 1  
                        //case 170:     // Shield 2  
                        case 171:     // Shield 3  
                        case 172:     // Shield 4  

                        //case 165:     // Helmet 1  
                        //case 166:     // Helmet 2  
                        case 167:     // Helmet 3  
                        case 168:     // Helmet 4  

                        //case 183:     // Backpack 1  
                        //case 184:     // Backpack 2  
                        case 185:     // Backpack 3  
                        case 186:     // Backpack 4  

                        //case 179:     // Knockdown Shield 1  
                        //case 180:     // Knockdown Shield 2  
                        case 181:     // Knockdown Shield 3  
                        case 182:     // Knockdown Shield 4  

                        //case 195:     // 1x Digital Threat  
                        //case 196:     // 3x Digital Threat  
                        //case 197:     // 2x-4x Variable AOG  
                        //case 200:     // 4x-10x Digital Threat  

                        case 191:     // 1x HCOG Classic  
                        case 192:     // 2x HCOG Bruiser  
                        //case 193:     // 1x Holo  
                        //case 194:     // 1x-2x Variable Holo  
                        //case 196:     // 3x HCOG Ranger  
                        //case 197:     // 6x Sniper  
                        //case 199:     // 4x-8x Variable Sniper  

                        //case 227:     // Standard Stock 1  
                        //case 228:     // Standard Stock 2  
                        case 229:     // Standard Stock 3  

                        //case 230:     // Sniper Stock 1  
                        //case 231:     // Sniper Stock 2  
                        //case 232:     // Sniper Stock 3  

                        //case 201:     // Barrel Stabilizer 1  
                        //case 202:     // Barrel Stabilizer 2  
                        case 203:     // Barrel Stabilizer 3  
                        case 204:     // Barrel Stabilizer 4  

                        //case 188:     // Thermite Grenade  
                        //case 189:     // Frag Grenade  
                        //case 190:     // Arc Star  

                        //case 212:     // Heavy Magazine 1  
                        //case 213:     // Heavy Magazine 2  
                        case 214:     // Heavy Magazine 3  
                        case 215:     // Heavy Magazine 4  

                        //case 216:     // Energy Magazine 1  
                        //case 217:     // Energy Magazine 2  
                        case 218:     // Energy Magazine 3  
                        case 219:     // Energy Magazine 4  

                        //case 208:     // Extended Light Mag  
                        //case 209:     // Extended Light Mag  
                        case 210:     // Extended Light Mag  
                        case 211:     // Extended Light Mag  

                        //case 159:     // Ultimate Accelerant  
                        //case 160:     // Phoenix Kit  
                        //case 161:     // Med Kit  
                        //case 162:     // Syringe  
                        case 163:     // Shield Battery  
                        //case 164:     // Shield Cell  

                        //case 220:     // Extended Sniper Mag  
                        //case 221:     // Extended Sniper Mag  
                        case 222:     // Extended Sniper Mag  
                        case 223:     // Extended Sniper Mag  

                        //case 224:     // Shotgun Bolt 1  
                        //case 225:     // Shotgun Bolt 2  
                        case 226:     // Shotgun Bolt 3  

                        //case 187:     // Throwing Knife  
                        case 233:     // Turbo Charger  

                        //case 205:     // Laser Sight 1  
                        //case 206:     // Laser Sight 2  
                        case 207:     // Laser Sight 3  

                        case 235:     // Skullpiercer Rifling  
                        case 238:     // Anvil Receiver  
                        case 239:     // Double Tap Trigger  
			
		    mem::WriteInt(ent_base + 0x02c0, 1363184265);

		    break;
		    }
		}
    }
};
