def kidds_encryption(text, reverse=False):
    symbol, bukva = list('8;4‡)*56(1†092:3?¶-.'), list('ethosnairfdlmbyguvcp')
    if reverse:
        symbol, bukva = bukva, symbol
    return ''.join([symbol[bukva.index(i)] for i in text.lower() if i in bukva])
