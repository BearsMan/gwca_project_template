#include <Windows.h>

#include <GWCA/GWCA.h>

void InitializeMyProject();

BOOL WINAPI DllMain(HINSTANCE /* hinstDLL */, DWORD fdwReason, LPVOID /* lpvReserved */)
{
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            InitializeMyProject();
            break;
    }
}

void InitializeMyProject() {
    GW::Initialize();

    // Add your project code here.  You should probably create a loop that
    // only exits when GW closes.  See Toolbox code for an example:
    // https://github.com/gwdevhub/GWToolboxpp/blob/b5c84bd4dd58868addf710980b2c8702556067ec/GWToolboxdll/GWToolbox.cpp#L397

    GW::Terminate();
}
