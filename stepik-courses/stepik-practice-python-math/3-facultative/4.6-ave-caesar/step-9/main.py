def disc_generator(alphabet):
    lst_alf = list(alphabet)
    random.shuffle(lst_alf)
    return ''.join(lst_alf)
