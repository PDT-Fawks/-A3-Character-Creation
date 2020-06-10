#define IDC_HAT_COMBO 190000
#define IDC_UNIFORM_COMBO 190001
#define IDC_GLASSES_COMBO 190002

private _hatCombo = ((uiNamespace getVariable "PDT_clothingSelectGUI") displayCtrl IDC_HAT_COMBO);
private _uniformCombo = ((uiNamespace getVariable "PDT_clothingSelectGUI") displayCtrl IDC_UNIFORM_COMBO);
private _glassesCombo = ((uiNamespace getVariable "PDT_clothingSelectGUI") displayCtrl IDC_GLASSES_COMBO);

private _hats =
[
	["Black hat", "H_Cap_blk"],
	["Blue hat", "H_Cap_blu"],
	["Green hat", "H_Cap_grn"],
	["Red hat", "H_Cap_red"]

];

private _uniforms =
[
	["Blue shirt, khaki shorts", "U_C_Poloshirt_blue"],
	["Burgundy shirt, blue shorts", "U_C_Poloshirt_burgundy"],
	["White shirt, red shorts", "U_C_Poloshirt_redwhite"],
	["Salmon shirt, brown shorts", "U_C_Poloshirt_salmon"],
	["Striped shirt, white shorts", "U_C_Poloshirt_stripped"]
];

private _glasses =
[
	["Aviator glasses", "G_Aviator"],
	["Black glasses", "G_Shades_Black"],
	["Blue glasses", "G_Shades_Blue"],
	["Green glasses", "G_Shades_Green"],
	["Red glasses", "G_Shades_Red"]
];


//add the items to the dropdown menu
{
	_item = _hatCombo lbAdd format ["%1", (_x select 0)];
	_hatCombo lbSetData [_item, (_x select 1)];
} forEach _hats;

{
	_item = _uniformCombo lbAdd format ["%1", (_x select 0)];
	_uniformCombo lbSetData [_item, (_x select 1)];
} forEach _uniforms;

{
	_item = _glassesCombo lbAdd format ["%1", (_x select 0)];
	_glassesCombo lbSetData [_item, (_x select 1)];
} forEach _glasses;


//add LBSelChanged eventHandlers
_hatCombo ctrlAddEventHandler ["LBSelChanged",
	{
		params ["_control", "_selectedIndex"];
		player addHeadgear (_control lbData (lbCurSel _control));
	}
];

_uniformCombo ctrlAddEventHandler ["LBSelChanged",
	{
		params ["_control", "_selectedIndex"];
		player forceAddUniform (_control lbData (lbCurSel _control));
	}
];

_glassesCombo ctrlAddEventHandler ["LBSelChanged",
	{
		params ["_control", "_selectedIndex"];
		player addGoggles (_control lbData (lbCurSel _control));
	}
];
