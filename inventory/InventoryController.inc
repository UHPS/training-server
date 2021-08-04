#include "../ls-gov/inventory/InventoryModel"
#include "../ls-gov/inventory/InventoryService"


CMD:invmenu(playerid, params[])
{
    worldInventoryIndex(playerid, GetPlayerVirtualWorld(playerid));
    return true;
}

CMD:inv(playerid, params[])
{
    playerInvitoryIndex(playerid);
    return true;
}

CMD:use(playerid, params[])
{
    return true;
}

CMD:pickup(playerid, params[])
{
    return true;
}

CMD:drop(playerid, params[])
{
    return true;
}