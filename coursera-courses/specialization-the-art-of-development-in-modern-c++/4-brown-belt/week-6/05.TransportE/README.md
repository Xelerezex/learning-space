В этой версии вам понадобится добавить в транспортный справочник функционал маршрутизации, реализованный с помощью предоставленных нами библиотек.
Изменения формата ввода
Новая секция — routing_settings

Во входной JSON добавляется ключ "routing_settings", значением которого является словарь с двумя ключами:

    "bus_wait_time" — время ожидания автобуса на остановке (в минутах). Считайте, что когда бы человек ни пришёл на остановку и какой бы ни была эта остановка, он будет ждать любой автобус в точности указанное количество минут. Значение — целое число от 1 до 1000.

    "bus_velocity" — скорость автобуса (в км/ч). Считайте, что скорость любого автобуса постоянна и в точности равна указанному числу. Время стоянки на остановках не учитывается, время разгона и торможения — тоже. Значение — вещественное число от 1 до 1000.

Пример

"routing_settings": {
  "bus_wait_time": 6,
  "bus_velocity": 40
}

Данная конфигурация задаёт время ожидания равным 6 минутам и скорость автобусов равной 40 километрам в час.
Новый тип запросов к базе — Route

В список stat_requests добавляются элементы с "type": "Route" — это запросы на построение маршрута между двумя остановками. Помимо стандартных свойств "id" и "type", они содержат ещё два:

    "from" — остановка, в которой нужно начать маршрут.

    "to" — остановка, в которой нужно закончить маршрут.

Оба значения — названия существующих в базе остановок (однако, возможно, не принадлежащих ни одному автобусному маршруту).

Пример

{
  "type": "Route",
  "from": "Biryulyovo Zapadnoye",
  "to": "Universam",
  "id": 4
}

Данный запрос означает построение маршрута от остановки «Biryulyovo Zapadnoye» до остановки «Universam».

На маршруте человек может использовать несколько автобусов, и даже один автобус несколько раз — если на некоторых участках он делает большой крюк и проще срезать на другом автобусе.

Маршрут должен быть наиболее оптимален по времени. Если маршрутов с минимально возможным суммарным временем несколько, допускается вывести любой из них: тестирующая система проверяет лишь совпадение времени маршрута с оптимальным и корректность самого маршрута.

При прохождении маршрута время расходуется на два типа активностей:

    Ожидание автобуса. Всегда длится bus_wait_time минут.

    Поездка на автобусе. Всегда длится ровно такое количество времени, которое требуется для преодоления данного расстояния со скоростью bus_velocity. Расстояние между остановками вычисляется по дорогам, то есть с помощью road_distances.

Ходить пешком, выпрыгивать из автобуса между остановками и использовать другие виды транспорта запрещается. На конечных остановках все автобусы высаживают пассажиров и уезжают в парк. Даже если человек едет на кольцевом ("is_roundtrip": true) маршруте и хочет проехать мимо конечной, он будет вынужден выйти и подождать тот же самый автобус ровно bus_wait_time минут. Этот и другие случаи разобраны в примерах.

Ответ на запрос Route устроен следующим образом:

{
    "request_id": <id запроса>,
    "total_time": <суммарное время>,
    "items": [
        <элементы маршрута>
    ]
}

total_time — суммарное время в минутах, требуемое для прохождения маршрута, выведенное в виде вещественного числа.

Обратите внимание, что расстояние от остановки A до остановки B может быть не равно расстоянию от B до A!

items — список элементов маршрута, каждый из которых описывает непрерывную активность пассажира, требующую временных затрат. А именно, элементы маршрута бывают двух типов.

Wait — подождать нужное количество минут (в нашем случае — всегда bus_wait_time) на указанной остановке:

{
    "type": "Wait",
    "stop_name": "Biryulyovo",
    "time": 6
}

  Bus — проехать span_count остановок (перегонов между остановками) на автобусе bus, потратив указанное количество минут:

  {
    "type": "Bus",
    "bus": "297",
    "span_count": 2,
    "time": 5.235
}

