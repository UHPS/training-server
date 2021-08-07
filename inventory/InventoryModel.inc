#define WORLD_INVENTORY_MAX_ITEMS           200
#define WORLD_INVENTORY_SLOT_NAME           24
#define WORLD_INVENTORY_SLOT_DESCRIPTION    144
#define WORLD_INVENTORY_PER_PAGE            20
#define WORLD_INVENTORY_INDEX_ARRAY         1280

#define PLAYER_INVENTORY_SLOT_ITEMS         50
#define STREAMER_INVENTORY_ID               E_STREAMER_CUSTOM(708)

enum worldInventoryEnum
{
    slotName[WORLD_INVENTORY_SLOT_NAME],
    slotDescription[WORLD_INVENTORY_SLOT_DESCRIPTION],
    slotModel,
    slotQuantity,
    slotBlock,
    slotStatus
}

new worldInventory[MAX_WORLDS][WORLD_INVENTORY_MAX_ITEMS][worldInventoryEnum];

enum playerInventroyEnum
{
    itemId,
    itemQuantity
}

new playerInventory[MAX_PLAYERS][PLAYER_INVENTORY_SLOT_ITEMS][playerInventroyEnum];

function setPlayerSelectedPage(playerid, value)
{
    pData[playerid][pSeeList][99] = value;
}

function getPlayerSelectedPage(playerid)
{
    return pData[playerid][pSeeList][99];
}

function setPlayerSelectedItem(playerid, value)
{
    pData[playerid][pSeeList][98] = value;
}

function getPlayerSelectedItem(playerid)
{
    return pData[playerid][pSeeList][98];
}

function isValidSelectedItemModel(playerid)
{
    return isValidObjectModel( getSelectedItemData( getPlayerSelectedItem(playerid) ) );
}

function getSelectedItemModel(playerid)
{
    new world = GetPlayerVirtualWorld(playerid);

    return worldInventory[world][ playerInventory[playerid][world][ getPlayerSelectedItem(playerid) ] ][slotModel];
}
