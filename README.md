# Compact Language Detector 2 for .Net

### Summary

CLD2 probabilistically detects over 80 languages in either plain text or HTML/XML. The design target is web pages of at least 200 characters (about two sentences); CLD2 is not designed to do well on very short text, lists of proper names, part numbers, etc.

### Supported Languages
These 83 languages are detected: 
>Afrikaans Albanian Arabic Armenian Azerbaijani Basque Belarusian Bengali Bihari Bulgarian Catalan Cebuano Cherokee Croatian Czech Chinese Chinese_T Danish Dhivehi Dutch English Estonian Finnish French Galician Ganda Georgian German Greek Gujarati Haitian_Creole Hebrew Hindi Hmong Hungarian Icelandic Indonesian Inuktitut Irish Italian Javanese Japanese Kannada Khmer Kinyarwanda Korean Laothian Latvian Limbu Lithuanian Macedonian Malay Malayalam Maltese Marathi Nepali Norwegian Oriya Persian Polish Portuguese Punjabi Romanian Russian Scots_Gaelic Serbian Sinhalese Slovak Slovenian Spanish Swahili Swedish Syriac Tagalog Tamil Telugu Thai Turkish Ukrainian Urdu Vietnamese Welsh Yiddish.

### Internals
__Classification &amp; Scoring__. CLD2 is a Naïve Bayesian classifier, using one of three different token algorithms. For Unicode scripts such as Greek and Thai that map one-to-one to detected languages, the script defines the result. For the 80,000+ character Han script and its CJK combination with Hiragana, Katakana, and Hangul scripts, single letters (unigrams) are scored. For all other scripts, sequences of four letters (quadgrams) are scored.

Scoring is done exclusively on lowercased Unicode letters and marks, after expanding HTML entities <code>&xyz;</code> and after deleting digits, punctuation, and <code>&lt;tags&gt;</code>. Quadgram word beginnings and endings (indicated here by underscore) are explicitly used, so the word <code>\_look\_</code> scores differently from the word-beginning <code>\_look</code> or the mid-word look. Quadgram single-letter "words" are completely ignored. For each letter sequence, the scoring uses the 3-6 most likely languages and their quantized log probabilities. The training corpus is manually constructed from chosen web pages for each language, then augmented by careful automated scraping of over 100M additional web pages.

Several embellishments improve the basic algorithm: 
- additional scoring of some sequences of two CJK letters or eight other letters
- scoring some words and word pairs that are distinctive within sets of statistically-close languages such as {Malay, Indonesian} or {Spanish, Portuguese, Galician}
- removing repetitive sequences/words that would otherwise skew the scoring, such as <code>jpg</code> in <code>foo.jpg bar.jpg baz.jpg</code>
- removing web-specific words that convey almost no language information such as <code>page</code>, <code>link</code>, <code>click</code>, <code>td</code>, <code>tr</code>, <code>copyright</code>, <code>wikipedia</code>, <code>http</code>.
