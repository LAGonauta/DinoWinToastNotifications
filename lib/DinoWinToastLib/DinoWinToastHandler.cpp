#include "DinoWinToastHandler.hpp"

WinToastHandler::WinToastHandler(int conv_id, void(*click_callback)(int conv_id, void* callback_target), void* callback_target) :
  conv_id(conv_id), callback_target(callback_target), click_callback(click_callback) {
}

void WinToastHandler::toastActivated() const {
  if (this->click_callback != nullptr && this->callback_target != nullptr && this->conv_id > 0) {
    this->click_callback(this->conv_id, this->callback_target);
  }
}

void WinToastHandler::toastActivated(int actionIndex) const
{
  if (this->click_callback != nullptr && this->callback_target != nullptr && this->conv_id > 0) {
    this->click_callback(this->conv_id, this->callback_target);
  }
}

void WinToastHandler::toastDismissed(WinToastDismissalReason state) const {
}

void WinToastHandler::toastFailed() const {
}