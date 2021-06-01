/*
	Тут хранится тело кода всех коллбеков.
*/


function OnPlayerCBKeyPress(playerid, newkeys)
{
	if(!IsPlayerInAnyDynamicArea(playerid, false))
		return false;
	
	if(newkeys & KEY_ACTION)
		cbPressKey(playerid, 14);	
		
	if(newkeys & KEY_CROUCH)
		cbPressKey(playerid, 15);

	if(newkeys & KEY_FIRE)
		cbPressKey(playerid, 16);	
		
	if(newkeys & KEY_SPRINT)
		cbPressKey(playerid, 17);	
		
	if(newkeys & KEY_SECONDARY_ATTACK)
		cbPressKey(playerid, 18);

	if(newkeys & KEY_JUMP)
		cbPressKey(playerid, 19);	

	if(newkeys & KEY_AIM)
		cbPressKey(playerid, 20);	
	
	if(newkeys & KEY_LOOK_BEHIND)
		cbPressKey(playerid, 21);	
		
	if(newkeys & KEY_WALK)
		cbPressKey(playerid, 22);

	if(newkeys & KEY_ANALOG_UP)
		cbPressKey(playerid, 23);	
	
	if(newkeys & KEY_ANALOG_DOWN)
		cbPressKey(playerid, 24);	
	
	if(newkeys & KEY_ANALOG_LEFT)
		cbPressKey(playerid, 25);	
	
	if(newkeys & KEY_ANALOG_RIGHT)
		cbPressKey(playerid, 26);	
	
	if(newkeys & KEY_YES)
		cbPressKey(playerid, 27);

	if(newkeys & KEY_NO)
		cbPressKey(playerid, 28);

	if(newkeys & KEY_CTRL_BACK)
		cbPressKey(playerid, 29);
	

	return true;
}

stock cbPressKey(playerid, newkeys)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = newkeys;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, newkeys);
}


function OnPlayerLeaveDynArea(playerid, areaid)
{
	new 
		blockid = Streamer_GetIntData(STREAMER_TYPE_AREA , areaid, E_STREAMER_EXTRA_ID),
		world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	if(!IsWorldAccess(world))
		return false;
		
	if(blockid >= 1000)
		return OnSBlockHandler(playerid, blockid, world, CB_AREA_EXIT);
	
	if(blockid < 0 || blockid > VW[world][wMaxCB])
		return false;
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = blockid;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	OnCmBlockHandler(playerid, blockid, world, CB_AREA_EXIT);
	return false;
}

function CB_OnPlayerLeave(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = false;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_LEAVE);
	return true;
}

function OnPlayerEnterDynArea(playerid, areaid)
{
	new 
		blockid = Streamer_GetIntData(STREAMER_TYPE_AREA , areaid, E_STREAMER_EXTRA_ID),
		world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	if(!IsWorldAccess(world))
		return false;
		
	if(blockid >= 1000)
		return OnSBlockHandler(playerid, blockid, world, CB_AREA_ENTER);
	
	if(blockid < 0 || blockid > VW[world][wMaxCB])
		return false;
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = blockid;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	OnCmBlockHandler(playerid, blockid, world, CB_AREA_ENTER);
	return false;
}

function OnPlayerCBShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = weaponid;
	pData[playerid][pRetVal][2] = hittype;
	pData[playerid][pRetVal][3] = hitid;
	pData[playerid][pRetVal][4] = floatround(fX);
	pData[playerid][pRetVal][5] = floatround(fY);
	pData[playerid][pRetVal][6] = floatround(fZ);
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	GetWeaponName(weaponid, pData[playerid][pRetStr][0], 24);
	switch(hittype)
	{
		case 0: format(pData[playerid][pRetStr][24], 24, "N/A");
		case 1: format(pData[playerid][pRetStr][24], 24, "Игрок");
		case 2: format(pData[playerid][pRetStr][24], 24, "Транспорт");
		case 3: format(pData[playerid][pRetStr][24], 24, "Объект");
		case 4: format(pData[playerid][pRetStr][24], 24, "Объект");
	}
	
	findDynamicArea(playerid, CB_AREA_SHOOT);
	return true;
}

function CB_OnPlayerMurder(playerid, murderid, reason)
{
	if(playerid < 0 || playerid > MAX_PLAYERS)
		return true;

	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = murderid;
	pData[playerid][pRetVal][2] = reason;
	pData[playerid][pRetVal][3] = pData[murderid][pTeam] + 1;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	GetPlayerName(murderid, pData[playerid][pRetStr][0], 24);
	GetWeaponName(reason, pData[playerid][pRetStr][24], 24);
	
	findDynamicArea(playerid, CB_AREA_MURDER);
	return true;
}

