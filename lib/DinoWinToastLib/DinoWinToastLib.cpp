// DinoWinToastLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DinoWinToastLib.h"

using namespace std;
using namespace WinToastLib;

bool isInit = false;

std::wstring getTextFromHtml(std::wstring);

//char* copyCharArrayToHeap(char* source) {
//	size_t size = strlen(source) + 1;
//	char* dest = (char*)malloc(size);
//	if (dest != nullptr) {
//		strcpy(dest, source);
//	}
//	return dest;
//}

class WinToastHandler : public IWinToastHandler {
public:
  void(*click_callback)(int conv_id, void* class_obj) = nullptr;
  void* class_obj = nullptr;
  int conv_id = 0;
  WinToastHandler(int conv_id, void* class_obj, void(*click_callback)(int conv_id, void* class_obj));
  // Public interfaces
  void toastActivated() const;
  void toastActivated(int actionIndex) const;
  void toastDismissed(WinToastDismissalReason state) const;
  void toastFailed() const;
};

WinToastHandler::WinToastHandler(int conv_id, void* class_obj, void(*click_callback)(int conv_id, void* class_obj)) :
  conv_id(conv_id), class_obj(class_obj), click_callback(click_callback) {
}

void WinToastHandler::toastActivated() const {
  if (this->click_callback != nullptr && this->class_obj != nullptr && this->conv_id > 0) {
    this->click_callback(this->conv_id, this->class_obj);
  }
}

void WinToastHandler::toastActivated(int actionIndex) const
{
  if (this->click_callback != nullptr && this->class_obj != nullptr && this->conv_id > 0) {
    this->click_callback(this->conv_id, this->class_obj);
  }
}

void WinToastHandler::toastDismissed(WinToastDismissalReason state) const {
}

void WinToastHandler::toastFailed() const {
}

extern "C" int dinoWinToastLibInit()
{
  try {
    WinToast::instance()->setAppName(L"Dino");
    WinToast::instance()->setAppUserModelId(
      WinToast::configureAUMI(L"Dino", L"Dino"));

    WinToast::WinToastError error;
    isInit = WinToast::instance()->initialize(&error);
    return error;
  }
  catch (...) {
    // unknown exception
    return -1;
  }
}

extern "C" int dinoWinToastLibShowMessage(const char* sender, const char* message, const char* imagePath, int conv_id, void* class_obj, void(*click_callback)(int conv_id, void* class_obj))
{
  if (isInit) {
    if (sender == nullptr) {
      return WinToast::WinToastError::InvalidParameters;
    }
    try {
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

      WinToastHandler* handler = new WinToastHandler(conv_id, class_obj, click_callback);
      WinToastTemplate templ;
      std::wstring sImagePath;

      if (imagePath != NULL) {
        templ = WinToastTemplate(WinToastTemplate::ImageAndText02);
        sImagePath = converter.from_bytes(imagePath);
        templ.setImagePath(sImagePath);
      }
      else {
        templ = WinToastTemplate(WinToastTemplate::Text02);
      }

      std::wstring sSender = converter.from_bytes(sender);
      templ.setTextField(sSender, WinToastTemplate::FirstLine);
      std::wstring sMessage = converter.from_bytes(message);
      sMessage = stripHTML(sMessage);
      templ.setTextField(sMessage, WinToastTemplate::SecondLine);

      WinToast::WinToastError error;
      INT64 toastResult = WinToast::instance()->showToast(templ, handler, &error);

      return error;
    }
    catch (...) {
      // unknown exception
      return -1;
    }
  }
  else {
    return WinToast::WinToastError::NotInitialized;
  }
}