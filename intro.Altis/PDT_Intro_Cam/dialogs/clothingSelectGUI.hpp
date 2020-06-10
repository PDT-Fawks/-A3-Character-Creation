#define ST_CENTER         0x02
#define IDC_HAT_COMBO 190000
#define IDC_UNIFORM_COMBO 190001
#define IDC_GLASSES_COMBO 190002
#define IDD_CLOTHINGSELECTGUI 190003
/*
    Author: PDT

    File: clothingSelectGUI.hpp
*/

class PDT_clothingSelectGUI {
    idd = IDD_CLOTHINGSELECTGUI;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "PDT_clothingSelectGUI";
    onLoad = "uiNamespace setVariable ['PDT_clothingSelectGUI', _this select 0]; [] call PDT_fnc_clothingLbAdd";
    objects[] = {};

    class controlsBackground {

		class PDT_RscText_TitleBackground: life_RscText
		{
            idc = -1;
            shadow = 0;
            type = 0;
            style = 0;
            sizeEx = 0.023;
            text = "";
            font = "PuristaMedium";
            colorBackground[] = {1, 1, 1, 1.0};
            colorText[] = {};
            x = 0.0 * safezoneW + safezoneX;
            y = 0.125 * safezoneH + safezoneY;
    		h = 0.035 * safezoneH;
    		w = 1 * safezoneW;
            tooltipColorText[] = {1,1,1,1};
            tooltipColorBox[] = {1,1,1,1};
            tooltipColorShade[] = {0,0,0,0.65};
		};

		class PDT_RscText_TitleText: Life_RscText
		{
            idc = -1;
            x = 0.015 * safezoneW + safezoneX;
            y = 0.120 * safezoneH + safezoneY;
    		h = 0.037 * safezoneH;
    		w = 0.3 * safezoneW;
			shadow = 0;
			colorShadow[] = {0, 0, 0, 0.5};
			font = "PuristaMedium";
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2)";
			text = "Player Customization";
			colorText[] = {0, 0, 0, 1.0};
			colorBackground[] = {0, 0, 0, 0};
			linespacing = 1;
			tooltipColorText[] = {1,1,1,1};
			tooltipColorBox[] = {1,1,1,1};
			tooltipColorShade[] = {0,0,0,0.65};
		};

        class PDT_RscButton_Accept: Life_RscButtonMenu
        {
            idc = -1;
            shadow = 0;
            x = 0.8 * safezoneW + safezoneX;
            y = 0.84 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {0,0,0,0.8};
            colorBackgroundFocused[] = {1,1,1,1};
            colorBackground2[] = {0.75,0.75,0.75,1};
            color[] = {1,1,1,1};
            colorFocused[] = {0,0,0,1};
            colorText[] = {1,1,1,1};
            size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
            sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
            text = "Accept";
            action = "closeDialog 1;";
            class Attributes
            {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
        };
    };

    class controls{
        class PDT_RscCombo_Hat: Life_RscCombo
        {
            idc = IDC_HAT_COMBO;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.25 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class PDT_RscCombo_Uniform: Life_RscCombo
        {
            idc = IDC_UNIFORM_COMBO;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.40 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class PDT_RscCombo_Glasses: Life_RscCombo
        {
            idc = IDC_GLASSES_COMBO;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.55 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.03 * safezoneH;
        };

		class PDT_RscText_HatText: Life_RscText
		{
            idc = -1;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.22 * safezoneH + safezoneY;
    		h = 0.037 * safezoneH;
    		w = 0.3 * safezoneW;
			shadow = 1;
			colorShadow[] = {0, 0, 0, 0.5};
			font = "PuristaMedium";
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			text = "Hats";
			colorText[] = {0.969,0.969,0.969,1};
			colorBackground[] = {0, 0, 0, 0};
			linespacing = 1;
			tooltipColorText[] = {1,1,1,1};
			tooltipColorBox[] = {1,1,1,1};
			tooltipColorShade[] = {0,0,0,0.65};
		};

		class PDT_RscText_UniformText: Life_RscText
		{
            idc = -1;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.37 * safezoneH + safezoneY;
    		h = 0.037 * safezoneH;
    		w = 0.3 * safezoneW;
			shadow = 1;
			colorShadow[] = {0, 0, 0, 0.5};
			font = "PuristaMedium";
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			text = "Uniforms";
			colorText[] = {0.969,0.969,0.969,1};
			colorBackground[] = {0, 0, 0, 0};
			linespacing = 1;
			tooltipColorText[] = {1,1,1,1};
			tooltipColorBox[] = {1,1,1,1};
			tooltipColorShade[] = {0,0,0,0.65};
		};

		class PDT_RscText_GlassesText: Life_RscText
		{
            idc = -1;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.52 * safezoneH + safezoneY;
    		h = 0.037 * safezoneH;
    		w = 0.3 * safezoneW;
			shadow = 1;
			colorShadow[] = {0, 0, 0, 0.5};
			font = "PuristaMedium";
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			text = "Glasses";
			colorText[] = {0.969,0.969,0.969,1};
			colorBackground[] = {0, 0, 0, 0};
			linespacing = 1;
			tooltipColorText[] = {1,1,1,1};
			tooltipColorBox[] = {1,1,1,1};
			tooltipColorShade[] = {0,0,0,0.65};
		};
    };
};
