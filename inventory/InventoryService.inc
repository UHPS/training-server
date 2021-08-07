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
        // case 2: worldInventorySetModel(playerid);  Данной функции нет. Надо создать и описать. Пример можно взять из worldInventorySetItemName
        // case 3: worldInventorySetQuantity(playerid); Данной функции нет. Надо создать и описать. Пример можно взять из worldInventorySetItemName
        // case 4: worldInentorySetBlock(playerid); Данной функции нет. Надо создать и описать. Пример можно взять из worldInventorySetItemName
        // case 5: worldInventoryToggleStatus(playerid); Данной функции нет. Надо создать и описать. Пример можно взять из worldInventorySetItemName
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
    // Просто очищает массив = EOS
    return true;
}

/**
 * Вернуть список всех предметов в инвентаре игрока
 *
 */
stock playerInvitoryIndex(playerid, page=0)
{
    // Достаточно базовой информации. Название предмета / количество. Кол. выводить если декремент у мира не != 0
    // Так же нужна проверка на статус. Если статус 0. То предмет как-бы есть в инвентаре, но не отображает его. И считает слот пустым.
    // Т.е. предмет как-бы под удаление, но пока ещё лежит на месте. 
    return true;
}

/**
 * Показать подробную информацию о предмете игрока
 *
 */
stock playerInvitoryShowItem(playerid)
{
    // Название описание и 2 кнопки Y / X
    return true;
}

/**
 * Использование предмета игроком
 *
 */
stock playerInvitoryUseItem(playerid)
{
    // Пока ещё точно не придумал. Но думаю пусть будет обычный вызов КБ. Может что-то лучше придумаем ещё.
    return true;
}

/**
 * Игрок выкидывает предмет
 *
 */
stock playerInvitoryDropItem(playerid)
{
    // Предмет должен быть выкинут на землю. Это лучше не трогайте вообще. Я сам опишу логику. Я собираюсь работать с массивами стримера. 
    new
        objectid,
        world = GetPlayerVirtualWorld(playerid),
        Float: x,
        Float: y,
        Float: z,
        Float: rz;

    if (!isValidWorld(world)) return true;

    if (!isValidSelectedItemModel(playerid)) return SendServerMessage(playerid, "Невозможно выкинуть данный предмет.");

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, rz);

    x += 2 * floatsin(-rz, degrees);
	y += 2 * floatcos(-rz, degrees);

    objectid = CreateDynamicObject(getSelectedItemModel(playerid), x, y, z, 0.0, 0.0, 0.0, world, GetPlayerInterior(playerid));
    Streamer_SetIntData(STREAMER_TYPE_OBJECT, objectid, STREAMER_INVENTORY_ID, getPlayerSelectedItem(playerid));

    return true;
}

/**
 * Игрок уничтожает предмет
 *
 */
stock playerInvitoryDestroyItem(playerid)
{
    // Просто очищает слот. Кстати по возможности надо добавить в настройку "ON/OFF" удаляемый предмет или нет. Ибо мб хост не хочет чтобы его удаляли.
    return true;
}


stock playerInventoryPickupItem(playerid)
{
    new 
        objectid = getInventoryNearItem(playerid),
        model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, STREAMER_INVENTORY_ID);

    // TODO: Добавить проверку на валидность предмета. Его может не быть
    
    DestroyDynamicObject(objectid);

    // TODO: А сюда доабвить выдачу предмета
}

function getInventoryNearItem(playerid)
{
    new
        Float: x,
        Float: y,
        Float: z,
        world = GetPlayerVirtualWorld(playerid),
        objectid,
        Float: nearlyDistance,
        items[100];

    GetPlayerPos(playerid, x, y, z);

    Streamer_GetNearbyItems(x, y, z, STREAMER_TYPE_OBJECT, items[], sizeof(items), 5.0, world);

    objectid = items[0];
    Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, objectid, nearlyDistance, 2)

    for (new i = 1; i < sizeof(items); i++)
    {
        new Float: distance;
        if (!Streamer_GetDistanceToItem(x, y, z, STREAMER_TYPE_OBJECT, items[i], distance, 2)) continue;

        if (nearlyDistance < distance) continue;

        objectid = items[i];
        nearlyDistance = distance;
    }

    return objectid;
}