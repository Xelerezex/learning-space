import os
import random

import numpy as np
import pandas as pd
from keras.layers import (Activation, BatchNormalization, Conv2D, Dense,
                          Dropout, Flatten, MaxPooling2D)
from keras.models import Sequential, load_model, model_from_json
from keras.preprocessing.image import ImageDataGenerator, load_img
from keras.utils import to_categorical
from sklearn.model_selection import train_test_split

FAST_RUN = False
IMAGE_WIDTH=128
IMAGE_HEIGHT=128
IMAGE_SIZE=(IMAGE_WIDTH, IMAGE_HEIGHT)
IMAGE_CHANNELS=3


def get_model():
    model = Sequential()

    model.add(Conv2D(32, (3, 3), activation='relu', input_shape=(IMAGE_WIDTH, IMAGE_HEIGHT, IMAGE_CHANNELS)))
    model.add(BatchNormalization())
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Conv2D(64, (3, 3), activation='relu'))
    model.add(BatchNormalization())
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Conv2D(128, (3, 3), activation='relu'))
    model.add(BatchNormalization())
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Flatten())
    model.add(Dense(512, activation='relu'))
    model.add(BatchNormalization())
    model.add(Dropout(0.5))
    model.add(Dense(2, activation='softmax')) # 2 because we have cat and dog classes

    model.compile(loss='categorical_crossentropy', optimizer='rmsprop', metrics=['accuracy'])

    model.summary()

    model.load_weights("model.h5")
    print("Loaded model from disk")
    return model

def predict_img_from_dir(path_to_dir='data/', name=None):
    """Функция предсказывает на основе картинок из папки их класс
    
    Если передан параметр name: функция возвращает словарем уверенность в 
    принадлежности картинки с таким именем к каждому классу
    Например: {'собака': 0.3, 'кошка': 0.7}
    
    Иначе возвращает словарь, где ключи - названия файлов,
                                  значения - название класса для этой картинки
    """
    test_filenames = [name for name in os.listdir(path_to_dir) if name.endswith('.jpg')]
    test_df = pd.DataFrame({
        'filename': test_filenames
    })
    nb_samples = test_df.shape[0]

    batch_size = 15

    test_gen = ImageDataGenerator(rescale=1./255)
    test_generator = test_gen.flow_from_dataframe(
        test_df, 
        path_to_dir, 
        x_col='filename',
        y_col=None,
        class_mode=None,
        target_size=IMAGE_SIZE,
        batch_size=batch_size,
        shuffle=False
    )

    labels = ('кошка', 'собака')
    predict = model.predict_generator(test_generator, steps=np.ceil(nb_samples/batch_size))

    if name:
        res = {k: v for k, v in zip(labels, predict[test_df['filename'] == name][0])}
        return res

    test_df['category'] = np.argmax(predict, axis=-1)
    test_df['probability'] = np.max(predict, axis=-1)

    test_df['label'] = test_df['category'].apply(lambda x: labels[x])
    res = {}
    for k, v in zip(test_df['filename'], test_df['label']):
        res[k] = v

    return res


model = get_model()

if __name__ == '__main__':
    res = predict_img_from_dir('images/test_test/199657479/')
    print(res)
