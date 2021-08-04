/**
 * Показать список всех существующих предметров в мире
 * 
 */
stock worldInventoryIndex(playerid, world, page=0)
{
    new inventory[WORLD_INVENTORY_INDEX_ARRAY];

    for (new i = page * WORLD_INVENTORY_PER_PAGE; i < page * WORLD_INVENTORY_PER_PAGE + WORLD_INVENTORY_PER_PAGE; i++)
    {
        if (i > WORLD_INVENTORY_MAX_ITEMS) break;
        
        format(inventory, sizeof(inventory), "%s%d.\t%s\n", inventory, i + 1, worldInventory[world][i][slotName]);
    }

    setPlayerPage(playerid, page);

    return Dialog_Show(playerid, worldInventoryIndex, DIALOG_STYLE_TABLIST, " ", inventory, "Y", "X");
}

Dialog:worldInventoryIndex(playerid, response, listitem, inputtext[])
{
    if (!response) return true;

    setPlayerItem(playerid, getPlayerPage(playerid) * WORLD_INVENTORY_PER_PAGE + listitem);
    
    worldInventoryShowItem(playerid, getPlayerItem(playerid));
    return true;
}

/**
 * Показать подробную информацию об предмете
 * 
 */
stock worldInventoryShowItem(playerid, item)
{
    if (item < 0 || item > WORLD_INVENTORY_MAX_ITEMS) return false;

    new 
        world = GetPlayerVirtualWorld(playerid),
        str[256];

    format(str, sizeof(str), "Название:\t[ %s ]\nОписание:\t[ %.24s ]\nМодель:\t[ %d ]\nДекремент:\t[ %d ]\nСтатус:\t[ %s ]\n \t \nОчистить\t", 
        worldInventory[world][item][slotName],
        worldInventory[world][item][slotDescription],
        worldInventory[world][item][slotModel],
        worldInventory[world][item][slotQuantity],
        worldInventory[world][item][slotStatus] ? SWITCH_ON : SWITCH_OFF
    );

    return Dialog_Show(playerid, worldInventoryShowItem, DIALOG_STYLE_TABLIST, " ", str, "Y", "X");
}

Dialog:worldInventoryShowItem(playerid, response, listitem, inputtext[])
{
    if (!response) return worldInventoryIndex(playerid, getPlayerPage(playerid));

    switch (listitem)
    {
        case 0: worldInventorySetItemName(playerid);
        case 1: worldInventorySetDescription(playerid);
        // case 2: worldInventorySetModel(playerid);
        // case 3: worldInventorySetQuantity(playerid);
        // case 4: worldInventoryToggleStatus(playerid);
        case 5: worldInventoryDestroyItem(playerid);
        default: worldInventoryShowItem(playerid, getPlayerItem(playerid));
    }

    return true;
}

stock worldInventorySetItemName(playerid, error[] = "")
{
    new 
        world = GetPlayerVirtualWorld(playerid),
        str[256];

    format(str, sizeof(str), HEX_WHITE"Укажите отображаемое название предмета от 1 до %d символов.\n\n%s\n\n"HEX_METRONIC_RED"%s", 
        WORLD_INVENTORY_SLOT_NAME, 
        worldInventory[world][ getPlayerItem(playerid) ][slotName],
        error
    );

    return Dialog_Show(playerid, worldInventorySetName, DIALOG_STYLE_INPUT, " ", str, "Y", "X");
}

Dialog:worldInventorySetName(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new world = GetPlayerVirtualWorld(playerid);

        if (isnull(inputtext) || strlen(inputtext) > WORLD_INVENTORY_SLOT_NAME)
        {
            return worldInventorySetItemName(playerid, "* Неверно указана длина имени!");
        }

        format(worldInventory[world][ getPlayerItem(playerid) ][slotName], WORLD_INVENTORY_SLOT_NAME, "%s", inputtext); 
    }

    return worldInventoryShowItem(playerid, getPlayerItem(playerid));
}

stock worldInventorySetDescription(playerid, error[] = "")
{
    new 
        world = GetPlayerVirtualWorld(playerid),
        str[1024];

    format(str, sizeof(str), HEX_WHITE"Укажите описание предмета от 1 до %d символов.\n\n%s\n\n"HEX_METRONIC_RED"%s", 
        WORLD_INVENTORY_SLOT_DESCRIPTION, 
        worldInventory[world][ getPlayerItem(playerid) ][slotDescription],
        error
    );

    return Dialog_Show(playerid, worldInventorySetDesc, DIALOG_STYLE_INPUT, " ", str, "Y", "X");
}

Dialog:worldInventorySetDesc(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new world = GetPlayerVirtualWorld(playerid);

        if (isnull(inputtext) || strlen(inputtext) > WORLD_INVENTORY_SLOT_DESCRIPTION)
        {
            return worldInventorySetDescription(playerid, "* Неверно указана длина названия!");
        }

        format(worldInventory[world][ getPlayerItem(playerid) ][slotDescription], WORLD_INVENTORY_SLOT_DESCRIPTION, "%s", inputtext); 
    }

    return worldInventoryShowItem(playerid, getPlayerItem(playerid));
}

/**
 * Уничтожение и очистка массива предмета
 * 
 */
stock worldInventoryDestroyItem(playerid)
{
    return true;
}

/**
 * Вернуть список всех предметов в инвентаре игрока
 * 
 */
stock playerInvitoryIndex(playerid, page=0)
{
    return true;
}

/**
 * Показать подробную информацию о предмете игрока
 * 
 */
stock playerInvitoryShowItem(playerid)
{
    return true;
}

/**
 * Использование предмета игроком
 *
 */
stock playerInvitoryUseItem(playerid)
{
    return true;
}

/**
 * Игрок выкидывает предмет
 * data[] - должен хранить в себе предмет и кол.
 */
stock playerInvitoryDropItem(playerid)
{
    return true;
}

/**
 * Игрок уничтожает предмет
 *
 */
stock playerInvitoryDestroyItem(playerid)
{
    return true;
}