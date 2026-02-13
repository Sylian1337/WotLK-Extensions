# WotLK-Extensions

Client extension project for the 3.3.5a client of World of Warcraft.

---

## About This Repository

This repository is a fork and continuation of prior 3.3.5a client extension work.  
It builds upon foundations laid by:

- **TSWoW ClientExtensions**  
- **WoWFix335** by [Robinsch](https://github.com/robinsch)  
- **AwesomeWotlk Patch** by [FrostAtom](https://github.com/FrostAtom)

The original groundwork and patching infrastructure remain credited to their respective authors.  
This repository preserves that functionality while extending it with additional runtime systems and development tooling.

---

## What This Fork Adds

Since forking, the following features were added:

- **DBC Hot Reloading** (reload DBC data without restarting the client)  
- **Runtime Item Name Hot-Patching**  
- **Additional Custom Lua Functions**  
- **Extended client-side packet handling**  
- **Internal improvements and refactoring for modularity**

These additions are independent extensions and do not replace or invalidate the original implementations.

---

## Project Structure

### Patcher.exe

Primarily based on **WoWFix335** by Robinsch.  
Most patching logic originates from that project.

DLL loading approach derived from **AwesomeWotlk** by FrostAtom.

Executable header data recalculated using CFF Explorer VIII.

---

### WotLKExtensions.dll

Contains runtime patches and functionality extensions.  
Most patches are configurable via `PatchConfig.h`.

**Important:**  
All patches are disabled by default.

This DLL is intended primarily for use in your own private server environment or projects that explicitly distribute it.

---

## Disclaimer

(Robinsch)
Some servers may scan the EBP stack for Lua calls.  
Using this DLL on servers that do not explicitly allow client modifications may result in account bans.

Use at your own discretion.

---

## Patches

- **No Ammo** – disables ammo requirement for ranged weapons; may require server core edits.  
- **More Than 21 Races Crashfix** – allows up to 31 playable races in character creation without crashes.  
- **Combo Point Fix** – allows every class to utilize combo points.  
- **More Than 12 Classes in LFD** – expands role table to handle more than 12 classes; can be overridden by `LFGRoles` DBC.  
- **Item Mod Expansion** – allows custom item mods to be displayed properly through GlobalStrings.lua.  
- **WoWTime Patch** – fixes calendar/date issues and potential client crashes.

See source and documentation for full technical details.

---

## Custom Lua Functions

Adds new and backported Lua functions.  
See the `Docs` directory for documentation.

---

## Custom DBC Manager

Includes a DBC loading and management system, expanded with hot-reload capabilities in this fork.  

See `Docs` for implementation details.

---

## Custom Packets

Allows the client to handle new data sent to and from the server.  
See `Docs` for more information.

---

## Repo Team

This fork is actively maintained by:

- [Sylian1337](https://github.com/Sylian1337)  
- [AzDeltaQQ](https://github.com/AzDeltaQQ)

We’re both working on adding new features, improving the DLL, and keeping the project alive.  

---

## Upstream Projects

This project builds upon:

- [WoWFix335](https://github.com/robinsch/WoWFix335)  
- [AwesomeWotlk](https://github.com/FrostAtom/awesome_wotlk)  
- [TSWoW](https://github.com/tswow/tswow)
- [WoTLK-Extension](https://github.com/Alyst3r/WotLK-Extensions)

If you are looking for the original implementations, please refer to the above repositories.

---

## Credits & Acknowledgements

**Original groundwork and patching infrastructure:**

- [Robinsch](https://github.com/robinsch) – WoWFix335, client patch research  
- [FrostAtom](https://github.com/FrostAtom) – AwesomeWotlk patch implementation  
- TSWoW contributors
- [Alyst3r](https://github.com/Alyst3r/WotLK-Extensions) - Porting TSWoW extention into DLL.
- [Tester](https://github.com/TesterWoWDev) – DBC manager collaboration and development support  
- Nix  
- Deamon  
- Natrist  
- [DrFrugal (4bhorrent)](https://drfrugal.xyz/) – research resources and documentation  
- [Titi](https://gitlab.com/T1ti) – design ideas and dehardcoding concepts  
- M'Dic  
- WoW Modding Community (Reverse Engineering channel)

If anyone is missing, feel free to open an issue and contributions will be added.

---
