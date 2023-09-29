modded class IngameHud
{
	
	ImageWidget m_FSMoon = NULL;
	ImageWidget m_FSMoon0 = NULL;
	Widget m_MoonBarPanel = NULL;
	Widget m_fsmoonLayout = NULL;
	Widget m_MoonModHudPanel = NULL;
	bool m_ShowGameHUD = true;

	// Initialize the relevant widgets for this mod
	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);

		
		Class.CastTo(m_fsmoonLayout, GetGame().GetWorkspace().CreateWidgets("FSLightingConfig/gui/layouts/moon.layout"));
		ImageWidget.CastTo(m_FSMoon, m_fsmoonLayout.FindAnyWidget("Moon"));
		ImageWidget.CastTo(m_FSMoon0, m_fsmoonLayout.FindAnyWidget("Moon0"));
		m_MoonBarPanel = m_fsmoonLayout.FindAnyWidget("MoonBarPanel");
		m_MoonModHudPanel = m_fsmoonLayout.FindAnyWidget("HudPanel_Moon");


		m_MoonModHudPanel.Show(false);
	}
	
	override void SetFSMoon(int value)
	{
		if (!m_FSMoon)
		{
			return;
		}
		if (value == 0)
		{
			m_FSMoon.Show(true);
			m_FSMoon0.Show(false);
		}
		else if (value == 1)
		{
			m_FSMoon.Show(false);
			m_FSMoon0.Show(true);
		}
		SetTempHudVisibility();
	}

	
	override void RefreshHudVisibility()
	{
		super.RefreshHudVisibility();

		if (!m_FSMoon )
		{ // Something has gone wrong loading UI - stop here.
			return;
		}

		SetTempHudVisibility();
	}

	void SetTempHudVisibility()
	{
		if (!m_ShowGameHUD)
		{
			m_MoonModHudPanel.Show(false);
			return;
		}
		bool shouldShow = (((!m_HudHidePlayer && !m_HudHideUI && m_HudState) || m_HudInventory);
		m_MoonModHudPanel.Show(shouldShow);
		
	}

	override void Show(bool show)
	{
		super.Show(show);
		m_ShowGameHUD = show;
	}
}