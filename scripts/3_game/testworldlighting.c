modded class WorldLighting
{
	string lighting_default = "dz\\data\\lighting\\lighting_default.txt";
	string lighting_darknight = "dz\\data\\lighting\\lighting_darknight.txt";
	
	void WorldLighting() {}
	void ~WorldLighting() {}
	
	int fslightingID;
	bool IsSetforToday = false;
	int IsSetforDay = 0;
		
	// sets global lighting config by given value (sent from server, defined in server config)
	void SetGlobalLighting( int lightingID )
	{
		switch ( lightingID )
		{
			case 0:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_default );
				fslightingID = 0;
				break;
				
			case 1:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_darknight );
				fslightingID = 1;
				break;
		}
	}
	
	int GetGlobalLighting()
	{
		return fslightingID;
	}
	
	void LightingIsSetforToday ( bool daylight)
	{
		
		IsSetforToday = daylight;
	}
	
	bool GetLightingIsSetforToday()
	{
		return IsSetforToday;
	}
	
	void SetDay(int day)
	{
		IsSetforDay = day;
	}
	
	int GetDay()
	{
		return IsSetforDay;
	}
	
}

/*modded class WorldLighting
{
	protected string lighting_modded = "your\\path\\to\\lighting\\cfg.txt";
	
	override void SetGlobalLighting( int lightingID )
	{
		switch ( lightingID )
		{
			case 3:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_modded );
				break;
		}
	}
}*/