class FSLightMdfr extends ModifierBase
{
	
	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 					= eModifiersFS.MDF_FS_Moon;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 100;
		DisableDeactivateCheck();

	}

	override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnReconnect(PlayerBase player)
	{

	}
	
	override string GetDebugText()
	{
		
	}
	
	override string GetDebugTextSimple()
	{
		
	}

	
	override void OnTick(PlayerBase player, float deltaT)
	{		
		int year, month, day, hour, minute;
		GetGame().GetWorld().GetDate(year, month, day, hour, minute);
		
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			WorldLighting wLighting = mission.GetWorldLighting();
		}
		
		if (wLighting.GetDay() == day)
		{
			wLighting.LightingIsSetforToday(false);
		}
		else
		{
			if (!wLighting.GetLightingIsSetforToday())
			{
				if (hour >= 9 && hour <= 10)
				{
					if (player.fs_lightingconfig == 0)
					{
						player.fs_lightingconfig = 1;
						wLighting.SetDay(day);
						//player.saveday = day;
						player.SetSynchDirty();
						player.MessageAction("Die nächste Nacht wird dunkel");
						wLighting.LightingIsSetforToday(true);
					}
					else if (player.fs_lightingconfig == 1)
					{
						player.fs_lightingconfig = 0;
						wLighting.SetDay(day);
						//player.saveday = day;
						player.SetSynchDirty();
						player.MessageAction("Die nächste Nacht wird hell");
						wLighting.LightingIsSetforToday(true);
					}
				}
			}
		}
		
	}
};
