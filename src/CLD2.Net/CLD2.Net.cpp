#include "CLD2.Net.h"
#include "../../cld2/public/compact_lang_det.h"
#include "../../cld2/public/encodings.h"

String^ CLD2Net::LanguageDetector::DetectLanguage(String^ text)
{
	bool isReliable = true;
	array<Byte>^ encodedBytes = Encoding::UTF8->GetBytes(text);
	pin_ptr<Byte> pinnedBytes = &encodedBytes[0];
	CLD2::Language lang = CLD2::DetectLanguage(reinterpret_cast<char*>(pinnedBytes), text->Length, true, &isReliable);
	return gcnew String(CLD2::LanguageCode(lang));
}