function CB_OnPlayerDead(playerid, killerid, reason)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = killerid;
	pData[playerid][pRetVal][2] = reason;
	
	if(killerid > 0 && killerid < MAX_PLAYERS)
		pData[playerid][pRetVal][3] = pData[killerid][pTeam] + 1;
	else
		pData[playerid][pRetVal][3] = false;
		
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	GetPlayerName(killerid, pData[playerid][pRetStr][0], 24);
	GetWeaponName(reason, pData[playerid][pRetStr][24], 24);
	
	findDynamicArea(playerid, CB_AREA_DEAD);
	return true;
}

function CB_GiveDamage(playerid, damagedid, Float: amount, weaponid, bodypart)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = damagedid;
	pData[playerid][pRetVal][2] = floatround(amount);
	pData[playerid][pRetVal][3] = weaponid;
	pData[playerid][pRetVal][4] = bodypart;
	
	if(damagedid > 0 && damagedid < MAX_PLAYERS)
		pData[playerid][pRetVal][5] = pData[damagedid][pTeam] + 1;
	else
		pData[playerid][pRetVal][5] = false;
	
	pData[playerid][pRetVal][6] = floatround(GetPlayerDistanceFromPlayer(playerid, damagedid));
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	GetPlayerName(damagedid, pData[playerid][pRetStr][0], 24);
	GetWeaponName(weaponid, pData[playerid][pRetStr][24], 24);
	
	switch(bodypart)
	{
		case 3: format(pData[playerid][pRetStr][48], 24, "Торс");
		case 4: format(pData[playerid][pRetStr][48], 24, "Пах");
		case 5: format(pData[playerid][pRetStr][48], 24, "Левая рука");
		case 6: format(pData[playerid][pRetStr][48], 24, "Правая рука");
		case 7: format(pData[playerid][pRetStr][48], 24, "Левая нога");
		case 8: format(pData[playerid][pRetStr][48], 24, "Правая нога");
		case 9: format(pData[playerid][pRetStr][48], 24, "Голова");
	}
	
	findDynamicArea(playerid, CB_AREA_GIVE_DMG);
	return true;
}

function CB_TakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = issuerid;
	pData[playerid][pRetVal][2] = floatround(amount);
	pData[playerid][pRetVal][3] = weaponid;
	pData[playerid][pRetVal][4] = bodypart;
	
	if(issuerid > 0 && issuerid < MAX_PLAYERS)
		pData[playerid][pRetVal][5] = pData[issuerid][pTeam] + 1;
	else
		pData[playerid][pRetVal][5] = false;
		
	pData[playerid][pRetVal][6] = floatround(GetPlayerDistanceFromPlayer(playerid, issuerid));
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	GetPlayerName(issuerid, pData[playerid][pRetStr][0], 24);
	GetWeaponName(weaponid, pData[playerid][pRetStr][24], 24);
	
	switch(bodypart)
	{
		case 3: format(pData[playerid][pRetStr][48], 24, "Торс");
		case 4: format(pData[playerid][pRetStr][48], 24, "Пах");
		case 5: format(pData[playerid][pRetStr][48], 24, "Левая рука");
		case 6: format(pData[playerid][pRetStr][48], 24, "Правая рука");
		case 7: format(pData[playerid][pRetStr][48], 24, "Левая нога");
		case 8: format(pData[playerid][pRetStr][48], 24, "Правая нога");
		case 9: format(pData[playerid][pRetStr][48], 24, "Голова");
	}
	
	findDynamicArea(playerid, CB_AREA_TAKE_DMG);
	return true;
}

function CB_EnterVeh(playerid, newstate, vehicleid, vehicleModel, vehicleOwner, Float: vX, Float: vY, Float: vZ)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = newstate;
	pData[playerid][pRetVal][2] = vehicleid;
	pData[playerid][pRetVal][3] = vehicleModel;
	pData[playerid][pRetVal][4] = vehicleOwner;
	pData[playerid][pRetVal][5] = floatround(vX);
	pData[playerid][pRetVal][6] = floatround(vY);
	pData[playerid][pRetVal][7] = floatround(vZ);
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;

	ReturnVehicleNameEx(vehicleModel, pData[playerid][pRetStr][0], 24);
	findDynamicArea(playerid, CB_AREA_ENTER_VEH);
	return true;
}

