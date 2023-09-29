enum eModifiersFS: eModifiers 
{
	MDF_FS_Moon = 251
}

modded class ModifiersManager
{
	override void Init()
	{
		super.Init();

		AddModifier( new FSLightMdfr);
		
	}
};