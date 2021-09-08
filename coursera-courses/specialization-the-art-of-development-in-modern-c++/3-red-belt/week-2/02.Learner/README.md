## Learner

Студента попросили написать класс Learner, помогающий изучать иностранный язык.
В публичном интерфейсе класса должны быть две функции:

```c++
int Learn(const vector<string>& words);
vector<string> KnownWords();
```

Функция Learn должна получать порцию слов, "запоминать" их и возвращать количество различных новых слов.
Функция KnownWords должна возвращать отсортированный по алфавиту список всех выученных слов.
В списке не должно быть повторов.

Студент написал следующее решение этой задачи, однако оно почему-то работает очень медленно.
Вам надо его ускорить.

Вам дан файл learner.cpp с медленным решением задачи. Не меняя публичный интерфейс класса Learner,
найдите в нём узкие места, исправьте их и сдайте переделанный класс в тестирующую систему.

> [learner.cpp](https://d3c33hcgiwev3.cloudfront.net/Rj2tMWpdEeiEwg4WmF3VaA_469d59206a5d11e89e76893a74f3c4cf_learner.cpp?Expires=1631232000&Signature=ZtthCndreN1MArKLuj4fPQvxUUay4GmPHzZ6KoleEvnTpn-L36YxTW9vI10h57An5g5vkVkCaUwtS0VAzyiBLFYWa0n7tnS-9dyiu97UlsAvRd9nmgLiHu407QLgqIQSI8vp0QEhVNSRl2ECGr1889IjkV7wTT9mdH2wStpShWo_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Ваш код будет тестироваться так:

```c++
int main() {
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
    }
    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
}
```

Подсказки

Для этой задачи есть подсказки, которые должны помочь вам с решением. Если вам не удаётся решить задачу и вы чувствуете,
что у вас кончились идеи, вы можете  воспользоваться. Но сначала обязательно попробуйте решить задачу без подсказок.

> [Подсказка-1.pdf](https://d3c33hcgiwev3.cloudfront.net/lQh8UcHWRdqIfFHB1tXavA_efab0ae5fb5543929367b4fd613c2d36_Podskazka-1.pdf?Expires=1631232000&Signature=JmlXGHCJfk1u4klZIm1oPr3j2dEpkcscBH8Uoy5QL9sK~LnRYRFtlK0NL0ZwvdW0V09tQpOGV7YMVs4H~LheXLfaEwLToVI9r9btlh9fzSZChAZwdT4W3LwcfIoAZoFZx-x6h2j3HNS3jeSyR834r25yNltgQVz~hHtU~2WrYyY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка-2.pdf](https://d3c33hcgiwev3.cloudfront.net/3v1ArebVQWO9QK3m1VFjTg_ec59d1263ac748eda35c2b10adc1aa81_Podskazka-2.pdf?Expires=1631232000&Signature=VHKE8AmG6EuJ~65P3k-rR-dPdgNhg5vOTx-BTNPogaS-YEcxmUCQEnuWRWrkuhKbnc3XcxcQuqBSGLH3Zlr9DtrF2EuMOkhNqkGUGwc7FN8pyck8jph-8S8rLnbVLsKcwsoHW1hLqBXSBlHmPqLVyR3PyRJysofBbVZM9DMxvKY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

