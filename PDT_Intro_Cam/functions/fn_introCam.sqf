//params ["_spawnType"];
private ["_spawnVehicle", "_introCam", "_introCamXOffset", "_introCamYOffset", "_introZoom"];

//prepare the intro vehicle
_spawnVehicle = createVehicle ["C_Boat_Civil_01_F", [0,0,0]];
_playerPos = getMarkerPos "marker_0";
createVehicleCrew _spawnVehicle;
_spawnVehicle doMove [5571.44, 1613.760, 0];
_spawnVehicle setPos [-0.003,18999.99,0];
_introCamXOffset = (getPos (_spawnVehicle) select 0);
_introCamYOffset = (getPos (_spawnVehicle) select 1) + 7;

//setup intro text
private _duration = 10; //how long you can see the text (value * 10)
[ "Altis", format ["%1", date select 0], mapGridPosition player ] spawn BIS_fnc_infoText;
titleText ["<t size='4' shadow='0'>Welcome to YourServerName</t><br /><t size='3' shadow='0'>YourShortMessage</t>", "BLACK IN", _duration, true, true];

//prepare the intro cam
_introCam = "camera" camCreate [_introCamXOffset, _introCamYOffset, (getPos (_spawnVehicle) select 2) + 3];
_introCam camSetTarget (_spawnVehicle);
_introCam cameraEffect ["internal", "back"];
_introCam camCommit 5;

//intro cam zoom to player
_introCamSpawn = [_introCam, _duration, _spawnVehicle, _playerPos] spawn{
	params ["_introCam", "_duration", "_spawnVehicle", "_playerPos"];
	_duration = 2;
	uiSleep 10;
	_introCam camSetTarget _playerPos;
	_introCam camCommit 5;
	_introCam camSetPos _playerPos;
	_introCam camCommit 1000;
	uiSleep 2;
	player setDir (_introCam getRelDir player);
	createDialog "PDT_clothingSelectGUI";
	{
		_x ctrlSetFade 1;
		_x ctrlCommit 0;
		_x ctrlSetFade 0;
		_x ctrlCommit 3;
	}forEach allControls (uiNamespace getVariable "PDT_clothingSelectGUI");
	player allowDamage  false;
	player enableSimulation false;
	while {!(isNull (uiNamespace getVariable "PDT_clothingSelectGUI"))} do
	{
		player setPos [(getPos (_introCam) select 0) + 1, (getPos (_introCam) select 1) - 2.5, (getPos (_introCam) select 2) - 0.98];
		player setDir (getDir _introCam - 180);
	};
	titleText ["", "BLACK IN", _duration, true, true];
	_introCam cameraEffect ["terminate", "back"];
	camDestroy _introCam;
	deleteVehicle _spawnVehicle;
	createDialog "PDT_spawnMenuGUI";
	{
		_x ctrlSetFade 1;
		_x ctrlCommit 0;
		_x ctrlSetFade 0;
		_x ctrlCommit 3;
	}forEach allControls (uiNamespace getVariable "PDT_spawnMenuGUI");
	uiSleep 2;

};
