#pragma once

#include "wintoastlib.h"

class WinToastHandler : public WinToastLib::IWinToastHandler {
private:
  void(*click_callback)(int conv_id, void* class_obj) = nullptr;
  void* callback_target = nullptr;
  int conv_id = 0;

public:
  WinToastHandler(int conv_id, void(*click_callback)(int conv_id, void* callback_target), void* callback_target);

  // Public interfaces
  void toastActivated() const;
  void toastActivated(int actionIndex) const;
  void toastDismissed(WinToastLib::IWinToastHandler::WinToastDismissalReason state) const;
  void toastFailed() const;
};