# DinoWinToastNotifications

Windows toast notification plugin for [Dino](https://dino.im/).

Shows notifications in the standard Windows design.

Direct message from someone who has a profile picture:

![Direct message with picture](./img/direct_with_picture.jpg "Direct message with picture")

Direct message from someone who has not a profile picture:

![Direct message without picture](./img/direct_without_picture.jpg "Direct message without picture")

Chat message from someone who has not a profile picture:

![Chat message without picture](./img/chat_without_picture.jpg "Chat message without picture")

This plugin uses Pidgin's standard C API so no other tools like Perl are required.

## Table of contents

* [Supported operating systems](#supported-operating-systems)
* [Installation](#installation)
* [Troubleshooting](#troubleshooting)
* [How to build on Windows](#how-to-build-on-windows)

## Supported operating systems

The plugin was developed and tested using the newest Windows 10 version.

Other Windows 10 versions, Windows 8 and Windows 8.1 should also work, but this has not been tested.

To display the protocol, account and chat name in the toast notifications the Windows 10 Anniversary Update (also known as version 1607 or Redstone 1) or newer is required.

## Installation

1. Ensure to have the Microsoft Visual C++ 2015-2019 Redistributable (x86) installed or [download and install it from Microsoft](https://aka.ms/vs/16/release/vc_redist.exe).
2. Download the dll files from the [newest release](https://github.com/LAGonauta/DinoWinToastNotifications/releases/latest).
3. Copy the file DinoWinToastLib.dll to the installation directory of Dino. This is usually "C:\Program Files\dino".

## Troubleshooting

If you experience a problem or have an idea for a new feature, [feel free to open an issue](https://github.com/LAGonauta/DinoWinToastNotifications/issues).

### Known errors

* The initialization may fail if the current user is not permitted to edit the Dino shortcut in the Start menu.

  To be able to create Windows Toast Notifications, it is required to set a property on the Start menu shortcut of Dino or automatically create a new one. Please ensure the current user is permitted to do this.
  
* There is a duplicate task bar icon.

  The Toast notification plugin sets an Application User Model ID that is used to group program windows.
  
  If you have pinned Dino to the task bar before enabling the Toast notification plugin, unpin it and pin the current running Dino window.
  
  If you are using other Windows specific plugins, they may try to set another conflicting app id. Please try to identify incompatible Plugins by selective enabling or disabling. If you have found an incompatible plugin, try to update it to the newest version before creating an issue.

## How to build on Windows

### DinoWinToastLib.dll

This file is built using Visual Studio 2019.

Open the Solution lib/DinoWinToastLib.sln in Visual Studio 2019. Right click on the Project and hit Build.

Now the file DinoWinToastLib.dll should be in the Release folder of your Solution.
