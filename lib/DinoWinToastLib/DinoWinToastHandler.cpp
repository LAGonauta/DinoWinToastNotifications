#include "DinoWinToastHandler.hpp"

WinToastHandler::WinToastHandler(dinoWinToastLib_Notification_Callbacks callbacks) :
  callbacks(callbacks) {
}

WinToastHandler::~WinToastHandler() {
  if (callbacks.activated_context != nullptr &&
    callbacks.activated_free != nullptr) {
    callbacks.activated_free(callbacks.activated_context);
  }

  if (callbacks.activatedWithIndex_context != nullptr &&
    callbacks.activatedWithIndex_free != nullptr) {
    callbacks.activatedWithIndex_free(callbacks.activatedWithIndex_context);
  }

  if (callbacks.dismissed_context != nullptr &&
    callbacks.dismissed_free != nullptr) {
    callbacks.dismissed_free(callbacks.dismissed_context);
  }

  if (callbacks.failed_context != nullptr &&
    callbacks.failed_free != nullptr) {
    callbacks.failed_free(callbacks.failed_context);
  }
}

void WinToastHandler::toastActivated() const {
  if (callbacks.activated != nullptr) {
    callbacks.activated(callbacks.activated_context);
  }
}

void WinToastHandler::toastActivated(int actionIndex) const
{
  if (callbacks.activatedWithIndex != nullptr) {
    callbacks.activatedWithIndex(actionIndex, callbacks.activatedWithIndex_context);
  }
}

void WinToastHandler::toastDismissed(WinToastDismissalReason reason) const {
  if (callbacks.dismissed != nullptr) {
    callbacks.dismissed(static_cast<dinoWinToastLib_Notification_Reason>(reason), callbacks.dismissed_context);
  }
}

void WinToastHandler::toastFailed() const {
  if (callbacks.failed != nullptr) {
    callbacks.failed(callbacks.failed_context);
  }
}