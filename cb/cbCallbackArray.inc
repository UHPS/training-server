/*
	При добавлении нового коллбека, необходимо внести новый #define
	А так же добавить описание в массив cmCallBack
*/

#define CB_AREA_ENTER		0
#define CB_AREA_EXIT		1
#define CB_AREA_GIVE_DMG	2
#define CB_AREA_TAKE_DMG	3
#define CB_AREA_SHOOT		4
#define CB_AREA_MURDER		5
#define CB_AREA_DEAD		6
#define CB_AREA_ENTER_VEH	7
#define CB_AREA_EXIT_VEH	8
#define CB_AREA_TRY_VEH		9
#define CB_AREA_ENTER_CP	10
#define CB_AREA_EXIT_CP		11
#define CB_AREA_ENTER_RCP	12
#define CB_AREA_EXIT_RCP	13
#define CB_AREA_SHOOT_OBJ	30
#define CB_AREA_DIALOG		31
#define CB_AREA_START_ENG	32
#define CB_AREA_STOP_ENG	33
#define CB_AREA_RP_DEATH	34
#define CB_AREA_LEAVE		35
#define CB_CLICK_MAP		36
#define CB_CLICK_PLAYER		37

new const cmCallBack[][] = {
	{"Вход"},
	{"Выход"},

	{"Нанесение урона"},
	{"Получение урона"},
	
	{"Выстрел"},
	{"Убийство"},
	{"Смерть"},
	
	{"Сесть в транспорт"},
	{"Выйти из транспорта"},
	{"Попытка сесть в транспорт"},
	
	{"Взять чекпоинт"},
	{"Выйти из чекпоинта"},
	
	{"Взять гоночный чекпоинт"},
	{"Выйти из гоночного чекпоинта"},
	
	{"Клавиша TAB"},
	{"Клавиша C"},
	{"Клавиша LCTRL / LMB"},
	{"Клавиша SPACE"},
	{"Клавиша ENTER"},
	{"Клавиша LSHIFT"},
	{"Клавиша RMB"},
	{"Клавиша NUM1 / MMB"},
	{"Клавиша LALT"},
	{"Клавиша NUM8"},
	{"Клавиша NUM2"},
	{"Клавиша NUM4"},
	{"Клавиша NUM6"},
	{"Клавиша Y"},
	{"Клавиша N"},
	{"Клавиша H"},
	{"Выстрелить по объекту"},
	{"Ввод диалога"},
	{"Завести двигатель"},
	{"Заглушить двигатель"},
	{"РП смерть"},
	{"Выход из мира"},
	{"Метка на карте"},
	{"Выбор игрока в TAB"}
};


/*
Вставить в начало мода:

new Text:TextdrawBlackScreen;

TextdrawBlackScreen = TextDrawCreate(-187.000000, -4.000000, "5");
TextDrawAlignment(TextdrawBlackScreen, 2);
TextDrawBackgroundColor(TextdrawBlackScreen, 255);
TextDrawFont(TextdrawBlackScreen, 5);
TextDrawLetterSize(TextdrawBlackScreen, 0.500000, 1.000000);
TextDrawColor(TextdrawBlackScreen, -1);
TextDrawSetOutline(TextdrawBlackScreen, 0);
TextDrawSetProportional(TextdrawBlackScreen, 0);
TextDrawSetShadow(TextdrawBlackScreen, 1);
TextDrawSetPreviewModel(TextdrawBlackScreen, 5);
TextDrawSetPreviewRot(TextdrawBlackScreen, -16.000000, 0.000000, -55.000000, 55555.000000);
TextDrawSetSelectable(TextdrawBlackScreen, 0);




CMD:black(playerid,params[])
{
	new retstr0[256];
	if(sscanf(params,"s",retstr0)) return SCM(playerid,0x88888888,"[SYNTAX]:{FFFFFF} /black ON/OFF.");
	if(strfind(params,"on",true) != -1)
	{
	    TextDrawShowForPlayer(playerid,TextdrawBlackScreen);
	    SCM(playerid,COL_SER,"[SERVER]: {FFFFFF}Режим черного экрана активирован.");
	}
	if(strfind(params,"off",true) != -1)
	{
		TextDrawHideForPlayer(playerid,TextdrawBlackScreen);
		SCM(playerid,COL_SER,"[SERVER]: {FFFFFF}Режим черного экрана деактивирован..");
		
	}
	return 1;
}

\*