В случае отсутствия маршрута между указанными остановками выведите результат в следующем формате:

{
    "request_id": <id запроса>,
    "error_message": "not found"
}

Реализация

Задача поиска оптимального маршрута данного вида сводится к задаче поиска кратчайшего пути во взвешенном ориентированном графе.
https://yandex.ru/search/?text=%D0%B2%D0%B7%D0%B2%D0%B5%D1%88%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9%20%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B9%20%D0%B3%D1%80%D0%B0%D1%84

Мы предоставляем вам две небольшие библиотеки:

graph.h
https://d3c33hcgiwev3.cloudfront.net/eJN9Xv6pEeiAgQrXx6bp4g_78f720f0fea911e89407e364d21df08c_graph.h?Expires=1653523200&Signature=QFrQb10szHsUwYDOgwTUczPw0CJ7Y~NRUSdOKbmrqg2L~bj6dXjmMgDLR666MV8AuCpn3HK-S1-m8wXpkLnDnHGryEf4Ze2WKskzya6FzY8T0~8TINVbtaaaOAUpUpvRyR10i4s6i39BkReJQS-jzLlCarjRCZbKf8SyqHliNB8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A


router.h
https://d3c33hcgiwev3.cloudfront.net/eI2xEf6pEeilxxL_ZeRz_A_78f74800fea911e8b560c962a37cd8a9_router.h?Expires=1653523200&Signature=iGwCKYEX5w2fyStoMGWV0XIG4OcHh61t-f4xVXUQn6Ud-g3W-7x-1E3pmYxC3T5Zh5qIxt6J3ZHQP3B7Z4qmjkFLV737yjutuYxiXuYZMHyQQcKwBBxB87~TyU7tjbSX4OlTMV7BoIZ672oxoAQYlBY32djRafiH-fRF-~vW8D4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A


    graph.h — класс, реализующий взвешенный ориентированный граф.

    router.h — класс, реализующий поиск кратчайшего пути во взвешенном ориентированном графе.

В отличие от парсера JSON в предыдущей версии задачи, эти библиотеки не нуждаются в модификации. С другой стороны, вы имеете право не использовать их вовсе или модифицировать произвольным образом.

Моделируя ситуации из реальной жизни разработчиков, обе эти библиотеки предоставляются без документации, но с самодокументируемым кодом: интерфейсы представленных классов легко читаются по заголовкам публичных методов.

Про эти классы дополнительно известно следующее:

    Вершины и рёбра графа нумеруются автоинкрементно беззнаковыми целыми числами, хранящимися в типах VertexId и EdgeId: вершины нумеруются от 0 до количества вершин минус один в соответствии с пользовательской логикой, а номер очередного ребра выдаётся методом AddEdge, равен нулю для первого вызова метода и при каждом следующем вызове увеличивается на единицу.

    Память, необходимая для хранения графа, линейна относительно суммы количеств вершин и рёбер.

    Конструктор и деструктор графа имеют линейную сложность, а остальные методы константны или амортизированно константны.

    Маршрутизатор (класс Router) требует квадратичного относительно количества вершин объёма памяти, не считая памяти, требуемой для хранения кэша маршрутов.

    Конструктор маршрутизатора имеет сложность O(V³+E), где V — количество вершин графа, E — количество рёбер.

    Маршрутизатор не работает с графами, имеющими рёбра отрицательного веса.

    Построение маршрута на готовом маршрутизаторе линейно относительно количества рёбер в маршруте. Таким образом, основная нагрузка построения оптимальных путей ложится на конструктор.

Вам необходимо:

    самостоятельно разобраться с понятиями графов и путями в них;

    придумать, как по транспортному справочнику построить граф, путь наименьшего веса в котором соответствует оптимальному маршруту на автобусах, предварительно определившись, что в этом графе будет являться вершинами, а что — рёбрами;

    написать код построения графа и описания маршрута по пути, полученному от маршрутизатора.

Ограничения

В этой и последующих версиях и количество остановок, и количество автобусов не превышает 100.

Ограничение по времени — 3 секунды на тест, по памяти — 512 МБ

