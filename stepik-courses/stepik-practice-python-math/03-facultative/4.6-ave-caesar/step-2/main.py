def caesar(text, key):
    return ''.join(chr(65 + (-65 + ord(ch) + key) % 26)
                   for ch in text.upper() if ch.isalpha())
