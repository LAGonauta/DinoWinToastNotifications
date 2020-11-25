// DinoWinToastLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DinoWinToastTemplate.h"

static std::wstring convert(const char* str)
{
  static thread_local std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.from_bytes(str);
}

extern "C" {
  dino_wintoasttemplate dino_wintoasttemplate_new(dino_wintoasttemplate_wintoasttemplatetype type)
  {
    return new WinToastLib::WinToastTemplate(static_cast<WinToastLib::WinToastTemplate::WinToastTemplateType>(type));
  }

  void dino_wintoasttemplate_destroy(dino_wintoasttemplate templ)
  {
    if (templ != nullptr)
    {
      delete static_cast<WinToastLib::WinToastTemplate*>(templ);
    }
  }

  void dino_wintoasttemplate_setTextField(dino_wintoasttemplate templ, const char* txt, dino_wintoasttemplate_textfield pos)
  {
    if (templ != nullptr && txt != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setTextField(convert(txt), static_cast<WinToastLib::WinToastTemplate::TextField>(pos));
    }
  }

  void dino_wintoasttemplate_setImagePath(dino_wintoasttemplate templ, const char* imgPath)
  {
    if (templ != nullptr && imgPath != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setImagePath(convert(imgPath));
    }
  }

  void dino_wintoasttemplate_setAudioPath(dino_wintoasttemplate templ, const char* audioPath)
  {
    if (templ != nullptr && audioPath != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setAudioPath(convert(audioPath));
    }
  }

  void dino_wintoasttemplate_setAttributionText(dino_wintoasttemplate templ, const char* attributionText)
  {
    if (templ != nullptr && attributionText != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setAttributionText(convert(attributionText));
    }
  }

  void dino_wintoasttemplate_addAction(dino_wintoasttemplate templ, const char* label)
  {
    if (templ != nullptr && label != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->addAction(convert(label));
    }
  }

  void dino_wintoasttemplate_setAudioOption(dino_wintoasttemplate templ, dino_wintoasttemplate_audiooption audioOption)
  {
    if (templ != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setAudioOption(static_cast<WinToastLib::WinToastTemplate::AudioOption>(audioOption));
    }
  }

  void dino_wintoasttemplate_setDuration(dino_wintoasttemplate templ, dino_wintoasttemplate_duration duration)
  {
    if (templ != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setDuration(static_cast<WinToastLib::WinToastTemplate::Duration>(duration));
    }
  }

  void dino_wintoasttemplate_setExpiration(dino_wintoasttemplate templ, int64_t millisecondsFromNow)
  {
    if (templ != nullptr)
    {
      auto obj = static_cast<WinToastLib::WinToastTemplate*>(templ);
      obj->setExpiration(millisecondsFromNow);
    }
  }
}