# Setting Up Your Windows Environment

## 1. Install Boxstarter
Boxstarter is a tool that simplifies the setup of Windows environments. Use the following command to install it. This command is provided on Boxstarter's official website:

```powershell
. { iwr -useb https://boxstarter.org/bootstrapper.ps1 } | iex; Get-Boxstarter -Force
```

## 2. Run the Setup Script
Run the setup script to enable folder options and install three essential programs. Use the command below:

```powershell
Install-BoxstarterPackage -PackageName https://raw.githubusercontent.com/GameHackingAcademy/vmsetup/master/vmsetup.txt -DisableReboots
```

### Programs Installed:
- **Cheat Engine**: A memory scanner.
- **x64dbg**: A debugger.
- **Chocolatey**: A package manager.

## 3. Install "The Battle for Wesnoth"
Install the game "The Battle for Wesnoth" version 1.14.9 using Chocolatey with the following command:

```powershell
choco install wesnoth --version=1.14.9 -y
```

### About "The Battle for Wesnoth"
"The Battle for Wesnoth" is a free, open-source game with no anti-cheating mechanisms, making it suitable for testing and learning.

