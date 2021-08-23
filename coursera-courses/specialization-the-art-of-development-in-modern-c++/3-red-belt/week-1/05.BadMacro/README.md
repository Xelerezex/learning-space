## Bad Macro

Вам дан макрос, который распечатывает два переданных ему значения в переданный поток вывода.
В реализации макроса есть недостаток, ограничивающий его применимость в реальных программах.
Вам требуется найти и устранить недостаток.

```c++
#define PRINT_VALUES(out, x, y) out << (x) << endl; out << (y) << endl
```

Автор задачи — [Борис Егоров](https://www.coursera.org/user/b36d9f5a62bc4a643cdf459fb068d606)

Заготовка решения

> [print_values.cpp](https://d3c33hcgiwev3.cloudfront.net/x9RWoPi4R76UVqD4uFe-rA_14b7282a29cd4b6989c2ed4fd14e7be1_print_values.cpp?Expires=1629849600&Signature=D~NmKxDvcdvSycRQiFB~sm65iPfE7meyq3u6QWwr~uessj6ZQvQvsFf8eArVV8PNXFolvc4zlF2nLy6yrCLxQyYXzKHDwMwr67DvwwB6hJjswhpsQJuEtohCAylsl-ewQBpnM6lnFXpuHtMCsCXKnJemgx52RaDiB83cyJn--28_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Для этой задачи есть набор подсказок, которые должны помочь вам с решением.
Если вам не удаётся решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться.
Но сначала обязательно попробуйте решить задачу без подсказок.

> [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/E_RriGNXEeiEZRKxXgWFpg_143df730635711e889bf435d20724b40__________-1.pdf?Expires=1629849600&Signature=aPdHAzaaR7Ld25eqwIqXabF8ZjUT1zfmLffsk~ataMGoCXEmykAbIrQ2xZOZVUrpKAeZ5SXp3QvBQbOCeD9h~7rZ349AaLCbZTsS7uPf2C5xScKX5ZqYBm292LQTdrVJplix0-k35uiUdDkNRPssfsB2sxMIDOnjuIWWHqgMMfc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/E_TglGNXEeiFLgr123Yivg_14630b60635711e88725a9851a341ffc__________-2.pdf?Expires=1629849600&Signature=Gbi7aPb8M52pnfCbqXp8mNZ6D3-vABxmWGosZnh5-lEviZtHjMu3p6vynynJAQQ3PhQWTBL65fiP5xBTXNTlZbKJbAWQVbBYvtiq-BZaIc1Znc1JrS64FV~-RW7Zt8tjDwIlsfWDMvy~98B6Lajb6n4wzLnFhAYMK4rER62lmCY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/E_Wj5WNXEeiFLgr123Yivg_14633270635711e8be963b2fd3de9069__________-3.pdf?Expires=1629849600&Signature=BCjdZ9NI~H0twjMbXrknW6dG-a1hsbxahIz~JckbI7-Jb-mOYq-4YgurOaUcppH-aun7ujazTbbEt33uiTuHlTZGIEytBr0e2~useH2V3egPih0nksJ8AW26C3XcXNp0FK8ZJMLghJ8-78gV7MEAG-K2~nbS64WFE8yyRthLwt0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/E_bcZmNXEeiFLgr123Yivg_1468fed0635711e8a0fd8dcb16442a53__________-4.pdf?Expires=1629849600&Signature=PF~nAxpWrB7IzzjHTg3MwwzQ23Eb7pmIVtY6XkiKNKU3DiFNT45d4chE08I0taTtpX~fHpzPQcbz5g4rgSyJYkZj0MBwQdQoSzcnFClghaknxBhuf~INlOOUmTcKWupIpaMdoTwXbCbSR-BLBgRD3Pcj7gaeekWuKxn8TIyV71w_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

