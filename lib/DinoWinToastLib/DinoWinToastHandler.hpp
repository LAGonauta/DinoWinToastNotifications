#pragma once

#include "wintoastlib.h"
#include "DinoWinToastLib.h"

class WinToastHandler : public WinToastLib::IWinToastHandler {
private:
  dinoWinToastLib_Notification_Callbacks callbacks{};

public:
  WinToastHandler(dinoWinToastLib_Notification_Callbacks callbacks);
  ~WinToastHandler();

  // Public interfaces
  void toastActivated() const;
  void toastActivated(int actionIndex) const;
  void toastDismissed(WinToastLib::IWinToastHandler::WinToastDismissalReason state) const;
  void toastFailed() const;
};