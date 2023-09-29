class CfgPatches
{
	class FSLightingConfig
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class FSLightingConfig
	{
		dir="FSLightingConfig";
		name="FSLightingConfig";
		picture="";
		action="";
		extra=0;
		hideName=0;
		hidePicture=1;
		credits="";
		version="0";
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"FSLightingConfig/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"FSLightingConfig/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"FSLightingConfig/scripts/5_mission"
				};
			};
		};
	};
};