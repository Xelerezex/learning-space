import telebot
import nn


TOKEN = '1701547955:AAGM4gM69shhbP3FfBeemA7l250pBGrOFms'

bot = telebot.TeleBot(TOKEN)


@bot.message_handler(commands=['start', 'help'])
def start_help_handler(message):
    bot.send_message(message.from_user.id,
                     "Привет, отправь сюда картинку, а я тебе отвечу, кошка или собака на ней")


@bot.message_handler(content_types=['photo'])
def photo_handler(message):
    """Функция обрабатывает сообщение с картинкой"""
    label = 'собака'
    sureness = 0.7

    # Отправим пользователю сообщение с результатом
    reply = 'На картинке изображена {} с уверенностью в {}%'
    bot.reply_to(message, reply.format(label, sureness))


@bot.message_handler(func=lambda m: True)
def all_handler(message):
    """Все остальные сообщения будут попадать в эту функцию"""
    bot.send_message(message.from_user.id, "Пожалуйста, отправьте картинку")


# Запустим нашего бота
bot.polling(none_stop=True, interval=0, timeout=20)
