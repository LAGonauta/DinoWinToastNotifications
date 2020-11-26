// DinoWinToastLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DinoWinToastLib.h"
#include "DinoWinToastHandler.hpp"

bool isInit = false;

extern "C"
{
  dinoWinToastLib_Notification_Callbacks* dinoWinToastLib_NewCallbacks() {
    return new dinoWinToastLib_Notification_Callbacks();
  }

  void dinoWinToastLib_DestroyCallbacks(dinoWinToastLib_Notification_Callbacks* callbacks) {
    if (callbacks != nullptr) {
      delete callbacks;
    }
  }

  int dinoWinToastLib_Init() {
    try {
      WinToastLib::WinToast::instance()->setAppName(L"Dino");
      WinToastLib::WinToast::instance()->setAppUserModelId(
        WinToastLib::WinToast::configureAUMI(L"Dino", L"Dino"));

      WinToastLib::WinToast::WinToastError error;
      isInit = WinToastLib::WinToast::instance()->initialize(&error);
      return error;
    }
    catch (...) {
      // unknown exception
      return -1;
    }
  }

  int64_t dinoWinToastLib_ShowMessage(dino_wintoasttemplate templ, dinoWinToastLib_Notification_Callbacks* callbacks) {
    if (isInit) {
      if (templ == nullptr) {
        return WinToastLib::WinToast::WinToastError::InvalidParameters;
      }

      try {
        auto handler = std::make_shared<WinToastHandler>(*callbacks);
        WinToastLib::WinToast::WinToastError error;
        return WinToastLib::WinToast::instance()->showToast(*static_cast<WinToastLib::WinToastTemplate*>(templ), handler, &error);
      }
      catch (...) {
        // unknown exception
        return -1;
      }
    }
    else {
      return WinToastLib::WinToast::WinToastError::NotInitialized;
    }
  }

  int dinoWinToastLib_RemoveNotification(int64_t notification_id)
  {
    return isInit && WinToastLib::WinToast::instance()->hideToast(notification_id);
  }
}