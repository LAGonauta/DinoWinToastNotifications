// DinoWinToastLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DinoWinToastLib.h"
#include "DinoWinToastHandler.hpp"

bool isInit = false;

extern "C"
{
  int dinoWinToastLibInit()
  {
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

  int dinoWinToastLibShowMessage(dino_wintoasttemplate templ, int conv_id, dinoWinToastLibNotificationCallback click_callback, void* callback_target)
  {
    if (isInit) {
      if (templ == nullptr) {
        return WinToastLib::WinToast::WinToastError::InvalidParameters;
      }

      try {
        auto handler = std::make_shared<WinToastHandler>(conv_id, click_callback, callback_target);
        WinToastLib::WinToast::WinToastError error;
        INT64 toastResult = WinToastLib::WinToast::instance()->showToast(*static_cast<WinToastLib::WinToastTemplate*>(templ), handler, &error);

        return error;
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
}