modded class PluginPlayerStatus
{
	void SetFSMoon(int value)
	{
		Mission mission = GetGame().GetMission();
		//MissionBaseWorld mission = MissionBaseWorld.Cast(GetGame().GetMission());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
			{
				hud.SetFSMoon(value);
			}
		}
	}
}