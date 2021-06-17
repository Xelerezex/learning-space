orders = pd.read_csv('orders.csv', delimiter=';')
products = pd.read_csv('Products.csv', delimiter=';')

dt = pd.merge(orders, products, left_on='ID товара', right_on='Product_ID')
socks = dt[(dt["Name"].str.contains("Носки")) & (dt["Оплачен"] == "Да")]

print(sum(socks["Количество"] * socks["Price"]))
