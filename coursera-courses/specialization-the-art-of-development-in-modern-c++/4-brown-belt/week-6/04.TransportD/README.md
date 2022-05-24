В этой версии необходимо перевести весь ввод и вывод на формат JSON. Детали — в примере ниже.

Гарантируется, что вещественные числа не задаются в экспоненциальной записи, то есть обязательно имеют целую часть и, возможно, дробную часть через десятичную точку.

Каждый запрос к базе дополнительно получает идентификатор в поле id — целое число от 0 до 2147483647. Ответ на запрос должен содержать идентификатор этого запроса в поле request_id. Это позволяет выводить ответы на запросы в любом порядке.

Ключи словарей могут располагаться в произвольном порядке. Форматирование (то есть пробельные символы вокруг скобок, запятых и двоеточий) не имеет значения как во входном, так и в выходном JSON.
Парсинг JSON

В качестве основы JSON-парсера используйте нашу заготовку:

json.h
https://d3c33hcgiwev3.cloudfront.net/RFqbWPkYEei5Kg7DUflKxA_44feca00f91811e8b59b07c93ade399f_json.h?Expires=1653436800&Signature=UllH~qfk-R3mzNWpwmA6DQdKzqpZT-iD0S3JIIeEmL7zRJyhNHw~w5Tr8lLD8cLq5ka95MBNZnNMV85s-q9JAoW7tUnfVLIs7-4mMLyPXkoILPuuPhmPRwlDwyM75--0epqamVM6MjVJCN07rt8x4cgIdizSzsoh-NYFyuewyRE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

json.cpp
https://d3c33hcgiwev3.cloudfront.net/RFVqxfkYEeilxxL_ZeRz_A_44fdb890f91811e887f49dea92615bcd_json.cpp?Expires=1653436800&Signature=hXPM0PVI3d1jR1UUU~lN8xbgfFSc2ZRMW9pTwDhwuSFF1pJPhT9~klgA7bSxkvHP8WSRjflfGqCBJmwY36vtq75mVK7NOLNZZ5cVh0U353ieWKiuRQVv9YHFqozmdQx0~LIAFur7rLMNEU3TuI5qXPMcqjFVKhGOTYBYvx9FWyg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

Пример
Ввод

