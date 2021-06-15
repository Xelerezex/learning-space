#  from collections import defaultdict
#
#  def mimic_dict(string):
#      words = [''] + string.split()
#      d = defaultdict(list)
#      for first, second in zip(words, words[1:]):
#          d[first].append(second)
#      return d

def mimic_dict(string):
    words = string.split()
    out_dict = {}
    prev_word = ""

    for word in words:
        out_dict.setdefault(prev_word, []).append(word)
        prev_word = word

    return out_dict