function CB_LeaveVeh(playerid, newstate, vehicleid, vehicleModel, vehicleOwner, Float: vX, Float: vY, Float: vZ)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = newstate;
	pData[playerid][pRetVal][2] = vehicleid;
	pData[playerid][pRetVal][3] = vehicleModel;
	pData[playerid][pRetVal][4] = vehicleOwner;
	pData[playerid][pRetVal][5] = floatround(vX);
	pData[playerid][pRetVal][6] = floatround(vY);
	pData[playerid][pRetVal][7] = floatround(vZ);
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;

	ReturnVehicleNameEx(vehicleModel, pData[playerid][pRetStr][0], 24);
	findDynamicArea(playerid, CB_AREA_EXIT_VEH);
	return true;
}

function CB_TryVeh(playerid, ispassenger, vehicleid, vehicleModel, vehicleOwner, Float: vX, Float: vY, Float: vZ)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = ispassenger;
	pData[playerid][pRetVal][2] = vehicleid;
	pData[playerid][pRetVal][3] = vehicleModel;
	pData[playerid][pRetVal][4] = vehicleOwner;
	pData[playerid][pRetVal][5] = floatround(vX);
	pData[playerid][pRetVal][6] = floatround(vY);
	pData[playerid][pRetVal][7] = floatround(vZ);
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	ReturnVehicleNameEx(vehicleModel, pData[playerid][pRetStr][0], 24);
	findDynamicArea(playerid, CB_AREA_TRY_VEH);
	return true;
}

function CB_EnterCP(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = false;
	pData[playerid][pRetVal][1] = false;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_ENTER_CP);
	return true;
}

function CB_LeaveCP(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = false;
	pData[playerid][pRetVal][1] = false;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_EXIT_CP);
	return true;
}

function CB_EnterRCP(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		new 
			Float:x,
			Float:y,
			Float:z,
			vehicleid = GetPlayerVehicleID(playerid);
		
		GetVehiclePos(vehicleid, x, y, z);
		
		pData[playerid][pRetVal][1] = vData[vehicleid][vLocalID];
		pData[playerid][pRetVal][2] = GetVehicleModel(vehicleid);
		pData[playerid][pRetVal][3] = vData[vehicleid][vOwner];
		pData[playerid][pRetVal][4] = floatround(x);
		pData[playerid][pRetVal][5] = floatround(y);
		pData[playerid][pRetVal][6] = floatround(z);
		pData[playerid][pRetVal][7] = floatround(Vehicle_Speed(vehicleid));
		pData[playerid][pRetVal][8] = false;
		pData[playerid][pRetVal][9] = false;
		
		ReturnVehicleNameEx(GetVehicleModel(vehicleid), pData[playerid][pRetStr][0], 24);
	}
	else
	{
		pData[playerid][pRetVal][1] = false;
		pData[playerid][pRetVal][2] = false;
		pData[playerid][pRetVal][3] = false;
		pData[playerid][pRetVal][4] = false;
		pData[playerid][pRetVal][5] = false;
		pData[playerid][pRetVal][6] = false;
		pData[playerid][pRetVal][7] = false;
		pData[playerid][pRetVal][8] = false;
		pData[playerid][pRetVal][9] = false;
	}
	
	findDynamicArea(playerid, CB_AREA_ENTER_RCP);
	return true;
}

function CB_LeaveRCP(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetStr] = EOS;	
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		new 
			Float:x,
			Float:y,
			Float:z,
			vehicleid = GetPlayerVehicleID(playerid);
		
		GetVehiclePos(vehicleid, x, y, z);
		
		pData[playerid][pRetVal][1] = vData[vehicleid][vLocalID];
		pData[playerid][pRetVal][2] = GetVehicleModel(vehicleid);
		pData[playerid][pRetVal][3] = vData[vehicleid][vOwner];
		pData[playerid][pRetVal][4] = floatround(x);
		pData[playerid][pRetVal][5] = floatround(y);
		pData[playerid][pRetVal][6] = floatround(z);
		pData[playerid][pRetVal][7] = floatround(Vehicle_Speed(vehicleid));
		pData[playerid][pRetVal][8] = false;
		pData[playerid][pRetVal][9] = false;
		
		ReturnVehicleNameEx(GetVehicleModel(vehicleid), pData[playerid][pRetStr][0], 24);
	}
	else
	{
		pData[playerid][pRetVal][1] = false;
		pData[playerid][pRetVal][2] = false;
		pData[playerid][pRetVal][3] = false;
		pData[playerid][pRetVal][4] = false;
		pData[playerid][pRetVal][5] = false;
		pData[playerid][pRetVal][6] = false;
		pData[playerid][pRetVal][7] = false;
		pData[playerid][pRetVal][8] = false;
		pData[playerid][pRetVal][9] = false;
	}
	
	findDynamicArea(playerid, CB_AREA_EXIT_RCP);
	return true;
}

