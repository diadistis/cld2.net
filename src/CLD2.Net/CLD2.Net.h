#pragma once

using namespace System;
using namespace System::Text;

namespace CLD2Net {
	public ref class LanguageDetector
	{
	public:
		String^ DetectLanguage(String^ str);
	};
}