В реальном маршрутизаторе время на предварительную подготовку данных вполне могло бы занимать минуты, что позволило бы увеличить это ограничение.
Пример 1
Иллюстрации к примеру

CourseraBrownFinalE1Map-7.pdf
https://d3c33hcgiwev3.cloudfront.net/yfxZgAXSEem6Gg6vVM6M8A_ca855ec005d211e996a4d38897f21547_CourseraBrownFinalE1Map-7.pdf?Expires=1653523200&Signature=WEzHhT-tMgeBDKBZLMk~I3vivrxNJJiibsGxKnC-nA~ha3PJPqrpSsS9M3DNwqnPSQXJ~kLvg6GAJx4TtDDjDBsMttjGX3UjB2TiuRkXNONGSIRP-2zeaLTXqvVPiti3PxTbaXEImk-eXWyPR5~g6EUtwQsuJoyPDLsrnl9FbCk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

Ввод

{
  "routing_settings": {
    "bus_wait_time": 6,
    "bus_velocity": 40
  },
  "base_requests": [
    {
      "type": "Bus",
      "name": "297",
      "stops": [
        "Biryulyovo Zapadnoye",
        "Biryulyovo Tovarnaya",
        "Universam",
        "Biryulyovo Zapadnoye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Bus",
      "name": "635",
      "stops": [
        "Biryulyovo Tovarnaya",
        "Universam",
        "Prazhskaya"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Tovarnaya": 2600
      },
      "longitude": 37.6517,
      "name": "Biryulyovo Zapadnoye",
      "latitude": 55.574371
    },
    {
      "type": "Stop",
      "road_distances": {
        "Prazhskaya": 4650,
        "Biryulyovo Tovarnaya": 1380,
        "Biryulyovo Zapadnoye": 2500
      },
      "longitude": 37.645687,
      "name": "Universam",
      "latitude": 55.587655
    },
    {
      "type": "Stop",
      "road_distances": {
        "Universam": 890
      },
      "longitude": 37.653656,
      "name": "Biryulyovo Tovarnaya",
      "latitude": 55.592028
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.603938,
      "name": "Prazhskaya",
      "latitude": 55.611717
    }
  ],
  "stat_requests": [
    {
      "type": "Bus",
      "name": "297",
      "id": 1
    },
    {
      "type": "Bus",
      "name": "635",
      "id": 2
    },
    {
      "type": "Stop",
      "name": "Universam",
      "id": 3
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Universam",
      "id": 4
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Prazhskaya",
      "id": 5
    }
  ]
}

Вывод

[
    {
        "curvature": 1.42963,
        "unique_stop_count": 3,
        "stop_count": 4,
        "request_id": 1,
        "route_length": 5990
    },
    {
        "curvature": 1.30156,
        "unique_stop_count": 3,
        "stop_count": 5,
        "request_id": 2,
        "route_length": 11570
    },
    {
        "request_id": 3,
        "buses": [
            "297",
            "635"
        ]
    },
    {
        "total_time": 11.235,
        "items": [
            {
                "time": 6,
                "type": "Wait",
                "stop_name": "Biryulyovo Zapadnoye"
            },
            {
                "span_count": 2,
                "bus": "297",
                "type": "Bus",
                "time": 5.235
            }
        ],
        "request_id": 4
    },
    {
        "total_time": 24.21,
        "items": [
            {
                "time": 6,
                "type": "Wait",
                "stop_name": "Biryulyovo Zapadnoye"
            },
            {
                "span_count": 2,
                "bus": "297",
                "type": "Bus",
                "time": 5.235
            },
            {
                "time": 6,
                "type": "Wait",
                "stop_name": "Universam"
            },
            {
                "span_count": 1,
                "bus": "635",
                "type": "Bus",
                "time": 6.975
            }
        ],
        "request_id": 5
    }
]

Пример 2
Иллюстрации к примеру

CourseraBrownFinalE1Map-10.pdf
https://d3c33hcgiwev3.cloudfront.net/OzScjgaYEem6Gg6vVM6M8A_3b809930069811e9a705156c70917e6c_CourseraBrownFinalE2Map-10.pdf?Expires=1653523200&Signature=Gr428DsZH9DMblsPAqThBIr3vTwgW81hr0gipeb5II-pSixH~yFcuCvwzr2oevC7Xs0Lpv2xHUjSus6-s4JDYnRvjrVvORgdRetceALf~ZcuNbKsGPDsf-KSQP2nypPfdQptiL5~TMqlhRMAYMi0iB4wEkZCFSXB7ZtQnDC1sFI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
Ввод

{
  "routing_settings": {
    "bus_wait_time": 2,
    "bus_velocity": 30
  },
  "base_requests": [
    {
      "type": "Bus",
      "name": "297",
      "stops": [
        "Biryulyovo Zapadnoye",
        "Biryulyovo Tovarnaya",
        "Universam",
        "Biryusinka",
        "Apteka",
        "Biryulyovo Zapadnoye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Bus",
      "name": "635",
      "stops": [
        "Biryulyovo Tovarnaya",
        "Universam",
        "Biryusinka",
        "TETs 26",
        "Pokrovskaya",
        "Prazhskaya"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Bus",
      "name": "828",
      "stops": [
        "Biryulyovo Zapadnoye",
        "TETs 26",
        "Biryusinka",
        "Universam",
        "Pokrovskaya",
        "Rossoshanskaya ulitsa"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Tovarnaya": 2600,
        "TETs 26": 1100
      },
      "longitude": 37.6517,
      "name": "Biryulyovo Zapadnoye",
      "latitude": 55.574371
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryusinka": 760,
        "Biryulyovo Tovarnaya": 1380,
        "Pokrovskaya": 2460
      },
      "longitude": 37.645687,
      "name": "Universam",
      "latitude": 55.587655
    },
    {
      "type": "Stop",
      "road_distances": {
        "Universam": 890
      },
      "longitude": 37.653656,
      "name": "Biryulyovo Tovarnaya",
      "latitude": 55.592028
    },
    {
      "type": "Stop",
      "road_distances": {
        "Apteka": 210,
        "TETs 26": 400
      },
      "longitude": 37.64839,
      "name": "Biryusinka",
      "latitude": 55.581065
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Zapadnoye": 1420
      },
      "longitude": 37.652296,
      "name": "Apteka",
      "latitude": 55.580023
    },
    {
      "type": "Stop",
      "road_distances": {
        "Pokrovskaya": 2850
      },
      "longitude": 37.642258,
      "name": "TETs 26",
      "latitude": 55.580685
    },
    {
      "type": "Stop",
      "road_distances": {
        "Rossoshanskaya ulitsa": 3140
      },
      "longitude": 37.635517,
      "name": "Pokrovskaya",
      "latitude": 55.603601
    },
    {
      "type": "Stop",
      "road_distances": {
        "Pokrovskaya": 3210
      },
      "longitude": 37.605757,
      "name": "Rossoshanskaya ulitsa",
      "latitude": 55.595579
    },
    {
      "type": "Stop",
      "road_distances": {
        "Pokrovskaya": 2260
      },
      "longitude": 37.603938,
      "name": "Prazhskaya",
      "latitude": 55.611717
    },
    {
      "type": "Bus",
      "name": "750",
      "stops": [
        "Tolstopaltsevo",
        "Rasskazovka"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Stop",
      "road_distances": {
        "Rasskazovka": 13800
      },
      "longitude": 37.20829,
      "name": "Tolstopaltsevo",
      "latitude": 55.611087
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.333324,
      "name": "Rasskazovka",
      "latitude": 55.632761
    }
  ],
  "stat_requests": [
    {
      "type": "Bus",
      "name": "297",
      "id": 1
    },
    {
      "type": "Bus",
      "name": "635",
      "id": 2
    },
    {
      "type": "Bus",
      "name": "828",
      "id": 3
    },
    {
      "type": "Stop",
      "name": "Universam",
      "id": 4
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Apteka",
      "id": 5
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Pokrovskaya",
      "id": 6
    },
    {
      "type": "Route",
      "from": "Biryulyovo Tovarnaya",
      "to": "Pokrovskaya",
      "id": 7
    },
    {
      "type": "Route",
      "from": "Biryulyovo Tovarnaya",
      "to": "Biryulyovo Zapadnoye",
      "id": 8
    },
    {
      "type": "Route",
      "from": "Biryulyovo Tovarnaya",
      "to": "Prazhskaya",
      "id": 9
    },
    {
      "type": "Route",
      "from": "Apteka",
      "to": "Biryulyovo Tovarnaya",
      "id": 10
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Tolstopaltsevo",
      "id": 11
    }
  ]
}

Вывод

[
    {
        "stop_count": 6,
        "route_length": 5880,
        "unique_stop_count": 5,
        "curvature": 1.36159,
        "request_id": 1
    },
    {
        "stop_count": 11,
        "route_length": 14810,
        "unique_stop_count": 6,
        "curvature": 1.12195,
        "request_id": 2
    },
    {
        "stop_count": 11,
        "route_length": 15790,
        "unique_stop_count": 6,
        "curvature": 1.31245,
        "request_id": 3
    },
    {
        "buses": [
            "297",
            "635",
            "828"
        ],
        "request_id": 4
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Biryulyovo Zapadnoye",
                "type": "Wait"
            },
            {
                "time": 3,
                "bus": "828",
                "span_count": 2,
                "type": "Bus"
            },
            {
                "time": 2,
                "stop_name": "Biryusinka",
                "type": "Wait"
            },
            {
                "time": 0.42,
                "bus": "297",
                "span_count": 1,
                "type": "Bus"
            }
        ],
        "request_id": 5,
        "total_time": 7.42
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Biryulyovo Zapadnoye",
                "type": "Wait"
            },
            {
                "time": 9.44,
                "bus": "828",
                "span_count": 4,
                "type": "Bus"
            }
        ],
        "request_id": 6,
        "total_time": 11.44
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Biryulyovo Tovarnaya",
                "type": "Wait"
            },
            {
                "time": 1.78,
                "bus": "635",
                "span_count": 1,
                "type": "Bus"
            },
            {
                "time": 2,
                "stop_name": "Universam",
                "type": "Wait"
            },
            {
                "time": 4.92,
                "bus": "828",
                "span_count": 1,
                "type": "Bus"
            }
        ],
        "request_id": 7,
        "total_time": 10.7
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Biryulyovo Tovarnaya",
                "type": "Wait"
            },
            {
                "time": 6.56,
                "bus": "297",
                "span_count": 4,
                "type": "Bus"
            }
        ],
        "request_id": 8,
        "total_time": 8.56
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Biryulyovo Tovarnaya",
                "type": "Wait"
            },
            {
                "time": 14.32,
                "bus": "635",
                "span_count": 5,
                "type": "Bus"
            }
        ],
        "request_id": 9,
        "total_time": 16.32
    },
    {
        "items": [
            {
                "time": 2,
                "stop_name": "Apteka",
                "type": "Wait"
            },
            {
                "time": 2.84,
                "bus": "297",
                "span_count": 1,
                "type": "Bus"
            },
            {
                "time": 2,
                "stop_name": "Biryulyovo Zapadnoye",
                "type": "Wait"
            },
            {
                "time": 5.2,
                "bus": "297",
                "span_count": 1,
                "type": "Bus"
            }
        ],
        "request_id": 10,
        "total_time": 12.04
    },
    {
        "error_message": "not found",
        "request_id": 11
    }
]

