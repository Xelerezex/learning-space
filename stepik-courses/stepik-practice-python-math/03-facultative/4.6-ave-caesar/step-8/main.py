from itertools import cycle


def jarriquez_encryption(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ', reverse=False):
    n = len(alphabet)
    sign = -1 if reverse else 1
    return "".join(
        alphabet[(alphabet.index(letter) + sign * int(skey)) % n]
        for letter, skey in zip(
            filter(alphabet.__contains__, text.upper()), cycle(str(key))
        )
    )


text = (
    "ТЛБЛДУЭППТКЛФЧУВНУПБКЗИХТЛТТЫХНЛОИНУВЖММИНПФНПШОКЧЛЕРНТФНАХЖИДМЯКЛТУБЖИУЕЖЕАХЛГЩЕЕ"
    "ЪУВНГАХИЯШПЙАОЦЦПВТЛБФТТИИНДИДНЧЮОНЯОФВТЕАТФУШБЛРЮЮЧЖДРУУШГЕХУРПЧЕУВАЭУОЙБДБНОЛСКЦБ"
#   "САОЦЦПВИШЮТППЦЧНЖОИНШВРЗЕЗКЗСБЮНЙРКПСЪЖФФШНЦЗРСЭШЦПЖСЙНГЭФФВЫМЖИЛРОЩСЗЮЙФШФДЖО"
#   "ИЗТРМООЙБНФГОЩЧФЖООКОФВЙСЭФЖУЬХИСЦЖГИЪЖДШПРМЖПУПГЦНВКБНРЕКИБШМЦХЙИАМФЛУЬЙИСЗРТЕС"
)

start = time.time()
for key in range(100_000, 500_000):
    en = jarriquez_encryption(text, key, alphabet="АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", reverse=True)
    if "АЛМАЗ" in en and "ДАКОСТА" in en:
        print(en, key)
        break
print(f"{time.time() - start:>.4f}")
