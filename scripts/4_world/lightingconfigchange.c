modded class PlayerBase extends ManBase
{
	int fs_lightingconfig = 0;
	int saveday = 1;
	int testlightingID;
	
	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("fs_lightingconfig");
		RegisterNetSyncVariableInt("saveday");
		
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			WorldLighting wLighting = mission.GetWorldLighting();
			if ( wLighting )
				testlightingID = wLighting.GetGlobalLighting();
		}
		
		// Update client 
		if (GetGame().IsClient())
		{
			

			if (IsControlledPlayer() && m_ModulePlayerStatus)
			{
				if (testlightingID == 0)
				{
					m_ModulePlayerStatus.SetFSMoon(0);
				}
				if (testlightingID == 1)
				{
					m_ModulePlayerStatus.SetFSMoon(1);
				}
			}
		}
	}
	
	/*void changelight()
	{
		int year, month, day, hour, minute;
		GetGame().GetWorld().GetDate(year, month, day, hour, minute);
		
		if (hour >= 9 && hour <= 10)
		{
			if (fs_lightingconfig == 0)
			{
				fs_lightingconfig = 1;
				UpdateLighting();
				SetSynchDirty();	
				this.MessageAction("Die nächste Nacht wird dunkel");
			}
			else
			{
				fs_lightingconfig = 0;
				UpdateLighting();
				SetSynchDirty();
				this.MessageAction("Die nächste Nacht wird hell");
			}
				
		}
	}*/
	
	// Triggered when variables are synchronized from the server to the client
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		
		// Update client 
		if (GetGame().IsClient())
		{
			
			
			if (IsControlledPlayer() && m_ModulePlayerStatus)
			{
				if (fs_lightingconfig == 0)
				{
					m_ModulePlayerStatus.SetFSMoon(0);
					UpdateLighting();
				}
				if (fs_lightingconfig == 1)
				{
					m_ModulePlayerStatus.SetFSMoon(1);
					UpdateLighting();
				}
			}
		}
	}
	
	override void UpdateLighting()
	{
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			WorldLighting wLighting = mission.GetWorldLighting();
			if ( wLighting )
				wLighting.SetGlobalLighting( fs_lightingconfig );
		}
	}
	
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if ( !super.OnStoreLoad( ctx, version ) ) {
			return false;
		}
		if (!ctx.Read( fs_lightingconfig )) {
			return false;
		}
		if (!ctx.Read( saveday )) {
			return false;
		}
		return true;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write( fs_lightingconfig );
		ctx.Write( saveday );
	}
	
	override void AfterStoreLoad()
	{    
		super.AfterStoreLoad();
		UpdateLighting();
	}
}