#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

    const uintptr_t healthAddress      = 0x00816C54;
    const uintptr_t mpt57BulletAddress = 0x00816CA8;
    const uintptr_t mpt57AmmoAddress   = 0x00816C84;
    const uintptr_t mk77BulletAddress  = 0x00816C94;
    const uintptr_t mk77AmmoAddress    = 0x00816C70;
    const uintptr_t shieldAddress      = 0x00816C58;
    const uintptr_t bombAddress        = 0x00816CAC;

    int health, mpt57_bullet, mpt57_ammo, mk77bullet, mk77ammo, shield, bomb;

    int afterHealth;
    int afterMptBullet;
    int afterMptAmmo;
    int afterMk77Bullet;
    int afterMk77Ammo;
    int afterShield;
    int afterBomb;

int main(void) {

    HWND gameWindowScreen = FindWindow(NULL, "AssaultCube");

    DWORD pidNo;

    GetWindowThreadProcessId(gameWindowScreen, &pidNo);

    HANDLE allowProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pidNo);

    if (!allowProcess)
    {
        printf("Process ID not found ");
        return 1;
    }

    else {

        printf("Process ID Found %d", pidNo);

    }



    while (1) {


        ReadProcessMemory(allowProcess, (LPCVOID)healthAddress, &health, sizeof(health), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mpt57BulletAddress, &mpt57_bullet, sizeof(mpt57_bullet), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mpt57AmmoAddress, &mpt57_ammo, sizeof(mpt57_ammo), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mk77BulletAddress, &mk77bullet, sizeof(mk77bullet), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mk77AmmoAddress, &mk77ammo, sizeof(mk77ammo), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)shieldAddress, &shield, sizeof(shield), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)bombAddress, &bomb, sizeof(bomb), NULL);

        if(GetAsyncKeyState(VK_F1) < 0) {

            afterHealth = 999;
            WriteProcessMemory(allowProcess, (LPVOID)healthAddress, &afterHealth, sizeof(afterHealth), NULL);

        }

        if(GetAsyncKeyState(VK_F2) < 0) {

            afterMptBullet = 999;
            WriteProcessMemory(allowProcess, (LPVOID)mpt57BulletAddress, &afterMptBullet, sizeof(afterMptBullet), NULL);

        }

        if(GetAsyncKeyState(VK_F3) < 0) {

            afterMptAmmo = 999;
            WriteProcessMemory(allowProcess, (LPVOID)mpt57AmmoAddress, &afterMptAmmo, sizeof(afterMptAmmo), NULL);

        }

        if(GetAsyncKeyState(VK_F4) < 0){

            afterMk77Bullet = 999;
            WriteProcessMemory(allowProcess, (LPVOID)mk77BulletAddress, &afterMk77Bullet, sizeof(afterMk77Bullet), NULL);

        }

        if(GetAsyncKeyState(VK_F5) < 0) {

            afterMk77Ammo = 999;
            WriteProcessMemory(allowProcess, (LPVOID)mk77AmmoAddress, &afterMk77Ammo, sizeof(afterMk77Ammo), NULL);

        }

        if(GetAsyncKeyState(VK_F6) < 0) {

            afterShield = 999;
            WriteProcessMemory(allowProcess, (LPVOID)shieldAddress, &afterShield, sizeof(afterShield), NULL);

        }

        if(GetAsyncKeyState(VK_F7) < 0) {

            afterBomb = 999;
            WriteProcessMemory(allowProcess, (LPVOID)bombAddress, &afterBomb, sizeof(afterBomb), NULL);

        }
    

        printf("--- Assault Cube Memory Read & Write ---\n\n"
                "[F1] Health        : %d\n"
                "[F2] Mpt Bullet    : %d\n"
                "[F3] Mpt Ammo      : %d\n"
                "[F4] Mk-77 Bullet  : %d\n"
                "[F5] Mk-77 Ammo    : %d\n"
                "[F6] Shield        : %d\n"
                "[F7] Bomb          : %d\n", health, mpt57_bullet, mpt57_ammo, mk77bullet, mk77ammo, shield, bomb);

            system("cls");

        }
    return 0;
    
}