function CB_ShootObj(playerid, weaponid, objectid, Float:x, Float:y, Float:z)
{
	new world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = weaponid;
	//pData[playerid][pRetVal][2] = false;
	

	pData[playerid][pRetVal][2] = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_EXTRA_ID);
	
	pData[playerid][pRetVal][3] = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_MODEL_ID);	
	pData[playerid][pRetVal][4] = floatround(x);
	pData[playerid][pRetVal][5] = floatround(y);
	pData[playerid][pRetVal][6] = floatround(z);
	
	new Float:objectPos[3];
	GetDynamicObjectPos(objectid, objectPos[0], objectPos[1], objectPos[2]);
	 
	pData[playerid][pRetVal][7] = floatround(objectPos[0]);
	pData[playerid][pRetVal][8] = floatround(objectPos[1]);
	pData[playerid][pRetVal][9] = floatround(objectPos[2]);
	
	GetWeaponName(weaponid, pData[playerid][pRetStr][0], 24);
	
	findDynamicArea(playerid, CB_AREA_SHOOT_OBJ);
	return true;
}

function CB_ClickMap(playerid, Float:x, Float:y, Float:z)
{
	new world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = floatround(GetPlayerDistanceFromPoint(playerid, x, y, z));
	pData[playerid][pRetVal][2] = floatround(x);
	pData[playerid][pRetVal][3] = floatround(y);
	pData[playerid][pRetVal][4] = floatround(z);
	pData[playerid][pRetVal][5] = Get2DZoneId(x, y);
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;

	Get2DZone(x, y, pData[playerid][pRetStr][0], MAX_ZONE_NAME);
	
	findDynamicArea(playerid, CB_CLICK_MAP);
	return true;
}

function CB_ClickPlayer(playerid, clickedplayerid)
{
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = clickedplayerid;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	return true;
}


function CB_StartEngine(playerid, vehicleid)
{
	new world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	new Float:vehicleHealth;
	GetVehicleHealth(vehicleid, vehicleHealth);
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = vehicleid;
	pData[playerid][pRetVal][2] = floatround(vehicleHealth, floatround_round);
	pData[playerid][pRetVal][3] = vData[vehicleid][vOwner];
	pData[playerid][pRetVal][4] = vData[vehicleid][vTeam];
	pData[playerid][pRetVal][5] = vData[vehicleid][vGodMode];
	pData[playerid][pRetVal][6] = vData[vehicleid][vNitroMode];
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_START_ENG);
	return true;
}

function CB_StopEngine(playerid, vehicleid)
{
	new world = GetPlayerVirtualWorld(playerid);
	
	if(!IsValidWorld(world))
		return false;
	
	new Float:vehicleHealth;
	GetVehicleHealth(vehicleid, vehicleHealth);
	
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = vehicleid;
	pData[playerid][pRetVal][2] = floatround(vehicleHealth, floatround_round);
	pData[playerid][pRetVal][3] = vData[vehicleid][vOwner];
	pData[playerid][pRetVal][4] = vData[vehicleid][vTeam];
	pData[playerid][pRetVal][5] = vData[vehicleid][vGodMode];
	pData[playerid][pRetVal][6] = vData[vehicleid][vNitroMode];
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_STOP_ENG);
	return true;
}

function CB_Reviwe(playerid)
{
	Streamer_Update(playerid, STREAMER_TYPE_AREA);
	pData[playerid][pRetStr] = EOS;	
	pData[playerid][pRetVal][0] = playerid;
	pData[playerid][pRetVal][1] = false;
	pData[playerid][pRetVal][2] = false;
	pData[playerid][pRetVal][3] = false;
	pData[playerid][pRetVal][4] = false;
	pData[playerid][pRetVal][5] = false;
	pData[playerid][pRetVal][6] = false;
	pData[playerid][pRetVal][7] = false;
	pData[playerid][pRetVal][8] = false;
	pData[playerid][pRetVal][9] = false;
	
	findDynamicArea(playerid, CB_AREA_RP_DEATH);
	return true;
}