{
  "base_requests": [
    {
      "type": "Stop",
      "road_distances": {
        "Marushkino": 3900
      },
      "longitude": 37.20829,
      "name": "Tolstopaltsevo",
      "latitude": 55.611087
    },
    {
      "type": "Stop",
      "road_distances": {
        "Rasskazovka": 9900
      },
      "longitude": 37.209755,
      "name": "Marushkino",
      "latitude": 55.595884
    },
    {
      "type": "Bus",
      "name": "256",
      "stops": [
        "Biryulyovo Zapadnoye",
        "Biryusinka",
        "Universam",
        "Biryulyovo Tovarnaya",
        "Biryulyovo Passazhirskaya",
        "Biryulyovo Zapadnoye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Bus",
      "name": "750",
      "stops": [
        "Tolstopaltsevo",
        "Marushkino",
        "Rasskazovka"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.333324,
      "name": "Rasskazovka",
      "latitude": 55.632761
    },
    {
      "type": "Stop",
      "road_distances": {
        "Rossoshanskaya ulitsa": 7500,
        "Biryusinka": 1800,
        "Universam": 2400
      },
      "longitude": 37.6517,
      "name": "Biryulyovo Zapadnoye",
      "latitude": 55.574371
    },
    {
      "type": "Stop",
      "road_distances": {
        "Universam": 750
      },
      "longitude": 37.64839,
      "name": "Biryusinka",
      "latitude": 55.581065
    },
    {
      "type": "Stop",
      "road_distances": {
        "Rossoshanskaya ulitsa": 5600,
        "Biryulyovo Tovarnaya": 900
      },
      "longitude": 37.645687,
      "name": "Universam",
      "latitude": 55.587655
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Passazhirskaya": 1300
      },
      "longitude": 37.653656,
      "name": "Biryulyovo Tovarnaya",
      "latitude": 55.592028
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Zapadnoye": 1200
      },
      "longitude": 37.659164,
      "name": "Biryulyovo Passazhirskaya",
      "latitude": 55.580999
    },
    {
      "type": "Bus",
      "name": "828",
      "stops": [
        "Biryulyovo Zapadnoye",
        "Universam",
        "Rossoshanskaya ulitsa",
        "Biryulyovo Zapadnoye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.605757,
      "name": "Rossoshanskaya ulitsa",
      "latitude": 55.595579
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.603831,
      "name": "Prazhskaya",
      "latitude": 55.611678
    }
  ],
  "stat_requests": [
    {
      "type": "Bus",
      "name": "256",
      "id": 1965312327
    },
    {
      "type": "Bus",
      "name": "750",
      "id": 519139350
    },
    {
      "type": "Bus",
      "name": "751",
      "id": 194217464
    },
    {
      "type": "Stop",
      "name": "Samara",
      "id": 746888088
    },
    {
      "type": "Stop",
      "name": "Prazhskaya",
      "id": 65100610
    },
    {
      "type": "Stop",
      "name": "Biryulyovo Zapadnoye",
      "id": 1042838872
    }
  ]
}

Вывод

[
  {
    "route_length": 5950,
    "request_id": 1965312327,
    "curvature": 1.36124,
    "stop_count": 6,
    "unique_stop_count": 5
  },
  {
    "route_length": 27600,
    "request_id": 519139350,
    "curvature": 1.31808,
    "stop_count": 5,
    "unique_stop_count": 3
  },
  {
    "request_id": 194217464,
    "error_message": "not found"
  },
  {
    "request_id": 746888088,
    "error_message": "not found"
  },
  {
    "buses": [],
    "request_id": 65100610
  },
  {
    "buses": [
      "256",
      "828"
    ],
    "request_id": 1042838872
  }
]

Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

d1.pdf
https://d3c33hcgiwev3.cloudfront.net/-TBd8gEYEemixgqCUDoEfA_f9591ac0011811e9a5c805e2b8f2a19e_d1.pdf?Expires=1653436800&Signature=ieASm3s5wUpsrnX2qxmwQNlp23YFjV-GlKt2i0LWQMep4ugqM2vtktv9uq~IBvjDu1RD2cFF839OpMtT~Xa2Mjxc81y8hGxbw6m2AyOQc2yIDn60rCjuH9lwtDJbCPBN97Kr-ta7LhJ6y2g6bsbUnDkJnUf8flLKcZ7kzr-7QkA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

d2.pdf
https://d3c33hcgiwev3.cloudfront.net/dhLyPApdEem5_xLqNrIdUA_766557200a5d11e986ab1514415c1ce6_d2.pdf?Expires=1653436800&Signature=BHDN6bSmkZzMWYaWWNnh4CCEx02PEQCGNO~qghnr~kYooNi1hWnQFmEhzDIQr6YWi-8ZpKJuF7F9ow8mFxqKb3TPn1qxg7Of9HdpWB1zJclKLUqa7ctA77IJZ0x0x4YFvHz3W8L0McG8d5cnDUeF3PmVJY~9OcphIETIUtx2y1k_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

d3.pdf
https://d3c33hcgiwev3.cloudfront.net/dhG5XQpdEemP8Qpm209XvA_7665a5400a5d11e98f16dd63388069b1_d3.pdf?Expires=1653436800&Signature=UCyTzDvKJM~Gs1LaG7o0QzXGX0hTzAtsvwLB1O4iBws2stdFAUoxCZeAlk8KjkcIX9uiGCNjkGW8zWt7Xbh7onz48Z7-NoRntnXcmciGGWVLUNCwYqsGdtEcLwUHLy5jCaVt~ff~1UOVyyWHtifs5zM3qU8ZoqGLUc2PKhc6Qrw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A
