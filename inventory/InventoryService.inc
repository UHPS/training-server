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

    setPlayerSelectedPage(playerid, page);

    return Dialog_Show(playerid, worldInventoryIndex, DIALOG_STYLE_TABLIST, " ", inventory, "Y", "X");
}

Dialog:worldInventoryIndex(playerid, response, listitem, inputtext[])
{
    if (!response) return true;

    setPlayerSelectedItem(playerid, getPlayerSelectedPage(playerid) * WORLD_INVENTORY_PER_PAGE + listitem);
    
    worldInventoryShowItem(playerid, getPlayerSelectedItem(playerid));
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

    format(str, sizeof(str), "Название:\t[ %s ]\n\
        Описание:\t[ %.24s ]\n\
        Модель:\t[ %d ]\n\
        Декремент:\t[ %d ]\n\
        Командный Блок:\t[ %d ]\n\
        Статус:\t[ %s ]\n\
         \t \n\
        Очистить\t",

        worldInventory[world][item][slotName],
        worldInventory[world][item][slotDescription],
        worldInventory[world][item][slotModel],
        worldInventory[world][item][slotQuantity],
        worldInventory[world][item][slotBlock],
        worldInventory[world][item][slotStatus] ? SWITCH_ON : SWITCH_OFF
    );

    return Dialog_Show(playerid, worldInventoryShowItem, DIALOG_STYLE_TABLIST, " ", str, "Y", "X");
}

Dialog:worldInventoryShowItem(playerid, response, listitem, inputtext[])
{
    if (!response) return worldInventoryIndex(playerid, getPlayerSelectedPage(playerid));

    switch (listitem)
    {
        case 0: worldInventorySetItemName(playerid);
        case 1: worldInventorySetDescription(playerid);
        // case 2: worldInventorySetModel(playerid);
        // case 3: worldInventorySetQuantity(playerid);
        // case 4: worldInentorySetBlock(playerid);
        // case 5: worldInventoryToggleStatus(playerid);
        case 5: worldInventoryDestroyItem(playerid);
        default: worldInventoryShowItem(playerid, getPlayerSelectedItem(playerid));
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
        worldInventory[world][ getPlayerSelectedItem(playerid) ][slotName],
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

        format(worldInventory[world][ getPlayerSelectedItem(playerid) ][slotName], WORLD_INVENTORY_SLOT_NAME, "%s", inputtext); 
    }

    return worldInventoryShowItem(playerid, getPlayerSelectedItem(playerid));
}

stock worldInventorySetDescription(playerid, error[] = "")
{
    new 
        world = GetPlayerVirtualWorld(playerid),
        str[1024];

    format(str, sizeof(str), HEX_WHITE"Укажите описание предмета от 1 до %d символов.\n\n%s\n\n"HEX_METRONIC_RED"%s", 
        WORLD_INVENTORY_SLOT_DESCRIPTION, 
        worldInventory[world][ getPlayerSelectedItem(playerid) ][slotDescription],
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

        format(worldInventory[world][ getPlayerSelectedItem(playerid) ][slotDescription], WORLD_INVENTORY_SLOT_DESCRIPTION, "%s", inputtext); 
    }

    return worldInventoryShowItem(playerid, getPlayerSelectedItem(playerid));
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
 * 
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