Пример 3
Иллюстрации к примеру

CourseraBrownFinalE3Map-1.pdf
https://d3c33hcgiwev3.cloudfront.net/1Nbt5yhKRiSW7ecoSpYkKQ_4a80fe34315146c282000224180412ae_CourseraBrownFinalE3Map-1.pdf?Expires=1653523200&Signature=VK~aEDyPTR-JTx~A21o35FRSyl22QdqKtSOztMGc4amc5C5wSTPjV-G9OLg-sAvvV5vx872NL~11-Iz7Engzay61ygWsxUT1nfeIspEu1L3a8SwkpcgD2Hsqym8ft4qNNRMmi7dsgklEtRREPvCinHn~rw9-wffFRl6YqEGQsJI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

Ввод

{
  "routing_settings": {
    "bus_wait_time": 2,
    "bus_velocity": 30
  },
  "base_requests": [
    {
      "type": "Bus",
      "name": "289",
      "stops": [
        "Zagorye",
        "Lipetskaya ulitsa 46",
        "Lipetskaya ulitsa 40",
        "Lipetskaya ulitsa 40",
        "Lipetskaya ulitsa 46",
        "Moskvorechye",
        "Zagorye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Stop",
      "road_distances": {
        "Lipetskaya ulitsa 46": 230
      },
      "longitude": 37.68372,
      "name": "Zagorye",
      "latitude": 55.579909
    },
    {
      "type": "Stop",
      "road_distances": {
        "Lipetskaya ulitsa 40": 390,
        "Moskvorechye": 12400
      },
      "longitude": 37.682205,
      "name": "Lipetskaya ulitsa 46",
      "latitude": 55.581441
    },
    {
      "type": "Stop",
      "road_distances": {
        "Lipetskaya ulitsa 40": 1090,
        "Lipetskaya ulitsa 46": 380
      },
      "longitude": 37.679133,
      "name": "Lipetskaya ulitsa 40",
      "latitude": 55.584496
    },
    {
      "type": "Stop",
      "road_distances": {
        "Zagorye": 10000
      },
      "longitude": 37.638433,
      "name": "Moskvorechye",
      "latitude": 55.638433
    }
  ],
  "stat_requests": [
    {
      "type": "Bus",
      "name": "289",
      "id": 1
    },
    {
      "type": "Route",
      "from": "Zagorye",
      "to": "Moskvorechye",
      "id": 2
    },
    {
      "type": "Route",
      "from": "Moskvorechye",
      "to": "Zagorye",
      "id": 3
    },
    {
      "type": "Route",
      "from": "Lipetskaya ulitsa 40",
      "to": "Lipetskaya ulitsa 40",
      "id": 4
    }
  ]
}

Вывод

[
    {
        "unique_stop_count": 4,
        "stop_count": 7,
        "request_id": 1,
        "curvature": 1.63414,
        "route_length": 24490
    },
    {
        "total_time": 29.26,
        "items": [
            {
                "time": 2,
                "stop_name": "Zagorye",
                "type": "Wait"
            },
            {
                "time": 0.46,
                "bus": "289",
                "span_count": 1,
                "type": "Bus"
            },
            {
                "time": 2,
                "stop_name": "Lipetskaya ulitsa 46",
                "type": "Wait"
            },
            {
                "time": 24.8,
                "bus": "289",
                "span_count": 1,
                "type": "Bus"
            }
        ],
        "request_id": 2
    },
    {
        "total_time": 22,
        "items": [
            {
                "time": 2,
                "stop_name": "Moskvorechye",
                "type": "Wait"
            },
            {
                "time": 20,
                "bus": "289",
                "span_count": 1,
                "type": "Bus"
            }
        ],
        "request_id": 3
    },
    {
        "total_time": 0,
        "items": [],
        "request_id": 4
    }
]

Пример 4

Тест с максимальными ограничениями
Ввод

transport-input4
https://d3c33hcgiwev3.cloudfront.net/hP_-KAjbEem5_xLqNrIdUA_85576cb008db11e980492d1bdac1a743_transport-input4.json?Expires=1653523200&Signature=SN3WlbwTfibKny2vEoodYNW5EAgqd~YOymUuLbzkQQh9h9wiPXxhn3uxMksZkyU9M5XoTr-gIKsLjMCSsdQYVQPnMsu7xb0hFhZ3LC4zTXOsnEFMlN1bc27WTTE1InzMoO9Rok0P1Rf6vPU4ITd2Z7DwtJJnDjuHlAXPM4~xhGw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

Вывод
transport-output4
https://d3c33hcgiwev3.cloudfront.net/hP_-GwjbEemYdRIT0BhLtg_8558f35008db11e9a83355cd28680ddf_transport-output4.json?Expires=1653523200&Signature=Ai0qBG~XPl69hPqj80QVUIj5G2o2JAYov1a8-yB1SjgD9FLAru1-eL-6SPizdVJ4l1xu1aO~9lE1iWEAVNreI1k3s7mI-Tecb2Z5Fmnfo7k3WNWmVMb-y3ivas1mb1PoBvHjC9b8F-yJ5WGAdyPLtvQphHWQ2xGuvr9hBNqhiY0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

В этой части подсказки посвящены, пожалуй, самой творческой части решения — способу построения графа по автобусным маршрутам.

e1.pdf
https://d3c33hcgiwev3.cloudfront.net/KSyldAEaEemAgQrXx6bp4g_29a4e280011a11e9bbfae30cc79f4ae1_e1.pdf?Expires=1653523200&Signature=j65I1ePs37jW5ZMspwaxkskzxr-5K4cn2VROppLap0VwVbQNFpiXJbJnXLCm7kqbD88yZAEoyLuMDLZWnsLsQmL7RqC3q1ikPBmhfyFytOUPvEWM~cEbEepVk4bH7QNhJPcvAXztqmhklGyyoE0WWWbZ5l8epvYsyonsgqNmjAw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
e2.pdf
https://d3c33hcgiwev3.cloudfront.net/KS6hgQEaEem5Kg7DUflKxA_29a382f0011a11e9a5c805e2b8f2a19e_e2.pdf?Expires=1653523200&Signature=NSQVMnP9v~fdF0V6J3jSmMvKZdmwWU-6f09fRMFlsph620UWRLvEEqMbLrG8A2oyUjY7TINsRD8LxubmmVrwy6x-a5jJKFK3S9vpi31XFCeWygXpLlXX-9OrMZpMLjDlEWN2NsjIxhEcnRneV9mYcEqVaO0N9jTzZuPB7-D3agM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
e3.pdf
https://d3c33hcgiwev3.cloudfront.net/KTZDEAEaEemlxxL_ZeRz_A_29a7c8b0011a11e9bb267581ac5408a9_e3.pdf?Expires=1653523200&Signature=NWxupPUsnxWVOqypPzyJIUBTA3aHP9GjESCkjA8iuJDtIZ9DhYC3KmDs6gefit2uhf28k7GSQX4TBPHaI9AAQ7ZmPdb4Txe1KQ8FtFD5Pb8v4i8YJmfFGq4iYlH0wU66j6haBSIBlBIEQmDHeEvQ9S-t25O76W1EtqUoFKkq0MQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
e4.pdf
https://d3c33hcgiwev3.cloudfront.net/KSymFwEaEemaxBKyA9PBAg_29a6b740011a11e9b1d629ab9619d043_e4.pdf?Expires=1653523200&Signature=XnFYzTgZr5JIbVoo5KGz1LY02FcEO0tgbwEDfetiOxpYEgdMW~12YhaHUpYA4KokeFXPgSqqdIkOozaGSd6NQ-t4xzTYFGcrZFh5Iv~kg8N9a2GCOrBeWxO-7NLbrpUtUqzabaeDG~u6m2F3TISBkYiUBR9o8iwesofGGsSkJ8k_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
e5.pdf
https://d3c33hcgiwev3.cloudfront.net/KVFEsgEaEem5Kg7DUflKxA_29a6de50011a11e99d584fb234eff555_e5.pdf?Expires=1653523200&Signature=EOXfBqRKB7vvozQ4vobUitRXjZmp~CCjkSGbBDNzb9yToadJFpNDmsBZ1KW47LBe4o-W0r4lnucs7JBDUAFka3-A8T8DQdgrHiLWf~v6Z3M~kQZa5UGYdV~mlfk4HMjlVEvtSrkj4zpoTdWYJOOCmxEETyEgIINTkS4ff-OHpOc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
